#ifndef __XPL_MEMORY_RESERVATION_NODE_H__
#define __XPL_MEMORY_RESERVATION_NODE_H__

#include <cdk/ast/unary_expression_node.h>
#include <cdk/ast/expression_node.h>
namespace xpl {

  class memory_reservation_node: public cdk::unary_expression_node {

  public:
    inline memory_reservation_node(int lineno,cdk::expression_node *expression):
        cdk::unary_expression_node(lineno,expression){
    }

  public:

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_memory_reservation_node(this, level);
    }

  };

}
#endif
