%{
// $Id: xpl_parser.y,v 1.21 2017/05/22 14:52:08 ist180970 Exp $
//-- don't change *any* of these: if you do, you'll break the compiler.
#include <cdk/compiler.h>
#include "ast/all.h"
#define LINE       compiler->scanner()->lineno()
#define yylex()    compiler->scanner()->scan()
#define yyerror(s) compiler->scanner()->error(s)
#define YYPARSE_PARAM_TYPE std::shared_ptr<cdk::compiler>
#define YYPARSE_PARAM      compiler
//-- don't change *any* of these --- END!
%}

%union {
  int                   i;	/* integer value */
  double                d;
  std::string          *s;	/* symbol name or string literal */
  cdk::basic_node      *node;	/* node pointer */
  cdk::sequence_node   *sequence;
  cdk::expression_node *expression; /* expression nodes */
  cdk::lvalue_node     *lvalue;
  basic_type            *type; /* type */
  xpl::block_node         *block;
};

%token <i> tINTEGER 
%token <s> tIDENTIFIER tSTRING
%token <d> tDOUBLE

%token tWHILE tIF tPRINTLN tPUBLIC tUSE tSTOP tNEXT tRETURN tSWEEP tELSE tELSEIF tPROCEDURE tNULL 
%token tSTRING_TYPE tINT_TYPE tDOUBLE_TYPE

%nonassoc tIFX
%nonassoc tELSEIF
%nonassoc tELSE

/*
%nonassoc tIF
%nonassoc tIFX
%nonassoc tELSEIFX
%nonassoc tELSEIF
%nonassoc tELSE
*/

%right '=' 
%left '|'
%left '&'
%nonassoc '~'
%left tEQ tNE
%left tGE '>' '<' tLE
%left '+' '-' 
%left '*' '/' '%' 

%nonassoc tUNARY
%nonassoc '['


%type <node> instrucao function variable iteration cond condCont declaration variableBlock arg
%type <sequence> instrucoes declarations declarationsBlock expressoes expressoesMais args arg_func 
%type <expression> expr literal funcall
%type <lvalue> lval
%type <type> tipo
%type <s> string
%type <block> bloco body



//SWEEP , ELSE IF, CONCATENACAO, STRING TODONOLEX: STRING E STRING_N

%{
//-- The rules below will be included in yyparse, the main parsing function.
%}
%%

file          : declarations   { compiler->ast($1); }
              ;

declarations  : declarations declaration   { $$ = new cdk::sequence_node(LINE,$2,$1); }
              | declaration                { $$ = new cdk::sequence_node(LINE,$1); }
              ;

declaration    : variable ';'        { $$ = $1; }
               | function            { $$ = $1; }
               ; 

variable      : tPUBLIC tipo  tIDENTIFIER  '=' expr { $$ = new xpl::variable_definition_node(LINE,$3,$2,$5,true);  }
              | tPUBLIC tipo  tIDENTIFIER  { $$ = new xpl::variable_declaration_node(LINE,$3,$2,true,false);  }
			  | tipo  tIDENTIFIER  '=' expr { $$ = new xpl::variable_definition_node(LINE,$2,$1,$4,false);  }              
              | tipo tIDENTIFIER { $$ = new xpl::variable_declaration_node(LINE,$2,$1,false,false);  }
			  | tUSE tipo  tIDENTIFIER  '=' expr { $$ = new xpl::variable_definition_node(LINE,$3,$2,$5,false);  } //confirmar 
              | tUSE tipo  tIDENTIFIER  { $$ = new xpl::variable_declaration_node(LINE,$3,$2,false,true);  }
              ;





