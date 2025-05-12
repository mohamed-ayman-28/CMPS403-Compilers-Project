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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    INTEGER_LITERAL = 258,         /* INTEGER_LITERAL  */
    FLOAT_LITERAL = 259,           /* FLOAT_LITERAL  */
    CHARACTER_LITERAL = 260,       /* CHARACTER_LITERAL  */
    STRING_LITERAL = 261,          /* STRING_LITERAL  */
    BOOLEAN_LITERAL = 262,         /* BOOLEAN_LITERAL  */
    IDENTIFIER = 263,              /* IDENTIFIER  */
    INT_TYPE_KEYWORD = 264,        /* INT_TYPE_KEYWORD  */
    FLOAT_TYPE_KEYWORD = 265,      /* FLOAT_TYPE_KEYWORD  */
    STRING_TYPE_KEYWORD = 266,     /* STRING_TYPE_KEYWORD  */
    CHAR_TYPE_KEYWORD = 267,       /* CHAR_TYPE_KEYWORD  */
    BOOL_TYPE_KEYWORD = 268,       /* BOOL_TYPE_KEYWORD  */
    VOID_TYPE_KEYWORD = 269,       /* VOID_TYPE_KEYWORD  */
    IF_KEYWORD = 270,              /* IF_KEYWORD  */
    ELSEIF_KEYWORD = 271,          /* ELSEIF_KEYWORD  */
    ELSE_KEYWORD = 272,            /* ELSE_KEYWORD  */
    FOR_KEYWORD = 273,             /* FOR_KEYWORD  */
    WHILE_KEYWORD = 274,           /* WHILE_KEYWORD  */
    SWITCH_KEYWORD = 275,          /* SWITCH_KEYWORD  */
    MAIN_KEYWORD = 276,            /* MAIN_KEYWORD  */
    DO_KEYWORD = 277,              /* DO_KEYWORD  */
    RETURN_KEYWORD = 278,          /* RETURN_KEYWORD  */
    CASE_KEYWORD = 279,            /* CASE_KEYWORD  */
    CONST_KEYWORD = 280,           /* CONST_KEYWORD  */
    BREAK_KEYWORD = 281,           /* BREAK_KEYWORD  */
    CONTINUE_KEYWORD = 282,        /* CONTINUE_KEYWORD  */
    DEFAULT_KEYWORD = 283,         /* DEFAULT_KEYWORD  */
    AND_KEYWORD = 284,             /* AND_KEYWORD  */
    OR_KEYWORD = 285,              /* OR_KEYWORD  */
    NOT_KEYWORD = 286,             /* NOT_KEYWORD  */
    OPENING_CURLY_BRACE = 287,     /* OPENING_CURLY_BRACE  */
    CLOSING_CURLY_BRACE = 288,     /* CLOSING_CURLY_BRACE  */
    OPENING_PARENTHESIS = 289,     /* OPENING_PARENTHESIS  */
    CLOSING_PARENTHESIS = 290,     /* CLOSING_PARENTHESIS  */
    OPENING_SQUARE_BRACKETS = 291, /* OPENING_SQUARE_BRACKETS  */
    CLOSING_SQUARE_BRACKETS = 292, /* CLOSING_SQUARE_BRACKETS  */
    COMMA = 293,                   /* COMMA  */
    ASTRISK = 294,                 /* ASTRISK  */
    PLUS = 295,                    /* PLUS  */
    MINUS = 296,                   /* MINUS  */
    DIVIDE = 297,                  /* DIVIDE  */
    MODULO = 298,                  /* MODULO  */
    INCREMENT = 299,               /* INCREMENT  */
    DECREMENT = 300,               /* DECREMENT  */
    ASSIGNMENT = 301,              /* ASSIGNMENT  */
    EQUAL = 302,                   /* EQUAL  */
    NOT_EQUAL = 303,               /* NOT_EQUAL  */
    LESS_OR_EQUAL = 304,           /* LESS_OR_EQUAL  */
    GREATER_OR_EQUAL = 305,        /* GREATER_OR_EQUAL  */
    LESS = 306,                    /* LESS  */
    GREATER = 307,                 /* GREATER  */
    BITWISE_AND = 308,             /* BITWISE_AND  */
    BITWISE_OR = 309,              /* BITWISE_OR  */
    BITWISE_XOR = 310,             /* BITWISE_XOR  */
    BITWISE_NOT = 311,             /* BITWISE_NOT  */
    COLON = 312,                   /* COLON  */
    SEMICOLON = 313,               /* SEMICOLON  */
    UNRECOGNIZED_TOKEN = 314,      /* UNRECOGNIZED_TOKEN  */
    RESERVED_IDENTIFIER = 315      /* RESERVED_IDENTIFIER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "parser.y"

    int ival;
    float fval;
    char* sval;
    char cval;
    struct Parameter *param_list;
    struct {
        char* type;
        char* name;
    } type_id;
    struct Instruction* instruction;

#line 137 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
