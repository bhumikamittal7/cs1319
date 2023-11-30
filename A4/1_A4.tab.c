/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "1_A4.y"

#include <string>
#include <stdio.h>
#include "1_A4_translator.h"
#include <iostream>              
#include <cstdlib>
#include <sstream>

extern string var_type;
extern int yylex();
void yyerror(const char *s);

using namespace std;

#line 86 "1_A4.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "1_A4.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_INTEGER_CONSTANT = 4,           /* INTEGER_CONSTANT  */
  YYSYMBOL_CHARACTER_CONSTANT = 5,         /* CHARACTER_CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 6,             /* STRING_LITERAL  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_CHAR = 8,                       /* CHAR  */
  YYSYMBOL_INT = 9,                        /* INT  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_FOR = 12,                       /* FOR  */
  YYSYMBOL_RETURN = 13,                    /* RETURN  */
  YYSYMBOL_L_SQUARE_BRACKET = 14,          /* L_SQUARE_BRACKET  */
  YYSYMBOL_R_SQUARE_BRACKET = 15,          /* R_SQUARE_BRACKET  */
  YYSYMBOL_L_ROUND_BRACKET = 16,           /* L_ROUND_BRACKET  */
  YYSYMBOL_R_ROUND_BRACKET = 17,           /* R_ROUND_BRACKET  */
  YYSYMBOL_L_CURLY_BRACKET = 18,           /* L_CURLY_BRACKET  */
  YYSYMBOL_R_CURLY_BRACKET = 19,           /* R_CURLY_BRACKET  */
  YYSYMBOL_ARROW = 20,                     /* ARROW  */
  YYSYMBOL_AMPERSAND = 21,                 /* AMPERSAND  */
  YYSYMBOL_ASTERISK = 22,                  /* ASTERISK  */
  YYSYMBOL_PLUS = 23,                      /* PLUS  */
  YYSYMBOL_MINUS = 24,                     /* MINUS  */
  YYSYMBOL_DIVIDE = 25,                    /* DIVIDE  */
  YYSYMBOL_MODULO = 26,                    /* MODULO  */
  YYSYMBOL_NOT = 27,                       /* NOT  */
  YYSYMBOL_QUESTION = 28,                  /* QUESTION  */
  YYSYMBOL_LESS_THAN = 29,                 /* LESS_THAN  */
  YYSYMBOL_GREATER_THAN = 30,              /* GREATER_THAN  */
  YYSYMBOL_LESS_THAN_EQUAL_TO = 31,        /* LESS_THAN_EQUAL_TO  */
  YYSYMBOL_GREATER_THAN_EQUAL_TO = 32,     /* GREATER_THAN_EQUAL_TO  */
  YYSYMBOL_EQUAL_TO = 33,                  /* EQUAL_TO  */
  YYSYMBOL_NOT_EQUAL_TO = 34,              /* NOT_EQUAL_TO  */
  YYSYMBOL_LOGICAL_AND = 35,               /* LOGICAL_AND  */
  YYSYMBOL_LOGICAL_OR = 36,                /* LOGICAL_OR  */
  YYSYMBOL_ASSIGN = 37,                    /* ASSIGN  */
  YYSYMBOL_COLON = 38,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 39,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 40,                     /* COMMA  */
  YYSYMBOL_INVALID_TOKEN = 41,             /* INVALID_TOKEN  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_M = 43,                         /* M  */
  YYSYMBOL_N = 44,                         /* N  */
  YYSYMBOL_primary_expression = 45,        /* primary_expression  */
  YYSYMBOL_postfix_expression = 46,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list_opt = 47, /* argument_expression_list_opt  */
  YYSYMBOL_argument_expression_list = 48,  /* argument_expression_list  */
  YYSYMBOL_unary_expression = 49,          /* unary_expression  */
  YYSYMBOL_unary_operator = 50,            /* unary_operator  */
  YYSYMBOL_multiplicative_expression = 51, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 52,       /* additive_expression  */
  YYSYMBOL_relational_expression = 53,     /* relational_expression  */
  YYSYMBOL_equality_expression = 54,       /* equality_expression  */
  YYSYMBOL_logical_AND_expression = 55,    /* logical_AND_expression  */
  YYSYMBOL_logical_OR_expression = 56,     /* logical_OR_expression  */
  YYSYMBOL_conditional_expression = 57,    /* conditional_expression  */
  YYSYMBOL_assignment_expression = 58,     /* assignment_expression  */
  YYSYMBOL_expression = 59,                /* expression  */
  YYSYMBOL_declaration = 60,               /* declaration  */
  YYSYMBOL_init_declarator_list = 61,      /* init_declarator_list  */
  YYSYMBOL_init_declarator = 62,           /* init_declarator  */
  YYSYMBOL_type_specifier = 63,            /* type_specifier  */
  YYSYMBOL_declarator = 64,                /* declarator  */
  YYSYMBOL_direct_declarator = 65,         /* direct_declarator  */
  YYSYMBOL_changetable = 66,               /* changetable  */
  YYSYMBOL_pointer = 67,                   /* pointer  */
  YYSYMBOL_parameter_list = 68,            /* parameter_list  */
  YYSYMBOL_parameter_list_opt = 69,        /* parameter_list_opt  */
  YYSYMBOL_identifier_opt = 70,            /* identifier_opt  */
  YYSYMBOL_parameter_declaration = 71,     /* parameter_declaration  */
  YYSYMBOL_initializer = 72,               /* initializer  */
  YYSYMBOL_statement = 73,                 /* statement  */
  YYSYMBOL_compound_statement = 74,        /* compound_statement  */
  YYSYMBOL_block_item_list_opt = 75,       /* block_item_list_opt  */
  YYSYMBOL_block_item_list = 76,           /* block_item_list  */
  YYSYMBOL_block_item = 77,                /* block_item  */
  YYSYMBOL_expression_statement = 78,      /* expression_statement  */
  YYSYMBOL_selection_statement = 79,       /* selection_statement  */
  YYSYMBOL_iteration_statement = 80,       /* iteration_statement  */
  YYSYMBOL_jump_statement = 81,            /* jump_statement  */
  YYSYMBOL_translation_unit = 82,          /* translation_unit  */
  YYSYMBOL_external_declaration = 83,      /* external_declaration  */
  YYSYMBOL_function_definition = 84,       /* function_definition  */
  YYSYMBOL_declaration_list = 85,          /* declaration_list  */
  YYSYMBOL_declaration_list_opt = 86       /* declaration_list_opt  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   227

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  178

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    92,    92,    98,   107,   116,   127,   136,   146,   152,
     164,   204,   215,   218,   219,   222,   229,   238,   239,   289,
     294,   299,   304,   309,   316,   343,   359,   375,   393,   397,
     413,   431,   435,   461,   487,   513,   541,   545,   575,   607,
     608,   631,   635,   658,   662,   703,   707,   740,   744,   749,
     750,   752,   753,   756,   757,   766,   767,   768,   771,   784,
     787,   797,   831,   863,   864,   885,   888,   908,   914,   919,
     922,   923,   927,   928,   931,   932,   935,   938,   943,   947,
     952,   956,   960,   966,   972,   976,   979,   983,   990,   991,
     997,   998,  1001,  1016,  1035,  1059,  1066,  1078,  1079,  1082,
    1083,  1087,  1100,  1101,  1104,  1105
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "INTEGER_CONSTANT", "CHARACTER_CONSTANT", "STRING_LITERAL", "VOID",
  "CHAR", "INT", "IF", "ELSE", "FOR", "RETURN", "L_SQUARE_BRACKET",
  "R_SQUARE_BRACKET", "L_ROUND_BRACKET", "R_ROUND_BRACKET",
  "L_CURLY_BRACKET", "R_CURLY_BRACKET", "ARROW", "AMPERSAND", "ASTERISK",
  "PLUS", "MINUS", "DIVIDE", "MODULO", "NOT", "QUESTION", "LESS_THAN",
  "GREATER_THAN", "LESS_THAN_EQUAL_TO", "GREATER_THAN_EQUAL_TO",
  "EQUAL_TO", "NOT_EQUAL_TO", "LOGICAL_AND", "LOGICAL_OR", "ASSIGN",
  "COLON", "SEMICOLON", "COMMA", "INVALID_TOKEN", "$accept", "M", "N",
  "primary_expression", "postfix_expression",
  "argument_expression_list_opt", "argument_expression_list",
  "unary_expression", "unary_operator", "multiplicative_expression",
  "additive_expression", "relational_expression", "equality_expression",
  "logical_AND_expression", "logical_OR_expression",
  "conditional_expression", "assignment_expression", "expression",
  "declaration", "init_declarator_list", "init_declarator",
  "type_specifier", "declarator", "direct_declarator", "changetable",
  "pointer", "parameter_list", "parameter_list_opt", "identifier_opt",
  "parameter_declaration", "initializer", "statement",
  "compound_statement", "block_item_list_opt", "block_item_list",
  "block_item", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "declaration_list",
  "declaration_list_opt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-118)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-105)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     108,  -118,  -118,  -118,  -118,     3,   100,  -118,  -118,  -118,
       2,  -118,  -118,    51,  -118,     8,     6,    27,  -118,  -118,
      -7,  -118,     2,   197,  -118,     3,   108,  -118,   183,  -118,
    -118,     6,  -118,  -118,    30,  -118,  -118,  -118,  -118,   197,
    -118,  -118,  -118,  -118,  -118,  -118,    36,    33,   197,    60,
      97,    82,    72,    43,    23,  -118,  -118,  -118,  -118,    70,
    -118,   115,   126,   108,  -118,     4,   197,   197,    93,   197,
    -118,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,    88,    37,   130,  -118,  -118,  -118,   125,   122,
     148,  -118,  -118,   197,   -12,   149,   127,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,    60,    60,    97,    97,    97,    97,
      82,    82,  -118,  -118,  -118,   152,   154,   155,  -118,   105,
    -118,  -118,  -118,   161,   162,  -118,  -118,  -118,  -118,  -118,
      24,   108,  -118,  -118,  -118,  -118,   197,   197,   197,   197,
     197,   169,  -118,   110,  -118,  -118,   130,  -118,  -118,  -118,
    -118,    72,   143,    43,   143,  -118,  -118,  -118,   146,   178,
     169,  -118,  -118,  -118,   197,    71,   197,  -118,  -118,   143,
     186,   192,  -118,  -118,    71,    71,  -118,  -118
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    55,    56,    57,   100,     0,     0,    97,    99,    60,
       0,    67,    50,     0,    51,    53,    59,     0,     1,    98,
       0,    49,     0,     0,   102,     0,   105,    66,     0,    66,
      68,    58,    65,    52,    53,     4,     5,     6,     7,     0,
      19,    20,    21,    22,    23,     9,    17,    24,     0,    28,
      31,    36,    39,    41,    43,    45,    77,    54,   103,     0,
      62,    20,     0,    73,    47,     0,     0,    14,     0,     0,
      18,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    85,   101,    63,    61,    69,    72,
       0,    70,     8,     0,     0,     0,    13,    15,    12,    46,
      25,    26,    27,    24,    29,    30,    32,    33,    34,    35,
      37,    38,     2,     2,     2,     0,     0,     0,    91,     0,
      88,    89,    78,     0,     2,    86,    79,    80,    81,    82,
      75,     0,    64,    48,    10,    11,     0,     0,     0,     0,
       0,     0,    96,     0,    90,    83,     0,    74,    76,    71,
      16,    40,     3,    42,     3,     2,    95,    87,     0,     0,
       0,     2,     2,     2,     0,     0,     0,    44,     3,     3,
      92,     0,     2,     2,     0,     0,    93,    94
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -118,  -101,   -50,  -118,  -118,  -118,  -118,   -40,  -118,    81,
      49,    83,    74,    73,  -118,    50,   -14,   -37,   -15,  -118,
     193,     1,    58,   199,   188,   134,  -118,  -118,  -118,    92,
    -118,  -117,   166,  -118,  -118,    80,   -94,  -118,  -118,  -118,
    -118,   221,  -118,  -118,  -118
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,   137,    82,    45,    46,    95,    96,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    64,   119,     4,    13,
      14,    25,    34,    16,    59,    17,    89,    90,   148,    91,
      57,   121,   122,   123,   124,   125,   126,   127,   128,   129,
       6,     7,     8,    26,    27
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,     5,    65,   134,    83,     9,     9,     5,    70,    56,
      32,    58,   138,   139,    62,     1,     2,     3,    10,    10,
      28,    92,    29,   146,    11,    11,  -104,   147,    93,    94,
       9,   100,   101,   102,   103,   103,   103,   103,   103,   103,
     103,   103,    12,    10,    93,    23,    30,   155,   168,    30,
      66,    -3,    67,    97,   160,    99,    68,   176,   177,    -3,
     164,   165,   166,    15,    88,   113,   163,    23,    20,   120,
      69,   174,   175,   114,    35,    36,    37,    38,    -3,   133,
     143,   115,    71,   116,   117,    72,    73,    39,    84,    84,
      21,    22,    40,    41,    42,    43,    98,   103,    44,   103,
      18,   152,   158,   154,   159,    80,    81,     1,     2,     3,
     118,    76,    77,    78,    79,     1,     2,     3,   170,   171,
      74,    75,   150,   112,   103,   106,   107,   108,   109,   169,
      86,   120,    88,    35,    36,    37,    38,     1,     2,     3,
     115,    87,   116,   117,   144,    93,    39,    11,    84,   156,
      93,    40,    41,    42,    43,   104,   105,    44,    35,    36,
      37,    38,   131,   110,   111,   132,   135,   136,   140,   118,
     141,    39,    35,    36,    37,    38,    40,    41,    42,    43,
     145,   -84,    44,    93,   161,    39,    35,    36,    37,    38,
      40,    41,    42,    43,   142,   162,    44,   172,    60,    39,
      35,    36,    37,    38,    40,    61,    42,    43,   118,   173,
      44,   151,   153,    39,   167,    33,    31,    63,    40,    41,
      42,    43,   130,   149,    44,    85,   157,    19
};

static const yytype_uint8 yycheck[] =
{
      15,     0,    39,    15,    54,     3,     3,     6,    48,    23,
      17,    26,   113,   114,    28,     7,     8,     9,    16,    16,
      14,    17,    16,   124,    22,    22,    18,     3,    40,    66,
       3,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    39,    16,    40,    37,    22,   141,   165,    22,
      14,    28,    16,    67,   155,    69,    20,   174,   175,    36,
     161,   162,   163,     5,    63,    28,   160,    37,    10,    84,
      37,   172,   173,    36,     3,     4,     5,     6,    35,    93,
     117,    10,    22,    12,    13,    25,    26,    16,    18,    18,
      39,    40,    21,    22,    23,    24,     3,   137,    27,   139,
       0,   138,   152,   140,   154,    33,    34,     7,     8,     9,
      39,    29,    30,    31,    32,     7,     8,     9,   168,   169,
      23,    24,   136,    35,   164,    76,    77,    78,    79,   166,
      15,   146,   131,     3,     4,     5,     6,     7,     8,     9,
      10,    15,    12,    13,    39,    40,    16,    22,    18,    39,
      40,    21,    22,    23,    24,    74,    75,    27,     3,     4,
       5,     6,    40,    80,    81,    17,    17,    40,    16,    39,
      16,    16,     3,     4,     5,     6,    21,    22,    23,    24,
      19,    19,    27,    40,    38,    16,     3,     4,     5,     6,
      21,    22,    23,    24,    39,    17,    27,    11,    15,    16,
       3,     4,     5,     6,    21,    22,    23,    24,    39,    17,
      27,   137,   139,    16,   164,    22,    17,    29,    21,    22,
      23,    24,    88,   131,    27,    59,   146,     6
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,     9,    60,    63,    82,    83,    84,     3,
      16,    22,    39,    61,    62,    64,    65,    67,     0,    83,
      64,    39,    40,    37,    60,    63,    85,    86,    14,    16,
      22,    65,    17,    62,    64,     3,     4,     5,     6,    16,
      21,    22,    23,    24,    27,    45,    46,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    72,    60,    66,
      15,    22,    58,    66,    58,    59,    14,    16,    20,    37,
      49,    22,    25,    26,    23,    24,    29,    30,    31,    32,
      33,    34,    44,    44,    18,    74,    15,    15,    63,    68,
      69,    71,    17,    40,    59,    47,    48,    58,     3,    58,
      49,    49,    49,    49,    51,    51,    52,    52,    52,    52,
      53,    53,    35,    28,    36,    10,    12,    13,    39,    59,
      60,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      67,    40,    17,    58,    15,    17,    40,    43,    43,    43,
      16,    16,    39,    59,    39,    19,    43,     3,    70,    71,
      58,    54,    59,    55,    59,    78,    39,    77,    44,    44,
      43,    38,    17,    78,    43,    43,    43,    57,    73,    59,
      44,    44,    11,    17,    43,    43,    73,    73
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    45,    45,    45,    45,    45,    46,
      46,    46,    46,    47,    47,    48,    48,    49,    49,    50,
      50,    50,    50,    50,    51,    51,    51,    51,    52,    52,
      52,    53,    53,    53,    53,    53,    54,    54,    54,    55,
      55,    56,    56,    57,    57,    58,    58,    59,    59,    60,
      60,    61,    61,    62,    62,    63,    63,    63,    64,    64,
      65,    65,    65,    65,    65,    65,    66,    67,    67,    67,
      68,    68,    69,    69,    70,    70,    71,    72,    73,    73,
      73,    73,    73,    74,    75,    75,    76,    76,    77,    77,
      78,    78,    79,    79,    80,    81,    81,    82,    82,    83,
      83,    84,    85,    85,    86,    86
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     1,     1,     1,     1,     3,     1,
       4,     4,     3,     1,     0,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       5,     1,     5,     1,     9,     1,     3,     1,     3,     3,
       2,     1,     3,     1,     3,     1,     1,     1,     2,     1,
       1,     4,     3,     4,     5,     3,     0,     1,     2,     0,
       1,     3,     1,     0,     1,     0,     3,     1,     1,     1,
       1,     1,     1,     3,     1,     0,     1,     3,     1,     1,
       2,     1,     8,    11,    11,     3,     2,     1,     2,     1,
       1,     5,     1,     2,     0,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* M: %empty  */
