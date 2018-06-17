/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "xpl_parser.y"
/* $Id: xpl_parser.y,v 1.21 2017/05/22 14:52:08 ist180970 Exp $*/
/*-- don't change *any* of these: if you do, you'll break the compiler.*/
#include <cdk/compiler.h>
#include "ast/all.h"
#define LINE       compiler->scanner()->lineno()
#define yylex()    compiler->scanner()->scan()
#define yyerror(s) compiler->scanner()->error(s)
#define YYPARSE_PARAM_TYPE std::shared_ptr<cdk::compiler>
#define YYPARSE_PARAM      compiler
/*-- don't change *any* of these --- END!*/
#line 14 "xpl_parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
  int                   i;	/* integer value */
  double                d;
  std::string          *s;	/* symbol name or string literal */
  cdk::basic_node      *node;	/* node pointer */
  cdk::sequence_node   *sequence;
  cdk::expression_node *expression; /* expression nodes */
  cdk::lvalue_node     *lvalue;
  basic_type            *type; /* type */
  xpl::block_node         *block;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 71 "xpl_parser.y"
/*-- The rules below will be included in yyparse, the main parsing function.*/
#line 53 "xpl_parser.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define tINTEGER 257
#define tIDENTIFIER 258
#define tSTRING 259
#define tDOUBLE 260
#define tWHILE 261
#define tIF 262
#define tPRINTLN 263
#define tPUBLIC 264
#define tUSE 265
#define tSTOP 266
#define tNEXT 267
#define tRETURN 268
#define tSWEEP 269
#define tELSE 270
#define tELSEIF 271
#define tPROCEDURE 272
#define tNULL 273
#define tSTRING_TYPE 274
#define tINT_TYPE 275
#define tDOUBLE_TYPE 276
#define tIFX 277
#define tEQ 278
#define tNE 279
#define tGE 280
#define tLE 281
#define tUNARY 282
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,   11,   11,    7,    7,    3,    3,    3,    3,    3,
    3,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,   21,   21,   21,   21,   18,   18,
   18,   18,   22,   22,   24,   23,   23,   23,   23,   12,
   12,    8,    8,    1,    1,    1,    1,    1,    1,    1,
    1,    1,   10,   10,    5,    5,    5,    6,    6,    6,
   17,   17,   17,   17,   17,   17,   17,   17,   17,   17,
   17,   17,   17,   17,   17,   17,   17,   17,   17,   17,
   17,   17,   17,   17,    4,    4,    4,    4,    4,   15,
   15,   16,   16,    9,   19,   14,   14,   13,   13,   20,
   20,
};
static const YYINT yylen[] = {                            2,
    1,    2,    1,    2,    1,    5,    3,    4,    2,    5,
    3,    5,    5,    6,    6,    6,    6,    7,    8,    6,
    9,    7,    6,    7,    1,    3,    1,    1,    1,    1,
    1,    1,    1,    2,    1,    3,    3,    4,    2,    1,
    2,    5,    3,    2,    2,    2,    1,    1,    1,    1,
    1,    1,    1,    2,    5,    7,    6,    5,    7,    6,
    1,    2,    2,    3,    3,    3,    3,    3,    3,    3,
    3,    1,    3,    3,    3,    3,    3,    2,    1,    1,
    3,    2,    3,    3,    5,   12,   10,   12,   10,    1,
    0,    3,    1,    2,    4,    1,    0,    3,    1,    1,
    4,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,   27,   25,   28,    0,    0,    5,    0,
    3,    0,    0,    0,    0,    0,    0,    0,    0,    4,
    2,    0,    0,    0,    0,    0,    0,   26,    0,    0,
    0,    0,    0,    0,    0,    0,   93,    0,    0,    0,
   31,    0,   33,   30,   32,    0,    0,    0,    0,    0,
   72,    0,   61,   80,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   94,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   82,   34,    0,
    0,    0,   17,   16,    0,   35,   20,   92,    0,    0,
    0,   83,   81,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   23,
   22,    0,   24,    0,    0,   50,   51,   52,    0,    0,
   39,   53,   48,   49,   40,    0,    0,    0,    0,   47,
    0,   95,  101,    0,    0,    0,    0,    0,    0,   37,
   54,   36,   41,    0,   46,   44,   45,    0,    0,   19,
   21,    0,    0,    0,    0,   38,    0,   43,    0,    0,
    0,    0,    0,    0,   85,    0,    0,    0,   42,    0,
    0,   57,    0,    0,   56,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   87,    0,   89,
    0,    0,   60,    0,    0,   59,   86,   88,
};
static const YYINT yydgoto[] = {                          8,
  132,    9,   10,  133,  134,  182,   11,  135,   37,  136,
   12,  137,   99,  100,   38,   39,  138,   53,   54,   55,
   40,   56,  140,   97,
};
static const YYINT yysindex[] = {                       -50,
  -26,   32, -249,    0,    0,    0,  -79,    0,    0,  -46,
    0,  -50, -231, -222, -218, -207, -200,   39,  -18,    0,
    0,  -40,   64,  -32,   68,    7,  -79,    0,  102,  -79,
  -79,  102,  -79,  -79,  102,  -79,    0,   48,   54, -145,
    0,   91,    0,    0,    0,  102,  102,  102,  102,  102,
    0, 1066,    0,    0,   22, -119,  109,  131, 1066,  137,
  138, 1066,  142,   75,  -79,    0,  102,   96,   96,   96,
  798,  814,  102,  102,  102,  102,  102,  102,  102,  102,
  102,  102,  102,  102,  102,  102,  102,    0,    0,  -56,
   75,  -54,    0,    0, 1201,    0,    0,    0,  155,  159,
 1066,    0,    0, 1157, 1166, 1173, 1173,   35,   35,   35,
   35,  139,  139,   96,   96,   96,  840, 1066, -130,    0,
    0, -130,    0,  161,  162,    0,    0,    0,  118,  -15,
    0,    0,    0,    0,    0, 1268, 1248,  442,  -55,    0,
  102,    0,    0,   75,   75,  102,  102,  164,  170,    0,
    0,    0,    0, 1290,    0,    0,    0,  110, 1066,    0,
    0,  856,  870,  102,  102,    0,  102,    0, 1540, 1540,
 1066,   23,   51,  882,    0, -248,  102,  102,    0, 1540,
  171,    0,  908,  958,    0,  102,  102,  102,  993,  709,
  748, 1540, 1540,  102, 1540,  102, -134,    0, 1005,    0,
 1021, 1540,    0, 1540, 1540,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  213,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  157,    0,  160,    0,  172,  131,    0,    0,  131,
  131,    0,  131,  131,    0,  131,    0,    0,  109,    0,
    0,   58,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  173,    0,    0,  -27,    1,    0,    0,  174,    0,
    0,  175,    0,   19,    0,    0,  177,  115,  147,  307,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   24,
   37,   50,    0,    0,    0,    0,    0,    0,  180,    0,
   30,    0,    0,  549,  704,  179,  602,  503,  539,  551,
  590,  450,  480,  339,  375,  407,    0,   29,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   55,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   49,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, 1131, 1131,    0,    0, 1308,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, 1357,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  497,    0,    0,    0,    0,   38,  217,  104,  182,  119,
    0,    0,    0,    0,  134,    0, 1560,   16,    0,  -10,
  132,    0,  -38,  -88,
};
#define YYTABLESIZE 1813
static const YYINT yytable[] = {                         30,
   29,  120,  121,  123,  119,   79,  122,   33,   18,   79,
   79,    7,   20,   79,   79,   79,   79,   79,   13,   79,
   29,  180,  181,   12,   50,   96,   22,   47,   32,   48,
   79,   79,   79,   29,   79,   23,   15,   29,   29,   24,
    7,   29,   29,   29,   29,   29,   36,   29,   51,   14,
   25,   96,   96,   96,   18,  160,  161,   26,   29,   29,
   29,   84,   29,   79,    7,   79,   95,   35,   95,   84,
   99,   85,   84,   99,   28,  130,   83,   81,   27,   82,
  177,   84,   87,   87,   88,   88,   84,   84,   64,   98,
  100,   29,   98,   29,  100,  100,   79,   65,  100,  100,
  100,  100,  100,   31,  100,   96,   96,   34,  178,   13,
   46,   87,   66,   88,   12,  100,  100,  100,  100,  100,
  100,   84,    7,   29,   29,   86,   41,   15,   43,   44,
   67,   13,   15,   17,  144,  202,  181,  145,   19,   89,
   14,   50,   45,   13,   47,   18,   48,   78,  100,   90,
  100,   78,   78,  172,  173,   78,   78,   78,   78,   78,
  148,   78,  149,   57,   58,   51,   60,   61,  168,   63,
  167,   91,   78,   78,   78,   85,   78,   92,   93,   63,
   83,  100,   94,   63,   63,   84,   86,   63,   63,   63,
   63,   63,   49,   63,    4,    5,    6,   95,  141,  142,
  146,  147,  158,  164,   63,   63,   63,   78,   63,  165,
  186,   75,    1,    1,    2,    9,   75,   97,    7,   75,
   96,    3,   75,    4,    5,    6,  139,   46,   21,   86,
   11,    8,    6,   10,  203,   79,   75,   75,   78,   63,
  153,   41,   42,   43,   44,   14,   98,    4,    5,    6,
   79,   79,   79,   79,    0,  154,    0,   45,    4,    5,
    6,   19,    0,   29,   29,   29,    0,    0,  139,    0,
   63,   75,   29,    0,   29,   29,   29,    0,   29,   29,
   29,   29,   13,   13,    0,    0,    0,   12,   12,    0,
   13,   84,   13,   13,   13,   12,    0,   12,   12,   12,
   15,   15,   75,   16,    0,    4,    5,    6,   15,    0,
   15,   15,   15,   14,   14,    0,    0,    0,   18,   18,
  100,   14,    0,   14,   14,   14,   18,    0,   18,   18,
   18,    0,    0,    0,    0,  100,  100,  100,  100,   62,
    0,    0,    0,   62,   62,    0,    0,   62,   62,   62,
   62,   62,    0,   62,    0,    0,    0,    0,   41,   42,
   43,   44,    0,    0,   62,   62,   62,    0,   62,    0,
    0,   66,    0,    0,   45,   66,   66,   78,    0,   66,
   66,   66,   66,   66,    0,   66,    0,    0,    0,    0,
    0,    0,   78,   78,   78,   78,   66,   66,   66,   62,
   66,    0,    0,    0,    0,    0,    0,   67,    0,   63,
    0,   67,   67,    0,    0,   67,   67,   67,   67,   67,
    0,   67,    0,    0,   63,   63,   63,   63,    0,    0,
   62,   66,   67,   67,   67,    0,   67,    0,    0,   68,
    0,   75,    0,   68,   68,    0,    0,   68,   68,   68,
   68,   68,    0,   68,    0,    0,   75,   75,    0,    0,
    0,    0,   66,    0,   68,   68,   68,   67,   68,    0,
    0,    0,    0,    0,  157,    0,    0,    0,   85,   74,
    0,    0,   64,   83,   81,    0,   82,   64,   84,    0,
   64,    0,   64,   64,   64,    0,    0,    0,   67,   68,
  156,   79,    0,   78,    0,    0,    0,   64,   64,   64,
    0,   64,   65,    0,    0,    0,    0,   65,    0,    0,
   65,    0,   65,   65,   65,    0,    0,    0,    0,    0,
   68,    0,   86,    0,    0,   71,    0,   65,   65,   65,
   71,   65,   64,   71,    0,    0,   71,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   71,   71,   71,    0,   71,   73,    0,    0,    0,   62,
    0,   70,   65,   64,    0,    0,   70,    0,    0,   70,
    0,   77,   70,   69,   62,   62,   62,   62,   69,   77,
    0,   69,   77,    0,   69,   71,   70,   70,   70,    0,
   70,   66,    0,   65,    0,    0,   77,   77,   69,   69,
   69,    0,   69,    0,    0,    0,   66,   66,   66,   66,
    0,    0,   73,    0,    0,    0,   71,   73,    0,    0,
   73,   70,  151,   73,   74,    0,    0,   67,    0,   74,
    0,   77,   74,   69,    0,   74,    0,   73,   73,   73,
  151,   73,   67,   67,   67,   67,    0,    0,    0,   74,
   74,    0,   70,    0,    0,  175,  176,    0,    0,   68,
    0,    0,   77,    0,   69,    0,  185,    0,    0,    0,
    0,    0,   73,    0,   68,   68,   68,   68,  197,  198,
    0,  200,    0,    0,   74,    0,    0,    0,  206,    0,
  207,  208,    0,    0,  155,    0,    0,    0,    0,    0,
    0,    0,   64,   73,    0,    0,    0,    0,    0,   75,
   76,   77,   80,    0,    0,   74,    0,   64,   64,   64,
   64,    0,    0,    0,    0,    0,   76,    0,    0,    0,
    0,   76,   65,    0,   76,   85,   74,   76,    0,  193,
   83,   81,    0,   82,    0,   84,    0,   65,   65,   65,
   65,   76,   76,    0,    0,   71,  194,    0,   79,    0,
   78,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   71,   71,   71,   71,   85,   74,    0,    0,  195,   83,
   81,    0,   82,    0,   84,    0,   76,    0,    0,   86,
    0,   70,    0,    0,    0,  196,    0,   79,    0,   78,
    0,   77,    0,   69,    0,    0,   70,   70,   70,   70,
    0,    0,    0,    0,    0,    0,    0,   76,   69,   69,
   69,   69,   73,    0,   85,   74,    0,    0,   86,   83,
   81,    0,   82,    0,   84,    0,    0,    0,    0,    0,
   85,   74,   73,    0,  103,   83,   81,   79,   82,   78,
   84,    0,    0,    0,   74,    0,    0,   73,   73,   73,
   73,   73,    0,   79,    0,   78,   85,   74,    0,   74,
   74,   83,   81,    0,   82,    0,   84,    0,   86,    0,
  102,    0,   85,   74,    0,    0,  169,   83,   81,   79,
   82,   78,   84,    0,   86,    0,   85,   74,    0,    0,
  170,   83,   81,    0,   82,   79,   84,   78,   85,   74,
    0,   73,    0,   83,   81,    0,   82,    0,   84,   79,
   86,   78,  143,    0,    0,    0,    0,   73,    0,    0,
  179,   79,    0,   78,   85,   74,   86,    0,    0,   83,
   81,    0,   82,    0,   84,    0,    0,    0,    0,    0,
   86,    0,    0,   73,    0,  187,   76,   79,    0,   78,
    0,    0,   86,    0,    0,    0,    0,    0,    0,   73,
    0,    0,    0,    0,    0,    0,   75,   76,   77,   80,
    0,    0,    0,   73,   85,   74,    0,    0,   86,   83,
   81,    0,   82,    0,   84,   73,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  188,    0,   79,    0,   78,
    0,    0,    0,    0,    0,   75,   76,   77,   80,   85,
   74,   73,    0,  192,   83,   81,    0,   82,    0,   84,
    0,   85,   74,    0,    0,  204,   83,   81,   86,   82,
    0,   84,   79,    0,   78,    0,    0,   85,   74,    0,
    0,  205,   83,   81,   79,   82,   78,   84,    0,    0,
    0,    0,    0,    0,    0,   75,   76,   77,   80,    0,
   79,   73,   78,   86,    0,    0,    0,    0,    0,    0,
    0,   75,   76,   77,   80,   86,    0,    0,    0,    0,
    0,    0,   85,   74,    0,    0,    0,   83,   81,    0,
   82,   86,   84,    0,    0,    0,   73,   75,   76,   77,
   80,    0,    0,    0,    0,   79,    0,   78,   73,    0,
    0,    0,    0,   75,   76,   77,   80,    0,    0,    0,
    0,    0,    0,    0,   73,    0,    0,   75,   76,   77,
   80,    0,    0,    0,    0,    0,   86,    0,    0,   75,
   76,   77,   80,    0,    0,    0,    0,   79,   79,    0,
    0,    0,   79,   79,    0,   79,    0,   79,    0,    0,
    0,    0,    0,    0,    0,   75,   76,   77,   80,   73,
   79,    0,   79,   85,   74,    0,    0,    0,   83,   81,
    0,   82,   85,   84,    0,    0,    0,   83,   81,   85,
   82,    0,   84,    0,   83,   81,   79,   82,   78,   84,
    0,   79,    0,    0,    0,   79,    0,   78,    0,    0,
    0,    0,   79,    0,   78,   75,   76,   77,   80,    0,
   50,    0,    0,   47,    0,   48,    0,   86,    0,    0,
    0,    0,    0,    0,   79,    0,   86,    0,    0,    0,
    0,    0,    0,   86,   51,    0,    0,    0,    0,    0,
   75,   76,   77,   80,    0,    0,    0,    0,    0,    0,
    0,    0,   75,   76,   77,   80,    0,   50,    0,    0,
   47,  130,   48,    0,    0,    0,    0,    0,   75,   76,
   77,   80,    0,    0,    0,    0,    0,   50,    0,    0,
   47,   51,   48,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   95,    0,  131,   46,    0,    0,   50,
    0,   51,   47,    0,   48,    0,    0,    0,  130,    0,
    0,    0,    0,   75,   76,   77,   80,   55,    0,    0,
   55,    0,   55,   51,    0,    0,    0,    0,   49,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   95,   55,  152,   46,    0,    0,    0,    0,    0,    0,
   49,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   95,    0,  150,   46,    0,    0,   58,    0,   55,   58,
    0,   58,    0,    0,    0,    0,    0,    0,   79,   79,
   79,   79,   95,    0,  166,   46,    0,    0,    0,    0,
   58,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   55,    0,   55,   55,   75,   76,   77,   80,    0,    0,
    0,    0,    0,   75,   76,   77,   80,   58,    0,    0,
    0,    0,   77,   80,    0,    0,    0,   41,   42,   43,
   44,  124,  125,    0,    0,    0,  126,  127,  128,  129,
    0,    0,    0,   45,    4,    5,    6,    0,    0,   58,
    0,   58,   58,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   41,   42,   43,   44,  124,  125,
    0,    0,    0,  126,  127,  128,  129,    0,    0,    0,
   45,    4,    5,    6,   41,   42,   43,   44,  124,  125,
    0,    0,    0,  126,  127,  128,  129,    0,    0,    0,
   45,    0,    0,    0,    0,    0,   41,   42,   43,   44,
  124,  125,    0,    0,    0,  126,  127,  128,  129,    0,
    0,    0,   45,    0,   55,   55,   55,   55,   55,   55,
    0,    0,    0,   55,   55,   55,   55,    0,    0,   50,
   55,    0,   47,    0,   48,    0,    0,    0,   52,    0,
    0,   59,    0,    0,   62,    0,    0,    0,    0,    0,
    0,    0,    0,   51,    0,   68,   69,   70,   71,   72,
    0,    0,    0,   58,   58,   58,   58,   58,   58,    0,
    0,    0,   58,   58,   58,   58,  101,    0,    0,   58,
   49,    0,  104,  105,  106,  107,  108,  109,  110,  111,
  112,  113,  114,  115,  116,  117,  118,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   95,    0,    0,   46,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   71,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  159,    0,    0,    0,    0,  162,  163,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  171,  171,    0,  174,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  183,  184,    0,    0,
    0,    0,    0,    0,    0,  189,  190,  191,    0,    0,
    0,    0,    0,  199,    0,  201,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   41,   42,   43,   44,
  124,  125,    0,    0,    0,  126,  127,  128,  129,    0,
    0,    0,   45,
};
static const YYINT yycheck[] = {                         40,
    0,   90,   91,   92,   61,   33,   61,   40,  258,   37,
   38,   91,   59,   41,   42,   43,   44,   45,    0,   47,
   61,  270,  271,    0,   40,   64,  258,   43,   61,   45,
   58,   59,   60,   33,   62,  258,    0,   37,   38,  258,
   91,   41,   42,   43,   44,   45,   40,   47,   64,    0,
  258,   90,   91,   92,    0,  144,  145,  258,   58,   59,
   60,   33,   62,   91,   91,   93,  123,   61,  123,   41,
   41,   37,   44,   44,   93,   91,   42,   43,   40,   45,
   58,   47,   61,   61,   63,   63,   58,   59,   41,   41,
   33,   91,   44,   93,   37,   38,  124,   44,   41,   42,
   43,   44,   45,   40,   47,  144,  145,   40,   58,   91,
  126,   61,  258,   63,   91,   58,   59,   60,   61,   62,
   63,   93,   91,  123,  124,   91,  257,   91,  259,  260,
   40,    0,    1,    2,  119,  270,  271,  122,    7,  259,
   91,   40,  273,   12,   43,   91,   45,   33,   91,   41,
   93,   37,   38,  164,  165,   41,   42,   43,   44,   45,
   43,   47,   45,   30,   31,   64,   33,   34,   59,   36,
   61,   41,   58,   59,   60,   37,   62,   41,   41,   33,
   42,  124,   41,   37,   38,   47,   91,   41,   42,   43,
   44,   45,   91,   47,  274,  275,  276,  123,   44,   41,
   40,   40,  258,   40,   58,   59,   60,   93,   62,   40,
   40,   33,    0,  264,  265,   59,   38,   41,   59,   41,
   41,  272,   44,  274,  275,  276,   95,  126,   12,   91,
   59,   59,   59,   59,  197,  263,   58,   59,  124,   93,
  137,  257,  258,  259,  260,  272,   65,  274,  275,  276,
  278,  279,  280,  281,   -1,  137,   -1,  273,  274,  275,
  276,  130,   -1,  263,  264,  265,   -1,   -1,  137,   -1,
  124,   93,  272,   -1,  274,  275,  276,   -1,  278,  279,
  280,  281,  264,  265,   -1,   -1,   -1,  264,  265,   -1,
  272,  263,  274,  275,  276,  272,   -1,  274,  275,  276,
  264,  265,  124,  272,   -1,  274,  275,  276,  272,   -1,
  274,  275,  276,  264,  265,   -1,   -1,   -1,  264,  265,
  263,  272,   -1,  274,  275,  276,  272,   -1,  274,  275,
  276,   -1,   -1,   -1,   -1,  278,  279,  280,  281,   33,
   -1,   -1,   -1,   37,   38,   -1,   -1,   41,   42,   43,
   44,   45,   -1,   47,   -1,   -1,   -1,   -1,  257,  258,
  259,  260,   -1,   -1,   58,   59,   60,   -1,   62,   -1,
   -1,   33,   -1,   -1,  273,   37,   38,  263,   -1,   41,
   42,   43,   44,   45,   -1,   47,   -1,   -1,   -1,   -1,
   -1,   -1,  278,  279,  280,  281,   58,   59,   60,   93,
   62,   -1,   -1,   -1,   -1,   -1,   -1,   33,   -1,  263,
   -1,   37,   38,   -1,   -1,   41,   42,   43,   44,   45,
   -1,   47,   -1,   -1,  278,  279,  280,  281,   -1,   -1,
  124,   93,   58,   59,   60,   -1,   62,   -1,   -1,   33,
   -1,  263,   -1,   37,   38,   -1,   -1,   41,   42,   43,
   44,   45,   -1,   47,   -1,   -1,  278,  279,   -1,   -1,
   -1,   -1,  124,   -1,   58,   59,   60,   93,   62,   -1,
   -1,   -1,   -1,   -1,   33,   -1,   -1,   -1,   37,   38,
   -1,   -1,   33,   42,   43,   -1,   45,   38,   47,   -1,
   41,   -1,   43,   44,   45,   -1,   -1,   -1,  124,   93,
   59,   60,   -1,   62,   -1,   -1,   -1,   58,   59,   60,
   -1,   62,   33,   -1,   -1,   -1,   -1,   38,   -1,   -1,
   41,   -1,   43,   44,   45,   -1,   -1,   -1,   -1,   -1,
  124,   -1,   91,   -1,   -1,   33,   -1,   58,   59,   60,
   38,   62,   93,   41,   -1,   -1,   44,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   58,   59,   60,   -1,   62,  124,   -1,   -1,   -1,  263,
   -1,   33,   93,  124,   -1,   -1,   38,   -1,   -1,   41,
   -1,   33,   44,   33,  278,  279,  280,  281,   38,   41,
   -1,   41,   44,   -1,   44,   93,   58,   59,   60,   -1,
   62,  263,   -1,  124,   -1,   -1,   58,   59,   58,   59,
   60,   -1,   62,   -1,   -1,   -1,  278,  279,  280,  281,
   -1,   -1,   33,   -1,   -1,   -1,  124,   38,   -1,   -1,
   41,   93,  136,   44,   33,   -1,   -1,  263,   -1,   38,
   -1,   93,   41,   93,   -1,   44,   -1,   58,   59,   60,
  154,   62,  278,  279,  280,  281,   -1,   -1,   -1,   58,
   59,   -1,  124,   -1,   -1,  169,  170,   -1,   -1,  263,
   -1,   -1,  124,   -1,  124,   -1,  180,   -1,   -1,   -1,
   -1,   -1,   93,   -1,  278,  279,  280,  281,  192,  193,
   -1,  195,   -1,   -1,   93,   -1,   -1,   -1,  202,   -1,
  204,  205,   -1,   -1,  263,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  263,  124,   -1,   -1,   -1,   -1,   -1,  278,
  279,  280,  281,   -1,   -1,  124,   -1,  278,  279,  280,
  281,   -1,   -1,   -1,   -1,   -1,   33,   -1,   -1,   -1,
   -1,   38,  263,   -1,   41,   37,   38,   44,   -1,   41,
   42,   43,   -1,   45,   -1,   47,   -1,  278,  279,  280,
  281,   58,   59,   -1,   -1,  263,   58,   -1,   60,   -1,
   62,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  278,  279,  280,  281,   37,   38,   -1,   -1,   41,   42,
   43,   -1,   45,   -1,   47,   -1,   93,   -1,   -1,   91,
   -1,  263,   -1,   -1,   -1,   58,   -1,   60,   -1,   62,
   -1,  263,   -1,  263,   -1,   -1,  278,  279,  280,  281,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,  278,  279,
  280,  281,  124,   -1,   37,   38,   -1,   -1,   91,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,
   37,   38,  263,   -1,   41,   42,   43,   60,   45,   62,
   47,   -1,   -1,   -1,  263,   -1,   -1,  278,  279,  280,
  281,  124,   -1,   60,   -1,   62,   37,   38,   -1,  278,
  279,   42,   43,   -1,   45,   -1,   47,   -1,   91,   -1,
   93,   -1,   37,   38,   -1,   -1,   41,   42,   43,   60,
   45,   62,   47,   -1,   91,   -1,   37,   38,   -1,   -1,
   41,   42,   43,   -1,   45,   60,   47,   62,   37,   38,
   -1,  124,   -1,   42,   43,   -1,   45,   -1,   47,   60,
   91,   62,   93,   -1,   -1,   -1,   -1,  124,   -1,   -1,
   59,   60,   -1,   62,   37,   38,   91,   -1,   -1,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,
   91,   -1,   -1,  124,   -1,   58,  263,   60,   -1,   62,
   -1,   -1,   91,   -1,   -1,   -1,   -1,   -1,   -1,  124,
   -1,   -1,   -1,   -1,   -1,   -1,  278,  279,  280,  281,
   -1,   -1,   -1,  124,   37,   38,   -1,   -1,   91,   42,
   43,   -1,   45,   -1,   47,  124,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   58,   -1,   60,   -1,   62,
   -1,   -1,   -1,   -1,   -1,  278,  279,  280,  281,   37,
   38,  124,   -1,   41,   42,   43,   -1,   45,   -1,   47,
   -1,   37,   38,   -1,   -1,   41,   42,   43,   91,   45,
   -1,   47,   60,   -1,   62,   -1,   -1,   37,   38,   -1,
   -1,   41,   42,   43,   60,   45,   62,   47,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  278,  279,  280,  281,   -1,
   60,  124,   62,   91,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  278,  279,  280,  281,   91,   -1,   -1,   -1,   -1,
   -1,   -1,   37,   38,   -1,   -1,   -1,   42,   43,   -1,
   45,   91,   47,   -1,   -1,   -1,  124,  278,  279,  280,
  281,   -1,   -1,   -1,   -1,   60,   -1,   62,  124,   -1,
   -1,   -1,   -1,  278,  279,  280,  281,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  124,   -1,   -1,  278,  279,  280,
  281,   -1,   -1,   -1,   -1,   -1,   91,   -1,   -1,  278,
  279,  280,  281,   -1,   -1,   -1,   -1,   37,   38,   -1,
   -1,   -1,   42,   43,   -1,   45,   -1,   47,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  278,  279,  280,  281,  124,
   60,   -1,   62,   37,   38,   -1,   -1,   -1,   42,   43,
   -1,   45,   37,   47,   -1,   -1,   -1,   42,   43,   37,
   45,   -1,   47,   -1,   42,   43,   60,   45,   62,   47,
   -1,   91,   -1,   -1,   -1,   60,   -1,   62,   -1,   -1,
   -1,   -1,   60,   -1,   62,  278,  279,  280,  281,   -1,
   40,   -1,   -1,   43,   -1,   45,   -1,   91,   -1,   -1,
   -1,   -1,   -1,   -1,  124,   -1,   91,   -1,   -1,   -1,
   -1,   -1,   -1,   91,   64,   -1,   -1,   -1,   -1,   -1,
  278,  279,  280,  281,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  278,  279,  280,  281,   -1,   40,   -1,   -1,
   43,   91,   45,   -1,   -1,   -1,   -1,   -1,  278,  279,
  280,  281,   -1,   -1,   -1,   -1,   -1,   40,   -1,   -1,
   43,   64,   45,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  123,   -1,  125,  126,   -1,   -1,   40,
   -1,   64,   43,   -1,   45,   -1,   -1,   -1,   91,   -1,
   -1,   -1,   -1,  278,  279,  280,  281,   40,   -1,   -1,
   43,   -1,   45,   64,   -1,   -1,   -1,   -1,   91,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  123,   64,  125,  126,   -1,   -1,   -1,   -1,   -1,   -1,
   91,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  123,   -1,  125,  126,   -1,   -1,   40,   -1,   91,   43,
   -1,   45,   -1,   -1,   -1,   -1,   -1,   -1,  278,  279,
  280,  281,  123,   -1,  125,  126,   -1,   -1,   -1,   -1,
   64,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  123,   -1,  125,  126,  278,  279,  280,  281,   -1,   -1,
   -1,   -1,   -1,  278,  279,  280,  281,   91,   -1,   -1,
   -1,   -1,  280,  281,   -1,   -1,   -1,  257,  258,  259,
  260,  261,  262,   -1,   -1,   -1,  266,  267,  268,  269,
   -1,   -1,   -1,  273,  274,  275,  276,   -1,   -1,  123,
   -1,  125,  126,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  257,  258,  259,  260,  261,  262,
   -1,   -1,   -1,  266,  267,  268,  269,   -1,   -1,   -1,
  273,  274,  275,  276,  257,  258,  259,  260,  261,  262,
   -1,   -1,   -1,  266,  267,  268,  269,   -1,   -1,   -1,
  273,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,  260,
  261,  262,   -1,   -1,   -1,  266,  267,  268,  269,   -1,
   -1,   -1,  273,   -1,  257,  258,  259,  260,  261,  262,
   -1,   -1,   -1,  266,  267,  268,  269,   -1,   -1,   40,
  273,   -1,   43,   -1,   45,   -1,   -1,   -1,   29,   -1,
   -1,   32,   -1,   -1,   35,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   64,   -1,   46,   47,   48,   49,   50,
   -1,   -1,   -1,  257,  258,  259,  260,  261,  262,   -1,
   -1,   -1,  266,  267,  268,  269,   67,   -1,   -1,  273,
   91,   -1,   73,   74,   75,   76,   77,   78,   79,   80,
   81,   82,   83,   84,   85,   86,   87,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  123,   -1,   -1,  126,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  130,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  141,   -1,   -1,   -1,   -1,  146,  147,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  164,  165,   -1,  167,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  177,  178,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  186,  187,  188,   -1,   -1,
   -1,   -1,   -1,  194,   -1,  196,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,  260,
  261,  262,   -1,   -1,   -1,  266,  267,  268,  269,   -1,
   -1,   -1,  273,
};
#define YYFINAL 8
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 282
#define YYUNDFTOKEN 309
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,
0,0,0,0,0,"':'","';'","'<'","'='","'>'","'?'","'@'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"tINTEGER",
"tIDENTIFIER","tSTRING","tDOUBLE","tWHILE","tIF","tPRINTLN","tPUBLIC","tUSE",
"tSTOP","tNEXT","tRETURN","tSWEEP","tELSE","tELSEIF","tPROCEDURE","tNULL",
"tSTRING_TYPE","tINT_TYPE","tDOUBLE_TYPE","tIFX","tEQ","tNE","tGE","tLE",
"tUNARY",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : file",
"file : declarations",
"declarations : declarations declaration",
"declarations : declaration",
"declaration : variable ';'",
"declaration : function",
"variable : tPUBLIC tipo tIDENTIFIER '=' expr",
"variable : tPUBLIC tipo tIDENTIFIER",
"variable : tipo tIDENTIFIER '=' expr",
"variable : tipo tIDENTIFIER",
"variable : tUSE tipo tIDENTIFIER '=' expr",
"variable : tUSE tipo tIDENTIFIER",
"function : tipo tIDENTIFIER '(' args ')'",
"function : tPROCEDURE tIDENTIFIER '(' args ')'",
"function : tPUBLIC tipo tIDENTIFIER '(' args ')'",
"function : tPUBLIC tPROCEDURE tIDENTIFIER '(' args ')'",
"function : tUSE tipo tIDENTIFIER '(' args ')'",
"function : tUSE tPROCEDURE tIDENTIFIER '(' args ')'",
"function : tipo tIDENTIFIER '(' args ')' '=' literal",
"function : tipo tIDENTIFIER '(' args ')' '=' literal body",
"function : tPROCEDURE tIDENTIFIER '(' args ')' body",
"function : tPUBLIC tipo tIDENTIFIER '(' args ')' '=' literal body",
"function : tPUBLIC tPROCEDURE tIDENTIFIER '(' args ')' body",
"function : tipo tIDENTIFIER '(' args ')' body",
"function : tPUBLIC tipo tIDENTIFIER '(' args ')' body",
"tipo : tINT_TYPE",
"tipo : '[' tipo ']'",
"tipo : tSTRING_TYPE",
"tipo : tDOUBLE_TYPE",
"literal : string",
"literal : tDOUBLE",
"literal : tINTEGER",
"literal : tNULL",
"string : tSTRING",
"string : string tSTRING",
"body : bloco",
"bloco : '{' declarationsBlock '}'",
"bloco : '{' instrucoes '}'",
"bloco : '{' declarationsBlock instrucoes '}'",
"bloco : '{' '}'",
"declarationsBlock : variableBlock",
"declarationsBlock : declarationsBlock variableBlock",
"variableBlock : tipo tIDENTIFIER '=' expr ';'",
"variableBlock : tipo tIDENTIFIER ';'",
"instrucao : expr ';'",
"instrucao : expr '!'",
"instrucao : expr tPRINTLN",
"instrucao : bloco",
"instrucao : iteration",
"instrucao : cond",
"instrucao : tSTOP",
"instrucao : tNEXT",
"instrucao : tRETURN",
"instrucoes : instrucao",
"instrucoes : instrucoes instrucao",
"cond : tIF '(' expr ')' instrucao",
"cond : tIF '(' expr ')' instrucao tELSE instrucao",
"cond : tIF '(' expr ')' instrucao condCont",
"condCont : tELSEIF '(' expr ')' instrucao",
"condCont : tELSEIF '(' expr ')' instrucao tELSE instrucao",
"condCont : tELSEIF '(' expr ')' instrucao condCont",
"expr : literal",
"expr : '-' expr",
"expr : '+' expr",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '<' expr",
"expr : expr '>' expr",
"expr : expr tGE expr",
"expr : '@'",
"expr : expr tLE expr",
"expr : expr tNE expr",
"expr : expr tEQ expr",
"expr : expr '&' expr",
"expr : expr '|' expr",
"expr : '~' expr",
"expr : lval",
"expr : funcall",
"expr : '(' expr ')'",
"expr : lval '?'",
"expr : '[' expr ']'",
"expr : lval '=' expr",
"iteration : tWHILE '(' expr ')' instrucao",
"iteration : tSWEEP '+' '(' lval ':' expr ':' expr ':' expr ')' instrucao",
"iteration : tSWEEP '+' '(' lval ':' expr ':' expr ')' instrucao",
"iteration : tSWEEP '-' '(' lval ':' expr ':' expr ':' expr ')' instrucao",
"iteration : tSWEEP '-' '(' lval ':' expr ':' expr ')' instrucao",
"args : arg_func",
"args :",
"arg_func : arg_func ',' arg",
"arg_func : arg",
"arg : tipo tIDENTIFIER",
"funcall : tIDENTIFIER '(' expressoesMais ')'",
"expressoesMais : expressoes",
"expressoesMais :",
"expressoes : expressoes ',' expr",
"expressoes : expr",
"lval : tIDENTIFIER",
"lval : expr '[' expr ']'",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 75 "xpl_parser.y"
	{ compiler->ast(yystack.l_mark[0].sequence); }
