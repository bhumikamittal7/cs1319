#ifndef __1_A5_TRANSLATOR_H
#define __1_A5_TRANSLATOR_H

#include <bits/stdc++.h>

extern char *yytext;
extern int yyparse();

using namespace std;
/*=========================================================================================*/

const unsigned int size_of_char = 1;
const unsigned int size_of_int = 4;
const unsigned int size_of_pointer = 4;
/*=========================================================================================*/
class sym;
class quad;
class symbolType;
class symTable;
class quadArray;
/*=========================================================================================*/
class symbolType
{
public:
	symbolType(string type, symbolType *ptr = NULL, int width = 1);
	string type;
	int width;
	symbolType *ptr;
};
/*=========================================================================================*/
class sym
{
public:
	string name;
	symbolType *type;
	string val;
	string category; // global or local or parameter
	int size;
	int offset;
	symTable *nested;

	sym(string name, string t = "int", symbolType *ptr = NULL, int width = 0);
	sym *update(symbolType *t);
};
/*=========================================================================================*/
class symTable
{
public:
	string name;
	int tempCount;
	list<sym> table;
	symTable *parent;
	map<string, int> array;

	symTable(string name = "NULL");
	sym *lookup(string name);
	void print();
	void update();
};

/*=========================================================================================*/
class quad
{
public:
	string op;
	string result;
	string arg1;
	string arg2;

	quad(string result, string arg1, string op = "ASSIGN", string arg2 = "");
	quad(string result, int arg1, string op = "ASSIGN", string arg2 = "");
	void print();
};
/*=========================================================================================*/
class quadArray
{
public:
	vector<quad> Array;
	void print();
};
/*=========================================================================================*/
struct Statement
{
	list<int> nextList;
};

struct Expression
{
	string type;
	sym *loc;
	list<int> trueList;
	list<int> falseList;
	list<int> nextList;
};

struct Array
{
	string aType;
	sym *loc;
	sym *Array;
	symbolType *type;
};
/*=========================================================================================*/
extern quadArray q;
extern symTable *table; // Current Symbbol Table - changing name here - last time something was messed up
extern sym *currentSymbol;
extern symTable *globalST;
/*=========================================================================================*/

int nextInstr();
int sizeOfType(symbolType *);
string printType(symbolType *);

sym *gentemp(symbolType *t, string init = "");
void backpatch(list<int> l, int i);
list<int> makelist(int i);
list<int> merge(list<int> &l1, list<int> &l2);

sym *convertType(sym *, string);
bool compareSymbolType(sym *&s1, sym *&s2);
bool compareSymbolType(symbolType *t1, symbolType *t2);

Expression *convertInt2Bool(Expression *);
Expression *convertBool2Int(Expression *);

void changeTable(symTable *newtable);

void emit(string op, string result, string arg1 = "", string arg2 = "");
void emit(string op, string result, int arg1, string arg2 = "");
/*=========================================================================================*/

#endif // __1_A4_TRANSLATOR_H

// =====================================================================================================
// Reference - I read through multiple tinyC compiler stuff to understand how their thing is implemented.
// Hence, some of the code is inspired from there but I have written everything from scratch.
// I have also referred to the slides and the dragon book for the same.
// =====================================================================================================