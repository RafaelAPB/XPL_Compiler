#ifndef __XPL_FUNCTION_DECLARATION_NODE_H__
#define __XPL_FUNCTION_DECLARATION_NODE_H__

#include <cdk/ast/sequence_node.h>
#include <cdk/basic_type.h>
#include <string>

namespace xpl {

  /**
   * Class for describing function_declaration_node nodes.
   */
  class function_declaration_node: public cdk::basic_node {
    std::string* _name;
    basic_type* _type;
    cdk::sequence_node* _arguments;
    bool _use;
    bool _public_indicator;

  public:
    inline function_declaration_node(int lineno, std::string* name, basic_type* type, cdk::sequence_node* arguments, bool use, bool public_indicator) :
        basic_node(lineno),_name(name), _type(type), _arguments(arguments), _use(use), _public_indicator(public_indicator){
    }

  public:
    inline std::string *name() {
      return _name;
    }
    inline basic_type* type(){
      return _type;
    }
    inline cdk::sequence_node* arguments(){
      return _arguments;
    }
    inline bool use(){
      return _use;
    }
    inline bool public_indicator(){
      return _public_indicator;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_declaration_node(this, level);
    }

  };

} // xpl
#endif