break;
case 2:
#line 78 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE,yystack.l_mark[0].node,yystack.l_mark[-1].sequence); }
break;
case 3:
#line 79 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE,yystack.l_mark[0].node); }
break;
case 4:
#line 82 "xpl_parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 5:
#line 83 "xpl_parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 6:
#line 86 "xpl_parser.y"
	{ yyval.node = new xpl::variable_definition_node(LINE,yystack.l_mark[-2].s,yystack.l_mark[-3].type,yystack.l_mark[0].expression,true);  }
break;
case 7:
#line 87 "xpl_parser.y"
	{ yyval.node = new xpl::variable_declaration_node(LINE,yystack.l_mark[0].s,yystack.l_mark[-1].type,true,false);  }
break;
case 8:
#line 88 "xpl_parser.y"
	{ yyval.node = new xpl::variable_definition_node(LINE,yystack.l_mark[-2].s,yystack.l_mark[-3].type,yystack.l_mark[0].expression,false);  }
break;
case 9:
#line 89 "xpl_parser.y"
	{ yyval.node = new xpl::variable_declaration_node(LINE,yystack.l_mark[0].s,yystack.l_mark[-1].type,false,false);  }
break;
case 10:
#line 90 "xpl_parser.y"
	{ yyval.node = new xpl::variable_definition_node(LINE,yystack.l_mark[-2].s,yystack.l_mark[-3].type,yystack.l_mark[0].expression,false);  }