function    : tipo tIDENTIFIER '('args')'       {$$ = new xpl::function_declaration_node(LINE, $2, $1, $4, false, false);}
            | tPROCEDURE tIDENTIFIER '('args')' {$$ = new xpl::function_declaration_node(LINE, $2, new basic_type(0,basic_type::TYPE_VOID), $4, false, false);}
           
            | tPUBLIC tipo tIDENTIFIER '('args')' {$$ = new xpl::function_declaration_node(LINE, $3, $2, $5, false, false);}
            | tPUBLIC tPROCEDURE tIDENTIFIER '('args')' {$$ = new xpl::function_declaration_node(LINE, $3, new basic_type(0,basic_type::TYPE_VOID), $5, false, false);}
 
            | tUSE tipo tIDENTIFIER '('args')' {$$ = new xpl::function_declaration_node(LINE, $3, $2, $5, true, false);}
            | tUSE tPROCEDURE tIDENTIFIER '('args')' {$$ = new xpl::function_declaration_node(LINE, $3, new basic_type(0,basic_type::TYPE_VOID), $5, true, false);}
			| tipo tIDENTIFIER '('args')' '=' literal      {$$ = new xpl::function_definition_node(LINE, $2, $1, $4, $7, nullptr, false);}
            
            | tipo tIDENTIFIER '('args')' '=' literal body     {$$ = new xpl::function_definition_node(LINE, $2, $1, $4, $7, $8, false);}
            | tPROCEDURE tIDENTIFIER '('args')' body           {$$ = new xpl::function_definition_node(LINE, $2, new basic_type(0,basic_type::TYPE_VOID), $4, nullptr, $6,false);}
            
            | tPUBLIC tipo tIDENTIFIER '('args')' '=' literal body     {$$ = new xpl::function_definition_node(LINE, $3, $2, $5, $8, $9,true);}
            | tPUBLIC tPROCEDURE tIDENTIFIER '('args')' body           {$$ = new xpl::function_definition_node(LINE, $3, new basic_type(0,basic_type::TYPE_VOID), $5, nullptr, $7, true);}
            
            | tipo tIDENTIFIER '('args')' body     {$$ = new xpl::function_definition_node(LINE, $2, $1, $4, nullptr, $6, false);} //TODO: BE CAREFULL
            | tPUBLIC tipo tIDENTIFIER '('args')' body  {$$ = new xpl::function_definition_node(LINE, $3, $2, $5, nullptr, $7, true);}
            
            ;
 



tipo        : tINT_TYPE          { $$ = new basic_type(4,basic_type::TYPE_INT);}
            | '['tipo']'        { $$ = new basic_type(4,basic_type::TYPE_POINTER); $$->_subtype=$2;}
            | tSTRING_TYPE           { $$ = new basic_type(4,basic_type::TYPE_STRING);}
            | tDOUBLE_TYPE            { $$ = new basic_type(8,basic_type::TYPE_DOUBLE);}
            ;

literal     : string { $$ = new cdk::string_node(LINE,$1);}
            | tDOUBLE { $$ = new cdk::double_node(LINE,$1);}
            | tINTEGER { $$ = new cdk::integer_node(LINE,$1);}
            | tNULL  { $$ = new xpl::null_node(LINE);}
            ;

string      : tSTRING 			{$$ = $1;}
    		| string tSTRING 	{ $$ = new std::string(*$1 + *$2); delete $2;}
            ;

body        :  bloco {$$ = $1;}
            ;

bloco       : '{' declarationsBlock '}'               { $$ = new xpl::block_node(LINE, $2,new cdk::sequence_node(LINE)); }
            | '{' instrucoes '}'                      { $$ = new xpl::block_node(LINE, new cdk::sequence_node(LINE), $2); }
            | '{' declarationsBlock instrucoes '}'    { $$ = new xpl::block_node(LINE, $2, $3); }
            | '{''}'                                { $$ = new xpl::block_node(LINE, new cdk::sequence_node(LINE),new cdk::sequence_node(LINE)); } //DOes nothing
            ;


declarationsBlock : variableBlock                        {$$ = new cdk::sequence_node(LINE,$1);}
                  | declarationsBlock variableBlock      {$$ = new cdk::sequence_node(LINE,$2,$1);}
                  ;

variableBlock     : tipo  tIDENTIFIER  '=' expr ';' { $$ = new xpl::variable_definition_node(LINE,$2,$1,$4,false);  }
                  | tipo  tIDENTIFIER  ';'          { $$ = new xpl::variable_declaration_node(LINE,$2,$1,false,false);  }
                  ;

instrucao   : expr ';'                       {$$ = new xpl::evaluation_node(LINE, $1); }
            | expr "!"                       {$$ = new xpl::print_node(LINE, $1, false); } 
            | expr tPRINTLN                  {$$ = new xpl::print_node(LINE, $1, true); }
            | bloco                          {$$ = $1;}
            | iteration                      {$$ = $1;}
            | cond                           {$$ = $1;}
            | tSTOP                          {$$ =  new xpl::stop_node(LINE) ;}
            | tNEXT                          {$$ =  new xpl::next_node(LINE) ;}
            | tRETURN                        {$$ =  new xpl::return_node(LINE) ;}
            ;

instrucoes  : instrucao       { $$ = new cdk::sequence_node(LINE, $1); }
            | instrucoes instrucao { $$ = new cdk::sequence_node(LINE, $2, $1); }
            ;


cond        : tIF '(' expr ')' instrucao   %prec tIFX      {$$ = new xpl::if_node(LINE, $3, $5);}
            | tIF '('expr')' instrucao tELSE instrucao        {$$ = new xpl::if_else_node(LINE, $3, $5, $7);}
            | tIF '('expr')' instrucao condCont                 {$$ = new xpl::if_else_node(LINE, $3, $5, $6);}
            ;

