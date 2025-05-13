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
    else {
        fprintf(stderr, "Unknown type '%s' at line %d\n", type_str, yylineno);
        free_symbol_table(symbol_table);
        exit(1);
    }
}

ValueType keyword_to_array_value_type(const char* keyword) {
    if (strncmp(keyword, "int", 3) == 0) return INT_ARRAY_VALUE;
    if (strncmp(keyword, "float", 5) == 0) return FLOAT_ARRAY_VALUE;
    if (strncmp(keyword, "string", 6) == 0) return STRING_ARRAY_VALUE;
    if (strncmp(keyword, "char", 4) == 0) return CHAR_ARRAY_VALUE;
    if (strncmp(keyword, "bool", 4) == 0) return BOOL_ARRAY_VALUE;
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
    fprintf(stderr, "Error at line %d: %s\n", yylineno, s);
    free_function_stack();
    free_symbol_table(symbol_table);
    exit(1);
}


#line 211 "parser.tab.c"

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
  YYSYMBOL_return_statement = 101,         /* return_statement  */
  YYSYMBOL_assignment = 102,               /* assignment  */
  YYSYMBOL_103_16 = 103,                   /* $@16  */
  YYSYMBOL_array_assignment = 104,         /* array_assignment  */
  YYSYMBOL_105_17 = 105,                   /* $@17  */
  YYSYMBOL_expression = 106,               /* expression  */
  YYSYMBOL_array_element = 107,            /* array_element  */
  YYSYMBOL_expr_list = 108,                /* expr_list  */
  YYSYMBOL_function_call = 109,            /* function_call  */
  YYSYMBOL_boolean_expr = 110,             /* boolean_expr  */
  YYSYMBOL_arithmetic_expr = 111,          /* arithmetic_expr  */
  YYSYMBOL_binary_expr = 112,              /* binary_expr  */
  YYSYMBOL_arithmetic_term = 113,          /* arithmetic_term  */
  YYSYMBOL_arithmetic_factor = 114,        /* arithmetic_factor  */
  YYSYMBOL_bitwise_expr = 115,             /* bitwise_expr  */
  YYSYMBOL_bitwise_xor_expr = 116,         /* bitwise_xor_expr  */
  YYSYMBOL_bitwise_and_expr = 117,         /* bitwise_and_expr  */
  YYSYMBOL_bitwise_not_expr = 118,         /* bitwise_not_expr  */
  YYSYMBOL_unary_expr = 119,               /* unary_expr  */
  YYSYMBOL_main_function = 120,            /* main_function  */
  YYSYMBOL_121_18 = 121                    /* $@18  */
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
#define YYLAST   345

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  133
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  265

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
       0,   229,   229,   229,   233,   234,   240,   245,   240,   269,
     274,   269,   291,   291,   315,   315,   335,   364,   391,   396,
     404,   405,   406,   407,   408,   413,   413,   428,   430,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   449,   452,   453,   456,   457,   460,   463,
     464,   465,   469,   492,   520,   548,   549,   552,   555,   559,
     572,   559,   576,   579,   580,   583,   588,   588,   653,   653,
     735,   735,   805,   805,   888,   888,   946,   975,   975,  1023,
    1023,  1125,  1131,  1132,  1133,  1139,  1145,  1146,  1191,  1237,
    1241,  1255,  1302,  1335,  1356,  1377,  1398,  1419,  1433,  1447,
    1461,  1475,  1489,  1503,  1517,  1533,  1534,  1537,  1556,  1575,
    1578,  1597,  1622,  1638,  1654,  1657,  1658,  1664,  1667,  1678,
    1681,  1692,  1695,  1706,  1709,  1720,  1729,  1756,  1783,  1805,
    1821,  1826,  1835,  1835
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
  "variable_declaration", "$@15", "return_statement", "assignment", "$@16",
  "array_assignment", "$@17", "expression", "array_element", "expr_list",
  "function_call", "boolean_expr", "arithmetic_expr", "binary_expr",
  "arithmetic_term", "arithmetic_factor", "bitwise_expr",
  "bitwise_xor_expr", "bitwise_and_expr", "bitwise_not_expr", "unary_expr",
  "main_function", "$@18", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-136)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-73)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -136,    24,   280,  -136,  -136,  -136,  -136,  -136,  -136,    12,
       7,   280,    33,     5,    19,  -136,  -136,    28,    42,    60,
      74,  -136,   106,  -136,  -136,   106,  -136,   168,  -136,    25,
    -136,  -136,   206,  -136,    61,  -136,   106,  -136,   110,  -136,
    -136,  -136,   163,  -136,  -136,    96,  -136,  -136,  -136,  -136,
    -136,   101,    89,   118,   127,   136,  -136,    80,   106,    80,
      58,    20,  -136,    -4,    27,   122,   111,   220,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,   199,
    -136,  -136,  -136,  -136,   100,   121,  -136,   133,   146,   162,
    -136,  -136,  -136,   219,  -136,    40,   234,  -136,  -136,    46,
      80,   287,    80,   228,   239,    86,   215,   217,    56,  -136,
      80,  -136,   256,    80,   202,    28,  -136,  -136,  -136,    26,
      26,    26,    26,    26,    26,  -136,    34,    34,    34,    34,
      23,    20,    20,    20,  -136,  -136,   254,   233,   232,    80,
     254,   254,   235,   226,    -4,   216,  -136,  -136,   240,  -136,
     249,  -136,   238,   250,   147,    77,   248,   254,  -136,   145,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,    80,   121,   121,  -136,  -136,  -136,    80,   146,
     162,  -136,  -136,    80,  -136,    31,   229,  -136,    80,    80,
    -136,   278,    80,    80,   311,  -136,  -136,  -136,   269,   258,
     107,   160,   254,  -136,  -136,   301,   260,  -136,   288,   284,
     230,   285,   289,  -136,  -136,  -136,   263,   290,   306,   318,
    -136,   270,  -136,   281,    80,  -136,    80,  -136,  -136,   105,
     294,  -136,   307,  -136,   296,   161,   295,  -136,  -136,  -136,
      80,  -136,   330,    70,  -136,    80,  -136,  -136,   254,  -136,
     277,   279,   302,  -136,   176,   282,  -136,   220,   163,  -136,
     283,  -136,  -136,  -136,  -136
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     5,     1,    20,    21,    22,    23,    24,     0,
       0,     5,     0,     0,     0,     3,     4,     0,     9,     0,
       6,    14,     0,   132,    12,     0,    25,     0,    16,     0,
      25,    25,     0,    15,     0,    10,     0,    18,     0,   133,
      13,     7,    25,    25,    17,     0,    25,   125,   116,    85,
      84,    87,     0,     0,     0,     0,    25,     0,     0,     0,
       0,     0,    42,    74,     0,     0,     0,    28,    37,    38,
      39,    40,    41,    34,    36,    35,    32,    30,    31,     0,
      86,    83,    81,    82,   105,   109,   114,   115,   119,   121,
     123,   106,    11,     0,     8,     0,     0,   126,   127,     0,
       0,    51,     0,     0,     0,    87,     0,    70,     0,   128,
       0,   124,     0,     0,     0,    18,    29,    26,    27,     0,
       0,     0,     0,     0,     0,    33,     0,     0,     0,     0,
       0,     0,     0,     0,    19,    92,    89,     0,     0,     0,
      77,     0,    81,     0,     0,     0,    50,    49,    81,    59,
       0,    76,     0,     0,   117,     0,     0,    66,    75,     0,
      94,    93,    96,    95,   100,    99,    98,    97,   104,   103,
     102,   101,     0,   107,   108,   110,   111,   112,     0,   118,
     120,   122,    91,     0,    88,     0,     0,    25,     0,     0,
      25,     0,     0,     0,     0,   130,   131,   129,     0,     0,
       0,     0,    90,    79,    78,    45,    81,    57,     0,    81,
       0,     0,     0,    67,   117,   113,     0,     0,    47,    56,
      60,     0,    71,     0,     0,    80,     0,    25,    43,     0,
       0,    55,     0,    58,     0,     0,    81,    46,    53,    54,
       0,    25,     0,     0,    64,     0,    68,    25,    52,    48,
       0,     0,     0,    63,     0,     0,    44,    28,    25,    61,
       0,    69,    65,    62,    73
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,  -136,   326,    45,  -136,  -136,  -136,  -136,  -136,
    -136,   313,     0,    -2,   -25,  -136,   -64,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,    99,   242,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,   243,  -136,  -136,  -136,   -40,  -136,  -135,  -108,   -92,
     188,  -136,   -55,    92,  -136,   208,   213,   -54,  -136,  -136,
    -136
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    10,    62,    25,    46,    22,    43,    31,
      26,    27,    63,    29,    65,    34,    66,    67,    68,   218,
     228,    69,   145,   230,    70,    71,    72,   191,   232,   252,
     243,   244,    73,   199,   255,    74,   152,   153,    75,   114,
      76,    77,   186,    78,   216,   141,    80,   137,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    15,
      30
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      12,    33,    79,   118,   185,    39,    40,   111,   142,    12,
     148,   160,   162,   164,   166,   168,   170,   106,    92,   108,
      13,    94,    28,    47,     3,    28,   177,    79,    14,    47,
      48,   104,   112,    37,   159,   115,    44,    47,    48,    18,
      64,    17,   113,    47,    48,    49,    50,    11,   105,    47,
      48,    49,    50,    19,   105,   136,    11,   178,   107,   140,
      59,    38,    20,    38,   203,    64,   109,    60,   172,   183,
     155,   173,   174,   157,    59,   135,    61,    21,   139,   181,
      59,    60,    61,    47,    48,    49,    50,    60,   105,   235,
      61,   154,   110,    42,   242,    23,    61,   206,   251,   136,
     209,   144,    61,   119,   120,   121,   122,   123,   124,    24,
     254,   231,   197,    45,    59,     4,     5,     6,     7,     8,
      95,    60,    96,   100,   119,   120,   121,   122,   123,   124,
      97,    98,   200,    93,   236,    95,    61,    96,   201,    95,
     126,   127,   214,   202,   117,    97,    98,    99,   140,   238,
     239,   240,   101,   210,   119,   120,   121,   122,   123,   124,
     128,   102,   205,   129,   130,   207,    47,    48,    49,    50,
     103,    51,     4,     5,     6,     7,     8,     9,    52,    95,
     116,    53,    54,    55,   136,    56,    57,   131,    58,    97,
      98,   195,   196,   262,   263,   215,   -28,    59,   246,   183,
     248,   132,   237,    35,    60,   136,    36,   119,   120,   121,
     122,   123,   124,   260,   183,   133,   249,    79,    79,    61,
     175,   176,   256,    47,    48,    49,    50,   134,    51,     4,
       5,     6,     7,     8,     9,    52,   149,   138,    53,    54,
      55,    41,    56,    57,    36,    58,   119,   120,   121,   122,
     123,   124,   -25,   -72,    59,    64,    64,   125,   150,   156,
     158,    60,   119,   120,   121,   122,   123,   124,   182,   184,
     187,   183,   188,   151,   189,   190,    61,   119,   120,   121,
     122,   123,   124,   192,   193,   198,   194,   204,   222,     4,
       5,     6,     7,     8,     9,   143,     4,     5,     6,     7,
       8,   119,   120,   121,   122,   123,   124,   161,   163,   165,
     167,   169,   171,   208,   211,   212,   213,   217,   219,   221,
     220,   225,   223,   227,   226,   224,   229,   234,   233,   241,
     247,   242,   245,   250,   257,   259,   258,    16,    32,   179,
     261,   264,   253,   146,   147,   180
};

