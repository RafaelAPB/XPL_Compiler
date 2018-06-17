#include <string>
#include <sstream>
#include "targets/type_checker.h"
#include "targets/postfix_writer.h"
#include "targets/size_visitor.h"
#include "ast/all.h"  // all.h is automatically generated



//---------------------------------------------------------------------------

void xpl::postfix_writer::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  for (size_t i = 0; i < node->size(); i++) {
    node->node(i)->accept(this, lvl);
  }
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_integer_node(cdk::integer_node * const node, int lvl) {
  if (_definition)	{

    _pf.CONST(node->value());  
  }
  else 
    _pf.INT(node->value());
}	

void xpl::postfix_writer::do_string_node(cdk::string_node * const node, int lvl) {
   ASSERT_SAFE_EXPRESSIONS; 
   int strlbl = ++_lbl;
  /* generate the string */
  _pf.RODATA(); // strings are DATA readonly
  _pf.ALIGN(); // make sure we are aligned
  _pf.LABEL(mklbl(strlbl)); // give the string a name

  _pf.STR(node->value()); // output string characters

  /* leave the address on the stack */
  if (_definition) { 

	_pf.DATA();
	_pf.ALIGN();				//Contexto local
    _pf.GLOBAL(_name,_pf.OBJ());
    _pf.LABEL(_name);
    _pf.ID(mklbl(strlbl));
  }

  _pf.TEXT(); // return to the TEXT segment
  _pf.ADDR(mklbl(strlbl)); // the string to be printed

}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_neg_node(cdk::neg_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl); // determine the value
  _pf.NEG(); // 2-complement
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_add_node(cdk::add_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.ADD();
}
void xpl::postfix_writer::do_sub_node(cdk::sub_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.SUB();
}
void xpl::postfix_writer::do_mul_node(cdk::mul_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.MUL();
}
void xpl::postfix_writer::do_div_node(cdk::div_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.DIV();
}
void xpl::postfix_writer::do_mod_node(cdk::mod_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.MOD();
}
void xpl::postfix_writer::do_lt_node(cdk::lt_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.LT();
}
void xpl::postfix_writer::do_le_node(cdk::le_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.LE();
}
void xpl::postfix_writer::do_ge_node(cdk::ge_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.GE();
}
void xpl::postfix_writer::do_gt_node(cdk::gt_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.GT();
}
void xpl::postfix_writer::do_ne_node(cdk::ne_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.NE();
}
void xpl::postfix_writer::do_eq_node(cdk::eq_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.EQ();
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_identifier_node(cdk::identifier_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  _name = node->name();
  std::shared_ptr<xpl::symbol> symbol = _symtab.find(_name);
  if (symbol->offset() < 0) 
    _pf.LOCAL(symbol->offset());
  else {
    _pf.ADDR(node->name());
  }

}

void xpl::postfix_writer::do_rvalue_node(cdk::rvalue_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->lvalue()->accept(this, lvl);
  _pf.LOAD(); // depends on type size
}

void xpl::postfix_writer::do_assignment_node(cdk::assignment_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->rvalue()->accept(this, lvl); // determine the new value
  _pf.DUP();
  if (new_symbol() == nullptr) {
    node->lvalue()->accept(this, lvl); // where to store the value
  } else {
    _pf.DATA(); // variables are all global and live in DATA
    _pf.ALIGN(); // make sure we are aligned
    _pf.LABEL(new_symbol()->name()); // name variable location
    _pf.CONST(0); // initialize it to 0 (zero)
    _pf.TEXT(); // return to the TEXT segment
    node->lvalue()->accept(this, lvl);  //DAVID: bah!
  }
  _pf.STORE(); // store the value at address
}


//---------------------------------------------------------------------------

void xpl::postfix_writer::do_evaluation_node(xpl::evaluation_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl); // determine the value
  if (node->argument()->type()->name() == basic_type::TYPE_INT) {
    _pf.TRASH(4); // delete the evaluated value
  } else if (node->argument()->type()->name() == basic_type::TYPE_STRING) {
    _pf.TRASH(4); // delete the evaluated value's address
  } else {
    std::cerr << "ERROR: CANNOT HAPPEN!" << std::endl;
    exit(1);
  }
}
;
void xpl::postfix_writer::do_print_node(xpl::print_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl); // determine the value to print
  if (node->argument()->type()->name() == basic_type::TYPE_INT) {
    _pf.CALL("printi");
    _pf.TRASH(4); // delete the printed value
  } else if (node->argument()->type()->name() == basic_type::TYPE_STRING) {
    _pf.CALL("prints");
    _pf.TRASH(4); // delete the printed value's address
  } else {
    std::cerr << "ERROR: CANNOT HAPPEN!" << std::endl;
    exit(1);
    if (node->line())	{
    	_pf.CALL("println"); // print a newline
    }
  }
 
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_read_node(xpl::read_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  _pf.CALL("readi");
  _pf.PUSH();
  _pf.STORE();
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_while_node(xpl::while_node * const node, int lvl) {
   ASSERT_SAFE_EXPRESSIONS;
  int condicao = ++_lbl;
  int fim_while = ++_lbl;

  std::string LABEL_CONDICAO = mklbl(condicao);
  std::string LABEL_FIM_WHILE = mklbl(fim_while);

  _labels_stop.push_back(LABEL_FIM_WHILE);
  _labels_next.push_back(LABEL_CONDICAO);

  _pf.LABEL(LABEL_CONDICAO);
  node->condition()->accept(this, lvl);
  _pf.JZ(LABEL_FIM_WHILE);
  node->block()->accept(this, lvl + 2);
  _pf.JMP(LABEL_CONDICAO);
  
  _pf.LABEL(LABEL_FIM_WHILE);

  _labels_stop.pop_back();
  _labels_next.pop_back();

}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_if_node(xpl::if_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lbl1;
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl1 = ++_lbl));
  node->block()->accept(this, lvl + 2);
  _pf.LABEL(mklbl(lbl1));
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_if_else_node(xpl::if_else_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lbl1, lbl2;
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl1 = ++_lbl));
  node->thenblock()->accept(this, lvl + 2);
  _pf.JMP(mklbl(lbl2 = ++_lbl));
  _pf.LABEL(mklbl(lbl1));
  node->elseblock()->accept(this, lvl + 2);
  _pf.LABEL(mklbl(lbl1 = lbl2));
}