break;
case 11:
#line 91 "xpl_parser.y"
	{ yyval.node = new xpl::variable_declaration_node(LINE,yystack.l_mark[0].s,yystack.l_mark[-1].type,false,true);  }
break;
case 12:
#line 98 "xpl_parser.y"
	{yyval.node = new xpl::function_declaration_node(LINE, yystack.l_mark[-3].s, yystack.l_mark[-4].type, yystack.l_mark[-1].sequence, false, false);}
break;
case 13:
#line 99 "xpl_parser.y"
	{yyval.node = new xpl::function_declaration_node(LINE, yystack.l_mark[-3].s, new basic_type(0,basic_type::TYPE_VOID), yystack.l_mark[-1].sequence, false, false);}
break;
case 14:
#line 101 "xpl_parser.y"
	{yyval.node = new xpl::function_declaration_node(LINE, yystack.l_mark[-3].s, yystack.l_mark[-4].type, yystack.l_mark[-1].sequence, false, false);}
break;
case 15:
#line 102 "xpl_parser.y"
	{yyval.node = new xpl::function_declaration_node(LINE, yystack.l_mark[-3].s, new basic_type(0,basic_type::TYPE_VOID), yystack.l_mark[-1].sequence, false, false);}
break;
case 16:
#line 104 "xpl_parser.y"
	{yyval.node = new xpl::function_declaration_node(LINE, yystack.l_mark[-3].s, yystack.l_mark[-4].type, yystack.l_mark[-1].sequence, true, false);}
