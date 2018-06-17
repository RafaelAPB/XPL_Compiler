// $Id: read_node.h,v 1.5 2017/04/18 14:09:51 ist180970 Exp $ -*- c++ -*-
#ifndef __XPL_READ_NODE_H__
#define __XPL_READ_NODE_H__

#include <cdk/ast/expression_node.h>

namespace xpl {

  /**
   * Class for describing read nodes.
   */
  class read_node: public cdk::expression_node {


  public:
    inline read_node(int lineno) :
        cdk::expression_node(lineno) {
    }


    void accept(basic_ast_visitor *sp, int level) {
      sp->do_read_node(this, level);
    }

  };

} // xpl

#endif
