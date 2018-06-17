#ifndef __XPL_MEMORY_POSITION_NODE_H__
#define __XPL_MEMORY_POSITION_NODE_H__

#include <cdk/ast/expression_node.h>


namespace xpl {

  /**
   * Class for describing memory adress of variable nodes.
   */
  class memory_position_node: public cdk::unary_expression_node {

  public:
    inline memory_position_node(int lineno, cdk::lvalue_node* lvalue) :
        unary_expression_node(lineno, lvalue) {
    }

  public:

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_memory_position_node(this, level);
    }

  };

}
#endif