break;
case 17:
#line 105 "xpl_parser.y"
	{yyval.node = new xpl::function_declaration_node(LINE, yystack.l_mark[-3].s, new basic_type(0,basic_type::TYPE_VOID), yystack.l_mark[-1].sequence, true, false);}
break;
case 18:
#line 106 "xpl_parser.y"
	{yyval.node = new xpl::function_definition_node(LINE, yystack.l_mark[-5].s, yystack.l_mark[-6].type, yystack.l_mark[-3].sequence, yystack.l_mark[0].expression, nullptr, false);}
break;
case 19:
#line 108 "xpl_parser.y"
	{yyval.node = new xpl::function_definition_node(LINE, yystack.l_mark[-6].s, yystack.l_mark[-7].type, yystack.l_mark[-4].sequence, yystack.l_mark[-1].expression, yystack.l_mark[0].block, false);}
break;
case 20:
#line 109 "xpl_parser.y"
	{yyval.node = new xpl::function_definition_node(LINE, yystack.l_mark[-4].s, new basic_type(0,basic_type::TYPE_VOID), yystack.l_mark[-2].sequence, nullptr, yystack.l_mark[0].block,false);}
break;
case 21:
#line 111 "xpl_parser.y"
	{yyval.node = new xpl::function_definition_node(LINE, yystack.l_mark[-6].s, yystack.l_mark[-7].type, yystack.l_mark[-4].sequence, yystack.l_mark[-1].expression, yystack.l_mark[0].block,true);}
