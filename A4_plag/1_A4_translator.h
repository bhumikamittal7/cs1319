#ifndef _1_A4_TRANSLATOR_H
#define _1_A4_TRANSLATOR_H

// bits/stdc++.h is a header file that includes every standard library.
#include <bits/stdc++.h>

// using namespace std; is used to avoid writing the std:: again and again.
using namespace std;

//================================================================================================
// let's define some macros (marcos are preprocessor directives used to define constants or functions))
// ltsit is a list of symbols iterator
#define listSymbolIterator list<sym>::iterator
// ltiit is a list of integers iterator
#define listIntegerIterator list<int>::iterator
// ltstit is a list of symbol tables iterator
#define listSymbolTableIterator list<symtable*>::iterator
// qdit is a quad vector iterator
#define quadVectorIterator vector<quad>::iterator
// ltsym is a list of symbols
#define listSymbol list<sym>
// ltst is a list of symbol tables
#define listSymbolTable list<symtable*>
// str is a string
#define str string
//================================================================================================

//================================================================================================
// let's define some class names
// sym is a class that defines the entry of a symbol table
class sym;
// symboltype is a class that defines the symbol type attribute of a symbol table
class symboltype;
// symtable is a class that defines the symbol table and contains associated functions for lookup, gentemp, print and update
class symtable;
// quad is a class that defines a quad - a quad is a tuple of 4 elements (op, arg1, arg2, result)
class quad;
// quadArray is a class that defines the quad array object - it contains a vector of quads and associated functions for emit, and print
class quadArray;
//================================================================================================

//================================================================================================
//CLASSES Definition
//symbol table stores the following information: NAME, TYPE, INITIAL VALUE, SIZE, OFFSET, NESTED TABLE

class sym {                                     
    public:
        str name;				
        symboltype *type;
        str initialValue;
        int size; 			
        int offset;
        symtable* nested; 

        // Constructor - initializes the symbol table entry with the given parameters
        sym (str, str t="int", symboltype* ptr = NULL, int width = 0);

        // updates the symboltype of the current symbol and make changes in size and offset accordingly
        sym* update(symboltype*);
};

//symbol type stores the following information: TYPE, WIDTH (1 is default), ARRAY TYPE
class symboltype {                            
    public:
        str type;
        symboltype* arrtype;
        int width; 

        // Constructor - initializes the symbol type with the given parameters
        symboltype(str, symboltype* ptr = NULL, int width = 1);
};
typedef symboltype symtyp;

//A symbol table is identified by 
// 1. the name of the function it is associated with
// 2. the list of symbols it contains
// 3. number of temporary variables declared in the function
// 4. pointer to its parent symbol table

class symtable{
    public:
        str name;
        listSymbol table;
        int tempCount;
        symtable* parent;

        // Constructor - initializes the symbol table with the given parameters
        symtable(str name="NULL");
        // searches for an id in the symbol table and returns its pointer if found, otherwise returns NULL
        sym* lookup(str);
        // prints the symbol table
        void print();
        //updates the symbol table
        void update();
};

//A quad is a tuple of 4 elements (op, arg1, arg2, result)
class quad{
    public:
        str result;
        str op;
        str arg1;
        str arg2;
  

        // Constructor - initializes the quad with the given parameters
        //arg2 is optional - default value is ""
        quad (str , str , str op = "=", str arg2 = "");
        quad (str , int , str op = "=", str arg2 = "");
        // quad (str , double , str op = "=", str arg2 = "");
};

//A quadArray class just contains a vector of quads 
class quadArray{
    public:
        vector<quad> arr;
        void print();
};

//non-user defined variable types
class basicType {                                
    public:
    vector <str> type;  //type name
    vector <int> size;  //size of the type
    
    //if needed we can add more types by addType function
    void addType(str, int);
};
//================================================================================================

//================================================================================================
//Structure Definitions - STRUCTS

//statements
struct statement{
    list<int> nextlist; 
};

//array
struct array{
    //array can be pointer to another array
    str arrType;  
    //loction to compute the address of the array
    sym* loc;
    //Symbol table entry pointer
    sym* array;
    //multi-dimensional array support
    symboltype* type;

};

//expression - this is that truelist and falselist for boolean expressions and nextlist for statement expressions (need to check Module 7 again)
struct expression{
    sym* loc;   //Symbol table entry pointer
    str type;   //to store type of expression out of int, char, bool (bool is implicit type)
    list<int> truelist;
    list<int> falselist;
    list<int> nextlist;
};
typedef expression* express;
//================================================================================================

//================================================================================================
//Let's define some global variables to include external variables and functions
//Recall: extern is used to declare a global variable that is defined in another file 
//(using recall lowkey feels like mathematician - why am I even doing CS bruh at 3AM ughhhhhhhhhh)

extern char* yytext;   
extern int yyparse();

extern symtable* currentST; //current symbol table
extern symtable* globalST;  //global symbol table
extern sym* currentSymbolPtr;  //pointer to current symbol

extern quadArray Q; //quad array - Q 
extern basicType bType; //basic type

//this is kinda for debugging purposes - atleast software debugging course was worth it unlike this course -_-
extern long long int instrCount;    //instruction count
extern bool debug;                  //debug flag 
void debugPrint();                  //debug print function for printing the debug output
//================================================================================================

//================================================================================================
// Other functions

//gentemp - static method to generate a temporary variable and insert it in the current symbol table
sym* gentemp(symtyp*, str init = "");

//emit - different versions for different purposes (overloading - just like I am overloaded with work - hate finals week)
void emit (str, str, int , str arg = "");
void emit (str, str, str arg1 ="" , str arg2 = "");

//prints the output in a formatted manner
void printOutput(int);

//backpatch - function to backpatch a list of addresses with the given label
void backpatch(list<int>, int);

//merge - function to merge two lists
list<int> merge(list<int> &l1, list<int> &l2);

//makeList - function to create a new list containing initail value
list<int> makeList(int);

//number of the next instruction
int nextInstruction();
void updateNextInstruction(); 
//================================================================================================

//================================================================================================
//TYPECHECK and conversion stuff goes here (and brain goes brrrr)
//okay this better work this time so we will ughhh

//typeConvert which will take symbol table entry pointer and the type to which we want to convert
sym* typeConvert(sym*, str);

//we also need to computeSize of the type to which we want to convert - this takes symtyp
int computeSize(symtyp*);

//printType - prints the type name
str printType(symtyp*);

//compareSymbolType - this will take two symbol table entry pointers and compare their types
//we can also compare just the symboltype attribute of the symbol table entry (so overloading this function)
bool compareSymbolType(symtyp*, symtyp*);
bool compareSymbolType(sym* &s1, sym* &s2);

//conversion functions
str convertInt2String(int); 
express convertInt2Bool(express);
express convertBool2Int(express);
//================================================================================================

//================================================================================================
#endif