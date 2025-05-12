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
#include "symbol_table.h"
#include "ir.h"

void yyerror(const char *s);
int yylex(void);
extern FILE* yyin;
extern scope_no;
extern yylineno;

SymbolTable* symbol_table = create_symbol_table();
Parameter* curr_function_parameter_list = NULL;
Parameter* curr_function_parameter_list_ptr = NULL;
Parameter* curr_function_instructions_list = NULL;
int inside_a_function_declaration_body = 0;

#line 91 "parser.tab.c"

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
  YYSYMBOL_63_1 = 63,                      /* $@1  */
  YYSYMBOL_functions = 64,                 /* functions  */
  YYSYMBOL_function = 65,                  /* function  */
  YYSYMBOL_66_2 = 66,                      /* $@2  */
  YYSYMBOL_67_3 = 67,                      /* $@3  */
  YYSYMBOL_68_4 = 68,                      /* $@4  */
  YYSYMBOL_69_5 = 69,                      /* $@5  */
  YYSYMBOL_70_6 = 70,                      /* $@6  */
  YYSYMBOL_71_7 = 71,                      /* $@7  */
  YYSYMBOL_function_arguments = 72,        /* function_arguments  */
  YYSYMBOL_type_identifier = 73,           /* type_identifier  */
  YYSYMBOL_type = 74,                      /* type  */
  YYSYMBOL_body = 75,                      /* body  */
  YYSYMBOL_76_8 = 76,                      /* $@8  */
  YYSYMBOL_statements = 77,                /* statements  */
  YYSYMBOL_statement = 78,                 /* statement  */
  YYSYMBOL_if_statement = 79,              /* if_statement  */
  YYSYMBOL_elseif_statement = 80,          /* elseif_statement  */
  YYSYMBOL_else_statement = 81,            /* else_statement  */
  YYSYMBOL_for_statement = 82,             /* for_statement  */
  YYSYMBOL_loop_start = 83,                /* loop_start  */
  YYSYMBOL_loop_update = 84,               /* loop_update  */
  YYSYMBOL_85_9 = 85,                      /* $@9  */
  YYSYMBOL_while_statement = 86,           /* while_statement  */
  YYSYMBOL_do_while_statement = 87,        /* do_while_statement  */
  YYSYMBOL_switch_statement = 88,          /* switch_statement  */
  YYSYMBOL_89_10 = 89,                     /* $@10  */
  YYSYMBOL_90_11 = 90,                     /* $@11  */
  YYSYMBOL_default_case = 91,              /* default_case  */
  YYSYMBOL_case_list = 92,                 /* case_list  */
  YYSYMBOL_case_statement = 93,            /* case_statement  */
  YYSYMBOL_initialization = 94,            /* initialization  */
  YYSYMBOL_95_12 = 95,                     /* $@12  */
  YYSYMBOL_96_13 = 96,                     /* $@13  */
  YYSYMBOL_const_initialization = 97,      /* const_initialization  */
  YYSYMBOL_98_14 = 98,                     /* $@14  */
  YYSYMBOL_99_15 = 99,                     /* $@15  */
  YYSYMBOL_variable_declaration = 100,     /* variable_declaration  */
  YYSYMBOL_101_16 = 101,                   /* $@16  */
  YYSYMBOL_102_17 = 102,                   /* $@17  */
  YYSYMBOL_const_variable_declaration = 103, /* const_variable_declaration  */
  YYSYMBOL_104_18 = 104,                   /* $@18  */
  YYSYMBOL_105_19 = 105,                   /* $@19  */
  YYSYMBOL_return_statement = 106,         /* return_statement  */
  YYSYMBOL_assignment = 107,               /* assignment  */
  YYSYMBOL_108_20 = 108,                   /* $@20  */
  YYSYMBOL_expression = 109,               /* expression  */
  YYSYMBOL_array_element = 110,            /* array_element  */
  YYSYMBOL_expr_list = 111,                /* expr_list  */
  YYSYMBOL_function_call = 112,            /* function_call  */
  YYSYMBOL_boolean_expr = 113,             /* boolean_expr  */
  YYSYMBOL_arithmetic_expr = 114,          /* arithmetic_expr  */
  YYSYMBOL_unary_expr = 115,               /* unary_expr  */
  YYSYMBOL_binary_expr = 116,              /* binary_expr  */
  YYSYMBOL_arithmetic_term = 117,          /* arithmetic_term  */
  YYSYMBOL_arithmetic_factor = 118,        /* arithmetic_factor  */
  YYSYMBOL_bitwise_expr = 119,             /* bitwise_expr  */
  YYSYMBOL_bitwise_xor_expr = 120,         /* bitwise_xor_expr  */
  YYSYMBOL_bitwise_and_expr = 121,         /* bitwise_and_expr  */
  YYSYMBOL_bitwise_not_expr = 122,         /* bitwise_not_expr  */
  YYSYMBOL_main_function = 123             /* main_function  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   400

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  141
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  279

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
       0,   102,   102,   102,   106,   107,   110,   113,   110,   126,
     129,   126,   141,   141,   152,   152,   166,   178,   187,   194,
     195,   196,   197,   198,   201,   201,   216,   218,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   237,   240,   241,   244,   245,   248,   251,   252,
     253,   256,   256,   264,   265,   268,   271,   274,   282,   274,
     285,   288,   289,   292,   296,   296,   304,   304,   314,   314,
     323,   323,   334,   334,   343,   343,   354,   354,   363,   363,
     375,   379,   379,   389,   390,   391,   392,   393,   394,   397,
     400,   401,   404,   405,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   430,   431,   434,   435,   436,   437,   438,
     439,   443,   444,   445,   448,   449,   450,   451,   452,   455,
     456,   457,   458,   461,   462,   464,   465,   468,   469,   472,
     473,   479
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
  "RESERVED_IDENTIFIER", "$accept", "program", "$@1", "functions",
  "function", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7",
  "function_arguments", "type_identifier", "type", "body", "$@8",
  "statements", "statement", "if_statement", "elseif_statement",
  "else_statement", "for_statement", "loop_start", "loop_update", "$@9",
  "while_statement", "do_while_statement", "switch_statement", "$@10",
  "$@11", "default_case", "case_list", "case_statement", "initialization",
  "$@12", "$@13", "const_initialization", "$@14", "$@15",
  "variable_declaration", "$@16", "$@17", "const_variable_declaration",
  "$@18", "$@19", "return_statement", "assignment", "$@20", "expression",
  "array_element", "expr_list", "function_call", "boolean_expr",
  "arithmetic_expr", "unary_expr", "binary_expr", "arithmetic_term",
  "arithmetic_factor", "bitwise_expr", "bitwise_xor_expr",
  "bitwise_and_expr", "bitwise_not_expr", "main_function", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-218)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-82)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -218,    39,    91,  -218,  -218,  -218,  -218,  -218,  -218,    37,
      43,    91,    76,    77,    92,  -218,  -218,    96,    98,   111,
     113,  -218,   126,  -218,  -218,   126,  -218,     2,  -218,   148,
    -218,   125,  -218,    48,  -218,  -218,   126,  -218,   109,  -218,
    -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,    45,   139,
     140,   142,   144,  -218,   164,   126,    14,   164,    15,    13,
    -218,   -16,   171,   122,   151,   240,  -218,  -218,  -218,  -218,
    -218,  -218,  -218,  -218,  -218,  -218,  -218,   237,  -218,  -218,
    -218,  -218,  -218,    19,   102,  -218,   131,   133,   136,  -218,
    -218,  -218,   156,   183,  -218,  -218,   146,   164,   218,   164,
     185,   175,   -10,   250,    -6,   162,   164,  -218,   310,  -218,
     198,  -218,   161,   172,   153,   177,    96,  -218,  -218,  -218,
       9,     9,     9,     9,     9,     9,     9,     9,  -218,    24,
      24,    24,    24,    12,    13,    13,    13,  -218,  -218,   152,
      50,   178,   164,   152,   181,  -218,   182,   159,  -218,  -218,
     186,  -218,   189,  -218,   187,   188,   176,   201,   317,    10,
     204,   164,   238,  -218,   239,    17,  -218,  -218,  -218,  -218,
    -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,
    -218,  -218,  -218,   164,   102,   102,  -218,  -218,  -218,   164,
     133,   136,  -218,  -218,   164,  -218,   262,  -218,   164,  -218,
     205,   164,   164,   253,  -218,   254,  -218,  -218,  -218,  -218,
     274,   224,   227,   341,   348,   152,  -218,   252,   215,  -218,
     243,   241,   286,   245,   246,  -218,   231,   220,  -218,  -218,
     256,   276,   297,  -218,   236,  -218,   260,   249,   281,  -218,
     164,  -218,  -218,   162,   283,  -218,   295,  -218,   291,  -218,
     164,   293,  -218,   284,  -218,   326,    29,  -218,   164,    71,
    -218,   164,  -218,   285,   292,   298,  -218,   114,   290,  -218,
     152,   240,   109,  -218,   296,  -218,  -218,  -218,  -218
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     5,     1,    19,    20,    21,    22,    23,     0,
       0,     5,     0,     0,     0,     3,     4,     0,     9,     0,
       6,    14,     0,    24,    12,     0,    24,     0,    16,     0,
     141,     0,    24,     0,    15,    10,     0,    18,    24,    13,
       7,    24,    17,   140,   130,    87,    86,   112,   131,     0,
       0,     0,     0,    24,     0,     0,     0,     0,     0,     0,
      41,    64,     0,     0,     0,    27,    36,    37,    38,    39,
      40,    32,    34,    33,    35,    30,    29,     0,    88,    85,
      83,    84,   114,   113,   123,   128,   129,   134,   136,   138,
      24,    11,     0,     0,   115,   116,     0,     0,    50,     0,
       0,     0,   131,     0,    68,     0,     0,   111,     0,   117,
       0,   139,     0,     0,     0,     0,    18,    28,    25,    26,
       0,     0,     0,     0,     0,     0,     0,     0,    31,     0,
       0,     0,     0,     0,     0,     0,     0,     8,    93,    90,
       0,     0,     0,     0,    83,    81,    64,     0,    49,    48,
      83,    57,     0,    80,     0,     0,     0,     0,     0,   132,
       0,     0,     0,    73,     0,   131,   107,   106,   109,   108,
      95,    94,    97,    96,   101,   100,    99,    98,   105,   104,
     103,   102,   131,     0,   121,   122,   124,   125,   126,     0,
     133,   135,   137,    92,     0,    89,     0,    24,     0,    24,
       0,     0,     0,     0,    77,     0,   110,   118,   119,   120,
       0,     0,     0,     0,     0,    91,    82,    44,    83,    55,
       0,    83,     0,     0,     0,    65,     0,     0,   132,   127,
       0,    46,    54,    58,     0,    69,     0,     0,     0,    75,
       0,    24,    42,    51,     0,    53,     0,    56,     0,    79,
       0,    83,    45,     0,    24,     0,     0,    62,     0,     0,
      24,     0,    47,     0,     0,     0,    61,     0,     0,    43,
      52,    27,    24,    59,     0,    67,    63,    60,    71
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -218,  -218,  -218,   330,    36,  -218,  -218,  -218,  -218,  -218,
    -218,   318,   -11,    -2,   -22,  -218,   -62,  -218,  -218,  -218,
    -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,
    -218,  -218,    94,   255,  -218,  -218,  -218,  -218,  -218,  -218,
    -218,  -218,  -218,  -218,  -218,  -218,   257,  -218,   -36,  -218,
    -217,   -49,   -91,   -28,  -218,  -218,   -63,    23,  -218,   217,
     221,   -54,  -218
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,    10,    60,    25,    90,    22,    41,    32,
      26,    27,    61,    29,    63,    31,    64,    65,    66,   231,
     242,    67,   147,   244,   253,    68,    69,    70,   200,   246,
     265,   256,   257,    71,   112,   113,    72,   154,   155,    73,
     114,   115,    74,   156,   157,    75,    76,    96,   143,    78,
     140,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    15
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      12,    30,    77,   119,    34,   111,   144,   107,   150,    12,
      39,    28,    43,    44,    28,   188,    43,   165,   103,    91,
     -66,   108,   105,   109,    92,    42,    93,    43,    44,    77,
     -70,   101,   182,   259,    94,    95,    62,    35,    11,     3,
      36,   267,   -72,    57,   104,    13,   189,    11,   106,   110,
      58,    92,   -76,   255,   207,   208,   139,   264,   183,   129,
     130,    94,    95,    62,    14,    59,   184,   185,   137,    59,
     158,   166,   168,   170,   172,   174,   176,   178,   180,    92,
      59,    93,   192,    40,    17,   193,    36,   146,   194,    94,
      95,   -81,   167,   169,   171,   173,   175,   177,   179,   181,
       4,     5,     6,     7,     8,     9,   196,   218,   268,   194,
     221,    18,    43,    44,    45,    46,    47,    48,     4,     5,
       6,     7,     8,     9,    49,   210,    19,    50,    51,    52,
      20,    53,    54,    21,    55,     4,     5,     6,     7,     8,
      56,   131,   -27,    57,   132,   133,    23,   213,    24,   251,
      58,   274,   194,   214,   186,   187,    37,    38,   215,    43,
      44,    45,    46,    47,   102,    59,   222,    43,    44,    45,
      46,    47,   102,    97,    98,   217,    99,   219,   100,   116,
     117,   120,   121,   245,   118,   134,   141,    56,   135,   136,
      57,   138,   142,   151,   152,    56,    92,    58,    57,   122,
     123,   124,   125,   126,   127,    58,   160,   161,   162,   276,
     277,   163,    59,   164,   139,   195,   197,   198,   -66,   252,
      59,   199,   139,   201,   203,   270,   145,     4,     5,     6,
       7,     8,   262,   202,   204,    77,    77,   205,   269,   209,
     220,   211,   212,    43,    44,    45,    46,    47,    48,     4,
       5,     6,     7,     8,     9,    49,   223,   224,    50,    51,
      52,   226,    53,    54,   227,    55,   120,   121,   230,    62,
      62,    56,   -24,   232,    57,   233,   234,   238,   239,   120,
     121,    58,   236,   237,   122,   123,   124,   125,   126,   127,
     240,   120,   121,   241,   247,   128,    59,   122,   123,   124,
     125,   126,   127,   120,   121,   243,   248,   249,   153,   122,
     123,   124,   125,   126,   127,   120,   121,   250,   254,   255,
     216,   122,   123,   124,   125,   126,   127,   258,   260,   263,
     261,   273,   225,   122,   123,   124,   125,   126,   127,   120,
     121,    16,   271,    33,   235,   159,   120,   121,   275,   272,
     266,   190,   206,   148,   278,   149,   191,   122,   123,   124,
     125,   126,   127,     0,   122,   123,   124,   125,   126,   127,
     120,   121,     0,     0,     0,     0,   228,   120,   121,     0,
       0,     0,     0,   229,     0,     0,     0,     0,   122,   123,
     124,   125,   126,   127,     0,   122,   123,   124,   125,   126,
     127
};

static const yytype_int16 yycheck[] =
{
       2,    23,    38,    65,    26,    59,    97,    56,    99,    11,
      32,    22,     3,     4,    25,     3,     3,     8,    54,    41,
      36,    57,     8,     8,    34,    36,    36,     3,     4,    65,
      36,    53,     8,   250,    44,    45,    38,    35,     2,     0,
      38,   258,    58,    34,    55,     8,    34,    11,    34,    34,
      41,    34,    58,    24,    44,    45,    92,    28,    34,    40,
      41,    44,    45,    65,    21,    56,   129,   130,    90,    56,
     106,   120,   121,   122,   123,   124,   125,   126,   127,    34,
      56,    36,   136,    35,     8,    35,    38,    98,    38,    44,
      45,    46,   120,   121,   122,   123,   124,   125,   126,   127,
       9,    10,    11,    12,    13,    14,   142,   198,    37,    38,
     201,    34,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,   161,    34,    18,    19,    20,
      34,    22,    23,    35,    25,     9,    10,    11,    12,    13,
      31,    39,    33,    34,    42,    43,    35,   183,    35,   240,
      41,    37,    38,   189,   131,   132,     8,    32,   194,     3,
       4,     5,     6,     7,     8,    56,   202,     3,     4,     5,
       6,     7,     8,    34,    34,   197,    34,   199,    34,     8,
      58,    29,    30,   232,    33,    54,     3,    31,    55,    53,
      34,    35,    46,     8,    19,    31,    34,    41,    34,    47,
      48,    49,    50,    51,    52,    41,     8,    46,    36,   271,
     272,    58,    56,    36,   250,    37,    35,    58,    36,   241,
      56,    35,   258,    34,    36,   261,     8,     9,    10,    11,
      12,    13,   254,    46,    58,   271,   272,    36,   260,    35,
      35,     3,     3,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     3,     3,    18,    19,
      20,    37,    22,    23,    37,    25,    29,    30,    16,   271,
     272,    31,    32,    58,    34,    32,    35,    46,    58,    29,
      30,    41,    37,    37,    47,    48,    49,    50,    51,    52,
      34,    29,    30,    17,    58,    58,    56,    47,    48,    49,
      50,    51,    52,    29,    30,     8,    46,    58,    58,    47,
      48,    49,    50,    51,    52,    29,    30,    36,    35,    24,
      58,    47,    48,    49,    50,    51,    52,    36,    35,     3,
      46,    33,    58,    47,    48,    49,    50,    51,    52,    29,
      30,    11,    57,    25,    58,    35,    29,    30,    58,    57,
     256,   134,    35,    98,    58,    98,   135,    47,    48,    49,
      50,    51,    52,    -1,    47,    48,    49,    50,    51,    52,
      29,    30,    -1,    -1,    -1,    -1,    35,    29,    30,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    52,    -1,    47,    48,    49,    50,    51,
      52
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    62,    63,     0,     9,    10,    11,    12,    13,    14,
      64,    65,    74,     8,    21,   123,    64,     8,    34,    34,
      34,    35,    68,    35,    35,    66,    71,    72,    73,    74,
      75,    76,    70,    72,    75,    35,    38,     8,    32,    75,
      35,    69,    73,     3,     4,     5,     6,     7,     8,    15,
      18,    19,    20,    22,    23,    25,    31,    34,    41,    56,
      65,    73,    74,    75,    77,    78,    79,    82,    86,    87,
      88,    94,    97,   100,   103,   106,   107,   109,   110,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
      67,    75,    34,    36,    44,    45,   108,    34,    34,    34,
      34,    75,     8,   109,    73,     8,    34,   112,   109,     8,
      34,   122,    95,    96,   101,   102,     8,    58,    33,    77,
      29,    30,    47,    48,    49,    50,    51,    52,    58,    40,
      41,    39,    42,    43,    54,    55,    53,    75,    35,   109,
     111,     3,    46,   109,   113,     8,    73,    83,    94,   107,
     113,     8,    19,    58,    98,    99,   104,   105,   109,    35,
       8,    46,    36,    58,    36,     8,   112,   114,   112,   114,
     112,   114,   112,   114,   112,   114,   112,   114,   112,   114,
     112,   114,     8,    34,   117,   117,   118,   118,     3,    34,
     120,   121,   122,    35,    38,    37,   109,    35,    58,    35,
      89,    34,    46,    36,    58,    36,    35,    44,    45,    35,
     109,     3,     3,   109,   109,   109,    58,    75,   113,    75,
      35,   113,   109,     3,     3,    58,    37,    37,    35,    35,
      16,    80,    58,    32,    35,    58,    37,    37,    46,    58,
      34,    17,    81,     8,    84,   112,    90,    58,    46,    58,
      36,   113,    75,    85,    35,    24,    92,    93,    36,   111,
      35,    46,    75,     3,    28,    91,    93,   111,    37,    75,
     109,    57,    57,    33,    37,    58,    77,    77,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    63,    62,    64,    64,    66,    67,    65,    68,
      69,    65,    70,    65,    71,    65,    72,    72,    73,    74,
      74,    74,    74,    74,    76,    75,    77,    77,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    79,    80,    80,    81,    81,    82,    83,    83,
      83,    85,    84,    84,    84,    86,    87,    89,    90,    88,
      91,    92,    92,    93,    95,    94,    96,    94,    98,    97,
      99,    97,   101,   100,   102,   100,   104,   103,   105,   103,
     106,   108,   107,   109,   109,   109,   109,   109,   109,   110,
     111,   111,   112,   112,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   114,   114,   115,   115,   115,   115,   115,
     115,   116,   116,   116,   117,   117,   117,   117,   117,   118,
     118,   118,   118,   119,   119,   120,   120,   121,   121,   122,
     122,   123
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     2,     0,     0,     0,     8,     0,
       0,     8,     0,     6,     0,     6,     1,     3,     2,     1,
       1,     1,     1,     1,     0,     4,     2,     0,     2,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     7,     5,     0,     2,     0,     9,     1,     1,
       0,     0,     4,     1,     0,     5,     7,     0,     0,    10,
       3,     2,     1,     4,     0,     5,     0,    10,     0,     6,
       0,    11,     0,     3,     0,     6,     0,     4,     0,     7,
       3,     0,     5,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     2,     1,     1,     1,     2,     2,     2,     4,     4,
       4,     3,     3,     1,     3,     3,     3,     5,     1,     1,
       1,     1,     3,     3,     1,     3,     1,     3,     1,     2,
       1,     4
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
  case 2: /* $@1: %empty  */