break;
case 22:
#line 112 "xpl_parser.y"
	{yyval.node = new xpl::function_definition_node(LINE, yystack.l_mark[-4].s, new basic_type(0,basic_type::TYPE_VOID), yystack.l_mark[-2].sequence, nullptr, yystack.l_mark[0].block, true);}
break;
case 23:
#line 114 "xpl_parser.y"
	{yyval.node = new xpl::function_definition_node(LINE, yystack.l_mark[-4].s, yystack.l_mark[-5].type, yystack.l_mark[-2].sequence, nullptr, yystack.l_mark[0].block, false);}
break;
case 24:
#line 115 "xpl_parser.y"
	{yyval.node = new xpl::function_definition_node(LINE, yystack.l_mark[-4].s, yystack.l_mark[-5].type, yystack.l_mark[-2].sequence, nullptr, yystack.l_mark[0].block, true);}
break;
case 25:
#line 122 "xpl_parser.y"
	{ yyval.type = new basic_type(4,basic_type::TYPE_INT);}
break;
case 26:
#line 123 "xpl_parser.y"
	{ yyval.type = new basic_type(4,basic_type::TYPE_POINTER); yyval.type->_subtype=yystack.l_mark[-1].type;}
break;
case 27:
#line 124 "xpl_parser.y"
	{ yyval.type = new basic_type(4,basic_type::TYPE_STRING);}
