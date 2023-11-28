#include<sstream>
#include<string>
#include<iostream>
#include "1_A4_translator.h"

using namespace std;

// global variables - defined in 1_A4_translator.h
symtable* globalST;       
quadArray Q;
sym* currentSymbolPtr;
symtable* currentST;
bool debug;
long long int instrCount;
basicType bType;

//debug print function for printing the debug output
void debugPrint(){
    cout<<"";       //just print a blank line
}
//================================================================================================

//================================================================================================
//switch case for for tokens from the lexer: we can map the tokens to an integer value
/*
The tokens are as follows - copilot please do your thing now.
"->"                            {return ARROW;}
"&"                             {return AMPERSAND;}
"*"                             {return ASTERISK;}
"+"                             {return PLUS;}
"-"                             {return MINUS;}
"/"                             {return DIVIDE;}
"%"                             {return MODULO;}
"!"                             {return NOT;}
"?"                             {return QUESTION;}
"<"                             {return LESS_THAN;}
">"                             {return GREATER_THAN;}
"<="                            {return LESS_THAN_EQUAL_TO;}
">="                            {return GREATER_THAN_EQUAL_TO;}
"=="                            {return EQUAL_TO;}
"!="                            {return NOT_EQUAL_TO;}
"&&"                            {return LOGICAL_AND;}
"||"                            {return LOGICAL_OR;}
"="                             {return ASSIGN;}
":"                             {return COLON;}
";"                             {return SEMICOLON;}
","                             {return COMMA;}
"char"                          {return CHAR;}
"else"                          {return ELSE;}
"for"                           {return FOR;}
"if"                            {return IF;}
"int"                           {return INT;}
"return"                        {return RETURN;}
"void"                          {return VOID;}
"goto"                          {return GOTO;}   

*/
int stringToInteger(string s){
    map <string, int> m;
    m = {
        {"L_SQUARE_BRACKET", 0}, {"R_SQUARE_BRACKET", 1}, {"L_ROUND_BRACKET", 2}, 
        {"R_ROUND_BRACKET", 3}, {"L_CURLY_BRACKET", 4}, {"R_CURLY_BRACKET", 5}, 
        {"ARROW", 6}, {"AMPERSAND", 7}, {"ASTERISK", 8}, {"PLUS", 9}, {"MINUS", 10}, 
        {"DIVIDE", 11}, {"MODULO", 12}, {"NOT", 13}, {"QUESTION", 14}, {"LESS_THAN", 15}, 
        {"GREATER_THAN", 16}, {"LESS_THAN_EQUAL_TO", 17}, {"GREATER_THAN_EQUAL_TO", 18}, 
        {"EQUAL_TO", 19}, {"NOT_EQUAL_TO", 20}, {"LOGICAL_AND", 21}, {"LOGICAL_OR", 22}, 
        {"ASSIGN", 23}, {"COLON", 24}, {"SEMICOLON", 25}, {"COMMA", 26}, {"CHAR", 27}, 
        {"ELSE", 28}, {"FOR", 29}, {"IF", 30}, {"INT", 31}, {"RETURN", 32}, {"VOID", 33}, 
        {"GOTO", 34}};

        if  (m.find(s) == m.end())
            return -1;
        return m[s];
}

//================================================================================================

//================================================================================================
//SYMBOL TABLE FUNCTIONS

//Constructor for class sym
sym::sym (string name, string t, symboltype* typeArray, int width){
    debugPrint();
    (*this).name = name;    //this is a pointer to the current object 
    type = new symboltype(t, typeArray, width);
    size= computeSize(type);
    offset = 0;
    nested = NULL;
    initialValue = "";
    debugPrint();
}

//Constructor for class symboltype
symboltype::symboltype(string t, symboltype* typeArray, int width){
    debugPrint();
    (*this).type = t;
    (*this).arrtype = typeArray;
    (*this).width = width;
    debugPrint();
}

//Constructor for class symtable
symtable::symtable(string name){
    (*this).name = name;
    tempCount = 0;
}

//update function for class sym
sym* sym::update(symboltype* t){
    debugPrint();
    type = t;
    (*this).size = computeSize(type);
    debugPrint();
    return this;
}

// updateCurrentTable
void updateCurrentTable(symtable* newTable){
    currentST = newTable;
}


//lookup function for class symtable
sym* symtable::lookup(string name){
    sym* s;
    //iterate through the symbol table and return the symbol if found
    listSymbolIterator it;
    it = table.begin();
    while(it != table.end()){

        if(it->name == name){
            return &(*it);
            }
        it++;
    }
    s = new sym(name);
    table.push_back(*s);
    return &table.back();
}

