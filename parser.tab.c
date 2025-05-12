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

ValueType string_to_value_type(const char* type_str) {
    if (strcmp(type_str, "int") == 0) return INT_VALUE;
    else if (strcmp(type_str, "float") == 0) return FLOAT_VALUE;
    else if (strcmp(type_str, "char") == 0) return CHAR_VALUE;
    else if (strcmp(type_str, "string") == 0) return STRING_VALUE;
    else if (strcmp(type_str, "bool") == 0) return BOOL_VALUE;
    else {
        fprintf(stderr, "Unknown type '%s' at line %d\n", type_str, yylineno);
        free_symbol_table(symbol_table);
        exit(1);
    }
}


#line 105 "parser.tab.c"

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
  YYSYMBOL_while_statement = 85,           /* while_statement  */
  YYSYMBOL_do_while_statement = 86,        /* do_while_statement  */
  YYSYMBOL_switch_statement = 87,          /* switch_statement  */
  YYSYMBOL_88_9 = 88,                      /* $@9  */
  YYSYMBOL_89_10 = 89,                     /* $@10  */
  YYSYMBOL_default_case = 90,              /* default_case  */
  YYSYMBOL_case_list = 91,                 /* case_list  */
  YYSYMBOL_case_statement = 92,            /* case_statement  */
  YYSYMBOL_initialization = 93,            /* initialization  */
  YYSYMBOL_94_11 = 94,                     /* $@11  */
  YYSYMBOL_95_12 = 95,                     /* $@12  */
  YYSYMBOL_const_initialization = 96,      /* const_initialization  */
  YYSYMBOL_97_13 = 97,                     /* $@13  */
  YYSYMBOL_98_14 = 98,                     /* $@14  */
  YYSYMBOL_variable_declaration = 99,      /* variable_declaration  */
  YYSYMBOL_100_15 = 100,                   /* $@15  */
  YYSYMBOL_101_16 = 101,                   /* $@16  */
  YYSYMBOL_return_statement = 102,         /* return_statement  */
  YYSYMBOL_assignment = 103,               /* assignment  */
  YYSYMBOL_104_17 = 104,                   /* $@17  */
  YYSYMBOL_array_assignment = 105,         /* array_assignment  */
  YYSYMBOL_106_18 = 106,                   /* $@18  */
  YYSYMBOL_expression = 107,               /* expression  */
  YYSYMBOL_array_element = 108,            /* array_element  */
  YYSYMBOL_expr_list = 109,                /* expr_list  */
  YYSYMBOL_function_call = 110,            /* function_call  */
  YYSYMBOL_boolean_expr = 111,             /* boolean_expr  */
  YYSYMBOL_arithmetic_expr = 112,          /* arithmetic_expr  */
  YYSYMBOL_binary_expr = 113,              /* binary_expr  */
  YYSYMBOL_arithmetic_term = 114,          /* arithmetic_term  */
  YYSYMBOL_arithmetic_factor = 115,        /* arithmetic_factor  */
  YYSYMBOL_bitwise_expr = 116,             /* bitwise_expr  */
  YYSYMBOL_bitwise_xor_expr = 117,         /* bitwise_xor_expr  */
  YYSYMBOL_bitwise_and_expr = 118,         /* bitwise_and_expr  */
  YYSYMBOL_bitwise_not_expr = 119,         /* bitwise_not_expr  */
  YYSYMBOL_unary_expr = 120,               /* unary_expr  */
  YYSYMBOL_main_function = 121             /* main_function  */
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
#define YYLAST   401

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  140
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
       0,   141,   141,   141,   145,   146,   149,   152,   149,   165,
     168,   165,   180,   180,   191,   191,   205,   217,   226,   233,
     234,   235,   236,   237,   240,   240,   255,   257,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   276,   279,   280,   283,   284,   287,   290,   291,
     292,   295,   318,   346,   374,   375,   378,   381,   384,   397,
     384,   400,   403,   404,   407,   411,   411,   443,   443,   535,
     535,   575,   575,   668,   668,   697,   697,   729,   732,   732,
     779,   779,   883,   889,   892,   895,   901,   907,   910,   955,
    1000,  1004,  1017,  1051,  1074,  1087,  1100,  1113,  1126,  1138,
    1150,  1162,  1174,  1186,  1198,  1210,  1222,  1233,  1244,  1255,
    1266,  1277,  1288,  1297,  1298,  1301,  1320,  1339,  1342,  1361,
    1386,  1402,  1418,  1421,  1422,  1428,  1431,  1442,  1445,  1456,
    1459,  1470,  1473,  1484,  1492,  1519,  1546,  1568,  1584,  1589,
    1598
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
  "else_statement", "for_statement", "loop_start", "loop_update",
  "while_statement", "do_while_statement", "switch_statement", "$@9",
  "$@10", "default_case", "case_list", "case_statement", "initialization",
  "$@11", "$@12", "const_initialization", "$@13", "$@14",
  "variable_declaration", "$@15", "$@16", "return_statement", "assignment",
  "$@17", "array_assignment", "$@18", "expression", "array_element",
  "expr_list", "function_call", "boolean_expr", "arithmetic_expr",
  "binary_expr", "arithmetic_term", "arithmetic_factor", "bitwise_expr",
  "bitwise_xor_expr", "bitwise_and_expr", "bitwise_not_expr", "unary_expr",
  "main_function", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-139)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-72)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -139,    23,   381,  -139,  -139,  -139,  -139,  -139,  -139,    13,
      26,   381,    33,    20,    40,  -139,  -139,    64,    47,    75,
      83,  -139,    93,    85,  -139,    93,  -139,    84,  -139,   139,
    -139,  -139,   106,  -139,   141,  -139,    93,  -139,  -139,  -139,
    -139,   120,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,
     114,   137,   164,   170,   171,  -139,   246,    93,     6,   246,
       8,    21,  -139,     0,   193,   117,   179,   177,  -139,  -139,
    -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,   210,
    -139,  -139,  -139,  -139,    51,   124,  -139,   156,   158,   161,
    -139,  -139,  -139,  -139,    45,   212,  -139,  -139,   240,   246,
     388,   246,   209,   200,   -16,   256,   185,   188,   246,  -139,
      65,  -139,   246,  -139,   220,   246,   166,    64,  -139,  -139,
    -139,    55,    55,    55,    55,    55,    55,    55,    55,  -139,
      28,    28,    28,    28,    10,    21,    21,    21,  -139,   337,
     134,   189,   246,   337,   337,   192,   182,    39,   173,  -139,
    -139,   194,  -139,   198,  -139,   195,   199,   292,    92,   299,
     197,   337,  -139,    -7,  -139,  -139,  -139,  -139,  -139,  -139,
    -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,
     246,   124,   124,  -139,  -139,  -139,   246,   158,   161,  -139,
    -139,   246,  -139,    50,   184,  -139,   246,   252,   246,  -139,
     221,   246,   246,   260,  -139,  -139,  -139,  -139,   218,   207,
     323,   330,   337,  -139,  -139,   250,   230,   215,  -139,   243,
     241,   268,   242,   247,   224,  -139,  -139,  -139,   226,   244,
     282,   218,   293,  -139,   251,  -139,   254,   246,  -139,  -139,
     246,  -139,  -139,    11,   275,  -139,   287,  -139,   276,   118,
     278,  -139,  -139,  -139,   246,  -139,   320,    69,  -139,   246,
    -139,  -139,   337,  -139,   267,   273,   298,  -139,   127,   274,
    -139,   177,   120,  -139,   277,  -139,  -139,  -139,  -139
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,    19,    20,    21,    22,    23,     0,
       0,     0,     0,     0,     0,     3,     4,     0,     9,     0,
       6,    14,     0,     0,    12,     0,    24,     0,    16,     0,
      24,    24,     0,    15,     0,    10,     0,    18,   140,    13,
       7,    24,    24,    17,    24,   133,   124,    86,    85,   112,
      88,     0,     0,     0,     0,    24,     0,     0,     0,     0,
       0,     0,    41,    73,     0,     0,     0,    27,    36,    37,
      38,    39,    40,    33,    35,    34,    31,    29,    30,     0,
      87,    84,    82,    83,   113,   117,   122,   123,   127,   129,
     131,   114,    11,     8,     0,     0,   134,   135,     0,     0,
      50,     0,     0,     0,    88,     0,    69,     0,     0,   111,
       0,   136,     0,   132,     0,     0,     0,    18,    28,    25,
      26,     0,     0,     0,     0,     0,     0,     0,     0,    32,
       0,     0,     0,     0,     0,     0,     0,     0,    93,    90,
       0,     0,     0,    78,     0,    82,     0,     0,     0,    49,
      48,    82,    58,     0,    77,     0,     0,     0,   125,     0,
       0,    65,    74,     0,   107,   106,   109,   108,    95,    94,
      97,    96,   101,   100,    99,    98,   105,   104,   103,   102,
       0,   115,   116,   118,   119,   120,     0,   126,   128,   130,
      92,     0,    89,     0,     0,    24,     0,     0,     0,    24,
       0,     0,     0,     0,   110,   138,   139,   137,    75,     0,
       0,     0,    91,    80,    79,    44,     0,    82,    56,     0,
      82,     0,     0,     0,     0,    66,   125,   121,     0,     0,
      46,     0,    55,    59,     0,    70,     0,     0,    76,    81,
       0,    24,    42,     0,     0,    54,     0,    57,     0,     0,
      82,    45,    52,    53,     0,    24,     0,     0,    63,     0,
      67,    24,    51,    47,     0,     0,     0,    62,     0,     0,
      43,    27,    24,    60,     0,    68,    64,    61,    72
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -139,  -139,  -139,   314,    32,  -139,  -139,  -139,  -139,  -139,
    -139,   308,   -10,    -2,   -25,  -139,   -65,  -139,  -139,  -139,
    -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,
    -139,    79,   237,  -139,  -139,  -139,  -139,  -139,  -139,  -139,
    -139,  -139,   238,  -139,  -139,  -139,   -34,  -139,  -138,   -55,
     -91,   167,  -139,    48,    61,  -139,   219,   225,   -50,  -139,
    -139
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,    10,    62,    25,    44,    22,    42,    31,
      26,    27,    63,    29,    65,    34,    66,    67,    68,   230,
     242,    69,   148,   244,    70,    71,    72,   200,   246,   266,
     257,   258,    73,   209,   269,    74,   155,   156,    75,   116,
     224,    76,    77,   194,    78,   228,   144,    80,   140,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      15
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      12,    33,   120,   109,   193,    38,    39,    79,   145,    12,
     151,   113,    28,   185,   107,    28,   111,    92,    94,    93,
      95,    13,   105,     3,    45,   110,    43,    94,    96,    97,
     103,    45,    46,    79,    11,    14,   114,    96,    97,    64,
     108,    17,   112,    11,   186,    94,   115,   106,    45,    46,
      47,    48,    49,   104,    18,   252,   253,   254,    45,    46,
     139,    19,   180,   163,   143,    64,   164,   166,   168,   170,
     172,   174,   176,   178,   157,   197,    58,    61,   159,    59,
     138,   161,    21,   213,    61,   115,    60,   189,   191,    59,
     147,   130,   131,   256,   121,   122,    60,   265,    20,   249,
     158,    61,     4,     5,     6,     7,     8,   217,   139,    23,
     220,    61,   123,   124,   125,   126,   127,   128,    24,    35,
      30,   268,    36,    45,    46,    47,    48,    49,    50,     4,
       5,     6,     7,     8,     9,    51,   205,   206,    52,    53,
      54,    40,    55,    56,    36,    57,   210,    37,    94,   250,
      95,    58,   211,   -27,    59,   260,   191,   212,    96,    97,
      98,    60,   143,   132,   274,   191,   133,   134,   221,   190,
     215,    99,   191,    41,   218,   118,    61,   245,   181,   182,
      45,    46,    47,    48,    49,    50,     4,     5,     6,     7,
       8,     9,    51,   183,   184,    52,    53,    54,   100,    55,
      56,   117,    57,   139,   101,   102,   276,   277,    58,   -24,
     135,    59,   119,   136,   137,   141,   251,   152,    60,   153,
     262,   -71,    94,   160,   162,   139,   192,   195,   196,   199,
     263,   198,   201,    61,   208,   203,   270,    79,    79,   121,
     122,   202,   214,    45,    46,    47,    48,    49,   104,    45,
      46,    47,    48,    49,   104,   216,   219,   123,   124,   125,
     126,   127,   128,   222,   223,   225,   229,   231,   129,    64,
      64,    58,   142,   232,    59,   233,   234,    58,   240,   236,
      59,    60,   238,   237,   239,   121,   122,    60,   165,   167,
     169,   171,   173,   175,   177,   179,    61,   121,   122,   241,
     248,   243,    61,   123,   124,   125,   126,   127,   128,   247,
     255,   256,   259,   261,   154,   123,   124,   125,   126,   127,
     128,   121,   122,   264,   271,    16,   235,   204,   121,   122,
     272,   273,   275,    32,   207,   278,   267,   149,   150,   123,
     124,   125,   126,   127,   128,     0,   123,   124,   125,   126,
     127,   128,   121,   122,   187,     0,     0,     0,   226,   121,
     122,   188,     0,     0,     0,   227,   121,   122,     0,     0,
     123,   124,   125,   126,   127,   128,     0,   123,   124,   125,
     126,   127,   128,     0,   123,   124,   125,   126,   127,   128,
       4,     5,     6,     7,     8,     9,   146,     4,     5,     6,
       7,     8
};