break;
case 28:
#line 125 "xpl_parser.y"
	{ yyval.type = new basic_type(8,basic_type::TYPE_DOUBLE);}
break;
case 29:
#line 128 "xpl_parser.y"
	{ yyval.expression = new cdk::string_node(LINE,yystack.l_mark[0].s);}
break;
case 30:
#line 129 "xpl_parser.y"
	{ yyval.expression = new cdk::double_node(LINE,yystack.l_mark[0].d);}
break;
case 31:
#line 130 "xpl_parser.y"
	{ yyval.expression = new cdk::integer_node(LINE,yystack.l_mark[0].i);}
break;
case 32:
#line 131 "xpl_parser.y"
	{ yyval.expression = new xpl::null_node(LINE);}
break;
case 33:
#line 134 "xpl_parser.y"
	{yyval.s = yystack.l_mark[0].s;}
break;
case 34:
#line 135 "xpl_parser.y"
	{ yyval.s = new std::string(*yystack.l_mark[-1].s + *yystack.l_mark[0].s); delete yystack.l_mark[0].s;}
break;
case 35:
#line 138 "xpl_parser.y"
	{yyval.block = yystack.l_mark[0].block;}
break;
case 36:
#line 141 "xpl_parser.y"
	{ yyval.block = new xpl::block_node(LINE, yystack.l_mark[-1].sequence,new cdk::sequence_node(LINE)); }