//update the symbol table
void symtable::update(){
    listSymbolTableIterator tableIter;
    listSymbolIterator symIter;

    symIter = table.begin();
    int count = 0;

    while(symIter != table.end()){
        if(symIter == table.begin()){
            symIter->offset = 0;
            count = symIter->size;
        }
        else{
            symIter->offset = count;
            count = symIter->offset + symIter->size;
        }
        if(symIter->nested != NULL){
            tableIter.push_back(symIter->nested);
        }
        symIter++;
    }

    listSymbolTableIterator tableIter1;
    tableIter1 = tableIter.begin();
    while(tableIter1 != tableIter.end()){
        (*tableIter1)->update();
        tableIter1++;
    }
}

//print function - making it look pretty
void symtable::print(){
   // use the reference from the code given above in comments
   int nextInstr = 0;
    listSymbolTable tableIter;
    for (int i = 0; i < 40; i++){
        cout << "__";
    }
    cout << endl;

    cout << "Table Name: " << (*this).name << "\t\t\t Parent Name: ";
    if ((*this).parent == NULL){
        cout << "NULL" << endl;
    }
    else{
        cout << (*this).parent->name << endl;
    }

    for (int i = 0; i < 40; i++){
        cout << "__";
    }

    cout << endl;

    cout << "Name";
    formatOutput(11);
    cout << "Type";
    formatOutput(16);
    cout << "Initial Value";
    formatOutput(7);
    cout << "Size";
    formatOutput(11);
    cout << "Offset";
    formatOutput(9);
    cout << "Nested" << endl;
    formatOutput(100);
    cout << endl;

    ostringstream str1;

    for (listSymbolIterator it = table.begin(); it != table.end(); it++){
        cout << it->name;
        formatOutput(15 - it->name.length());
        string typeRes = printType(it->type);

        cout << typeRes;
        formatOutput(20 - typeRes.length());
        cout << it->initialValue;

        formatOutput(20 - it->initialValue.length());
        cout << it->size;
        str1 << it->size;

        formatOutput(15 - str1.str().length());
        str1.str("");
        str1.clear();
        cout << it->offset;
        str1 << it->offset;

        formatOutput(15 - str1.str().length());
        str1.str("");
        str1.clear();

        if (it->nested == NULL){
            cout << "NULL" << endl;
        }
        else{
            cout << it->nested->name << endl;
            tableIter.push_back(it->nested);
        }
    }

    for (int i = 0; i < 100; i++){
        cout << "-";
    }
    cout << "\n\n";

    for (listSymbolTableIterator iter = tableIter.begin(); iter != tableIter.end(); ++iter){
        (*iter)->print();
    }
}

//=========================================================================================================

//=========================================================================================================

bool compareSymbolType(sym*&s1, sym*&s2){
    symboltype* t1 = s1->type;
    symboltype* t2 = s2->type;
    int flag = 0;
    if (compareSymbolType(t1, t2)){
        flag = 1;
    }
    else if (s1 = typeConvert(s1, t2->type)){
        flag = 1;
    }
    else if (s2 = typeConvert(s2, t1->type)){
        flag = 1;
    }
    if (flag){
        return true;
    }
    else{
        return false;
    }
}

bool compareSymbolType(symboltype* t1, symboltype* t2){
    int flag = 0;
    if (t1 == NULL && t2 == NULL){
        return true;
    }
    else if (t1 == NULL || t2 == NULL || t1->type != t2->type){
        return false;
    }
    else{
        return compareSymbolType(t1->arrtype, t2->arrtype);
    }
}

quad::quad(string result, string arg1, string op, string arg2){
    (*this).result = result;
    (*this).arg1 = convertInt2String(arg1);
    (*this).op = op;
    (*this).arg2 = arg2;
}


