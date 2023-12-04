#include "1_A5_translator.h"
#include <string>
#include <sstream>  //this is for the stringstream which allows us to use the >> operator
#include <iostream> //this is for the cout and cerr

using namespace std;

/*=========================================================================================*/
// Global Variables
symTable *ST;             // current Symbol Table
symTable *globalST;       // Global Symbol Table
sym *currentSymbol;       // current Symbol
quadArray quadArr;        // Quad Array
basicType bType;          // Basic Type
long long int instrCount; // Instruction Count
string var_type;          // this is for the variable type
/*=========================================================================================*/
// Stupid but useful functions
void updateNextInstr()
{
    instrCount = instrCount + 1;
}

int nextInstr()
{
    return quadArr.Array.size();
}

void addSpaces(int n)
{
    for (int i = 0; i < n; i++)
        cout << " ";
}

void changeTable(symTable *nTable)
{
    ST = nTable;
}

int sizeOfType(symbolType *t)
{
    if (t->type.compare("void") == 0)
        return bType.size[1];
    else if (t->type.compare("char") == 0)
        return size_of_char;
    else if (t->type.compare("int") == 0)
        return size_of_int;
    else if (t->type.compare("arr") == 0)
        return t->width * sizeOfType(t->arrtype);
    else if (t->type.compare("ptr") == 0)
        return size_of_pointer;
    else if (t->type.compare("func") == 0)
        return bType.size[6];
    else
        return -1;
}

string printType(symbolType *t)
{
    if (t == NULL)
        return bType.type[0];
    else if (t->type.compare("void") == 0)
        return bType.type[1];
    else if (t->type.compare("char") == 0)
        return bType.type[2];
    else if (t->type.compare("int") == 0)
        return bType.type[3];
    else if (t->type.compare("ptr") == 0)
        return bType.type[4] + "(" + printType(t->arrtype) + ")";
    else if (t->type.compare("arr") == 0)
        return bType.type[5] + "(" + convertToString(t->width) + "," + printType(t->arrtype) + ")";
    else if (t->type.compare("func") == 0)
        return bType.type[6];
    else
        return "Type not found";
}

// Print the Quad Type 1
void quad::printType1()
{
    cout << result << " = " << arg1 << " " << op << " " << arg2;
}

// Print the Quad Type 2
void quad::printType2()
{
    cout << "if " << arg1 << " " << op << " " << arg2 << " goto " << result;
}

/*=========================================================================================*/
// Symbol Table Entry
sym::sym(string name, string t, symbolType *arrtype, int width)
{
    (*this).name = name;
    type = new symbolType(t, arrtype, width);
    size = sizeOfType(type);
    offset = 0;
    nested = NULL;
    val = "-";
}

sym *sym::update(symbolType *t)
{
    type = t;
    (*this).size = sizeOfType(t);
    return this;
}

// Symbol Type
symbolType::symbolType(string type, symbolType *arrtype, int width)
{
    (*this).type = type;
    (*this).width = width;
    (*this).arrtype = arrtype;
}

// Symbol Table
symTable::symTable(string name)
{
    (*this).name = name;
    tempCount = 0;
}

// basic idea: we will iterate through the list of symbols and if we find the symbol, we will return it
// if we don't find it, we will create a new symbol, push it into the list and return it
sym *symTable::lookup(string name)
{
    sym *symbol;
    listIterator it;
    it = table.begin();
    while (it != table.end())
    {
        if (it->name == name)
        {
            return &(*it);
        }
        it++;
    }

    symbol = new sym(name);
    table.push_back(*symbol);
    return &table.back();
}

// to update the symbol table
void symTable::update()
{
    list<symTable *> tableList; // this is a list of symbol tables
    int off;
    listIterator it;

    it = table.begin();
    while (it != table.end())
    {
        if (it == table.begin())
        {
            it->offset = 0;
            off = it->size;
        }
        else
        {
            it->offset = off;
            off = it->offset + it->size;
        }
        if (it->nested != NULL)
        {
            tableList.push_back(it->nested);
        }
        it++;
    }

    list<symTable *>::iterator it1;
    it1 = tableList.begin();
    while (it1 != tableList.end())
    {
        (*it1)->update();
        it1++;
    }
}