#line 102 "parser.y"
    { scope_no++; }
#line 1435 "parser.tab.c"
    break;

  case 3: /* program: $@1 functions main_function  */
#line 102 "parser.y"
                                            { delete_scope(symbol_table, scope_no); scope_no--;}
#line 1441 "parser.tab.c"
    break;

  case 6: /* $@2: %empty  */
#line 110 "parser.y"
                                              { 
            curr_function_parameter_list = NULL; 
          }
#line 1449 "parser.tab.c"
    break;

  case 7: /* $@3: %empty  */
#line 113 "parser.y"
                                                  { 
            inside_a_function_declaration_body = 1;
            curr_function_instructions_list = NULL;  
          }
#line 1458 "parser.tab.c"
    break;

  case 8: /* function: type IDENTIFIER OPENING_PARENTHESIS $@2 function_arguments CLOSING_PARENTHESIS $@3 body  */
#line 117 "parser.y"
               {
            Value val;
            val.function = (yyvsp[0].instruction);  
            insert_symbol(symbol_table, (yyvsp[-6].sval), (yyvsp[-7].sval), val, FUNCTION, scope_no, 1, (yyvsp[-3].param_list), yylineno, 0);
            inside_a_function_declaration_body = 0;
            curr_function_parameter_list = NULL;
            curr_function_parameter_list_ptr = NULL;
            curr_function_instructions_list = NULL;
          }
