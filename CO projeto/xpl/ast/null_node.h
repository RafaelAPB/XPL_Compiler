#ifndef __XPL_NULL_NODE_H__
#define __XPL_NULL_NODE_H__

#include <cdk/ast/expression_node.h>

namespace xpl {

  class null_node: public cdk::expression_node{

  public:
    inline null_node(int lineno) :
        cdk::expression_node(lineno) {
    }

  public:

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_null_node(this, level);
    }

  };

}
#endif
