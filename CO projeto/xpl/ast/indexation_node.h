#ifndef __XPL_INDEXATIONNODE_H__
#define __XPL_INDEXATIONNODE_H__

#include <cdk/ast/expression_node.h>


namespace xpl {

  /**
   * Class for describing indexation node.
   */
  class indexation_node: public cdk::lvalue_node {
    cdk::expression_node* _expression;
    cdk::expression_node* _expression2;

  public:
    inline indexation_node(int lineno, cdk::expression_node *expression, cdk::expression_node *expression2) :
        lvalue_node(lineno), _expression(expression), _expression2(expression2) {
    }

  public:
    inline cdk::expression_node *expression() {
      return _expression;
    }
    inline cdk::expression_node *expression2() {
      return _expression2;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_indexation_node(this, level);
    }

  };

} // xpl

#endif