#line 1472 "parser.tab.c"
    break;

  case 9: /* $@4: %empty  */
#line 126 "parser.y"
                                                           { 
            curr_function_parameter_list = NULL; 
          }
#line 1480 "parser.tab.c"
    break;

  case 10: /* $@5: %empty  */
#line 129 "parser.y"
                                                 { 
            inside_a_function_declaration_body = 1;
            curr_function_instructions_list = NULL;  
          }
#line 1489 "parser.tab.c"
    break;

  case 11: /* function: VOID_TYPE_KEYWORD IDENTIFIER OPENING_PARENTHESIS $@4 function_arguments CLOSING_PARENTHESIS $@5 body  */
#line 133 "parser.y"
               { 
            Value val;
            val.function = (yyvsp[0].instruction);
            insert_symbol(symbol_table, (yyvsp[-6].sval), (yyvsp[-7].sval), val, FUNCTION, scope_no, 1, (yyvsp[-3].param_list), yylineno, 0);
            inside_a_function_declaration_body = 0;
            curr_function_parameter_list = NULL;
            curr_function_parameter_list_ptr = NULL; 
          }
#line 1502 "parser.tab.c"
    break;

  case 12: /* $@6: %empty  */
#line 141 "parser.y"
                                                                  { 
            inside_a_function_declaration_body = 1;
            curr_function_instructions_list = NULL;  
          }