static const yytype_int16 yycheck[] =
{
       2,    26,    67,    58,   142,    30,    31,    41,    99,    11,
     101,    61,    22,     3,     8,    25,     8,    42,    34,    44,
      36,     8,    56,     0,     3,    59,    36,    34,    44,    45,
      55,     3,     4,    67,     2,     9,    36,    44,    45,    41,
      34,     8,    34,    11,    34,    34,    46,    57,     3,     4,
       5,     6,     7,     8,    34,    44,    45,    46,     3,     4,
      94,    21,    34,     8,    98,    67,   121,   122,   123,   124,
     125,   126,   127,   128,   108,    36,    31,    56,   112,    34,
      35,   115,    35,    33,    56,    46,    41,   137,    38,    34,
     100,    40,    41,    24,    29,    30,    41,    28,    34,   237,
      35,    56,     9,    10,    11,    12,    13,   198,   142,    34,
     201,    56,    47,    48,    49,    50,    51,    52,    35,    35,
      35,   259,    38,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    44,    45,    18,    19,
      20,    35,    22,    23,    38,    25,   180,     8,    34,   240,
      36,    31,   186,    33,    34,    37,    38,   191,    44,    45,
      46,    41,   196,    39,    37,    38,    42,    43,   202,    35,
     195,    34,    38,    32,   199,    58,    56,   232,   130,   131,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,   132,   133,    18,    19,    20,    34,    22,
      23,     8,    25,   237,    34,    34,   271,   272,    31,    32,
      54,    34,    33,    55,    53,     3,   241,     8,    41,    19,
     254,    36,    34,     3,    58,   259,    37,    35,    46,    35,
     255,    58,    34,    56,    37,    36,   261,   271,   272,    29,
      30,    46,    58,     3,     4,     5,     6,     7,     8,     3,
       4,     5,     6,     7,     8,     3,    35,    47,    48,    49,
      50,    51,    52,     3,    46,    58,    16,    37,    58,   271,
     272,    31,    32,    58,    34,    32,    35,    31,    34,    37,
      34,    41,    58,    36,    58,    29,    30,    41,   121,   122,
     123,   124,   125,   126,   127,   128,    56,    29,    30,    17,
      46,     8,    56,    47,    48,    49,    50,    51,    52,    58,
      35,    24,    36,    35,    58,    47,    48,    49,    50,    51,
      52,    29,    30,     3,    57,    11,    58,    35,    29,    30,
      57,    33,    58,    25,    35,    58,   257,   100,   100,    47,
      48,    49,    50,    51,    52,    -1,    47,    48,    49,    50,
      51,    52,    29,    30,   135,    -1,    -1,    -1,    35,    29,
      30,   136,    -1,    -1,    -1,    35,    29,    30,    -1,    -1,
      47,    48,    49,    50,    51,    52,    -1,    47,    48,    49,
      50,    51,    52,    -1,    47,    48,    49,    50,    51,    52,
       9,    10,    11,    12,    13,    14,     8,     9,    10,    11,
      12,    13
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    62,    63,     0,     9,    10,    11,    12,    13,    14,
      64,    65,    74,     8,     9,   121,    64,     8,    34,    21,
      34,    35,    68,    34,    35,    66,    71,    72,    73,    74,
      35,    70,    72,    75,    76,    35,    38,     8,    75,    75,
      35,    32,    69,    73,    67,     3,     4,     5,     6,     7,
       8,    15,    18,    19,    20,    22,    23,    25,    31,    34,
      41,    56,    65,    73,    74,    75,    77,    78,    79,    82,
      85,    86,    87,    93,    96,    99,   102,   103,   105,   107,
     108,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    75,    75,    34,    36,    44,    45,    46,    34,
      34,    34,    34,    75,     8,   107,    73,     8,    34,   110,
     107,     8,    34,   119,    36,    46,   100,     8,    58,    33,
      77,    29,    30,    47,    48,    49,    50,    51,    52,    58,
      40,    41,    39,    42,    43,    54,    55,    53,    35,   107,
     109,     3,    32,   107,   107,   111,     8,    73,    83,    93,
     103,   111,     8,    19,    58,    97,    98,   107,    35,   107,
       3,   107,    58,     8,   110,   112,   110,   112,   110,   112,
     110,   112,   110,   112,   110,   112,   110,   112,   110,   112,
      34,   114,   114,   115,   115,     3,    34,   117,   118,   119,
      35,    38,    37,   109,   104,    35,    46,    36,    58,    35,
      88,    34,    46,    36,    35,    44,    45,    35,    37,    94,
     107,   107,   107,    33,    58,    75,     3,   111,    75,    35,
     111,   107,     3,    46,   101,    58,    35,    35,   106,    16,
      80,    37,    58,    32,    35,    58,    37,    36,    58,    58,
      34,    17,    81,     8,    84,   110,    89,    58,    46,   109,
     111,    75,    44,    45,    46,    35,    24,    91,    92,    36,
      37,    35,   107,    75,     3,    28,    90,    92,   109,    95,
      75,    57,    57,    33,    37,    58,    77,    77,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    63,    62,    64,    64,    66,    67,    65,    68,
      69,    65,    70,    65,    71,    65,    72,    72,    73,    74,
      74,    74,    74,    74,    76,    75,    77,    77,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    79,    80,    80,    81,    81,    82,    83,    83,
      83,    84,    84,    84,    84,    84,    85,    86,    88,    89,
      87,    90,    91,    91,    92,    94,    93,    95,    93,    97,
      96,    98,    96,   100,    99,   101,    99,   102,   104,   103,
     106,   105,   107,   107,   107,   107,   107,   107,   107,   108,
     109,   109,   110,   110,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   112,   112,   113,   113,   113,   114,   114,
     114,   114,   114,   115,   115,   115,   116,   116,   117,   117,
     118,   118,   119,   119,   120,   120,   120,   120,   120,   120,
     121
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     2,     0,     0,     0,     8,     0,
       0,     8,     0,     6,     0,     6,     1,     3,     2,     1,
       1,     1,     1,     1,     0,     4,     2,     0,     2,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     7,     5,     0,     2,     0,     9,     1,     1,
       0,     3,     2,     2,     1,     0,     5,     7,     0,     0,
      10,     3,     2,     1,     4,     0,     5,     0,    10,     0,
       6,     0,    11,     0,     3,     0,     6,     3,     0,     5,
       0,     7,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     2,     1,     1,     1,     3,     3,     1,     3,     3,
       3,     5,     1,     1,     1,     3,     3,     1,     3,     1,
       3,     1,     2,     1,     2,     2,     2,     4,     4,     4,
       5
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
#line 141 "parser.y"
    { scope_no++; }
#line 1447 "parser.tab.c"
    break;

  case 3: /* program: $@1 functions main_function  */
#line 141 "parser.y"
                                            { delete_scope(symbol_table, scope_no); scope_no--;}
#line 1453 "parser.tab.c"
    break;

  case 6: /* $@2: %empty  */
#line 149 "parser.y"
                                              { 
            curr_function_parameter_list = NULL; 
          }
#line 1461 "parser.tab.c"
    break;

  case 7: /* $@3: %empty  */
#line 152 "parser.y"
                                                  { 
            inside_a_function_declaration_body = 1;
            curr_function_instructions_list = NULL;  
          }
#line 1470 "parser.tab.c"
    break;

  case 8: /* function: type IDENTIFIER OPENING_PARENTHESIS $@2 function_arguments CLOSING_PARENTHESIS $@3 body  */
#line 156 "parser.y"
               {
            Value val;
            val.function = (yyvsp[0].instruction);  
            insert_symbol(symbol_table, (yyvsp[-6].sval), (yyvsp[-7].sval), val, FUNCTION, scope_no, 1, 0, 0, (yyvsp[-3].param_list), yylineno, 0);
            inside_a_function_declaration_body = 0;
            curr_function_parameter_list = NULL;
            curr_function_parameter_list_ptr = NULL;
            curr_function_instructions_list = NULL;
          }
#line 1484 "parser.tab.c"
    break;

  case 9: /* $@4: %empty  */
#line 165 "parser.y"
                                                           { 
            curr_function_parameter_list = NULL; 
          }
#line 1492 "parser.tab.c"
    break;

  case 10: /* $@5: %empty  */
#line 168 "parser.y"
                                                 { 
            inside_a_function_declaration_body = 1;
            curr_function_instructions_list = NULL;  
          }
#line 1501 "parser.tab.c"
    break;

  case 11: /* function: VOID_TYPE_KEYWORD IDENTIFIER OPENING_PARENTHESIS $@4 function_arguments CLOSING_PARENTHESIS $@5 body  */
#line 172 "parser.y"
               { 
            Value val;
            val.function = (yyvsp[0].instruction);
            insert_symbol(symbol_table, (yyvsp[-6].sval), (yyvsp[-7].sval), val, FUNCTION, scope_no, 1, 0, 0, (yyvsp[-3].param_list), yylineno, 0);
            inside_a_function_declaration_body = 0;
            curr_function_parameter_list = NULL;
            curr_function_parameter_list_ptr = NULL; 
          }
#line 1514 "parser.tab.c"
    break;

  case 12: /* $@6: %empty  */
#line 180 "parser.y"
                                                                  { 
            inside_a_function_declaration_body = 1;
            curr_function_instructions_list = NULL;  
          }
#line 1523 "parser.tab.c"
    break;

  case 13: /* function: type IDENTIFIER OPENING_PARENTHESIS CLOSING_PARENTHESIS $@6 body  */
#line 184 "parser.y"
               { 
            Value val;
            val.function = (yyvsp[0].instruction);
            insert_symbol(symbol_table, (yyvsp[-4].sval), (yyvsp[-5].sval), val, FUNCTION, scope_no, 1, 0, 0, NULL, yylineno, 0);
            inside_a_function_declaration_body = 0;
            curr_function_instructions_list = NULL; 
          }
#line 1535 "parser.tab.c"
    break;

  case 14: /* $@7: %empty  */
#line 191 "parser.y"
                                                                               { 
            inside_a_function_declaration_body = 1;
            curr_function_instructions_list = NULL;  
          }
#line 1544 "parser.tab.c"
    break;

  case 15: /* function: VOID_TYPE_KEYWORD IDENTIFIER OPENING_PARENTHESIS CLOSING_PARENTHESIS $@7 body  */
#line 195 "parser.y"
               { 
            Value val;
            val.function = (yyvsp[0].instruction);
            insert_symbol(symbol_table, (yyvsp[-4].sval), (yyvsp[-5].sval), val, FUNCTION, scope_no, 1, 0, 0, NULL, yylineno, 0);
            inside_a_function_declaration_body = 0;
            curr_function_instructions_list = NULL; 
          }
#line 1556 "parser.tab.c"
    break;

  case 16: /* function_arguments: type_identifier  */
#line 205 "parser.y"
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
#line 1573 "parser.tab.c"
    break;

  case 17: /* function_arguments: function_arguments COMMA type_identifier  */
#line 217 "parser.y"
                                                   {
            curr_function_parameter_list_ptr->next = create_parameter((yyvsp[0].type_id).name, (yyvsp[0].type_id).type);
            curr_function_parameter_list_ptr = curr_function_parameter_list_ptr->next;
            (yyval.param_list) = curr_function_parameter_list; // Propagate the parameter list
            free((yyvsp[0].type_id).name);
            free((yyvsp[0].type_id).type);
        }
#line 1585 "parser.tab.c"
    break;

  case 18: /* type_identifier: type IDENTIFIER  */
#line 226 "parser.y"
                                          { 
                                            (yyval.type_id).type = (yyvsp[-1].sval);
                                            (yyval.type_id).name = (yyvsp[0].sval); 
                                          }
#line 1594 "parser.tab.c"
    break;

  case 19: /* type: INT_TYPE_KEYWORD  */
#line 233 "parser.y"
                       { (yyval.sval) = (yyvsp[0].sval); }
#line 1600 "parser.tab.c"
    break;

  case 20: /* type: FLOAT_TYPE_KEYWORD  */
#line 234 "parser.y"
                          { (yyval.sval) = (yyvsp[0].sval); }
#line 1606 "parser.tab.c"
    break;

  case 21: /* type: STRING_TYPE_KEYWORD  */
#line 235 "parser.y"
                          { (yyval.sval) = (yyvsp[0].sval); }
#line 1612 "parser.tab.c"
    break;

  case 22: /* type: CHAR_TYPE_KEYWORD  */
#line 236 "parser.y"
                         { (yyval.sval) = (yyvsp[0].sval); }
#line 1618 "parser.tab.c"
    break;

  case 23: /* type: BOOL_TYPE_KEYWORD  */
#line 237 "parser.y"
                         { (yyval.sval) = (yyvsp[0].sval); }
#line 1624 "parser.tab.c"
    break;

  case 24: /* $@8: %empty  */
#line 240 "parser.y"
     { 
        scope_no++;
    }
#line 1632 "parser.tab.c"
    break;

  case 25: /* body: $@8 OPENING_CURLY_BRACE statements CLOSING_CURLY_BRACE  */
#line 245 "parser.y"
                        { 
        if(!inside_a_function_declaration_body) {
            delete_scope(symbol_table, scope_no); 
        }
        scope_no--;
        (yyval.instruction) = (yyvsp[-1].instruction); 
    }
#line 1644 "parser.tab.c"
    break;

  case 26: /* statements: statement statements  */
#line 256 "parser.y"
               {(yyval.instruction) = NULL;}
#line 1650 "parser.tab.c"
    break;

  case 27: /* statements: %empty  */
#line 257 "parser.y"
                  {(yyval.instruction) = NULL;}
#line 1656 "parser.tab.c"
    break;

  case 28: /* statement: body SEMICOLON  */
#line 260 "parser.y"
                          {(yyval.instruction) = NULL;}
#line 1662 "parser.tab.c"
    break;

  case 29: /* statement: assignment  */
#line 261 "parser.y"
                      {(yyval.instruction) = NULL;}
#line 1668 "parser.tab.c"
    break;

  case 30: /* statement: array_assignment  */
#line 262 "parser.y"
                            {(yyval.instruction) = NULL;}
#line 1674 "parser.tab.c"
    break;

  case 31: /* statement: return_statement  */
#line 263 "parser.y"
                            {(yyval.instruction) = NULL;}
#line 1680 "parser.tab.c"
    break;

  case 32: /* statement: expression SEMICOLON  */
#line 264 "parser.y"
                                {(yyval.instruction) = NULL;}
#line 1686 "parser.tab.c"
    break;

  case 33: /* statement: initialization  */
#line 265 "parser.y"
                          {(yyval.instruction) = NULL;}
#line 1692 "parser.tab.c"
    break;

  case 34: /* statement: variable_declaration  */
#line 266 "parser.y"
                                {(yyval.instruction) = NULL;}
#line 1698 "parser.tab.c"
    break;

  case 35: /* statement: const_initialization  */
#line 267 "parser.y"
                                {(yyval.instruction) = NULL;}
#line 1704 "parser.tab.c"
    break;

  case 36: /* statement: if_statement  */
#line 268 "parser.y"
                        {(yyval.instruction) = NULL;}
#line 1710 "parser.tab.c"
    break;

  case 37: /* statement: for_statement  */
#line 269 "parser.y"
                         {(yyval.instruction) = NULL;}
#line 1716 "parser.tab.c"
    break;

  case 38: /* statement: while_statement  */
#line 270 "parser.y"
                           {(yyval.instruction) = NULL;}
#line 1722 "parser.tab.c"
    break;

  case 39: /* statement: do_while_statement  */
#line 271 "parser.y"
                              {(yyval.instruction) = NULL;}
#line 1728 "parser.tab.c"
    break;

  case 40: /* statement: switch_statement  */
#line 272 "parser.y"
                            {(yyval.instruction) = NULL;}
#line 1734 "parser.tab.c"
    break;

  case 41: /* statement: function  */
#line 273 "parser.y"
                    {(yyval.instruction) = NULL;}
#line 1740 "parser.tab.c"
    break;

  case 51: /* loop_update: IDENTIFIER ASSIGNMENT expression  */
#line 295 "parser.y"
                                                            {
                              SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[-2].sval), scope_no);
                              if(!result){
                                  fprintf(stderr, "Undeclared identifier '%s' at line %d\n", (yyvsp[-2].sval), yylineno);
                                  free_symbol_table(symbol_table);
                                  exit(1);
                              }
                              if(result->is_function){
                                fprintf(stderr, "Cannot use function '%s' at line %d as a loop variable", (yyvsp[-2].sval), yylineno);
                                free_symbol_table(symbol_table);
                                exit(1);
                              }
                              if(result->is_constant){
                                fprintf(stderr, "Cannot use const identifier '%s' at line %d as a loop variable", (yyvsp[-2].sval), yylineno);
                                free_symbol_table(symbol_table);
                                exit(1);
                              }
                              if (result->value_type != (yyvsp[0].expr).expr_return_type) {
                                  fprintf(stderr, "Type mismatch in loop update for '%s' at line %d\n", (yyvsp[-2].sval), yylineno);
                                  free_symbol_table(symbol_table);
                                  exit(1);
                              }
                          }