#line 93 "1_A4.y"
        { 
		(yyval.instrNum) = nextInstr(); 
	}
#line 1576 "1_A4.tab.c"
    break;

  case 3: /* N: %empty  */
#line 98 "1_A4.y"
          { 
        (yyval.S) = new Statement();
        (yyval.S) -> nextList = makelist(nextInstr());
        emit("goto", "");
         
}
#line 1587 "1_A4.tab.c"
    break;

  case 4: /* primary_expression: IDENTIFIER  */
#line 108 "1_A4.y"
                        {
							(yyval.E) = new Expression();
							updateNextInstr();
							(yyval.E) -> loc = (yyvsp[0].symPtr);
							updateNextInstr();
							(yyval.E)->type = "not-boolean";
							updateNextInstr();
                        }
#line 1600 "1_A4.tab.c"
    break;

  case 5: /* primary_expression: INTEGER_CONSTANT  */
#line 117 "1_A4.y"
                                                {
							(yyval.E)=new Expression();	
							updateNextInstr();
							string p=convertToString((yyvsp[0].intval));
							updateNextInstr();
							(yyval.E)->loc=gentemp(new symbolType("int"),p);
							updateNextInstr();
							emit("=",(yyval.E)->loc->name,p);
							updateNextInstr();
						}
#line 1615 "1_A4.tab.c"
    break;

  case 6: /* primary_expression: CHARACTER_CONSTANT  */
