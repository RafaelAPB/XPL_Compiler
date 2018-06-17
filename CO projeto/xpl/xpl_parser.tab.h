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
extern YYSTYPE yylval;
