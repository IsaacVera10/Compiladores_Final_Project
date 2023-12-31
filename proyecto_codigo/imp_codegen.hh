#ifndef IMP_CODEGEN
#define IMP_CODEGEN

#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <fstream>
#include <stack>

#include "imp.hh"
#include "imp_visitor.hh"
#include "environment.hh"

class ImpCodeGen : public ImpVisitor {
public:
  void codegen(Program*, string outfname);
  int visit(Program*);
  int visit(Body*);
  int visit(VarDecList*);
  int visit(VarDec*);
  int visit(StatementList*);
  int visit(AssignStatement*);
  int visit(PrintStatement*);
  int visit(IfStatement*);
  int visit(WhileStatement*);
  int visit(DoWhileStatement*); // Agregar el visit de Codegen para DoWhileStatement
  int visit(ForStatement*);
  int visit(BreakStatement*); // Agregar el visit de Codegen para Break y Continue Statement
  int visit(ContinueStatement*);

  int visit(BinaryExp* e);
  int visit(UnaryExp* e);
  int visit(NumberExp* e);
  int visit(BoolConstExp* e);
  int visit(IdExp* e);
  int visit(ParenthExp* e);
  int visit(CondExp* e);

private:
  std::ostringstream code;
  string nolabel;
  int current_label;
  Environment<int> direcciones;
  int siguiente_direccion, mem_locals;
  std::stack<string> loopStartLabels; //Manejo de labels para continue y break statemnts
  std::stack<string> loopEndLabels;
  void codegen(string label, string instr);
  void codegen(string label, string instr, int arg);
  void codegen(string label, string instr, string jmplabel);
  string next_label();
};



#endif