#line 128 "1_A4.y"
                                                {
							(yyval.E)=new Expression();
							updateNextInstr();
							(yyval.E)->loc=gentemp(new symbolType("char"),(yyvsp[0].char_value));
							updateNextInstr();
							emit("=",(yyval.E)->loc->name,string((yyvsp[0].char_value)));
							updateNextInstr();
						}
#line 1628 "1_A4.tab.c"
    break;

  case 7: /* primary_expression: STRING_LITERAL  */
#line 137 "1_A4.y"
                    {
                        (yyval.E)=new Expression();
                        updateNextInstr();
                        (yyval.E)->loc=gentemp(new symbolType("ptr"),(yyvsp[0].char_value));
                        updateNextInstr();
                        (yyval.E)->loc->type->arrtype=new symbolType("char");
                        updateNextInstr();
                        
                    }
#line 1642 "1_A4.tab.c"
    break;

  case 8: /* primary_expression: L_ROUND_BRACKET expression R_ROUND_BRACKET  */
#line 147 "1_A4.y"
                        {
                                (yyval.E) = (yyvsp[-1].E);
                        }
#line 1650 "1_A4.tab.c"
    break;

  case 9: /* postfix_expression: primary_expression  */
#line 153 "1_A4.y"
                        {
                                (yyval.A)=new Array();
                                updateNextInstr();
                                (yyval.A)->Array=(yyvsp[0].E)->loc;	
                                updateNextInstr();
                                (yyval.A)->type=(yyvsp[0].E)->loc->type;	
                                updateNextInstr();
                                (yyval.A)->loc=(yyval.A)->Array;
                                updateNextInstr();
                        }
#line 1665 "1_A4.tab.c"
    break;

  case 10: /* postfix_expression: postfix_expression L_SQUARE_BRACKET expression R_SQUARE_BRACKET  */
#line 165 "1_A4.y"
                { 	
                                	 
						(yyval.A)=new Array();
						updateNextInstr();
						(yyval.A)->type=(yyvsp[-3].A)->type->arrtype;				// type=type of element	
						updateNextInstr();			
						(yyval.A)->Array=(yyvsp[-3].A)->Array;						// copy the base
						updateNextInstr();
						(yyval.A)->loc=gentemp(new symbolType("int"));		// store computed address
						updateNextInstr();
						(yyval.A)->aType="arr";						//aType is arr.
						updateNextInstr();
						if((yyvsp[-3].A)->aType=="arr") 
						{			
							
							sym* t=gentemp(new symbolType("int"));
							updateNextInstr();
							int p=sizeOfType((yyval.A)->type);
							updateNextInstr();
							string str=convertToString(p);
							updateNextInstr();
							emit("*",t->name,(yyvsp[-1].E)->loc->name,str);
							updateNextInstr();	
							
							emit("+",(yyval.A)->loc->name,(yyvsp[-3].A)->loc->name,t->name);
							updateNextInstr();
							
						}
						else 
						{                        //if a 1D Array, simply calculate size
							int p=sizeOfType((yyval.A)->type);
							updateNextInstr();
							string str=convertToString(p);
							updateNextInstr();
							emit("*",(yyval.A)->loc->name,(yyvsp[-1].E)->loc->name,str);
							updateNextInstr();
							
						}
	        }
#line 1709 "1_A4.tab.c"
    break;

  case 11: /* postfix_expression: postfix_expression L_ROUND_BRACKET argument_expression_list_opt R_ROUND_BRACKET  */
#line 205 "1_A4.y"
                    {
                        (yyval.A)=new Array();	
                        updateNextInstr();
                        (yyval.A)->Array=gentemp((yyvsp[-3].A)->type);
                        updateNextInstr();
                        string str=convertToString((yyvsp[-1].paramCount));
                        updateNextInstr();
                        emit("call",(yyval.A)->Array->name,(yyvsp[-3].A)->Array->name,str);
                        updateNextInstr();
                    }
#line 1724 "1_A4.tab.c"
    break;

  case 12: /* postfix_expression: postfix_expression ARROW IDENTIFIER  */
#line 215 "1_A4.y"
                                                          {  }
#line 1730 "1_A4.tab.c"
    break;

  case 13: /* argument_expression_list_opt: argument_expression_list  */
#line 218 "1_A4.y"
                                                        { (yyval.paramCount)=(yyvsp[0].paramCount); }
#line 1736 "1_A4.tab.c"
    break;

  case 14: /* argument_expression_list_opt: %empty  */
#line 219 "1_A4.y"
                                    { (yyval.paramCount)=0; }