#line 1768 "parser.tab.c"
    break;

  case 52: /* loop_update: IDENTIFIER INCREMENT  */
#line 318 "parser.y"
                                           {
                        SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[-1].sval), scope_no);
                        if (!result) {
                            fprintf(stderr, "Undeclared identifier '%s' at line %d\n", (yyvsp[-1].sval), yylineno);
                            free_symbol_table(symbol_table);
                            exit(1);
                        }
                        if (result->is_function) {
                            fprintf(stderr, "Cannot use function '%s' at line %d as a loop variable\n", (yyvsp[-1].sval), yylineno);
                            free_symbol_table(symbol_table);
                            exit(1);
                        }
                        if (result->is_constant) {
                            fprintf(stderr, "Cannot use const identifier '%s' at line %d as a loop variable\n", (yyvsp[-1].sval), yylineno);
                            free_symbol_table(symbol_table);
                            exit(1);
                        }
                        if (result->value_type != INT_VALUE && result->value_type != FLOAT_VALUE) {
                            fprintf(stderr, "Increment requires numeric operand at line %d\n", (yyvsp[-1].sval), yylineno);
                            free_symbol_table(symbol_table);
                            exit(1);
                        }
                        if (result->value_type == INT_VALUE) {
                            result->value.int_value++;
                        } else {
                            result->value.float_value++;
                        }
                    }
#line 1801 "parser.tab.c"
    break;

  case 53: /* loop_update: IDENTIFIER DECREMENT  */
#line 346 "parser.y"
                                           {
                        SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[-1].sval), scope_no);
                        if (!result) {
                            fprintf(stderr, "Undeclared identifier '%s' at line %d\n", (yyvsp[-1].sval), yylineno);
                            free_symbol_table(symbol_table);
                            exit(1);
                        }
                        if (result->is_function) {
                            fprintf(stderr, "Cannot use function '%s' at line %d as a loop variable\n", (yyvsp[-1].sval), yylineno);
                            free_symbol_table(symbol_table);
                            exit(1);
                        }
                        if (result->is_constant) {
                            fprintf(stderr, "Cannot use const identifier '%s' at line %d as a loop variable\n", (yyvsp[-1].sval), yylineno);
                            free_symbol_table(symbol_table);
                            exit(1);
                        }
                        if (result->value_type != INT_VALUE && result->value_type != FLOAT_VALUE) {
                            fprintf(stderr, "Decrement requires numeric operand at line %d\n", (yyvsp[-1].sval), yylineno);
                            free_symbol_table(symbol_table);
                            exit(1);
                        }
                        if (result->value_type == INT_VALUE) {
                            result->value.int_value--;
                        } else {
                            result->value.float_value--;
                        }
                    }
#line 1834 "parser.tab.c"
    break;

  case 58: /* $@9: %empty  */
#line 384 "parser.y"
                                                                        {
                              SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[0].sval), scope_no);
                              if(!result){
                                  fprintf(stderr, "Undeclared identifier '%s' at line %d\n", (yyvsp[0].sval), yylineno);
                                  free_symbol_table(symbol_table);
                                  exit(1);
                              }
                              if(result->value_type != INT_VALUE){
                                fprintf(stderr, "Cannot use non-integer '%s' at line %d as a switch statement variable", (yyvsp[0].sval), yylineno);
                                free_symbol_table(symbol_table);
                                exit(1);
                              }
                          }
#line 1852 "parser.tab.c"
    break;

  case 59: /* $@10: %empty  */
#line 397 "parser.y"
                                                                   {scope_no++;}
#line 1858 "parser.tab.c"
    break;

  case 60: /* switch_statement: SWITCH_KEYWORD OPENING_PARENTHESIS IDENTIFIER $@9 CLOSING_PARENTHESIS OPENING_CURLY_BRACE $@10 case_list default_case CLOSING_CURLY_BRACE  */
#line 397 "parser.y"
                                                                                                                            { delete_scope(symbol_table, scope_no); scope_no--;}
#line 1864 "parser.tab.c"
    break;

  case 65: /* $@11: %empty  */
#line 411 "parser.y"
                                                       {
                   SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[-2].type_id).name, scope_no);
                   if (result) {
                       fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", (yyvsp[-2].type_id).name, yylineno);
                       free_symbol_table(symbol_table);
                       exit(1);
                   }
                   ValueType declared_type = string_to_value_type((yyvsp[-2].type_id).type);
                   if (declared_type != (yyvsp[0].expr).expr_return_type) {
                       fprintf(stderr, "Type mismatch in initialization at line %d\n", yylineno);
                       free_symbol_table(symbol_table);
                       exit(1);
                   }
                   Value val;
                   switch (declared_type) {
                       case INT_VALUE:
                       case BOOL_VALUE:
                           val.int_value = (yyvsp[0].expr).expr_value.int_value;
                           break;
                       case FLOAT_VALUE:
                           val.float_value = (yyvsp[0].expr).expr_value.float_value;
                           break;
                       case CHAR_VALUE:
                           val.char_value = (yyvsp[0].expr).expr_value.char_value;
                           break;
                       case STRING_VALUE:
                           val.char_array = strdup((yyvsp[0].expr).expr_value.char_array);
                           break;
                   }
                   insert_symbol(symbol_table, (yyvsp[-2].type_id).name, (yyvsp[-2].type_id).type, val, declared_type, scope_no, 0, 0, 0, NULL, yylineno, 0);
               }
#line 1900 "parser.tab.c"
    break;

  case 67: /* $@12: %empty  */