break;
case 37:
#line 142 "xpl_parser.y"
	{ yyval.block = new xpl::block_node(LINE, new cdk::sequence_node(LINE), yystack.l_mark[-1].sequence); }
break;
case 38:
#line 143 "xpl_parser.y"
	{ yyval.block = new xpl::block_node(LINE, yystack.l_mark[-2].sequence, yystack.l_mark[-1].sequence); }
break;
case 39:
#line 144 "xpl_parser.y"
	{ yyval.block = new xpl::block_node(LINE, new cdk::sequence_node(LINE),new cdk::sequence_node(LINE)); }
break;
case 40:
#line 148 "xpl_parser.y"
	{yyval.sequence = new cdk::sequence_node(LINE,yystack.l_mark[0].node);}
break;
case 41:
#line 149 "xpl_parser.y"
	{yyval.sequence = new cdk::sequence_node(LINE,yystack.l_mark[0].node,yystack.l_mark[-1].sequence);}
break;
case 42:
#line 152 "xpl_parser.y"
	{ yyval.node = new xpl::variable_definition_node(LINE,yystack.l_mark[-3].s,yystack.l_mark[-4].type,yystack.l_mark[-1].expression,false);  }
break;
case 43:
#line 153 "xpl_parser.y"
	{ yyval.node = new xpl::variable_declaration_node(LINE,yystack.l_mark[-1].s,yystack.l_mark[-2].type,false,false);  }
break;
case 44:
#line 156 "xpl_parser.y"
	{yyval.node = new xpl::evaluation_node(LINE, yystack.l_mark[-1].expression); }
break;
case 45:
#line 157 "xpl_parser.y"
	{yyval.node = new xpl::print_node(LINE, yystack.l_mark[-1].expression, false); }
break;
case 46:
#line 158 "xpl_parser.y"
	{yyval.node = new xpl::print_node(LINE, yystack.l_mark[-1].expression, true); }
break;
case 47:
#line 159 "xpl_parser.y"
	{yyval.node = yystack.l_mark[0].block;}
break;
case 48:
#line 160 "xpl_parser.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 49:
#line 161 "xpl_parser.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 50:
#line 162 "xpl_parser.y"
	{yyval.node =  new xpl::stop_node(LINE) ;}
break;
case 51:
#line 163 "xpl_parser.y"
	{yyval.node =  new xpl::next_node(LINE) ;}
break;
case 52:
#line 164 "xpl_parser.y"
	{yyval.node =  new xpl::return_node(LINE) ;}
break;
case 53:
#line 167 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node); }
break;
case 54:
#line 168 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node, yystack.l_mark[-1].sequence); }
break;
case 55:
#line 172 "xpl_parser.y"
	{yyval.node = new xpl::if_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].node);}
