#ifndef __1_A4_TRANSLATOR_H
#define __1_A4_TRANSLATOR_H

#include <bits/stdc++.h>

extern  char* yytext;
extern  int yyparse();

const unsigned int size_of_char  = 1;
const unsigned int size_of_int   = 4;
const unsigned int size_of_pointer = 4;

using namespace std;
/*==========================================================================================*/
#define listIterator list<sym>::iterator //here we define the iterator for the list of symbols in ST
#define listInt list<int>                   //here we define the list of integers
#define listSym list<sym>                   //here we define the list of symbols
#define vectorSym vector                   //here we define the vector of symbols
#define stringSym string                   //here we define the string
#define voidSym void                       //here we define the void
/*==========================================================================================*/
class sym;						            //an entry in ST
class symbolType;				            //the type of a symbol in ST
class symTable;					            //ST
class quad;						            //a single entry in the quad Array
class quadArray;				            //the Array of quads
/*==========================================================================================*/
//ST contains: Name, Type, Initial Value, Size, Offset, Nested Table
class sym{
    public:
        stringSym name;				        //name of the symbol
        symbolType *type;			        //type of the symbol
        int size;					        //size of the symbol
        int offset;					        //offset of the symbol
        symTable* nested;			        //nested symbol table
        stringSym val;				        //initial value of the symbol if specified
        
        sym (stringSym , stringSym t="int", symbolType* ptr = NULL, int width = 0);
        
        //Update the ST Entry 
        sym* update(symbolType*); 	        //To update different fields of an existing entry.
};

//ST contains: Type, Width (we don't have mutidimensional arrays)
class symbolType{
    public:
        stringSym type;				        //type of symbol. 
        int width;					        //size of Array (if we encounter an Array) and it is 1 in default case        
        symbolType* arrtype;
        symbolType(stringSym , symbolType* ptr = NULL, int width = 1);
};

//ST contains: Name,tempCount, Table, Parent ST
class symTable{
    public:
        stringSym name;				        //Name of the Table
        int tempCount;					    
        listSym table; 			            //list of sym
        symTable* parent;			        //Parent ST of the current ST
        
        symTable (stringSym name="NULL");   //default name is NULL
        
        //Lookup for a symbol/identifier in ST
        sym* lookup (stringSym);	

        //Print the ST
        void print();

        //Update the ST
        void update();
};

class quad{
    public:
        stringSym result;
        stringSym op;				     
        stringSym arg1;				      
        stringSym arg2;				      

        //Print
        void print();
        void printType1();
        void printType2();

        //Constructors (because we have different types of quads - overloading stuff)
        quad(stringSym, stringSym, stringSym op = "=", stringSym arg2 = ""); 
        quad(stringSym, int, stringSym op = "=", stringSym arg2 = ""); 
};

class quadArray{
    public:
        vectorSym<quad> Array;				//Array of quads (it's a vector of quads)

        //Print
        void print();
};

class basicType{
    public:
        vectorSym<stringSym> type;			//Name of the basic type
        vectorSym<int> size;				//size of the basic type

        voidSym addType(stringSym, int);
};
/*==========================================================================================*/
//Global Variables
extern symTable* ST;						// current Symbol Table
extern symTable* globalST;				    // Global Symbol Table
extern sym* currentSymbol;				    // current Symbol
extern quadArray quadArr;				    // Quad Array
extern basicType bType;				        // Basic Type
extern long long int instrCount;			// Instruction Count - we use long long int because we have a lot of instructions and we don't want to overflow
/*==========================================================================================*/

//Function Declarations
stringSym convertToString(int);				//Converts an integer to a string
void generateSpace(int);					//Generates spaces for indentation

sym* gentemp(symbolType*, stringSym initalVal = "" );					//Generate a temporary variable and insert it in the current symbol table

void backpatch(list<int> , int);
listInt makelist(int);
listInt merge(list<int> &l1, list<int> &l2);

//convert and type checking functions
sym* convertType(sym*, stringSym);								//type conversion
bool compareSymbolType(sym* &s1, sym* &s2);						//Same type of two symbol table entries?
bool compareSymbolType(symbolType*, symbolType*);		//Same type of two symbolTypes


//Emit functions
void emit(stringSym, stringSym, stringSym arg1 = "", stringSym arg2 = "");  //binary operators
void emit(stringSym, int, stringSym, stringSym arg2 = "");		  			//unary operators

int nextInstr();                                                //returns the next instruction number
void updateNextInstr();
int sizeOfType(symbolType*);									//Size of a type
stringSym printType(symbolType*);								//Print a type
void changeTable(symTable* newtable);							//Change to current symbol table
/*==========================================================================================*/
//Support for arrays, pointers and functions

struct Array{
    stringSym aType;                    //type of Array
    sym* loc;                           //location of the Array
    sym* Array;                       //pointer to the Array
    symbolType* type;                   //type of the sub Array
};

struct Statement{
    listInt nextList;                   //nextlist for statement
};

struct Expression{
    sym* loc;                           //location of the expression
    stringSym type;                     //type of expression
    listInt trueList;                   //true list
    listInt falseList;                  //false list
    listInt nextList;                   //next list
};

Expression* convertInt2Bool(Expression*);                      //convert int to bool
Expression* convertBool2Int(Expression*);                      //convert bool to int
/*=====================================================================================================*/

#endif // __1_A4_TRANSLATOR_H

/*
=====================================================================================================
Reference - I read through multiple tinyC compiler stuff to understand how their thing is implemented.
Hence, some of the code is inspired from there but I have written everything from scratch. 
I have also referred to the slides and the dragon book for the same.
=====================================================================================================
*/


/* Leaving this here for my reference and debug purposes - ignore everything below this line

Support for Lazy TAC generation through Quad array 
typedef enum {
	PLUS = 1,
    MINUS,
    DIVIDE,
    MODULO,
    NOT,
    ARROW,
    AMPERSAND,
    ASTERISK,
    QUESTION,
    LESS_THAN,
    GREATER_THAN,
    LESS_THAN_EQUAL_TO,
    GREATER_THAN_EQUAL_TO,
    EQUAL_TO,
    NOT_EQUAL_TO,
    LOGICAL_AND,
    LOGICAL_OR,
    ASSIGN,
    COLON,
    SEMICOLON,
    COMMA,
    CHAR,
    ELSE,
    FOR,
    IF,
    INT,
    RETURN,
    VOID,
} opcodeType; 

*/