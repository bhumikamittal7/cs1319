#ifndef __PARSER_H
#define __PARSER_H

typedef struct symtab{
    char *name;
    int value;
} symboltable;

symboltable *symlook (char *);

#endif // __PARSER_H