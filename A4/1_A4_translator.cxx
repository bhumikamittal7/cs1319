#include "1_A4_translator.h"
#include <string>           
#include <sstream>          //this is for the stringstream which allows us to use the >> operator
#include <iostream>         //this is for the cout and cerr

using namespace std;

/*=========================================================================================*/

//Global Variables
symTable* ST;						// current Symbol Table
symTable* globalST;				    // Global Symbol Table
sym* currentSymbol;				    // current Symbol
quadArray quadArr;				    // Quad Array
basicType bType;				    // Basic Type
long long int instrCount;			// Instruction Count
/*=========================================================================================*/
//Stupid functions 
void updateNextInstr(){
    instrCount = instrCount + 1;
}

int nextInstr(){
    return quadArr.Array.size();
}

void generateSpace(int n){
    for (int i=0; i<n; i++) cout<<" ";
}
/*=========================================================================================*/
//we will now define the constructors for the classes we have declared in the header file

//Symbol Table Entry
sym::sym (string name, string t, symbolType* arrtype , int width){
    (*this).name=name;
    type = new symbolType(t, arrtype, width);
    size = sizeOfType(type);
    offset = 0;
    nested = NULL;
    val = "-";
}

sym* sym::update(symbolType* t){
    type = t;
    (*this).size = sizeOfType(t);
    return this;
}

//Symbol Type
symbolType::symbolType(string t, symbolType* ptr, int width){
    (*this).type = t;
    (*this).width = width;
    (*this).arrtype = ptr;
}

//Symbol Table
symTable::symTable(string name){
    (*this).name = name;
    (*this).tempCount = 0;
}

//basic idea: we will iterate through the list of symbols and if we find the symbol, we will return it
//if we don't find it, we will create a new symbol, push it into the list and return it
sym* symTable::lookup(string name){
    sym* s;
    listIterator it;
    it = table.begin();
    while(it!=table.end()){
        if (it->name == name){
            s = &(*it);
            return s;
        }
        it++;
    }

    s = new sym(name);
    table.push_back(*s);
    return &table.back();
}

//to update the symbol table
void symTable::update(){
    list <symTable*> tableList;         //this is a list of symbol tables
    int offset;
    listIterator it;

    it = table.begin();
    while(it!=table.end()){
        if(it==table.begin()){
            it->offset = 0;
            offset = it->size;
        }
        else{
            it->offset = offset;
            offset = offset + it->size;
        }
        if(it->nested!=NULL){
            tableList.push_back(it->nested);
        }
        it++;
    }

    list <symTable*> :: iterator it1;
    it1 = tableList.begin();
    while(it1!=tableList.end()){
        (*it1)->update();
        it1++;
    }
}

//to print the symbol table
void symTable::print(){
    int nextInstr = 0;
    list<symTable*> tableList;

    for (int i=0; i<80; i++) cout<<"__";
    cout<<endl;

    cout<<"Table Name: "<<(*this).name<<"\t\t\t Parent Name: ";

    if((*this).parent!=NULL) cout<<(*this).parent->name<<endl;
    else cout<<"NULL"<<endl;

    for (int i=0; i<80; i++) cout<<"__";
    cout<<endl;

    cout<<"Name";
    generateSpace(15);
    cout<<"Type";
    generateSpace(15);
    cout<<"Initial Value";
    generateSpace(15);
    cout<<"Size";
    generateSpace(15);
    cout<<"Offset";
    generateSpace(15);
    cout<<"Nested";
    generateSpace(20);
    cout<<endl;

    ostringstream str1;         //this is for the string stream

    for (listIterator it = table.begin(); it != table.end(); it++){
        cout<<it->name;
        generateSpace(15 - it->name.length());

        string typeResult = printType(it->type);
        cout<<typeResult;
        generateSpace(20 - typeResult.length());

        cout<<it->val;
        generateSpace(15 - it->val.length());

        cout << it->size;
        str1 << it->size;
        generateSpace(15 - str1.str().length());

        str1.str("");
        str1.clear();
        cout << it->offset;
        str1 << it->offset;
        generateSpace(15 - str1.str().length());

        str1.str("");
        str1.clear();
        if(it->nested!=NULL) {cout<<it->nested->name; tableList.push_back(it->nested);}
        else cout<<"NULL"<<endl;
    }

    for (int i=0; i<80; i++) cout<<"-";
    cout<<"\n\n";

    for (list<symTable*>::iterator it1 = tableList.begin(); it1 != tableList.end(); it1++){
        (*it1)->print();
    }

}

