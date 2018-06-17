// $Id: print_node.h,v 1.4 2017/05/19 19:12:08 ist180970 Exp $ -*- c++ -*-
#ifndef __XPL_PRINT_NODE_H__
#define __XPL_PRINT_NODE_H__

#include <cdk/ast/expression_node.h>

namespace xpl {

  /**
   * Class for describing print nodes.
   */
  class print_node: public cdk::basic_node {
    cdk::expression_node *_argument;
    bool _line;

  public:
    inline print_node(int lineno, cdk::expression_node *argument,  bool line) :
        cdk::basic_node(lineno), _argument(argument), _line(line) {
    }

  public:
    inline cdk::expression_node *argument() {
      return _argument;
    }


    inline bool line(){
      return _line;
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_print_node(this, level);
    }

  };

} // xpl

#endif