#line 1742 "1_A4.tab.c"
    break;

  case 15: /* argument_expression_list: assignment_expression  */
#line 223 "1_A4.y"
                        {
                                (yyval.paramCount) = 1;
                                updateNextInstr();
                                emit("param",(yyvsp[0].E)->loc->name);	
                                updateNextInstr();
                        }
#line 1753 "1_A4.tab.c"
    break;

  case 16: /* argument_expression_list: argument_expression_list COMMA assignment_expression  */
#line 230 "1_A4.y"
                        {
                                (yyval.paramCount) = (yyvsp[-2].paramCount)+1;
                                updateNextInstr();
                                emit("param",(yyvsp[0].E)->loc->name);	
                                updateNextInstr();
                        }
#line 1764 "1_A4.tab.c"
    break;

  case 17: /* unary_expression: postfix_expression  */
#line 238 "1_A4.y"
                                     { (yyval.A)=(yyvsp[0].A); }
#line 1770 "1_A4.tab.c"
    break;

  case 18: /* unary_expression: unary_operator unary_expression  */
#line 240 "1_A4.y"
                {			

                        (yyval.A)=new Array();
                        updateNextInstr();
                        switch((yyvsp[-1].unaryOp))
                                {	  
                                        case '+':  
                                                (yyval.A)=(yyvsp[0].A);
                                                break;          
                                        case '-':				
                                                (yyval.A)->Array=gentemp(new symbolType((yyvsp[0].A)->Array->type->type));
                                                updateNextInstr();
                                                emit("uminus",(yyval.A)->Array->name,(yyvsp[0].A)->Array->name);
                                                updateNextInstr();
                                                break; 

                                        case '!':			
                                                (yyval.A)->Array=gentemp(new symbolType((yyvsp[0].A)->Array->type->type));
                                                updateNextInstr();
                                                emit("!",(yyval.A)->Array->name,(yyvsp[0].A)->Array->name);
                                                updateNextInstr();
                                                break;

										case '&':                                       //address of something, then generate a pointer temporary and emit the quad
												
												(yyval.A)->Array=gentemp((new symbolType("ptr")));
												updateNextInstr();
												(yyval.A)->Array->type->arrtype=(yyvsp[0].A)->Array->type; 
												updateNextInstr();
												emit("=&",(yyval.A)->Array->name,(yyvsp[0].A)->Array->name);
												updateNextInstr();
												break;
												
										case '*':                          //value of something, then generate a temporary of the corresponding type and emit the quad	
											(yyval.A)->aType="ptr";
											updateNextInstr();
											(yyval.A)->loc=gentemp((yyvsp[0].A)->Array->type->arrtype);
											updateNextInstr();
											(yyval.A)->Array=(yyvsp[0].A)->Array;
											updateNextInstr();
											emit("=*",(yyval.A)->loc->name,(yyvsp[0].A)->Array->name);
											updateNextInstr();
											
											break;
						
                                }
                }
#line 1822 "1_A4.tab.c"
    break;

  case 19: /* unary_operator: AMPERSAND  */
#line 290 "1_A4.y"
                {
                        (yyval.unaryOp) = '&';
						updateNextInstr();
                }
#line 1831 "1_A4.tab.c"
    break;

  case 20: /* unary_operator: ASTERISK  */
#line 295 "1_A4.y"
                {
                        (yyval.unaryOp) = '*';
						updateNextInstr();
                }
#line 1840 "1_A4.tab.c"
    break;

  case 21: /* unary_operator: PLUS  */
#line 300 "1_A4.y"
                {
                        (yyval.unaryOp) = '+';
						updateNextInstr();
                }
#line 1849 "1_A4.tab.c"
    break;

  case 22: /* unary_operator: MINUS  */
#line 305 "1_A4.y"
                {
                        (yyval.unaryOp) = '-';
						updateNextInstr();
                }
#line 1858 "1_A4.tab.c"
    break;

  case 23: /* unary_operator: NOT  */
#line 310 "1_A4.y"
                {
                        (yyval.unaryOp) = '!';
						updateNextInstr();
                }
#line 1867 "1_A4.tab.c"
    break;

  case 24: /* multiplicative_expression: unary_expression  */
#line 317 "1_A4.y"
                           {
		 
								(yyval.E) = new Expression();             
								updateNextInstr();						    
								if((yyvsp[0].A)->aType=="arr") 			  
								{
									(yyval.E)->loc = gentemp((yyvsp[0].A)->loc->type);	
									updateNextInstr();
									emit("=[]", (yyval.E)->loc->name, (yyvsp[0].A)->Array->name, (yyvsp[0].A)->loc->name);     //emit with Array right
									updateNextInstr();
									
								}
								else if((yyvsp[0].A)->aType=="ptr")         //if it is of type ptr
								{ 
									(yyval.E)->loc = (yyvsp[0].A)->loc;        //equate the locs
									updateNextInstr();
									
								}
								else
								{
									(yyval.E)->loc = (yyvsp[0].A)->Array;
									updateNextInstr();
									
								}
							}
#line 1897 "1_A4.tab.c"
    break;

  case 25: /* multiplicative_expression: multiplicative_expression ASTERISK unary_expression  */
#line 344 "1_A4.y"
                                { 
			
									if(!compareSymbolType((yyvsp[-2].E)->loc, (yyvsp[0].A)->Array))         
										cout<<"Type Error"<< endl;	
									else 								 
									{
										(yyval.E) = new Expression();	
										updateNextInstr();
										(yyval.E)->loc = gentemp(new symbolType((yyvsp[-2].E)->loc->type->type));
										updateNextInstr();
										emit("*", (yyval.E)->loc->name, (yyvsp[-2].E)->loc->name, (yyvsp[0].A)->Array->name);
										updateNextInstr();
										
									}
								}
#line 1917 "1_A4.tab.c"
    break;

  case 26: /* multiplicative_expression: multiplicative_expression DIVIDE unary_expression  */
#line 360 "1_A4.y"
                                {
									
									if(!compareSymbolType((yyvsp[-2].E)->loc, (yyvsp[0].A)->Array))
										cout << "Type Error"<< endl;
									else    
									{
										(yyval.E) = new Expression();
										updateNextInstr();
										(yyval.E)->loc = gentemp(new symbolType((yyvsp[-2].E)->loc->type->type));
										updateNextInstr();
										emit("/", (yyval.E)->loc->name, (yyvsp[-2].E)->loc->name, (yyvsp[0].A)->Array->name);
										updateNextInstr();	
																
									}
								}
#line 1937 "1_A4.tab.c"
    break;

  case 27: /* multiplicative_expression: multiplicative_expression MODULO unary_expression  */
#line 376 "1_A4.y"
                                {
		 
									if(!compareSymbolType((yyvsp[-2].E)->loc, (yyvsp[0].A)->Array))
										cout << "Type Error"<< endl;		
									else 		
									{
										(yyval.E) = new Expression();
										updateNextInstr();
										(yyval.E)->loc = gentemp(new symbolType((yyvsp[-2].E)->loc->type->type));
										updateNextInstr();
										emit("%", (yyval.E)->loc->name, (yyvsp[-2].E)->loc->name, (yyvsp[0].A)->Array->name);	
										updateNextInstr();	
											
									}
								}
#line 1957 "1_A4.tab.c"
    break;

  case 28: /* additive_expression: multiplicative_expression  */
#line 394 "1_A4.y"
                        {
                                (yyval.E) = (yyvsp[0].E);
                        }
#line 1965 "1_A4.tab.c"
    break;

  case 29: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 398 "1_A4.y"
                        {
		 
							if(!compareSymbolType((yyvsp[-2].E)->loc, (yyvsp[0].E)->loc))
								cout << "Type Error"<< endl;
							else    
							{
								(yyval.E) = new Expression();	
								updateNextInstr();
								(yyval.E)->loc = gentemp(new symbolType((yyvsp[-2].E)->loc->type->type));
								updateNextInstr();
								emit("+", (yyval.E)->loc->name, (yyvsp[-2].E)->loc->name, (yyvsp[0].E)->loc->name);
								updateNextInstr();
								
							}
						}
