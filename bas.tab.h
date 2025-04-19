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

#ifndef YY_YY_BAS_TAB_H_INCLUDED
# define YY_YY_BAS_TAB_H_INCLUDED
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
    PRINT = 258,                   /* PRINT  */
    INPUT = 259,                   /* INPUT  */
    BASE10_INTEGER_LITERAL = 260,  /* BASE10_INTEGER_LITERAL  */
    BASE8_INTEGER_LITERAL = 261,   /* BASE8_INTEGER_LITERAL  */
    BASE16_INTEGER_LITERAL = 262,  /* BASE16_INTEGER_LITERAL  */
    BASE2_INTEGER_LITERAL = 263,   /* BASE2_INTEGER_LITERAL  */
    FLOAT_LITERAL = 264,           /* FLOAT_LITERAL  */
    CHARACTER_LITERAL = 265,       /* CHARACTER_LITERAL  */
    STRING_LITERAL = 266,          /* STRING_LITERAL  */
    BOOLEAN_LITERAL = 267,         /* BOOLEAN_LITERAL  */
    NULL_LITERAL = 268,            /* NULL_LITERAL  */
    COMMENT = 269,                 /* COMMENT  */
    IDENTIFIER = 270,              /* IDENTIFIER  */
    INT_TYPE_KEYWORD = 271,        /* INT_TYPE_KEYWORD  */
    FLOAT_TYPE_KEYWORD = 272,      /* FLOAT_TYPE_KEYWORD  */
    STRING_TYPE_KEYWORD = 273,     /* STRING_TYPE_KEYWORD  */
    CHAR_TYPE_KEYWORD = 274,       /* CHAR_TYPE_KEYWORD  */
    BOOL_TYPE_KEYWORD = 275,       /* BOOL_TYPE_KEYWORD  */
    VOID_TYPE_KEYWORD = 276,       /* VOID_TYPE_KEYWORD  */
    IF_KEYWORD = 277,              /* IF_KEYWORD  */
    ELSE_KEYWORD = 278,            /* ELSE_KEYWORD  */
    ELSE_IF_KEYWORD = 279,         /* ELSE_IF_KEYWORD  */
    TRY_KEYWORD = 280,             /* TRY_KEYWORD  */
    CATCH_KEYWORD = 281,           /* CATCH_KEYWORD  */
    THROW_KEYWORD = 282,           /* THROW_KEYWORD  */
    FOR_KEYWORD = 283,             /* FOR_KEYWORD  */
    WHILE_KEYWORD = 284,           /* WHILE_KEYWORD  */
    SWITCH_KEYWORD = 285,          /* SWITCH_KEYWORD  */
    REPEAT_KEYWORD = 286,          /* REPEAT_KEYWORD  */
    UNTIL_KEYWORD = 287,           /* UNTIL_KEYWORD  */
    RETURN_KEYWORD = 288,          /* RETURN_KEYWORD  */
    IMPORT_KEYWORD = 289,          /* IMPORT_KEYWORD  */
    GLOBAL_KEYWORD = 290,          /* GLOBAL_KEYWORD  */
    CONST_KEYWORD = 291,           /* CONST_KEYWORD  */
    DELETE_KEYWORD = 292,          /* DELETE_KEYWORD  */
    NEW_KEYWORD = 293,             /* NEW_KEYWORD  */
    IS_KEYWORD = 294,              /* IS_KEYWORD  */
    AND_KEYWORD = 295,             /* AND_KEYWORD  */
    OR_KEYWORD = 296,              /* OR_KEYWORD  */
    NOT_KEYWORD = 297,             /* NOT_KEYWORD  */
    OPENING_CURLY_BRACE = 298,     /* OPENING_CURLY_BRACE  */
    CLOSING_CURLY_BRACE = 299,     /* CLOSING_CURLY_BRACE  */
    OPENING_PARENTHESIS = 300,     /* OPENING_PARENTHESIS  */
    CLOSING_PARENTHESIS = 301,     /* CLOSING_PARENTHESIS  */
    OPENING_SQUARE_BRACKETS = 302, /* OPENING_SQUARE_BRACKETS  */
    CLOSING_SQUARE_BRACKETS = 303, /* CLOSING_SQUARE_BRACKETS  */
    DOT = 304,                     /* DOT  */
    COMMA = 305,                   /* COMMA  */
    ASTRISK = 306,                 /* ASTRISK  */
    PLUS = 307,                    /* PLUS  */
    MINUS = 308,                   /* MINUS  */
    DIVIDE = 309,                  /* DIVIDE  */
    MODULO = 310,                  /* MODULO  */
    INCREMENT = 311,               /* INCREMENT  */
    DECREMENT = 312,               /* DECREMENT  */
    ASSIGNMENT = 313,              /* ASSIGNMENT  */
    EQUAL = 314,                   /* EQUAL  */
    NOT_EQUAL = 315,               /* NOT_EQUAL  */
    LESS_OR_EQUAL = 316,           /* LESS_OR_EQUAL  */
    GREATER_OR_EQUAL = 317,        /* GREATER_OR_EQUAL  */
    LESS = 318,                    /* LESS  */
    GREATER = 319,                 /* GREATER  */
    BITWISE_AND = 320,             /* BITWISE_AND  */
    BITWISE_OR = 321,              /* BITWISE_OR  */
    BITWISE_XOR = 322,             /* BITWISE_XOR  */
    BITWISE_NOT = 323,             /* BITWISE_NOT  */
    QUESTION_MARK = 324,           /* QUESTION_MARK  */
    COLON = 325,                   /* COLON  */
    SEMICOLON = 326,               /* SEMICOLON  */
    UNRECOGNIZED_TOKEN = 327,      /* UNRECOGNIZED_TOKEN  */
    RESERVED_IDENTIFIER = 328      /* RESERVED_IDENTIFIER  */
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


#endif /* !YY_YY_BAS_TAB_H_INCLUDED  */