condCont    : tELSEIF '('expr')' instrucao  %prec tIFX   {$$ = new xpl::if_node(LINE, $3, $5);}
            | tELSEIF '('expr')' instrucao tELSE instrucao     {$$ = new xpl::if_else_node(LINE, $3, $5, $7);}
            | tELSEIF '('expr')' instrucao condCont              {$$ = new xpl::if_else_node(LINE, $3, $5, $6);}
            ;

expr        : literal                 { $$ = $1;}
            | '-' expr %prec tUNARY   { $$ = new cdk::neg_node(LINE, $2); }
            | '+' expr %prec tUNARY   { $$ = new xpl::identity_node(LINE, $2); }
            | expr '+' expr	         { $$ = new cdk::add_node(LINE, $1, $3); }
            | expr '-' expr	         { $$ = new cdk::sub_node(LINE, $1, $3); }
            | expr '*' expr	         { $$ = new cdk::mul_node(LINE, $1, $3); }
            | expr '/' expr	         { $$ = new cdk::div_node(LINE, $1, $3); }
            | expr '%' expr	         { $$ = new cdk::mod_node(LINE, $1, $3); }
            | expr '<' expr	         { $$ = new cdk::lt_node(LINE, $1, $3); }
            | expr '>' expr	         { $$ = new cdk::gt_node(LINE, $1, $3); }
            | expr tGE expr	         { $$ = new cdk::ge_node(LINE, $1, $3); }
            | '@'                    { $$ = new xpl::read_node(LINE); }            
            | expr tLE expr           { $$ = new cdk::le_node(LINE, $1, $3); }
            | expr tNE expr	         { $$ = new cdk::ne_node(LINE, $1, $3); }
            | expr tEQ expr	         { $$ = new cdk::eq_node(LINE, $1, $3); }
            | expr "&" expr           { $$ = new cdk::and_node(LINE, $1, $3); }   //AND                   
            | expr "|" expr           { $$ = new cdk::or_node(LINE, $1, $3); }    //OR       
            | "~" expr %prec tUNARY          { $$ = new cdk::not_node(LINE, $2); }    //NOT
            | lval                    { $$ = new cdk::rvalue_node(LINE,$1); }
            | funcall                 { $$ = $1;}
            | '(' expr ')'            { $$ = $2; }
            | lval '?'                { $$ = new xpl::memory_position_node(LINE, $1); }
            | '[' expr ']'                   { $$ = new xpl::memory_reservation_node(LINE, $2); }
            | lval '=' expr           { $$ = new cdk::assignment_node(LINE, $1, $3); }
            ;
      

iteration   : tWHILE '(' expr ')' instrucao                                   { $$ = new xpl::while_node(LINE, $3, $5); }
            | tSWEEP '+' '(' lval ':' expr ':' expr ':' expr ')' instrucao    { $$ = new xpl::sweep_plus_node(LINE, $4, $6,$8,$10,$12); }
            | tSWEEP '+' '(' lval ':' expr ':' expr ')' instrucao            { $$ = new xpl::sweep_plus_node(LINE, $4, $6,$8,$10); }
            | tSWEEP '-' '(' lval ':' expr ':' expr ':' expr ')' instrucao    { $$ = new xpl::sweep_minus_node(LINE, $4, $6,$8,$10,$12); }
            | tSWEEP '-' '(' lval ':' expr ':' expr ')' instrucao              { $$ = new xpl::sweep_minus_node(LINE, $4, $6,$8,$10); }
            ; 

args        : arg_func { $$ = new cdk::sequence_node(LINE,$1); }
            | {$$ = new cdk::sequence_node(LINE);}
            ;


 arg_func    : arg_func "," arg  { $$ = new cdk::sequence_node(LINE,$3,$1);  }
 			| arg               { $$ = new cdk::sequence_node(LINE, $1, new cdk::sequence_node(LINE));  }
 			;

arg         : tipo tIDENTIFIER { $$ = new xpl::variable_declaration_node(LINE,$2,$1,false,false);  } 
			;

funcall   : tIDENTIFIER '('expressoesMais')'  { $$ = new xpl::function_call_node(LINE,$1,$3);}
          ;

expressoesMais     : expressoes { $$ = new cdk::sequence_node(LINE,$1);  }
             		|                 { $$ = new cdk::sequence_node(LINE);  }
             		 ;

expressoes     : expressoes ',' expr  { $$ = new cdk::sequence_node(LINE,$3,$1);  }
              | expr                { $$ = new cdk::sequence_node(LINE,$1);  }
              ;

lval : tIDENTIFIER                   { $$ = new cdk::identifier_node(LINE, $1); delete $1;}
     | expr '[' expr ']'             { $$ = new xpl::indexation_node(LINE, $3, $1);}       
     ;
%%