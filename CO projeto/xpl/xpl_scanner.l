%option c++ yyclass="xpl_scanner" outfile="xpl_scanner.cpp"
%option stack noyywrap yylineno 8bit
%{ 
/* $Id: xpl_scanner.l,v 1.11 2017/05/21 12:22:22 ist180970 Exp $ */
// make relevant includes before including the parser's tab file
#include <string>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>
#include "xpl_scanner.h"
#include "xpl_parser.tab.h"
// don't change this
#define yyerror LexerError
%}
%x X_STRING X_DOUBLESLASH X_SLASHZERO X_COMMENT

WHITESPACE              [ \t\n\r]+
DIGIT					[0-9]
DIGITNOTZERO			[1-9]
HEXADIGIT				[0-9a-fA-F]
LETTER 					[A-Za-z]
DOUBLE                  {DIGIT}*"."({DIGIT}+)|{DIGIT}+"."({DIGIT}*)
%%


\"                     							yy_push_state(X_STRING); yylval.s = new std::string("");
<X_STRING>\\00 									yy_pop_state(); yy_push_state(X_SLASHZERO); return tSTRING;
<X_STRING>\\{HEXADIGIT}{HEXADIGIT}  			*yylval.s += (char)strtol(yytext+1, nullptr, 16);
<X_STRING>\\0									yy_pop_state(); yy_push_state(X_SLASHZERO); return tSTRING;
<X_STRING>\\{HEXADIGIT}							*yylval.s += (char)strtol(yytext+1, nullptr, 16);
<X_STRING>\\\"         							*yylval.s += (char)34;
<X_STRING>\\t         							*yylval.s += (char)9;
<X_STRING>\\n         							*yylval.s += (char)10;
<X_STRING>\\r         							*yylval.s += (char)13;
<X_STRING>\\\\         							*yylval.s += (char)92;
<X_STRING>\\.												*yylval.s += yytext+1;
<X_STRING>\"           							yy_pop_state(); return tSTRING;
<X_STRING>.            							*yylval.s += yytext;
<X_STRING>\n           							yyerror("newline in string");

<X_SLASHZERO>\\\"						;
<X_SLASHZERO>\"						{ yy_pop_state(); }
<X_SLASHZERO>.						;
<X_SLASHZERO>\n         			yyerror("newline in string");     

"/*"				   				yy_push_state(X_COMMENT);
<X_COMMENT>"/*"		   				yy_push_state(X_COMMENT);
<X_COMMENT>"*/"		   				yy_pop_state(); 
<X_COMMENT>.|\n   					;
"//".*$                	; /* ignore comments */


[-()<>=+?*/%:;{}.,&|~!]       				return *yytext;
{WHITESPACE}		   	; /* ignore whitespace */

">="                   return tGE; 
"<="                   return tLE; 
"=="                   return tEQ; 
"!="                   return tNE;

"!!"                   return tPRINTLN;

"int"				   return tINT_TYPE;
"real"				   return tDOUBLE_TYPE;
"string"			   return tSTRING_TYPE;
"elsif"				   return tELSEIF;
"sweep"                return tSWEEP;
"next"                 return tNEXT;
"stop"                 return tSTOP;
"return"               return tRETURN;
"while"                return tWHILE; 
"if"                   return tIF; 
"else"                 return tELSE; 

"public"			   return tPUBLIC;
"use"				   return tUSE;
"procedure" 		   return tPROCEDURE;
"null"				   return tNULL; 

[A-Za-z_][A-Za-z0-9_]*  			{ yylval.s = new std::string(yytext); return tIDENTIFIER; }

{DIGIT}                   			{ yylval.i = strtol(yytext, nullptr, 10); return tINTEGER; }
({DIGITNOTZERO}){DIGIT}*            { yylval.i = strtol(yytext, nullptr, 10); return tINTEGER; }
"0x"{HEXADIGIT}+ 		            { yylval.i = strtol(yytext, nullptr, 16); return tINTEGER; }  
	
{DOUBLE}													{yylval.d = strtod(yytext, nullptr); return tDOUBLE;}
({DIGIT}|{DOUBLE})+[eE][-+]?{DIGIT}+						{yylval.d = strtod(yytext, nullptr); return tDOUBLE;}


.                      yyerror(yytext);

%%
// Very, very dirty hack: flex is a mess generating C++ scanners.
int xpl_scanner::yywrap() { return 1; }