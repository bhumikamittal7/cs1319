#ifndef __1_A4_TRANSLATOR_H__
#define __1_A4_TRANSLATOR_H__

// Maxsize for symbol table
# define MAX_SIZE 100

const unsigned int size_of_char = 1;
const unsigned int size_of_int = 4;
const unsigned int size_of_pointer = 4;


/* Support for Lazy TAC generation through Quad array */
typedef enum{
    PLUS = 1,
    MINUS,
    ASTERISK,
    DIVIDE,
    MODULO,
    NOT,
    LOGICAL_AND,
    LOGICAL_OR,
    ASSIGN,
    LESS_THAN,
    GREATER_THAN,
    LESS_THAN_EQUAL_TO,
    GREATER_THAN_EQUAL_TO,
    EQUAL_TO,
    NOT_EQUAL_TO,
    L_SQUARE_BRACKET,
    R_SQUARE_BRACKET,
    L_ROUND_BRACKET,
    R_ROUND_BRACKET,
    L_CURLY_BRACKET,
    R_CURLY_BRACKET,
    ARROW,
    AMPERSAND,
    QUESTION,
    COLON,
    SEMICOLON,
    COMMA,
    GOTO,
    IF,
    IFFALSE,
    CALL,
    PARAM,
    RETURN,
    UMINUS,
    UPLUS,
} opcodeType;

char *opcodeArray[] = {"PLUS", "MINUS" };

typedef enum{
    INT,
    CHAR,
    PTR,
    VOID,
    BOOL
} dataType;
//=========================================================================================================================

//symbol table - name, type, initial value, size, offset, nested table
typedef struct symbolTableEntry{
    char *name;
    dataType type;
    void *initialValue;
    int size;
    int offset;
    struct symbolTable *nestedTable;
    struct symbolTableEntry *next;
} symbolTableEntry;

typedef struct symbolTable{
    symbolTableEntry *entry;
} symbolTable;

extern symbolTable symbol_table[MAX_SIZE];

//functions supported by symbol table - lookup, update, print, gentemp
symbolTable *newSymbolTable(char *name);
symbolTableEntry *newSymbolTableEntry(char *name, dataType type, void *initialValue, int size, int offset);
symbolTableEntry *lookup(symbolTable *st, char *name);
void update(symbolTable *st, symbolTableEntry *entry);
void printSymbolTable(symbolTable *st);
void printSymbolTableEntry(symbolTableEntry *entry);
char *gentemp(dataType type, symbolTable *st);

//===================================================================================================

/*quad array - op arg1 arg2 result*/
typedef struct quad{
    opcodeType op;
    char *arg1, *arg2, *result;
} quad;

//quad array
extern quad qArray[MAX_SIZE];
// we do extern here because we want to use the same quad array in all the files

//methods for quad array - emit, print
//emit has been overloaded to support unary and binary operations and copy
void emit_binary(char *result, char *arg1, opcodeType op, char *arg2);
void emit_unary(char *result, char *arg1, opcodeType op);
void emit_copy(char *result, opcodeType op, char *arg1);
void printQuadArray();
//===================================================================================================

//global functions for semantic actions - makelist, merge, backpatch,typecheck, conv
typedef struct list{
    int index;
    struct list *next;
} list;

list *makelist(int index);
list *merge(list *p1, list *p2);
void backpatch(list *p, int index);
void typecheck(symbolTableEntry *E1, symbolTableEntry *E2);

// int    <--> bool
// bool   <--> int
// char   <--> int
// int    <--> char
// pointer <--> int
// int    <--> pointer

void convInt2Bool(symbolTableEntry *E);
void convBool2Int(symbolTableEntry *E);
void convChar2Int(symbolTableEntry *E);
void convInt2Char(symbolTableEntry *E);
void convPtr2Int(symbolTableEntry *E);
void convInt2Ptr(symbolTableEntry *E);

//===================================================================================================

// Global variables for semantic actions - globalST, localST, currentST, globalOffset, localOffset, currentOffset, tempCount, labelCount
extern symbolTable *globalST;   // global symbol table
extern symbolTable *localST;
extern symbolTable *currentST;
extern int globalOffset;
extern int localOffset;
extern int currentOffset;
extern int tempCount;
extern int labelCount;

//===================================================================================================
#endif