#line 1985 "1_A4.tab.c"
    break;

  case 30: /* additive_expression: additive_expression MINUS multiplicative_expression  */
#line 414 "1_A4.y"
                        {
		 
							if(!compareSymbolType((yyvsp[-2].E)->loc, (yyvsp[0].E)->loc))
								cout << "Type Error"<< endl;		
							else       
							{	
								(yyval.E) = new Expression();	
								updateNextInstr();
								(yyval.E)->loc = gentemp(new symbolType((yyvsp[-2].E)->loc->type->type));
								updateNextInstr();
								emit("-", (yyval.E)->loc->name, (yyvsp[-2].E)->loc->name, (yyvsp[0].E)->loc->name);
								updateNextInstr();
								
							}
						}
#line 2005 "1_A4.tab.c"
    break;

  case 31: /* relational_expression: additive_expression  */
#line 432 "1_A4.y"
                        {
                                (yyval.E) = (yyvsp[0].E);
                        }
#line 2013 "1_A4.tab.c"
    break;

  case 32: /* relational_expression: relational_expression LESS_THAN additive_expression  */
#line 436 "1_A4.y"
                                {
								if(!compareSymbolType((yyvsp[-2].E)->loc, (yyvsp[0].E)->loc)) 
								{
									
									cout << "Type Error in Program"<< endl;
								}
								else 
								{      //check compatible types		
																
									(yyval.E) = new Expression();
									updateNextInstr();
									(yyval.E)->type = "bool";                         //new type is boolean
									updateNextInstr();		
									(yyval.E)->trueList = makelist(nextInstr());     //makelist for trueList and falseList
									updateNextInstr();
									(yyval.E)->falseList = makelist(nextInstr()+1);
									updateNextInstr();
									emit("<", "", (yyvsp[-2].E)->loc->name, (yyvsp[0].E)->loc->name);     //emit statement if a<b goto .. 
									updateNextInstr();
									
									emit("goto", "");	//emit statement goto ..
									updateNextInstr();
									
								}
							}
#line 2043 "1_A4.tab.c"
    break;

  case 33: /* relational_expression: relational_expression GREATER_THAN additive_expression  */
#line 462 "1_A4.y"
                                {
								if(!compareSymbolType((yyvsp[-2].E)->loc, (yyvsp[0].E)->loc)) 
								{
									
									cout << "Type Error"<< endl;
								}
								else 
								{
									
									(yyval.E) = new Expression();	
									updateNextInstr();
									(yyval.E)->type = "bool";
									updateNextInstr();
									(yyval.E)->trueList = makelist(nextInstr());
									updateNextInstr();
									(yyval.E)->falseList = makelist(nextInstr()+1);
									updateNextInstr();
									emit(">", "", (yyvsp[-2].E)->loc->name, (yyvsp[0].E)->loc->name);
									updateNextInstr();
									
									emit("goto", "");
									updateNextInstr();
									
								}	
							}
#line 2073 "1_A4.tab.c"
    break;

  case 34: /* relational_expression: relational_expression LESS_THAN_EQUAL_TO additive_expression  */
#line 488 "1_A4.y"
                                {
								if(!compareSymbolType((yyvsp[-2].E)->loc, (yyvsp[0].E)->loc)) 
								{
									
									cout << "Type Error"<< endl;
								}
								else 
								{		
									
									(yyval.E) = new Expression();		
									updateNextInstr();
									(yyval.E)->type = "bool";
									updateNextInstr();
									(yyval.E)->trueList = makelist(nextInstr());
									updateNextInstr();
									(yyval.E)->falseList = makelist(nextInstr()+1);
									updateNextInstr();
									emit("<=", "", (yyvsp[-2].E)->loc->name, (yyvsp[0].E)->loc->name);
									updateNextInstr();
									
									emit("goto", "");
									updateNextInstr();
									
								}		
							}
#line 2103 "1_A4.tab.c"
    break;

  case 35: /* relational_expression: relational_expression GREATER_THAN_EQUAL_TO additive_expression  */
#line 514 "1_A4.y"
                                                        {
								if(!compareSymbolType((yyvsp[-2].E)->loc, (yyvsp[0].E)->loc))
								{
									
									cout << "Type Error"<< endl;
								}
								else 
								{
									
									(yyval.E) = new Expression();
									updateNextInstr();
									(yyval.E)->type = "bool";
									updateNextInstr();
									(yyval.E)->trueList = makelist(nextInstr());
									updateNextInstr();
									(yyval.E)->falseList = makelist(nextInstr()+1);
									updateNextInstr();
									emit(">=", "", (yyvsp[-2].E)->loc->name, (yyvsp[0].E)->loc->name);
									updateNextInstr();
									
									emit("goto", "");
									updateNextInstr();
									
								}
							}
#line 2133 "1_A4.tab.c"
    break;

  case 36: /* equality_expression: relational_expression  */
#line 542 "1_A4.y"
                        {
                                (yyval.E) = (yyvsp[0].E);
                        }
#line 2141 "1_A4.tab.c"
    break;

  case 37: /* equality_expression: equality_expression EQUAL_TO relational_expression  */
#line 546 "1_A4.y"
                    {
						if(!compareSymbolType((yyvsp[-2].E)->loc, (yyvsp[0].E)->loc))                //check compatible types
						{
							
							cout << "Type Error"<< endl;
						}
						else 
						{
							
							convertBool2Int((yyvsp[-2].E));                  //convert bool to INTEGER
							updateNextInstr();	
							convertBool2Int((yyvsp[0].E));
							updateNextInstr();
							(yyval.E) = new Expression();
							updateNextInstr();
							(yyval.E)->type = "bool";
							updateNextInstr();
							(yyval.E)->trueList = makelist(nextInstr());            //make lists for new expression
							updateNextInstr();
							(yyval.E)->falseList = makelist(nextInstr()+1); 
							updateNextInstr();
							emit("==", "", (yyvsp[-2].E)->loc->name, (yyvsp[0].E)->loc->name);      //emit if a==b goto ..
							updateNextInstr();
							emit("goto", "");				//emit goto ..
							updateNextInstr();
							
						}
						
					}
#line 2175 "1_A4.tab.c"
    break;

  case 38: /* equality_expression: equality_expression NOT_EQUAL_TO relational_expression  */
#line 576 "1_A4.y"
                    {
						if(!compareSymbolType((yyvsp[-2].E)->loc, (yyvsp[0].E)->loc)) 
						{
							
							cout << "Type Error in Program"<< endl;
						}
						else 
						{			
							
							convertBool2Int((yyvsp[-2].E));	
							updateNextInstr();
							convertBool2Int((yyvsp[0].E));
							updateNextInstr();
							(yyval.E) = new Expression();                 //result is boolean
							updateNextInstr();
							(yyval.E)->type = "bool";
							updateNextInstr();
							(yyval.E)->trueList = makelist(nextInstr());
							updateNextInstr();
							(yyval.E)->falseList = makelist(nextInstr()+1);
							updateNextInstr();
							emit("!=", "", (yyvsp[-2].E)->loc->name, (yyvsp[0].E)->loc->name);
							updateNextInstr();
							
							emit("goto", "");
							updateNextInstr();
							
						}
					}
#line 2209 "1_A4.tab.c"
    break;

  case 39: /* logical_AND_expression: equality_expression  */
#line 607 "1_A4.y"
                                             { (yyval.E)=(yyvsp[0].E); }
#line 2215 "1_A4.tab.c"
    break;

  case 40: /* logical_AND_expression: logical_AND_expression N LOGICAL_AND M equality_expression  */
#line 609 "1_A4.y"
                        { 
		 
							convertInt2Bool((yyvsp[0].E));         //convert inclusive_or_expression INTEGER to bool
							updateNextInstr();
							backpatch((yyvsp[-3].S)->nextList, nextInstr());        //$2->nextList goes to next instruction
							updateNextInstr();
							convertInt2Bool((yyvsp[-4].E));                  //convert logical_and_expression to bool
							updateNextInstr();
							(yyval.E) = new Expression();     //make new boolean expression 
							updateNextInstr();
							(yyval.E)->type = "bool";
							updateNextInstr();
							backpatch((yyvsp[-4].E)->trueList, (yyvsp[-1].instrNum));        //if $1 is true, we move to $5
							updateNextInstr();
							(yyval.E)->trueList = (yyvsp[0].E)->trueList;        //if $5 is also true, we get trueList for $$
							updateNextInstr();
							(yyval.E)->falseList = merge((yyvsp[-4].E)->falseList, (yyvsp[0].E)->falseList);    //merge their falselists
							updateNextInstr();
							
						}
