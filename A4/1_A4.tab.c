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

extern int yylex();
void yyerror(const char *s);
extern string var_type;

using namespace std;

#line 85 "1_A4.tab.c"

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
  YYSYMBOL_constant = 45,                  /* constant  */
  YYSYMBOL_primary_expression = 46,        /* primary_expression  */
  YYSYMBOL_argument_expression_list_opt = 47, /* argument_expression_list_opt  */
  YYSYMBOL_postfix_expression = 48,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 49,  /* argument_expression_list  */
  YYSYMBOL_unary_expression = 50,          /* unary_expression  */
  YYSYMBOL_unary_operator = 51,            /* unary_operator  */
  YYSYMBOL_multiplicative_expression = 52, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 53,       /* additive_expression  */
  YYSYMBOL_relational_expression = 54,     /* relational_expression  */
  YYSYMBOL_equality_expression = 55,       /* equality_expression  */
  YYSYMBOL_logical_AND_expression = 56,    /* logical_AND_expression  */
  YYSYMBOL_logical_OR_expression = 57,     /* logical_OR_expression  */
  YYSYMBOL_conditional_expression = 58,    /* conditional_expression  */
  YYSYMBOL_assignment_expression = 59,     /* assignment_expression  */
  YYSYMBOL_expression = 60,                /* expression  */
  YYSYMBOL_declaration = 61,               /* declaration  */
  YYSYMBOL_init_declarator = 62,           /* init_declarator  */
  YYSYMBOL_type_specifier = 63,            /* type_specifier  */
  YYSYMBOL_declarator = 64,                /* declarator  */
  YYSYMBOL_parameter_list_opt = 65,        /* parameter_list_opt  */
  YYSYMBOL_direct_declarator = 66,         /* direct_declarator  */
  YYSYMBOL_pointer = 67,                   /* pointer  */
  YYSYMBOL_parameter_list = 68,            /* parameter_list  */
  YYSYMBOL_identifier_opt = 69,            /* identifier_opt  */
  YYSYMBOL_parameter_declaration = 70,     /* parameter_declaration  */
  YYSYMBOL_initializer = 71,               /* initializer  */
  YYSYMBOL_statement = 72,                 /* statement  */
  YYSYMBOL_block_item_list_opt = 73,       /* block_item_list_opt  */
  YYSYMBOL_compound_statement = 74,        /* compound_statement  */
  YYSYMBOL_block_item_list = 75,           /* block_item_list  */
  YYSYMBOL_block_item = 76,                /* block_item  */
  YYSYMBOL_expression_opt = 77,            /* expression_opt  */
  YYSYMBOL_expression_statement = 78,      /* expression_statement  */
  YYSYMBOL_selection_statement = 79,       /* selection_statement  */
  YYSYMBOL_iteration_statement = 80,       /* iteration_statement  */
  YYSYMBOL_jump_statement = 81,            /* jump_statement  */
  YYSYMBOL_translation_unit = 82,          /* translation_unit  */
  YYSYMBOL_external_declaration = 83,      /* external_declaration  */
  YYSYMBOL_function_definition = 84        /* function_definition  */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   186

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  161

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
       0,    95,    95,    98,   107,   118,   129,   138,   142,   152,
     158,   159,   162,   174,   214,   225,   228,   235,   244,   245,
     272,   276,   280,   284,   288,   294,   320,   336,   352,   370,
     374,   390,   408,   412,   438,   464,   490,   493,   497,   528,
     560,   561,   584,   588,   611,   615,   656,   660,   693,   701,
     704,   705,   715,   716,   717,   721,   734,   737,   738,   741,
     751,   752,   755,   763,   764,   767,   768,   771,   774,   779,
     783,   788,   792,   796,   802,   806,   809,   815,   819,   826,
     827,   833,   837,   843,   846,   861,   880,   903,   915,   916,
     919,   920,   923
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
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
  "constant", "primary_expression", "argument_expression_list_opt",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "unary_operator", "multiplicative_expression", "additive_expression",
  "relational_expression", "equality_expression", "logical_AND_expression",
  "logical_OR_expression", "conditional_expression",
  "assignment_expression", "expression", "declaration", "init_declarator",
  "type_specifier", "declarator", "parameter_list_opt",
  "direct_declarator", "pointer", "parameter_list", "identifier_opt",
  "parameter_declaration", "initializer", "statement",
  "block_item_list_opt", "compound_statement", "block_item_list",
  "block_item", "expression_opt", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "translation_unit", "external_declaration", "function_definition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-92)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-83)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      29,   -92,   -92,   -92,   -92,    -1,   147,   -92,   -92,    39,
     -92,   -30,   -10,   -92,    23,   -92,   -92,    18,    29,   -92,
      66,   146,   -92,   -92,    50,    55,    69,    51,   -92,   -92,
     -92,   -92,   -92,    83,    86,   146,   146,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,    19,    67,   146,    41,    57,   128,
      77,    71,    -4,   -92,   -92,   -92,   -92,    -1,   -92,    93,
     -92,    95,   -92,    89,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   113,   -92,    29,   146,   146,    91,   105,   146,   146,
     129,   146,   -92,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   103,    26,   104,   -92,     7,   -92,
     -92,   -92,   -92,   -92,   101,   -92,   -92,   131,   136,   132,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,    41,    41,    57,
      57,    57,    57,   128,   128,   -92,   -92,   -92,   -92,   144,
     -92,   -92,   -92,   146,   146,   146,   146,   -92,   146,   -92,
      77,   -92,    71,   121,   135,   133,   -92,   -92,   -92,   164,
     146,   146,   -92,   -92,   -92,   121,   159,   -92,   -92,   121,
     -92
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    52,    53,    54,    91,     0,     0,    88,    90,    59,
      62,     0,    50,    56,     0,     1,    89,     0,    58,    49,
      75,     0,    92,    55,     0,     0,     0,    57,    63,     6,
       4,     5,     8,     0,     0,    82,     0,    20,    21,    22,
      23,    24,     7,    12,    18,    25,     0,    29,    32,    37,
      40,    42,    44,    46,    48,    81,    79,     0,    80,     0,
      69,     2,    77,     0,    70,    71,    72,    73,    68,    51,
      60,    66,    61,     0,     0,    82,     0,     0,     0,    11,
       0,     0,    19,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    76,    82,    83,
      65,    67,    64,     3,     0,    87,     9,     0,     0,    10,
      16,    15,    47,    26,    27,    28,    25,    30,    31,    33,
      34,    35,    36,    38,    39,     2,     2,     2,    78,     0,
       2,    13,    14,     0,     0,     0,     0,     2,    82,    17,
      41,     3,    43,    82,     0,     0,     3,     2,     2,    84,
      82,     0,     2,     3,    45,    82,     0,    85,     2,    82,
      86
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -92,   -29,   -46,   -92,   -92,   -92,   -92,   -92,   -42,   -92,
      34,    75,    43,    44,    45,   -92,    28,   -20,   -18,   -13,
     -92,   -15,   120,   -92,   166,   157,   -92,   -92,   110,   -92,
     -91,   -92,   172,   -92,    87,   -35,   -92,   -92,   -92,   -92,
     -92,   180,   -92
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    98,    94,    42,    43,   108,    44,   109,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,     4,
      11,     5,    12,    26,    13,    14,    27,   101,    28,    69,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       6,     7,     8
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      76,    68,     9,    25,    82,    57,    95,    56,    20,    19,
      29,    30,    31,    32,     1,     2,     3,    33,    77,    34,
      35,    10,    24,    36,    -3,    20,     9,    21,    37,    38,
      39,    40,    -3,    78,    41,    79,     1,     2,     3,    80,
     104,   113,   114,   115,   116,   116,   116,   116,   116,   116,
     116,   116,   146,    17,   126,    18,   103,   129,    25,   110,
     107,   112,   127,    83,   157,    70,    84,    85,   160,    29,
      30,    31,    32,     1,     2,     3,    33,    10,    34,    35,
      86,    87,    36,    57,    20,    56,    72,    37,    38,    39,
      40,    73,   116,    41,   116,   145,   134,   135,   136,    74,
     149,   138,    75,   144,    81,   -82,    -3,   156,   143,   116,
      92,    93,    97,   139,   -74,   153,   100,   141,   150,   151,
     117,   118,   106,   155,    29,    30,    31,    32,    99,   159,
     105,    33,   111,    34,    35,   123,   124,    36,   125,    20,
     130,    21,    37,    38,    39,    40,   131,    15,    41,    29,
      30,    31,    32,   132,     1,     2,     3,    88,    89,    90,
      91,   137,    36,   119,   120,   121,   122,    37,    38,    39,
      40,   148,   133,    41,   147,   152,   158,    96,   140,   154,
      23,   142,    71,   102,    22,   128,    16
};