/*
FOR THE FOLLOWING mapping, we will print the relevant format

int stringToInteger(string s){
    map <string, int> m;
    m = {
        {"L_SQUARE_BRACKET", 0}, {"R_SQUARE_BRACKET", 1}, {"L_ROUND_BRACKET", 2}, 
        {"R_ROUND_BRACKET", 3}, {"L_CURLY_BRACKET", 4}, {"R_CURLY_BRACKET", 5}, 
        {"ARROW", 6}, {"AMPERSAND", 7}, {"ASTERISK", 8}, {"PLUS", 9}, {"MINUS", 10}, 
        {"DIVIDE", 11}, {"MODULO", 12}, {"NOT", 13}, {"QUESTION", 14}, {"LESS_THAN", 15}, 
        {"GREATER_THAN", 16}, {"LESS_THAN_EQUAL_TO", 17}, {"GREATER_THAN_EQUAL_TO", 18}, 
        {"EQUAL_TO", 19}, {"NOT_EQUAL_TO", 20}, {"LOGICAL_AND", 21}, {"LOGICAL_OR", 22}, 
        {"ASSIGN", 23}, {"COLON", 24}, {"SEMICOLON", 25}, {"COMMA", 26}, {"CHAR", 27}, 
        {"ELSE", 28}, {"FOR", 29}, {"IF", 30}, {"INT", 31}, {"RETURN", 32}, {"VOID", 33}, 
        {"GOTO", 34}};
}

You can use the following as the example:


map <string, int> m = {{"+", 0}, {"-", 1}, {"*", 2},
        {"/", 3}, {"%", 4}, {"|", 5}, {"^", 6}, {"&", 7},
        {"==", 8}, {"!=", 9}, {"<=", 10}, {"<", 11}, 
		{">", 12}, {">=", 13}, {"goto", 14}, {">>", 15},
        {"<<", 16}, {"=", 17}, {"=&", 18}, {"=*", 19},
        {"*=", 20}, {"uminus", 21}, {"~", 22}, {"!", 23},
        {"=[]", 24}, {"[]=", 25}, {"return", 26}, 
		{"param", 27}, {"call", 28}, {"label", 29}
    }; 
// function that prints quads
void quad::print() 
{   
	int next_instr=0;	
    switch(s2i(op))
    {
        // Binary Operations
        case 0:
            debug_print();	
		    (*this).print1();
            break;
        
        case 1:
            debug_print();
		    (*this).print1();
            break;
    
        case 2:
            debug_print();
		    (*this).print1();
            break;

        case 3:
            debug_print();
		    (*this).print1();
            break;

        case 4:
            debug_print();	
		    (*this).print1();
            break;

        case 5:
            debug_print();	
		    (*this).print1();
            break;

        case 6:
            debug_print();
		    (*this).print1();
            break;

        case 7:
            debug_print();
		    (*this).print1();
            break;

        case 8:
            debug_print();
		    (*this).print2();
            break;

        case 9:
            debug_print();
		    (*this).print2();
            break;

        case 10:
            debug_print();
		    (*this).print2();
            break;

        case 11:
            debug_print();	
		    (*this).print2();
            break;

        case 12:
            debug_print();
		    (*this).print2();
            break;

        case 13:
            debug_print();
		    (*this).print2();
            break;

        case 14:
            debug_print();
		    cout<<"goto "<<res;
            break;

        // Shift Operations
        case 15:
            debug_print();
		    (*this).print1();
            break;

        case 16:
            debug_print();
		    (*this).print1();
            break;
    
        case 17:
            debug_print();			
		    cout<<res<<" = "<<arg1;
            break;

        // Unary Operators 
        case 18:
            debug_print();			
		    cout<<res<<" = &"<<arg1;
            break;

        case 19:
            debug_print();			
		    cout<<res<<" = *"<<arg1;
            break;

        case 20:
            debug_print();			
		    cout<<"*"<<res<<" = "<<arg1;
            break;

        case 21:
            debug_print();			
		    cout<<res<<" = -"<<arg1;
            break;
    
        case 22:
            debug_print();			
		    cout<<res<<" = ~"<<arg1;
            break;

        case 23:
            debug_print();			
		    cout<<res<<" = !"<<arg1;
            break;

        // Other operations
        case 24:
            debug_print();			
		    cout<<res<<" = "<<arg1<<"["<<arg2<<"]";
            break;

        case 25:
            debug_print();			
		    cout<<res<<"["<<arg1<<"]"<<" = "<< arg2;
            break;

        case 26:
            debug_print();			
		    cout<<"return "<<res;
            break;

        case 27:
            debug_print();			
		    cout<<"param "<<res;
            break;

        case 28:
            debug_print();			
		    cout<<res<<" = "<<"call "<<arg1<<", "<<arg2;
            break;

        case 29:
            debug_print();			
		    cout<<res<<": ";
            break;

        default:
            cout<<"Can't find "<<op;
            break;
    }  
    cout<<endl;         
}

void quad::print1()
{
	debug_print();
	cout<<res<<" = "<<arg1<<" "<<op<<" "<<arg2;
	debug_print();
}

// for printing if statmennts
void quad::print2()
{
	debug_print();
	cout<<"if "<<arg1<< " "<<op<<" "<<arg2<<" goto "<<res;
	debug_print();
}


*/
void quad::print(){
    int nextInstr = 0;
    switch (stringToInteger(op)){
        case 0: 
        
    }
}