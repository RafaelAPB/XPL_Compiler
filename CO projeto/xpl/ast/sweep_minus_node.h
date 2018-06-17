#ifndef __XPL_SWEEP_MINUS_H__
#define __XPL_SWEEP_MINUS_H__

#include <cdk/ast/expression_node.h>
#include <cdk/ast/lvalue_node.h>
#include <cdk/ast/basic_node.h>

namespace xpl {

  class sweep_minus_node: public cdk::basic_node {
    cdk::lvalue_node* _left;
    cdk::expression_node *_inicialization;
    cdk::expression_node *_condition;
    cdk::expression_node *_increment;
    cdk::basic_node *_block;

  public:
    inline sweep_minus_node(int lineno,cdk::lvalue_node *left,cdk::expression_node *inicialization,cdk::expression_node *condition,cdk::expression_node *increment,cdk::basic_node *block):
        cdk::basic_node(lineno),_left(left),_inicialization(inicialization), _condition(condition), _increment(increment), _block(block){
    }
    inline sweep_minus_node(int lineno,cdk::lvalue_node *left,cdk::expression_node *inicialization,cdk::expression_node *condition,cdk::basic_node *block):
        cdk::basic_node(lineno),_left(left),_inicialization(inicialization), _condition(condition), _block(block){
          _increment= new cdk::integer_node(lineno,1);
    }
  public:
    inline cdk::expression_node *inicialization() {
      return _inicialization;
    }
    inline cdk::expression_node *condition() {
      return _condition;
    }
    inline cdk::expression_node *increment() {
      return _increment;
    }
    inline cdk::basic_node *block() {
      return _block;
    }
    inline cdk::basic_node *left() {
      return _left;
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_sweep_minus_node(this, level);
    }

  };

} // xpl

#endif
