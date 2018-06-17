#ifndef __XPL_SEMANTICS_SYMBOL_H__
#define __XPL_SEMANTICS_SYMBOL_H__

#include <string>
#include <cdk/basic_type.h>

namespace xpl {

    class symbol {

      std::vector<basic_type *> _arguments; //stores func args

      bool _isdeclared; //TODO CONFIRMAR AQUI?

      basic_type *_type;
      std::string _name;
      int _offset;
      

    public:
      inline symbol(basic_type *type, const std::string &name, int offset) :
          _type(type), _name(name), _offset(offset)  {
      }

      virtual ~symbol() {
        delete _type;
      }

      inline basic_type *type() const {
        return _type;
      }
      inline const std::string &name() const {
        return _name;
      }
      
      inline int offset() {
        return _offset;
      }
      inline void offset(int i) {
        _offset = i;
      }
/*
      inline bool isGlobal() {
        return _isGlobal;
      }
      inline bool isGlobal(bool d) {
        return _isGlobal = d;
      }
*/
/*
      void add_arg(basic_type *t) {
        _arguments.push_back(t);
      }
      
      basic_type *get_arg(size_t s) { //size_t is an unsigned integer
        return _arguments.at(s);
      }
      size_t argsize() {
        return _arguments.size();
      }
    */
    };

} // xpl

#endif