// to print the symbol table - found this formatting online so this part of the code is kinda inspired (my formatting wasn't this neat) - though the code is written by me (only style is copied)
void symTable::print()
{
    int nextInstr = 0;
    list<symTable *> tableList;

    for (int i = 0; i < 60; i++)
        cout << "__";
    cout << endl;

    cout << "Table Name: " << (*this).name << "\t\t\t\t\t\t Parent Name: ";

    if ((*this).parent != NULL)
        cout << (*this).parent->name << endl;
    else
        cout << "NULL" << endl;

    for (int i = 0; i < 60; i++)
        cout << "__";
    cout << endl;

    cout << "Name";             addSpaces(15);
    cout << "Type";             addSpaces(15);
    cout << "Initial Value";    addSpaces(15);
    cout << "Size";             addSpaces(15);
    cout << "Offset";           addSpaces(15);
    cout << "Nested";           addSpaces(20);
    cout << endl;

    ostringstream str1; // this is for the string stream

    for (listIterator it = table.begin(); it != table.end(); it++)
    {
        cout << it->name;
        addSpaces(18 - it->name.length());

        string typeResult = printType(it->type);
        cout << typeResult;
        addSpaces(23 - typeResult.length());

        cout << it->val;
        addSpaces(26 - it->val.length());

        cout << it->size;
        str1 << it->size;
        addSpaces(20 - str1.str().length());

        str1.str("");
        str1.clear();
        cout << it->offset;
        str1 << it->offset;
        addSpaces(20 - str1.str().length());

        str1.str("");
        str1.clear();
        if (it->nested != NULL)
        {
            cout << it->nested->name;
            tableList.push_back(it->nested);
        }
        else
            cout << "NULL";
        addSpaces(20);
        cout << endl;
    }

    for (int i = 0; i < 120; i++)
        cout << "-";
    cout << "\n";

    for (list<symTable *>::iterator it1 = tableList.begin(); it1 != tableList.end(); it1++)
    {
        (*it1)->print();
    }
}

/*=========================================================================================*/
// Quad
quad::quad(string result, string arg1, string op, string arg2)
{
    (*this).result = result;
    (*this).arg1 = arg1;
    (*this).op = op;
    (*this).arg2 = arg2;
}

quad::quad(string result, int arg1, string op, string arg2)
{
    (*this).result = result;
    (*this).arg2 = arg2;
    (*this).op = op;
    (*this).arg1 = convertToString(arg1);
}

void quad::print()
{
    int nextInstr = 0;
    if (op == "+" || op == "-" || op == "*" || op == "/" || op == "%")
    {

        (*this).printType1();
    }
    else if (op == "||" | op == "&&" | op == "==" | op == "!=" | op == "<=" | op == "<" | op == ">" | op == ">=")
    {

        (*this).printType2();
    }
    else if (op == "=")
    {

        cout << result << " = " << arg1;
    }
    else if (op == "uminus")
    {

        cout << result << " = -" << arg1;
    }

    else if (op == "!")
    {

        cout << result << " = !" << arg1;
    }
    else if (op == "return")
    {

        cout << "return " << result;
    }
    else if (op == "goto")
    {
        cout << "goto " << result;
    }
    else if (op == "label")
    {
        cout << "label " << result;
    }
    else if (op == "param")
    {
        cout << "param " << result;
    }
    else if (op == "call")
    {
        cout << "call " << result;
    }
    else
    {
        cout << "Can't find " << op;
    }
    cout << endl;
}

// add the new data type to the symbol typle ST
void basicType::addType(string t, int s)
{
    type.push_back(t);
    size.push_back(s);
}

// Quad Array print
void quadArray::print()
{   
    cout << "TAC (Three Address Code) \n" << endl;
    int k = 100;
    vector<quad>::iterator it = Array.begin();

    while (it != Array.end())
    {
        cout << k << ": ";
        addSpaces(2);
        it->print();
        it++;
        k++;
    }
}
/*=========================================================================================*/

string convertToString(int num)
{
    stringstream ss;
    ss << num;

    string temp = ss.str();
    char *integer = (char *)temp.c_str();
    string stringNew = string(integer);
    return stringNew;
}
/*=========================================================================================*/

