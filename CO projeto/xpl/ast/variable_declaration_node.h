#ifndef __XPL_VARIABLE_DECLARATION_NODE_H__
#define __XPL_VARIABLE_DECLARATION_NODE_H__

#include <string>


namespace xpl {

  /**
   * Class for describing variable declaration nodes.
   */
  class variable_declaration_node: public cdk::basic_node {
    std::string *_name;
    basic_type* _type;
    bool _public_indicator;
    bool _use_indicator;

  public:
    inline variable_declaration_node(int lineno, std::string *name, basic_type *type, bool public_indicator, bool use_indicator) :
        cdk::basic_node(lineno), _name(name), _type(type), _public_indicator(public_indicator), _use_indicator(use_indicator){
    }

  public:
    inline std::string *name() {
      return _name;
    }
    inline basic_type *type(){
      return _type;
    }
    inline bool public_indicator(){
      return _public_indicator;
    }
    inline bool use_indicator(){
      return _use_indicator;
    }

   void accept(basic_ast_visitor *sp, int level) {
      sp->do_variable_declaration_node(this, level);
    }

  };

} // xpl

#endif