//Quad
quad::quad(string op, string arg1, string arg2, string result){
    (*this).op = op;
    (*this).arg1 = arg1;
    (*this).arg2 = arg2;
    (*this).result = result;
}

quad::quad(string op, int arg1, string arg2, string result){
    (*this).op = op;
    (*this).arg1 = convertToString(arg1);
    (*this).arg2 = arg2;
    (*this).result = result;
}

// typedef enum {

// ARROW,
//     QUESTION,
//     COLON,
//     SEMICOLON,
//     COMMA,
//     CHAR,
//     ELSE,
//     FOR,
//     IF,
//     INT,
//     VOID,
// } opcodeType;

//Print the Quad - might need to fix this (flagging)
void quad::print(){

    //binary
    int nextInstr = 0;

    if (op == "PLUS" || op =="MINUS" || op == "DIVIDE" || op == "MODULO" || op == "ASTERISK" || op == "AMPERSAND"){
        (*this).printType1();
    }
    //relational
    else if (op =="LOGICAL_OR" || op == "LOGICAL_AND" || op == "LESS_THAN" || op == "GREATER_THAN" || op == "LESS_THAN_EQUAL_TO" || op == "GREATER_THAN_EQUAL_TO" || op == "EQUAL_TO" || op == "NOT_EQUAL_TO"){
        (*this).printType2();
    }
    else if (op == "ASSIGN"){
        cout<<result<<" = "<<arg1;
    }
    //unary
    else if (op =="NOT"){
        cout << result << " = ! " << arg1;
    }
    else if (op == "UMINUS"){
        cout << result << " = - " << arg1;
    }
    else if (op == "UPLUS"){
        cout << result << " = + " << arg1;
    }
    //return
    else if (op == "RETURN"){
        cout << "return " << result;
    }
    else {
        cout << "error" << op;
    }
    cout << endl;
}

//Print the Quad Type 1
void quad::printType1(){
    cout << result << " = " << arg1 << " " << op << " " << arg2;
}

//Print the Quad Type 2
void quad::printType2(){
    cout << "if " << arg1 << " " << op << " " << arg2 << " goto " << result;
}

//add the new data type to the symbol typle ST
void basicType::addType(string t, int s){
    type.push_back(t);
    size.push_back(s);
}

//Quad Array
void quadArray::print(){
    for (int i=0; i<80; i++) cout<<"__";
    cout<<endl;

    cout<<"TAC"<<endl;
    for (int i=0; i<80; i++) cout<<"__";
    cout<<endl;

    int i = 0;
    vector<quad>::iterator it = Array.begin();

    while (it != Array.end()){
        cout << i << ": ";
        generateSpace(5);
        it->print();
        it++;
        i++;
    }

    for (int i=0; i<80; i++) cout<<"__";
    cout<<endl;
}
/*=========================================================================================*/

string convertToString(int num){
    stringstream ss;
    ss << num;

    string temp = ss.str();
    char* integer = (char*) temp.c_str();
    string stringNew = string(integer);
    return stringNew;

}
/*=========================================================================================*/

//emit 
void emit(string op, string arg1, string arg2, string result){
    quadArr.Array.push_back(*(new quad(op, arg1, arg2, result)));
}

void emit(string op, int arg1, string arg2, string result){
    quadArr.Array.push_back(*(new quad(op, arg1, arg2, result)));
}
/*=========================================================================================*/

//type conversion stuff
sym* convertType(sym* s, string t){
    sym* tmp = gentemp(new symbolType(t));
    if((*s).type-> type == "INTEGER"){
        if (t == "CHAR"){
            emit("=", tmp->name, "int2char("+(*s).name+")", "");
            return tmp;
        }
           return s;
        }
     else if ((*s).type->type == "CHAR" ){
        if (t == "INTEGER"){
            emit("=", tmp->name, "char2int("+(*s).name+")", "");
            return tmp;
        }
        return s;
    }
    else {
    cout << "error" << endl;
    }
    return s;
}
/*=========================================================================================*/
void changeTable(symTable* nTable){
    ST = nTable;
}