static const yytype_uint8 yycheck[] =
{
      35,    21,     3,    18,    46,    20,    52,    20,    18,    39,
       3,     4,     5,     6,     7,     8,     9,    10,    36,    12,
      13,    22,     4,    16,    28,    18,     3,    37,    21,    22,
      23,    24,    36,    14,    27,    16,     7,     8,     9,    20,
      75,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,   143,    14,    28,    16,    74,   103,    73,    79,
      78,    81,    36,    22,   155,    15,    25,    26,   159,     3,
       4,     5,     6,     7,     8,     9,    10,    22,    12,    13,
      23,    24,    16,    98,    18,    98,    17,    21,    22,    23,
      24,    40,   134,    27,   136,   141,   125,   126,   127,    16,
     146,   130,    16,   138,    37,    39,    35,   153,   137,   151,
      33,    34,    19,   133,    19,   150,     3,   135,   147,   148,
      86,    87,    17,   152,     3,     4,     5,     6,    39,   158,
      39,    10,     3,    12,    13,    92,    93,    16,    35,    18,
      39,    37,    21,    22,    23,    24,    15,     0,    27,     3,
       4,     5,     6,    17,     7,     8,     9,    29,    30,    31,
      32,    17,    16,    88,    89,    90,    91,    21,    22,    23,
      24,    38,    40,    27,    39,    11,    17,    57,   134,   151,
      14,   136,    25,    73,    12,    98,     6
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,     9,    61,    63,    82,    83,    84,     3,
      22,    62,    64,    66,    67,     0,    83,    14,    16,    39,
      18,    37,    74,    66,     4,    63,    65,    68,    70,     3,
       4,     5,     6,    10,    12,    13,    16,    21,    22,    23,
      24,    27,    45,    46,    48,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    63,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    59,    71,
      15,    67,    17,    40,    16,    16,    77,    60,    14,    16,
      20,    37,    50,    22,    25,    26,    23,    24,    29,    30,
      31,    32,    33,    34,    44,    44,    64,    19,    43,    39,
       3,    69,    70,    60,    77,    39,    17,    60,    47,    49,
      59,     3,    59,    50,    50,    50,    50,    52,    52,    53,
      53,    53,    53,    54,    54,    35,    28,    36,    76,    44,
      39,    15,    17,    40,    43,    43,    43,    17,    43,    59,
      55,    60,    56,    43,    77,    44,    72,    39,    38,    44,
      43,    43,    11,    77,    58,    43,    44,    72,    17,    43,
      72
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    45,    45,    46,    46,    46,    46,
      47,    47,    48,    48,    48,    48,    49,    49,    50,    50,
      51,    51,    51,    51,    51,    52,    52,    52,    52,    53,
      53,    53,    54,    54,    54,    54,    54,    55,    55,    55,
      56,    56,    57,    57,    58,    58,    59,    59,    60,    61,
      62,    62,    63,    63,    63,    64,    64,    65,    65,    66,
      66,    66,    67,    68,    68,    69,    69,    70,    71,    72,
      72,    72,    72,    72,    73,    73,    74,    75,    75,    76,
      76,    77,    77,    78,    79,    79,    80,    81,    82,    82,
      83,    83,    84
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     1,     1,     1,     1,     1,     3,
       1,     0,     1,     4,     4,     3,     1,     3,     1,     2,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     5,     1,     5,     1,     9,     1,     3,     1,     3,
       1,     3,     1,     1,     1,     2,     1,     1,     0,     1,
       4,     4,     1,     1,     3,     1,     0,     3,     1,     1,
       1,     1,     1,     1,     1,     0,     3,     1,     3,     1,
       1,     1,     0,     2,     8,    11,    13,     3,     1,     2,
       1,     1,     3
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
#line 95 "1_A4.y"
          { (yyval.instrCount) = instrCount; }
#line 1285 "1_A4.tab.c"
    break;

  case 3: /* N: %empty  */
#line 98 "1_A4.y"
          { 
        (yyval.S) = new Statement();
        (yyval.S) -> nextList = makelist(nextInstr());
        emit("goto", "");
         
}
#line 1296 "1_A4.tab.c"
    break;

  case 4: /* constant: INTEGER_CONSTANT  */
#line 108 "1_A4.y"
        {
		(yyval.E)=new Expression();	
		updateNextInstr();
		string p=convertToString((yyvsp[0].intval));
		updateNextInstr();
		(yyval.E)->loc=gentemp(new symbolType("INTEGER"),p);
		updateNextInstr();
		emit("=",(yyval.E)->loc->name,p);
		updateNextInstr();
        }
#line 1311 "1_A4.tab.c"
    break;

  case 5: /* constant: CHARACTER_CONSTANT  */
#line 119 "1_A4.y"
        {
		(yyval.E)=new Expression();
		updateNextInstr();
		(yyval.E)->loc=gentemp(new symbolType("CHAR"),(yyvsp[0].char_value));
		updateNextInstr();
		emit("=",(yyval.E)->loc->name,string((yyvsp[0].char_value)));
		updateNextInstr();
        }
#line 1324 "1_A4.tab.c"
    break;

  case 6: /* primary_expression: IDENTIFIER  */
#line 130 "1_A4.y"
                        {
                                (yyval.E) = new Expression();
                                updateNextInstr();
                                (yyval.E) -> loc = (yyvsp[0].symPtr);
                                updateNextInstr();
                                (yyval.E)->type = "not-boolean";
                                updateNextInstr();
                        }
#line 1337 "1_A4.tab.c"
    break;

  case 7: /* primary_expression: constant  */
#line 139 "1_A4.y"
                        {
                                (yyval.E) = (yyvsp[0].E);
                        }
#line 1345 "1_A4.tab.c"
    break;

  case 8: /* primary_expression: STRING_LITERAL  */
#line 143 "1_A4.y"
                    {
                        (yyval.E)=new Expression();
                        updateNextInstr();
                        (yyval.E)->loc=gentemp(new symbolType("PTR"),(yyvsp[0].char_value));
                        updateNextInstr();
                        (yyval.E)->loc->type->arrtype=new symbolType("CHAR");
                        updateNextInstr();
                        
                    }
#line 1359 "1_A4.tab.c"
    break;

  case 9: /* primary_expression: L_ROUND_BRACKET expression R_ROUND_BRACKET  */
#line 153 "1_A4.y"
                        {
                                (yyval.E) = (yyvsp[-1].E);
                        }
#line 1367 "1_A4.tab.c"
    break;

  case 10: /* argument_expression_list_opt: argument_expression_list  */
#line 158 "1_A4.y"
                                                        { (yyval.paramCount)=(yyvsp[0].paramCount); }
#line 1373 "1_A4.tab.c"
    break;

  case 11: /* argument_expression_list_opt: %empty  */
#line 159 "1_A4.y"
                                    { (yyval.paramCount)=0; }
#line 1379 "1_A4.tab.c"
    break;

  case 12: /* postfix_expression: primary_expression  */
#line 163 "1_A4.y"
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
#line 1394 "1_A4.tab.c"
    break;

  case 13: /* postfix_expression: postfix_expression L_SQUARE_BRACKET expression R_SQUARE_BRACKET  */
#line 175 "1_A4.y"
                { 	
                                	 
						(yyval.A)=new Array();
						updateNextInstr();
						(yyval.A)->type=(yyvsp[-3].A)->type->arrtype;				// type=type of element	
						updateNextInstr();			
						(yyval.A)->Array=(yyvsp[-3].A)->Array;						// copy the base
						updateNextInstr();
						(yyval.A)->loc=gentemp(new symbolType("INTEGER"));		// store computed address
						updateNextInstr();
						(yyval.A)->aType="ARR";						//aType is ARR.
						updateNextInstr();
						if((yyvsp[-3].A)->aType=="ARR") 
						{			// if already ARR, multiply the size of the sub-type of Array with the expression value and add
							
							sym* t=gentemp(new symbolType("INTEGER"));
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
#line 1438 "1_A4.tab.c"
    break;

  case 14: /* postfix_expression: postfix_expression L_ROUND_BRACKET argument_expression_list_opt R_ROUND_BRACKET  */
#line 215 "1_A4.y"
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
#line 1453 "1_A4.tab.c"
    break;

  case 15: /* postfix_expression: postfix_expression ARROW IDENTIFIER  */
#line 225 "1_A4.y"
                                                          {  }
#line 1459 "1_A4.tab.c"
    break;

  case 16: /* argument_expression_list: assignment_expression  */
#line 229 "1_A4.y"
                        {
                                (yyval.paramCount) = 1;
                                updateNextInstr();
                                emit("param",(yyvsp[0].E)->loc->name);	
                                updateNextInstr();
                        }
#line 1470 "1_A4.tab.c"
    break;

  case 17: /* argument_expression_list: argument_expression_list COMMA assignment_expression  */
#line 236 "1_A4.y"
                        {
                                (yyval.paramCount) = (yyvsp[-2].paramCount)+1;
                                updateNextInstr();
                                emit("param",(yyvsp[0].E)->loc->name);	
                                updateNextInstr();
                        }
#line 1481 "1_A4.tab.c"
    break;

  case 18: /* unary_expression: postfix_expression  */
#line 244 "1_A4.y"
                                     { (yyval.A)=(yyvsp[0].A); }
#line 1487 "1_A4.tab.c"
    break;

  case 19: /* unary_expression: unary_operator unary_expression  */
#line 246 "1_A4.y"
                {			

                        (yyval.A)=new Array();
                        updateNextInstr();
                        switch((yyvsp[-1].unaryOp))
                                {	  
                                        case '+':  
                                                (yyval.A)=(yyvsp[0].A);
                                                break;                    //unary plus, do nothing
                                        case '-':				   //unary minus, generate new temporary of the same base type and make it negative of current one
                                                (yyval.A)->Array=gentemp(new symbolType((yyvsp[0].A)->Array->type->type));
                                                updateNextInstr();
                                                emit("uminus",(yyval.A)->Array->name,(yyvsp[0].A)->Array->name);
                                                updateNextInstr();
                                                break; 

                                        case '!':				//logical not, generate new temporary of the same base type and make it negative of current one
                                                (yyval.A)->Array=gentemp(new symbolType((yyvsp[0].A)->Array->type->type));
                                                updateNextInstr();
                                                emit("!",(yyval.A)->Array->name,(yyvsp[0].A)->Array->name);
                                                updateNextInstr();
                                                break;
                                }
                }
#line 1516 "1_A4.tab.c"
    break;

  case 20: /* unary_operator: AMPERSAND  */
#line 273 "1_A4.y"
                {
                        (yyval.unaryOp) = '&';
                }
#line 1524 "1_A4.tab.c"
    break;

  case 21: /* unary_operator: ASTERISK  */
#line 277 "1_A4.y"
                {
                        (yyval.unaryOp) = '*';
                }
#line 1532 "1_A4.tab.c"
    break;

  case 22: /* unary_operator: PLUS  */
#line 281 "1_A4.y"
                {
                        (yyval.unaryOp) = '+';
                }
#line 1540 "1_A4.tab.c"
    break;

  case 23: /* unary_operator: MINUS  */
#line 285 "1_A4.y"
                {
                        (yyval.unaryOp) = '-';
                }
#line 1548 "1_A4.tab.c"
    break;

  case 24: /* unary_operator: NOT  */
#line 289 "1_A4.y"
                {
                        (yyval.unaryOp) = '!';
                }
#line 1556 "1_A4.tab.c"
    break;

  case 25: /* multiplicative_expression: unary_expression  */
#line 295 "1_A4.y"
                           {
		 
		(yyval.E) = new Expression();             //generate new expression	
		updateNextInstr();						    
		if((yyvsp[0].A)->aType=="ARR") 			   //if it is of type ARR
		{
			(yyval.E)->loc = gentemp((yyvsp[0].A)->loc->type);	
			updateNextInstr();
			emit("=[]", (yyval.E)->loc->name, (yyvsp[0].A)->Array->name, (yyvsp[0].A)->loc->name);     //emit with Array right
			updateNextInstr();
			 
		}
		else if((yyvsp[0].A)->aType=="PTR")         //if it is of type PTR
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
#line 1586 "1_A4.tab.c"
    break;

  case 26: /* multiplicative_expression: multiplicative_expression ASTERISK unary_expression  */
#line 321 "1_A4.y"
                                { 
		 
		if(!compareSymbolType((yyvsp[-2].E)->loc, (yyvsp[0].A)->Array))         
			cout<<"Type Error in Program"<< endl;	// error
		else 								 //if types are compatible, generate new temporary and equate to the product
		{
			(yyval.E) = new Expression();	
			updateNextInstr();
			(yyval.E)->loc = gentemp(new symbolType((yyvsp[-2].E)->loc->type->type));
			updateNextInstr();
			emit("*", (yyval.E)->loc->name, (yyvsp[-2].E)->loc->name, (yyvsp[0].A)->Array->name);
			updateNextInstr();
			 
		}
	}
#line 1606 "1_A4.tab.c"
    break;

  case 27: /* multiplicative_expression: multiplicative_expression DIVIDE unary_expression  */
#line 337 "1_A4.y"
                                {
		 
		if(!compareSymbolType((yyvsp[-2].E)->loc, (yyvsp[0].A)->Array))
			cout << "Type Error in Program"<< endl;
		else    //if types are compatible, generate new temporary and equate to the quotient
		{
			(yyval.E) = new Expression();
			updateNextInstr();
			(yyval.E)->loc = gentemp(new symbolType((yyvsp[-2].E)->loc->type->type));
			updateNextInstr();
			emit("/", (yyval.E)->loc->name, (yyvsp[-2].E)->loc->name, (yyvsp[0].A)->Array->name);
			updateNextInstr();	
			 						
		}
	}
#line 1626 "1_A4.tab.c"
    break;

  case 28: /* multiplicative_expression: multiplicative_expression MODULO unary_expression  */
#line 353 "1_A4.y"
                                {
		 
		if(!compareSymbolType((yyvsp[-2].E)->loc, (yyvsp[0].A)->Array))
			cout << "Type Error in Program"<< endl;		
		else 		 //if types are compatible, generate new temporary and equate to the quotient
		{
			(yyval.E) = new Expression();
			updateNextInstr();
			(yyval.E)->loc = gentemp(new symbolType((yyvsp[-2].E)->loc->type->type));
			updateNextInstr();
			emit("%", (yyval.E)->loc->name, (yyvsp[-2].E)->loc->name, (yyvsp[0].A)->Array->name);	
			updateNextInstr();	
			 	
		}
	}
#line 1646 "1_A4.tab.c"
    break;

  case 29: /* additive_expression: multiplicative_expression  */
#line 371 "1_A4.y"
                        {
                                (yyval.E) = (yyvsp[0].E);
                        }
#line 1654 "1_A4.tab.c"
    break;

  case 30: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 375 "1_A4.y"
                        {
		 
		if(!compareSymbolType((yyvsp[-2].E)->loc, (yyvsp[0].E)->loc))
			cout << "Type Error in Program"<< endl;
		else    	//if types are compatible, generate new temporary and equate to the sum
		{
			(yyval.E) = new Expression();	
			updateNextInstr();
			(yyval.E)->loc = gentemp(new symbolType((yyvsp[-2].E)->loc->type->type));
			updateNextInstr();
			emit("+", (yyval.E)->loc->name, (yyvsp[-2].E)->loc->name, (yyvsp[0].E)->loc->name);
			updateNextInstr();
			 
		}
	}
#line 1674 "1_A4.tab.c"
    break;

  case 31: /* additive_expression: additive_expression MINUS multiplicative_expression  */
#line 391 "1_A4.y"
                        {
		 
		if(!compareSymbolType((yyvsp[-2].E)->loc, (yyvsp[0].E)->loc))
			cout << "Type Error in Program"<< endl;		
		else        //if types are compatible, generate new temporary and equate to the difference
		{	
			(yyval.E) = new Expression();	
			updateNextInstr();
			(yyval.E)->loc = gentemp(new symbolType((yyvsp[-2].E)->loc->type->type));
			updateNextInstr();
			emit("-", (yyval.E)->loc->name, (yyvsp[-2].E)->loc->name, (yyvsp[0].E)->loc->name);
			updateNextInstr();
			 
		}
	}
#line 1694 "1_A4.tab.c"
    break;

  case 32: /* relational_expression: additive_expression  */
#line 409 "1_A4.y"
                        {
                                (yyval.E) = (yyvsp[0].E);
                        }
#line 1702 "1_A4.tab.c"
    break;

  case 33: /* relational_expression: relational_expression LESS_THAN additive_expression  */
#line 413 "1_A4.y"
                                {
		if(!compareSymbolType((yyvsp[-2].E)->loc, (yyvsp[0].E)->loc)) 
		{
			 
			cout << "Type Error in Program"<< endl;
		}
		else 
		{      //check compatible types		
			 							
			(yyval.E) = new Expression();
			updateNextInstr();
			(yyval.E)->type = "BOOL";                         //new type is boolean
			updateNextInstr();		
			(yyval.E)->trueList = makelist(nextInstr());     //makelist for trueList and falseList
			updateNextInstr();
			(yyval.E)->falseList = makelist(nextInstr()+1);
			updateNextInstr();
			emit("<", "", (yyvsp[-2].E)->loc->name, (yyvsp[0].E)->loc->name);     //emit statement if a<b GOTO .. 
			updateNextInstr();
			 
			emit("GOTO", "");	//emit statement GOTO ..
			updateNextInstr();
			 
		}
	}
#line 1732 "1_A4.tab.c"
    break;

  case 34: /* relational_expression: relational_expression GREATER_THAN additive_expression  */
#line 439 "1_A4.y"
                                {
		if(!compareSymbolType((yyvsp[-2].E)->loc, (yyvsp[0].E)->loc)) 
		{
			 
			cout << "Type Error in Program"<< endl;
		}
		else 
		{
			 
			(yyval.E) = new Expression();	
			updateNextInstr();
			(yyval.E)->type = "BOOL";
			updateNextInstr();
			(yyval.E)->trueList = makelist(nextInstr());
			updateNextInstr();
			(yyval.E)->falseList = makelist(nextInstr()+1);
			updateNextInstr();
			emit(">", "", (yyvsp[-2].E)->loc->name, (yyvsp[0].E)->loc->name);
			updateNextInstr();
			 
			emit("GOTO", "");
			updateNextInstr();
			 
		}	
	}
#line 1762 "1_A4.tab.c"
    break;

  case 35: /* relational_expression: relational_expression LESS_THAN_EQUAL_TO additive_expression  */
#line 465 "1_A4.y"
                                {
		if(!compareSymbolType((yyvsp[-2].E)->loc, (yyvsp[0].E)->loc)) 
		{
			 
			cout << "Type Error in Program"<< endl;
		}
		else 
		{		
			 
			(yyval.E) = new Expression();		
			updateNextInstr();
			(yyval.E)->type = "BOOL";
			updateNextInstr();
			(yyval.E)->trueList = makelist(nextInstr());
			updateNextInstr();
			(yyval.E)->falseList = makelist(nextInstr()+1);
			updateNextInstr();
			emit("<=", "", (yyvsp[-2].E)->loc->name, (yyvsp[0].E)->loc->name);
			updateNextInstr();
			 
			emit("GOTO", "");
			updateNextInstr();
			 
		}		
	}
#line 1792 "1_A4.tab.c"
    break;

  case 37: /* equality_expression: relational_expression  */
#line 494 "1_A4.y"
                        {
                                (yyval.E) = (yyvsp[0].E);
                        }
#line 1800 "1_A4.tab.c"
    break;

  case 38: /* equality_expression: equality_expression EQUAL_TO relational_expression  */
#line 498 "1_A4.y"
                    {
		if(!compareSymbolType((yyvsp[-2].E)->loc, (yyvsp[0].E)->loc))                //check compatible types
		{
			 
			cout << "Type Error in Program"<< endl;
		}
		else 
		{
			 
			convertBool2Int((yyvsp[-2].E));                  //convert BOOL to INTEGER
			updateNextInstr();	
			convertBool2Int((yyvsp[0].E));
			updateNextInstr();
			(yyval.E) = new Expression();
			updateNextInstr();
			(yyval.E)->type = "BOOL";
			updateNextInstr();
			(yyval.E)->trueList = makelist(nextInstr());            //make lists for new expression
			updateNextInstr();
			(yyval.E)->falseList = makelist(nextInstr()+1); 
			updateNextInstr();
			emit("==", "", (yyvsp[-2].E)->loc->name, (yyvsp[0].E)->loc->name);      //emit if a==b GOTO ..
			updateNextInstr();
			 
			emit("GOTO", "");				//emit GOTO ..
			updateNextInstr();
			 
		}
		
	}
#line 1835 "1_A4.tab.c"
    break;

  case 39: /* equality_expression: equality_expression NOT_EQUAL_TO relational_expression  */
#line 529 "1_A4.y"
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
			(yyval.E)->type = "BOOL";
			updateNextInstr();
			(yyval.E)->trueList = makelist(nextInstr());
			updateNextInstr();
			(yyval.E)->falseList = makelist(nextInstr()+1);
			updateNextInstr();
			emit("!=", "", (yyvsp[-2].E)->loc->name, (yyvsp[0].E)->loc->name);
			updateNextInstr();
			 
			emit("GOTO", "");
			updateNextInstr();
			 
		}
	}
#line 1869 "1_A4.tab.c"
    break;

  case 40: /* logical_AND_expression: equality_expression  */
#line 560 "1_A4.y"
                                             { (yyval.E)=(yyvsp[0].E); }
#line 1875 "1_A4.tab.c"
    break;

  case 41: /* logical_AND_expression: logical_AND_expression N LOGICAL_AND M equality_expression  */
#line 562 "1_A4.y"
                                { 
		 
		convertInt2Bool((yyvsp[0].E));         //convert inclusive_or_expression INTEGER to BOOL
		updateNextInstr();
		backpatch((yyvsp[-3].S)->nextList, nextInstr());        //$2->nextList goes to next instruction
		updateNextInstr();
		convertInt2Bool((yyvsp[-4].E));                  //convert logical_and_expression to BOOL
		updateNextInstr();
		(yyval.E) = new Expression();     //make new boolean expression 
		updateNextInstr();
		(yyval.E)->type = "BOOL";
		updateNextInstr();
		backpatch((yyvsp[-4].E)->trueList, (yyvsp[-1].instrCount));        //if $1 is true, we move to $5
		updateNextInstr();
		(yyval.E)->trueList = (yyvsp[0].E)->trueList;        //if $5 is also true, we get trueList for $$
		updateNextInstr();
		(yyval.E)->falseList = merge((yyvsp[-4].E)->falseList, (yyvsp[0].E)->falseList);    //merge their falselists
		updateNextInstr();
		 
	}
#line 1900 "1_A4.tab.c"
    break;

  case 42: /* logical_OR_expression: logical_AND_expression  */
#line 585 "1_A4.y"
                        {
                                (yyval.E) = (yyvsp[0].E);
                        }
#line 1908 "1_A4.tab.c"
    break;

  case 43: /* logical_OR_expression: logical_OR_expression N LOGICAL_OR M logical_AND_expression  */
#line 589 "1_A4.y"
                                { 
		 
		convertInt2Bool((yyvsp[0].E));			 //convert logical_and_expression INTEGER to BOOL
		updateNextInstr();
		backpatch((yyvsp[-3].S)->nextList, nextInstr());	//$2->nextList goes to next instruction
		updateNextInstr();
		convertInt2Bool((yyvsp[-4].E));			//convert logical_or_expression to BOOL
		updateNextInstr();
		(yyval.E) = new Expression();			//make new boolean expression
		updateNextInstr();
		(yyval.E)->type = "BOOL";
		updateNextInstr();
		backpatch((yyvsp[-4].E)->falseList, (yyvsp[-1].instrCount));		//if $1 is true, we move to $5
		updateNextInstr();
		(yyval.E)->trueList = merge((yyvsp[-4].E)->trueList, (yyvsp[0].E)->trueList);		//merge their truelists
		updateNextInstr();
		(yyval.E)->falseList = (yyvsp[0].E)->falseList;		 	//if $5 is also false, we get falseList for $$
		updateNextInstr();
		 
	}
#line 1933 "1_A4.tab.c"
    break;

  case 44: /* conditional_expression: logical_OR_expression  */
#line 612 "1_A4.y"
                        {
                                (yyval.E) = (yyvsp[0].E);
                        }
#line 1941 "1_A4.tab.c"
    break;

  case 45: /* conditional_expression: logical_OR_expression N QUESTION M expression N COLON M conditional_expression  */
#line 616 "1_A4.y"
                        {
		 
		//normal conversion method to get conditional expressions
		(yyval.E)->loc = gentemp((yyvsp[-4].E)->loc->type);       //generate temporary for expression
		updateNextInstr();
		(yyval.E)->loc->update((yyvsp[-4].E)->loc->type);
		updateNextInstr();
		emit("=", (yyval.E)->loc->name, (yyvsp[0].E)->loc->name);      //make it equal to sconditional_expression
		updateNextInstr();
		 
		list<int> l = makelist(nextInstr());        //makelist next instruction
		emit("GOTO", "");              //prevent fallthrough
		updateNextInstr();
		 
		backpatch((yyvsp[-3].S)->nextList, nextInstr());        //after N, go to next instruction
		updateNextInstr();
		emit("=", (yyval.E)->loc->name, (yyvsp[-4].E)->loc->name);
		updateNextInstr();
		 
		list<int> m = makelist(nextInstr());         //makelist next instruction
		updateNextInstr();
		l = merge(l, m);						//merge the two lists
		updateNextInstr();
		emit("GOTO", "");						//prevent fallthrough
		updateNextInstr();
		 
		backpatch((yyvsp[-7].S)->nextList, nextInstr());   //backpatching
		updateNextInstr();
		convertInt2Bool((yyvsp[-8].E));                   //convert expression to boolean
		updateNextInstr();
		backpatch((yyvsp[-8].E)->trueList, (yyvsp[-5].instrCount));           //$1 true goes to expression
		updateNextInstr();
		backpatch((yyvsp[-8].E)->falseList, (yyvsp[-1].instrCount));          //$1 false goes to conditional_expression
		updateNextInstr();
		backpatch(l, nextInstr());
		updateNextInstr();
		 
	}
#line 1984 "1_A4.tab.c"
    break;

  case 46: /* assignment_expression: conditional_expression  */
#line 657 "1_A4.y"
                        {
                                (yyval.E) = (yyvsp[0].E);
                        }
#line 1992 "1_A4.tab.c"
    break;

  case 47: /* assignment_expression: unary_expression ASSIGN assignment_expression  */
#line 661 "1_A4.y"
                                 {
		if((yyvsp[-2].A)->aType=="ARR")       //if type is ARR, simply check if we need to convert and emit
		{
			 
			(yyvsp[0].E)->loc = convertType((yyvsp[0].E)->loc, (yyvsp[-2].A)->aType);
			updateNextInstr();
			emit("[]=", (yyvsp[-2].A)->Array->name, (yyvsp[-2].A)->loc->name, (yyvsp[0].E)->loc->name);		
			updateNextInstr();
			 
		}
		else if((yyvsp[-2].A)->aType=="PTR")     //if type is PTR, simply emit
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
#line 2027 "1_A4.tab.c"
    break;

  case 48: /* expression: assignment_expression  */
#line 694 "1_A4.y"
                {
                        (yyval.E) = (yyvsp[0].E);
                }
#line 2035 "1_A4.tab.c"
    break;

  case 49: /* declaration: type_specifier init_declarator SEMICOLON  */
#line 701 "1_A4.y"
                                                        {       }
#line 2041 "1_A4.tab.c"
    break;

  case 50: /* init_declarator: declarator  */
#line 704 "1_A4.y"
                            {(yyval.symPtr)=(yyvsp[0].symPtr);}
#line 2047 "1_A4.tab.c"
    break;

  case 51: /* init_declarator: declarator ASSIGN initializer  */
#line 706 "1_A4.y"
                        {
		 
		if((yyvsp[0].symPtr)->val!="") (yyvsp[-2].symPtr)->val=(yyvsp[0].symPtr)->val;        //get the initial value and  emit it
		emit("=", (yyvsp[-2].symPtr)->name, (yyvsp[0].symPtr)->name);
		updateNextInstr();
		 
	}
#line 2059 "1_A4.tab.c"
    break;

  case 52: /* type_specifier: VOID  */
#line 715 "1_A4.y"
                        {var_type="VOID";}
#line 2065 "1_A4.tab.c"
    break;

  case 53: /* type_specifier: CHAR  */
#line 716 "1_A4.y"
                        { var_type="CHAR"; }
#line 2071 "1_A4.tab.c"
    break;

  case 54: /* type_specifier: INT  */
#line 717 "1_A4.y"
                        { var_type="INTEGER"; }
#line 2077 "1_A4.tab.c"
    break;

  case 55: /* declarator: pointer direct_declarator  */
#line 722 "1_A4.y"
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
#line 2094 "1_A4.tab.c"
    break;

  case 56: /* declarator: direct_declarator  */
#line 734 "1_A4.y"
                            { }
#line 2100 "1_A4.tab.c"
    break;

  case 59: /* direct_declarator: IDENTIFIER  */
#line 742 "1_A4.y"
        {
		 
		(yyval.symPtr) = (yyvsp[0].symPtr)->update(new symbolType(var_type));
		updateNextInstr();
		currentSymbol = (yyval.symPtr);
		updateNextInstr();
		 
		
	}
#line 2114 "1_A4.tab.c"
    break;

  case 62: /* pointer: ASTERISK  */
#line 756 "1_A4.y"
        { 
		(yyval.symType) = new symbolType("PTR");
		updateNextInstr();
		  
	}
#line 2124 "1_A4.tab.c"
    break;

  case 63: /* parameter_list: parameter_declaration  */
#line 763 "1_A4.y"
                                                {       }
#line 2130 "1_A4.tab.c"
    break;

  case 64: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 764 "1_A4.y"
                                                             {  }
#line 2136 "1_A4.tab.c"
    break;

  case 68: /* initializer: assignment_expression  */
#line 774 "1_A4.y"
                                     { (yyval.symPtr)=(yyvsp[0].E)->loc; }
#line 2142 "1_A4.tab.c"
    break;

  case 69: /* statement: compound_statement  */
#line 780 "1_A4.y"
                {
                        (yyval.S) = (yyvsp[0].S);
                }
#line 2150 "1_A4.tab.c"
    break;

  case 70: /* statement: expression_statement  */
#line 784 "1_A4.y"
                                { 
		(yyval.S)=new Statement();              //create new statement with same nextList
		(yyval.S)->nextList=(yyvsp[0].E)->nextList; 
	}
#line 2159 "1_A4.tab.c"
    break;

  case 71: /* statement: selection_statement  */
#line 789 "1_A4.y"
                {
                        (yyval.S) = (yyvsp[0].S);
                }
#line 2167 "1_A4.tab.c"
    break;

  case 72: /* statement: iteration_statement  */
#line 793 "1_A4.y"
                {
                        (yyval.S) = (yyvsp[0].S);
                }
#line 2175 "1_A4.tab.c"
    break;

  case 73: /* statement: jump_statement  */
#line 797 "1_A4.y"
                {
                        (yyval.S) = (yyvsp[0].S);
                }
#line 2183 "1_A4.tab.c"
    break;

  case 74: /* block_item_list_opt: block_item_list  */
#line 803 "1_A4.y"
                {
                        (yyval.S) = (yyvsp[0].S);
                }
#line 2191 "1_A4.tab.c"
    break;

  case 75: /* block_item_list_opt: %empty  */
#line 806 "1_A4.y"
                                       { (yyval.S)=new Statement(); }
#line 2197 "1_A4.tab.c"
    break;

  case 76: /* compound_statement: L_CURLY_BRACKET block_item_list_opt R_CURLY_BRACKET  */
#line 810 "1_A4.y"
                {
                        (yyval.S) = (yyvsp[-1].S);
                }
#line 2205 "1_A4.tab.c"
    break;

  case 77: /* block_item_list: block_item  */
#line 816 "1_A4.y"
                {
                        (yyval.S) = (yyvsp[0].S);
                }
#line 2213 "1_A4.tab.c"
    break;

  case 78: /* block_item_list: block_item_list M block_item  */
#line 820 "1_A4.y"
                                        { 
						(yyval.S)=(yyvsp[0].S);
						backpatch((yyvsp[-2].S)->nextList,(yyvsp[-1].instrCount));     //after $1, move to block_item via $2
					}
#line 2222 "1_A4.tab.c"
    break;

  case 79: /* block_item: declaration  */
#line 826 "1_A4.y"
                         { (yyval.S)=new Statement(); }
#line 2228 "1_A4.tab.c"
    break;

  case 80: /* block_item: statement  */
#line 828 "1_A4.y"
                {
                        (yyval.S) = (yyvsp[0].S);
                }
#line 2236 "1_A4.tab.c"
    break;

  case 81: /* expression_opt: expression  */
#line 834 "1_A4.y"
                {
                        (yyval.E) = (yyvsp[0].E);
                }
#line 2244 "1_A4.tab.c"
    break;

  case 82: /* expression_opt: %empty  */
#line 838 "1_A4.y"
                {
                        (yyval.E) = new Expression();
                }
#line 2252 "1_A4.tab.c"
    break;

  case 83: /* expression_statement: expression_opt SEMICOLON  */
#line 843 "1_A4.y"
                                                {       }
#line 2258 "1_A4.tab.c"
    break;

  case 84: /* selection_statement: IF L_ROUND_BRACKET expression N R_ROUND_BRACKET M statement N  */
#line 847 "1_A4.y"
                                                {
							backpatch((yyvsp[-4].S)->nextList, nextInstr());        //nextList of N goes to nextinstr
							updateNextInstr();
							convertInt2Bool((yyvsp[-5].E));         //convert expression to BOOL
							updateNextInstr();
							(yyval.S) = new Statement();        //make new statement
							updateNextInstr();
							backpatch((yyvsp[-5].E)->trueList, (yyvsp[-2].instrCount));        //is expression is true, go to M i.e just before statement body
							updateNextInstr();
							list<int> temp = merge((yyvsp[-5].E)->falseList, (yyvsp[-1].S)->nextList);   //merge falseList of expression, nextList of statement and second N
							updateNextInstr();
							(yyval.S)->nextList = merge((yyvsp[0].S)->nextList, temp);
							updateNextInstr();
						}
#line 2277 "1_A4.tab.c"
    break;

  case 85: /* selection_statement: IF L_ROUND_BRACKET expression N R_ROUND_BRACKET M statement N ELSE M statement  */
#line 862 "1_A4.y"
                                                {
							backpatch((yyvsp[-7].S)->nextList, nextInstr());		//nextList of N goes to nextinstr
							updateNextInstr();
							convertInt2Bool((yyvsp[-8].E));        //convert expression to BOOL
							updateNextInstr();
							(yyval.S) = new Statement();       //make new statement
							updateNextInstr();
							backpatch((yyvsp[-8].E)->trueList, (yyvsp[-5].instrCount));    //when expression is true, go to M1 else go to M2
							updateNextInstr();
							backpatch((yyvsp[-8].E)->falseList, (yyvsp[-1].instrCount));
							updateNextInstr();
							list<int> temp = merge((yyvsp[-4].S)->nextList, (yyvsp[-3].S)->nextList);       //merge the nextlists of the statements and second N
							updateNextInstr();
							(yyval.S)->nextList = merge((yyvsp[0].S)->nextList,temp);	
							updateNextInstr();
						}
#line 2298 "1_A4.tab.c"
    break;

  case 86: /* iteration_statement: FOR L_ROUND_BRACKET expression_opt SEMICOLON M expression_opt SEMICOLON M expression_opt N R_ROUND_BRACKET M statement  */
#line 881 "1_A4.y"
                                        {

						(yyval.S) = new Statement();		 //create new statement
						updateNextInstr();
						convertInt2Bool((yyvsp[-7].E));  //convert check expression to boolean
						updateNextInstr();
						backpatch((yyvsp[-7].E)->trueList, (yyvsp[-1].instrCount));	//if expression is true, go to M2
						updateNextInstr();
						backpatch((yyvsp[-3].S)->nextList, (yyvsp[-8].instrCount));	//after N, go back to M1
						updateNextInstr();
						backpatch((yyvsp[0].S)->nextList, (yyvsp[-5].instrCount));	//statement go back to expression
						updateNextInstr();
						string str=convertToString((yyvsp[-5].instrCount));
						updateNextInstr();
						emit("GOTO", str);				//prevent fallthrough
						updateNextInstr();
						
						(yyval.S)->nextList = (yyvsp[-7].E)->falseList;	//move out if statement is false	
						updateNextInstr();
					}
#line 2323 "1_A4.tab.c"
    break;

  case 87: /* jump_statement: RETURN expression_opt SEMICOLON  */
#line 904 "1_A4.y"
                                {
					(yyval.S) = new Statement();
					updateNextInstr();
					emit("return", "");
					updateNextInstr();
				}
#line 2334 "1_A4.tab.c"
    break;

  case 88: /* translation_unit: external_declaration  */
#line 915 "1_A4.y"
                                                        {   }
#line 2340 "1_A4.tab.c"
    break;

  case 89: /* translation_unit: translation_unit external_declaration  */
#line 916 "1_A4.y"
                                                         {   }
#line 2346 "1_A4.tab.c"
    break;

  case 90: /* external_declaration: function_definition  */
#line 919 "1_A4.y"
                                                {   }
#line 2352 "1_A4.tab.c"
    break;

  case 91: /* external_declaration: declaration  */
#line 920 "1_A4.y"
                                          {   }
#line 2358 "1_A4.tab.c"
    break;

  case 92: /* function_definition: type_specifier declarator compound_statement  */
#line 924 "1_A4.y"
                        {
                            int nextInstr = 0;
							updateNextInstr();
							ST->parent=globalST;
							updateNextInstr();
							changeTable(globalST);                  
							updateNextInstr();
                        }
#line 2371 "1_A4.tab.c"
    break;


#line 2375 "1_A4.tab.c"

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
      yyerror (YY_("syntax error"));
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

  return yyresult;
}

#line 934 "1_A4.y"


void yyerror(const char * s) {        //print syntax error
    cout<<s<<endl;
}