#line 443 "parser.y"
                                                                                                                                                                      {
                   SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[-7].type_id).name, scope_no);
                   if (result) {
                       fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", (yyvsp[-7].type_id).name, yylineno);
                       free_symbol_table(symbol_table);
                       exit(1);
                   }
                   ValueType array_type;
                   ValueType element_type;
                   if (strcmp((yyvsp[-7].type_id).type, "int") == 0 || strcmp((yyvsp[-7].type_id).type, "bool") == 0) {
                       array_type = INT_ARRAY_VALUE;
                       element_type = INT_VALUE;
                   } else if (strcmp((yyvsp[-7].type_id).type, "float") == 0) {
                       array_type = FLOAT_ARRAY_VALUE;
                       element_type = FLOAT_VALUE;
                   } else if (strcmp((yyvsp[-7].type_id).type, "char") == 0) {
                       array_type = CHAR_ARRAY_VALUE;
                       element_type = CHAR_VALUE;
                   } else if (strcmp((yyvsp[-7].type_id).type, "string") == 0) {
                       array_type = STRING_ARRAY_VALUE;
                       element_type = STRING_VALUE;
                   } else {
                       fprintf(stderr, "Unsupported array type '%s' at line %d\n", (yyvsp[-7].type_id).type, yylineno);
                       free_symbol_table(symbol_table);
                       exit(1);
                   }

                   size_t declared_size = (yyvsp[-5].ival);
                   size_t provided_size = 0;
                   expr_lst* current = &(yyvsp[-1].expr_lst);
                   while (current) {
                       provided_size++;
                       if (current->e->expr_return_type != element_type) {
                           fprintf(stderr, "Type mismatch in array initialization at line %d\n", yylineno);
                           free_symbol_table(symbol_table);
                           exit(1);
                       }
                       current = current->next_expr;
                   }

                   if (provided_size > declared_size) {
                       fprintf(stderr, "Too many initializers for array '%s' at line %d\n", (yyvsp[-7].type_id).name, yylineno);
                       free_symbol_table(symbol_table);
                       exit(1);
                   }

                   Value val;
                   switch (array_type) {
                       case INT_ARRAY_VALUE:
                           val.int_array = (int*)calloc(declared_size, sizeof(int)); // Defaults to 0
                           current = &(yyvsp[-1].expr_lst);
                           for (size_t i = 0; i < provided_size; i++) {
                               val.int_array[i] = current->e->expr_value.int_value;
                               current = current->next_expr;
                           }
                           break;
                       case FLOAT_ARRAY_VALUE:
                           val.float_array = (double*)calloc(declared_size, sizeof(double)); // Defaults to 0.0
                           current = &(yyvsp[-1].expr_lst);
                           for (size_t i = 0; i < provided_size; i++) {
                               val.float_array[i] = current->e->expr_value.float_value;
                               current = current->next_expr;
                           }
                           break;
                       case CHAR_ARRAY_VALUE:
                           val.char_array = (char*)calloc(declared_size, sizeof(char)); // Defaults to '\0'
                           current = &(yyvsp[-1].expr_lst);
                           for (size_t i = 0; i < provided_size; i++) {
                               val.char_array[i] = current->e->expr_value.char_value;
                               current = current->next_expr;
                           }
                           break;
                       case STRING_ARRAY_VALUE:
                           val.string_array = (char**)malloc(declared_size * sizeof(char*));
                           for (size_t i = 0; i < declared_size; i++) {
                               val.string_array[i] = strdup(""); // Default to ""
                           }
                           current = &(yyvsp[-1].expr_lst);
                           for (size_t i = 0; i < provided_size; i++) {
                               free(val.string_array[i]);
                               val.string_array[i] = strdup(current->e->expr_value.char_array);
                               current = current->next_expr;
                           }
                           break;
                   }

                   insert_symbol(symbol_table, (yyvsp[-7].type_id).name, (yyvsp[-7].type_id).type, val, array_type, scope_no, 0, 0, 1, NULL, yylineno, declared_size);
               }
#line 1993 "parser.tab.c"
    break;

  case 69: /* $@13: %empty  */
#line 535 "parser.y"
                                                     {
                           SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[0].type_id).name, scope_no);
                           if(result){
                               fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", (yyvsp[0].type_id).name, yylineno);
                               free_symbol_table(symbol_table);
                               exit(1);
                           }
                       }
#line 2006 "parser.tab.c"
    break;

  case 70: /* const_initialization: CONST_KEYWORD type_identifier $@13 ASSIGNMENT expression SEMICOLON  */
#line 543 "parser.y"
                                                       {
                           ValueType declared_type = string_to_value_type((yyvsp[-4].type_id).type);
                       
                           if (declared_type != (yyvsp[-1].expr).expr_return_type) {
                               fprintf(stderr, "Type mismatch in constant initialization at line %d\n", yylineno);
                               free_symbol_table(symbol_table);
                               exit(1);
                           }
                       
                           Value val;
                           switch (declared_type) {
                               case INT_VALUE:
                               case BOOL_VALUE:
                                   val.int_value = (yyvsp[-1].expr).expr_value.int_value;
                                   break;
                               case FLOAT_VALUE:
                                   val.float_value = (yyvsp[-1].expr).expr_value.float_value;
                                   break;
                               case CHAR_VALUE:
                                   val.char_value = (yyvsp[-1].expr).expr_value.char_value;
                                   break;
                               case STRING_VALUE:
                                   val.char_array = strdup((yyvsp[-1].expr).expr_value.char_array);
                                   break;
                               default:
                                   fprintf(stderr, "Unsupported type in constant initialization at line %d\n", yylineno);
                                   free_symbol_table(symbol_table);
                                   exit(1);
                           }
                       
                           insert_symbol(symbol_table, (yyvsp[-4].type_id).name, (yyvsp[-4].type_id).type, val, declared_type, scope_no, 0, 1, 0, NULL, yylineno, 0);
                       }
#line 2043 "parser.tab.c"
    break;

  case 71: /* $@14: %empty  */
#line 575 "parser.y"
                                                       {
                           SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[0].type_id).name, scope_no);
                           if(result){
                               fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", (yyvsp[0].type_id).name, yylineno);
                               free_symbol_table(symbol_table);
                               exit(1);
                           }
                       }
#line 2056 "parser.tab.c"
    break;

  case 72: /* const_initialization: CONST_KEYWORD type_identifier $@14 OPENING_SQUARE_BRACKETS INTEGER_LITERAL CLOSING_SQUARE_BRACKETS ASSIGNMENT OPENING_SQUARE_BRACKETS expr_list CLOSING_SQUARE_BRACKETS SEMICOLON  */
#line 583 "parser.y"
                                                                                                                                                                      {
                           ValueType array_type;
                           ValueType element_type;
                           if (strcmp((yyvsp[-9].type_id).type, "int") == 0 || strcmp((yyvsp[-9].type_id).type, "bool") == 0) {
                               array_type = INT_ARRAY_VALUE;
                               element_type = INT_VALUE;
                           } else if (strcmp((yyvsp[-9].type_id).type, "float") == 0) {
                               array_type = FLOAT_ARRAY_VALUE;
                               element_type = FLOAT_VALUE;
                           } else if (strcmp((yyvsp[-9].type_id).type, "char") == 0) {
                               array_type = CHAR_ARRAY_VALUE;
                               element_type = CHAR_VALUE;
                           } else if (strcmp((yyvsp[-9].type_id).type, "string") == 0) {
                               array_type = STRING_ARRAY_VALUE;
                               element_type = STRING_VALUE;
                           } else {
                               fprintf(stderr, "Unsupported array type '%s' at line %d\n", (yyvsp[-9].type_id).type, yylineno);
                               free_symbol_table(symbol_table);
                               exit(1);
                           }

                           size_t declared_size = (yyvsp[-6].ival);
                           size_t provided_size = 0;
                           expr_lst* current = &(yyvsp[-2].expr_lst);
                           while (current) {
                               provided_size++;
                               if (current->e->expr_return_type != element_type) {
                                   fprintf(stderr, "Type mismatch in constant array initialization at line %d\n", yylineno);
                                   free_symbol_table(symbol_table);
                                   exit(1);
                               }
                               current = current->next_expr;
                           }

                           if (provided_size > declared_size) {
                               fprintf(stderr, "Too many initializers for constant array '%s' at line %d\n", (yyvsp[-9].type_id).name, yylineno);
                               free_symbol_table(symbol_table);
                               exit(1);
                           }

                           Value val;
                           switch (array_type) {
                               case INT_ARRAY_VALUE:
                                   val.int_array = (int*)calloc(declared_size, sizeof(int)); // Defaults to 0
                                   current = &(yyvsp[-2].expr_lst);
                                   for (size_t i = 0; i < provided_size; i++) {
                                       val.int_array[i] = current->e->expr_value.int_value;
                                       current = current->next_expr;
                                   }
                                   break;
                               case FLOAT_ARRAY_VALUE:
                                   val.float_array = (double*)calloc(declared_size, sizeof(double)); // Defaults to 0.0
                                   current = &(yyvsp[-2].expr_lst);
                                   for (size_t i = 0; i < provided_size; i++) {
                                       val.float_array[i] = current->e->expr_value.float_value;
                                       current = current->next_expr;
                                   }
                                   break;
                               case CHAR_ARRAY_VALUE:
                                   val.char_array = (char*)calloc(declared_size, sizeof(char)); // Defaults to '\0'
                                   current = &(yyvsp[-2].expr_lst);
                                   for (size_t i = 0; i < provided_size; i++) {
                                       val.char_array[i] = current->e->expr_value.char_value;
                                       current = current->next_expr;
                                   }
                                   break;
                               case STRING_ARRAY_VALUE:
                                   val.string_array = (char**)malloc(declared_size * sizeof(char*));
                                   for (size_t i = 0; i < declared_size; i++) {
                                       val.string_array[i] = strdup(""); // Default to ""
                                   }
                                   current = &(yyvsp[-2].expr_lst);
                                   for (size_t i = 0; i < provided_size; i++) {
                                       free(val.string_array[i]);
                                       val.string_array[i] = strdup(current->e->expr_value.char_array);
                                       current = current->next_expr;
                                   }
                                   break;
                           }

                           insert_symbol(symbol_table, (yyvsp[-9].type_id).name, (yyvsp[-9].type_id).type, val, array_type, scope_no, 0, 1, 1, NULL, yylineno, declared_size);
                       }
#line 2143 "parser.tab.c"
    break;

  case 73: /* $@15: %empty  */
#line 668 "parser.y"
                                          {
                              SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[0].type_id).name, scope_no);
                              if(result){
                                  fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", (yyvsp[0].type_id).name, yylineno);
                                  free_symbol_table(symbol_table);
                                  exit(1);
                              }
                              Value val;
                              if(strcmp((yyvsp[0].type_id).type, INT_TYPE_KEYWORD) == 0){
                                val.int_value = 0;
                                insert_symbol(symbol_table, (yyvsp[0].type_id).name, (yyvsp[0].type_id).type, val, INT_VALUE, scope_no, 0, 0, 0, NULL, yylineno, 0);
                              }else if(strcmp((yyvsp[0].type_id).type, FLOAT_TYPE_KEYWORD) == 0){
                                val.float_value = 0.0;
                                insert_symbol(symbol_table, (yyvsp[0].type_id).name, (yyvsp[0].type_id).type, val, FLOAT_VALUE, scope_no, 0, 0, 0, NULL, yylineno, 0);
                              }else if(strcmp((yyvsp[0].type_id).type, STRING_TYPE_KEYWORD) == 0){
                                val.char_array = strdup("");
                                insert_symbol(symbol_table, (yyvsp[0].type_id).name, (yyvsp[0].type_id).type, val, STRING_VALUE, scope_no, 0, 0, 0, NULL, yylineno, 0);
                              }else if(strcmp((yyvsp[0].type_id).type, CHAR_TYPE_KEYWORD) == 0){
                                val.char_value = '';
                                insert_symbol(symbol_table, (yyvsp[0].type_id).name, (yyvsp[0].type_id).type, val, CHAR_VALUE, scope_no, 0, 0, 0, NULL, yylineno, 0);
                              }else if(strcmp((yyvsp[0].type_id).type, BOOL_TYPE_KEYWORD) == 0){
                                val.int_value = 0;
                                insert_symbol(symbol_table, (yyvsp[0].type_id).name, (yyvsp[0].type_id).type, val, INT_VALUE, scope_no, 0, 0, 0, NULL, yylineno, 0);
                              }
                              free((yyvsp[0].type_id).name);
                              free((yyvsp[0].type_id).type);
                              
                          }
#line 2176 "parser.tab.c"
    break;

  case 75: /* $@16: %empty  */
#line 697 "parser.y"
                                                                                                            {
                              SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[-3].type_id).name, scope_no);
                              if(result){
                                  fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", (yyvsp[-3].type_id).name, yylineno);
                                  free_symbol_table(symbol_table);
                                  exit(1);
                              }
                              if((yyvsp[-1].ival) <= 0){
                                fprintf(stderr, "Cannot declare an array of size %d at line %d\n", (yyvsp[-1].ival), yylineno);
                                free_symbol_table(symbol_table);
                                exit(1);
                              }
                              Value val;
                              if (strcmp((yyvsp[-3].type_id).type, INT_TYPE_KEYWORD) == 0) {
                                  insert_symbol(symbol_table, (yyvsp[-3].type_id).name, (yyvsp[-3].type_id).type, val, INT_ARRAY_VALUE, scope_no, 0, 0, 1, NULL, yylineno, (yyvsp[-1].ival));
                              }else if(strcmp((yyvsp[-3].type_id).type, FLOAT_TYPE_KEYWORD) == 0){
                                insert_symbol(symbol_table, (yyvsp[-3].type_id).name, (yyvsp[-3].type_id).type, val, FLOAT_ARRAY_VALUE, scope_no, 0, 0, 1, NULL, yylineno, (yyvsp[-1].ival));
                              }else if(strcmp((yyvsp[-3].type_id).type, STRING_TYPE_KEYWORD) == 0){
                                insert_symbol(symbol_table, (yyvsp[-3].type_id).name, (yyvsp[-3].type_id).type, val, STRING_ARRAY_VALUE, scope_no, 0, 0, 1, NULL, yylineno, (yyvsp[-1].ival));
                              }else if(strcmp((yyvsp[-3].type_id).type, CHAR_TYPE_KEYWORD) == 0){
                                insert_symbol(symbol_table, (yyvsp[-3].type_id).name, (yyvsp[-3].type_id).type, val, CHAR_ARRAY_VALUE, scope_no, 0, 0, 1, NULL, yylineno, (yyvsp[-1].ival));
                              }else if(strcmp((yyvsp[-3].type_id).type, BOOL_TYPE_KEYWORD) == 0){
                                insert_symbol(symbol_table, (yyvsp[-3].type_id).name, (yyvsp[-3].type_id).type, val, INT_ARRAY_VALUE, scope_no, 0, 0, 1, NULL, yylineno, (yyvsp[-1].ival));
                              }
                              free((yyvsp[-3].type_id).name);
                              free((yyvsp[-3].type_id).type);
                          }
