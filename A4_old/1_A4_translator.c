#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "1_A4_translator.h"

symbolTableEntry symtab[MAX_SIZE];	// -> Definition

extern void yyerror(char *s);

//symbol table functions
symbolTable *newSymbolTable(char *name){
    symbolTable *st = (symbolTable *)malloc(sizeof(symbolTable));
    st->entry = NULL;
    return st;
}

symbolTableEntry *newSymbolTableEntry(char *name, dataType type, void *initialValue, int size, int offset){
    symbolTableEntry *entry = (symbolTableEntry *)malloc(sizeof(symbolTableEntry));
    entry->name = strdup(name);
    entry->type = type;
    entry->initialValue = initialValue;
    entry->size = size;
    entry->offset = offset;
    entry->nestedTable = NULL;
    entry->next = NULL;
    return entry;
}

symbolTableEntry *lookup(symbolTable *st, char *name){
    symbolTableEntry *entry = st->entry;
    while(entry != NULL){
        if(strcmp(entry->name, name) == 0){
            return entry;
        }
        entry = entry->next;
    }
    return NULL;
}

void update(symbolTable *st, symbolTableEntry *entry){
    if(st->entry == NULL){
        st->entry = entry;
    }
    else{
        symbolTableEntry *temp = st->entry;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = entry;
    }
}

void printSymbolTable(symbolTable *st){
    symbolTableEntry *entry = st->entry;
    while(entry != NULL){
        printSymbolTableEntry(entry);
        entry = entry->next;
    }
}

void printSymbolTableEntry(symbolTableEntry *entry){
    printf("Name: %s, Type: %d, Size: %d, Offset: %d\n", entry->name, entry->type, entry->size, entry->offset);
}

char *gentemp(dataType type, symbolTable *st){
    tempCount++;
    char *name = (char *)malloc(sizeof(char) * 10);
    sprintf(name, "t%d", tempCount);
    symbolTableEntry *entry = newSymbolTableEntry(name, type, NULL, 1, 0);
    update(st, entry);
    return name;
}
//===================================================================================================

//quad array functions
quad quadArray[MAX_SIZE];
int nextInstruction = 0;

void emit_binary(char *result, char *arg1, opcodeType op, char *arg2){
    quadArray[nextInstruction].op = op;
    quadArray[nextInstruction].arg1 = arg1;
    quadArray[nextInstruction].arg2 = arg2;
    quadArray[nextInstruction].result = result;
    nextInstruction++;
}

void emit_unary(char *result, char *arg1, opcodeType op){
    emit_binary(result, arg1, op, NULL);
}

void emit_copy(char *result, opcodeType op, char *arg1){
    emit_binary(result, NULL, op, arg1);
}



void printQuadArray(){
    int i;
    for(i = 0; i < nextInstruction; i++){
        printf("%d: %s, %s, %s, %s\n", i, opcodeArray[quadArray[i].op], quadArray[i].arg1, quadArray[i].arg2, quadArray[i].result);
    
        }
}
//===================================================================================================   

// int    <--> bool
// bool   <--> int
// char   <--> int
// int    <--> char
// pointer <--> int
// int    <--> pointer

// list *makelist(int index);
// list *merge(list *p1, list *p2);
// void backpatch(list *p, int index);
// void typecheck(symbolTableEntry *E1, symbolTableEntry *E2);
// void convInt2Bool(symbolTableEntry *E);
// void convBool2Int(symbolTableEntry *E);
// void convChar2Int(symbolTableEntry *E);
// void convInt2Char(symbolTableEntry *E);
// void convPtr2Int(symbolTableEntry *E);
// void convInt2Ptr(symbolTableEntry *E);

list *makelist(int index){
    list *temp = (list *)malloc(sizeof(list));
    temp->index = index;
    temp->next = NULL;
    return temp;
}

list *merge(list *p1, list *p2){
    if(p1 == NULL){
        return p2;
    }
    else if(p2 == NULL){
        return p1;
    }
    else{
        list *temp = p1;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = p2;
        return p1;
    }
}

void backpatch(list *p, int index){
    list *temp = p;
    while(temp != NULL){
        quadArray[temp->index].result = (char *)malloc(sizeof(char) * 10);
        sprintf(quadArray[temp->index].result, "%d", index);
        temp = temp->next;
    }
}

void typecheck(symbolTableEntry *E1, symbolTableEntry *E2){
    if(E1->type == E2->type){
        return;
    }
    else if(E1->type == INT && E2->type == BOOL){
        convInt2Bool(E2);
    }
    else if(E1->type == BOOL && E2->type == INT){
        convBool2Int(E2);
    }
    else if(E1->type == CHAR && E2->type == INT){
        convChar2Int(E2);
    }
    else if(E1->type == INT && E2->type == CHAR){
        convInt2Char(E2);
    }
    else if(E1->type == PTR && E2->type == INT){
        convPtr2Int(E2);
    }
    else if(E1->type == INT && E2->type == PTR){
        convInt2Ptr(E2);
    }
    else{
        yyerror("Type mismatch");
    }
}

void convInt2Bool(symbolTableEntry *E){
    if(E->type == INT){
            E->type = BOOL;
        }
    }
    
    void convBool2Int(symbolTableEntry *E){
        if(E->type == BOOL){
            E->type = INT;
        }
    }

    void convChar2Int(symbolTableEntry *E){
        if(E->type == CHAR){
            E->type = INT;
        }
    }

    void convInt2Char(symbolTableEntry *E){
        if(E->type == INT){
            E->type = CHAR;
        }
    }

    void convPtr2Int(symbolTableEntry *E){
        if(E->type == PTR){
            E->type = INT;
        }
    }

    void convInt2Ptr(symbolTableEntry *E){
        if(E->type == INT){
            E->type = PTR;
        }
    }

void yyerror(char *s) {
	printf("%s\n", s);
}

int main(){
    //use the above function main as a reference
    symbolTable *globalST = newSymbolTable("Global");
    symbolTable *localST = newSymbolTable("Local");
    symbolTable *tempST = newSymbolTable("Temp");
    symbolTable *constantST = newSymbolTable("Constant");
    symbolTable *labelST = newSymbolTable("Label");
    symbolTable *functionST = newSymbolTable("Function");
    symbolTable *arrayST = newSymbolTable("Array");
    symbolTable *recordST = newSymbolTable("Record");
    symbolTable *pointerST = newSymbolTable("Pointer");
    symbolTable *currentST = globalST;

    //test code
    symbolTableEntry *entry1 = newSymbolTableEntry("a", INT, NULL, 1, 0);
    symbolTableEntry *entry2 = newSymbolTableEntry("b", BOOL, NULL, 1, 0);

    update(globalST, entry1);
    update(globalST, entry2);

    printSymbolTable(globalST);

}
