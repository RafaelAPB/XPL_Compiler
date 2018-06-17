#ifndef __XPL_VARIABLE_DEFINITION_NODE_H__
#define __XPL_VARIABLE_DEFINITION_NODE_H__

#include <cdk/ast/expression_node.h>
#include <string>


namespace xpl {

  /**
   * Class for describing variable definition nodes.
   */
  class variable_definition_node: public cdk::basic_node {
    std::string *_name;
    basic_type* _type;
    cdk::expression_node *_content;
    bool _public_indicator;

  public:
    inline variable_definition_node(int lineno, std::string *string, basic_type *type, cdk::expression_node *content, bool public_indicator) :
        cdk::basic_node(lineno), _name(string), _type(type), _content(content), _public_indicator(public_indicator){
    }

  public:
    inline cdk::expression_node *content() {
      return _content;
    }
    inline std::string *name() {
      return _name;
    }
    inline basic_type *type(){
      return _type;
    }
    inline bool public_indicator(){
      return _public_indicator;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_variable_definition_node(this, level);
    }

  };

} // xpl

#endif