#line 2208 "parser.tab.c"
    break;

  case 78: /* $@17: %empty  */
#line 732 "parser.y"
                                              {
               SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[-2].sval), scope_no);
               if (!result) {
                   fprintf(stderr, "Undeclared identifier '%s' at line %d\n", (yyvsp[-2].sval), yylineno);
                   free_symbol_table(symbol_table);
                   exit(1);
               }
               if (result->is_constant) {
                   fprintf(stderr, "Cannot assign to constant '%s' at line %d\n", (yyvsp[-2].sval), yylineno);
                   free_symbol_table(symbol_table);
                   exit(1);
               }
               if (result->value_type == INT_ARRAY_VALUE || result->value_type == FLOAT_ARRAY_VALUE ||
                   result->value_type == CHAR_ARRAY_VALUE || result->value_type == STRING_ARRAY_VALUE) {
                   fprintf(stderr, "Cannot assign to array '%s' directly at line %d\n", (yyvsp[-2].sval), yylineno);
                   free_symbol_table(symbol_table);
                   exit(1);
               }
               if (result->value_type != (yyvsp[0].expr).expr_return_type) {
                   fprintf(stderr, "Type mismatch in assignment at line %d\n", yylineno);
                   free_symbol_table(symbol_table);
                   exit(1);
               }
               switch (result->value_type) {
                   case INT_VALUE:
                   case BOOL_VALUE:
                       result->value.int_value = (yyvsp[0].expr).expr_value.int_value;
                       break;
                   case FLOAT_VALUE:
                       result->value.float_value = (yyvsp[0].expr).expr_value.float_value;
                       break;
                   case CHAR_VALUE:
                       result->value.char_value = (yyvsp[0].expr).expr_value.char_value;
                       break;
                   case STRING_VALUE:
                       if (result->value.char_array) free(result->value.char_array);
                       result->value.char_array = strdup((yyvsp[0].expr).expr_value.char_array);
                       break;
                   default:
                       fprintf(stderr, "Unsupported type in assignment at line %d\n", yylineno);
                       free_symbol_table(symbol_table);
                       exit(1);
               }
           }
#line 2257 "parser.tab.c"
    break;

  case 80: /* $@18: %empty  */
#line 779 "parser.y"
                                                                                           {
                       SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[-4].sval), scope_no);
                       if (!result) {
                           fprintf(stderr, "Undeclared identifier '%s' at line %d\n", (yyvsp[-4].sval), yylineno);
                           free_symbol_table(symbol_table);
                           exit(1);
                       }
                       if (result->is_constant) {
                           fprintf(stderr, "Cannot assign to constant array '%s' at line %d\n", (yyvsp[-4].sval), yylineno);
                           free_symbol_table(symbol_table);
                           exit(1);
                       }
                       ValueType array_type = result->value_type;
                       ValueType element_type;
                       switch (array_type) {
                           case INT_ARRAY_VALUE:
                               element_type = INT_VALUE;
                               break;
                           case FLOAT_ARRAY_VALUE:
                               element_type = FLOAT_VALUE;
                               break;
                           case CHAR_ARRAY_VALUE:
                               element_type = CHAR_VALUE;
                               break;
                           case STRING_ARRAY_VALUE:
                               element_type = STRING_VALUE;
                               break;
                           default:
                               fprintf(stderr, "'%s' is not an array at line %d\n", (yyvsp[-4].sval), yylineno);
                               free_symbol_table(symbol_table);
                               exit(1);
                       }

                       size_t array_size = result->array_length;
                       size_t provided_size = 0;
                       expr_lst* current = &(yyvsp[-1].expr_lst);
                       while (current) {
                           provided_size++;
                           if (current->e->expr_return_type != element_type) {
                               fprintf(stderr, "Type mismatch in array assignment at line %d\n", yylineno);
                               free_symbol_table(symbol_table);
                               exit(1);
                           }
                           current = current->next_expr;
                       }

                       if (provided_size > array_size) {
                           fprintf(stderr, "Too many values in array assignment for '%s' at line %d\n", (yyvsp[-4].sval), yylineno);
                           free_symbol_table(symbol_table);
                           exit(1);
                       }

                       switch (array_type) {
                           case INT_ARRAY_VALUE:
                               if (result->value.int_array) free(result->value.int_array);
                               result->value.int_array = (int*)calloc(array_size, sizeof(int)); // Defaults to 0
                               current = &(yyvsp[-1].expr_lst);
                               for (size_t i = 0; i < provided_size; i++) {
                                   result->value.int_array[i] = current->e->expr_value.int_value;
                                   current = current->next_expr;
                               }
                               break;
                           case FLOAT_ARRAY_VALUE:
                               if (result->value.float_array) free(result->value.float_array);
                               result->value.float_array = (double*)calloc(array_size, sizeof(double)); // Defaults to 0.0
                               current = &(yyvsp[-1].expr_lst);
                               for (size_t i = 0; i < provided_size; i++) {
                                   result->value.float_array[i] = current->e->expr_value.float_value;
                                   current = current->next_expr;
                               }
                               break;
                           case CHAR_ARRAY_VALUE:
                               if (result->value.char_array) free(result->value.char_array);
                               result->value.char_array = (char*)calloc(array_size, sizeof(char)); // Defaults to '\0'
                               current = &(yyvsp[-1].expr_lst);
                               for (size_t i = 0; i < provided_size; i++) {
                                   result->value.char_array[i] = current->e->expr_value.char_value;
                                   current = current->next_expr;
                               }
                               break;
                           case STRING_ARRAY_VALUE:
                               if (result->value.string_array) {
                                   for (size_t i = 0; i < array_size; i++) {
                                       free(result->value.string_array[i]);
                                   }
                                   free(result->value.string_array);
                               }
                               result->value.string_array = (char**)malloc(array_size * sizeof(char*));
                               for (size_t i = 0; i < array_size; i++) {
                                   result->value.string_array[i] = strdup(""); // Default to ""
                               }
                               current = &(yyvsp[-1].expr_lst);
                               for (size_t i = 0; i < provided_size; i++) {
                                   free(result->value.string_array[i]);
                                   result->value.string_array[i] = strdup(current->e->expr_value.char_array);
                                   current = current->next_expr;
                               }
                               break;
                       }
                   }
#line 2362 "parser.tab.c"
    break;

  case 82: /* expression: boolean_expr  */
#line 883 "parser.y"
                          {
               (yyval.expr).expr_type = BOOL_EXPR;
               (yyval.expr).expr_value.int_value = (yyvsp[0].expr).expr_value.int_value; // Assume boolean_expr returns 0 or 1
               (yyval.expr).expr_return_type = BOOL_VALUE;
               (yyval.expr).associated_identifier = NULL;
           }
#line 2373 "parser.tab.c"
    break;

  case 83: /* expression: arithmetic_expr  */
#line 889 "parser.y"
                             {
               (yyval.expr) = (yyvsp[0].expr); // Directly propagate the expr struct from arithmetic_expr
           }
#line 2381 "parser.tab.c"
    break;

  case 84: /* expression: function_call  */
#line 892 "parser.y"
                           {
               (yyval.expr) = (yyvsp[0].expr); // Propagate from function_call, which sets type and value
           }
#line 2389 "parser.tab.c"
    break;

  case 85: /* expression: STRING_LITERAL  */
#line 895 "parser.y"
                            {
               (yyval.expr).expr_type = STRING_EXPR;
               (yyval.expr).expr_value.char_array = strdup((yyvsp[0].sval));
               (yyval.expr).expr_return_type = STRING_VALUE;
               (yyval.expr).associated_identifier = NULL;
           }
#line 2400 "parser.tab.c"
    break;

  case 86: /* expression: CHARACTER_LITERAL  */
#line 901 "parser.y"
                               {
               (yyval.expr).expr_type = CHAR_EXPR;
               (yyval.expr).expr_value.char_value = (yyvsp[0].cval);
               (yyval.expr).expr_return_type = CHAR_VALUE;
               (yyval.expr).associated_identifier = NULL;
           }
#line 2411 "parser.tab.c"
    break;

  case 87: /* expression: array_element  */
#line 907 "parser.y"
                           {
               (yyval.expr) = (yyvsp[0].expr); // Propagate from array_element
           }
#line 2419 "parser.tab.c"
    break;

  case 88: /* expression: IDENTIFIER  */
#line 910 "parser.y"
                        {
               SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[0].sval), scope_no);
               if (!result) {
                   fprintf(stderr, "Undeclared identifier '%s' at line %d\n", (yyvsp[0].sval), yylineno);
                   free_symbol_table(symbol_table);
                   exit(1);
               }
               (yyval.expr).expr_type = IDENTIFIER_EXPR;
               (yyval.expr).associated_identifier = strdup((yyvsp[0].sval));
               (yyval.expr).expr_return_type = result->value_type;
               switch (result->value_type) {
                   case INT_VALUE:
                   case BOOL_VALUE:
                       (yyval.expr).expr_value.int_value = result->value.int_value;
                       break;
                   case FLOAT_VALUE:
                       (yyval.expr).expr_value.float_value = result->value.float_value;
                       break;
                   case CHAR_VALUE:
                       (yyval.expr).expr_value.char_value = result->value.char_value;
                       break;
                   case STRING_VALUE:
                       (yyval.expr).expr_value.char_array = strdup(result->value.char_array);
                       break;
                   case INT_ARRAY_VALUE:
                       (yyval.expr).expr_value.int_array = result->value.int_array;
                       break;
                   case FLOAT_ARRAY_VALUE:
                       (yyval.expr).expr_value.float_array = result->value.float_array;
                       break;
                   case CHAR_ARRAY_VALUE:
                       (yyval.expr).expr_value.char_array = result->value.char_array;
                       break;
                   case STRING_ARRAY_VALUE:
                       (yyval.expr).expr_value.string_array = result->value.string_array;
                       break;
                   default:
                       fprintf(stderr, "Unsupported type for identifier '%s' at line %d\n", (yyvsp[0].sval), yylineno);
                       free_symbol_table(symbol_table);
                       exit(1);
               }
           }
#line 2466 "parser.tab.c"
    break;

  case 89: /* array_element: IDENTIFIER OPENING_SQUARE_BRACKETS INTEGER_LITERAL CLOSING_SQUARE_BRACKETS  */
