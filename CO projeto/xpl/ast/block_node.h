// $Id: block_node.h,v 1.4 2017/05/19 09:16:02 ist180970 Exp $
#ifndef __XPL_BLOCK_NODE_H__
#define __XPL_BLOCK_NODE_H__

#include <cdk/ast/sequence_node.h>

namespace xpl {

  /**
   * Class for describing evaluation nodes.
   */
  class block_node: public cdk::basic_node {
    cdk::sequence_node *_declaration;
    cdk::sequence_node *_code;

  public:
    inline block_node(int lineno, cdk::sequence_node *declaration, cdk::sequence_node *code) :
        cdk::basic_node(lineno), _declaration(declaration), _code(code) {
    }

  public:
    inline cdk::sequence_node *declaration() {
      return _declaration;
    }

    inline cdk::sequence_node *code() {
      return _code;
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_block_node(this, level);
    }

  };

} // xpl

#endif
