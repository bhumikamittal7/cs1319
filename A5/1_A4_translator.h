#ifndef __1_A4_TRANSLATOR_H
#define __1_A4_TRANSLATOR_H

#include <bits/stdc++.h>

extern char *yytext;
extern int yyparse();

const unsigned int size_of_char = 1;
const unsigned int size_of_int = 4;
const unsigned int size_of_pointer = 4;

using namespace std;
/*==========================================================================================*/
#define listIterator list<sym>::iterator // define the iterator for the list of symbols in ST
#define listInt list<int>				 // define the list of integers
#define listSym list<sym>				 // define the list of symbols
#define vectorSym vector				 // define the vector of symbols
#define stringSym string				 // define the string of symbols
#define voidSym void
/*==========================================================================================*/
class sym;		  // an entry in the symbol table
class symbolType; // type of the symbol
class symTable;	  // ST - symbol table
class quad;		  // an entry in the quad array
class quadArray;  // array of quads
/*==========================================================================================*/
// ST contains: Name, Type, Initial Value, Size, Offset, Nested Table
class sym
{
public:
	stringSym name;
	symbolType *type;
	int size;
	int offset;
	symTable *nested;
	stringSym val;

	sym(stringSym, stringSym t = "int", symbolType *ptr = NULL, int width = 0);

	// Update the symbol table entry
	sym *update(symbolType *);
};
typedef sym s;

// ST contains: Type, Width
class symbolType
{
public:
	stringSym type; // type of symbol
	int width;		// size of Array (if we encounter an Array) and it is 1 in default case
	symbolType *arrtype;

	symbolType(stringSym, symbolType *ptr = NULL, int width = 1);
};
typedef symbolType symtyp;

// ST contains: Name,tempCount, Table, Parent ST
class symTable
{
public:
	stringSym name;
	int tempCount;	  // count of temporary variables
	listSym table;	  // list of symbols
	symTable *parent; // pointer to the parent symbol table

	symTable(stringSym name = "NULL");
	s *lookup(stringSym);
	voidSym print();
	voidSym update();
};
/*==========================================================================================*/
// Quad contains: Result, Operator, Argument1, Argument2
class quad
{
public:
	stringSym result;
	stringSym op;
	stringSym arg1;
	stringSym arg2;

	voidSym print();
	voidSym printType1();
	voidSym printType2();

	// overloading stuff here?
	quad(stringSym, stringSym, stringSym op = "=", stringSym arg2 = "");
	quad(stringSym, int, stringSym op = "=", stringSym arg2 = "");
};

// we will have an array that will store all the quads and emit them at the end
class quadArray
{
public:
	vectorSym<quad> Array; // Array of quads (it's a vector of quads)
	voidSym print();
};

class basicType
{
public:
	vectorSym<stringSym> type;
	vectorSym<int> size;
	voidSym addType(stringSym, int);
};
/*==========================================================================================*/
// Global variables
extern symTable *ST;
extern symTable *globalST;
extern s *currentSymbol;
extern quadArray quadArr;
extern basicType bType;
extern long long int instrCount;
/*==========================================================================================*/
// Other structs for arrays, pointer and functions
struct Statement
{
	listInt nextList;
};

struct Array
{
	stringSym aType;
	s *loc;
	s *Array;
	symbolType *type;
};

struct Expression
{
	s *loc;
	stringSym type;
	listInt trueList;
	listInt falseList;
	listInt nextList;
};

/*==========================================================================================*/
// Function declarations
voidSym addSpacess(int);
int nextInstr();
voidSym updateNextInstr();
stringSym convertToString(int);
int sizeOfType(symbolType *);

s *gentemp(symbolType *, stringSym initalVal = "");
voidSym backpatch(list<int>, int);
listInt makelist(int);
listInt merge(list<int> &l1, list<int> &l2);
s *convertType(sym *, stringSym);
Expression *convertInt2Bool(Expression *);
Expression *convertBool2Int(Expression *);

bool compareSymbolType(sym *&s1, sym *&s2);
bool compareSymbolType(symbolType *, symbolType *);
stringSym printType(symbolType *);
voidSym changeTable(symTable *);

voidSym emit(stringSym, stringSym, stringSym arg1 = "", stringSym arg2 = "");
voidSym emit(stringSym, stringSym, int, stringSym arg2 = "");

#endif // __1_A4_TRANSLATOR_H

// =====================================================================================================
// Reference - I read through multiple tinyC compiler stuff to understand how their thing is implemented.
// Hence, some of the code is inspired from there but I have written everything from scratch.
// I have also referred to the slides and the dragon book for the same.
// =====================================================================================================