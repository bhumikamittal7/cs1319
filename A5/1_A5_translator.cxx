#include "1_A5_translator.h"
#include <string>
#include <sstream>  
#include <iostream> 

using namespace std;

/*=========================================================================================*/
quadArray q;                                                                            
string Type;                                                                            
symTable * table;                                                                       
sym * currentSymbol;                                                                    
symTable * globalST;                                                                 
/*=========================================================================================*/

symbolType::symbolType(string type, symbolType *ptr, int width):
	type(type),
	ptr(ptr),
	width(width) {};
/*=========================================================================================*/

quad::quad(string result, string arg1, string op, string arg2):
	result(result), arg1(arg1), arg2(arg2), op(op) {};                                  


quad::quad(string result, int arg1, string op, string arg2):
	result(result), arg2(arg2), op(op)                                                  
	{
		stringstream strs;                                                              
		strs << arg1;                                                                   
		string temp_str = strs.str();                                                   
		char *intStr = (char*) temp_str.c_str();                                        
		string str = string(intStr);                                                    
		this->arg1 = str;                                                               
	}
/*=========================================================================================*/
void changeTable(symTable *newtable)
{
	
	table = newtable;
}

int nextInstr()
{
	return q.Array.size();
}


int sizeOfType(symbolType *t)
{
	if (t->type == "void") return 0;
	else if (t->type == "arr") return t->width* sizeOfType(t->ptr);
	else if (t->type == "ptr") return size_of_pointer;
	else if (t->type == "char") return size_of_char;
	else if (t->type == "func") return 0;
	else if (t->type == "int") return size_of_int;
	return -1;
}
/*=========================================================================================*/

void quad::print()
{
		
	if (op == "=") std::cout << result << " = " << arg1;
	
    

	else if (op == "PLUS") std::cout << result << " = " << arg1 << " + " << arg2;
	else if (op == "MINUS") std::cout << result << " = " << arg1 << " - " << arg2;
	else if (op == "ASTERISK") std::cout << result << " = " << arg1 << " *" << arg2;
	else if (op == "DIVIDE") std::cout << result << " = " << arg1 << " / " << arg2;
	else if (op == "MODULO") std::cout << result << " = " << arg1 << " % " << arg2;

    

    else if (op == "EQUAL_TO") std::cout << "if " << arg1 << " == " << arg2 << " goto " << result;
	else if (op == "NOT_EQUAL_TO") std::cout << "if " << arg1 << " != " << arg2 << " goto " << result;
	else if (op == "LESS_THAN") std::cout << "if " << arg1 << "<" << arg2 << " goto " << result;
	else if (op == "GREATER_THAN") std::cout << "if " << arg1 << " > " << arg2 << " goto " << result;
	else if (op == "GREATER_THAN_EQUAL_TO") std::cout << "if " << arg1 << " >= " << arg2 << " goto " << result;
	else if (op == "LESS_THAN_EQUAL_TO") std::cout << "if " << arg1 << " <= " << arg2 << " goto " << result;
    else if (op == "LOGICAL_AND") std::cout << "if " << arg1 << " && " << arg2 << " goto " << result;
    else if (op == "LOGICAL_OR") std::cout << "if " << arg1 << " || " << arg2 << " goto " << result;

	else if (op == "GOTO") std::cout << "goto " << result;

    

	else if (op == "UMINUS") std::cout << result << " = -" << arg1;
    else if (op == "!") std::cout << result << " = !" << arg1;

	else if (op == "ARRR") std::cout << result << " = " << arg1 << "[" << arg2 << "]";
	else if (op == "ARRL") std::cout << result << "[" << arg1 << "]" << " = " << arg2;
	else if (op == "RETURN") std::cout << "ret " << result;
	else if (op == "PARAM") std::cout << "param " << result;
	else if (op == "CALL") std::cout << result << " = " << "call " << arg1 << ", " << arg2;
	else if (op == "FUNC") std::cout << result << ": ";
	else if (op == "FUNCEND") std::cout << "";
    
	else std::cout << "op";
	std::cout << endl;
}
/*=========================================================================================*/

