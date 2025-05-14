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
#include <stdlib.h>
#include <stdbool.h>
#include "symbol_table.h"

void yyerror(const char *s);
int yylex(void);
extern FILE* yyin;
extern int yylineno;
extern char* yytext;
extern FILE* symbol_table_file;
extern FILE* symbol_table_changes_file;


SymbolTable* symbol_table = NULL;
Parameter* curr_function_parameter_list = NULL;
Parameter* curr_function_parameter_list_ptr = NULL;
Parameter* curr_function_instructions_list = NULL;
int inside_a_function_declaration_body = 0;

// Function stack for nested functions
typedef struct FunctionStack {
    char* function_name;
    struct FunctionStack* next;
} FunctionStack;

char* concat_strings(const char* s1, const char* s2) {
    if (!s1 || !s2) return NULL;  // handle null pointers

    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    // +1 for null terminator
    char* result = malloc(len1 + len2 + 1);
    if (!result) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    strcpy(result, s1);
    strcat(result, s2);

    return result;
}


ValueType string_to_value_type(const char* type_str) {
    if (strcmp(type_str, "int") == 0) return INT_VALUE;
    else if (strcmp(type_str, "float") == 0) return FLOAT_VALUE;
    else if (strcmp(type_str, "char") == 0) return CHAR_VALUE;
    else if (strcmp(type_str, "string") == 0) return STRING_VALUE;
    else if (strcmp(type_str, "bool") == 0) return BOOL_VALUE;
    else if (strcmp(type_str, "void") == 0) return VOID;
    else {
        fprintf(stderr, "Unknown type '%s' at line %d\n", type_str, yylineno);
        free_symbol_table(symbol_table);
        exit(1);
    }
}

ValueType keyword_to_array_value_type(const char* keyword) {
    if (strncmp(keyword, "aint", 3) == 0) return INT_ARRAY_VALUE;
    if (strncmp(keyword, "afloat", 5) == 0) return FLOAT_ARRAY_VALUE;
    if (strncmp(keyword, "astring", 6) == 0) return STRING_ARRAY_VALUE;
    if (strncmp(keyword, "achar", 4) == 0) return CHAR_ARRAY_VALUE;
    if (strncmp(keyword, "abool", 4) == 0) return BOOL_ARRAY_VALUE;
    fprintf(stderr, "Invalid array type '%s' at line %d\n", keyword, yylineno);
    free_symbol_table(symbol_table);
    exit(1);
}

FunctionStack* function_stack = NULL;

void push_function(const char* name) {
    FunctionStack* node = (FunctionStack*)malloc(sizeof(FunctionStack));
    if (!node) {
        fprintf(stderr, "Memory allocation for function stack failed at line %d\n", yylineno);
        exit(1);
    }
    node->function_name = strdup(name);
    if (!node->function_name) {
        fprintf(stderr, "Memory allocation for function name failed at line %d\n", yylineno);
        free(node);
        exit(1);
    }
    node->next = function_stack;
    function_stack = node;
}

char* pop_function(void) {
    if (!function_stack) return NULL;
    FunctionStack* node = function_stack;
    char* name = node->function_name;
    function_stack = node->next;
    free(node);
    return name;
}

char* get_current_enclosing_function(void) {
    if (!function_stack) return NULL;
    return function_stack->function_name;
}

char* get_prev_enclosing_function(void) {
    if (!function_stack || !function_stack->next) return NULL;
    return function_stack->next->function_name;
}

void free_function_stack(void) {
    while (function_stack) {
        FunctionStack* node = function_stack;
        function_stack = node->next;
        free(node->function_name);
        free(node);
    }
}

int init_compiler(void) {
    symbol_table = create_symbol_table();
    if (!symbol_table) {
        fprintf(stderr, "Error: Failed to create symbol table\n");
        return 0;
    }
    return 1;
}

void cleanup_compiler(void) {
    free_symbol_table(symbol_table);
    symbol_table = NULL;
    free_function_stack();
}


void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s (token: '%s')\n", yylineno, s, yytext);
    free_function_stack();
    free_symbol_table(symbol_table);
    exit(1);
}


#line 215 "parser.tab.c"

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
  YYSYMBOL_78_9 = 78,                      /* $@9  */
  YYSYMBOL_79_10 = 79,                     /* $@10  */
  YYSYMBOL_statement = 80,                 /* statement  */
  YYSYMBOL_if_statement = 81,              /* if_statement  */
  YYSYMBOL_82_11 = 82,                     /* $@11  */
  YYSYMBOL_elseif_statement = 83,          /* elseif_statement  */
  YYSYMBOL_else_statement = 84,            /* else_statement  */
  YYSYMBOL_for_statement = 85,             /* for_statement  */
  YYSYMBOL_86_12 = 86,                     /* $@12  */
  YYSYMBOL_loop_start = 87,                /* loop_start  */
  YYSYMBOL_loop_update = 88,               /* loop_update  */
  YYSYMBOL_while_statement = 89,           /* while_statement  */
  YYSYMBOL_90_13 = 90,                     /* $@13  */
  YYSYMBOL_do_while_statement = 91,        /* do_while_statement  */
  YYSYMBOL_92_14 = 92,                     /* $@14  */
  YYSYMBOL_switch_statement = 93,          /* switch_statement  */
  YYSYMBOL_94_15 = 94,                     /* $@15  */
  YYSYMBOL_95_16 = 95,                     /* $@16  */
  YYSYMBOL_default_case = 96,              /* default_case  */
  YYSYMBOL_case_list = 97,                 /* case_list  */
  YYSYMBOL_case_statement = 98,            /* case_statement  */
  YYSYMBOL_initialization = 99,            /* initialization  */
  YYSYMBOL_100_17 = 100,                   /* $@17  */
  YYSYMBOL_101_18 = 101,                   /* $@18  */
  YYSYMBOL_const_initialization = 102,     /* const_initialization  */
  YYSYMBOL_103_19 = 103,                   /* $@19  */
  YYSYMBOL_variable_declaration = 104,     /* variable_declaration  */
  YYSYMBOL_105_20 = 105,                   /* $@20  */
  YYSYMBOL_return_statement = 106,         /* return_statement  */
  YYSYMBOL_assignment = 107,               /* assignment  */
  YYSYMBOL_108_21 = 108,                   /* $@21  */
  YYSYMBOL_array_assignment = 109,         /* array_assignment  */
  YYSYMBOL_110_22 = 110,                   /* $@22  */
  YYSYMBOL_expression = 111,               /* expression  */
  YYSYMBOL_array_element = 112,            /* array_element  */
  YYSYMBOL_expr_list = 113,                /* expr_list  */
  YYSYMBOL_function_call = 114,            /* function_call  */
  YYSYMBOL_boolean_expr = 115,             /* boolean_expr  */
  YYSYMBOL_arithmetic_expr = 116,          /* arithmetic_expr  */
  YYSYMBOL_binary_expr = 117,              /* binary_expr  */
  YYSYMBOL_arithmetic_term = 118,          /* arithmetic_term  */
  YYSYMBOL_arithmetic_factor = 119,        /* arithmetic_factor  */
  YYSYMBOL_bitwise_expr = 120,             /* bitwise_expr  */
  YYSYMBOL_bitwise_xor_expr = 121,         /* bitwise_xor_expr  */
  YYSYMBOL_bitwise_and_expr = 122,         /* bitwise_and_expr  */
  YYSYMBOL_bitwise_not_expr = 123,         /* bitwise_not_expr  */
  YYSYMBOL_unary_expr = 124,               /* unary_expr  */
  YYSYMBOL_main_function = 125,            /* main_function  */
  YYSYMBOL_126_23 = 126                    /* $@23  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   323

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  66
/* YYNRULES -- Number of rules.  */
#define YYNRULES  137
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  261

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
       0,   234,   234,   234,   238,   239,   245,   252,   245,   288,
     293,   288,   310,   310,   336,   336,   356,   392,   426,   432,
     441,   442,   443,   444,   445,   450,   450,   466,   467,   466,
     469,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   488,   488,   491,   492,   495,
     496,   499,   499,   502,   546,   591,   595,   618,   646,   674,
     675,   678,   678,   681,   681,   685,   699,   685,   703,   706,
     707,   710,   715,   715,   766,   766,   857,   857,   907,   907,
     972,  1005,  1005,  1053,  1053,  1155,  1161,  1162,  1163,  1169,
    1175,  1179,  1225,  1230,  1245,  1296,  1331,  1353,  1375,  1397,
    1419,  1434,  1449,  1464,  1479,  1494,  1509,  1524,  1541,  1544,
    1564,  1584,  1587,  1607,  1633,  1650,  1667,  1670,  1671,  1674,
    1686,  1689,  1701,  1704,  1716,  1719,  1731,  1735,  1778,  1784,
    1790,  1817,  1844,  1866,  1882,  1887,  1896,  1896
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
  "statements", "$@9", "$@10", "statement", "if_statement", "$@11",
  "elseif_statement", "else_statement", "for_statement", "$@12",
  "loop_start", "loop_update", "while_statement", "$@13",
  "do_while_statement", "$@14", "switch_statement", "$@15", "$@16",
  "default_case", "case_list", "case_statement", "initialization", "$@17",
  "$@18", "const_initialization", "$@19", "variable_declaration", "$@20",
  "return_statement", "assignment", "$@21", "array_assignment", "$@22",
  "expression", "array_element", "expr_list", "function_call",
  "boolean_expr", "arithmetic_expr", "binary_expr", "arithmetic_term",
  "arithmetic_factor", "bitwise_expr", "bitwise_xor_expr",
  "bitwise_and_expr", "bitwise_not_expr", "unary_expr", "main_function",
  "$@23", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-137)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-31)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -137,    46,   278,  -137,  -137,  -137,  -137,  -137,  -137,    55,
      47,   278,    68,    44,    66,  -137,  -137,    79,    54,    67,
      88,  -137,   248,  -137,  -137,   248,  -137,    -7,  -137,     4,
    -137,  -137,    87,  -137,    96,  -137,   248,  -137,   129,  -137,
    -137,  -137,   107,  -137,  -137,   124,  -137,   130,   179,  -137,
     128,  -137,  -137,  -137,  -137,  -137,  -137,   105,   134,   135,
     138,   140,  -137,    77,   248,    77,    -4,    90,  -137,   132,
       6,   117,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
    -137,  -137,  -137,  -137,   204,  -137,  -137,  -137,  -137,    14,
      78,  -137,   122,   125,   133,  -137,  -137,  -137,    31,   176,
    -137,  -137,    45,  -137,  -137,  -137,   173,   177,   126,   216,
     197,   160,  -137,    77,    99,    77,  -137,    56,   148,    79,
    -137,    75,   101,   101,   101,   101,   101,   101,  -137,   111,
     111,   111,   111,     7,    90,    90,    90,  -137,   246,    92,
     181,    77,   246,    77,   291,    77,  -137,  -137,  -137,  -137,
     103,   180,   189,    77,   246,  -137,  -137,    13,  -137,  -137,
    -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
      78,    78,  -137,  -137,  -137,    77,   125,   133,  -137,  -137,
      77,  -137,   -27,   156,   246,   184,   170,   175,   165,   190,
     191,   200,   196,  -137,  -137,  -137,   103,   116,   185,   198,
     246,  -137,  -137,  -137,    77,    77,    77,  -137,   212,    77,
      77,  -137,  -137,  -137,   211,   254,   246,   246,   213,  -137,
    -137,   237,   228,   215,  -137,   247,   265,   275,   260,   227,
    -137,  -137,    77,  -137,  -137,    -1,   276,  -137,   309,    60,
    -137,  -137,   279,  -137,  -137,  -137,    77,  -137,   256,   258,
     283,  -137,  -137,   246,  -137,    82,   107,  -137,  -137,  -137,
    -137
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     5,     1,    20,    21,    22,    23,    24,     0,
       0,     5,     0,     0,     0,     3,     4,     0,     9,     0,
       6,    14,     0,   136,    12,     0,    25,     0,    16,     0,
      25,    25,     0,    15,     0,    10,     0,    19,     0,   137,
      13,     7,    27,    25,    17,     0,    25,     0,    25,    11,
       0,     8,    26,   128,   129,    89,    88,   127,     0,     0,
       0,     0,    25,     0,     0,     0,     0,     0,    44,    78,
       0,     0,    28,    39,    40,    41,    42,    43,    36,    38,
      37,    34,    33,    32,     0,    90,    87,    85,    86,   108,
     111,   116,   117,   120,   122,   124,   126,    18,     0,     0,
     130,   131,     0,    45,    51,    61,     0,     0,   127,     0,
       0,     0,   132,     0,   127,     0,   125,     0,     0,    19,
      31,    27,     0,     0,     0,     0,     0,     0,    35,     0,
       0,     0,     0,     0,     0,     0,     0,    95,    92,     0,
       0,     0,    81,     0,    55,     0,    65,    63,    80,    76,
     118,     0,     0,     0,    72,    79,    29,   127,    97,    96,
      99,    98,   103,   102,   101,   100,   107,   106,   105,   104,
     109,   110,   112,   113,   114,     0,   119,   121,   123,    94,
       0,    91,     0,     0,     0,    85,     0,     0,     0,    85,
       0,     0,     0,   134,   135,   133,     0,     0,     0,     0,
      93,    83,    82,    25,     0,     0,     0,    25,     0,     0,
       0,    74,    73,   115,     0,    48,    53,    54,    85,    62,
      66,    85,     0,     0,    84,     0,    50,    60,     0,     0,
      77,    75,     0,    25,    46,     0,     0,    59,     0,     0,
      70,    64,    85,    49,    57,    58,     0,    25,     0,     0,
       0,    69,    25,    56,    52,    27,    27,    67,    47,    71,
      68
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -137,  -137,  -137,   306,   270,  -137,  -137,  -137,  -137,  -137,
    -137,   294,   -28,    27,   -30,  -137,  -118,  -137,  -137,  -137,
    -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
    -137,  -137,  -137,  -137,  -137,  -137,  -137,    81,  -137,  -137,
    -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
     -46,  -137,  -126,  -101,  -136,   183,  -137,    26,    34,  -137,
     187,   188,   -62,  -137,  -137,  -137
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    10,    11,    25,    46,    22,    43,    31,
      26,    27,    28,    29,    33,    34,    47,    48,   121,    72,
      73,   143,   226,   234,    74,   144,   188,   236,    75,   145,
      76,   191,    77,   190,   228,   250,   239,   240,    78,   198,
     223,    79,   192,    80,   118,    81,    82,   183,    83,   214,
     184,    85,   139,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    15,    30
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,    40,    84,   156,   112,   116,   201,   185,    44,   189,
     174,   180,    37,    49,   119,   182,    51,   109,    71,   111,
      69,   158,   160,   162,   164,   166,   168,   197,    35,    12,
     113,    36,   107,    98,    53,    54,    55,    56,    12,   108,
      38,   175,    38,   244,   245,   246,     3,    98,    53,    54,
      55,    56,   138,   108,   129,   130,   142,   100,   101,    53,
      54,    55,    56,    13,   108,    65,   137,   151,    14,   152,
     218,   154,    66,   221,   178,    70,    17,   141,    18,    65,
      53,    54,    55,    56,   238,   108,    66,    67,   249,    21,
      65,   110,   153,    53,    54,   138,   242,    66,   114,   -30,
      19,    67,    23,   -30,    53,    54,   -30,   138,   -30,   157,
     -30,    65,    67,    20,    53,    54,   187,   131,    66,   114,
     132,   133,    41,    24,   115,    36,   237,   179,    42,   199,
     180,    66,    45,    67,   200,    65,    97,   259,   260,    98,
     -30,    99,    66,   100,   101,    65,    67,   193,   194,   100,
     101,   102,    66,   211,   180,   170,   171,    67,   216,   217,
      98,    50,    99,    52,   222,   172,   173,    67,   103,   104,
     100,   101,   105,   215,   106,   120,   134,   219,   117,   140,
     135,   146,    53,    54,    55,    56,   136,    57,     4,     5,
       6,     7,     8,     9,    58,   150,   147,    59,    60,    61,
     253,    62,    63,   243,    64,   149,   155,   122,   123,   124,
     125,   126,   127,    65,   202,   195,   204,   254,   181,   203,
      66,   205,   258,   206,   196,   207,   208,   122,   123,   124,
     125,   126,   127,   213,   209,    67,   122,   123,   124,   125,
     126,   127,   210,   212,   220,   122,   123,   124,   125,   126,
     127,   122,   123,   124,   125,   126,   127,     4,     5,     6,
       7,     8,   128,   122,   123,   124,   125,   126,   127,   224,
     225,   227,   229,   231,   148,   122,   123,   124,   125,   126,
     127,   232,   233,   235,   238,   241,   230,     4,     5,     6,
       7,     8,     9,   122,   123,   124,   125,   126,   127,   186,
       4,     5,     6,     7,     8,   159,   161,   163,   165,   167,
     169,   247,   248,   255,   252,   256,   257,    16,    68,    32,
     251,   176,     0,   177
};