#line 2240 "1_A4.tab.c"
    break;

  case 41: /* logical_OR_expression: logical_AND_expression  */
#line 632 "1_A4.y"
                        {
                                (yyval.E) = (yyvsp[0].E);
                        }
#line 2248 "1_A4.tab.c"
    break;

  case 42: /* logical_OR_expression: logical_OR_expression N LOGICAL_OR M logical_AND_expression  */
#line 636 "1_A4.y"
                        { 
							
							convertInt2Bool((yyvsp[0].E));			 //convert logical_and_expression INTEGER to bool
							updateNextInstr();
							backpatch((yyvsp[-3].S)->nextList, nextInstr());	//$2->nextList goes to next instruction
							updateNextInstr();
							convertInt2Bool((yyvsp[-4].E));			//convert logical_or_expression to bool
							updateNextInstr();
							(yyval.E) = new Expression();			//make new boolean expression
							updateNextInstr();
							(yyval.E)->type = "bool";
							updateNextInstr();
							backpatch((yyvsp[-4].E)->falseList, (yyvsp[-1].instrNum));		//if $1 is true, we move to $5
							updateNextInstr();
							(yyval.E)->trueList = merge((yyvsp[-4].E)->trueList, (yyvsp[0].E)->trueList);		//merge their truelists
							updateNextInstr();
							(yyval.E)->falseList = (yyvsp[0].E)->falseList;		 	//if $5 is also false, we get falseList for $$
							updateNextInstr();
							
						}
#line 2273 "1_A4.tab.c"
    break;

  case 43: /* conditional_expression: logical_OR_expression  */
#line 659 "1_A4.y"
                        {
                                (yyval.E) = (yyvsp[0].E);
                        }
#line 2281 "1_A4.tab.c"
    break;

  case 44: /* conditional_expression: logical_OR_expression N QUESTION M expression N COLON M conditional_expression  */
#line 663 "1_A4.y"
                        {
							
							//normal conversion method to get conditional expressions
							(yyval.E)->loc = gentemp((yyvsp[-4].E)->loc->type);       //generate temporary for expression
							updateNextInstr();
							(yyval.E)->loc->update((yyvsp[-4].E)->loc->type);
							updateNextInstr();
							emit("=", (yyval.E)->loc->name, (yyvsp[0].E)->loc->name);      //make it equal to sconditional_expression
							updateNextInstr();
							
							list<int> l = makelist(nextInstr());        //makelist next instruction
							emit("goto", "");              //prevent fallthrough
							updateNextInstr();
							
							backpatch((yyvsp[-3].S)->nextList, nextInstr());        //after N, go to next instruction
							updateNextInstr();
							emit("=", (yyval.E)->loc->name, (yyvsp[-4].E)->loc->name);
							updateNextInstr();
							
							list<int> m = makelist(nextInstr());         //makelist next instruction
							updateNextInstr();
							l = merge(l, m);						//merge the two lists
							updateNextInstr();
							emit("goto", "");						//prevent fallthrough
							updateNextInstr();
							
							backpatch((yyvsp[-7].S)->nextList, nextInstr());   //backpatching
							updateNextInstr();
							convertInt2Bool((yyvsp[-8].E));                   //convert expression to boolean
							updateNextInstr();
							backpatch((yyvsp[-8].E)->trueList, (yyvsp[-5].instrNum));           //$1 true goes to expression
							updateNextInstr();
							backpatch((yyvsp[-8].E)->falseList, (yyvsp[-1].instrNum));          //$1 false goes to conditional_expression
							updateNextInstr();
							backpatch(l, nextInstr());
							updateNextInstr();
							
						}
#line 2324 "1_A4.tab.c"
    break;

  case 45: /* assignment_expression: conditional_expression  */
#line 704 "1_A4.y"
                        {
                                (yyval.E) = (yyvsp[0].E);
                        }
#line 2332 "1_A4.tab.c"
    break;

  case 46: /* assignment_expression: unary_expression ASSIGN assignment_expression  */
#line 708 "1_A4.y"
                                {
								if((yyvsp[-2].A)->aType=="arr")       //if type is arr, simply check if we need to convert and emit
								{
									
									(yyvsp[0].E)->loc = convertType((yyvsp[0].E)->loc, (yyvsp[-2].A)->aType);
									updateNextInstr();
									emit("[]=", (yyvsp[-2].A)->Array->name, (yyvsp[-2].A)->loc->name, (yyvsp[0].E)->loc->name);		
									updateNextInstr();
									
								}
								else if((yyvsp[-2].A)->aType=="ptr")     
								{
									
									emit("*=", (yyvsp[-2].A)->Array->name, (yyvsp[0].E)->loc->name);		
									updateNextInstr();
									
								}
								else                              //otherwise assignment
								{
									
									(yyvsp[0].E)->loc = convertType((yyvsp[0].E)->loc, (yyvsp[-2].A)->Array->type->type);
									emit("=", (yyvsp[-2].A)->Array->name, (yyvsp[0].E)->loc->name);
									updateNextInstr();
									
								}
								
								(yyval.E) = (yyvsp[0].E);
								
								
							}
#line 2367 "1_A4.tab.c"
    break;

  case 47: /* expression: assignment_expression  */
#line 741 "1_A4.y"
                {
                        (yyval.E) = (yyvsp[0].E);
                }
#line 2375 "1_A4.tab.c"
    break;

  case 48: /* expression: expression COMMA assignment_expression  */
#line 744 "1_A4.y"
                                                                         {   }
#line 2381 "1_A4.tab.c"
    break;

  case 49: /* declaration: type_specifier init_declarator_list SEMICOLON  */
#line 749 "1_A4.y"
                                                                { }
#line 2387 "1_A4.tab.c"
    break;

  case 50: /* declaration: type_specifier SEMICOLON  */
#line 750 "1_A4.y"
                                                     {       }
#line 2393 "1_A4.tab.c"
    break;

  case 51: /* init_declarator_list: init_declarator  */
#line 752 "1_A4.y"
                                        {   }
#line 2399 "1_A4.tab.c"
    break;

  case 52: /* init_declarator_list: init_declarator_list COMMA init_declarator  */
#line 753 "1_A4.y"
                                                                             {   }
#line 2405 "1_A4.tab.c"
    break;

  case 53: /* init_declarator: declarator  */
#line 756 "1_A4.y"
                            {(yyval.symPtr)=(yyvsp[0].symPtr);}
#line 2411 "1_A4.tab.c"
    break;

  case 54: /* init_declarator: declarator ASSIGN initializer  */
#line 758 "1_A4.y"
                {
					if((yyvsp[0].symPtr)->val!="") (yyvsp[-2].symPtr)->val=(yyvsp[0].symPtr)->val;        //get the initial value and  emit it
					emit("=", (yyvsp[-2].symPtr)->name, (yyvsp[0].symPtr)->name);
					updateNextInstr();
					
				}
#line 2422 "1_A4.tab.c"
    break;

  case 55: /* type_specifier: VOID  */
#line 766 "1_A4.y"
                        {var_type="void";}
#line 2428 "1_A4.tab.c"
    break;

  case 56: /* type_specifier: CHAR  */
#line 767 "1_A4.y"
                        { var_type="char"; }
#line 2434 "1_A4.tab.c"
    break;

  case 57: /* type_specifier: INT  */
#line 768 "1_A4.y"
                        { var_type="int"; }
#line 2440 "1_A4.tab.c"
    break;

  case 58: /* declarator: pointer direct_declarator  */