// emit
void emit(string op, string result, string arg1, string arg2)
{
    quad *q1 = new quad(result, arg1, op, arg2);
    quadArr.Array.push_back(*q1);
}

void emit(string op, string result, int arg1, string arg2)
{
    quad *q2 = new quad(result, arg1, op, arg2);
    quadArr.Array.push_back(*q2);
}
/*=========================================================================================*/

// type conversion stuff
sym *convertType(sym *s, string t)
{
    sym *tmp = gentemp(new symbolType(t));

    if ((*s).type->type == "int")
    {
        if (t == "char")
        {
            emit("=", tmp->name, "int2char(" + (*s).name + ")");
            return tmp;
        }
        return s;
    }
    else if ((*s).type->type == "char")
    {
        if (t == "int")
        {
            emit("=", tmp->name, "char2int(" + (*s).name + ")", "");
            return tmp;
        }
        return s;
    }
    return s;
}
/*=========================================================================================*/
bool compareSymbolType(sym *&s1, sym *&s2)
{
    symbolType *t1 = s1->type;
    symbolType *t2 = s2->type;
    if (compareSymbolType(t1, t2))
        return true;
    else if (s1 == convertType(s1, t2->type))
        return true;
    else if (s2 == convertType(s2, t1->type))
        return true;
    else
        return false;
}

bool compareSymbolType(symbolType *t1, symbolType *t2)
{
    if (t1 == NULL && t2 == NULL)
        return true;
    else if (t1 == NULL || t2 == NULL || t1->type != t2->type)
        return false;
    else
        return compareSymbolType(t1->arrtype, t2->arrtype);
}
/*=========================================================================================*/

sym *gentemp(symbolType *t, string init)
{
    string name = "t" + convertToString(ST->tempCount++);
    sym *s = new sym(name);
    (*s).type = t;
    (*s).size = sizeOfType(t);
    (*s).val = init;
    ST->table.push_back(*s);
    return &ST->table.back();
}

void backpatch(list<int> l, int address)
{
    string str = convertToString(address);
    list<int>::iterator it = l.begin();
    while (it != l.end())
    {
        quadArr.Array[*it].result = str;
        it++;
    }
}

list<int> makelist(int i)
{
    list<int> newL(1, i);
    return newL;
}

list<int> merge(list<int> &l1, list<int> &l2)
{
    l1.merge(l2);
    return l1;
}
/*=========================================================================================*/

Expression *convertInt2Bool(Expression *e)
{
    if (e->type != "bool")
    {
        e->falseList = makelist(nextInstr());
        emit("==", "", e->loc->name, "0");
        e->trueList = makelist(nextInstr());
        emit("goto", " ");
    }
    return e;
}

Expression *convertBool2Int(Expression *e)
{
    if (e->type == "bool")
    {
        e->loc = gentemp(new symbolType("int"));
        backpatch(e->trueList, nextInstr());
        emit("=", e->loc->name, "true");
        int inst = nextInstr() + 1;
        string str = convertToString(inst);
        emit("goto", str);
        backpatch(e->falseList, nextInstr());
        emit("=", e->loc->name, "false");
    }
    return e;
}

/*=========================================================================================*/
int main()
{
    bType.addType("null", 0);
    bType.addType("void", 0);
    bType.addType("char", size_of_char);
    bType.addType("int", size_of_int);
    bType.addType("ptr", size_of_pointer);
    bType.addType("arr", 0);
    bType.addType("func", 0);

    instrCount = 0;

    globalST = new symTable("Global");
    ST = globalST;

    yyparse();
    globalST->update();

    cout << "\n";
    quadArr.print(); // print the TAC
    cout << "\n";
    globalST->print(); // print the symbol table
    cout << "\n";

    // pls work otherwise i will legit kms bruh!
}

/*
=====================================================================================================
Reference - I read through multiple tinyC compiler stuff to understand how their thing is implemented.
Hence, some of the code is inspired from there but I have written everything from scratch.
I have also referred to the class slides and the dragon book for the same.

Also, thanks to copilot for helping me finish my comments faster (hence citing copilot for comments as well).
=====================================================================================================
*/