static const yytype_int16 yycheck[] =
{
       2,    26,    42,    67,   139,    30,    31,    61,   100,    11,
     102,   119,   120,   121,   122,   123,   124,    57,    43,    59,
       8,    46,    22,     3,     0,    25,     3,    67,    21,     3,
       4,    56,    36,     8,     8,     8,    36,     3,     4,    34,
      42,     8,    46,     3,     4,     5,     6,     2,     8,     3,
       4,     5,     6,    34,     8,    95,    11,    34,    58,    99,
      34,    36,    34,    36,    33,    67,     8,    41,    34,    38,
     110,   126,   127,   113,    34,    35,    56,    35,    32,   133,
      34,    41,    56,     3,     4,     5,     6,    41,     8,   224,
      56,    35,    34,    32,    24,    35,    56,   189,    28,   139,
     192,   101,    56,    47,    48,    49,    50,    51,    52,    35,
     245,   219,    35,     3,    34,     9,    10,    11,    12,    13,
      34,    41,    36,    34,    47,    48,    49,    50,    51,    52,
      44,    45,   172,    37,   226,    34,    56,    36,   178,    34,
      40,    41,    35,   183,    33,    44,    45,    46,   188,    44,
      45,    46,    34,   193,    47,    48,    49,    50,    51,    52,
      39,    34,   187,    42,    43,   190,     3,     4,     5,     6,
      34,     8,     9,    10,    11,    12,    13,    14,    15,    34,
      58,    18,    19,    20,   224,    22,    23,    54,    25,    44,
      45,    44,    45,   257,   258,    35,    33,    34,    37,    38,
     240,    55,   227,    35,    41,   245,    38,    47,    48,    49,
      50,    51,    52,    37,    38,    53,   241,   257,   258,    56,
     128,   129,   247,     3,     4,     5,     6,     8,     8,     9,
      10,    11,    12,    13,    14,    15,     8,     3,    18,    19,
      20,    35,    22,    23,    38,    25,    47,    48,    49,    50,
      51,    52,    32,    36,    34,   257,   258,    58,    19,     3,
      58,    41,    47,    48,    49,    50,    51,    52,    35,    37,
      35,    38,    46,    58,    58,    35,    56,    47,    48,    49,
      50,    51,    52,    34,    46,    37,    36,    58,    58,     9,
      10,    11,    12,    13,    14,     8,     9,    10,    11,    12,
      13,    47,    48,    49,    50,    51,    52,   119,   120,   121,
     122,   123,   124,    35,     3,    46,    58,    16,    58,    35,
      32,    58,    37,    17,    34,    36,     8,    46,    58,    35,
      35,    24,    36,     3,    57,    33,    57,    11,    25,   131,
      58,    58,   243,   101,   101,   132
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    62,    63,     0,     9,    10,    11,    12,    13,    14,
      64,    65,    74,     8,    21,   120,    64,     8,    34,    34,
      34,    35,    68,    35,    35,    66,    71,    72,    73,    74,
     121,    70,    72,    75,    76,    35,    38,     8,    36,    75,
      75,    35,    32,    69,    73,     3,    67,     3,     4,     5,
       6,     8,    15,    18,    19,    20,    22,    23,    25,    34,
      41,    56,    65,    73,    74,    75,    77,    78,    79,    82,
      85,    86,    87,    93,    96,    99,   101,   102,   104,   106,
     107,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    75,    37,    75,    34,    36,    44,    45,    46,
      34,    34,    34,    34,    75,     8,   106,    73,   106,     8,
      34,   118,    36,    46,   100,     8,    58,    33,    77,    47,
      48,    49,    50,    51,    52,    58,    40,    41,    39,    42,
      43,    54,    55,    53,     8,    35,   106,   108,     3,    32,
     106,   106,   110,     8,    73,    83,    93,   102,   110,     8,
      19,    58,    97,    98,    35,   106,     3,   106,    58,     8,
     109,   111,   109,   111,   109,   111,   109,   111,   109,   111,
     109,   111,    34,   113,   113,   114,   114,     3,    34,   116,
     117,   118,    35,    38,    37,   108,   103,    35,    46,    58,
      35,    88,    34,    46,    36,    44,    45,    35,    37,    94,
     106,   106,   106,    33,    58,    75,   110,    75,    35,   110,
     106,     3,    46,    58,    35,    35,   105,    16,    80,    58,
      32,    35,    58,    37,    36,    58,    34,    17,    81,     8,
      84,   109,    89,    58,    46,   108,   110,    75,    44,    45,
      46,    35,    24,    91,    92,    36,    37,    35,   106,    75,
       3,    28,    90,    92,   108,    95,    75,    57,    57,    33,
      37,    58,    77,    77,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    63,    62,    64,    64,    66,    67,    65,    68,
      69,    65,    70,    65,    71,    65,    72,    72,    73,    73,
      74,    74,    74,    74,    74,    76,    75,    77,    77,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    79,    80,    80,    81,    81,    82,    83,
      83,    83,    84,    84,    84,    84,    84,    85,    86,    88,
      89,    87,    90,    91,    91,    92,    94,    93,    95,    93,
      97,    96,    98,    96,   100,    99,   101,   103,   102,   105,
     104,   106,   106,   106,   106,   106,   106,   106,   107,   108,
     108,   109,   109,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   111,   111,   112,   112,   112,
     113,   113,   113,   113,   113,   114,   114,   114,   115,   115,
     116,   116,   117,   117,   118,   118,   119,   119,   119,   119,
     119,   119,   121,   120
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     2,     0,     0,     0,     8,     0,
       0,     8,     0,     6,     0,     6,     1,     3,     2,     5,
       1,     1,     1,     1,     1,     0,     4,     2,     0,     2,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     7,     5,     0,     2,     0,     9,     1,
       1,     0,     3,     2,     2,     1,     0,     5,     7,     0,
       0,    10,     3,     2,     1,     4,     0,     5,     0,    10,
       0,     6,     0,    11,     0,     3,     3,     0,     5,     0,
       7,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       3,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     3,     3,     1,
       3,     3,     3,     5,     1,     1,     1,     3,     3,     1,
       3,     1,     3,     1,     2,     1,     2,     2,     2,     4,
       4,     4,     0,     5
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
#line 229 "parser.y"
    { scope_no++; }
#line 1535 "parser.tab.c"
    break;

  case 3: /* program: $@1 functions main_function  */
#line 229 "parser.y"
                                            { delete_scope(symbol_table, scope_no); scope_no--;}
#line 1541 "parser.tab.c"
    break;

  case 6: /* $@2: %empty  */
#line 240 "parser.y"
                                        {
        scope_no++;
        curr_function_parameter_list = NULL;
        push_function((yyvsp[-1].sval));
    }
#line 1551 "parser.tab.c"
    break;

  case 7: /* $@3: %empty  */
#line 245 "parser.y"
                                           {
        inside_a_function_declaration_body = 1;
        curr_function_instructions_list = NULL;
    }
#line 1560 "parser.tab.c"
    break;

  case 8: /* function: type IDENTIFIER OPENING_PARENTHESIS $@2 function_arguments CLOSING_PARENTHESIS $@3 body  */
#line 249 "parser.y"
         {
        Value val;
        val.function = (yyvsp[0].instruction);
        ValueType return_type = string_to_value_type((yyvsp[-7].sval));
        size_t array_size = 0;
        if ((yyvsp[-7].sval)[0] == 'a') {
            return_type = keyword_to_array_value_type((yyvsp[-7].sval) + 1);
            char* size_str = strchr((yyvsp[-7].sval), '[') + 1;
            array_size = atoi(size_str);
        }
        insert_symbol(symbol_table, (yyvsp[-6].sval), (yyvsp[-7].sval), val, FUNCTION, scope_no, 1, 0, array_size > 0, (yyvsp[-3].param_list), yylineno, array_size, get_prev_enclosing_function());
        inside_a_function_declaration_body = 0;
        curr_function_parameter_list = NULL;
        curr_function_parameter_list_ptr = NULL;
        curr_function_instructions_list = NULL;
        char* popped = pop_function();
        if (popped) free(popped);
        scope_no--;
        free((yyvsp[-7].sval));
    }
#line 1585 "parser.tab.c"
    break;

  case 9: /* $@4: %empty  */
#line 269 "parser.y"
                                                       {
        scope_no++;
        curr_function_parameter_list = NULL;
        push_function((yyvsp[-1].sval));
    }
#line 1595 "parser.tab.c"
    break;

  case 10: /* $@5: %empty  */
#line 274 "parser.y"
                                           {
        inside_a_function_declaration_body = 1;
        curr_function_instructions_list = NULL;
    }
#line 1604 "parser.tab.c"
    break;

  case 11: /* function: VOID_TYPE_KEYWORD IDENTIFIER OPENING_PARENTHESIS $@4 function_arguments CLOSING_PARENTHESIS $@5 body  */
#line 278 "parser.y"
         {
        Value val;
        val.function = (yyvsp[0].instruction);
        ValueType return_type = string_to_value_type("void");
        insert_symbol(symbol_table, (yyvsp[-6].sval), "void", val, FUNCTION, scope_no, 1, 0, 0, (yyvsp[-3].param_list), yylineno, 0, get_prev_enclosing_function());
        inside_a_function_declaration_body = 0;
        curr_function_parameter_list = NULL;
        curr_function_parameter_list_ptr = NULL;
        curr_function_instructions_list = NULL;
        char* popped = pop_function();
        if (popped) free(popped);
        scope_no--;
    }
#line 1622 "parser.tab.c"
    break;

  case 12: /* $@6: %empty  */
#line 291 "parser.y"
                                                              {
        scope_no++;
        inside_a_function_declaration_body = 1;
        curr_function_instructions_list = NULL;
        push_function((yyvsp[-2].sval));
    }
#line 1633 "parser.tab.c"
    break;

  case 13: /* function: type IDENTIFIER OPENING_PARENTHESIS CLOSING_PARENTHESIS $@6 body  */
#line 297 "parser.y"
         {
        Value val;
        val.function = (yyvsp[0].instruction);
        ValueType return_type = string_to_value_type((yyvsp[-5].sval));
        size_t array_size = 0;
        if ((yyvsp[-5].sval)[0] == 'a') {
            return_type = keyword_to_array_value_type((yyvsp[-5].sval) + 1);
            char* size_str = strchr((yyvsp[-5].sval), '[') + 1;
            array_size = atoi(size_str);
        }
        insert_symbol(symbol_table, (yyvsp[-4].sval), (yyvsp[-5].sval), val, FUNCTION, scope_no, 1, 0, array_size > 0, NULL, yylineno, array_size, get_prev_enclosing_function());
        inside_a_function_declaration_body = 0;
        curr_function_instructions_list = NULL;
        char* popped = pop_function();
        if (popped) free(popped);
        scope_no--;
        free((yyvsp[-5].sval));
    }
#line 1656 "parser.tab.c"
    break;

  case 14: /* $@7: %empty  */
#line 315 "parser.y"
                                                                           {
        scope_no++;
        inside_a_function_declaration_body = 1;
        curr_function_instructions_list = NULL;
        push_function((yyvsp[-2].sval));
    }
#line 1667 "parser.tab.c"
    break;

  case 15: /* function: VOID_TYPE_KEYWORD IDENTIFIER OPENING_PARENTHESIS CLOSING_PARENTHESIS $@7 body  */
#line 321 "parser.y"
         {
        Value val;
        val.function = (yyvsp[0].instruction);
        ValueType return_type = string_to_value_type("void");
        insert_symbol(symbol_table, (yyvsp[-4].sval), "void", val, FUNCTION, scope_no, 1, 0, 0, NULL, yylineno, 0, get_prev_enclosing_function());
        inside_a_function_declaration_body = 0;
        curr_function_instructions_list = NULL;
        char* popped = pop_function();
        if (popped) free(popped);
        scope_no--;
    }
#line 1683 "parser.tab.c"
    break;

  case 16: /* function_arguments: type_identifier  */
#line 335 "parser.y"
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
        ValueType param_type = string_to_value_type((yyvsp[0].type_id).type);
        size_t param_size = (yyvsp[0].type_id).array_size;
        if ((yyvsp[0].type_id).array_size > 0) {
            param_type = keyword_to_array_value_type((yyvsp[0].type_id).type);
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
#line 1717 "parser.tab.c"
    break;

  case 17: /* function_arguments: function_arguments COMMA type_identifier  */
#line 364 "parser.y"
                                               {
        curr_function_parameter_list_ptr->next = create_parameter((yyvsp[0].type_id).name, (yyvsp[0].type_id).type);
        curr_function_parameter_list_ptr = curr_function_parameter_list_ptr->next;
        Value val;
        memset(&val, 0, sizeof(Value));
        ValueType param_type = string_to_value_type((yyvsp[0].type_id).type);
        size_t param_size = (yyvsp[0].type_id).array_size;
        curr_function_parameter_list_ptr->array_length = (yyvsp[0].type_id).array_size;
        if ((yyvsp[0].type_id).array_size > 0) {
            param_type = keyword_to_array_value_type((yyvsp[0].type_id).type);
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
#line 1746 "parser.tab.c"
    break;

  case 18: /* type_identifier: type IDENTIFIER  */
#line 391 "parser.y"
                    {
        (yyval.type_id).type = (yyvsp[-1].sval);
        (yyval.type_id).name = (yyvsp[0].sval);
        (yyval.type_id).array_size = 0; // Default for scalar types
    }
#line 1756 "parser.tab.c"
    break;

  case 19: /* type_identifier: type OPENING_SQUARE_BRACKETS INTEGER_LITERAL CLOSING_SQUARE_BRACKETS IDENTIFIER  */
#line 396 "parser.y"
                                                                                      {
        (yyval.type_id).type = concat_strings("a", (yyvsp[-4].sval));
        (yyval.type_id).name = (yyvsp[0].sval);
        (yyval.type_id).array_size = (yyvsp[-2].ival);
    }
#line 1766 "parser.tab.c"
    break;

  case 20: /* type: INT_TYPE_KEYWORD  */
#line 404 "parser.y"
                       { (yyval.sval) = strdup("int"); }
#line 1772 "parser.tab.c"
    break;

  case 21: /* type: FLOAT_TYPE_KEYWORD  */
#line 405 "parser.y"
                           { (yyval.sval) = strdup("float"); }
#line 1778 "parser.tab.c"
    break;

  case 22: /* type: STRING_TYPE_KEYWORD  */
#line 406 "parser.y"
                            { (yyval.sval) = strdup("string"); }
#line 1784 "parser.tab.c"
    break;

  case 23: /* type: CHAR_TYPE_KEYWORD  */
#line 407 "parser.y"
                          { (yyval.sval) = strdup("char"); }
#line 1790 "parser.tab.c"
    break;

  case 24: /* type: BOOL_TYPE_KEYWORD  */
#line 408 "parser.y"
                          { (yyval.sval) = strdup("bool"); }
#line 1796 "parser.tab.c"
    break;

  case 25: /* $@8: %empty  */
#line 413 "parser.y"
     { 
        scope_no++;
    }
#line 1804 "parser.tab.c"
    break;

  case 26: /* body: $@8 OPENING_CURLY_BRACE statements CLOSING_CURLY_BRACE  */
#line 418 "parser.y"
                        { 
        if(!inside_a_function_declaration_body) {
            delete_scope(symbol_table, scope_no); 
        }
        scope_no--;
        (yyval.instruction) = (yyvsp[-1].instruction); 
    }
#line 1816 "parser.tab.c"
    break;

  case 27: /* statements: statement statements  */
#line 429 "parser.y"
               {(yyval.instruction) = NULL;}
#line 1822 "parser.tab.c"
    break;

  case 28: /* statements: %empty  */
#line 430 "parser.y"
                  {(yyval.instruction) = NULL;}
#line 1828 "parser.tab.c"
    break;

  case 29: /* statement: body SEMICOLON  */
#line 433 "parser.y"
                          {(yyval.instruction) = NULL;}
#line 1834 "parser.tab.c"
    break;

  case 30: /* statement: assignment  */
#line 434 "parser.y"
                      {(yyval.instruction) = NULL;}
#line 1840 "parser.tab.c"
    break;

  case 31: /* statement: array_assignment  */
#line 435 "parser.y"
                            {(yyval.instruction) = NULL;}
#line 1846 "parser.tab.c"
    break;

  case 32: /* statement: return_statement  */
#line 436 "parser.y"
                            {(yyval.instruction) = NULL;}
#line 1852 "parser.tab.c"
    break;

  case 33: /* statement: expression SEMICOLON  */
#line 437 "parser.y"
                                {(yyval.instruction) = NULL;}
#line 1858 "parser.tab.c"
    break;

  case 34: /* statement: initialization  */
#line 438 "parser.y"
                          {(yyval.instruction) = NULL;}
#line 1864 "parser.tab.c"
    break;

  case 35: /* statement: variable_declaration  */
#line 439 "parser.y"
                                {(yyval.instruction) = NULL;}
#line 1870 "parser.tab.c"
    break;

  case 36: /* statement: const_initialization  */
#line 440 "parser.y"
                                {(yyval.instruction) = NULL;}
#line 1876 "parser.tab.c"
    break;

  case 37: /* statement: if_statement  */
#line 441 "parser.y"
                        {(yyval.instruction) = NULL;}
#line 1882 "parser.tab.c"
    break;

  case 38: /* statement: for_statement  */
#line 442 "parser.y"
                         {(yyval.instruction) = NULL;}
#line 1888 "parser.tab.c"
    break;

  case 39: /* statement: while_statement  */
#line 443 "parser.y"
                           {(yyval.instruction) = NULL;}
#line 1894 "parser.tab.c"
    break;

  case 40: /* statement: do_while_statement  */
#line 444 "parser.y"
                              {(yyval.instruction) = NULL;}
#line 1900 "parser.tab.c"
    break;

  case 41: /* statement: switch_statement  */
#line 445 "parser.y"
                            {(yyval.instruction) = NULL;}
#line 1906 "parser.tab.c"
    break;

  case 42: /* statement: function  */
#line 446 "parser.y"
                    {(yyval.instruction) = NULL;}
#line 1912 "parser.tab.c"
    break;

  case 52: /* loop_update: IDENTIFIER ASSIGNMENT expression  */
#line 469 "parser.y"
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
#line 1940 "parser.tab.c"
    break;

  case 53: /* loop_update: IDENTIFIER INCREMENT  */
#line 492 "parser.y"
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
#line 1973 "parser.tab.c"
    break;

  case 54: /* loop_update: IDENTIFIER DECREMENT  */
#line 520 "parser.y"
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
#line 2006 "parser.tab.c"
    break;

  case 59: /* $@9: %empty  */
#line 559 "parser.y"
                                                  {
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
#line 2024 "parser.tab.c"
    break;

  case 60: /* $@10: %empty  */
#line 572 "parser.y"
                                            {scope_no++;}
#line 2030 "parser.tab.c"
    break;

  case 61: /* switch_statement: SWITCH_KEYWORD OPENING_PARENTHESIS IDENTIFIER $@9 CLOSING_PARENTHESIS OPENING_CURLY_BRACE $@10 case_list default_case CLOSING_CURLY_BRACE  */
#line 573 "parser.y"
                                               { delete_scope(symbol_table, scope_no); scope_no--;}
#line 2036 "parser.tab.c"
    break;

  case 66: /* $@11: %empty  */
#line 588 "parser.y"
                                          {
        SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[-2].type_id).name, scope_no, get_current_enclosing_function());
        if (result && (!result->enclosing_function_name || 
                       (get_current_enclosing_function() && 
                        strcmp(result->enclosing_function_name, get_current_enclosing_function()) == 0))) {
            fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", (yyvsp[-2].type_id).name, yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        ValueType declared_type = string_to_value_type((yyvsp[-2].type_id).type);
        size_t declared_size = (yyvsp[-2].type_id).array_size;
        if ((yyvsp[-2].type_id).array_size > 0) {
            declared_type = keyword_to_array_value_type((yyvsp[-2].type_id).type);
        }
        if (declared_type != (yyvsp[0].expr).expr_return_type || 
            (declared_type >= INT_ARRAY_VALUE && declared_size != (yyvsp[0].expr).array_length)) {
            fprintf(stderr, "Type or size mismatch in initialization at line %d\n", yylineno);
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
            case INT_ARRAY_VALUE:
                val.int_array = (int*)calloc(declared_size, sizeof(int));
                for (size_t i = 0; i < declared_size; i++) {
                    val.int_array[i] = (yyvsp[0].expr).expr_value.int_array[i];
                }
                break;
            case FLOAT_ARRAY_VALUE:
                val.float_array = (double*)calloc(declared_size, sizeof(double));
                for (size_t i = 0; i < declared_size; i++) {
                    val.float_array[i] = (yyvsp[0].expr).expr_value.float_array[i];
                }
                break;
            case CHAR_ARRAY_VALUE:
                val.char_array = (char*)calloc(declared_size, sizeof(char));
                for (size_t i = 0; i < declared_size; i++) {
                    val.char_array[i] = (yyvsp[0].expr).expr_value.char_array[i];
                }
                break;
            case STRING_ARRAY_VALUE:
                val.string_array = (char**)malloc(declared_size * sizeof(char*));
                for (size_t i = 0; i < declared_size; i++) {
                    val.string_array[i] = strdup((yyvsp[0].expr).expr_value.string_array[i]);
                }
                break;
        }
        insert_symbol(symbol_table, (yyvsp[-2].type_id).name, (yyvsp[-2].type_id).type, val, declared_type, scope_no, 0, 0, declared_size > 0, NULL, yylineno, declared_size, get_current_enclosing_function());
        free((yyvsp[-2].type_id).name);
        free((yyvsp[-2].type_id).type);
    }
#line 2105 "parser.tab.c"
    break;

  case 68: /* $@12: %empty  */
#line 653 "parser.y"
                                                                                                                                                           {
        SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[-7].type_id).name, scope_no, get_current_enclosing_function());
        if (result && (!result->enclosing_function_name || 
                       (get_current_enclosing_function() && 
                        strcmp(result->enclosing_function_name, get_current_enclosing_function()) == 0))) {
            fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", (yyvsp[-7].type_id).name, yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        ValueType declared_type = string_to_value_type((yyvsp[-7].type_id).type);
        ValueType element_type = declared_type;
        size_t declared_size = (yyvsp[-5].ival);
        if ((yyvsp[-7].type_id).type[0] == 'a') {
            declared_type = keyword_to_array_value_type((yyvsp[-7].type_id).type + 1);
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
            fprintf(stderr, "Too many initializers for array '%s' at line %d\n", (yyvsp[-7].type_id).name, yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        Value val;
        switch (declared_type) {
            case INT_ARRAY_VALUE:
                val.int_array = (int*)calloc(declared_size, sizeof(int));
                current = &(yyvsp[-1].expr_lst);
                for (size_t i = 0; i < provided_size && current && current->e; i++) {
                    val.int_array[i] = current->e->expr_value.int_value;
                    current = current->next_expr;
                }
                break;
            case FLOAT_ARRAY_VALUE:
                val.float_array = (double*)calloc(declared_size, sizeof(double));
                current = &(yyvsp[-1].expr_lst);
                for (size_t i = 0; i < provided_size && current && current->e; i++) {
                    val.float_array[i] = current->e->expr_value.float_value;
                    current = current->next_expr;
                }
                break;
            case CHAR_ARRAY_VALUE:
                val.char_array = (char*)calloc(declared_size, sizeof(char));
                current = &(yyvsp[-1].expr_lst);
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
                current = &(yyvsp[-1].expr_lst);
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
        insert_symbol(symbol_table, (yyvsp[-7].type_id).name, (yyvsp[-7].type_id).type, val, declared_type, scope_no, 0, 0, 1, NULL, yylineno, declared_size, get_current_enclosing_function());
        free((yyvsp[-7].type_id).name);
        free((yyvsp[-7].type_id).type);
    }
#line 2188 "parser.tab.c"
    break;

  case 70: /* $@13: %empty  */
#line 735 "parser.y"
                                  {
        SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[0].type_id).name, scope_no, get_current_enclosing_function());
        if (result && (!result->enclosing_function_name || 
                       (get_current_enclosing_function() && 
                        strcmp(result->enclosing_function_name, get_current_enclosing_function()) == 0))) {
            fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", (yyvsp[0].type_id).name, yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
    }
#line 2203 "parser.tab.c"
    break;

  case 71: /* const_initialization: CONST_KEYWORD type_identifier $@13 ASSIGNMENT expression SEMICOLON  */
#line 745 "parser.y"
                                    {
        ValueType declared_type = string_to_value_type((yyvsp[-4].type_id).type);
        size_t declared_size = (yyvsp[-4].type_id).array_size;
        if ((yyvsp[-4].type_id).array_size > 0) {
            declared_type = keyword_to_array_value_type((yyvsp[-4].type_id).type);
        }
        if (declared_type != (yyvsp[-1].expr).expr_return_type || 
            (declared_type >= INT_ARRAY_VALUE && declared_size != (yyvsp[-1].expr).array_length)) {
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
            case INT_ARRAY_VALUE:
                val.int_array = (int*)calloc(declared_size, sizeof(int));
                for (size_t i = 0; i < declared_size; i++) {
                    val.int_array[i] = (yyvsp[-1].expr).expr_value.int_array[i];
                }
                break;
            case FLOAT_ARRAY_VALUE:
                val.float_array = (double*)calloc(declared_size, sizeof(double));
                for (size_t i = 0; i < declared_size; i++) {
                    val.float_array[i] = (yyvsp[-1].expr).expr_value.float_array[i];
                }
                break;
            case CHAR_ARRAY_VALUE:
                val.char_array = (char*)calloc(declared_size, sizeof(char));
                for (size_t i = 0; i < declared_size; i++) {
                    val.char_array[i] = (yyvsp[-1].expr).expr_value.char_array[i];
                }
                break;
            case STRING_ARRAY_VALUE:
                val.string_array = (char**)malloc(declared_size * sizeof(char*));
                for (size_t i = 0; i < declared_size; i++) {
                    val.string_array[i] = strdup((yyvsp[-1].expr).expr_value.string_array[i]);
                }
                break;
            default:
                fprintf(stderr, "Unsupported type in constant initialization at line %d\n", yylineno);
                free_symbol_table(symbol_table);
                exit(1);
        }
        insert_symbol(symbol_table, (yyvsp[-4].type_id).name, (yyvsp[-4].type_id).type, val, declared_type, scope_no, 0, 1, declared_size > 0, NULL, yylineno, declared_size, get_current_enclosing_function());
        free((yyvsp[-4].type_id).name);
        free((yyvsp[-4].type_id).type);
    }
#line 2268 "parser.tab.c"
    break;

  case 72: /* $@14: %empty  */
#line 805 "parser.y"
                                    {
        SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[0].type_id).name, scope_no, get_current_enclosing_function());
        if (result && (!result->enclosing_function_name || 
                       (get_current_enclosing_function() && 
                        strcmp(result->enclosing_function_name, get_current_enclosing_function()) == 0))) {
            fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", (yyvsp[0].type_id).name, yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
    }
#line 2283 "parser.tab.c"
    break;

  case 73: /* const_initialization: CONST_KEYWORD type_identifier $@14 OPENING_SQUARE_BRACKETS INTEGER_LITERAL CLOSING_SQUARE_BRACKETS ASSIGNMENT OPENING_SQUARE_BRACKETS expr_list CLOSING_SQUARE_BRACKETS SEMICOLON  */
#line 815 "parser.y"
                                                                                                                                                   {
        ValueType declared_type = string_to_value_type((yyvsp[-9].type_id).type);
        ValueType element_type = declared_type;
        size_t declared_size = (yyvsp[-6].ival);
        if ((yyvsp[-9].type_id).array_size > 0) {
            declared_type = keyword_to_array_value_type((yyvsp[-9].type_id).type);
        }
        size_t provided_size = 0;
        ExprList* current = &((yyvsp[-2].expr_lst));
        while (current && current->e) {
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
        switch (declared_type) {
            case INT_ARRAY_VALUE:
                val.int_array = (int*)calloc(declared_size, sizeof(int));
                current = &(yyvsp[-2].expr_lst);
                for (size_t i = 0; i < provided_size && current && current->e; i++) {
                    val.int_array[i] = current->e->expr_value.int_value;
                    current = current->next_expr;
                }
                break;
            case FLOAT_ARRAY_VALUE:
                val.float_array = (double*)calloc(declared_size, sizeof(double));
                current = &(yyvsp[-2].expr_lst);
                for (size_t i = 0; i < provided_size && current && current->e; i++) {
                    val.float_array[i] = current->e->expr_value.float_value;
                    current = current->next_expr;
                }
                break;
            case CHAR_ARRAY_VALUE:
                val.char_array = (char*)calloc(declared_size, sizeof(char));
                current = &(yyvsp[-2].expr_lst);
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
                current = &(yyvsp[-2].expr_lst);
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
        insert_symbol(symbol_table, (yyvsp[-9].type_id).name, (yyvsp[-9].type_id).type, val, declared_type, scope_no, 0, 1, declared_size > 0, NULL, yylineno, declared_size, get_current_enclosing_function());
        free((yyvsp[-9].type_id).name);
        free((yyvsp[-9].type_id).type);
    }
#line 2358 "parser.tab.c"
    break;

  case 74: /* $@15: %empty  */
#line 888 "parser.y"
                    {
        SymbolTableEntry* result = search_symbol_table(symbol_table, (yyvsp[0].type_id).name, scope_no, get_current_enclosing_function());
        if (result && (!result->enclosing_function_name || 
                       (get_current_enclosing_function() && 
                        strcmp(result->enclosing_function_name, get_current_enclosing_function()) == 0))) {
            fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", (yyvsp[0].type_id).name, yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        ValueType declared_type = string_to_value_type((yyvsp[0].type_id).type);
        size_t declared_size = (yyvsp[0].type_id).array_size;
        if ((yyvsp[0].type_id).array_size > 0) {
            declared_type = keyword_to_array_value_type((yyvsp[0].type_id).type);
        }
        if (declared_size > 0 && declared_size <= 0) {
            fprintf(stderr, "Array size must be positive at line %d\n", yylineno);
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
#line 2417 "parser.tab.c"
    break;

  case 76: /* return_statement: RETURN_KEYWORD expression SEMICOLON  */
#line 946 "parser.y"
                                        {
        if (!get_current_enclosing_function()) {
            fprintf(stderr, "Return statement outside function at line %d\n", yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        SymbolTableEntry* func = search_symbol_table(symbol_table, get_current_enclosing_function(), scope_no, get_current_enclosing_function());
        if (!func) {
            fprintf(stderr, "Function '%s' not found at line %d\n", get_current_enclosing_function(), yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
        ValueType return_type = string_to_value_type(func->type);
        size_t return_size = 0;
        if (func->type[0] == 'a') {
            return_type = keyword_to_array_value_type(func->type + 1);
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
#line 2448 "parser.tab.c"
    break;

  case 77: /* $@16: %empty  */
#line 975 "parser.y"
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
#line 2497 "parser.tab.c"
    break;

  case 79: /* $@17: %empty  */
#line 1023 "parser.y"
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
#line 2599 "parser.tab.c"
    break;

  case 81: /* expression: boolean_expr  */
#line 1125 "parser.y"
                 {
        (yyval.expr).expr_type = BOOL_EXPR;
        (yyval.expr).expr_value.int_value = (yyvsp[0].expr).expr_value.int_value;
        (yyval.expr).expr_return_type = BOOL_VALUE;
        (yyval.expr).associated_identifier = NULL;
    }
#line 2610 "parser.tab.c"
    break;

  case 82: /* expression: arithmetic_expr  */
#line 1131 "parser.y"
                      { (yyval.expr) = (yyvsp[0].expr); }
#line 2616 "parser.tab.c"
    break;

  case 83: /* expression: function_call  */
#line 1132 "parser.y"
                    { (yyval.expr) = (yyvsp[0].expr); }
#line 2622 "parser.tab.c"
    break;

  case 84: /* expression: STRING_LITERAL  */
#line 1133 "parser.y"
                     {
        (yyval.expr).expr_type = STRING_EXPR;
        (yyval.expr).expr_value.char_array = strdup((yyvsp[0].sval));
        (yyval.expr).expr_return_type = STRING_VALUE;
        (yyval.expr).associated_identifier = NULL;
    }
#line 2633 "parser.tab.c"
    break;

  case 85: /* expression: CHARACTER_LITERAL  */
#line 1139 "parser.y"
                        {
        (yyval.expr).expr_type = CHAR_EXPR;
        (yyval.expr).expr_value.char_value = (yyvsp[0].cval);
        (yyval.expr).expr_return_type = CHAR_VALUE;
        (yyval.expr).associated_identifier = NULL;
    }
#line 2644 "parser.tab.c"
    break;

  case 86: /* expression: array_element  */
#line 1145 "parser.y"
                    { (yyval.expr) = (yyvsp[0].expr); }
#line 2650 "parser.tab.c"
    break;

  case 87: /* expression: IDENTIFIER  */
#line 1146 "parser.y"
                 {
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
#line 2697 "parser.tab.c"
    break;

  case 88: /* array_element: IDENTIFIER OPENING_SQUARE_BRACKETS INTEGER_LITERAL CLOSING_SQUARE_BRACKETS  */
#line 1191 "parser.y"
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
#line 2745 "parser.tab.c"
    break;

  case 89: /* expr_list: expression  */
#line 1237 "parser.y"
               {
        (yyval.expr_lst).e = &(yyvsp[0].expr);
        (yyval.expr_lst).next_expr = NULL;
    }
#line 2754 "parser.tab.c"
    break;

  case 90: /* expr_list: expr_list COMMA expression  */
#line 1241 "parser.y"
                                 {
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
#line 2770 "parser.tab.c"
    break;

  case 91: /* function_call: IDENTIFIER OPENING_PARENTHESIS expr_list CLOSING_PARENTHESIS  */
#line 1255 "parser.y"
                                                                 {
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
            ValueType param_type = string_to_value_type(param->type);
            size_t param_size = param->array_length;
            if (param_size > 0) {
                param_type = keyword_to_array_value_type(param->type);
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
        (yyval.expr).expr_return_type = string_to_value_type(result->type);
        (yyval.expr).array_length = result->array_length;
        if (result->type[0] == 'a') {
            (yyval.expr).expr_return_type = keyword_to_array_value_type(result->type + 1);
            char* size_str = strchr(result->type, '[') + 1;
            (yyval.expr).array_length = atoi(size_str);
        }
        scope_no = prev_scope_no;
    }
#line 2822 "parser.tab.c"
    break;

  case 92: /* function_call: IDENTIFIER OPENING_PARENTHESIS CLOSING_PARENTHESIS  */
#line 1302 "parser.y"
                                                         {
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
        (yyval.expr).expr_return_type = string_to_value_type(result->type);
        (yyval.expr).array_length = result->array_length;
        if (result->type[0] == 'a') {
            (yyval.expr).expr_return_type = keyword_to_array_value_type(result->type + 1);
            char* size_str = strchr(result->type, '[') + 1;
            (yyval.expr).array_length = atoi(size_str);
        }
        scope_no = prev_scope_no;
    }
#line 2857 "parser.tab.c"
    break;

  case 93: /* boolean_expr: expression EQUAL arithmetic_expr  */
#line 1335 "parser.y"
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
#line 2883 "parser.tab.c"
    break;

  case 94: /* boolean_expr: expression EQUAL function_call  */
#line 1356 "parser.y"
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
#line 2909 "parser.tab.c"
    break;

  case 95: /* boolean_expr: expression NOT_EQUAL arithmetic_expr  */
#line 1377 "parser.y"
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
#line 2935 "parser.tab.c"
    break;

  case 96: /* boolean_expr: expression NOT_EQUAL function_call  */
#line 1398 "parser.y"
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
#line 2961 "parser.tab.c"
    break;

  case 97: /* boolean_expr: expression GREATER_OR_EQUAL arithmetic_expr  */
#line 1419 "parser.y"
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
        float left = ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[-2].expr).expr_value.float_value : (yyvsp[-2].expr).expr_value.int_value;
        float right = ((yyvsp[0].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[0].expr).expr_value.float_value : (yyvsp[0].expr).expr_value.int_value;
        (yyval.expr).expr_value.int_value = (left >= right);
    }
#line 2980 "parser.tab.c"
    break;

  case 98: /* boolean_expr: expression GREATER_OR_EQUAL function_call  */
#line 1433 "parser.y"
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
        float left = ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[-2].expr).expr_value.float_value : (yyvsp[-2].expr).expr_value.int_value;
        float right = ((yyvsp[0].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[0].expr).expr_value.float_value : (yyvsp[0].expr).expr_value.int_value;
        (yyval.expr).expr_value.int_value = (left >= right);
    }
#line 2999 "parser.tab.c"
    break;

  case 99: /* boolean_expr: expression LESS_OR_EQUAL arithmetic_expr  */
#line 1447 "parser.y"
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
        float left = ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[-2].expr).expr_value.float_value : (yyvsp[-2].expr).expr_value.int_value;
        float right = ((yyvsp[0].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[0].expr).expr_value.float_value : (yyvsp[0].expr).expr_value.int_value;
        (yyval.expr).expr_value.int_value = (left <= right);
    }
#line 3018 "parser.tab.c"
    break;

  case 100: /* boolean_expr: expression LESS_OR_EQUAL function_call  */
#line 1461 "parser.y"
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
        float left = ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[-2].expr).expr_value.float_value : (yyvsp[-2].expr).expr_value.int_value;
        float right = ((yyvsp[0].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[0].expr).expr_value.float_value : (yyvsp[0].expr).expr_value.int_value;
        (yyval.expr).expr_value.int_value = (left <= right);
    }
#line 3037 "parser.tab.c"
    break;

  case 101: /* boolean_expr: expression GREATER arithmetic_expr  */
#line 1475 "parser.y"
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
        float left = ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[-2].expr).expr_value.float_value : (yyvsp[-2].expr).expr_value.int_value;
        float right = ((yyvsp[0].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[0].expr).expr_value.float_value : (yyvsp[0].expr).expr_value.int_value;
        (yyval.expr).expr_value.int_value = (left > right);
    }
#line 3056 "parser.tab.c"
    break;

  case 102: /* boolean_expr: expression GREATER function_call  */
#line 1489 "parser.y"
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
        float left = ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[-2].expr).expr_value.float_value : (yyvsp[-2].expr).expr_value.int_value;
        float right = ((yyvsp[0].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[0].expr).expr_value.float_value : (yyvsp[0].expr).expr_value.int_value;
        (yyval.expr).expr_value.int_value = (left > right);
    }
#line 3075 "parser.tab.c"
    break;

  case 103: /* boolean_expr: expression LESS arithmetic_expr  */
#line 1503 "parser.y"
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
        float left = ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[-2].expr).expr_value.float_value : (yyvsp[-2].expr).expr_value.int_value;
        float right = ((yyvsp[0].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[0].expr).expr_value.float_value : (yyvsp[0].expr).expr_value.int_value;
        (yyval.expr).expr_value.int_value = (left < right);
    }
#line 3094 "parser.tab.c"
    break;

  case 104: /* boolean_expr: expression LESS function_call  */
#line 1517 "parser.y"
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
        float left = ((yyvsp[-2].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[-2].expr).expr_value.float_value : (yyvsp[-2].expr).expr_value.int_value;
        float right = ((yyvsp[0].expr).expr_return_type == FLOAT_VALUE) ? (yyvsp[0].expr).expr_value.float_value : (yyvsp[0].expr).expr_value.int_value;
        (yyval.expr).expr_value.int_value = (left < right);
    }
#line 3113 "parser.tab.c"
    break;

  case 105: /* arithmetic_expr: binary_expr  */
#line 1533 "parser.y"
                              { (yyval.expr) = (yyvsp[0].expr); }
#line 3119 "parser.tab.c"
    break;

  case 106: /* arithmetic_expr: unary_expr  */
#line 1534 "parser.y"
                             { (yyval.expr) = (yyvsp[0].expr); }
#line 3125 "parser.tab.c"
    break;

  case 107: /* binary_expr: binary_expr PLUS arithmetic_term  */
#line 1537 "parser.y"
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
#line 3149 "parser.tab.c"
    break;

  case 108: /* binary_expr: binary_expr MINUS arithmetic_term  */
#line 1556 "parser.y"
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
#line 3173 "parser.tab.c"
    break;

  case 109: /* binary_expr: arithmetic_term  */
#line 1575 "parser.y"
                              { (yyval.expr) = (yyvsp[0].expr); }
#line 3179 "parser.tab.c"
    break;

  case 110: /* arithmetic_term: arithmetic_term ASTRISK arithmetic_factor  */
#line 1578 "parser.y"
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
#line 3203 "parser.tab.c"
    break;

  case 111: /* arithmetic_term: arithmetic_term DIVIDE arithmetic_factor  */
#line 1597 "parser.y"
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
#line 3233 "parser.tab.c"
    break;

  case 112: /* arithmetic_term: arithmetic_term MODULO INTEGER_LITERAL  */
#line 1622 "parser.y"
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
#line 3254 "parser.tab.c"
    break;

  case 113: /* arithmetic_term: arithmetic_term MODULO OPENING_PARENTHESIS expression CLOSING_PARENTHESIS  */
#line 1638 "parser.y"
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
#line 3275 "parser.tab.c"
    break;

  case 114: /* arithmetic_term: arithmetic_factor  */
#line 1654 "parser.y"
                                    { (yyval.expr) = (yyvsp[0].expr); }
#line 3281 "parser.tab.c"
    break;

  case 115: /* arithmetic_factor: bitwise_expr  */
#line 1657 "parser.y"
                                 { (yyval.expr) = (yyvsp[0].expr); }
#line 3287 "parser.tab.c"
    break;

  case 116: /* arithmetic_factor: FLOAT_LITERAL  */
#line 1658 "parser.y"
                                  {
                      (yyval.expr).expr_type = FLOAT_EXPR;
                      (yyval.expr).expr_value.float_value = (yyvsp[0].fval);
                      (yyval.expr).expr_return_type = FLOAT_VALUE;
                      (yyval.expr).associated_identifier = NULL;
                  }
#line 3298 "parser.tab.c"
    break;

  case 117: /* arithmetic_factor: OPENING_PARENTHESIS expression CLOSING_PARENTHESIS  */
#line 1664 "parser.y"
                                                                       { (yyval.expr) = (yyvsp[-1].expr); }
#line 3304 "parser.tab.c"
    break;

  case 118: /* bitwise_expr: bitwise_expr BITWISE_OR bitwise_xor_expr  */
#line 1667 "parser.y"
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
#line 3320 "parser.tab.c"
    break;

  case 119: /* bitwise_expr: bitwise_xor_expr  */
#line 1678 "parser.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 3326 "parser.tab.c"
    break;

  case 120: /* bitwise_xor_expr: bitwise_xor_expr BITWISE_XOR bitwise_and_expr  */
#line 1681 "parser.y"
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
#line 3342 "parser.tab.c"
    break;

  case 121: /* bitwise_xor_expr: bitwise_and_expr  */
#line 1692 "parser.y"
                                    { (yyval.expr) = (yyvsp[0].expr); }
#line 3348 "parser.tab.c"
    break;

  case 122: /* bitwise_and_expr: bitwise_and_expr BITWISE_AND bitwise_not_expr  */
#line 1695 "parser.y"
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
#line 3364 "parser.tab.c"
    break;

  case 123: /* bitwise_and_expr: bitwise_not_expr  */
#line 1706 "parser.y"
                                    { (yyval.expr) = (yyvsp[0].expr); }
#line 3370 "parser.tab.c"
    break;

  case 124: /* bitwise_not_expr: BITWISE_NOT bitwise_not_expr  */
#line 1709 "parser.y"
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
#line 3386 "parser.tab.c"
    break;

  case 125: /* bitwise_not_expr: INTEGER_LITERAL  */
#line 1720 "parser.y"
                                   {
                     (yyval.expr).expr_type = INT_EXPR;
                     (yyval.expr).expr_return_type = INT_VALUE;
                     (yyval.expr).expr_value.int_value = (yyvsp[0].ival);
                     (yyval.expr).associated_identifier = NULL;
                 }
#line 3397 "parser.tab.c"
    break;

  case 126: /* unary_expr: IDENTIFIER INCREMENT  */
#line 1729 "parser.y"
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
#line 3429 "parser.tab.c"
    break;

  case 127: /* unary_expr: IDENTIFIER DECREMENT  */
#line 1756 "parser.y"
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
#line 3461 "parser.tab.c"
    break;

  case 128: /* unary_expr: MINUS IDENTIFIER  */
#line 1783 "parser.y"
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
#line 3488 "parser.tab.c"
    break;

  case 129: /* unary_expr: MINUS OPENING_PARENTHESIS expression CLOSING_PARENTHESIS  */
#line 1805 "parser.y"
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
#line 3509 "parser.tab.c"
    break;

  case 130: /* unary_expr: OPENING_PARENTHESIS expression CLOSING_PARENTHESIS INCREMENT  */
#line 1821 "parser.y"
                                                                   {
        fprintf(stderr, "Increment on expression not supported at line %d\n", yylineno);
        free_symbol_table(symbol_table);
        exit(1);
    }
#line 3519 "parser.tab.c"
    break;

  case 131: /* unary_expr: OPENING_PARENTHESIS expression CLOSING_PARENTHESIS DECREMENT  */
#line 1826 "parser.y"
                                                                   {
        fprintf(stderr, "Decrement on expression not supported at line %d\n", yylineno);
        free_symbol_table(symbol_table);
        exit(1);
    }
#line 3529 "parser.tab.c"
    break;

  case 132: /* $@18: %empty  */
#line 1835 "parser.y"
                                                         { 
        scope_no++;
        push_function("main");
    }
#line 3538 "parser.tab.c"
    break;

  case 133: /* main_function: MAIN_KEYWORD OPENING_PARENTHESIS CLOSING_PARENTHESIS $@18 body  */
#line 1839 "parser.y"
         {
        char* popped = pop_function();
        if (popped) free(popped);
        scope_no--;
    }
#line 3548 "parser.tab.c"
    break;


#line 3552 "parser.tab.c"

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

#line 1845 "parser.y"



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