//---------------------------------------------------------------------------

void xpl::postfix_writer::do_stop_node(xpl::stop_node * const node, int lvl) {

  if(_labels_stop.size()>0)
  	_pf.JMP(_labels_stop.back());
  else
  	throw std::string("Nao ha labels stop"); 
    
  
}
//---------------------------------------------------------------------------
void xpl::postfix_writer::do_next_node(xpl::next_node * const node, int lvl) {
  
  if(_labels_next.size() >= 0)
  	_pf.JMP((_labels_next.back()));
  else
  	throw std::string("Nao ha labels next"); 
    
//---------------------------------------------------------------------------
}
void xpl::postfix_writer::do_return_node(xpl::return_node * const node, int lvl) {
  //TODO
}

//---------------------------------------------------------------------------
void xpl::postfix_writer::do_sweep_plus_node(xpl::sweep_plus_node * const node, int lvl){
   ASSERT_SAFE_EXPRESSIONS;
  int comparacao_sweep = ++_lbl;
  int incremento_sweep = ++_lbl;
  int fim_sweep = ++_lbl;

  std::string LABEL_FIM_SWEEP = mklbl(fim_sweep);
  std::string LABEL_COMPARACAO_SWEEP = mklbl(comparacao_sweep);
  std::string LABEL_INCREMENTO_SWEEP = mklbl(incremento_sweep);

  //Insert labels, to next and stop instruction
  _labels_stop.push_back(LABEL_FIM_SWEEP);
  _labels_next.push_back(LABEL_INCREMENTO_SWEEP);

  //Saves inicialization into lvalue
  node->inicialization()->accept(this,lvl);
  node->left()->accept(this,lvl);
  _pf.STORE();

  _pf.LABEL(LABEL_COMPARACAO_SWEEP); 		
  node->left()->accept(this,lvl);					
  _pf.LOAD();
  node->condition()->accept(this, lvl);				


  _pf.LE();
  _pf.JZ(LABEL_FIM_SWEEP);


  node->block()->accept(this, lvl + 2);			
 _pf.LABEL(LABEL_INCREMENTO_SWEEP);

    node->increment()->accept(this,lvl);
  _pf.DUP();
  node->left()->accept(this,lvl);					
  _pf.LOAD();
  _pf.ADD();
    node->left()->accept(this,lvl);

  _pf.STORE();
  _pf.TRASH(4);

  _pf.JMP(LABEL_COMPARACAO_SWEEP);
  _pf.LABEL(LABEL_FIM_SWEEP);

  _labels_stop.pop_back();
  _labels_next.pop_back();
}
//---------------------------------------------------------------------------
void xpl::postfix_writer::do_sweep_minus_node(xpl::sweep_minus_node * const node, int lvl){
 ASSERT_SAFE_EXPRESSIONS;
  int comparacao_sweep = ++_lbl;
  int incremento_sweep = ++_lbl;
  int fim_sweep = ++_lbl;

  std::string LABEL_FIM_SWEEP = mklbl(fim_sweep);
  std::string LABEL_COMPARACAO_SWEEP = mklbl(comparacao_sweep);
  std::string LABEL_INCREMENTO_SWEEP = mklbl(incremento_sweep);

  //Insert labels, to next and stop instruction
  _labels_stop.push_back(LABEL_FIM_SWEEP);
  _labels_next.push_back(LABEL_INCREMENTO_SWEEP);

  //Saves inicialization into lvalue
  node->inicialization()->accept(this,lvl);
  node->left()->accept(this,lvl);
  _pf.STORE();

  _pf.LABEL(LABEL_COMPARACAO_SWEEP); 		   //creates label for comaparisation
  node->left()->accept(this,lvl);					  //Loads lvalue
  _pf.LOAD();
  node->condition()->accept(this, lvl);				//Loads condition to compare
  _pf.GE();
  _pf.JZ(LABEL_FIM_SWEEP);

//lvalue e load

  node->block()->accept(this, lvl + 2);				//Code
 _pf.LABEL(LABEL_INCREMENTO_SWEEP);


  	node->left()->accept(this,lvl);					//Loads lvalue
  	_pf.LOAD();
  	_pf.DUP();
 	node->increment()->accept(this,lvl);
  	_pf.SUB();
    node->left()->accept(this,lvl);

  	_pf.STORE();
	_pf.TRASH(4);

	_pf.JMP(LABEL_COMPARACAO_SWEEP);
	_pf.LABEL(LABEL_FIM_SWEEP);

	_labels_stop.pop_back();
 	_labels_next.pop_back();
}
//---------------------------------------------------------------------------
void xpl::postfix_writer::do_block_node(xpl::block_node * const node, int lvl){
	if (node->declaration()!= nullptr)	{
		node->declaration()->accept(this,lvl);
	}
  if (node->code()!= nullptr)  {
	 node->code()->accept(this,lvl);
  }
}

