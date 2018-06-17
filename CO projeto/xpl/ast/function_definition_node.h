#ifndef __XPL_FUNCTION_DEFINITION_NODE_H__
#define __XPL_FUNCTION_DEFINITION_NODE_H__

#include <cdk/ast/expression_node.h>
#include <cdk/ast/sequence_node.h>
#include <cdk/basic_type.h>

namespace xpl {
  class function_definition_node: public cdk::basic_node {
    std::string* _name;
    basic_type* _type;
    cdk::sequence_node* _arguments;
    cdk::expression_node* _expression;
    block_node* _block;
    bool _public_indicator;

  public:
    inline function_definition_node(int lineno, std::string* name, basic_type* type, cdk::sequence_node* arguments, cdk::expression_node* expression, block_node* block, bool public_indicator) :
        basic_node(lineno), _name(name), _type(type), _arguments(arguments), _expression(expression) ,_block(block), _public_indicator(public_indicator){
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
    inline cdk::expression_node* expression(){
      return _expression;
    }    
    inline block_node* block(){
      return _block;
    }

    inline bool public_indicator(){
      return _public_indicator;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_definition_node(this, level);
    }

  };

} // xpl
#endif