bool compareSymbolType(sym*& s1, sym*& s2){
    symbolType* t1 = s1->type;
    symbolType* t2 = s2->type;
    if(compareSymbolType(t1,t2)) 
		return true;
    else if(s1 = convertType(s1, t2->type))
        return true;
    else if(s2 = convertType(s2, t1->type))
        return true;
    else
        return false;
}

bool compareSymbolType(symbolType* t1, symbolType* t2){
    if (t1 == NULL && t2 == NULL) return true;
    else if (t1 == NULL || t2 == NULL || t1->type!=t2->type) return false;
    else return compareSymbolType(t1->arrtype, t2->arrtype);
}
/*=========================================================================================*/
void backpatch(list<int> l, int address){
    string str = convertToString(address);
    list<int>::iterator it = l.begin();
    while(it!=l.end()){
        quadArr.Array[*it].result = str;
        it++;
    }
}

list<int> makelist(int i){
    list<int> l(1,i);
    return l;
}

list<int> merge(list<int> &a, list<int> &b){
    a.merge(b);
    return a;
}
/*=========================================================================================*/

Expression* convertInt2Bool(Expression* e){
    if(e->type!="BOOL"){
        e -> falseList = makelist(nextInstr());
        emit("EQUAL_TO", e->loc->name, "0", " ");
        e -> trueList = makelist(nextInstr());
        emit("GOTO", " ");
    }
}

Expression* convertBool2Int(Expression* e){
    if(e->type=="BOOL"){
        e -> loc = gentemp(new symbolType("INTEGER"));
        backpatch(e->trueList, nextInstr());
        emit("=", e->loc->name, "true", " ");
        int inst = nextInstr()+1;
        string str = convertToString(inst);
        emit("GOTO", str);
        backpatch(e->falseList, nextInstr());
        emit("=", e->loc->name, "false", " ");
    }
}

/*=========================================================================================*/

sym* gentemp(symbolType* t, string init){
    string name = "t" + convertToString(ST->tempCount);
    sym* s = new sym(name);
    (*s).type = t;
    (*s).size = sizeOfType(t);
    (*s).val = init;
    ST->table.push_back(*s);
    return &ST->table.back();
}

int sizeOfType(symbolType* t){
    if(t->type=="VOID") return 0;
    else if(t->type=="CHAR") return size_of_char;
    else if(t->type=="INTEGER") return size_of_int;
    else if(t->type=="PTR") return size_of_pointer;
    else if(t->type=="ARR") return t->width * sizeOfType(t->arrtype);
    else if(t->type=="FUNC") return 0;
    else if(t->type=="BOOL") return 1;
    else cout << "error" << endl;
}

string printType(symbolType* t){
    if(t==NULL) return bType.type[0];
    else if(t->type=="VOID") return bType.type[1];
    else if(t->type=="CHAR") return bType.type[2];
    else if(t->type=="INTEGER") return bType.type[3];
    else if(t->type=="PTR") return (bType.type[4] + "(" + printType(t->arrtype) + ")");
    else if(t->type=="ARR") return (bType.type[5] + "(" + convertToString(t->width) + "," + printType(t->arrtype) + ")");
    else if(t->type=="FUNC") return (bType.type[6] + "(" + printType(t->arrtype) + ")");
    else if(t->type=="BOOL") return bType.type[7];
    else cout << "error" << endl;
}

/*=========================================================================================*/

int main(){
    bType.addType("NULL", 0);
    bType.addType("VOID", 0);
    bType.addType("CHAR", size_of_char);
    bType.addType("INTEGER", size_of_int);
    bType.addType("PTR", size_of_pointer);
    bType.addType("ARR", 0);
    bType.addType("FUNC", 0);
    bType.addType("BOOL", 1);

    instrCount = 0;

    globalST = new symTable("Global");
    ST = globalST;

    yyparse();
    globalST->update();

    cout << "\n";
    quadArr.print();
    cout << "\n";
    globalST->print();

    //pls work otherwise i will legit kms bruh!
}

/*
=====================================================================================================
Reference - I read through multiple tinyC compiler stuff to understand how their thing is implemented.
Hence, some of the code is inspired from there but I have written everything from scratch. 
I have also referred to the class slides and the dragon book for the same.

Also, thanks to copilot for helping me finish my comments faster (hence citing copilot for comments as well).
=====================================================================================================
*/