#line 772 "1_A4.y"
                        {
				
				symbolType *t = (yyvsp[-1].symType);
				updateNextInstr();
				while(t->arrtype!=NULL) t = t->arrtype;           //for multidimensional arr1s, move in depth till you get the base type
				updateNextInstr();
				t->arrtype = (yyvsp[0].symPtr)->type;                //add the base type 
				updateNextInstr();
				(yyval.symPtr) = (yyvsp[0].symPtr)->update((yyvsp[-1].symType));                  //update
				updateNextInstr();
				
			}
#line 2457 "1_A4.tab.c"
    break;

  case 59: /* declarator: direct_declarator  */
#line 784 "1_A4.y"
                                    { }
#line 2463 "1_A4.tab.c"
    break;

  case 60: /* direct_declarator: IDENTIFIER  */
#line 788 "1_A4.y"
                                        {
						
						(yyval.symPtr) = (yyvsp[0].symPtr)->update(new symbolType(var_type));
						updateNextInstr();
						currentSymbol = (yyval.symPtr);
						updateNextInstr();
						
						
					}
#line 2477 "1_A4.tab.c"
    break;

  case 61: /* direct_declarator: direct_declarator L_SQUARE_BRACKET assignment_expression R_SQUARE_BRACKET  */
#line 798 "1_A4.y"
                                        {
						
						symbolType *t = (yyvsp[-3].symPtr) -> type;
						updateNextInstr();
						symbolType *prev = NULL;
						updateNextInstr();
						while(t->type == "arr") 
						{
							prev = t;	
							t = t->arrtype;      //keep moving recursively to get basetype
							updateNextInstr();
						}
						if(prev==NULL) 
						{
							
							int temp = atoi((yyvsp[-1].E)->loc->val.c_str());      //get initial value
							updateNextInstr();
							symbolType* s = new symbolType("arr", (yyvsp[-3].symPtr)->type, temp);        //create new symbol with that initial value
							updateNextInstr();
							(yyval.symPtr) = (yyvsp[-3].symPtr)->update(s);   //update the symbol table
							updateNextInstr();
							
						}
						else 
						{
							
							prev->arrtype =  new symbolType("arr", t, atoi((yyvsp[-1].E)->loc->val.c_str()));     //similar arguments as above		
							updateNextInstr();
							(yyval.symPtr) = (yyvsp[-3].symPtr)->update((yyvsp[-3].symPtr)->type);
							updateNextInstr();
							
						}
					}
#line 2515 "1_A4.tab.c"
    break;

  case 62: /* direct_declarator: direct_declarator L_SQUARE_BRACKET R_SQUARE_BRACKET  */
#line 832 "1_A4.y"
                                        {
						
						symbolType *t = (yyvsp[-2].symPtr) -> type;
						updateNextInstr();
						symbolType *prev = NULL;
						updateNextInstr();
						while(t->type == "arr") 
						{
							prev = t;	
							t = t->arrtype;         //keep moving recursively to base type
							updateNextInstr();
						}
						if(prev==NULL) 
						{
							
							symbolType* s = new symbolType("arr", (yyvsp[-2].symPtr)->type, 0);    //no initial values, simply keep 0
							updateNextInstr();
							(yyval.symPtr) = (yyvsp[-2].symPtr)->update(s);
							updateNextInstr();
								
						}
						else 
						{
							
							prev->arrtype =  new symbolType("arr", t, 0);
							updateNextInstr();
							(yyval.symPtr) = (yyvsp[-2].symPtr)->update((yyvsp[-2].symPtr)->type);
							updateNextInstr();
							
						}
					}
#line 2551 "1_A4.tab.c"
    break;

  case 63: /* direct_declarator: direct_declarator L_SQUARE_BRACKET ASTERISK R_SQUARE_BRACKET  */
#line 863 "1_A4.y"
                                                                                   {	}
#line 2557 "1_A4.tab.c"
    break;

  case 64: /* direct_declarator: direct_declarator L_ROUND_BRACKET changetable parameter_list_opt R_ROUND_BRACKET  */
#line 865 "1_A4.y"
                                        {
						ST->name = (yyvsp[-4].symPtr)->name;
						updateNextInstr();
						if((yyvsp[-4].symPtr)->type->type !="void") 
						{
							sym *s = ST->lookup("return");         //lookup for return value	
							s->update((yyvsp[-4].symPtr)->type);
							updateNextInstr();
							
						}
						(yyvsp[-4].symPtr)->nested=ST;       
						updateNextInstr();	
						ST->parent = globalST;
						updateNextInstr();
						changeTable(globalST);				// Come back to globalsymbol table
						updateNextInstr();
						currentSymbol = (yyval.symPtr);
						updateNextInstr();
						
					}
#line 2582 "1_A4.tab.c"
    break;

  case 65: /* direct_declarator: L_ROUND_BRACKET declarator R_ROUND_BRACKET  */
#line 885 "1_A4.y"
                                                                                     { (yyval.symPtr) = (yyvsp[-1].symPtr); }
#line 2588 "1_A4.tab.c"
    break;

  case 66: /* changetable: %empty  */
#line 889 "1_A4.y"
                        { 														// Used for changing to symbol table for a function
				if(currentSymbol->nested==NULL) 
				{
					
					changeTable(new symTable(""));	// Function symbol table doesn't already exist
					updateNextInstr();
				}
				else 
				{
					
					changeTable(currentSymbol->nested);						// Function symbol table already exists
					updateNextInstr();
					emit("label", ST->name);
					updateNextInstr();
					
				}
			}
#line 2610 "1_A4.tab.c"
    break;

  case 67: /* pointer: ASTERISK  */
#line 909 "1_A4.y"
        { 
		(yyval.symType) = new symbolType("ptr");
		updateNextInstr();
		  
	}
#line 2620 "1_A4.tab.c"
    break;

  case 68: /* pointer: pointer ASTERISK  */
#line 915 "1_A4.y"
        {
		(yyval.symType) = new symbolType("ptr", (yyvsp[-1].symType));
		updateNextInstr();
	}
#line 2629 "1_A4.tab.c"
    break;

  case 69: /* pointer: %empty  */
#line 919 "1_A4.y"
                        {	}
#line 2635 "1_A4.tab.c"
    break;

  case 70: /* parameter_list: parameter_declaration  */
#line 922 "1_A4.y"
                                                {       }
#line 2641 "1_A4.tab.c"
    break;

  case 71: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 923 "1_A4.y"
                                                             {  }
#line 2647 "1_A4.tab.c"
    break;

  case 72: /* parameter_list_opt: parameter_list  */
#line 927 "1_A4.y"
                                            {	}
#line 2653 "1_A4.tab.c"
    break;

  case 73: /* parameter_list_opt: %empty  */
#line 928 "1_A4.y"
                                           {	}
#line 2659 "1_A4.tab.c"
    break;

  case 74: /* identifier_opt: IDENTIFIER  */
#line 931 "1_A4.y"
                            {	}
#line 2665 "1_A4.tab.c"
    break;

  case 75: /* identifier_opt: %empty  */
#line 932 "1_A4.y"
                           {	}
#line 2671 "1_A4.tab.c"
    break;

  case 76: /* parameter_declaration: type_specifier pointer identifier_opt  */
#line 935 "1_A4.y"
                                                               {	}
#line 2677 "1_A4.tab.c"
    break;

  case 77: /* initializer: assignment_expression  */
#line 938 "1_A4.y"
                                     { (yyval.symPtr)=(yyvsp[0].E)->loc; }
#line 2683 "1_A4.tab.c"
    break;

  case 78: /* statement: compound_statement  */
#line 944 "1_A4.y"
                {
                        (yyval.S) = (yyvsp[0].S);
                }
#line 2691 "1_A4.tab.c"
    break;

  case 79: /* statement: expression_statement  */
#line 948 "1_A4.y"
                                { 
					(yyval.S)=new Statement();              //create new statement with same nextList
					(yyval.S)->nextList=(yyvsp[0].E)->nextList; 
				}
#line 2700 "1_A4.tab.c"
    break;

  case 80: /* statement: selection_statement  */
#line 953 "1_A4.y"
                {
                        (yyval.S) = (yyvsp[0].S);
                }
#line 2708 "1_A4.tab.c"
    break;

  case 81: /* statement: iteration_statement  */
#line 957 "1_A4.y"
                {
                        (yyval.S) = (yyvsp[0].S);
                }