#line 1511 "parser.tab.c"
    break;

  case 13: /* function: type IDENTIFIER OPENING_PARENTHESIS CLOSING_PARENTHESIS $@6 body  */
#line 145 "parser.y"
               { 
            Value val;
            val.function = (yyvsp[0].instruction);
            insert_symbol(symbol_table, (yyvsp[-4].sval), (yyvsp[-5].sval), val, FUNCTION, scope_no, 1, NULL, yylineno, 0);
            inside_a_function_declaration_body = 0;
            curr_function_instructions_list = NULL; 
          }
#line 1523 "parser.tab.c"
    break;

  case 14: /* $@7: %empty  */
#line 152 "parser.y"
                                                                               { 
            inside_a_function_declaration_body = 1;
            curr_function_instructions_list = NULL;  
          }
#line 1532 "parser.tab.c"
    break;

  case 15: /* function: VOID_TYPE_KEYWORD IDENTIFIER OPENING_PARENTHESIS CLOSING_PARENTHESIS $@7 body  */
#line 156 "parser.y"
               { 
            Value val;
            val.function = (yyvsp[0].instruction);
            insert_symbol(symbol_table, (yyvsp[-4].sval), (yyvsp[-5].sval), val, FUNCTION, scope_no, 1, NULL, yylineno, 0);
            inside_a_function_declaration_body = 0;
            curr_function_instructions_list = NULL; 
          }
