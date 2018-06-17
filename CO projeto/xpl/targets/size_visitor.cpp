#include <string>
#include <sstream>
#include "targets/size_visitor.h"
#include "ast/all.h"  

	void xpl::size_visitor::do_variable_declaration_node(xpl::variable_declaration_node * const node, int lvl) {
		_size += node->type()->size();
	}

	void xpl::size_visitor::do_variable_definition_node(xpl::variable_definition_node * const node, int lvl) {
		_size += node->type()->size();
	}

	void xpl::size_visitor::do_function_definition_node(xpl::function_definition_node * const node, int lvl)	{
	if (node->block() != nullptr)
		node->block()->accept(this, lvl);
	_size += node->type()->size();
	}


	void xpl::size_visitor::do_block_node(xpl::block_node * const node, int lvl) 	{
	if (node->declaration() != nullptr)
		node->declaration()->accept(this,lvl);

	if (node->code() != nullptr)
		node->code()->accept(this,lvl);

	}

	void xpl::size_visitor::do_sequence_node(cdk::sequence_node * const node, int lvl) {
	for (size_t i = 0; i < node->size(); i++) {
	     node->node(i)->accept(this, lvl);
	 }
	}
	   
