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
#line 1 "parser.y"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*not used right now*/
void yyerror(const char *s);
int yylex(void);
extern FILE* yyin;

#line 82 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTEGER_LITERAL = 3,            /* INTEGER_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 4,              /* FLOAT_LITERAL  */
  YYSYMBOL_CHARACTER_LITERAL = 5,          /* CHARACTER_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 6,             /* STRING_LITERAL  */
  YYSYMBOL_BOOLEAN_LITERAL = 7,            /* BOOLEAN_LITERAL  */
  YYSYMBOL_IDENTIFIER = 8,                 /* IDENTIFIER  */
  YYSYMBOL_INT_TYPE_KEYWORD = 9,           /* INT_TYPE_KEYWORD  */
  YYSYMBOL_FLOAT_TYPE_KEYWORD = 10,        /* FLOAT_TYPE_KEYWORD  */
  YYSYMBOL_STRING_TYPE_KEYWORD = 11,       /* STRING_TYPE_KEYWORD  */
  YYSYMBOL_CHAR_TYPE_KEYWORD = 12,         /* CHAR_TYPE_KEYWORD  */
  YYSYMBOL_BOOL_TYPE_KEYWORD = 13,         /* BOOL_TYPE_KEYWORD  */
  YYSYMBOL_VOID_TYPE_KEYWORD = 14,         /* VOID_TYPE_KEYWORD  */
  YYSYMBOL_IF_KEYWORD = 15,                /* IF_KEYWORD  */
  YYSYMBOL_ELSEIF_KEYWORD = 16,            /* ELSEIF_KEYWORD  */
  YYSYMBOL_ELSE_KEYWORD = 17,              /* ELSE_KEYWORD  */
  YYSYMBOL_FOR_KEYWORD = 18,               /* FOR_KEYWORD  */
  YYSYMBOL_WHILE_KEYWORD = 19,             /* WHILE_KEYWORD  */
  YYSYMBOL_SWITCH_KEYWORD = 20,            /* SWITCH_KEYWORD  */
  YYSYMBOL_MAIN_KEYWORD = 21,              /* MAIN_KEYWORD  */
  YYSYMBOL_DO_KEYWORD = 22,                /* DO_KEYWORD  */
  YYSYMBOL_RETURN_KEYWORD = 23,            /* RETURN_KEYWORD  */
  YYSYMBOL_CASE_KEYWORD = 24,              /* CASE_KEYWORD  */
  YYSYMBOL_CONST_KEYWORD = 25,             /* CONST_KEYWORD  */
  YYSYMBOL_BREAK_KEYWORD = 26,             /* BREAK_KEYWORD  */
  YYSYMBOL_CONTINUE_KEYWORD = 27,          /* CONTINUE_KEYWORD  */
  YYSYMBOL_DEFAULT_KEYWORD = 28,           /* DEFAULT_KEYWORD  */
  YYSYMBOL_AND_KEYWORD = 29,               /* AND_KEYWORD  */
  YYSYMBOL_OR_KEYWORD = 30,                /* OR_KEYWORD  */
  YYSYMBOL_NOT_KEYWORD = 31,               /* NOT_KEYWORD  */
  YYSYMBOL_OPENING_CURLY_BRACE = 32,       /* OPENING_CURLY_BRACE  */
  YYSYMBOL_CLOSING_CURLY_BRACE = 33,       /* CLOSING_CURLY_BRACE  */
  YYSYMBOL_OPENING_PARENTHESIS = 34,       /* OPENING_PARENTHESIS  */
  YYSYMBOL_CLOSING_PARENTHESIS = 35,       /* CLOSING_PARENTHESIS  */
  YYSYMBOL_OPENING_SQUARE_BRACKETS = 36,   /* OPENING_SQUARE_BRACKETS  */
  YYSYMBOL_CLOSING_SQUARE_BRACKETS = 37,   /* CLOSING_SQUARE_BRACKETS  */
  YYSYMBOL_COMMA = 38,                     /* COMMA  */
  YYSYMBOL_ASTRISK = 39,                   /* ASTRISK  */
  YYSYMBOL_PLUS = 40,                      /* PLUS  */
  YYSYMBOL_MINUS = 41,                     /* MINUS  */
  YYSYMBOL_DIVIDE = 42,                    /* DIVIDE  */
  YYSYMBOL_MODULO = 43,                    /* MODULO  */
  YYSYMBOL_INCREMENT = 44,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 45,                 /* DECREMENT  */
  YYSYMBOL_ASSIGNMENT = 46,                /* ASSIGNMENT  */
  YYSYMBOL_EQUAL = 47,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 48,                 /* NOT_EQUAL  */
  YYSYMBOL_LESS_OR_EQUAL = 49,             /* LESS_OR_EQUAL  */
  YYSYMBOL_GREATER_OR_EQUAL = 50,          /* GREATER_OR_EQUAL  */
  YYSYMBOL_LESS = 51,                      /* LESS  */
  YYSYMBOL_GREATER = 52,                   /* GREATER  */
  YYSYMBOL_BITWISE_AND = 53,               /* BITWISE_AND  */
  YYSYMBOL_BITWISE_OR = 54,                /* BITWISE_OR  */
  YYSYMBOL_BITWISE_XOR = 55,               /* BITWISE_XOR  */
  YYSYMBOL_BITWISE_NOT = 56,               /* BITWISE_NOT  */
  YYSYMBOL_COLON = 57,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 58,                 /* SEMICOLON  */
  YYSYMBOL_UNRECOGNIZED_TOKEN = 59,        /* UNRECOGNIZED_TOKEN  */
  YYSYMBOL_RESERVED_IDENTIFIER = 60,       /* RESERVED_IDENTIFIER  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_program = 62,                   /* program  */
  YYSYMBOL_functions = 63,                 /* functions  */
  YYSYMBOL_function = 64,                  /* function  */
  YYSYMBOL_function_arguments = 65,        /* function_arguments  */
  YYSYMBOL_type_identifier = 66,           /* type_identifier  */
  YYSYMBOL_type = 67,                      /* type  */
  YYSYMBOL_body = 68,                      /* body  */
  YYSYMBOL_statements = 69,                /* statements  */
  YYSYMBOL_statement = 70,                 /* statement  */
  YYSYMBOL_if_statement = 71,              /* if_statement  */
  YYSYMBOL_elseif_statement = 72,          /* elseif_statement  */
  YYSYMBOL_else_statement = 73,            /* else_statement  */
  YYSYMBOL_for_statement = 74,             /* for_statement  */
  YYSYMBOL_loop_start = 75,                /* loop_start  */
  YYSYMBOL_loop_update = 76,               /* loop_update  */
  YYSYMBOL_while_statement = 77,           /* while_statement  */
  YYSYMBOL_do_while_statement = 78,        /* do_while_statement  */
  YYSYMBOL_switch_statement = 79,          /* switch_statement  */
  YYSYMBOL_default_case = 80,              /* default_case  */
  YYSYMBOL_case_list = 81,                 /* case_list  */
  YYSYMBOL_case_statement = 82,            /* case_statement  */
  YYSYMBOL_initialization = 83,            /* initialization  */
  YYSYMBOL_const_initialization = 84,      /* const_initialization  */
  YYSYMBOL_variable_declaration = 85,      /* variable_declaration  */
  YYSYMBOL_const_variable_declaration = 86, /* const_variable_declaration  */
  YYSYMBOL_return_statement = 87,          /* return_statement  */
  YYSYMBOL_assignment = 88,                /* assignment  */
  YYSYMBOL_expression = 89,                /* expression  */
  YYSYMBOL_array_element = 90,             /* array_element  */
  YYSYMBOL_expr_list = 91,                 /* expr_list  */
  YYSYMBOL_function_call = 92,             /* function_call  */
  YYSYMBOL_boolean_expr = 93,              /* boolean_expr  */
  YYSYMBOL_arithmetic_expr = 94,           /* arithmetic_expr  */
  YYSYMBOL_unary_expr = 95,                /* unary_expr  */
  YYSYMBOL_binary_expr = 96,               /* binary_expr  */
  YYSYMBOL_arithmetic_term = 97,           /* arithmetic_term  */
  YYSYMBOL_arithmetic_factor = 98,         /* arithmetic_factor  */
  YYSYMBOL_bitwise_expr = 99,              /* bitwise_expr  */
  YYSYMBOL_bitwise_xor_expr = 100,         /* bitwise_xor_expr  */
  YYSYMBOL_bitwise_and_expr = 101,         /* bitwise_and_expr  */
  YYSYMBOL_bitwise_not_expr = 102,         /* bitwise_not_expr  */
  YYSYMBOL_main_function = 103             /* main_function  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   370

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  257

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   315


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    84,    84,    88,    89,    92,    93,    94,    95,    98,
      99,   102,   106,   107,   108,   109,   110,   114,   118,   119,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   138,   141,   142,   145,   146,   149,
     152,   153,   154,   157,   158,   159,   162,   165,   168,   169,
     172,   175,   176,   179,   183,   184,   187,   188,   191,   192,
     195,   196,   199,   203,   206,   207,   208,   209,   210,   211,
     214,   217,   218,   221,   222,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   247,   248,   251,   252,   253,   254,
     255,   256,   260,   261,   262,   265,   266,   267,   268,   269,
     272,   273,   274,   275,   278,   279,   281,   282,   285,   286,
     289,   290,   296
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
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER_LITERAL",
  "FLOAT_LITERAL", "CHARACTER_LITERAL", "STRING_LITERAL",
  "BOOLEAN_LITERAL", "IDENTIFIER", "INT_TYPE_KEYWORD",
  "FLOAT_TYPE_KEYWORD", "STRING_TYPE_KEYWORD", "CHAR_TYPE_KEYWORD",
  "BOOL_TYPE_KEYWORD", "VOID_TYPE_KEYWORD", "IF_KEYWORD", "ELSEIF_KEYWORD",
  "ELSE_KEYWORD", "FOR_KEYWORD", "WHILE_KEYWORD", "SWITCH_KEYWORD",
  "MAIN_KEYWORD", "DO_KEYWORD", "RETURN_KEYWORD", "CASE_KEYWORD",
  "CONST_KEYWORD", "BREAK_KEYWORD", "CONTINUE_KEYWORD", "DEFAULT_KEYWORD",
  "AND_KEYWORD", "OR_KEYWORD", "NOT_KEYWORD", "OPENING_CURLY_BRACE",
  "CLOSING_CURLY_BRACE", "OPENING_PARENTHESIS", "CLOSING_PARENTHESIS",
  "OPENING_SQUARE_BRACKETS", "CLOSING_SQUARE_BRACKETS", "COMMA", "ASTRISK",
  "PLUS", "MINUS", "DIVIDE", "MODULO", "INCREMENT", "DECREMENT",
  "ASSIGNMENT", "EQUAL", "NOT_EQUAL", "LESS_OR_EQUAL", "GREATER_OR_EQUAL",
  "LESS", "GREATER", "BITWISE_AND", "BITWISE_OR", "BITWISE_XOR",
  "BITWISE_NOT", "COLON", "SEMICOLON", "UNRECOGNIZED_TOKEN",
  "RESERVED_IDENTIFIER", "$accept", "program", "functions", "function",
  "function_arguments", "type_identifier", "type", "body", "statements",
  "statement", "if_statement", "elseif_statement", "else_statement",
  "for_statement", "loop_start", "loop_update", "while_statement",
  "do_while_statement", "switch_statement", "default_case", "case_list",
  "case_statement", "initialization", "const_initialization",
  "variable_declaration", "const_variable_declaration", "return_statement",
  "assignment", "expression", "array_element", "expr_list",
  "function_call", "boolean_expr", "arithmetic_expr", "unary_expr",
  "binary_expr", "arithmetic_term", "arithmetic_factor", "bitwise_expr",
  "bitwise_xor_expr", "bitwise_and_expr", "bitwise_not_expr",
  "main_function", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-202)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     343,  -202,  -202,  -202,  -202,  -202,    26,    11,    44,   343,
      65,    13,  -202,    37,  -202,  -202,    69,    42,    70,   254,
      79,   105,  -202,   147,    79,    79,   123,   119,  -202,    79,
     107,  -202,  -202,  -202,    79,  -202,  -202,  -202,  -202,  -202,
      62,   129,   138,   142,   149,    79,   174,   107,    22,   174,
      38,     5,  -202,   -29,   178,    55,   155,   119,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,   144,
    -202,  -202,  -202,  -202,  -202,    39,   106,  -202,   146,   148,
     151,  -202,  -202,  -202,  -202,    35,   203,  -202,  -202,   174,
     174,   350,   174,   193,   190,   120,   184,    56,   176,   174,
    -202,   246,  -202,   209,  -202,   208,   174,  -202,    69,  -202,
    -202,  -202,    59,    59,    59,    59,    59,    59,    59,    59,
    -202,    41,    41,    41,    41,     1,     5,     5,     5,  -202,
     291,   124,   183,   198,   291,   186,   179,    32,   164,  -202,
    -202,   189,   191,   204,  -202,   234,   174,  -202,   253,    91,
     206,   216,   210,    14,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,   174,   106,   106,  -202,  -202,  -202,   174,   148,   151,
    -202,  -202,   174,  -202,  -202,    79,   251,   174,    79,   223,
     174,   240,   222,  -202,  -202,  -202,  -202,   -27,  -202,   277,
     284,   291,   262,   242,   226,  -202,   261,   252,   -21,  -202,
     250,  -202,  -202,  -202,   256,   274,   263,   300,   289,    71,
    -202,   241,   275,  -202,   174,   174,    79,  -202,   -18,   280,
    -202,   259,   260,  -202,   285,  -202,  -202,   174,   130,   287,
    -202,   174,    79,   119,   119,  -202,   133,   265,    79,   291,
    -202,  -202,  -202,   272,  -202,  -202,  -202
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,    12,    13,    14,    15,    16,     0,     0,     0,     4,
       0,     0,     1,     0,     2,     3,     0,     0,     0,     0,
       0,     0,     9,     0,     0,     0,     0,    19,     8,     0,
       0,    11,   122,     7,     0,   121,   111,    68,    67,    93,
     112,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,     0,     0,     0,     0,    19,    28,    29,
      30,    31,    32,    24,    26,    25,    27,    22,    21,     0,
      69,    66,    64,    65,    95,    94,   104,   109,   110,   115,
     117,   119,     6,    10,     5,     0,     0,    96,    97,     0,
       0,    42,     0,     0,     0,   112,     0,     0,     0,     0,
      92,     0,    98,     0,   120,     0,     0,    58,    11,    20,
      17,    18,     0,     0,     0,     0,     0,     0,     0,     0,
      23,     0,     0,     0,     0,     0,     0,     0,     0,    74,
      71,     0,     0,     0,     0,    64,     0,     0,     0,    41,
      40,    64,     0,     0,    62,     0,     0,    60,     0,   113,
       0,     0,     0,   112,    88,    87,    90,    89,    76,    75,
      78,    77,    82,    81,    80,    79,    86,    85,    84,    83,
     112,     0,   102,   103,   105,   106,   107,     0,   114,   116,
     118,    73,     0,    70,    63,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    99,   100,   101,     0,    54,     0,
       0,    72,    36,     0,    64,    46,     0,    64,     0,    56,
       0,    59,   113,   108,     0,    38,     0,    45,     0,     0,
      52,     0,     0,    61,     0,     0,     0,    34,     0,     0,
      44,     0,     0,    48,     0,    51,    47,     0,     0,    64,
      37,     0,     0,    19,    19,    49,     0,     0,     0,    43,
      39,    53,    50,     0,    55,    35,    57
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -202,  -202,   301,   101,   318,     3,     0,   -19,   -54,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,   145,   276,  -202,  -202,  -202,  -202,   278,   -25,  -202,
    -201,   -30,   -78,   232,  -202,  -202,    63,    74,  -202,   239,
     243,   -38,  -202
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     7,     8,    52,    21,    53,    23,    55,    56,    57,
      58,   215,   227,    59,   138,   229,    60,    61,    62,   234,
     219,   220,    63,    64,    65,    66,    67,    68,   134,    70,
     131,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    14
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      10,    28,    69,   111,   176,    32,    33,   105,    35,    10,
      82,    12,   135,   104,   141,    84,    85,   106,   100,   210,
      22,    96,    22,   238,   101,   222,    94,    54,   241,   107,
      98,   211,    69,    83,    11,   177,   246,   223,    35,    36,
      37,    38,    39,    95,    35,    36,   102,    17,    85,   170,
      97,     1,     2,     3,     4,     5,    99,    54,    87,    88,
     130,    51,    35,    36,   133,    13,    48,   153,   186,    49,
     129,    18,   103,    16,   148,   171,    50,    20,   106,   121,
     122,   152,   154,   156,   158,   160,   162,   164,   166,   168,
     180,    51,   145,    49,   137,   218,    85,    51,    86,   232,
      50,     9,   146,    19,   233,    24,    87,    88,    89,   204,
       9,    27,   207,   109,   147,    51,     1,     2,     3,     4,
       5,   192,    35,    36,    37,    38,    39,    40,     1,     2,
       3,     4,     5,     6,    41,   194,   195,    42,    43,    44,
      29,    45,    46,    30,    47,   123,   199,   239,   124,   125,
      48,    27,   200,    49,    85,    31,    86,   201,    34,   181,
      50,    30,   182,    90,    87,    88,   202,   247,   182,   205,
     253,   182,    91,   112,   113,    51,    92,    35,    36,    37,
      38,    39,    95,    93,   172,   173,   108,   230,   110,   251,
     252,   114,   115,   116,   117,   118,   119,   174,   175,   130,
     126,   142,   120,   127,   128,    48,   132,   240,    49,   143,
      85,   151,   130,   112,   113,    50,   249,   150,    69,    69,
     183,   185,   187,   250,   188,    89,   189,   112,   113,   255,
      51,   114,   115,   116,   117,   118,   119,   191,   190,   112,
     113,   196,   144,    54,    54,   114,   115,   116,   117,   118,
     119,   112,   113,   197,   203,   206,   184,   114,   115,   116,
     117,   118,   119,     1,     2,     3,     4,     5,   198,   114,
     115,   116,   117,   118,   119,   112,   113,   208,   214,   216,
     209,   149,   112,   113,   217,   218,   224,   221,   193,    25,
     225,   226,   231,   114,   115,   116,   117,   118,   119,   236,
     114,   115,   116,   117,   118,   119,   112,   113,   228,   210,
      15,   237,   212,   112,   113,   242,   243,   244,   245,   213,
     112,   113,   248,   254,   114,   115,   116,   117,   118,   119,
     256,   114,   115,   116,   117,   118,   119,    26,   114,   115,
     116,   117,   118,   119,   155,   157,   159,   161,   163,   165,
     167,   169,     1,     2,     3,     4,     5,     6,   136,     1,
       2,     3,     4,     5,   235,   178,     0,   139,     0,   140,
     179
};

static const yytype_int16 yycheck[] =
{
       0,    20,    27,    57,     3,    24,    25,    36,     3,     9,
      29,     0,    90,    51,    92,    34,    34,    46,    48,    46,
      17,    46,    19,   224,    49,    46,    45,    27,    46,    58,
       8,    58,    57,    30,     8,    34,   237,    58,     3,     4,
       5,     6,     7,     8,     3,     4,     8,    34,    34,     8,
      47,     9,    10,    11,    12,    13,    34,    57,    44,    45,
      85,    56,     3,     4,    89,    21,    31,     8,    36,    34,
      35,    34,    34,     8,    99,    34,    41,    35,    46,    40,
      41,   106,   112,   113,   114,   115,   116,   117,   118,   119,
     128,    56,    36,    34,    91,    24,    34,    56,    36,    28,
      41,     0,    46,    34,    33,    35,    44,    45,    46,   187,
       9,    32,   190,    58,    58,    56,     9,    10,    11,    12,
      13,   146,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    44,    45,    18,    19,    20,
      35,    22,    23,    38,    25,    39,   171,   225,    42,    43,
      31,    32,   177,    34,    34,     8,    36,   182,    35,    35,
      41,    38,    38,    34,    44,    45,   185,    37,    38,   188,
      37,    38,    34,    29,    30,    56,    34,     3,     4,     5,
       6,     7,     8,    34,   121,   122,     8,   217,    33,   243,
     244,    47,    48,    49,    50,    51,    52,   123,   124,   224,
      54,     8,    58,    55,    53,    31,     3,   226,    34,    19,
      34,     3,   237,    29,    30,    41,   241,     8,   243,   244,
      37,    35,    58,   242,    35,    46,    35,    29,    30,   248,
      56,    47,    48,    49,    50,    51,    52,     3,    34,    29,
      30,    35,    58,   243,   244,    47,    48,    49,    50,    51,
      52,    29,    30,    37,     3,    32,    58,    47,    48,    49,
      50,    51,    52,     9,    10,    11,    12,    13,    58,    47,
      48,    49,    50,    51,    52,    29,    30,    37,    16,    37,
      58,    35,    29,    30,    58,    24,    36,    35,    35,    35,
      34,    17,     3,    47,    48,    49,    50,    51,    52,    58,
      47,    48,    49,    50,    51,    52,    29,    30,     8,    46,
       9,    36,    35,    29,    30,    35,    57,    57,    33,    35,
      29,    30,    35,    58,    47,    48,    49,    50,    51,    52,
      58,    47,    48,    49,    50,    51,    52,    19,    47,    48,
      49,    50,    51,    52,   112,   113,   114,   115,   116,   117,
     118,   119,     9,    10,    11,    12,    13,    14,     8,     9,
      10,    11,    12,    13,   219,   126,    -1,    91,    -1,    91,
     127
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    10,    11,    12,    13,    14,    62,    63,    64,
      67,     8,     0,    21,   103,    63,     8,    34,    34,    34,
      35,    65,    66,    67,    35,    35,    65,    32,    68,    35,
      38,     8,    68,    68,    35,     3,     4,     5,     6,     7,
       8,    15,    18,    19,    20,    22,    23,    25,    31,    34,
      41,    56,    64,    66,    67,    68,    69,    70,    71,    74,
      77,    78,    79,    83,    84,    85,    86,    87,    88,    89,
      90,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    68,    66,    68,    34,    36,    44,    45,    46,
      34,    34,    34,    34,    68,     8,    89,    66,     8,    34,
      92,    89,     8,    34,   102,    36,    46,    58,     8,    58,
      33,    69,    29,    30,    47,    48,    49,    50,    51,    52,
      58,    40,    41,    39,    42,    43,    54,    55,    53,    35,
      89,    91,     3,    89,    89,    93,     8,    66,    75,    83,
      88,    93,     8,    19,    58,    36,    46,    58,    89,    35,
       8,     3,    89,     8,    92,    94,    92,    94,    92,    94,
      92,    94,    92,    94,    92,    94,    92,    94,    92,    94,
       8,    34,    97,    97,    98,    98,     3,    34,   100,   101,
     102,    35,    38,    37,    58,    35,    36,    58,    35,    35,
      34,     3,    89,    35,    44,    45,    35,    37,    58,    89,
      89,    89,    68,     3,    93,    68,    32,    93,    37,    58,
      46,    58,    35,    35,    16,    72,    37,    58,    24,    81,
      82,    35,    46,    58,    36,    34,    17,    73,     8,    76,
      92,     3,    28,    33,    80,    82,    58,    36,    91,    93,
      68,    46,    35,    57,    57,    33,    91,    37,    35,    89,
      68,    69,    69,    37,    58,    68,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    63,    63,    64,    64,    64,    64,    65,
      65,    66,    67,    67,    67,    67,    67,    68,    69,    69,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    71,    72,    72,    73,    73,    74,
      75,    75,    75,    76,    76,    76,    77,    78,    79,    79,
      80,    81,    81,    82,    83,    83,    84,    84,    85,    85,
      86,    86,    87,    88,    89,    89,    89,    89,    89,    89,
      90,    91,    91,    92,    92,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    94,    94,    95,    95,    95,    95,
      95,    95,    96,    96,    96,    97,    97,    97,    97,    97,
      98,    98,    98,    98,    99,    99,   100,   100,   101,   101,
     102,   102,   103
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     6,     6,     5,     5,     1,
       3,     2,     1,     1,     1,     1,     1,     3,     2,     0,
       2,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     7,     5,     0,     2,     0,     9,
       1,     1,     0,     3,     1,     0,     5,     7,     7,     8,
       3,     2,     1,     4,     4,     9,     5,    10,     2,     5,
       3,     6,     3,     4,     1,     1,     1,     1,     1,     1,
       4,     1,     3,     4,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     2,     1,     1,     1,     2,     2,     2,     4,
       4,     4,     3,     3,     1,     3,     3,     3,     5,     1,
       1,     1,     1,     3,     3,     1,     3,     1,     3,     1,
       2,     1,     4
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

#line 1380 "parser.tab.c"

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

#line 299 "parser.y"