#line 1544 "parser.tab.c"
    break;

  case 16: /* function_arguments: type_identifier  */
#line 166 "parser.y"
                        {
            if (!curr_function_parameter_list) {
                curr_function_parameter_list = create_parameter((yyvsp[0].type_id).name, (yyvsp[0].type_id).type);
                curr_function_parameter_list_ptr = curr_function_parameter_list; // Point to the new parameter
            } else {
                curr_function_parameter_list_ptr->next = create_parameter((yyvsp[0].type_id).name, (yyvsp[0].type_id).type);
                curr_function_parameter_list_ptr = curr_function_parameter_list_ptr->next;
            }
            free((yyvsp[0].type_id).name);
            free((yyvsp[0].type_id).type);
            (yyval.param_list) = curr_function_parameter_list; // Set the parameter list
        }
#line 1561 "parser.tab.c"
    break;

  case 17: /* function_arguments: function_arguments COMMA type_identifier  */
#line 178 "parser.y"
                                                   {
            curr_function_parameter_list_ptr->next = create_parameter((yyvsp[0].type_id).name, (yyvsp[0].type_id).type);
            curr_function_parameter_list_ptr = curr_function_parameter_list_ptr->next;
            (yyval.param_list) = curr_function_parameter_list; // Propagate the parameter list
            free((yyvsp[0].type_id).name);
            free((yyvsp[0].type_id).type);
        }
