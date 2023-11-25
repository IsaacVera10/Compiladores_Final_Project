#ifndef IMP_TYPECHECKER
#define IMP_TYPECHECKER

#include <unordered_map>

#include "imp.hh"
#include "type_visitor.hh"
#include "environment.hh"

using namespace std;

class ImpTypeChecker : public TypeVisitor {
public:
  ImpTypeChecker();
private:
  Environment<ImpType> env;
  ImpType booltype;
  ImpType inttype;
  int loopNestingLevel = 0;
  
public:
  void typecheck(Program*);
  void visit(Program*);
  void visit(Body*);
  void visit(VarDecList*);
  void visit(VarDec*);
  void visit(StatementList*);
  void visit(AssignStatement*);
  void visit(PrintStatement*);
  void visit(IfStatement*);
  void visit(WhileStatement*);
  void visit(DoWhileStatement*); // Agregar el visit para DoWhileStatement en el typechecker 
  void visit(ForStatement*);
  void visit(BreakStatement*); // Agregar al typechecker visit para Break y Continue statement;
  void visit(ContinueStatement*);

  ImpType visit(BinaryExp* e);
  ImpType visit(UnaryExp* e);
  ImpType visit(NumberExp* e);
  ImpType visit(BoolConstExp* e);
  ImpType visit(IdExp* e);
  ImpType visit(ParenthExp* e);
  ImpType visit(CondExp* e);
};


#endif

