// $Id: next_node.h,v 1.3 2017/05/19 09:16:02 ist180970 Exp $ -*- c++ -*-
#ifndef __XPL_NEXT_NODE_H__ 
#define __XPL_NEXT_NODE_H__

#include <cdk/ast/expression_node.h>

namespace xpl { 

  /**
   * Class for describing while-cycle nodes.
   */
  class next_node: public cdk::basic_node {

  public:
    inline next_node(int lineno) :
        cdk::basic_node(lineno) {
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_next_node(this, level);
    }

  };

} // xpl

#endif