#line 1573 "parser.tab.c"
    break;

  case 18: /* type_identifier: type IDENTIFIER  */
#line 187 "parser.y"
                                          { 
                                            (yyval.type_id).type = (yyvsp[-1].sval);
                                            (yyval.type_id).name = (yyvsp[0].sval); 
                                          }
#line 1582 "parser.tab.c"
    break;

  case 19: /* type: INT_TYPE_KEYWORD  */
#line 194 "parser.y"
                       { (yyval.sval) = (yyvsp[0].sval); }
#line 1588 "parser.tab.c"
    break;

  case 20: /* type: FLOAT_TYPE_KEYWORD  */
#line 195 "parser.y"
                          { (yyval.sval) = (yyvsp[0].sval); }
#line 1594 "parser.tab.c"
    break;

  case 21: /* type: STRING_TYPE_KEYWORD  */
#line 196 "parser.y"
                          { (yyval.sval) = (yyvsp[0].sval); }
#line 1600 "parser.tab.c"
    break;

  case 22: /* type: CHAR_TYPE_KEYWORD  */
#line 197 "parser.y"
                         { (yyval.sval) = (yyvsp[0].sval); }
#line 1606 "parser.tab.c"
    break;

  case 23: /* type: BOOL_TYPE_KEYWORD  */
