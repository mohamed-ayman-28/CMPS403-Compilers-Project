
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER_LITERAL = 258,
     FLOAT_LITERAL = 259,
     CHARACTER_LITERAL = 260,
     STRING_LITERAL = 261,
     BOOLEAN_LITERAL = 262,
     IDENTIFIER = 263,
     INT_TYPE_KEYWORD = 264,
     FLOAT_TYPE_KEYWORD = 265,
     STRING_TYPE_KEYWORD = 266,
     CHAR_TYPE_KEYWORD = 267,
     BOOL_TYPE_KEYWORD = 268,
     VOID_TYPE_KEYWORD = 269,
     IF_KEYWORD = 270,
     ELSE_KEYWORD = 271,
     FOR_KEYWORD = 272,
     WHILE_KEYWORD = 273,
     SWITCH_KEYWORD = 274,
     MAIN_KEYWORD = 275,
     DO_KEYWORD = 276,
     RETURN_KEYWORD = 277,
     CASE_KEYWORD = 278,
     CONST_KEYWORD = 279,
     BREAK_KEYWORD = 280,
     CONTINUE_KEYWORD = 281,
     DEFAULT_KEYWORD = 282,
     AND_KEYWORD = 283,
     OR_KEYWORD = 284,
     NOT_KEYWORD = 285,
     OPENING_CURLY_BRACE = 286,
     CLOSING_CURLY_BRACE = 287,
     OPENING_PARENTHESIS = 288,
     CLOSING_PARENTHESIS = 289,
     OPENING_SQUARE_BRACKETS = 290,
     CLOSING_SQUARE_BRACKETS = 291,
     COMMA = 292,
     ASTRISK = 293,
     PLUS = 294,
     MINUS = 295,
     DIVIDE = 296,
     MODULO = 297,
     INCREMENT = 298,
     DECREMENT = 299,
     ASSIGNMENT = 300,
     EQUAL = 301,
     NOT_EQUAL = 302,
     LESS_OR_EQUAL = 303,
     GREATER_OR_EQUAL = 304,
     LESS = 305,
     GREATER = 306,
     BITWISE_AND = 307,
     BITWISE_OR = 308,
     BITWISE_XOR = 309,
     BITWISE_NOT = 310,
     COLON = 311,
     SEMICOLON = 312,
     UNRECOGNIZED_TOKEN = 313,
     RESERVED_IDENTIFIER = 314
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