void quadArray::print()
{
	std::cout << setw(30) << setfill('=') << "=" << endl;
	std::cout << "Quad Translation" << endl;
	std::cout << setw(30) << setfill('-') << "-" << setfill(' ') << endl;
	for (vector<quad>::iterator it = Array.begin(); it != Array.end(); it++)
	{
		if (it->op == "func")
		{
			std::cout << "\n";
			it->print();
			std::cout << "\n";
		}
		else if (it->op == "FUNCEND") {}
		else
		{
			std::cout << "\t" << setw(4) << it - Array.begin() << ":\t";
			it->print();
		}
	}

	std::cout << setw(30) << setfill('-') << "-" << endl;
}
/*=========================================================================================*/
sym::sym(string name, string t, symbolType *ptr, int width): name(name)
{
	type = new symbolType(t, ptr, width);
	nested = NULL;
	val = "";
	category = "";
	offset = 0;
	size = sizeOfType(type);
}

sym *sym::update(symbolType *t)
{
	type = t;
	this->size = sizeOfType(t);
	return this;
}

symTable::symTable(string name): name(name), tempCount(0) {}

void symTable::print()
{
	list<symTable*> tablelist;
	std::cout << setw(120) << setfill('=') << "=" << endl;
	std::cout << "Symbol Table: " << setfill(' ') << left << setw(50) << this->name;
	std::cout << right << setw(25) << "Parent: ";
	if (this->parent != NULL)
		std::cout << this->parent->name;
	else std::cout << "null";
	std::cout << endl;
	std::cout << setw(120) << setfill('-') << "-" << endl;
	std::cout << setfill(' ') << left << setw(15) << "Name";
	std::cout << left << setw(25) << "Type";
	std::cout << left << setw(15) << "Category";
	std::cout << left << setw(30) << "Initial Value";
	std::cout << left << setw(12) << "Size";
	std::cout << left << setw(12) << "Offset";
	std::cout << left << "Nested" << endl;
	std::cout << setw(120) << setfill('-') << "-" << setfill(' ') << endl;

	for (list<sym>::iterator it = table.begin(); it != table.end(); it++)
	{
		std::cout << left << setw(15) << it->name;
		string stype = printType(it->type);
		std::cout << left << setw(25) << stype;
		std::cout << left << setw(15) << it->category;
		std::cout << left << setw(30) << it->val;
		std::cout << left << setw(12) << it->size;
		std::cout << left << setw(12) << it->offset;
		std::cout << left;
		if (it->nested == NULL)
		{
			std::cout << "null" << endl;
		}
		else
		{
			std::cout << it->nested->name << endl;
			tablelist.push_back(it->nested);
		}
	}

	std::cout << setw(120) << setfill('-') << "-" << setfill(' ') << endl;
	std::cout << endl;
	for (list<symTable*>::iterator iterator = tablelist.begin(); iterator != tablelist.end();
		++iterator)
	{
		(*iterator)->print();
	}
}
/*=========================================================================================*/

void symTable::update()
{
	list<symTable*> tablelist;
	int off=0;
	for (list<sym>::iterator it = table.begin(); it != table.end(); it++)
	{
		it->offset = off;
		off = it->offset + it->size;	
		if (it->nested != NULL) tablelist.push_back(it->nested);
	}

	for (list<symTable*>::iterator iterator = tablelist.begin(); iterator != tablelist.end(); ++iterator)
	{
		(*iterator)->update();
	}
}
/*=========================================================================================*/

sym *symTable::lookup(string name)
{
	sym * s;
	for (list<sym>::iterator it = table.begin(); it != table.end(); it++)
	{
		if (it->name == name) return &*it;;
	}

	
	s = new sym(name);
	s->category = "local";
	table.push_back(*s);
	return &table.back();
}
/*=========================================================================================*/