#line 198 "parser.y"
                         { (yyval.sval) = (yyvsp[0].sval); }
#line 1612 "parser.tab.c"
    break;

  case 24: /* $@8: %empty  */
#line 201 "parser.y"
     { 
        scope_no++;
    }
#line 1620 "parser.tab.c"
    break;

  case 25: /* body: $@8 OPENING_CURLY_BRACE statements CLOSING_CURLY_BRACE  */
#line 206 "parser.y"
                        { 
        if(!inside_a_function_declaration_body) {
            delete_scope(symbol_table, scope_no); 
        }
        scope_no--;
        (yyval.instruction) = (yyvsp[-1].instruction); 
    }
#line 1632 "parser.tab.c"
    break;

  case 26: /* statements: statement statements  */
#line 217 "parser.y"
               {(yyval.instruction) = cur;}
#line 1638 "parser.tab.c"
    break;

  case 27: /* statements: %empty  */
#line 218 "parser.y"
                  {(yyval.instruction) = NULL;}
#line 1644 "parser.tab.c"
    break;

  case 28: /* statement: body SEMICOLON  */
#line 221 "parser.y"
                          {(yyval.instruction) = NULL;}
#line 1650 "parser.tab.c"
    break;

  case 29: /* statement: assignment  */
#line 222 "parser.y"
                      {(yyval.instruction) = NULL;}
#line 1656 "parser.tab.c"
    break;

  case 30: /* statement: return_statement  */
#line 223 "parser.y"
                            {(yyval.instruction) = NULL;}
#line 1662 "parser.tab.c"
    break;

  case 31: /* statement: expression SEMICOLON  */
#line 224 "parser.y"
                                {(yyval.instruction) = NULL;}
#line 1668 "parser.tab.c"
    break;

  case 32: /* statement: initialization  */
#line 225 "parser.y"
                          {(yyval.instruction) = NULL;}
#line 1674 "parser.tab.c"
    break;

  case 33: /* statement: variable_declaration  */
#line 226 "parser.y"
                                {(yyval.instruction) = NULL;}
#line 1680 "parser.tab.c"
    break;

  case 34: /* statement: const_initialization  */
#line 227 "parser.y"
                                {(yyval.instruction) = NULL;}
#line 1686 "parser.tab.c"
    break;

  case 35: /* statement: const_variable_declaration  */
#line 228 "parser.y"
                                      {(yyval.instruction) = NULL;}
#line 1692 "parser.tab.c"
    break;

  case 36: /* statement: if_statement  */
#line 229 "parser.y"
                        {(yyval.instruction) = NULL;}
#line 1698 "parser.tab.c"
    break;

  case 37: /* statement: for_statement  */
#line 230 "parser.y"
                         {(yyval.instruction) = NULL;}
#line 1704 "parser.tab.c"
    break;

  case 38: /* statement: while_statement  */
#line 231 "parser.y"
                           {(yyval.instruction) = NULL;}
#line 1710 "parser.tab.c"
    break;

  case 39: /* statement: do_while_statement  */
#line 232 "parser.y"
                              {(yyval.instruction) = NULL;}
#line 1716 "parser.tab.c"
    break;

  case 40: /* statement: switch_statement  */
#line 233 "parser.y"
                            {(yyval.instruction) = NULL;}
#line 1722 "parser.tab.c"
    break;

  case 41: /* statement: function  */
#line 234 "parser.y"
                    {(yyval.instruction) = NULL;}
#line 1728 "parser.tab.c"
    break;

  case 51: /* $@9: %empty  */