#line 2716 "1_A4.tab.c"
    break;

  case 82: /* statement: jump_statement  */
#line 961 "1_A4.y"
                {
                        (yyval.S) = (yyvsp[0].S);
                }
#line 2724 "1_A4.tab.c"
    break;

  case 83: /* compound_statement: L_CURLY_BRACKET block_item_list_opt R_CURLY_BRACKET  */
#line 967 "1_A4.y"
                {
                        (yyval.S) = (yyvsp[-1].S);
                }
#line 2732 "1_A4.tab.c"
    break;

  case 84: /* block_item_list_opt: block_item_list  */
#line 973 "1_A4.y"
                {
                        (yyval.S) = (yyvsp[0].S);
                }
#line 2740 "1_A4.tab.c"
    break;

  case 85: /* block_item_list_opt: %empty  */
#line 976 "1_A4.y"
                                       { (yyval.S)=new Statement(); }
#line 2746 "1_A4.tab.c"
    break;

  case 86: /* block_item_list: block_item  */
#line 980 "1_A4.y"
                {
                        (yyval.S) = (yyvsp[0].S);
                }
#line 2754 "1_A4.tab.c"
    break;

  case 87: /* block_item_list: block_item_list M block_item  */
#line 984 "1_A4.y"
                                        { 
						(yyval.S)=(yyvsp[0].S);
						backpatch((yyvsp[-2].S)->nextList,(yyvsp[-1].instrNum));     //after $1, move to block_item via $2
					}
#line 2763 "1_A4.tab.c"
    break;

  case 88: /* block_item: declaration  */
#line 990 "1_A4.y"
                         { (yyval.S)=new Statement(); }
#line 2769 "1_A4.tab.c"
    break;

  case 89: /* block_item: statement  */
#line 992 "1_A4.y"
                {
                        (yyval.S) = (yyvsp[0].S);
                }
#line 2777 "1_A4.tab.c"
    break;

  case 90: /* expression_statement: expression SEMICOLON  */
#line 997 "1_A4.y"
                                            { (yyval.E)=(yyvsp[-1].E);}
#line 2783 "1_A4.tab.c"
    break;

  case 91: /* expression_statement: SEMICOLON  */
#line 998 "1_A4.y"
                                                    { (yyval.E)=new Expression(); }
#line 2789 "1_A4.tab.c"
    break;

  case 92: /* selection_statement: IF L_ROUND_BRACKET expression N R_ROUND_BRACKET M statement N  */
#line 1002 "1_A4.y"
                                                {
							backpatch((yyvsp[-4].S)->nextList, nextInstr());        //nextList of N goes to nextInstr
							updateNextInstr();
							convertInt2Bool((yyvsp[-5].E));         //convert expression to bool
							updateNextInstr();
							(yyval.S) = new Statement();        //make new statement
							updateNextInstr();
							backpatch((yyvsp[-5].E)->trueList, (yyvsp[-2].instrNum));        //is expression is true, go to M i.e just before statement body
							updateNextInstr();
							list<int> temp = merge((yyvsp[-5].E)->falseList, (yyvsp[-1].S)->nextList);   //merge falseList of expression, nextList of statement and second N
							updateNextInstr();
							(yyval.S)->nextList = merge((yyvsp[0].S)->nextList, temp);
							updateNextInstr();
						}
#line 2808 "1_A4.tab.c"
    break;

  case 93: /* selection_statement: IF L_ROUND_BRACKET expression N R_ROUND_BRACKET M statement N ELSE M statement  */
#line 1017 "1_A4.y"
                                                {
							backpatch((yyvsp[-7].S)->nextList, nextInstr());		//nextList of N goes to nextInstr
							updateNextInstr();
							convertInt2Bool((yyvsp[-8].E));        //convert expression to bool
							updateNextInstr();
							(yyval.S) = new Statement();       //make new statement
							updateNextInstr();
							backpatch((yyvsp[-8].E)->trueList, (yyvsp[-5].instrNum));    //when expression is true, go to M1 else go to M2
							updateNextInstr();
							backpatch((yyvsp[-8].E)->falseList, (yyvsp[-1].instrNum));
							updateNextInstr();
							list<int> temp = merge((yyvsp[-4].S)->nextList, (yyvsp[-3].S)->nextList);       //merge the nextlists of the statements and second N
							updateNextInstr();
							(yyval.S)->nextList = merge((yyvsp[0].S)->nextList,temp);	
							updateNextInstr();
						}
#line 2829 "1_A4.tab.c"
    break;

  case 94: /* iteration_statement: FOR L_ROUND_BRACKET expression_statement M expression_statement M expression N R_ROUND_BRACKET M statement  */
#line 1036 "1_A4.y"
                                        {
						
						(yyval.S) = new Statement();		 //create new statement
						updateNextInstr();
						convertInt2Bool((yyvsp[-6].E));  //convert check expression to boolean
						updateNextInstr();
						backpatch((yyvsp[-6].E)->trueList, (yyvsp[-1].instrNum));	//if expression is true, go to M2
						updateNextInstr();
						backpatch((yyvsp[-3].S)->nextList, (yyvsp[-7].instrNum));	//after N, go back to M1
						updateNextInstr();
						backpatch((yyvsp[0].S)->nextList, (yyvsp[-5].instrNum));	//statement go back to expression
						updateNextInstr();
						string str=convertToString((yyvsp[-5].instrNum));
						updateNextInstr();
						emit("goto", str);				//prevent fallthrough
						updateNextInstr();
						
						(yyval.S)->nextList = (yyvsp[-6].E)->falseList;	//move out if statement is false	
						updateNextInstr();
							
					}
#line 2855 "1_A4.tab.c"
    break;

  case 95: /* jump_statement: RETURN expression SEMICOLON  */
#line 1060 "1_A4.y"
                                {
					(yyval.S) = new Statement();
					updateNextInstr();
					emit("return",(yyvsp[-1].E)->loc->name);  
					updateNextInstr();
				}
#line 2866 "1_A4.tab.c"
    break;

  case 96: /* jump_statement: RETURN SEMICOLON  */
#line 1067 "1_A4.y"
                                {
					(yyval.S) = new Statement();
					updateNextInstr();
					emit("return", "");
					updateNextInstr();
				}
#line 2877 "1_A4.tab.c"
    break;

  case 97: /* translation_unit: external_declaration  */
#line 1078 "1_A4.y"
                                                        {   }
#line 2883 "1_A4.tab.c"
    break;

  case 98: /* translation_unit: translation_unit external_declaration  */
#line 1079 "1_A4.y"
                                                         {   }
#line 2889 "1_A4.tab.c"
    break;

  case 99: /* external_declaration: function_definition  */
#line 1082 "1_A4.y"
                                                {   }
#line 2895 "1_A4.tab.c"
    break;

  case 100: /* external_declaration: declaration  */
#line 1083 "1_A4.y"
                                          {   }
#line 2901 "1_A4.tab.c"
    break;

  case 101: /* function_definition: type_specifier declarator declaration_list_opt changetable compound_statement  */
#line 1088 "1_A4.y"
                                        {
						
						int nextInstr=0;	 
						updateNextInstr();
						ST->parent=globalST;
						updateNextInstr();
						changeTable(globalST);                    
						updateNextInstr();
						
					}
#line 2916 "1_A4.tab.c"
    break;

  case 102: /* declaration_list: declaration  */
#line 1100 "1_A4.y"
                                {  }
#line 2922 "1_A4.tab.c"
    break;

  case 103: /* declaration_list: declaration_list declaration  */
#line 1101 "1_A4.y"
                                                                {  }
#line 2928 "1_A4.tab.c"
    break;

  case 104: /* declaration_list_opt: %empty  */
#line 1104 "1_A4.y"
                             {  }
#line 2934 "1_A4.tab.c"
    break;

  case 105: /* declaration_list_opt: declaration_list  */
#line 1105 "1_A4.y"
                                                             {  }
#line 2940 "1_A4.tab.c"
    break;


#line 2944 "1_A4.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1108 "1_A4.y"


void yyerror(const char * s) {        //print syntax error
    cout<<s<<endl;
}