static const yytype_int16 yycheck[] =
{
      30,    31,    48,   121,     8,    67,    33,   143,    36,   145,
       3,    38,     8,    43,     8,   141,    46,    63,    48,    65,
      48,   122,   123,   124,   125,   126,   127,   153,    35,     2,
      34,    38,    62,    34,     3,     4,     5,     6,    11,     8,
      36,    34,    36,    44,    45,    46,     0,    34,     3,     4,
       5,     6,    98,     8,    40,    41,   102,    44,    45,     3,
       4,     5,     6,     8,     8,    34,    35,   113,    21,   115,
     206,   117,    41,   209,   136,    48,     8,    32,    34,    34,
       3,     4,     5,     6,    24,     8,    41,    56,    28,    35,
      34,    64,    36,     3,     4,   141,   232,    41,     8,    24,
      34,    56,    35,    28,     3,     4,    24,   153,    33,     8,
      28,    34,    56,    34,     3,     4,   144,    39,    41,     8,
      42,    43,    35,    35,    34,    38,   227,    35,    32,   175,
      38,    41,     3,    56,   180,    34,     8,   255,   256,    34,
      33,    36,    41,    44,    45,    34,    56,    44,    45,    44,
      45,    46,    41,    37,    38,   129,   130,    56,   204,   205,
      34,    37,    36,    33,   210,   131,   132,    56,    34,    34,
      44,    45,    34,   203,    34,    58,    54,   207,    46,     3,
      55,     8,     3,     4,     5,     6,    53,     8,     9,    10,
      11,    12,    13,    14,    15,    35,    19,    18,    19,    20,
     246,    22,    23,   233,    25,     8,    58,    47,    48,    49,
      50,    51,    52,    34,    58,    35,    46,   247,    37,    35,
      41,    46,   252,    58,    35,    35,    35,    47,    48,    49,
      50,    51,    52,    35,    34,    56,    47,    48,    49,    50,
      51,    52,    46,    58,    32,    47,    48,    49,    50,    51,
      52,    47,    48,    49,    50,    51,    52,     9,    10,    11,
      12,    13,    58,    47,    48,    49,    50,    51,    52,    58,
      16,    58,    35,    58,    58,    47,    48,    49,    50,    51,
      52,    34,    17,     8,    24,    58,    58,     9,    10,    11,
      12,    13,    14,    47,    48,    49,    50,    51,    52,     8,
       9,    10,    11,    12,    13,   122,   123,   124,   125,   126,
     127,    35,     3,    57,    35,    57,    33,    11,    48,    25,
     239,   134,    -1,   135
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    62,    63,     0,     9,    10,    11,    12,    13,    14,
      64,    65,    74,     8,    21,   125,    64,     8,    34,    34,
      34,    35,    68,    35,    35,    66,    71,    72,    73,    74,
     126,    70,    72,    75,    76,    35,    38,     8,    36,    75,
      75,    35,    32,    69,    73,     3,    67,    77,    78,    75,
      37,    75,    33,     3,     4,     5,     6,     8,    15,    18,
      19,    20,    22,    23,    25,    34,    41,    56,    65,    73,
      74,    75,    80,    81,    85,    89,    91,    93,    99,   102,
     104,   106,   107,   109,   111,   112,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,     8,    34,    36,
      44,    45,    46,    34,    34,    34,    34,    75,     8,   111,
      74,   111,     8,    34,     8,    34,   123,    46,   105,     8,
      58,    79,    47,    48,    49,    50,    51,    52,    58,    40,
      41,    39,    42,    43,    54,    55,    53,    35,   111,   113,
       3,    32,   111,    82,    86,    90,     8,    19,    58,     8,
      35,   111,   111,    36,   111,    58,    77,     8,   114,   116,
     114,   116,   114,   116,   114,   116,   114,   116,   114,   116,
     118,   118,   119,   119,     3,    34,   121,   122,   123,    35,
      38,    37,   113,   108,   111,   115,     8,    73,    87,   115,
      94,    92,   103,    44,    45,    35,    35,   113,   100,   111,
     111,    33,    58,    35,    46,    46,    58,    35,    35,    34,
      46,    37,    58,    35,   110,    75,   111,   111,   115,    75,
      32,   115,   111,   101,    58,    16,    83,    58,    95,    35,
      58,    58,    34,    17,    84,     8,    88,   114,    24,    97,
      98,    58,   115,    75,    44,    45,    46,    35,     3,    28,
      96,    98,    35,   111,    75,    57,    57,    33,    75,    77,
      77
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    63,    62,    64,    64,    66,    67,    65,    68,
      69,    65,    70,    65,    71,    65,    72,    72,    73,    73,
      74,    74,    74,    74,    74,    76,    75,    78,    79,    77,
      77,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    82,    81,    83,    83,    84,
      84,    86,    85,    87,    87,    87,    88,    88,    88,    88,
      88,    90,    89,    92,    91,    94,    95,    93,    96,    97,
      97,    98,   100,    99,   101,    99,   103,   102,   105,   104,
     106,   108,   107,   110,   109,   111,   111,   111,   111,   111,
     111,   112,   113,   113,   114,   114,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   116,   117,
     117,   117,   118,   118,   118,   118,   118,   119,   119,   120,
     120,   121,   121,   122,   122,   123,   123,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   126,   125
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     2,     0,     0,     0,     8,     0,
       0,     8,     0,     6,     0,     6,     1,     3,     5,     2,
       1,     1,     1,     1,     1,     0,     4,     0,     0,     4,
       0,     2,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     8,     5,     0,     2,
       0,     0,    10,     3,     3,     0,     3,     2,     2,     1,
       0,     0,     6,     0,     8,     0,     0,    10,     3,     2,
       1,     4,     0,     5,     0,     7,     0,     7,     0,     3,
       3,     0,     5,     0,     7,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     5,     1,     1,     3,     3,
       1,     3,     1,     3,     1,     2,     1,     1,     1,     1,
       2,     2,     2,     4,     4,     4,     0,     5
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
  case 2: /* $@1: %empty  */
#line 234 "parser.y"
    { scope_no++; }
#line 1811 "parser.tab.c"
    break;

  case 3: /* program: $@1 functions main_function  */
#line 234 "parser.y"
                                            { delete_scope(symbol_table, scope_no); scope_no--;}
#line 1817 "parser.tab.c"
    break;

  case 6: /* $@2: %empty  */
#line 245 "parser.y"
                                        {
        printf("function match %s\n", (yyvsp[-1].sval));
        fflush(stdout);
        scope_no++;
        curr_function_parameter_list = NULL;
        push_function((yyvsp[-1].sval));
    }
#line 1829 "parser.tab.c"
    break;

  case 7: /* $@3: %empty  */
#line 252 "parser.y"
                                           {
        inside_a_function_declaration_body = 1;
        curr_function_instructions_list = NULL;
        printf("Entering the body of %s\n", (yyvsp[-4].sval));
        fflush(stdout);
        Value val;
        val.function = NULL;
        size_t array_size = 0;
        ValueType return_type;
        printf("checking array return type of %s\n", (yyvsp[-4].sval));
        if ((yyvsp[-5].sval)[0] == 'a') {
            return_type = keyword_to_array_value_type((yyvsp[-5].sval));
            char* size_str = strchr((yyvsp[-5].sval), '[') + 1;
            array_size = atoi(size_str);
        }else{
            printf("checking return type of %s which is %s t\n", (yyvsp[-4].sval), (yyvsp[-5].sval));
            return_type = string_to_value_type((yyvsp[-5].sval));
        }

        printf("found return type of %s\n", (yyvsp[-4].sval));
        printf("%s entering insert\n", (yyvsp[-4].sval));
        fflush(stdout);
        insert_symbol(symbol_table, (yyvsp[-4].sval), (yyvsp[-5].sval), val, return_type, scope_no - 1, 1, 0, array_size > 0, (yyvsp[-1].param_list), yylineno, array_size, get_prev_enclosing_function());
        inside_a_function_declaration_body = 0;
        curr_function_parameter_list = NULL;
        curr_function_parameter_list_ptr = NULL;
        curr_function_instructions_list = NULL;
    }
#line 1862 "parser.tab.c"
    break;

  case 8: /* function: type IDENTIFIER OPENING_PARENTHESIS $@2 function_arguments CLOSING_PARENTHESIS $@3 body  */
#line 280 "parser.y"
         {
        char* popped = pop_function();
        if (popped) free(popped);
        scope_no--;
        free((yyvsp[-7].sval));
        printf("Exiting the body of %s\n", (yyvsp[-6].sval));
        fflush(stdout);
    }
#line 1875 "parser.tab.c"
    break;

  case 9: /* $@4: %empty  */
#line 288 "parser.y"
                                                       {
        scope_no++;
        curr_function_parameter_list = NULL;
        push_function((yyvsp[-1].sval));
    }
#line 1885 "parser.tab.c"
    break;

  case 10: /* $@5: %empty  */
#line 293 "parser.y"
                                           {
        inside_a_function_declaration_body = 1;
        curr_function_instructions_list = NULL;
        Value val;
        val.function = NULL;
        ValueType return_type = string_to_value_type("void");
        insert_symbol(symbol_table, (yyvsp[-4].sval), "void", val, return_type, scope_no-1, 1, 0, 0, (yyvsp[-1].param_list), yylineno, 0, get_prev_enclosing_function());
        inside_a_function_declaration_body = 0;
        curr_function_parameter_list = NULL;
        curr_function_parameter_list_ptr = NULL;
        curr_function_instructions_list = NULL;
    }
#line 1902 "parser.tab.c"
    break;

  case 11: /* function: VOID_TYPE_KEYWORD IDENTIFIER OPENING_PARENTHESIS $@4 function_arguments CLOSING_PARENTHESIS $@5 body  */
#line 305 "parser.y"
         {
        char* popped = pop_function();
        if (popped) free(popped);
        scope_no--;
    }
#line 1912 "parser.tab.c"
    break;

  case 12: /* $@6: %empty  */
#line 310 "parser.y"
                                                              {
        scope_no++;
        inside_a_function_declaration_body = 1;
        curr_function_instructions_list = NULL;
        push_function((yyvsp[-2].sval));
        Value val;
        val.function = NULL;
        ValueType return_type;
        size_t array_size = 0;
        if ((yyvsp[-3].sval)[0] == 'a') {
            return_type = keyword_to_array_value_type((yyvsp[-3].sval));
            char* size_str = strchr((yyvsp[-3].sval), '[') + 1;
            array_size = atoi(size_str);
        }else{
            return_type = string_to_value_type((yyvsp[-3].sval));
        }
        insert_symbol(symbol_table, (yyvsp[-2].sval), (yyvsp[-3].sval), val, return_type, scope_no - 1, 1, 0, array_size > 0, NULL, yylineno, array_size, get_prev_enclosing_function());
        inside_a_function_declaration_body = 0;
        curr_function_instructions_list = NULL;
    }
#line 1937 "parser.tab.c"
    break;

  case 13: /* function: type IDENTIFIER OPENING_PARENTHESIS CLOSING_PARENTHESIS $@6 body  */
#line 330 "parser.y"
         {
        char* popped = pop_function();
        if (popped) free(popped);
        scope_no--;
        free((yyvsp[-5].sval));
    }
#line 1948 "parser.tab.c"
    break;

  case 14: /* $@7: %empty  */
#line 336 "parser.y"
                                                                           {
        scope_no++;
        inside_a_function_declaration_body = 1;
        curr_function_instructions_list = NULL;
        push_function((yyvsp[-2].sval));
        Value val;
        val.function = NULL;
        ValueType return_type = string_to_value_type("void");
        insert_symbol(symbol_table, (yyvsp[-2].sval), "void", val, return_type, scope_no - 1, 1, 0, 0, NULL, yylineno, 0, get_prev_enclosing_function());
        inside_a_function_declaration_body = 0;
        curr_function_instructions_list = NULL;
    }
#line 1965 "parser.tab.c"
    break;

  case 15: /* function: VOID_TYPE_KEYWORD IDENTIFIER OPENING_PARENTHESIS CLOSING_PARENTHESIS $@7 body  */
#line 348 "parser.y"
         {
        char* popped = pop_function();
        if (popped) free(popped);
        scope_no--;
    }
#line 1975 "parser.tab.c"
    break;

  case 16: /* function_arguments: type_identifier  */
#line 356 "parser.y"
                    {
        if (!curr_function_parameter_list) {
            curr_function_parameter_list = create_parameter((yyvsp[0].type_id).name, (yyvsp[0].type_id).type);
            curr_function_parameter_list_ptr = curr_function_parameter_list;
        } else {
            curr_function_parameter_list_ptr->next = create_parameter((yyvsp[0].type_id).name, (yyvsp[0].type_id).type);
            curr_function_parameter_list_ptr = curr_function_parameter_list_ptr->next;
        }
        curr_function_parameter_list_ptr->array_length = (yyvsp[0].type_id).array_size;
        Value val;
        memset(&val, 0, sizeof(Value));
        ValueType param_type;
        if(param_type == VOID){
            fprintf(stderr, "Can't have a function parameter of type 'void' at line %d\n", yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        size_t param_size = (yyvsp[0].type_id).array_size;
        if ((yyvsp[0].type_id).array_size > 0) {
            param_type = keyword_to_array_value_type((yyvsp[0].type_id).type);
        }else{
            param_type = string_to_value_type((yyvsp[0].type_id).type);
        }
        SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[0].type_id).name, scope_no, get_current_enclosing_function());
        if (result && (!result->enclosing_function_name || 
                       (get_current_enclosing_function() && 
                        strcmp(result->enclosing_function_name, get_current_enclosing_function()) == 0))) {
            fprintf(stderr, "Cannot re-declare parameter '%s' at line %d\n", (yyvsp[0].type_id).name, yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        insert_symbol(symbol_table, (yyvsp[0].type_id).name, (yyvsp[0].type_id).type, val, param_type, scope_no, 0, 0, param_size > 0, NULL, yylineno, param_size, get_current_enclosing_function());
        free((yyvsp[0].type_id).name);
        free((yyvsp[0].type_id).type);
        (yyval.param_list) = curr_function_parameter_list;
    }
#line 2016 "parser.tab.c"
    break;

  case 17: /* function_arguments: function_arguments COMMA type_identifier  */
#line 392 "parser.y"
                                               {
        curr_function_parameter_list_ptr->next = create_parameter((yyvsp[0].type_id).name, (yyvsp[0].type_id).type);
        curr_function_parameter_list_ptr = curr_function_parameter_list_ptr->next;
        Value val;
        memset(&val, 0, sizeof(Value));
        ValueType param_type;
        if(param_type == VOID){
            fprintf(stderr, "Can't have a function parameter of type 'void' at line %d\n", yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        size_t param_size = (yyvsp[0].type_id).array_size;
        curr_function_parameter_list_ptr->array_length = (yyvsp[0].type_id).array_size;
        if ((yyvsp[0].type_id).array_size > 0) {
            param_type = keyword_to_array_value_type((yyvsp[0].type_id).type);
        }else{
            param_type = string_to_value_type((yyvsp[0].type_id).type);
        }
        SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[0].type_id).name, scope_no, get_current_enclosing_function());
        if (result && (!result->enclosing_function_name || 
                       (get_current_enclosing_function() && 
                        strcmp(result->enclosing_function_name, get_current_enclosing_function()) == 0))) {
            fprintf(stderr, "Cannot re-declare parameter '%s' at line %d\n", (yyvsp[0].type_id).name, yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        insert_symbol(symbol_table, (yyvsp[0].type_id).name, (yyvsp[0].type_id).type, val, param_type, scope_no, 0, 0, param_size > 0, NULL, yylineno, param_size, get_current_enclosing_function());
        free((yyvsp[0].type_id).name);
        free((yyvsp[0].type_id).type);
        (yyval.param_list) = curr_function_parameter_list;
    }
#line 2052 "parser.tab.c"
    break;

  case 18: /* type_identifier: type OPENING_SQUARE_BRACKETS INTEGER_LITERAL CLOSING_SQUARE_BRACKETS IDENTIFIER  */
#line 426 "parser.y"
                                                                                    {
        asprintf(&((yyval.type_id).type), "a%s[%d]", (yyvsp[-4].sval), (yyvsp[-2].ival));  
        (yyval.type_id).name = strdup((yyvsp[0].sval));                    
        (yyval.type_id).array_size = (yyvsp[-2].ival);                      
        printf("Found array type: %s %s\n", (yyval.type_id).type, (yyval.type_id).name);
    }
#line 2063 "parser.tab.c"
    break;

  case 19: /* type_identifier: type IDENTIFIER  */
#line 432 "parser.y"
                      {
        (yyval.type_id).type = strdup((yyvsp[-1].sval));  
        (yyval.type_id).name = strdup((yyvsp[0].sval));  
        (yyval.type_id).array_size = 0;      // Not an array
    }
#line 2073 "parser.tab.c"
    break;

  case 20: /* type: INT_TYPE_KEYWORD  */
#line 441 "parser.y"
                       { (yyval.sval) = strdup("int"); }
#line 2079 "parser.tab.c"
    break;

  case 21: /* type: FLOAT_TYPE_KEYWORD  */
#line 442 "parser.y"
                           { (yyval.sval) = strdup("float"); }
#line 2085 "parser.tab.c"
    break;

  case 22: /* type: STRING_TYPE_KEYWORD  */
#line 443 "parser.y"
                            { (yyval.sval) = strdup("string"); }
#line 2091 "parser.tab.c"
    break;

  case 23: /* type: CHAR_TYPE_KEYWORD  */
#line 444 "parser.y"
                          { (yyval.sval) = strdup("char"); }
#line 2097 "parser.tab.c"
    break;

  case 24: /* type: BOOL_TYPE_KEYWORD  */
#line 445 "parser.y"
                          { (yyval.sval) = strdup("bool"); }
#line 2103 "parser.tab.c"
    break;

  case 25: /* $@8: %empty  */
#line 450 "parser.y"
     { 
       printf("entering body\n");
        scope_no++;
    }
#line 2112 "parser.tab.c"
    break;

  case 26: /* body: $@8 OPENING_CURLY_BRACE statements CLOSING_CURLY_BRACE  */
#line 456 "parser.y"
                        { 
        if(!inside_a_function_declaration_body) {
            printf("boom\n");
            delete_scope(symbol_table, scope_no); 
        }
        scope_no--; 
        printf("Exiting body\n");
    }
#line 2125 "parser.tab.c"
    break;

  case 27: /* $@9: %empty  */
#line 466 "parser.y"
            {printf("inside statements\n");}
#line 2131 "parser.tab.c"
    break;

  case 28: /* $@10: %empty  */
#line 467 "parser.y"
              {printf("found a statement\n");}
#line 2137 "parser.tab.c"
    break;

  case 29: /* statements: $@9 statement $@10 statements  */
#line 468 "parser.y"
               {printf("inside statements again\n");}
#line 2143 "parser.tab.c"
    break;

  case 30: /* statements: %empty  */
#line 469 "parser.y"
                  {printf("empty statement");}
#line 2149 "parser.tab.c"
    break;

  case 31: /* statement: body SEMICOLON  */
#line 472 "parser.y"
                          {printf("a body statement\n");}
#line 2155 "parser.tab.c"
    break;

  case 32: /* statement: array_assignment  */
#line 473 "parser.y"
                            {printf("an array assignment statement\n");}
#line 2161 "parser.tab.c"
    break;

  case 33: /* statement: assignment  */
#line 474 "parser.y"
                      {printf("an assignment statement\n");}
#line 2167 "parser.tab.c"
    break;

  case 34: /* statement: return_statement  */
#line 475 "parser.y"
                            {printf("a return statement\n");}
#line 2173 "parser.tab.c"
    break;

  case 35: /* statement: expression SEMICOLON  */
#line 476 "parser.y"
                                {printf("an expression statement\n");}
#line 2179 "parser.tab.c"
    break;

  case 36: /* statement: initialization  */
#line 477 "parser.y"
                          {printf("an initialization statement\n");}
#line 2185 "parser.tab.c"
    break;

  case 37: /* statement: variable_declaration  */
#line 478 "parser.y"
                                {printf("a variable declaration statement\n");}
#line 2191 "parser.tab.c"
    break;

  case 38: /* statement: const_initialization  */
#line 479 "parser.y"
                                {printf("a const initialization statement\n");}
#line 2197 "parser.tab.c"
    break;

  case 39: /* statement: if_statement  */
#line 480 "parser.y"
                        {printf("an if statement\n");}
#line 2203 "parser.tab.c"
    break;

  case 40: /* statement: for_statement  */
#line 481 "parser.y"
                         {printf("a for statement\n");}
#line 2209 "parser.tab.c"
    break;

  case 41: /* statement: while_statement  */
#line 482 "parser.y"
                           {printf("a while statement\n");}
#line 2215 "parser.tab.c"
    break;

  case 42: /* statement: do_while_statement  */
#line 483 "parser.y"
                              {printf("a do while statement\n");}
#line 2221 "parser.tab.c"
    break;

  case 43: /* statement: switch_statement  */
#line 484 "parser.y"
                            {printf("a switch statement\n");}
#line 2227 "parser.tab.c"
    break;

  case 44: /* statement: function  */
#line 485 "parser.y"
                    {printf("a function declaration statement\n");}
#line 2233 "parser.tab.c"
    break;

  case 45: /* $@11: %empty  */
#line 488 "parser.y"
                                                         {printf("entering if\n");}
#line 2239 "parser.tab.c"
    break;

  case 46: /* if_statement: IF_KEYWORD OPENING_PARENTHESIS $@11 boolean_expr CLOSING_PARENTHESIS body elseif_statement else_statement  */
#line 488 "parser.y"
                                                                                                                                                          {printf("exiting if\n");}
#line 2245 "parser.tab.c"
    break;

  case 51: /* $@12: %empty  */
#line 499 "parser.y"
                                                          {printf("entering for\n");}
#line 2251 "parser.tab.c"
    break;

  case 52: /* for_statement: FOR_KEYWORD OPENING_PARENTHESIS $@12 loop_start SEMICOLON boolean_expr SEMICOLON loop_update CLOSING_PARENTHESIS body  */
#line 499 "parser.y"
                                                                                                                                                                       {printf("entering for\n");}
#line 2257 "parser.tab.c"
    break;

  case 53: /* loop_start: IDENTIFIER ASSIGNMENT expression  */
#line 502 "parser.y"
                                                             {
                            SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[-2].sval), scope_no, get_current_enclosing_function());
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
#line 2306 "parser.tab.c"
    break;

  case 54: /* loop_start: type_identifier ASSIGNMENT expression  */
#line 546 "parser.y"
                                                                {
                            SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[-2].type_id).name, scope_no, get_current_enclosing_function());
                            if (result && (!result->enclosing_function_name || 
                                           (get_current_enclosing_function() && 
                                            strcmp(result->enclosing_function_name, get_current_enclosing_function()) == 0))) {
                                fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", (yyvsp[-2].type_id).name, yylineno);
                                free_symbol_table(symbol_table);
                                exit(1);
                            }
                            ValueType declared_type;
                            if(declared_type == VOID){
                                fprintf(stderr, "Can't declare a non-function of type 'void' at line %d\n", yylineno);
                                free_symbol_table(symbol_table);
                                exit(1);
                            }
                            size_t declared_size = (yyvsp[-2].type_id).array_size;
                            if ((yyvsp[-2].type_id).type[0] =='a') {
                                fprintf(stderr, "Loop variable can't be an array at line %d\n", yylineno);
                                free_symbol_table(symbol_table);
                                exit(1);
                            }else{
                                declared_type = string_to_value_type((yyvsp[-2].type_id).type);
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
                                default:
                                    break;
                            }
                            insert_symbol(symbol_table, (yyvsp[-2].type_id).name, (yyvsp[-2].type_id).type, val, declared_type, scope_no, 0, 0, declared_size > 0, NULL, yylineno, declared_size, get_current_enclosing_function());
                            free((yyvsp[-2].type_id).name);
                            free((yyvsp[-2].type_id).type);
                        }
#line 2356 "parser.tab.c"
    break;

  case 56: /* loop_update: IDENTIFIER ASSIGNMENT expression  */
#line 595 "parser.y"
                                     {
        SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[-2].sval), scope_no, get_current_enclosing_function());
        if (!result) {
            fprintf(stderr, "Undeclared identifier '%s' at line %d\n", (yyvsp[-2].sval), yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        if (result->is_function) {
            fprintf(stderr, "Cannot use function '%s' at line %d as a loop variable\n", (yyvsp[-2].sval), yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        if (result->is_constant) {
            fprintf(stderr, "Cannot use const identifier '%s' at line %d as a loop variable\n", (yyvsp[-2].sval), yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        if (result->value_type != (yyvsp[0].expr).expr_return_type) {
            fprintf(stderr, "Type mismatch in loop update for '%s' at line %d\n", (yyvsp[-2].sval), yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
    }
#line 2384 "parser.tab.c"
    break;

  case 57: /* loop_update: IDENTIFIER INCREMENT  */
#line 618 "parser.y"
                           {
        SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[-1].sval), scope_no, get_current_enclosing_function());
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
            fprintf(stderr, "Increment requires numeric operand at line %d\n", yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        if (result->value_type == INT_VALUE) {
            result->value.int_value++;
        } else {
            result->value.float_value++;
        }
    }
#line 2417 "parser.tab.c"
    break;

  case 58: /* loop_update: IDENTIFIER DECREMENT  */
#line 646 "parser.y"
                           {
        SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[-1].sval), scope_no, get_current_enclosing_function());
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
            fprintf(stderr, "Decrement requires numeric operand at line %d\n", yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        if (result->value_type == INT_VALUE) {
            result->value.int_value--;
        } else {
            result->value.float_value--;
        }
    }
#line 2450 "parser.tab.c"
    break;

  case 61: /* $@13: %empty  */
#line 678 "parser.y"
                                                            {printf("entering a while statement\n");}
#line 2456 "parser.tab.c"
    break;

  case 63: /* $@14: %empty  */
#line 681 "parser.y"
                                                        {printf("entering a do-while statement\n");}
#line 2462 "parser.tab.c"
    break;

  case 65: /* $@15: %empty  */
#line 685 "parser.y"
                                                  {
        printf("entering a switch statement\n");
        SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[0].sval), scope_no, get_current_enclosing_function());
        if (!result) {
            fprintf(stderr, "Undeclared identifier '%s' at line %d\n", (yyvsp[0].sval), yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        if (result->value_type != INT_VALUE) {
            fprintf(stderr, "Cannot use non-integer '%s' at line %d as a switch statement variable\n", (yyvsp[0].sval), yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
    }
#line 2481 "parser.tab.c"
    break;

  case 66: /* $@16: %empty  */
#line 699 "parser.y"
                                            {scope_no++;}
#line 2487 "parser.tab.c"
    break;

  case 67: /* switch_statement: SWITCH_KEYWORD OPENING_PARENTHESIS IDENTIFIER $@15 CLOSING_PARENTHESIS OPENING_CURLY_BRACE $@16 case_list default_case CLOSING_CURLY_BRACE  */
#line 700 "parser.y"
                                               { delete_scope(symbol_table, scope_no); scope_no--;}
#line 2493 "parser.tab.c"
    break;

  case 72: /* $@17: %empty  */
#line 715 "parser.y"
                                          {
        printf("entering an initialization statement\n");
        SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[-2].type_id).name, scope_no, get_current_enclosing_function());
        if (result && (!result->enclosing_function_name || 
                       (get_current_enclosing_function() && 
                        strcmp(result->enclosing_function_name, get_current_enclosing_function()) == 0))) {
            fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", (yyvsp[-2].type_id).name, yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        ValueType declared_type;
        if(declared_type == VOID){
            fprintf(stderr, "Can't declare a non-function of type 'void' at line %d\n", yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        size_t declared_size = (yyvsp[-2].type_id).array_size;
        if ((yyvsp[-2].type_id).type[0] == 'a') {
            fprintf(stderr, "Array size must be specified at line %d\n", yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }else{
            declared_type = string_to_value_type((yyvsp[-2].type_id).type);
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
            default:
                fprintf(stderr, "Unsupported array type at line %d\n", yylineno);
                free_symbol_table(symbol_table);
                exit(1);
        }
        insert_symbol(symbol_table, (yyvsp[-2].type_id).name, (yyvsp[-2].type_id).type, val, declared_type, scope_no, 0, 0, declared_size > 0, NULL, yylineno, declared_size, get_current_enclosing_function());
        free((yyvsp[-2].type_id).name);
        free((yyvsp[-2].type_id).type);
    }
#line 2546 "parser.tab.c"
    break;

  case 74: /* $@18: %empty  */
#line 766 "parser.y"
                                                                                           {
        SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[-4].type_id).name, scope_no, get_current_enclosing_function());
        if (result && (!result->enclosing_function_name || 
                       (get_current_enclosing_function() && 
                        strcmp(result->enclosing_function_name, get_current_enclosing_function()) == 0))) {
            fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", (yyvsp[-4].type_id).name, yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        ValueType declared_type;
        if(declared_type == VOID){
            fprintf(stderr, "Can't declare a non-function of type 'void' at line %d\n", yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        ValueType element_type = declared_type;
        size_t declared_size = (yyvsp[-4].type_id).array_size;
        if ((yyvsp[-4].type_id).type[0] == 'a') {
            declared_type = keyword_to_array_value_type((yyvsp[-4].type_id).type);
        }else{
            fprintf(stderr, "Wrong array initialization at line %d\n", yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        size_t provided_size = 0;
        ExprList* current = &((yyvsp[-1].expr_lst));
        while (current && current->e) {
            provided_size++;
            if (current->e->expr_return_type != element_type) {
                fprintf(stderr, "Type mismatch in array initialization at line %d\n", yylineno);
                free_symbol_table(symbol_table);
                exit(1);
            }
            current = current->next_expr;
        }
        if (provided_size > declared_size) {
            fprintf(stderr, "Too many initializers for array '%s' at line %d\n", (yyvsp[-4].type_id).name, yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        Value val;
        switch (declared_type) {
            case INT_ARRAY_VALUE:
                val.int_array = (int*)calloc(declared_size, sizeof(int));
                current = &((yyvsp[-1].expr_lst));
                for (size_t i = 0; i < provided_size && current && current->e; i++) {
                    val.int_array[i] = current->e->expr_value.int_value;
                    current = current->next_expr;
                }
                break;
            case FLOAT_ARRAY_VALUE:
                val.float_array = (double*)calloc(declared_size, sizeof(double));
                current = &((yyvsp[-1].expr_lst));
                for (size_t i = 0; i < provided_size && current && current->e; i++) {
                    val.float_array[i] = current->e->expr_value.float_value;
                    current = current->next_expr;
                }
                break;
            case CHAR_ARRAY_VALUE:
                val.char_array = (char*)calloc(declared_size, sizeof(char));
                current = &((yyvsp[-1].expr_lst));
                for (size_t i = 0; i < provided_size && current && current->e; i++) {
                    val.char_array[i] = current->e->expr_value.char_value;
                    current = current->next_expr;
                }
                break;
            case STRING_ARRAY_VALUE:
                val.string_array = (char**)malloc(declared_size * sizeof(char*));
                for (size_t i = 0; i < declared_size; i++) {
                    val.string_array[i] = strdup("");
                }
                current = &((yyvsp[-1].expr_lst));
                for (size_t i = 0; i < provided_size && current && current->e; i++) {
                    free(val.string_array[i]);
                    val.string_array[i] = strdup(current->e->expr_value.char_array);
                    current = current->next_expr;
                }
                break;
            default:
                fprintf(stderr, "Unsupported array type at line %d\n", yylineno);
                free_symbol_table(symbol_table);
                exit(1);
        }
        insert_symbol(symbol_table, (yyvsp[-4].type_id).name, (yyvsp[-4].type_id).type, val, declared_type, scope_no, 0, 0, 1, NULL, yylineno, declared_size, get_current_enclosing_function());
        free((yyvsp[-4].type_id).name);
        free((yyvsp[-4].type_id).type);
    }
#line 2638 "parser.tab.c"
    break;

  case 76: /* $@19: %empty  */
#line 857 "parser.y"
                                 {
        SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[0].sval), scope_no, get_current_enclosing_function());
        if (result && (!result->enclosing_function_name || 
                       (get_current_enclosing_function() && 
                        strcmp(result->enclosing_function_name, get_current_enclosing_function()) == 0))) {
            fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", (yyvsp[0].sval), yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
    }
#line 2653 "parser.tab.c"
    break;

  case 77: /* const_initialization: CONST_KEYWORD type IDENTIFIER $@19 ASSIGNMENT expression SEMICOLON  */
#line 867 "parser.y"
                                    {
        ValueType declared_type;
        if(declared_type == VOID){
            fprintf(stderr, "Can't declare a non-function of type 'void' at line %d\n", yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        size_t declared_size = 0;
        if ((yyvsp[-5].sval)[0] == 'a') {
            fprintf(stderr, "Array size must be specified at line %d\n", yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }else{
            declared_type = string_to_value_type((yyvsp[-5].sval));
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
        insert_symbol(symbol_table, (yyvsp[-4].sval), (yyvsp[-5].sval), val, declared_type, scope_no, 0, 1, declared_size > 0, NULL, yylineno, declared_size, get_current_enclosing_function());
    }
#line 2695 "parser.tab.c"
    break;

  case 78: /* $@20: %empty  */
#line 907 "parser.y"
                    {
        SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[0].type_id).name, scope_no, get_current_enclosing_function());
        if (result && (!result->enclosing_function_name || 
                       (get_current_enclosing_function() && 
                        strcmp(result->enclosing_function_name, get_current_enclosing_function()) == 0))) {
            fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", (yyvsp[0].type_id).name, yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        ValueType declared_type;
        size_t declared_size = (yyvsp[0].type_id).array_size;
        if ((yyvsp[0].type_id).type[0] == 'a') {
            declared_type = keyword_to_array_value_type((yyvsp[0].type_id).type);
        }else{
            declared_type = string_to_value_type((yyvsp[0].type_id).type);
        }
        if (declared_size > 0 && declared_size <= 0) {
            fprintf(stderr, "Array size must be positive at line %d\n", yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        if(declared_type == VOID){
            fprintf(stderr, "Can't declare a non-function of type 'void' at line %d\n", yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        Value val;
        switch (declared_type) {
            case INT_VALUE:
            case BOOL_VALUE:
                val.int_value = 0;
                break;
            case FLOAT_VALUE:
                val.float_value = 0.0;
                break;
            case CHAR_VALUE:
                val.char_value = '\0';
                break;
            case STRING_VALUE:
                val.char_array = strdup("");
                break;
            case INT_ARRAY_VALUE:
                val.int_array = (int*)calloc(declared_size, sizeof(int));
                break;
            case FLOAT_ARRAY_VALUE:
                val.float_array = (double*)calloc(declared_size, sizeof(double));
                break;
            case CHAR_ARRAY_VALUE:
                val.char_array = (char*)calloc(declared_size, sizeof(char));
                break;
            case STRING_ARRAY_VALUE:
                val.string_array = (char**)malloc(declared_size * sizeof(char*));
                for (size_t i = 0; i < declared_size; i++) {
                    val.string_array[i] = strdup("");
                }
                break;
        }
        insert_symbol(symbol_table, (yyvsp[0].type_id).name, (yyvsp[0].type_id).type, val, declared_type, scope_no, 0, 0, declared_size > 0, NULL, yylineno, declared_size, get_current_enclosing_function());
        free((yyvsp[0].type_id).name);
        free((yyvsp[0].type_id).type);
    }
#line 2761 "parser.tab.c"
    break;

  case 80: /* return_statement: RETURN_KEYWORD expression SEMICOLON  */
#line 972 "parser.y"
                                         {
        printf("entering return statement\n");
        if (!get_current_enclosing_function()) {
            fprintf(stderr, "Return statement outside function at line %d\n", yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        SymbolTableEntry* func = search_symbol_table(symbol_table, get_current_enclosing_function(), scope_no, get_prev_enclosing_function());
        printf("current ecnlosing func : %s\n", get_current_enclosing_function());
        printf("prev enclosing func : %s\n", get_prev_enclosing_function());
        if (!func) {
            fprintf(stderr, "Function '%s' not found at line %d\n", get_current_enclosing_function(), yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        ValueType return_type = string_to_value_type(func->type);
        printf("turns out return type is %s\n", func->type);
        size_t return_size = 0;
        if (func->array_length > 0) {
            return_type = keyword_to_array_value_type(func->type);
            char* size_str = strchr(func->type, '[') + 1;
            return_size = atoi(size_str);
        }
        if (return_type != (yyvsp[-1].expr).expr_return_type || 
            (return_type >= INT_ARRAY_VALUE && return_size != (yyvsp[-1].expr).array_length)) {
            fprintf(stderr, "Return type mismatch in function '%s' at line %d\n", get_current_enclosing_function(), yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
    }
#line 2796 "parser.tab.c"
    break;

  case 81: /* $@21: %empty  */
#line 1005 "parser.y"
                                     {
        SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[-2].sval), scope_no, get_current_enclosing_function());
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
#line 2845 "parser.tab.c"
    break;

  case 83: /* $@22: %empty  */
#line 1053 "parser.y"
                                                                            {
        SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[-4].sval), scope_no, get_current_enclosing_function());
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
        ExprList* current = &((yyvsp[-1].expr_lst));
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
                result->value.int_array = (int*)calloc(array_size, sizeof(int));
                current = &(yyvsp[-1].expr_lst);
                for (size_t i = 0; i < provided_size; i++) {
                    result->value.int_array[i] = current->e->expr_value.int_value;
                    current = current->next_expr;
                }
                break;
            case FLOAT_ARRAY_VALUE:
                if (result->value.float_array) free(result->value.float_array);
                result->value.float_array = (double*)calloc(array_size, sizeof(double));
                current = &(yyvsp[-1].expr_lst);
                for (size_t i = 0; i < provided_size; i++) {
                    result->value.float_array[i] = current->e->expr_value.float_value;
                    current = current->next_expr;
                }
                break;
            case CHAR_ARRAY_VALUE:
                if (result->value.char_array) free(result->value.char_array);
                result->value.char_array = (char*)calloc(array_size, sizeof(char));
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
                    result->value.string_array[i] = strdup("");
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
#line 2947 "parser.tab.c"
    break;

  case 85: /* expression: boolean_expr  */
#line 1155 "parser.y"
                 {
        (yyval.expr).expr_type = BOOL_EXPR;
        (yyval.expr).expr_value.int_value = (yyvsp[0].expr).expr_value.int_value;
        (yyval.expr).expr_return_type = BOOL_VALUE;
        (yyval.expr).associated_identifier = NULL;
    }
#line 2958 "parser.tab.c"
    break;

  case 86: /* expression: arithmetic_expr  */
#line 1161 "parser.y"
                      { (yyval.expr) = (yyvsp[0].expr); }
#line 2964 "parser.tab.c"
    break;

  case 87: /* expression: function_call  */
#line 1162 "parser.y"
                    { (yyval.expr) = (yyvsp[0].expr); }
#line 2970 "parser.tab.c"
    break;

  case 88: /* expression: STRING_LITERAL  */
#line 1163 "parser.y"
                     {
        (yyval.expr).expr_type = STRING_EXPR;
        (yyval.expr).expr_value.char_array = strdup((yyvsp[0].sval));
        (yyval.expr).expr_return_type = STRING_VALUE;
        (yyval.expr).associated_identifier = NULL;
    }
#line 2981 "parser.tab.c"
    break;

  case 89: /* expression: CHARACTER_LITERAL  */
#line 1169 "parser.y"
                        {
        (yyval.expr).expr_type = CHAR_EXPR;
        (yyval.expr).expr_value.char_value = (yyvsp[0].cval);
        (yyval.expr).expr_return_type = CHAR_VALUE;
        (yyval.expr).associated_identifier = NULL;
    }
#line 2992 "parser.tab.c"
    break;

  case 90: /* expression: array_element  */
#line 1175 "parser.y"
                    { (yyval.expr) = (yyvsp[0].expr); }
#line 2998 "parser.tab.c"
    break;

  case 91: /* array_element: IDENTIFIER OPENING_SQUARE_BRACKETS INTEGER_LITERAL CLOSING_SQUARE_BRACKETS  */
#line 1179 "parser.y"
                                                                               {
        SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[-3].sval), scope_no, get_current_enclosing_function());
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
#line 3046 "parser.tab.c"
    break;

  case 92: /* expr_list: expression  */
#line 1225 "parser.y"
               {
        (yyval.expr_lst).e = &(yyvsp[0].expr);
        (yyval.expr_lst).next_expr = NULL;
        printf("Inside a single expression within an expression list\n");
    }
#line 3056 "parser.tab.c"
    break;

  case 93: /* expr_list: expr_list COMMA expression  */
#line 1230 "parser.y"
                                 {
        printf("Inside an expression within an expression list\n");
        ExprList* new_node = (ExprList*)malloc(sizeof(ExprList));
        new_node->e = &(yyvsp[0].expr);
        new_node->next_expr = NULL;
        ExprList* current = &((yyvsp[-2].expr_lst));
        while (current->next_expr) {
            current = current->next_expr;
        }
        current->next_expr = new_node;
        (yyval.expr_lst) = (yyvsp[-2].expr_lst);
    }
#line 3073 "parser.tab.c"
    break;

  case 94: /* function_call: IDENTIFIER OPENING_PARENTHESIS expr_list CLOSING_PARENTHESIS  */
#line 1245 "parser.y"
                                                                 {
        printf("Inside a function call with arguments\n");
        SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[-3].sval), scope_no, get_current_enclosing_function());
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
        ExprList* arg = &((yyvsp[-1].expr_lst));
        while (param && arg && arg->e) {
            ValueType param_type;
            size_t param_size = param->array_length;
            if (param_size > 0) {
                param_type = keyword_to_array_value_type(param->type);
            }else{
                param_type = string_to_value_type(param->type);
            }
            if (param_type != arg->e->expr_return_type || 
                (param_type >= INT_ARRAY_VALUE && param_size != arg->e->array_length)) {
                fprintf(stderr, "Parameter type or size mismatch for '%s' at line %d\n", (yyvsp[-3].sval), yylineno);
                free_symbol_table(symbol_table);
                exit(1);
            }
            param = param->next;
            arg = arg->next_expr;
        }
        if ((param && !param->next) || (arg && !arg->next_expr)) {
            fprintf(stderr, "Incorrect number of arguments for '%s' at line %d\n", (yyvsp[-3].sval), yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        int prev_scope_no = scope_no;
        scope_no = result->scope_no + 1;
        (yyval.expr).expr_type = FUNCTION_CALL_EXPR;
        (yyval.expr).associated_identifier = strdup((yyvsp[-3].sval));
        (yyval.expr).array_length = result->array_length;
        if (result->array_length > 0) {
            (yyval.expr).expr_return_type = keyword_to_array_value_type(result->type);
            char* size_str = strchr(result->type, '[') + 1;
            (yyval.expr).array_length = atoi(size_str);
        }else{
            (yyval.expr).expr_return_type = string_to_value_type(result->type);
        }
        scope_no = prev_scope_no;
    }
#line 3129 "parser.tab.c"
    break;

  case 95: /* function_call: IDENTIFIER OPENING_PARENTHESIS CLOSING_PARENTHESIS  */
#line 1296 "parser.y"
                                                         {
        printf("Inside a function call without arguments\n");
        SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[-2].sval), scope_no, get_current_enclosing_function());
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
        int prev_scope_no = scope_no;
        scope_no = result->scope_no + 1;
        (yyval.expr).expr_type = FUNCTION_CALL_EXPR;
        (yyval.expr).associated_identifier = strdup((yyvsp[-2].sval));
        (yyval.expr).array_length = result->array_length;
        if (result->array_length > 0) {
            (yyval.expr).expr_return_type = keyword_to_array_value_type(result->type);
            char* size_str = strchr(result->type, '[') + 1;
            (yyval.expr).array_length = atoi(size_str);
        }else{
            (yyval.expr).expr_return_type = string_to_value_type(result->type);
        }
        scope_no = prev_scope_no;
    }
#line 3166 "parser.tab.c"
    break;

  case 96: /* boolean_expr: expression EQUAL arithmetic_expr  */
#line 1331 "parser.y"
                                     {
        printf("Arithmetic expression within an == boolean expression\n");
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
        if ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE || (yyvsp[0].expr).expr_return_type == FLOAT_VALUE) {
            float left = ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[-2].expr).expr_value.float_value : (yyvsp[-2].expr).expr_value.int_value;
            float right = ((yyvsp[0].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[0].expr).expr_value.float_value : (yyvsp[0].expr).expr_value.int_value;
            (yyval.expr).expr_value.int_value = (left == right);
        } else if ((yyvsp[-2].expr).expr_return_type == STRING_VALUE) {
            (yyval.expr).expr_value.int_value = (strcmp((yyvsp[-2].expr).expr_value.char_array, (yyvsp[0].expr).expr_value.char_array) == 0);
        } else {
            (yyval.expr).expr_value.int_value = ((yyvsp[-2].expr).expr_value.int_value == (yyvsp[0].expr).expr_value.int_value);
        }
    }
#line 3193 "parser.tab.c"
    break;

  case 97: /* boolean_expr: expression EQUAL function_call  */
#line 1353 "parser.y"
                                     {
        printf("Function call within an == boolean expression\n");
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
        if ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE || (yyvsp[0].expr).expr_return_type == FLOAT_VALUE) {
            float left = ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[-2].expr).expr_value.float_value : (yyvsp[-2].expr).expr_value.int_value;
            float right = ((yyvsp[0].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[0].expr).expr_value.float_value : (yyvsp[0].expr).expr_value.int_value;
            (yyval.expr).expr_value.int_value = (left == right);
        } else if ((yyvsp[-2].expr).expr_return_type == STRING_VALUE) {
            (yyval.expr).expr_value.int_value = (strcmp((yyvsp[-2].expr).expr_value.char_array, (yyvsp[0].expr).expr_value.char_array) == 0);
        } else {
            (yyval.expr).expr_value.int_value = ((yyvsp[-2].expr).expr_value.int_value == (yyvsp[0].expr).expr_value.int_value);
        }
    }
#line 3220 "parser.tab.c"
    break;

  case 98: /* boolean_expr: expression NOT_EQUAL arithmetic_expr  */
#line 1375 "parser.y"
                                           {
        printf("Arithmetic within an != boolean expression\n");
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
        if ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE || (yyvsp[0].expr).expr_return_type == FLOAT_VALUE) {
            float left = ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[-2].expr).expr_value.float_value : (yyvsp[-2].expr).expr_value.int_value;
            float right = ((yyvsp[0].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[0].expr).expr_value.float_value : (yyvsp[0].expr).expr_value.int_value;
            (yyval.expr).expr_value.int_value = (left != right);
        } else if ((yyvsp[-2].expr).expr_return_type == STRING_VALUE) {
            (yyval.expr).expr_value.int_value = (strcmp((yyvsp[-2].expr).expr_value.char_array, (yyvsp[0].expr).expr_value.char_array) != 0);
        } else {
            (yyval.expr).expr_value.int_value = ((yyvsp[-2].expr).expr_value.int_value != (yyvsp[0].expr).expr_value.int_value);
        }
    }
#line 3247 "parser.tab.c"
    break;

  case 99: /* boolean_expr: expression NOT_EQUAL function_call  */
#line 1397 "parser.y"
                                         {
        printf("function call within an != boolean expression\n");
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
        if ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE || (yyvsp[0].expr).expr_return_type == FLOAT_VALUE) {
            float left = ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[-2].expr).expr_value.float_value : (yyvsp[-2].expr).expr_value.int_value;
            float right = ((yyvsp[0].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[0].expr).expr_value.float_value : (yyvsp[0].expr).expr_value.int_value;
            (yyval.expr).expr_value.int_value = (left != right);
        } else if ((yyvsp[-2].expr).expr_return_type == STRING_VALUE) {
            (yyval.expr).expr_value.int_value = (strcmp((yyvsp[-2].expr).expr_value.char_array, (yyvsp[0].expr).expr_value.char_array) != 0);
        } else {
            (yyval.expr).expr_value.int_value = ((yyvsp[-2].expr).expr_value.int_value != (yyvsp[0].expr).expr_value.int_value);
        }
    }
#line 3274 "parser.tab.c"
    break;

  case 100: /* boolean_expr: expression GREATER_OR_EQUAL arithmetic_expr  */
#line 1419 "parser.y"
                                                  {
        printf("Arithmetic within an >= boolean expression\n");
        if (((yyvsp[-2].expr).expr_return_type != INT_VALUE && (yyvsp[-2].expr).expr_return_type != FLOAT_VALUE) ||
            ((yyvsp[0].expr).expr_return_type != INT_VALUE && (yyvsp[0].expr).expr_return_type != FLOAT_VALUE)) {
            fprintf(stderr, "Invalid types for >= at line %d\n", yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        (yyval.expr).expr_type = BOOL_EXPR;
        (yyval.expr).expr_return_type = BOOL_VALUE;
        (yyval.expr).associated_identifier = NULL;
        float left = ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[-2].expr).expr_value.float_value : (yyvsp[-2].expr).expr_value.int_value;
        float right = ((yyvsp[0].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[0].expr).expr_value.float_value : (yyvsp[0].expr).expr_value.int_value;
        (yyval.expr).expr_value.int_value = (left >= right);
    }
#line 3294 "parser.tab.c"
    break;

  case 101: /* boolean_expr: expression GREATER_OR_EQUAL function_call  */
#line 1434 "parser.y"
                                                {
        printf("Function call within an >= boolean expression\n");
        if (((yyvsp[-2].expr).expr_return_type != INT_VALUE && (yyvsp[-2].expr).expr_return_type != FLOAT_VALUE) ||
            ((yyvsp[0].expr).expr_return_type != INT_VALUE && (yyvsp[0].expr).expr_return_type != FLOAT_VALUE)) {
            fprintf(stderr, "Invalid types for >= at line %d\n", yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        (yyval.expr).expr_type = BOOL_EXPR;
        (yyval.expr).expr_return_type = BOOL_VALUE;
        (yyval.expr).associated_identifier = NULL;
        float left = ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[-2].expr).expr_value.float_value : (yyvsp[-2].expr).expr_value.int_value;
        float right = ((yyvsp[0].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[0].expr).expr_value.float_value : (yyvsp[0].expr).expr_value.int_value;
        (yyval.expr).expr_value.int_value = (left >= right);
    }
#line 3314 "parser.tab.c"
    break;

  case 102: /* boolean_expr: expression LESS_OR_EQUAL arithmetic_expr  */
#line 1449 "parser.y"
                                               {
        printf("Arithmetic within an <= boolean expression\n");
        if (((yyvsp[-2].expr).expr_return_type != INT_VALUE && (yyvsp[-2].expr).expr_return_type != FLOAT_VALUE) ||
            ((yyvsp[0].expr).expr_return_type != INT_VALUE && (yyvsp[0].expr).expr_return_type != FLOAT_VALUE)) {
            fprintf(stderr, "Invalid types for <= at line %d\n", yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        (yyval.expr).expr_type = BOOL_EXPR;
        (yyval.expr).expr_return_type = BOOL_VALUE;
        (yyval.expr).associated_identifier = NULL;
        float left = ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[-2].expr).expr_value.float_value : (yyvsp[-2].expr).expr_value.int_value;
        float right = ((yyvsp[0].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[0].expr).expr_value.float_value : (yyvsp[0].expr).expr_value.int_value;
        (yyval.expr).expr_value.int_value = (left <= right);
    }
#line 3334 "parser.tab.c"
    break;

  case 103: /* boolean_expr: expression LESS_OR_EQUAL function_call  */
#line 1464 "parser.y"
                                             {
        printf("Function call within an <= boolean expression\n");
        if (((yyvsp[-2].expr).expr_return_type != INT_VALUE && (yyvsp[-2].expr).expr_return_type != FLOAT_VALUE) ||
            ((yyvsp[0].expr).expr_return_type != INT_VALUE && (yyvsp[0].expr).expr_return_type != FLOAT_VALUE)) {
            fprintf(stderr, "Invalid types for <= at line %d\n", yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        (yyval.expr).expr_type = BOOL_EXPR;
        (yyval.expr).expr_return_type = BOOL_VALUE;
        (yyval.expr).associated_identifier = NULL;
        float left = ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[-2].expr).expr_value.float_value : (yyvsp[-2].expr).expr_value.int_value;
        float right = ((yyvsp[0].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[0].expr).expr_value.float_value : (yyvsp[0].expr).expr_value.int_value;
        (yyval.expr).expr_value.int_value = (left <= right);
    }
#line 3354 "parser.tab.c"
    break;

  case 104: /* boolean_expr: expression GREATER arithmetic_expr  */
#line 1479 "parser.y"
                                         {
        printf("Arithmetic within a > boolean expression\n");
        if (((yyvsp[-2].expr).expr_return_type != INT_VALUE && (yyvsp[-2].expr).expr_return_type != FLOAT_VALUE) ||
            ((yyvsp[0].expr).expr_return_type != INT_VALUE && (yyvsp[0].expr).expr_return_type != FLOAT_VALUE)) {
            fprintf(stderr, "Invalid types for > at line %d\n", yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        (yyval.expr).expr_type = BOOL_EXPR;
        (yyval.expr).expr_return_type = BOOL_VALUE;
        (yyval.expr).associated_identifier = NULL;
        float left = ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[-2].expr).expr_value.float_value : (yyvsp[-2].expr).expr_value.int_value;
        float right = ((yyvsp[0].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[0].expr).expr_value.float_value : (yyvsp[0].expr).expr_value.int_value;
        (yyval.expr).expr_value.int_value = (left > right);
    }
#line 3374 "parser.tab.c"
    break;

  case 105: /* boolean_expr: expression GREATER function_call  */
#line 1494 "parser.y"
                                       {
        printf("Function call within a > boolean expression\n");
        if (((yyvsp[-2].expr).expr_return_type != INT_VALUE && (yyvsp[-2].expr).expr_return_type != FLOAT_VALUE) ||
            ((yyvsp[0].expr).expr_return_type != INT_VALUE && (yyvsp[0].expr).expr_return_type != FLOAT_VALUE)) {
            fprintf(stderr, "Invalid types for > at line %d\n", yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        (yyval.expr).expr_type = BOOL_EXPR;
        (yyval.expr).expr_return_type = BOOL_VALUE;
        (yyval.expr).associated_identifier = NULL;
        float left = ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[-2].expr).expr_value.float_value : (yyvsp[-2].expr).expr_value.int_value;
        float right = ((yyvsp[0].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[0].expr).expr_value.float_value : (yyvsp[0].expr).expr_value.int_value;
        (yyval.expr).expr_value.int_value = (left > right);
    }
#line 3394 "parser.tab.c"
    break;

  case 106: /* boolean_expr: expression LESS arithmetic_expr  */
#line 1509 "parser.y"
                                      {
        printf("Arithmetic within a < boolean expression\n");
        if (((yyvsp[-2].expr).expr_return_type != INT_VALUE && (yyvsp[-2].expr).expr_return_type != FLOAT_VALUE) ||
            ((yyvsp[0].expr).expr_return_type != INT_VALUE && (yyvsp[0].expr).expr_return_type != FLOAT_VALUE)) {
            fprintf(stderr, "Invalid types for < at line %d\n", yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        (yyval.expr).expr_type = BOOL_EXPR;
        (yyval.expr).expr_return_type = BOOL_VALUE;
        (yyval.expr).associated_identifier = NULL;
        float left = ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[-2].expr).expr_value.float_value : (yyvsp[-2].expr).expr_value.int_value;
        float right = ((yyvsp[0].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[0].expr).expr_value.float_value : (yyvsp[0].expr).expr_value.int_value;
        (yyval.expr).expr_value.int_value = (left < right);
    }
#line 3414 "parser.tab.c"
    break;

  case 107: /* boolean_expr: expression LESS function_call  */
#line 1524 "parser.y"
                                    {
        printf("Function call within an < boolean expression\n");
        if (((yyvsp[-2].expr).expr_return_type != INT_VALUE && (yyvsp[-2].expr).expr_return_type != FLOAT_VALUE) ||
            ((yyvsp[0].expr).expr_return_type != INT_VALUE && (yyvsp[0].expr).expr_return_type != FLOAT_VALUE)) {
            fprintf(stderr, "Invalid types for < at line %d\n", yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        (yyval.expr).expr_type = BOOL_EXPR;
        (yyval.expr).expr_return_type = BOOL_VALUE;
        (yyval.expr).associated_identifier = NULL;
        float left = ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[-2].expr).expr_value.float_value : (yyvsp[-2].expr).expr_value.int_value;
        float right = ((yyvsp[0].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[0].expr).expr_value.float_value : (yyvsp[0].expr).expr_value.int_value;
        (yyval.expr).expr_value.int_value = (left < right);
    }
#line 3434 "parser.tab.c"
    break;

  case 108: /* arithmetic_expr: binary_expr  */
#line 1541 "parser.y"
                              { (yyval.expr) = (yyvsp[0].expr); printf("Outside arithmetic expression\n"); }
#line 3440 "parser.tab.c"
    break;

  case 109: /* binary_expr: binary_expr PLUS arithmetic_term  */
#line 1544 "parser.y"
                                               {
                printf("Arithmetic term with an + arithmetic expression\n");
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
#line 3465 "parser.tab.c"
    break;

  case 110: /* binary_expr: binary_expr MINUS arithmetic_term  */
#line 1564 "parser.y"
                                                {
                printf("Arithmetic term with a - arithmetic expression\n");
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
#line 3490 "parser.tab.c"
    break;

  case 111: /* binary_expr: arithmetic_term  */
#line 1584 "parser.y"
                              { printf("Arithmetic term with an arithmetic expression\n"); (yyval.expr) = (yyvsp[0].expr); }
#line 3496 "parser.tab.c"
    break;

  case 112: /* arithmetic_term: arithmetic_term ASTRISK arithmetic_factor  */
#line 1587 "parser.y"
                                                            {
                    printf("Arithmetic factor with an * arithmetic term\n");
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
#line 3521 "parser.tab.c"
    break;

  case 113: /* arithmetic_term: arithmetic_term DIVIDE arithmetic_factor  */
#line 1607 "parser.y"
                                                           {
                    printf("Arithmetic factor with an / arithmetic term\n");
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
#line 3552 "parser.tab.c"
    break;

  case 114: /* arithmetic_term: arithmetic_term MODULO INTEGER_LITERAL  */
#line 1633 "parser.y"
                                                         {
                    printf("INTEGER_LITERAL with an mod arithmetic term\n");
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
#line 3574 "parser.tab.c"
    break;

  case 115: /* arithmetic_term: arithmetic_term MODULO OPENING_PARENTHESIS expression CLOSING_PARENTHESIS  */
#line 1650 "parser.y"
                                                                                            {
                    printf("(expression) with a mod arithmetic term\n");
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
#line 3596 "parser.tab.c"
    break;

  case 116: /* arithmetic_term: arithmetic_factor  */
#line 1667 "parser.y"
                                    { (yyval.expr) = (yyvsp[0].expr);printf("Arithmetic factor within n arithmetic term\n"); }
#line 3602 "parser.tab.c"
    break;

  case 117: /* arithmetic_factor: bitwise_expr  */
#line 1670 "parser.y"
                                 { (yyval.expr) = (yyvsp[0].expr); printf("Bitwise expression within a * arithmetic factor\n"); }
#line 3608 "parser.tab.c"
    break;

  case 118: /* arithmetic_factor: OPENING_PARENTHESIS expression CLOSING_PARENTHESIS  */
#line 1671 "parser.y"
                                                                       { (yyval.expr) = (yyvsp[-1].expr); }
#line 3614 "parser.tab.c"
    break;

  case 119: /* bitwise_expr: bitwise_expr BITWISE_OR bitwise_xor_expr  */
#line 1674 "parser.y"
                                                        {
                 printf("Bitwise xor expression within a or bitwise expr\n");
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
#line 3631 "parser.tab.c"
    break;

  case 120: /* bitwise_expr: bitwise_xor_expr  */
#line 1686 "parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); printf("Bitwise xor expression within a bitwise expr\n");}
#line 3637 "parser.tab.c"
    break;

  case 121: /* bitwise_xor_expr: bitwise_xor_expr BITWISE_XOR bitwise_and_expr  */
#line 1689 "parser.y"
                                                                 {
                    printf("Bitwise and expression within an xor bitwise xor expr\n");
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
#line 3654 "parser.tab.c"
    break;

  case 122: /* bitwise_xor_expr: bitwise_and_expr  */
#line 1701 "parser.y"
                                    { (yyval.expr) = (yyvsp[0].expr); printf("Bitwise and expression within a bitwise xor expr\n");}
#line 3660 "parser.tab.c"
    break;

  case 123: /* bitwise_and_expr: bitwise_and_expr BITWISE_AND bitwise_not_expr  */
#line 1704 "parser.y"
                                                                 {
                     printf("Bitwise not expression within an and bitwise and expr\n");
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
#line 3677 "parser.tab.c"
    break;

  case 124: /* bitwise_and_expr: bitwise_not_expr  */
#line 1716 "parser.y"
                                    { (yyval.expr) = (yyvsp[0].expr); printf("Bitwise not expression within a bitwise and expr\n"); }
#line 3683 "parser.tab.c"
    break;

  case 125: /* bitwise_not_expr: BITWISE_NOT bitwise_not_expr  */
#line 1719 "parser.y"
                                                {
                     printf("Bitwise not expression within a not bitwise not expr\n");
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
#line 3700 "parser.tab.c"
    break;

  case 127: /* unary_expr: IDENTIFIER  */
#line 1735 "parser.y"
               {
        printf("Identifier withing a unary expression\n");
        SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[0].sval), scope_no, get_current_enclosing_function());
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
#line 3748 "parser.tab.c"
    break;

  case 128: /* unary_expr: INTEGER_LITERAL  */
#line 1778 "parser.y"
                      {
                     (yyval.expr).expr_type = INT_EXPR;
                     (yyval.expr).expr_return_type = INT_VALUE;
                     (yyval.expr).expr_value.int_value = (yyvsp[0].ival);
                     (yyval.expr).associated_identifier = NULL;
                 }
#line 3759 "parser.tab.c"
    break;

  case 129: /* unary_expr: FLOAT_LITERAL  */
#line 1784 "parser.y"
                    {
                      (yyval.expr).expr_type = FLOAT_EXPR;
                      (yyval.expr).expr_value.float_value = (yyvsp[0].fval);
                      (yyval.expr).expr_return_type = FLOAT_VALUE;
                      (yyval.expr).associated_identifier = NULL;
                  }
#line 3770 "parser.tab.c"
    break;

  case 130: /* unary_expr: IDENTIFIER INCREMENT  */
#line 1790 "parser.y"
                           {
        SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[-1].sval), scope_no, get_current_enclosing_function());
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
#line 3802 "parser.tab.c"
    break;

  case 131: /* unary_expr: IDENTIFIER DECREMENT  */
#line 1817 "parser.y"
                           {
        SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[-1].sval), scope_no, get_current_enclosing_function());
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
#line 3834 "parser.tab.c"
    break;

  case 132: /* unary_expr: MINUS IDENTIFIER  */
#line 1844 "parser.y"
                       {
        SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[0].sval), scope_no, get_current_enclosing_function());
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
#line 3861 "parser.tab.c"
    break;

  case 133: /* unary_expr: MINUS OPENING_PARENTHESIS expression CLOSING_PARENTHESIS  */
#line 1866 "parser.y"
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
#line 3882 "parser.tab.c"
    break;

  case 134: /* unary_expr: OPENING_PARENTHESIS expression CLOSING_PARENTHESIS INCREMENT  */
#line 1882 "parser.y"
                                                                   {
        fprintf(stderr, "Increment on expression not supported at line %d\n", yylineno);
        free_symbol_table(symbol_table);
        exit(1);
    }
#line 3892 "parser.tab.c"
    break;

  case 135: /* unary_expr: OPENING_PARENTHESIS expression CLOSING_PARENTHESIS DECREMENT  */
#line 1887 "parser.y"
                                                                   {
        fprintf(stderr, "Decrement on expression not supported at line %d\n", yylineno);
        free_symbol_table(symbol_table);
        exit(1);
    }
#line 3902 "parser.tab.c"
    break;

  case 136: /* $@23: %empty  */
#line 1896 "parser.y"
                                                         { 
        scope_no++;
        push_function("main");
    }
#line 3911 "parser.tab.c"
    break;

  case 137: /* main_function: MAIN_KEYWORD OPENING_PARENTHESIS CLOSING_PARENTHESIS $@23 body  */
#line 1900 "parser.y"
         {
        char* popped = pop_function();
        if (popped) free(popped);
        scope_no--;
    }
#line 3921 "parser.tab.c"
    break;


#line 3925 "parser.tab.c"

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

#line 1906 "parser.y"



int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <source_file>\n", argv[0]);
        return 1;
    }
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        fprintf(stderr, "Error: Cannot open source file '%s'\n", argv[1]);
        return 1;
    }

    // Create filenames for symbol_table_file and symbol_table_changes_file
    char* base_name = strtok(argv[1], ".");
    char symbol_table_filename[256];
    char symbol_table_changes_filename[256];
    snprintf(symbol_table_filename, sizeof(symbol_table_filename), "%s_symbol_table.txt", base_name);
    snprintf(symbol_table_changes_filename, sizeof(symbol_table_changes_filename), "%s_symbol_table_changes.txt", base_name);

    // Open symbol_table_file for writing
    symbol_table_file = fopen(symbol_table_filename, "w");
    if (!symbol_table_file) {
        fprintf(stderr, "Error: Cannot create symbol table file '%s'\n", symbol_table_filename);
        fclose(yyin);
        return 1;
    }

    // Open symbol_table_changes_file for writing
    symbol_table_changes_file = fopen(symbol_table_changes_filename, "w");
    if (!symbol_table_changes_file) {
        fprintf(stderr, "Error: Cannot create symbol table changes file '%s'\n", symbol_table_changes_filename);
        fclose(symbol_table_file);
        fclose(yyin);
        return 1;
    }

    symbol_table = create_symbol_table();
    if (!symbol_table) {
        fprintf(stderr, "Error: Failed to create symbol table\n");
        fclose(symbol_table_changes_file);
        fclose(symbol_table_file);
        fclose(yyin);
        return 1;
    }

    yylineno = 1;
    int parse_result = yyparse();
    print_symbol_table(symbol_table, symbol_table_file);
    fclose(yyin);
    fclose(symbol_table_file);
    fclose(symbol_table_changes_file);
    if (parse_result == 0) {
        printf("Parsing successful.\n");
    } else {
        printf("Parsing failed.\n");
    }
    free_symbol_table(symbol_table);
    return parse_result;
}