#line 955 "parser.y"
                                                                                           {
                    SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[-3].sval), scope_no);
                    if (!result) {
                        fprintf(stderr, "Undeclared identifier '%s' at line %d\n", (yyvsp[-3].sval), yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    if (result->value_type != INT_ARRAY_VALUE && result->value_type != FLOAT_ARRAY_VALUE &&
                        result->value_type != CHAR_ARRAY_VALUE && result->value_type != STRING_ARRAY_VALUE) {
                        fprintf(stderr, "'%s' is not an array at line %d\n", (yyvsp[-3].sval), yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    if ((yyvsp[-1].ival) < 0 || (yyvsp[-1].ival) >= result->array_length) {
                        fprintf(stderr, "Array index out of bounds at line %d\n", yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    (yyval.expr).expr_type = ARRAY_ACCESS_EXPR;
                    (yyval.expr).associated_identifier = strdup((yyvsp[-3].sval));
                    switch (result->value_type) {
                        case INT_ARRAY_VALUE:
                            (yyval.expr).expr_return_type = INT_VALUE;
                            (yyval.expr).expr_value.int_value = result->value.int_array[(yyvsp[-1].ival)];
                            break;
                        case FLOAT_ARRAY_VALUE:
                            (yyval.expr).expr_return_type = FLOAT_VALUE;
                            (yyval.expr).expr_value.float_value = result->value.float_array[(yyvsp[-1].ival)];
                            break;
                        case CHAR_ARRAY_VALUE:
                            (yyval.expr).expr_return_type = CHAR_VALUE;
                            (yyval.expr).expr_value.char_value = result->value.char_array[(yyvsp[-1].ival)];
                            break;
                        case STRING_ARRAY_VALUE:
                            (yyval.expr).expr_return_type = STRING_VALUE;
                            (yyval.expr).expr_value.char_array = strdup(result->value.string_array[(yyvsp[-1].ival)]);
                            break;
                        default:
                            fprintf(stderr, "Unsupported array type at line %d\n", yylineno);
                            free_symbol_table(symbol_table);
                            exit(1);
                    }
                }
#line 2514 "parser.tab.c"
    break;

  case 90: /* expr_list: expression  */
#line 1000 "parser.y"
                       {
              (yyval.expr_lst).e = &(yyvsp[0].expr);
              (yyval.expr_lst).next_expr = NULL;
          }
#line 2523 "parser.tab.c"
    break;

  case 91: /* expr_list: expr_list COMMA expression  */
#line 1004 "parser.y"
                                       {
              expr_lst* new_node = (expr_lst*)malloc(sizeof(expr_lst));
              new_node->e = &(yyvsp[0].expr);
              new_node->next_expr = NULL;
              expr_lst* current = &(yyvsp[-2].expr_lst);
              while (current->next_expr) {
                  current = current->next_expr;
              }
              current->next_expr = new_node;
              (yyval.expr_lst) = (yyvsp[-2].expr_lst);
          }
#line 2539 "parser.tab.c"
    break;

  case 92: /* function_call: IDENTIFIER OPENING_PARENTHESIS expr_list CLOSING_PARENTHESIS  */
#line 1017 "parser.y"
                                                                             {
                    SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[-3].sval), scope_no);
                    if (!result) {
                        fprintf(stderr, "Undeclared identifier '%s' at line %d\n", (yyvsp[-3].sval), yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    if (!result->is_function) {
                        fprintf(stderr, "'%s' is not a function at line %d\n", (yyvsp[-3].sval), yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    Parameter* param = result->parameters;
                    expr_lst* arg = &(yyvsp[-1].expr_lst);
                    while (param && arg) {
                        ValueType param_type = string_to_value_type(param->type);
                        if (param_type != arg->e->expr_return_type) {
                            fprintf(stderr, "Parameter type mismatch for '%s' at line %d\n", (yyvsp[-3].sval), yylineno);
                            free_symbol_table(symbol_table);
                            exit(1);
                        }
                        param = param->next;
                        arg = arg->next_expr;
                    }
                    if (param || arg) {
                        fprintf(stderr, "Incorrect number of arguments for '%s' at line %d\n", (yyvsp[-3].sval), yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    (yyval.expr).expr_type = FUNCTION_CALL_EXPR;
                    (yyval.expr).associated_identifier = strdup((yyvsp[-3].sval));
                    (yyval.expr).expr_return_type = string_to_value_type(result->type);
                    // expr_value not set (requires execution)
                }
#line 2578 "parser.tab.c"
    break;

  case 93: /* function_call: IDENTIFIER OPENING_PARENTHESIS CLOSING_PARENTHESIS  */
#line 1051 "parser.y"
                                                                     {
                    SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[-2].sval), scope_no);
                    if (!result) {
                        fprintf(stderr, "Undeclared identifier '%s' at line %d\n", (yyvsp[-2].sval), yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    if (!result->is_function) {
                        fprintf(stderr, "'%s' is not a function at line %d\n", (yyvsp[-2].sval), yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    if (result->parameters) {
                        fprintf(stderr, "'%s' expects parameters at line %d\n", (yyvsp[-2].sval), yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    (yyval.expr).expr_type = FUNCTION_CALL_EXPR;
                    (yyval.expr).associated_identifier = strdup((yyvsp[-2].sval));
                    (yyval.expr).expr_return_type = string_to_value_type(result->type);
                }
#line 2604 "parser.tab.c"
    break;

  case 94: /* boolean_expr: expression EQUAL arithmetic_expr  */
#line 1074 "parser.y"
                                                {
                 if ((yyvsp[-2].expr).expr_return_type != (yyvsp[0].expr).expr_return_type &&
                     !((yyvsp[-2].expr).expr_return_type == INT_VALUE && (yyvsp[0].expr).expr_return_type == FLOAT_VALUE) &&
                     !((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE && (yyvsp[0].expr).expr_return_type == INT_VALUE)) {
                     fprintf(stderr, "Type mismatch in == at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 (yyval.expr).expr_type = BOOL_EXPR;
                 (yyval.expr).expr_return_type = BOOL_VALUE;
                 (yyval.expr).associated_identifier = NULL;
                 (yyval.expr).expr_value.int_value = 0; // Placeholder
             }
#line 2622 "parser.tab.c"
    break;

  case 95: /* boolean_expr: expression EQUAL function_call  */
#line 1087 "parser.y"
                                              {
                 if ((yyvsp[-2].expr).expr_return_type != (yyvsp[0].expr).expr_return_type &&
                     !((yyvsp[-2].expr).expr_return_type == INT_VALUE && (yyvsp[0].expr).expr_return_type == FLOAT_VALUE) &&
                     !((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE && (yyvsp[0].expr).expr_return_type == INT_VALUE)) {
                     fprintf(stderr, "Type mismatch in == at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 (yyval.expr).expr_type = BOOL_EXPR;
                 (yyval.expr).expr_return_type = BOOL_VALUE;
                 (yyval.expr).associated_identifier = NULL;
                 (yyval.expr).expr_value.int_value = 0; // Placeholder
             }
#line 2640 "parser.tab.c"
    break;

  case 96: /* boolean_expr: expression NOT_EQUAL arithmetic_expr  */
#line 1100 "parser.y"
                                                    {
                 if ((yyvsp[-2].expr).expr_return_type != (yyvsp[0].expr).expr_return_type &&
                     !((yyvsp[-2].expr).expr_return_type == INT_VALUE && (yyvsp[0].expr).expr_return_type == FLOAT_VALUE) &&
                     !((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE && (yyvsp[0].expr).expr_return_type == INT_VALUE)) {
                     fprintf(stderr, "Type mismatch in != at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 (yyval.expr).expr_type = BOOL_EXPR;
                 (yyval.expr).expr_return_type = BOOL_VALUE;
                 (yyval.expr).associated_identifier = NULL;
                 (yyval.expr).expr_value.int_value = 0; // Placeholder
             }
#line 2658 "parser.tab.c"
    break;

  case 97: /* boolean_expr: expression NOT_EQUAL function_call  */
#line 1113 "parser.y"
                                                  {
                 if ((yyvsp[-2].expr).expr_return_type != (yyvsp[0].expr).expr_return_type &&
                     !((yyvsp[-2].expr).expr_return_type == INT_VALUE && (yyvsp[0].expr).expr_return_type == FLOAT_VALUE) &&
                     !((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE && (yyvsp[0].expr).expr_return_type == INT_VALUE)) {
                     fprintf(stderr, "Type mismatch in != at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 (yyval.expr).expr_type = BOOL_EXPR;
                 (yyval.expr).expr_return_type = BOOL_VALUE;
                 (yyval.expr).associated_identifier = NULL;
                 (yyval.expr).expr_value.int_value = 0; // Placeholder
             }
#line 2676 "parser.tab.c"
    break;

  case 98: /* boolean_expr: expression GREATER_OR_EQUAL arithmetic_expr  */
#line 1126 "parser.y"
                                                           {
                 if (((yyvsp[-2].expr).expr_return_type != INT_VALUE && (yyvsp[-2].expr).expr_return_type != FLOAT_VALUE) ||
                     ((yyvsp[0].expr).expr_return_type != INT_VALUE && (yyvsp[0].expr).expr_return_type != FLOAT_VALUE)) {
                     fprintf(stderr, "Invalid types for >= at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 (yyval.expr).expr_type = BOOL_EXPR;
                 (yyval.expr).expr_return_type = BOOL_VALUE;
                 (yyval.expr).associated_identifier = NULL;
                 (yyval.expr).expr_value.int_value = 0; // Placeholder
             }
#line 2693 "parser.tab.c"
    break;

  case 99: /* boolean_expr: expression GREATER_OR_EQUAL function_call  */
#line 1138 "parser.y"
                                                         {
                 if (((yyvsp[-2].expr).expr_return_type != INT_VALUE && (yyvsp[-2].expr).expr_return_type != FLOAT_VALUE) ||
                     ((yyvsp[0].expr).expr_return_type != INT_VALUE && (yyvsp[0].expr).expr_return_type != FLOAT_VALUE)) {
                     fprintf(stderr, "Invalid types for >= at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 (yyval.expr).expr_type = BOOL_EXPR;
                 (yyval.expr).expr_return_type = BOOL_VALUE;
                 (yyval.expr).associated_identifier = NULL;
                 (yyval.expr).expr_value.int_value = 0; // Placeholder
             }
#line 2710 "parser.tab.c"
    break;

  case 100: /* boolean_expr: expression LESS_OR_EQUAL arithmetic_expr  */
#line 1150 "parser.y"
                                                        {
                 if (((yyvsp[-2].expr).expr_return_type != INT_VALUE && (yyvsp[-2].expr).expr_return_type != FLOAT_VALUE) ||
                     ((yyvsp[0].expr).expr_return_type != INT_VALUE && (yyvsp[0].expr).expr_return_type != FLOAT_VALUE)) {
                     fprintf(stderr, "Invalid types for <= at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 (yyval.expr).expr_type = BOOL_EXPR;
                 (yyval.expr).expr_return_type = BOOL_VALUE;
                 (yyval.expr).associated_identifier = NULL;
                 (yyval.expr).expr_value.int_value = 0; // Placeholder
             }
#line 2727 "parser.tab.c"
    break;

  case 101: /* boolean_expr: expression LESS_OR_EQUAL function_call  */
#line 1162 "parser.y"
                                                      {
                 if (((yyvsp[-2].expr).expr_return_type != INT_VALUE && (yyvsp[-2].expr).expr_return_type != FLOAT_VALUE) ||
                     ((yyvsp[0].expr).expr_return_type != INT_VALUE && (yyvsp[0].expr).expr_return_type != FLOAT_VALUE)) {
                     fprintf(stderr, "Invalid types for <= at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 (yyval.expr).expr_type = BOOL_EXPR;
                 (yyval.expr).expr_return_type = BOOL_VALUE;
                 (yyval.expr).associated_identifier = NULL;
                 (yyval.expr).expr_value.int_value = 0; // Placeholder
             }
#line 2744 "parser.tab.c"
    break;

  case 102: /* boolean_expr: expression GREATER arithmetic_expr  */
#line 1174 "parser.y"
                                                  {
                 if (((yyvsp[-2].expr).expr_return_type != INT_VALUE && (yyvsp[-2].expr).expr_return_type != FLOAT_VALUE) ||
                     ((yyvsp[0].expr).expr_return_type != INT_VALUE && (yyvsp[0].expr).expr_return_type != FLOAT_VALUE)) {
                     fprintf(stderr, "Invalid types for > at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 (yyval.expr).expr_type = BOOL_EXPR;
                 (yyval.expr).expr_return_type = BOOL_VALUE;
                 (yyval.expr).associated_identifier = NULL;
                 (yyval.expr).expr_value.int_value = 0; // Placeholder
             }
#line 2761 "parser.tab.c"
    break;

  case 103: /* boolean_expr: expression GREATER function_call  */
#line 1186 "parser.y"
                                                {
                 if (((yyvsp[-2].expr).expr_return_type != INT_VALUE && (yyvsp[-2].expr).expr_return_type != FLOAT_VALUE) ||
                     ((yyvsp[0].expr).expr_return_type != INT_VALUE && (yyvsp[0].expr).expr_return_type != FLOAT_VALUE)) {
                     fprintf(stderr, "Invalid types for > at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 (yyval.expr).expr_type = BOOL_EXPR;
                 (yyval.expr).expr_return_type = BOOL_VALUE;
                 (yyval.expr).associated_identifier = NULL;
                 (yyval.expr).expr_value.int_value = 0; // Placeholder
             }
#line 2778 "parser.tab.c"
    break;

  case 104: /* boolean_expr: expression LESS arithmetic_expr  */
#line 1198 "parser.y"
                                               {
                 if (((yyvsp[-2].expr).expr_return_type != INT_VALUE && (yyvsp[-2].expr).expr_return_type != FLOAT_VALUE) ||
                     ((yyvsp[0].expr).expr_return_type != INT_VALUE && (yyvsp[0].expr).expr_return_type != FLOAT_VALUE)) {
                     fprintf(stderr, "Invalid types for < at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 (yyval.expr).expr_type = BOOL_EXPR;
                 (yyval.expr).expr_return_type = BOOL_VALUE;
                 (yyval.expr).associated_identifier = NULL;
                 (yyval.expr).expr_value.int_value = 0; // Placeholder
             }
#line 2795 "parser.tab.c"
    break;

  case 105: /* boolean_expr: expression LESS function_call  */
#line 1210 "parser.y"
                                             {
                 if (((yyvsp[-2].expr).expr_return_type != INT_VALUE && (yyvsp[-2].expr).expr_return_type != FLOAT_VALUE) ||
                     ((yyvsp[0].expr).expr_return_type != INT_VALUE && (yyvsp[0].expr).expr_return_type != FLOAT_VALUE)) {
                     fprintf(stderr, "Invalid types for < at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 (yyval.expr).expr_type = BOOL_EXPR;
                 (yyval.expr).expr_return_type = BOOL_VALUE;
                 (yyval.expr).associated_identifier = NULL;
                 (yyval.expr).expr_value.int_value = 0; // Placeholder
             }
#line 2812 "parser.tab.c"
    break;

  case 106: /* boolean_expr: expression AND_KEYWORD arithmetic_expr  */
#line 1222 "parser.y"
                                                      {
                 if ((yyvsp[-2].expr).expr_return_type != BOOL_VALUE || (yyvsp[0].expr).expr_return_type != BOOL_VALUE) {
                     fprintf(stderr, "AND requires boolean operands at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 (yyval.expr).expr_type = BOOL_EXPR;
                 (yyval.expr).expr_return_type = BOOL_VALUE;
                 (yyval.expr).associated_identifier = NULL;
                 (yyval.expr).expr_value.int_value = 0;
             }
#line 2828 "parser.tab.c"
    break;

  case 107: /* boolean_expr: expression AND_KEYWORD function_call  */
#line 1233 "parser.y"
                                                    {
                 if ((yyvsp[-2].expr).expr_return_type != BOOL_VALUE || (yyvsp[0].expr).expr_return_type != BOOL_VALUE) {
                     fprintf(stderr, "AND requires boolean operands at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 (yyval.expr).expr_type = BOOL_EXPR;
                 (yyval.expr).expr_return_type = BOOL_VALUE;
                 (yyval.expr).associated_identifier = NULL;
                 (yyval.expr).expr_value.int_value = 0;
             }
#line 2844 "parser.tab.c"
    break;

  case 108: /* boolean_expr: expression OR_KEYWORD arithmetic_expr  */
#line 1244 "parser.y"
                                                     {
                 if ((yyvsp[-2].expr).expr_return_type != BOOL_VALUE || (yyvsp[0].expr).expr_return_type != BOOL_VALUE) {
                     fprintf(stderr, "OR requires boolean operands at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 (yyval.expr).expr_type = BOOL_EXPR;
                 (yyval.expr).expr_return_type = BOOL_VALUE;
                 (yyval.expr).associated_identifier = NULL;
                 (yyval.expr).expr_value.int_value = 0;
             }
#line 2860 "parser.tab.c"
    break;

  case 109: /* boolean_expr: expression OR_KEYWORD function_call  */
#line 1255 "parser.y"
                                                   {
                 if ((yyvsp[-2].expr).expr_return_type != BOOL_VALUE || (yyvsp[0].expr).expr_return_type != BOOL_VALUE) {
                     fprintf(stderr, "OR requires boolean operands at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 (yyval.expr).expr_type = BOOL_EXPR;
                 (yyval.expr).expr_return_type = BOOL_VALUE;
                 (yyval.expr).associated_identifier = NULL;
                 (yyval.expr).expr_value.int_value = 0;
             }
#line 2876 "parser.tab.c"
    break;

  case 110: /* boolean_expr: NOT_KEYWORD OPENING_PARENTHESIS expression CLOSING_PARENTHESIS  */
#line 1266 "parser.y"
                                                                              {
                 if ((yyvsp[-1].expr).expr_return_type != BOOL_VALUE) {
                     fprintf(stderr, "! requires boolean operand at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 (yyval.expr).expr_type = BOOL_EXPR;
                 (yyval.expr).expr_return_type = BOOL_VALUE;
                 (yyval.expr).associated_identifier = NULL;
                 (yyval.expr).expr_value.int_value = 0;
             }
#line 2892 "parser.tab.c"
    break;

  case 111: /* boolean_expr: NOT_KEYWORD function_call  */
#line 1277 "parser.y"
                                         {
                 if ((yyvsp[0].expr).expr_return_type != BOOL_VALUE) {
                     fprintf(stderr, "! requires boolean operand at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 (yyval.expr).expr_type = BOOL_EXPR;
                 (yyval.expr).expr_return_type = BOOL_VALUE;
                 (yyval.expr).associated_identifier = NULL;
                 (yyval.expr).expr_value.int_value = 0;
             }
#line 2908 "parser.tab.c"
    break;

  case 112: /* boolean_expr: BOOLEAN_LITERAL  */
#line 1288 "parser.y"
                               {
                 (yyval.expr).expr_type = BOOL_EXPR;
                 (yyval.expr).expr_return_type = BOOL_VALUE;
                 (yyval.expr).expr_value.int_value = (yyvsp[0].ival);
                 (yyval.expr).associated_identifier = NULL;
             }
#line 2919 "parser.tab.c"
    break;

  case 113: /* arithmetic_expr: binary_expr  */
#line 1297 "parser.y"
                              { (yyval.expr) = (yyvsp[0].expr); }
#line 2925 "parser.tab.c"
    break;

  case 114: /* arithmetic_expr: unary_expr  */
#line 1298 "parser.y"
                             { (yyval.expr) = (yyvsp[0].expr); }
#line 2931 "parser.tab.c"
    break;

  case 115: /* binary_expr: binary_expr PLUS arithmetic_term  */
#line 1301 "parser.y"
                                               {
                if ((yyvsp[-2].expr).expr_return_type != INT_VALUE && (yyvsp[-2].expr).expr_return_type != FLOAT_VALUE ||
                    (yyvsp[0].expr).expr_return_type != INT_VALUE && (yyvsp[0].expr).expr_return_type != FLOAT_VALUE) {
                    fprintf(stderr, "Invalid types for + at line %d\n", yylineno);
                    free_symbol_table(symbol_table);
                    exit(1);
                }
                (yyval.expr).expr_type = NUMERIC_EXPR;
                (yyval.expr).associated_identifier = NULL;
                if ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE || (yyvsp[0].expr).expr_return_type == FLOAT_VALUE) {
                    (yyval.expr).expr_return_type = FLOAT_VALUE;
                    float left = ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[-2].expr).expr_value.float_value : (yyvsp[-2].expr).expr_value.int_value;
                    float right = ((yyvsp[0].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[0].expr).expr_value.float_value : (yyvsp[0].expr).expr_value.int_value;
                    (yyval.expr).expr_value.float_value = left + right;
                } else {
                    (yyval.expr).expr_return_type = INT_VALUE;
                    (yyval.expr).expr_value.int_value = (yyvsp[-2].expr).expr_value.int_value + (yyvsp[0].expr).expr_value.int_value;
                }
            }
#line 2955 "parser.tab.c"
    break;

  case 116: /* binary_expr: binary_expr MINUS arithmetic_term  */
#line 1320 "parser.y"
                                                {
                if ((yyvsp[-2].expr).expr_return_type != INT_VALUE && (yyvsp[-2].expr).expr_return_type != FLOAT_VALUE ||
                    (yyvsp[0].expr).expr_return_type != INT_VALUE && (yyvsp[0].expr).expr_return_type != FLOAT_VALUE) {
                    fprintf(stderr, "Invalid types for - at line %d\n", yylineno);
                    free_symbol_table(symbol_table);
                    exit(1);
                }
                (yyval.expr).expr_type = NUMERIC_EXPR;
                (yyval.expr).associated_identifier = NULL;
                if ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE || (yyvsp[0].expr).expr_return_type == FLOAT_VALUE) {
                    (yyval.expr).expr_return_type = FLOAT_VALUE;
                    float left = ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[-2].expr).expr_value.float_value : (yyvsp[-2].expr).expr_value.int_value;
                    float right = ((yyvsp[0].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[0].expr).expr_value.float_value : (yyvsp[0].expr).expr_value.int_value;
                    (yyval.expr).expr_value.float_value = left - right;
                } else {
                    (yyval.expr).expr_return_type = INT_VALUE;
                    (yyval.expr).expr_value.int_value = (yyvsp[-2].expr).expr_value.int_value - (yyvsp[0].expr).expr_value.int_value;
                }
            }
#line 2979 "parser.tab.c"
    break;

  case 117: /* binary_expr: arithmetic_term  */
#line 1339 "parser.y"
                              { (yyval.expr) = (yyvsp[0].expr); }
#line 2985 "parser.tab.c"
    break;

  case 118: /* arithmetic_term: arithmetic_term ASTRISK arithmetic_factor  */
#line 1342 "parser.y"
                                                            {
                    if ((yyvsp[-2].expr).expr_return_type != INT_VALUE && (yyvsp[-2].expr).expr_return_type != FLOAT_VALUE ||
                        (yyvsp[0].expr).expr_return_type != INT_VALUE && (yyvsp[0].expr).expr_return_type != FLOAT_VALUE) {
                        fprintf(stderr, "Invalid types for * at line %d\n", yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    (yyval.expr).expr_type = NUMERIC_EXPR;
                    (yyval.expr).associated_identifier = NULL;
                    if ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE || (yyvsp[0].expr).expr_return_type == FLOAT_VALUE) {
                        (yyval.expr).expr_return_type = FLOAT_VALUE;
                        float left = ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[-2].expr).expr_value.float_value : (yyvsp[-2].expr).expr_value.int_value;
                        float right = ((yyvsp[0].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[0].expr).expr_value.float_value : (yyvsp[0].expr).expr_value.int_value;
                        (yyval.expr).expr_value.float_value = left * right;
                    } else {
                        (yyval.expr).expr_return_type = INT_VALUE;
                        (yyval.expr).expr_value.int_value = (yyvsp[-2].expr).expr_value.int_value * (yyvsp[0].expr).expr_value.int_value;
                    }
                }
#line 3009 "parser.tab.c"
    break;

  case 119: /* arithmetic_term: arithmetic_term DIVIDE arithmetic_factor  */
#line 1361 "parser.y"
                                                           {
                    if ((yyvsp[-2].expr).expr_return_type != INT_VALUE && (yyvsp[-2].expr).expr_return_type != FLOAT_VALUE ||
                        (yyvsp[0].expr).expr_return_type != INT_VALUE && (yyvsp[0].expr).expr_return_type != FLOAT_VALUE) {
                        fprintf(stderr, "Invalid types for / at line %d\n", yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    if (((yyvsp[0].expr).expr_return_type == INT_VALUE && (yyvsp[0].expr).expr_value.int_value == 0) ||
                        ((yyvsp[0].expr).expr_return_type == FLOAT_VALUE && (yyvsp[0].expr).expr_value.float_value == 0.0)) {
                        fprintf(stderr, "Division by zero at line %d\n", yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    (yyval.expr).expr_type = NUMERIC_EXPR;
                    (yyval.expr).associated_identifier = NULL;
                    if ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE || (yyvsp[0].expr).expr_return_type == FLOAT_VALUE) {
                        (yyval.expr).expr_return_type = FLOAT_VALUE;
                        float left = ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[-2].expr).expr_value.float_value : (yyvsp[-2].expr).expr_value.int_value;
                        float right = ((yyvsp[0].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[0].expr).expr_value.float_value : (yyvsp[0].expr).expr_value.int_value;
                        (yyval.expr).expr_value.float_value = left / right;
                    } else {
                        (yyval.expr).expr_return_type = INT_VALUE;
                        (yyval.expr).expr_value.int_value = (yyvsp[-2].expr).expr_value.int_value / (yyvsp[0].expr).expr_value.int_value;
                    }
                }
#line 3039 "parser.tab.c"
    break;

  case 120: /* arithmetic_term: arithmetic_term MODULO INTEGER_LITERAL  */
#line 1386 "parser.y"
                                                         {
                    if ((yyvsp[-2].expr).expr_return_type != INT_VALUE) {
                        fprintf(stderr, "Modulo requires integer operand at line %d\n", yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    if ((yyvsp[0].ival) == 0) {
                        fprintf(stderr, "Modulo by zero at line %d\n", yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    (yyval.expr).expr_type = NUMERIC_EXPR;
                    (yyval.expr).expr_return_type = INT_VALUE;
                    (yyval.expr).expr_value.int_value = (yyvsp[-2].expr).expr_value.int_value % (yyvsp[0].ival);
                    (yyval.expr).associated_identifier = NULL;
                }
#line 3060 "parser.tab.c"
    break;

  case 121: /* arithmetic_term: arithmetic_term MODULO OPENING_PARENTHESIS expression CLOSING_PARENTHESIS  */
#line 1402 "parser.y"
                                                                                            {
                    if ((yyvsp[-4].expr).expr_return_type != INT_VALUE || (yyvsp[-1].expr).expr_return_type != INT_VALUE) {
                        fprintf(stderr, "Modulo requires integer operands at line %d\n", yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    if ((yyvsp[-1].expr).expr_value.int_value == 0) {
                        fprintf(stderr, "Modulo by zero at line %d\n", yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    (yyval.expr).expr_type = NUMERIC_EXPR;
                    (yyval.expr).expr_return_type = INT_VALUE;
                    (yyval.expr).expr_value.int_value = (yyvsp[-4].expr).expr_value.int_value % (yyvsp[-1].expr).expr_value.int_value;
                    (yyval.expr).associated_identifier = NULL;
                }
#line 3081 "parser.tab.c"
    break;

  case 122: /* arithmetic_term: arithmetic_factor  */
#line 1418 "parser.y"
                                    { (yyval.expr) = (yyvsp[0].expr); }
#line 3087 "parser.tab.c"
    break;

  case 123: /* arithmetic_factor: bitwise_expr  */
#line 1421 "parser.y"
                                 { (yyval.expr) = (yyvsp[0].expr); }
#line 3093 "parser.tab.c"
    break;

  case 124: /* arithmetic_factor: FLOAT_LITERAL  */
#line 1422 "parser.y"
                                  {
                      (yyval.expr).expr_type = FLOAT_EXPR;
                      (yyval.expr).expr_value.float_value = (yyvsp[0].fval);
                      (yyval.expr).expr_return_type = FLOAT_VALUE;
                      (yyval.expr).associated_identifier = NULL;
                  }
#line 3104 "parser.tab.c"
    break;

  case 125: /* arithmetic_factor: OPENING_PARENTHESIS expression CLOSING_PARENTHESIS  */
#line 1428 "parser.y"
                                                                       { (yyval.expr) = (yyvsp[-1].expr); }
#line 3110 "parser.tab.c"
    break;

  case 126: /* bitwise_expr: bitwise_expr BITWISE_OR bitwise_xor_expr  */
#line 1431 "parser.y"
                                                        {
                 if ((yyvsp[-2].expr).expr_return_type != INT_VALUE || (yyvsp[0].expr).expr_return_type != INT_VALUE) {
                     fprintf(stderr, "Bitwise OR requires integer operands at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 (yyval.expr).expr_type = NUMERIC_EXPR;
                 (yyval.expr).expr_return_type = INT_VALUE;
                 (yyval.expr).expr_value.int_value = (yyvsp[-2].expr).expr_value.int_value | (yyvsp[0].expr).expr_value.int_value;
                 (yyval.expr).associated_identifier = NULL;
             }
#line 3126 "parser.tab.c"
    break;

  case 127: /* bitwise_expr: bitwise_xor_expr  */
#line 1442 "parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 3132 "parser.tab.c"
    break;

  case 128: /* bitwise_xor_expr: bitwise_xor_expr BITWISE_XOR bitwise_and_expr  */
#line 1445 "parser.y"
                                                                 {
                     if ((yyvsp[-2].expr).expr_return_type != INT_VALUE || (yyvsp[0].expr).expr_return_type != INT_VALUE) {
                         fprintf(stderr, "Bitwise XOR requires integer operands at line %d\n", yylineno);
                         free_symbol_table(symbol_table);
                         exit(1);
                     }
                     (yyval.expr).expr_type = NUMERIC_EXPR;
                     (yyval.expr).expr_return_type = INT_VALUE;
                     (yyval.expr).expr_value.int_value = (yyvsp[-2].expr).expr_value.int_value ^ (yyvsp[0].expr).expr_value.int_value;
                     (yyval.expr).associated_identifier = NULL;
                 }
#line 3148 "parser.tab.c"
    break;

  case 129: /* bitwise_xor_expr: bitwise_and_expr  */
#line 1456 "parser.y"
                                    { (yyval.expr) = (yyvsp[0].expr); }
#line 3154 "parser.tab.c"
    break;

  case 130: /* bitwise_and_expr: bitwise_and_expr BITWISE_AND bitwise_not_expr  */
#line 1459 "parser.y"
                                                                 {
                     if ((yyvsp[-2].expr).expr_return_type != INT_VALUE || (yyvsp[0].expr).expr_return_type != INT_VALUE) {
                         fprintf(stderr, "Bitwise AND requires integer operands at line %d\n", yylineno);
                         free_symbol_table(symbol_table);
                         exit(1);
                     }
                     (yyval.expr).expr_type = NUMERIC_EXPR;
                     (yyval.expr).expr_return_type = INT_VALUE;
                     (yyval.expr).expr_value.int_value = (yyvsp[-2].expr).expr_value.int_value & (yyvsp[0].expr).expr_value.int_value;
                     (yyval.expr).associated_identifier = NULL;
                 }
#line 3170 "parser.tab.c"
    break;

  case 131: /* bitwise_and_expr: bitwise_not_expr  */
#line 1470 "parser.y"
                                    { (yyval.expr) = (yyvsp[0].expr); }
#line 3176 "parser.tab.c"
    break;

  case 132: /* bitwise_not_expr: BITWISE_NOT bitwise_not_expr  */
#line 1473 "parser.y"
                                                {
                     if ((yyvsp[0].expr).expr_return_type != INT_VALUE) {
                         fprintf(stderr, "Bitwise NOT requires integer operand at line %d\n", yylineno);
                         free_symbol_table(symbol_table);
                         exit(1);
                     }
                     (yyval.expr).expr_type = NUMERIC_EXPR;
                     (yyval.expr).expr_return_type = INT_VALUE;
                     (yyval.expr).expr_value.int_value = ~(yyvsp[0].expr).expr_value.int_value;
                     (yyval.expr).associated_identifier = NULL;
                 }
#line 3192 "parser.tab.c"
    break;

  case 133: /* bitwise_not_expr: INTEGER_LITERAL  */
#line 1484 "parser.y"
                                   {
                     (yyval.expr).expr_type = INT_EXPR;
                     (yyval.expr).expr_return_type = INT_VALUE;
                     (yyval.expr).expr_value.int_value = (yyvsp[0].ival);
                     (yyval.expr).associated_identifier = NULL;
                 }
#line 3203 "parser.tab.c"
    break;

  case 134: /* unary_expr: IDENTIFIER INCREMENT  */
#line 1492 "parser.y"
                                  {
               SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[-1].sval), scope_no);
               if (!result) {
                   fprintf(stderr, "Undeclared identifier '%s' at line %d\n", (yyvsp[-1].sval), yylineno);
                   free_symbol_table(symbol_table);
                   exit(1);
               }
               if (result->value_type != INT_VALUE && result->value_type != FLOAT_VALUE) {
                   fprintf(stderr, "Increment requires numeric operand at line %d\n", yylineno);
                   free_symbol_table(symbol_table);
                   exit(1);
               }
               if (result->is_constant) {
                   fprintf(stderr, "Cannot increment constant '%s' at line %d\n", (yyvsp[-1].sval), yylineno);
                   free_symbol_table(symbol_table);
                   exit(1);
               }
               (yyval.expr).expr_type = NUMERIC_EXPR;
               (yyval.expr).associated_identifier = strdup((yyvsp[-1].sval));
               if (result->value_type == INT_VALUE) {
                   (yyval.expr).expr_return_type = INT_VALUE;
                   (yyval.expr).expr_value.int_value = result->value.int_value++;
               } else {
                   (yyval.expr).expr_return_type = FLOAT_VALUE;
                   (yyval.expr).expr_value.float_value = result->value.float_value++;
               }
           }
#line 3235 "parser.tab.c"
    break;

  case 135: /* unary_expr: IDENTIFIER DECREMENT  */
#line 1519 "parser.y"
                                  {
               SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[-1].sval), scope_no);
               if (!result) {
                   fprintf(stderr, "Undeclared identifier '%s' at line %d\n", (yyvsp[-1].sval), yylineno);
                   free_symbol_table(symbol_table);
                   exit(1);
               }
               if (result->value_type != INT_VALUE && result->value_type != FLOAT_VALUE) {
                   fprintf(stderr, "Decrement requires numeric operand at line %d\n", yylineno);
                   free_symbol_table(symbol_table);
                   exit(1);
               }
               if (result->is_constant) {
                   fprintf(stderr, "Cannot decrement constant '%s' at line %d\n", (yyvsp[-1].sval), yylineno);
                   free_symbol_table(symbol_table);
                   exit(1);
               }
               (yyval.expr).expr_type = NUMERIC_EXPR;
               (yyval.expr).associated_identifier = strdup((yyvsp[-1].sval));
               if (result->value_type == INT_VALUE) {
                   (yyval.expr).expr_return_type = INT_VALUE;
                   (yyval.expr).expr_value.int_value = result->value.int_value--;
               } else {
                   (yyval.expr).expr_return_type = FLOAT_VALUE;
                   (yyval.expr).expr_value.float_value = result->value.float_value--;
               }
           }
#line 3267 "parser.tab.c"
    break;

  case 136: /* unary_expr: MINUS IDENTIFIER  */
#line 1546 "parser.y"
                              {
               SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[0].sval), scope_no);
               if (!result) {
                   fprintf(stderr, "Undeclared identifier '%s' at line %d\n", (yyvsp[0].sval), yylineno);
                   free_symbol_table(symbol_table);
                   exit(1);
               }
               if (result->value_type != INT_VALUE && result->value_type != FLOAT_VALUE) {
                   fprintf(stderr, "Unary minus requires numeric operand at line %d\n", yylineno);
                   free_symbol_table(symbol_table);
                   exit(1);
               }
               (yyval.expr).expr_type = NUMERIC_EXPR;
               (yyval.expr).associated_identifier = NULL;
               if (result->value_type == INT_VALUE) {
                   (yyval.expr).expr_return_type = INT_VALUE;
                   (yyval.expr).expr_value.int_value = -result->value.int_value;
               } else {
                   (yyval.expr).expr_return_type = FLOAT_VALUE;
                   (yyval.expr).expr_value.float_value = -result->value.float_value;
               }
           }
#line 3294 "parser.tab.c"
    break;

  case 137: /* unary_expr: MINUS OPENING_PARENTHESIS expression CLOSING_PARENTHESIS  */
#line 1568 "parser.y"
                                                                      {
               if ((yyvsp[-1].expr).expr_return_type != INT_VALUE && (yyvsp[-1].expr).expr_return_type != FLOAT_VALUE) {
                   fprintf(stderr, "Unary minus requires numeric operand at line %d\n", yylineno);
                   free_symbol_table(symbol_table);
                   exit(1);
               }
               (yyval.expr).expr_type = NUMERIC_EXPR;
               (yyval.expr).associated_identifier = NULL;
               if ((yyvsp[-1].expr).expr_return_type == INT_VALUE) {
                   (yyval.expr).expr_return_type = INT_VALUE;
                   (yyval.expr).expr_value.int_value = -(yyvsp[-1].expr).expr_value.int_value;
               } else {
                   (yyval.expr).expr_return_type = FLOAT_VALUE;
                   (yyval.expr).expr_value.float_value = -(yyvsp[-1].expr).expr_value.float_value;
               }
           }
#line 3315 "parser.tab.c"
    break;

  case 138: /* unary_expr: OPENING_PARENTHESIS expression CLOSING_PARENTHESIS INCREMENT  */
#line 1584 "parser.y"
                                                                          {
               fprintf(stderr, "Increment on expression not supported at line %d\n", yylineno);
               free_symbol_table(symbol_table);
               exit(1);
           }
#line 3325 "parser.tab.c"
    break;

  case 139: /* unary_expr: OPENING_PARENTHESIS expression CLOSING_PARENTHESIS DECREMENT  */
#line 1589 "parser.y"
                                                                          {
               fprintf(stderr, "Decrement on expression not supported at line %d\n", yylineno);
               free_symbol_table(symbol_table);
               exit(1);
           }
#line 3335 "parser.tab.c"
    break;


#line 3339 "parser.tab.c"

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

#line 1601 "parser.y"

