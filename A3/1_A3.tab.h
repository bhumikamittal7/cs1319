/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_1_A3_TAB_H_INCLUDED
# define YY_YY_1_A3_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    VOID = 258,                    /* VOID  */
    CHAR = 259,                    /* CHAR  */
    INT = 260,                     /* INT  */
    IF = 261,                      /* IF  */
    ELSE = 262,                    /* ELSE  */
    FOR = 263,                     /* FOR  */
    RETURN = 264,                  /* RETURN  */
    IDENTIFIER = 265,              /* IDENTIFIER  */
    INTEGER_CONSTANT = 266,        /* INTEGER_CONSTANT  */
    CHARACTER_CONSTANT = 267,      /* CHARACTER_CONSTANT  */
    STRING_LITERAL = 268,          /* STRING_LITERAL  */
    L_SQUARE_BRACKET = 269,        /* L_SQUARE_BRACKET  */
    R_SQUARE_BRACKET = 270,        /* R_SQUARE_BRACKET  */
    L_ROUND_BRACKET = 271,         /* L_ROUND_BRACKET  */
    R_ROUND_BRACKET = 272,         /* R_ROUND_BRACKET  */
    L_CURLY_BRACKET = 273,         /* L_CURLY_BRACKET  */
    R_CURLY_BRACKET = 274,         /* R_CURLY_BRACKET  */
    ARROW = 275,                   /* ARROW  */
    AMPERSAND = 276,               /* AMPERSAND  */
    ASTERISK = 277,                /* ASTERISK  */
    PLUS = 278,                    /* PLUS  */
    MINUS = 279,                   /* MINUS  */
    DIVIDE = 280,                  /* DIVIDE  */
    MODULO = 281,                  /* MODULO  */
    NOT = 282,                     /* NOT  */
    QUESTION = 283,                /* QUESTION  */
    LESS_THAN = 284,               /* LESS_THAN  */
    GREATER_THAN = 285,            /* GREATER_THAN  */
    LESS_THAN_EQUAL_TO = 286,      /* LESS_THAN_EQUAL_TO  */
    GREATER_THAN_EQUAL_TO = 287,   /* GREATER_THAN_EQUAL_TO  */
    EQUAL_TO = 288,                /* EQUAL_TO  */
    NOT_EQUAL_TO = 289,            /* NOT_EQUAL_TO  */
    LOGICAL_AND = 290,             /* LOGICAL_AND  */
    LOGICAL_OR = 291,              /* LOGICAL_OR  */
    ASSIGN = 292,                  /* ASSIGN  */
    COLON = 293,                   /* COLON  */
    SEMICOLON = 294,               /* SEMICOLON  */
    COMMA = 295,                   /* COMMA  */
    INVALID_TOKEN = 296            /* INVALID_TOKEN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_1_A3_TAB_H_INCLUDED  */