void emit(string op, string result, string arg1, string arg2)
{
	q.Array.push_back(*(new quad(result, arg1, op, arg2)));
}

void emit(string op, string result, int arg1, string arg2)
{
	q.Array.push_back(*(new quad(result, arg1, op, arg2)));
}
/*=========================================================================================*/


sym* convertType(sym *s, string t)
{
	sym *temp = gentemp(new symbolType(t));
	if (s->type->type == "int")
	{
        if (t == "char")
		{
			emit("=", temp->name, "int2char(" + s->name + ")");
			return temp;
		}

		return s;
	}
	else if (s->type->type == "char")
	{
		if (t == "int")
		{
			emit("=", temp->name, "char2int(" + s->name + ")");
			return temp;
		}

		return s;
	}

	return s;
}
/*=========================================================================================*/

bool compareSymbolType(sym* &s1, sym* &s2)
{
	
	symbolType *type1 = s1->type;
	symbolType *type2 = s2->type;
	if (compareSymbolType(type1, type2)) return true;
	else if (s1 = convertType(s1, type2->type)) return true;
	else if (s2 = convertType(s2, type1->type)) return true;
	else return false;
}

bool compareSymbolType(symbolType *t1, symbolType *t2)
{
	
	if (t1 != NULL || t2 != NULL)
	{
		if (t1 == NULL) return false;
		if (t2 == NULL) return false;
		if (t1->type == t2->type) return compareSymbolType(t1->ptr, t2->ptr);
		else return false;
	}

	return true;
}
/*=========================================================================================*/

void backpatch(list<int> l, int addr)
{
	stringstream strs;
	strs << addr;
	string temp_str = strs.str();
	char *intStr = (char*) temp_str.c_str();                                                    
	string str = string(intStr);                                                                
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)                               
	{                                                                                           
		q.Array[*it].result = str;
	}
}

list<int> makelist(int i)
{
	list<int> l(1, i);                                                                           
	return l;                                                                                    
}

list<int> merge(list<int> &a, list<int> &b)
{
	a.merge(b);                                                                                   
	return a;                                                                                     
}
/*=========================================================================================*/


Expression* convertInt2Bool(Expression *e)                                                                     
{
	
	if (e->type != "BOOL")                                                                         
	{
		e->falseList = makelist(nextInstr());
		emit("EQOP", "", e->loc->name, "0");
		e->trueList = makelist(nextInstr());
		emit("GOTOOP", "");
	}

	return e;
}

Expression* convertBool2Int(Expression *e)
{
	
	if (e->type == "BOOL")
	{
		e->loc = gentemp(new symbolType("int"));
		backpatch(e->trueList, nextInstr());
		emit("=", e->loc->name, "true");
		stringstream strs;
		strs << nextInstr() + 1;
		string temp_str = strs.str();
		char *intStr = (char*) temp_str.c_str();
		string str = string(intStr);
		emit("GOTOOP", str);
		backpatch(e->falseList, nextInstr());
		emit("=", e->loc->name, "false");
	}

	return e;
}
/*=========================================================================================*/


sym* gentemp(symbolType *t, string init)
{
	char n[10];
	sprintf(n, "t%02d", table->tempCount++);
	sym *s = new sym(n);
	s->type = t;
	s->size = sizeOfType(t);
	s->val = init;
	s->category = "temp";
	table->table.push_back(*s);
	return &table->table.back();
}
/*=========================================================================================*/

string printType(symbolType *t)
{
	if (t == NULL) return "null";
	if (t->type == "void") return "void";
	else if (t->type == "char") return "char";
	else if (t->type == "int") return "integer";
	else if (t->type == "ptr") return "ptr(" + printType(t->ptr) + ")";
	else if (t->type == "arr")
	{
		stringstream strs;
		strs << t->width;
		string temp_str = strs.str();
		char *intStr = (char*) temp_str.c_str();
		string str = string(intStr);
		return "arr(" + str + ", " + printType(t->ptr) + ")";
	}
	else if (t->type == "func") return "function";
	else return "_";
}