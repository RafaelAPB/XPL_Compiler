#include <string>
#include "targets/xml_writer.h"
#include "targets/type_checker.h"
#include "ast/all.h"  // automatically generated

//---------------------------------------------------------------------------

void xpl::xml_writer::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  os() << std::string(lvl, ' ') << "<sequence_node size='" << node->size() << "'>" << std::endl;
  for (size_t i = 0; i < node->size(); i++)
    node->node(i)->accept(this, lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void xpl::xml_writer::do_integer_node(cdk::integer_node * const node, int lvl) {
  process_literal(node, lvl);
}

void xpl::xml_writer::do_string_node(cdk::string_node * const node, int lvl) {
  process_literal(node, lvl);
}

//---------------------------------------------------------------------------

inline void xpl::xml_writer::do_unary_expression(cdk::unary_expression_node * const node, int lvl) {
  //ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void xpl::xml_writer::do_neg_node(cdk::neg_node * const node, int lvl) {
  do_unary_expression(node, lvl);
}

//---------------------------------------------------------------------------

inline void xpl::xml_writer::do_binary_expression(cdk::binary_expression_node * const node, int lvl) {
  //ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void xpl::xml_writer::do_add_node(cdk::add_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void xpl::xml_writer::do_sub_node(cdk::sub_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void xpl::xml_writer::do_mul_node(cdk::mul_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void xpl::xml_writer::do_div_node(cdk::div_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void xpl::xml_writer::do_mod_node(cdk::mod_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void xpl::xml_writer::do_lt_node(cdk::lt_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void xpl::xml_writer::do_le_node(cdk::le_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void xpl::xml_writer::do_ge_node(cdk::ge_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void xpl::xml_writer::do_gt_node(cdk::gt_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void xpl::xml_writer::do_ne_node(cdk::ne_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void xpl::xml_writer::do_eq_node(cdk::eq_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}

//---------------------------------------------------------------------------

void xpl::xml_writer::do_identifier_node(cdk::identifier_node * const node, int lvl) {
  //ASSERT_SAFE_EXPRESSIONS;
  os() << std::string(lvl, ' ') << "<" << node->label() << ">" << node->name() << "</" << node->label() << ">" << std::endl;
}

void xpl::xml_writer::do_rvalue_node(cdk::rvalue_node * const node, int lvl) {
  //ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->lvalue()->accept(this, lvl + 4);
  closeTag(node, lvl);
}

void xpl::xml_writer::do_assignment_node(cdk::assignment_node * const node, int lvl) {
  //ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);

  node->lvalue()->accept(this, lvl);
  reset_new_symbol();

  node->rvalue()->accept(this, lvl + 4);
  closeTag(node, lvl);
}

void xpl::xml_writer::do_evaluation_node(xpl::evaluation_node * const node, int lvl) {
  //ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void xpl::xml_writer::do_print_node(xpl::print_node * const node, int lvl) {
  //ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void xpl::xml_writer::do_read_node(xpl::read_node * const node, int lvl) {
  //ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void xpl::xml_writer::do_while_node(xpl::while_node * const node, int lvl) {
  //ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("block", lvl + 2);
  node->block()->accept(this, lvl + 4);
  closeTag("block", lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void xpl::xml_writer::do_if_node(xpl::if_node * const node, int lvl) {
  //ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("then", lvl + 2);
  node->block()->accept(this, lvl + 4);
  closeTag("then", lvl + 2);
  closeTag(node, lvl);
}

void xpl::xml_writer::do_if_else_node(xpl::if_else_node * const node, int lvl) {
  //ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("then", lvl + 2);
  node->thenblock()->accept(this, lvl + 4);
  closeTag("then", lvl + 2);
  openTag("else", lvl + 2);
  node->elseblock()->accept(this, lvl + 4);
  closeTag("else", lvl + 2);
  closeTag(node, lvl);
}

void xpl::xml_writer::do_stop_node(xpl::stop_node * const node, int lvl) {
  //ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  closeTag(node, lvl);
}
void xpl::xml_writer::do_next_node(xpl::next_node * const node, int lvl) {
  //ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  closeTag(node, lvl);
}
void xpl::xml_writer::do_return_node(xpl::return_node * const node, int lvl) {
  //ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  closeTag(node, lvl);
}

void xpl::xml_writer::do_sweep_plus_node(xpl::sweep_plus_node * const node, int lvl){
  //ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);

    openTag("inicialization", lvl + 2);
    node->inicialization()->accept(this, lvl + 4);
    closeTag("inicialization", lvl + 2);

    openTag("condition", lvl + 2);
    node->condition()->accept(this, lvl + 4);
    closeTag("condition", lvl + 2);

    openTag("increment", lvl + 2);
    node->increment()->accept(this, lvl + 4);
    closeTag("increment", lvl + 2);    

     openTag("block", lvl + 2);
    node->block()->accept(this, lvl + 4);
    closeTag("block", lvl + 2); 

    openTag("left", lvl + 2);
    node->left()->accept(this, lvl + 4);
    closeTag("left", lvl + 2);

  closeTag(node, lvl);

}

void xpl::xml_writer::do_sweep_minus_node(xpl::sweep_minus_node * const node, int lvl){
  //ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);

    openTag("inicialization", lvl + 2);
    node->inicialization()->accept(this, lvl + 4);
    closeTag("inicialization", lvl + 2);

    openTag("condition", lvl + 2);
    node->condition()->accept(this, lvl + 4);
    closeTag("condition", lvl + 2);

    openTag("increment", lvl + 2);
    node->increment()->accept(this, lvl + 4);
    closeTag("increment", lvl + 2);    

     openTag("block", lvl + 2);
    node->block()->accept(this, lvl + 4);
    closeTag("block", lvl + 2); 

    openTag("left", lvl + 2);
    node->left()->accept(this, lvl + 4);
    closeTag("left", lvl + 2);
    
  closeTag(node, lvl);

}

void xpl::xml_writer::do_block_node(xpl::block_node * const node, int lvl){
  //ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
    if(node->declaration()!=nullptr){
        openTag("declarations", lvl + 2);
        node->declaration()->accept(this, lvl + 4);
        closeTag("declarations", lvl + 2);
    }

    openTag("instructions", lvl + 2);
    node->code()->accept(this, lvl + 4);
    closeTag("instructions", lvl + 2);
  closeTag(node, lvl);
}
//---------------------------------------------------------------------------
void xpl::xml_writer::do_variable_definition_node(xpl::variable_definition_node * const node, int lvl){
  //ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);

    if(node->public_indicator()){
      openTag("public", lvl + 2);
      closeTag("public", lvl + 2);
    }
  
    process_name(*node->name(), lvl+2);
    process_type(node->type(),lvl+2);

    openTag("var_content", lvl + 2);
    node->content()->accept(this, lvl + 4);
    closeTag("var_content", lvl + 2);

  closeTag(node, lvl);
}

//---------------------------------------------------------------------------
void xpl::xml_writer::do_variable_declaration_node(xpl::variable_declaration_node * const node, int lvl){
  //ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);

  if(node->use_indicator()){
      openTag("use", lvl + 2);
      closeTag("use", lvl + 2);
  }
  if(node->public_indicator()){
    openTag("public", lvl + 2);
    closeTag("public", lvl + 2);
  }
  process_name(*node->name(), lvl+2);
  process_type(node->type(),lvl+2);

  closeTag(node, lvl);
}
//---------------------------------------------------------------------------
void xpl::xml_writer::do_null_node(xpl::null_node * const node, int lvl){
  //ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  closeTag(node, lvl);
}
//---------------------------------------------------------------------------
void xpl::xml_writer::do_memory_position_node(xpl::memory_position_node * const node, int lvl){
  do_unary_expression(node, lvl);
}
//---------------------------------------------------------------------------
void xpl::xml_writer::do_indexation_node(xpl::indexation_node * const node, int lvl){
  //ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);

    openTag("expression", lvl + 2);
    node->expression()->accept(this, lvl + 4);
    closeTag("expression", lvl + 2);

    openTag("expression2", lvl + 2);
    node->expression2()->accept(this, lvl + 4);
    closeTag("expression2", lvl + 2);


  closeTag(node, lvl);
}
//---------------------------------------------------------------------------
void xpl::xml_writer::do_memory_reservation_node(xpl::memory_reservation_node* const node, int lvl){
    do_unary_expression(node, lvl);
 /* 
 openTag(node, lvl);
  openTag("size", lvl + 2);
  node->expression()->accept(this, lvl + 4);
  closeTag("size", lvl + 2);
  closeTag(node, lvl);
  */
}
//---------------------------------------------------------------------------
void xpl::xml_writer::do_identity_node(xpl::identity_node * const node, int lvl){
  do_unary_expression(node, lvl);
}
//--------------------------------------------------------------------------
void xpl::xml_writer::do_function_declaration_node(xpl::function_declaration_node * const node, int lvl){
  //ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);

    if (node->use())  {
      openTag("use", lvl + 2);
      closeTag("use", lvl + 2);    
    }

    if (node->public_indicator())  {
      openTag("public", lvl + 2);
      closeTag("public", lvl + 2);    
    }

    process_name(*node->name(), lvl+2);
    process_type(node->type(),lvl+2);

    openTag("arguments", lvl + 2);
    node->arguments()->accept(this, lvl + 4);
    closeTag("arguments", lvl + 2);

  closeTag(node, lvl);
}

//---------------------------------------------------------------------------
void xpl::xml_writer::do_function_call_node(xpl::function_call_node * const node, int lvl){
  //ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);

  process_name(*node->name(), lvl+2);

  openTag("arguments", lvl + 2);
  node->arguments()->accept(this, lvl + 4);
  closeTag("arguments", lvl + 2);

  closeTag(node, lvl);
}

//---------------------------------------------------------------------------
void xpl::xml_writer::do_function_definition_node(xpl::function_definition_node * const node, int lvl){
  //ASSERT_SAFE_EXPRESSIONS;     
  openTag(node, lvl);
  //TODO: INNER TAG - add inner tag function
    if(node->public_indicator()){
      openTag("public", lvl + 2);
      closeTag("public", lvl + 2);
    }
    process_name(*node->name(), lvl+2);
    process_type(node->type(),lvl+2);

    openTag("arguments", lvl + 2);
    node->arguments()->accept(this, lvl + 4);
    closeTag("arguments", lvl + 2);

   if(node->expression()!=nullptr){
    openTag("expression", lvl + 2);
    node->expression()->accept(this, lvl + 4);
    closeTag("expression", lvl + 2);
  }
    openTag("block", lvl + 2);
    node->block()->accept(this, lvl + 4);
    closeTag("block", lvl + 2);

  closeTag(node, lvl);
}