//---------------------------------------------------------------------------
void xpl::postfix_writer::do_variable_declaration_node(xpl::variable_declaration_node * const node, int lvl){
	 ASSERT_SAFE_EXPRESSIONS;
	//TODO: SO funciona com inteiros
   _name = *node->name();
   std::shared_ptr<xpl::symbol> symbol =
     _symtab.find(_name); 

   if (_isGlobal) {
  	_pf.BSS();            
  	_pf.ALIGN();           
   	_pf.GLOBAL(*node->name(), _pf.OBJ());   
  	_pf.LABEL(*node->name());       
  	_pf.BYTE(node->type()->size()); 

  } else {
      _local_offset -= node->type()->size();
      symbol->offset(_local_offset); //guardar offset
  }
	
}

//---------------------------------------------------------------------------
void xpl::postfix_writer::do_variable_definition_node(xpl::variable_definition_node * const node, int lvl){
 	ASSERT_SAFE_EXPRESSIONS;
 	_definition = true;
 	_name = *node->name();

	std::shared_ptr<xpl::symbol> symbol =
		 _symtab.find(_name); 

	if (_isGlobal) {


		if (node->type()->name() == basic_type::TYPE_INT) {

      _pf.DATA();
      _pf.ALIGN();                      //align memory
      _pf.GLOBAL(*(node->name()), _pf.OBJ());     //declare a global symbol (linker)
      _pf.LABEL(*(node->name()));             //define the label  

		}

		if (node->type()->name() == basic_type::TYPE_DOUBLE) {
			//todo


		}
	
	node->content()->accept(this, lvl);					//Visita tanto a string como o inteiro
	
	} else {

			//Contexto local
			_local_offset -= node->type()->size();

			symbol->offset(_local_offset); //guardar offset
			node->content()->accept(this,lvl);

		if (node->type()->name() == basic_type::TYPE_DOUBLE &&
			node->content()->type()->name() == basic_type::TYPE_INT) {
			
			_pf.I2D(); //Converts to double

		}

		_pf.LOCAL(symbol->offset()); //endereco da variavel no topo
		
		if (node->type()->name() == basic_type::TYPE_INT ||
			node->type()->name() == basic_type::TYPE_STRING ||
			node->type()->name() == basic_type::TYPE_POINTER  )	{
			_pf.STORE(); //se inteiro string ou pointer
		}	

		else if (node->type()->name() == basic_type::TYPE_DOUBLE )	{
			_pf.DSTORE();
		}
	}

	_definition = false;
	
}