break;
case 56:
#line 173 "xpl_parser.y"
	{yyval.node = new xpl::if_else_node(LINE, yystack.l_mark[-4].expression, yystack.l_mark[-2].node, yystack.l_mark[0].node);}
break;
case 57:
#line 174 "xpl_parser.y"
	{yyval.node = new xpl::if_else_node(LINE, yystack.l_mark[-3].expression, yystack.l_mark[-1].node, yystack.l_mark[0].node);}
break;
case 58:
#line 177 "xpl_parser.y"
	{yyval.node = new xpl::if_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].node);}
break;
case 59:
#line 178 "xpl_parser.y"
	{yyval.node = new xpl::if_else_node(LINE, yystack.l_mark[-4].expression, yystack.l_mark[-2].node, yystack.l_mark[0].node);}
break;
case 60:
#line 179 "xpl_parser.y"
	{yyval.node = new xpl::if_else_node(LINE, yystack.l_mark[-3].expression, yystack.l_mark[-1].node, yystack.l_mark[0].node);}
break;
case 61:
#line 182 "xpl_parser.y"
	{ yyval.expression = yystack.l_mark[0].expression;}
break;
case 62:
#line 183 "xpl_parser.y"
	{ yyval.expression = new cdk::neg_node(LINE, yystack.l_mark[0].expression); }
break;
case 63:
#line 184 "xpl_parser.y"
	{ yyval.expression = new xpl::identity_node(LINE, yystack.l_mark[0].expression); }
break;
case 64:
#line 185 "xpl_parser.y"
	{ yyval.expression = new cdk::add_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 65:
#line 186 "xpl_parser.y"
	{ yyval.expression = new cdk::sub_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 66:
#line 187 "xpl_parser.y"
	{ yyval.expression = new cdk::mul_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 67:
#line 188 "xpl_parser.y"
	{ yyval.expression = new cdk::div_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 68:
#line 189 "xpl_parser.y"
	{ yyval.expression = new cdk::mod_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 69:
#line 190 "xpl_parser.y"
	{ yyval.expression = new cdk::lt_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 70:
#line 191 "xpl_parser.y"
	{ yyval.expression = new cdk::gt_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 71:
#line 192 "xpl_parser.y"
	{ yyval.expression = new cdk::ge_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 72:
#line 193 "xpl_parser.y"
	{ yyval.expression = new xpl::read_node(LINE); }
break;
case 73:
#line 194 "xpl_parser.y"
	{ yyval.expression = new cdk::le_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 74:
#line 195 "xpl_parser.y"
	{ yyval.expression = new cdk::ne_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 75:
#line 196 "xpl_parser.y"
	{ yyval.expression = new cdk::eq_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 76:
#line 197 "xpl_parser.y"
	{ yyval.expression = new cdk::and_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 77:
#line 198 "xpl_parser.y"
	{ yyval.expression = new cdk::or_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 78:
#line 199 "xpl_parser.y"
	{ yyval.expression = new cdk::not_node(LINE, yystack.l_mark[0].expression); }
break;
case 79:
#line 200 "xpl_parser.y"
	{ yyval.expression = new cdk::rvalue_node(LINE,yystack.l_mark[0].lvalue); }
break;
case 80:
#line 201 "xpl_parser.y"
	{ yyval.expression = yystack.l_mark[0].expression;}
break;
case 81:
#line 202 "xpl_parser.y"
	{ yyval.expression = yystack.l_mark[-1].expression; }
break;
case 82:
#line 203 "xpl_parser.y"
	{ yyval.expression = new xpl::memory_position_node(LINE, yystack.l_mark[-1].lvalue); }
break;
case 83:
#line 204 "xpl_parser.y"
	{ yyval.expression = new xpl::memory_reservation_node(LINE, yystack.l_mark[-1].expression); }
break;
case 84:
#line 205 "xpl_parser.y"
	{ yyval.expression = new cdk::assignment_node(LINE, yystack.l_mark[-2].lvalue, yystack.l_mark[0].expression); }
break;
case 85:
#line 209 "xpl_parser.y"
	{ yyval.node = new xpl::while_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].node); }
break;
case 86:
#line 210 "xpl_parser.y"
	{ yyval.node = new xpl::sweep_plus_node(LINE, yystack.l_mark[-8].lvalue, yystack.l_mark[-6].expression,yystack.l_mark[-4].expression,yystack.l_mark[-2].expression,yystack.l_mark[0].node); }
break;
case 87:
#line 211 "xpl_parser.y"
	{ yyval.node = new xpl::sweep_plus_node(LINE, yystack.l_mark[-6].lvalue, yystack.l_mark[-4].expression,yystack.l_mark[-2].expression,yystack.l_mark[0].node); }
break;
case 88:
#line 212 "xpl_parser.y"
	{ yyval.node = new xpl::sweep_minus_node(LINE, yystack.l_mark[-8].lvalue, yystack.l_mark[-6].expression,yystack.l_mark[-4].expression,yystack.l_mark[-2].expression,yystack.l_mark[0].node); }
break;
case 89:
#line 213 "xpl_parser.y"
	{ yyval.node = new xpl::sweep_minus_node(LINE, yystack.l_mark[-6].lvalue, yystack.l_mark[-4].expression,yystack.l_mark[-2].expression,yystack.l_mark[0].node); }
break;
case 90:
#line 216 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE,yystack.l_mark[0].sequence); }
break;
case 91:
#line 217 "xpl_parser.y"
	{yyval.sequence = new cdk::sequence_node(LINE);}
break;
case 92:
#line 221 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE,yystack.l_mark[0].node,yystack.l_mark[-2].sequence);  }
break;
case 93:
#line 222 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node, new cdk::sequence_node(LINE));  }
break;
case 94:
#line 225 "xpl_parser.y"
	{ yyval.node = new xpl::variable_declaration_node(LINE,yystack.l_mark[0].s,yystack.l_mark[-1].type,false,false);  }
break;
case 95:
#line 228 "xpl_parser.y"
	{ yyval.expression = new xpl::function_call_node(LINE,yystack.l_mark[-3].s,yystack.l_mark[-1].sequence);}
break;
case 96:
#line 231 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE,yystack.l_mark[0].sequence);  }
break;
case 97:
#line 232 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE);  }
break;
case 98:
#line 235 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE,yystack.l_mark[0].expression,yystack.l_mark[-2].sequence);  }
break;
case 99:
#line 236 "xpl_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE,yystack.l_mark[0].expression);  }
break;
case 100:
#line 239 "xpl_parser.y"
	{ yyval.lvalue = new cdk::identifier_node(LINE, yystack.l_mark[0].s); delete yystack.l_mark[0].s;}
break;
case 101:
#line 240 "xpl_parser.y"
	{ yyval.lvalue = new xpl::indexation_node(LINE, yystack.l_mark[-1].expression, yystack.l_mark[-3].expression);}
break;
#line 1356 "xpl_parser.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