#line 256 "parser.y"
                                     {
                              SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[0].sval), scope_no);
                              if(!result){
                                  fprintf(stderr, "Undeclared identifier '%s' at line %d\n", (yyvsp[0].sval), yylineno);
                                  free_symbol_table(symbol_table);
                                  exit(1);
                              }
                          }
#line 1741 "parser.tab.c"
    break;

  case 57: /* $@10: %empty  */
#line 274 "parser.y"
                                                                        {
                              SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[0].sval), scope_no);
                              if(!result){
                                  fprintf(stderr, "Undeclared identifier '%s' at line %d\n", (yyvsp[0].sval), yylineno);
                                  free_symbol_table(symbol_table);
                                  exit(1);
                              }
                          }
#line 1754 "parser.tab.c"
    break;

  case 58: /* $@11: %empty  */
#line 282 "parser.y"
                                                                   {scope_no++;}
#line 1760 "parser.tab.c"
    break;

  case 59: /* switch_statement: SWITCH_KEYWORD OPENING_PARENTHESIS IDENTIFIER $@10 CLOSING_PARENTHESIS OPENING_CURLY_BRACE $@11 case_list default_case CLOSING_CURLY_BRACE  */
#line 282 "parser.y"
                                                                                                                            { delete_scope(symbol_table, scope_no); scope_no--;}
#line 1766 "parser.tab.c"
    break;

  case 64: /* $@12: %empty  */
#line 296 "parser.y"
                                          {
                              SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[0].type_id).name, scope_no);
                              if(result){
                                  fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", (yyvsp[0].type_id).name, yylineno);
                                  free_symbol_table(symbol_table);
                                  exit(1);
                              }
                          }
#line 1779 "parser.tab.c"
    break;

  case 66: /* $@13: %empty  */
#line 304 "parser.y"
                                            {
                              SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[0].type_id).name, scope_no);
                              if(result){
                                  fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", (yyvsp[0].type_id).name, yylineno);
                                  free_symbol_table(symbol_table);
                                  exit(1);
                              }
                          }
#line 1792 "parser.tab.c"
    break;

  case 68: /* $@14: %empty  */
#line 314 "parser.y"
                                                        {
                              SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[0].type_id).name, scope_no);
                              if(result){
                                  fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", (yyvsp[0].type_id).name, yylineno);
                                  free_symbol_table(symbol_table);
                                  exit(1);
                              }
                          }
#line 1805 "parser.tab.c"
    break;

  case 70: /* $@15: %empty  */
#line 323 "parser.y"
                                                        {
                            SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[0].type_id).name, scope_no);
                            if(result){
                                fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", (yyvsp[0].type_id).name, yylineno);
                                free_symbol_table(symbol_table);
                                exit(1);
                            }
                        }
#line 1818 "parser.tab.c"
    break;

  case 72: /* $@16: %empty  */
#line 334 "parser.y"
                                          {
                              SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[0].type_id).name, scope_no);
                              if(result){
                                  fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", (yyvsp[0].type_id).name, yylineno);
                                  free_symbol_table(symbol_table);
                                  exit(1);
                              }
                          }
#line 1831 "parser.tab.c"
    break;

  case 74: /* $@17: %empty  */
#line 343 "parser.y"
                                            {
                              SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[0].type_id).name, scope_no);
                              if(result){
                                  fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", (yyvsp[0].type_id).name, yylineno);
                                  free_symbol_table(symbol_table);
                                  exit(1);
                              }
                          }
#line 1844 "parser.tab.c"
    break;

  case 76: /* $@18: %empty  */
#line 354 "parser.y"
                                                            {
                                  SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[0].type_id).name, scope_no);
                                  if(result){
                                      fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", (yyvsp[0].type_id).name, yylineno);
                                      free_symbol_table(symbol_table);
                                      exit(1);
                                  }
                              }
#line 1857 "parser.tab.c"
    break;

  case 78: /* $@19: %empty  */
#line 363 "parser.y"
                                                              {
                                  SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[0].type_id).name, scope_no);
                                  if(result){
                                      fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", (yyvsp[0].type_id).name, yylineno);
                                      free_symbol_table(symbol_table);
                                      exit(1);
                                  }
                              }
#line 1870 "parser.tab.c"
    break;

  case 81: /* $@20: %empty  */
#line 379 "parser.y"
               {
        SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[0].sval), scope_no);
        if(!result){
            fprintf(stderr, "Undeclared identifier '%s' at line %d\n", (yyvsp[0].sval), yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
    }
#line 1883 "parser.tab.c"
    break;


#line 1887 "parser.tab.c"

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

#line 482 "parser.y"