//---------------------------------------------------------------------------
void xpl::postfix_writer::do_null_node(xpl::null_node * const node, int lvl){
//TODO
}

//---------------------------------------------------------------------------
void xpl::postfix_writer::do_memory_position_node(xpl::memory_position_node * const node, int lvl){
//TODO
}

//---------------------------------------------------------------------------
void xpl::postfix_writer::do_identity_node(xpl::identity_node * const node, int lvl){
	node->argument()->accept(this,lvl);
}
//---------------------------------------------------------------------------

void xpl::postfix_writer::do_indexation_node(xpl::indexation_node * const node, int lvl){
//TODO
}
//---------------------------------------------------------------------------
void xpl::postfix_writer::do_memory_reservation_node(xpl::memory_reservation_node* const node, int lvl){
//TODO
}

//---------------------------------------------------------------------------
void xpl::postfix_writer::do_function_declaration_node(xpl::function_declaration_node * const node, int lvl){
//TODO
}
//---------------------------------------------------------------------------
void xpl::postfix_writer::do_function_call_node(xpl::function_call_node * const node, int lvl){
//TODO
}
//---------------------------------------------------------------------------
void xpl::postfix_writer::do_function_definition_node(xpl::function_definition_node * const node, int lvl){
  ASSERT_SAFE_EXPRESSIONS;
  std::string id;
  std::string FUNCTION_LABEL = mklbl(++_lbl);

  _pf.TEXT();
  _pf.ALIGN();
  if (*node->name() == ("xpl"))  {
    id = "_main";
  } else {
    id = *node->name();

  }
  
  if (node->public_indicator()) {
      _pf.GLOBAL(id, _pf.FUNC());
  }

  _pf.LABEL(id);

  //Creates visitor to know how many bytes
  size_visitor *visitor = new size_visitor(_compiler);
  node->accept(visitor,lvl);
  size_t bytes = visitor->getSize();
  delete visitor;

  _pf.ENTER(bytes); 
   
  _isGlobal = false;
  node->block()->accept(this, lvl);
  _isGlobal = true;
  
  _pf.LABEL(FUNCTION_LABEL);

  _pf.INT(0);
  _pf.POP();
  _pf.LEAVE();
  _pf.RET();

  // these are just a few library function imports
  _pf.EXTERN("readi");
  _pf.EXTERN("printi");
  _pf.EXTERN("prints");
  _pf.EXTERN("println");
 
}
  

