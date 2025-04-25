
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "test.y"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool main_defined = false; // Flag to track if main has been defined

void yyerror(const char *s);
int yylex(void);


/* Line 189 of yacc.c  */
#line 85 "test.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 186 "test.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   785

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  148
/* YYNRULES -- Number of states.  */
#define YYNSTATES  304

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   314

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    13,    16,    20,    24,    25,    35,    45,
      47,    51,    52,    55,    57,    58,    60,    62,    64,    67,
      70,    73,    76,    78,    80,    82,    84,    87,    90,    92,
      94,    98,   100,   101,   104,   110,   114,   120,   127,   132,
     142,   147,   149,   153,   154,   156,   158,   160,   162,   164,
     166,   171,   175,   179,   181,   185,   189,   193,   195,   197,
     200,   202,   205,   208,   210,   212,   214,   216,   220,   222,
     226,   228,   232,   234,   237,   239,   241,   245,   249,   253,
     257,   261,   265,   267,   271,   273,   277,   279,   283,   285,
     288,   290,   294,   296,   298,   300,   302,   304,   306,   309,
     311,   313,   315,   317,   319,   321,   323,   331,   333,   335,
     338,   344,   352,   354,   356,   364,   366,   372,   380,   385,
     387,   389,   391,   394,   397,   400,   403,   406,   409,   411,
     413,   415,   417,   420,   423,   424,   426,   429,   441,   443,
     445,   453,   463,   471,   482,   485,   487,   488,   493
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      61,     0,    -1,    62,     9,    20,    33,    34,    31,    65,
      92,    32,    -1,    62,    63,    -1,    62,    71,    57,    -1,
      62,    73,    57,    -1,    -1,    14,     8,    33,    64,    34,
      31,    65,    92,    32,    -1,    96,     8,    33,    64,    34,
      31,    65,    92,    32,    -1,    95,    -1,    64,    37,    95,
      -1,    -1,    65,    66,    -1,    66,    -1,    -1,    97,    -1,
     106,    -1,   107,    -1,    72,    57,    -1,    73,    57,    -1,
      71,    57,    -1,    74,    57,    -1,   110,    -1,   112,    -1,
     113,    -1,   114,    -1,    69,    57,    -1,    68,    57,    -1,
      58,    -1,    59,    -1,    31,    65,    32,    -1,    24,    -1,
      -1,    70,    95,    -1,    70,    95,    35,     3,    36,    -1,
       8,    45,    76,    -1,     8,    45,    35,    75,    36,    -1,
       8,    35,    76,    36,    45,    76,    -1,    70,    95,    45,
      76,    -1,    70,    95,    35,     3,    36,    45,    35,    75,
      36,    -1,     8,    33,    75,    34,    -1,    76,    -1,    75,
      37,    76,    -1,    -1,    78,    -1,    77,    -1,    83,    -1,
      74,    -1,    88,    -1,    93,    -1,     8,    35,    76,    36,
      -1,    78,    39,    79,    -1,    78,    40,    79,    -1,    79,
      -1,    79,    38,    80,    -1,    79,    41,    80,    -1,    79,
      42,    80,    -1,    80,    -1,    81,    -1,    40,    80,    -1,
      82,    -1,    82,    43,    -1,    82,    44,    -1,    94,    -1,
      77,    -1,    74,    -1,     8,    -1,    33,    78,    34,    -1,
      84,    -1,    84,    29,    85,    -1,    85,    -1,    85,    28,
      86,    -1,    86,    -1,    30,    86,    -1,     7,    -1,    87,
      -1,    78,    46,    78,    -1,    78,    47,    78,    -1,    78,
      50,    78,    -1,    78,    51,    78,    -1,    78,    48,    78,
      -1,    78,    49,    78,    -1,    78,    -1,    88,    53,    89,
      -1,    89,    -1,    89,    54,    90,    -1,    90,    -1,    90,
      52,    91,    -1,    91,    -1,    55,    91,    -1,    78,    -1,
      22,    76,    57,    -1,    94,    -1,     5,    -1,     6,    -1,
       7,    -1,     3,    -1,     4,    -1,    96,     8,    -1,     9,
      -1,    10,    -1,    11,    -1,    12,    -1,    13,    -1,    98,
      -1,   100,    -1,    15,    33,    83,    34,    98,    16,    98,
      -1,    99,    -1,    67,    -1,    99,    67,    -1,    15,    33,
      83,    34,    65,    -1,    15,    33,    83,    34,    98,    16,
     100,    -1,   102,    -1,   103,    -1,    15,    33,    83,    34,
     104,    16,   102,    -1,    99,    -1,    15,    33,    83,    34,
     104,    -1,    15,    33,    83,    34,   102,    16,   103,    -1,
      31,    65,   108,    32,    -1,   101,    -1,   106,    -1,   107,
      -1,    72,    57,    -1,    73,    57,    -1,    71,    57,    -1,
      74,    57,    -1,    69,    57,    -1,    68,    57,    -1,   114,
      -1,   110,    -1,   112,    -1,   113,    -1,    25,    57,    -1,
      26,    57,    -1,    -1,   105,    -1,   109,   105,    -1,    17,
      33,   111,    57,    83,    57,    72,    34,    31,   109,    32,
      -1,    72,    -1,    73,    -1,    18,    33,    83,    34,    31,
     109,    32,    -1,    21,    31,   109,    32,    18,    33,    83,
      34,    57,    -1,    19,    33,    76,    34,    31,   115,    32,
      -1,    19,    33,    76,    34,    31,   115,    27,    56,    65,
      32,    -1,   115,   116,    -1,   116,    -1,    -1,    23,     8,
      56,    65,    -1,    23,    93,    56,    65,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    74,    74,    85,    86,    87,    88,    91,    97,   111,
     112,   113,   117,   118,   119,   122,   123,   124,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   140,   144,
     150,   153,   154,   158,   159,   162,   163,   164,   167,   168,
     171,   174,   175,   176,   179,   180,   181,   182,   183,   184,
     187,   190,   191,   192,   195,   196,   197,   198,   201,   202,
     205,   206,   207,   210,   211,   212,   213,   214,   217,   220,
     221,   224,   225,   228,   229,   230,   233,   234,   235,   236,
     237,   238,   239,   242,   243,   246,   247,   250,   251,   254,
     255,   258,   261,   262,   263,   264,   267,   268,   271,   274,
     275,   276,   277,   278,   282,   283,   286,   287,   289,   290,
     293,   294,   297,   298,   301,   302,   305,   306,   309,   313,
     314,   315,   318,   319,   320,   321,   322,   323,   324,   326,
     327,   328,   334,   335,   336,   339,   340,   343,   346,   347,
     350,   353,   356,   357,   360,   361,   362,   365,   366
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER_LITERAL", "FLOAT_LITERAL",
  "CHARACTER_LITERAL", "STRING_LITERAL", "BOOLEAN_LITERAL", "IDENTIFIER",
  "INT_TYPE_KEYWORD", "FLOAT_TYPE_KEYWORD", "STRING_TYPE_KEYWORD",
  "CHAR_TYPE_KEYWORD", "BOOL_TYPE_KEYWORD", "VOID_TYPE_KEYWORD",
  "IF_KEYWORD", "ELSE_KEYWORD", "FOR_KEYWORD", "WHILE_KEYWORD",
  "SWITCH_KEYWORD", "MAIN_KEYWORD", "DO_KEYWORD", "RETURN_KEYWORD",
  "CASE_KEYWORD", "CONST_KEYWORD", "BREAK_KEYWORD", "CONTINUE_KEYWORD",
  "DEFAULT_KEYWORD", "AND_KEYWORD", "OR_KEYWORD", "NOT_KEYWORD",
  "OPENING_CURLY_BRACE", "CLOSING_CURLY_BRACE", "OPENING_PARENTHESIS",
  "CLOSING_PARENTHESIS", "OPENING_SQUARE_BRACKETS",
  "CLOSING_SQUARE_BRACKETS", "COMMA", "ASTRISK", "PLUS", "MINUS", "DIVIDE",
  "MODULO", "INCREMENT", "DECREMENT", "ASSIGNMENT", "EQUAL", "NOT_EQUAL",
  "LESS_OR_EQUAL", "GREATER_OR_EQUAL", "LESS", "GREATER", "BITWISE_AND",
  "BITWISE_OR", "BITWISE_XOR", "BITWISE_NOT", "COLON", "SEMICOLON",
  "UNRECOGNIZED_TOKEN", "RESERVED_IDENTIFIER", "$accept", "program",
  "declarations", "function_declaration", "function_arguments", "body",
  "statement", "non_if_statement", "error_token", "block_structure",
  "const", "declaration", "assignment", "initialization", "function_call",
  "expr_list", "expr", "array_element", "arithmetic_expr",
  "arithmetic_term", "arithmetic_factor", "postfix_expr", "primary_expr",
  "bool_expr", "logical_or_expression", "logical_and_expression",
  "logical_not_expression", "comparison_expr", "bitwise_expr",
  "bitwise_xor_expr", "bitwise_and_expr", "bitwise_not_expr", "return",
  "literal", "numeric_literal", "type_identifier", "type", "if",
  "matched_statement", "non_if_statements", "unmatched_statement",
  "if_in_loop", "matched_if_in_loop", "unmatched_if_in_loop", "loop_block",
  "loop_body_statement", "non_loop_non_if_statement", "loop_statement",
  "break_or_continue", "loop_body_statements", "for", "loop_start",
  "while", "do_while", "switch", "case_list", "case_statement", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    62,    62,    62,    62,    63,    63,    64,
      64,    64,    65,    65,    65,    66,    66,    66,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    68,    68,
      69,    70,    70,    71,    71,    72,    72,    72,    73,    73,
      74,    75,    75,    75,    76,    76,    76,    76,    76,    76,
      77,    78,    78,    78,    79,    79,    79,    79,    80,    80,
      81,    81,    81,    82,    82,    82,    82,    82,    83,    84,
      84,    85,    85,    86,    86,    86,    87,    87,    87,    87,
      87,    87,    87,    88,    88,    89,    89,    90,    90,    91,
      91,    92,    93,    93,    93,    93,    94,    94,    95,    96,
      96,    96,    96,    96,    97,    97,    98,    98,    99,    99,
     100,   100,   101,   101,   102,   102,   103,   103,   104,   105,
     105,   105,   106,   106,   106,   106,   106,   106,   106,   107,
     107,   107,   108,   108,   108,   109,   109,   110,   111,   111,
     112,   113,   114,   114,   115,   115,   115,   116,   116
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     9,     2,     3,     3,     0,     9,     9,     1,
       3,     0,     2,     1,     0,     1,     1,     1,     2,     2,
       2,     2,     1,     1,     1,     1,     2,     2,     1,     1,
       3,     1,     0,     2,     5,     3,     5,     6,     4,     9,
       4,     1,     3,     0,     1,     1,     1,     1,     1,     1,
       4,     3,     3,     1,     3,     3,     3,     1,     1,     2,
       1,     2,     2,     1,     1,     1,     1,     3,     1,     3,
       1,     3,     1,     2,     1,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     2,
       1,     3,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     7,     1,     1,     2,
       5,     7,     1,     1,     7,     1,     5,     7,     4,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     2,     2,     0,     1,     2,    11,     1,     1,
       7,     9,     7,    10,     2,     1,     0,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     0,     1,    99,   100,   101,   102,   103,     0,
      31,     3,     0,     0,     0,     0,     0,     0,    99,    33,
       0,     4,     5,     0,     0,    11,     0,     0,    98,    11,
       0,     0,     9,     0,    96,    97,    93,    94,    74,    66,
       0,     0,     0,     0,    65,    38,    64,    44,    53,    57,
      58,    60,    46,    68,    70,    72,    75,    48,    84,    86,
      88,    49,    63,     0,    14,     0,     0,    34,    43,     0,
      74,    65,    64,    82,    73,    63,     0,    59,    90,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    61,    62,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    14,    28,    29,    32,    13,
     108,     0,     0,     0,     0,     0,     0,    15,   104,   107,
     105,    16,    17,    22,    23,    24,    25,    14,    10,     0,
       0,    41,     0,    67,    51,    52,    76,    77,    80,    81,
      78,    79,    54,    55,    56,    69,    71,    83,    85,    87,
      14,     0,     0,     0,    32,     0,     0,    32,    32,     0,
      12,     0,    27,    26,    20,    18,    19,    21,   109,     0,
       0,     0,     0,     0,     0,    22,    23,    24,    25,    32,
      43,    40,     0,    50,    32,     0,    43,    35,     0,     0,
       0,   138,   139,     0,     0,     0,     0,    32,   119,   112,
     113,   135,   120,   121,    32,    30,     0,     2,    27,    26,
      20,    18,    19,    21,     0,     0,    42,     0,     0,     0,
      14,     0,     0,     0,     0,     0,     0,   136,    91,     7,
      39,     8,     0,    36,   110,   104,     0,     0,    32,   146,
       0,     0,    37,    32,     0,     0,    32,     0,     0,   145,
      32,     0,   106,   111,     0,     0,   140,    95,     0,     0,
      92,     0,   142,   144,     0,    14,     0,   116,     0,     0,
      14,    14,    14,     0,    32,     0,    32,     0,    32,    32,
      32,    32,     0,     0,     0,     0,     0,   117,   114,   141,
      32,   143,     0,   132,   133,   118,     0,   137,    14,     0,
       0,    32,    32,   116
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    11,    31,   108,   109,   110,   111,   112,
      12,   113,   114,   115,    71,   130,   131,    72,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,   161,    61,    75,    32,    20,   117,   118,   119,
     120,   198,   199,   200,   267,   201,   121,   122,   285,   204,
     123,   193,   124,   125,   126,   248,   249
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -246
static const yytype_int16 yypact[] =
{
    -246,    26,   399,  -246,    10,  -246,  -246,  -246,  -246,    39,
    -246,  -246,   643,    19,    78,    88,    22,    75,  -246,   -26,
     119,  -246,  -246,   110,   112,   643,   137,   398,  -246,   643,
     126,    50,  -246,   114,  -246,  -246,  -246,  -246,  -246,   109,
     411,   118,   118,   301,   -23,  -246,   -14,   720,   194,  -246,
    -246,   111,  -246,   132,   144,  -246,  -246,   121,   122,   113,
    -246,  -246,  -246,    61,   672,   163,   643,   133,   398,   398,
    -246,  -246,  -246,    24,  -246,  -246,   151,  -246,   130,  -246,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,  -246,  -246,   411,   411,   301,   301,   301,   170,   -17,
     176,   178,   184,   186,   203,   672,  -246,  -246,   553,  -246,
    -246,   182,   187,   190,   198,   200,   205,  -246,  -246,   454,
    -246,  -246,  -246,  -246,  -246,  -246,  -246,   672,  -246,   230,
      72,  -246,   232,  -246,   194,   194,   130,   130,   130,   130,
     130,   130,  -246,  -246,  -246,   144,  -246,   122,   113,  -246,
     672,   398,   387,   411,     9,   411,   398,   697,   561,   398,
    -246,   234,  -246,  -246,  -246,  -246,  -246,  -246,  -246,   216,
     219,   220,   222,   223,   229,  -246,  -246,  -246,  -246,   553,
     398,  -246,   398,  -246,   553,   253,   398,  -246,   256,     6,
     643,  -246,  -246,   236,   262,   263,   270,    21,  -246,  -246,
    -246,  -246,  -246,  -246,   582,  -246,   250,  -246,  -246,  -246,
    -246,  -246,  -246,  -246,   276,   146,  -246,   280,   278,   185,
     672,    47,   411,   284,   290,   411,   307,  -246,  -246,  -246,
    -246,  -246,   398,  -246,   437,   310,   325,   272,   697,   312,
     299,   303,  -246,   672,   302,   331,   607,   429,   102,  -246,
     705,   411,  -246,  -246,   133,   308,  -246,  -246,   287,   293,
    -246,   295,  -246,  -246,   321,   672,   344,   345,   328,   333,
     672,   672,   672,   411,   462,   350,   726,   309,   697,   483,
     508,   627,   335,   313,   317,   343,   334,  -246,  -246,  -246,
     652,  -246,   346,  -246,  -246,  -246,   411,  -246,   672,   345,
     348,   528,   705,  -246
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -246,  -246,  -246,  -246,   349,   -73,   -93,  -116,    56,    70,
     225,    -1,   -30,    -2,   -20,   -70,    -3,   136,    18,   147,
     -21,  -246,  -246,  -128,  -246,   294,   -34,  -246,  -246,   285,
     292,   -35,   -51,   139,    51,   -10,   396,  -246,  -208,    81,
     157,  -246,  -245,   141,  -209,  -200,   106,   107,  -246,  -228,
      74,  -246,    87,    97,   105,  -246,   173
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -149
static const yytype_int16 yytable[] =
{
      14,    13,    19,   168,   227,   266,    74,    44,    79,    26,
     246,   -47,   235,   -47,   -47,   160,    68,   189,   151,    27,
     -45,    77,   -45,   -45,    45,   188,     3,   194,   152,    99,
      16,   288,   158,    10,   -47,   252,  -115,  -115,   101,   102,
     103,   151,   104,   -45,   116,    10,   227,    17,    44,    44,
     290,   152,   105,  -115,   179,    24,   128,   266,    73,    76,
     146,    78,   149,    80,    81,   160,   132,   142,   143,   144,
      82,    83,    84,    85,    86,    87,    21,   184,    62,   106,
     107,   168,   236,   299,    65,   116,   160,    66,   116,   172,
     227,   160,    27,   303,   237,    98,    23,   240,    66,   174,
     136,   137,   138,   139,   140,   141,   181,   116,    25,   182,
     215,    73,    73,    78,    78,    78,   219,   173,   171,    62,
      62,    34,    35,   268,   191,   247,    39,    28,   214,   261,
     116,    44,    44,   217,   262,    22,    44,   116,   116,    44,
      33,   160,    68,    29,    69,   282,    30,   234,   185,   187,
      67,    41,   192,   195,    91,    92,   206,    64,    42,   116,
      44,    93,    44,    46,   116,    97,    44,   172,   300,    80,
      81,    73,    94,    73,    95,   169,    96,   174,   129,   216,
     221,   160,   230,   182,   116,   133,   160,   160,   160,   170,
      80,    81,   274,   175,   127,   173,   171,   279,   280,   281,
     116,   150,    62,    62,    46,    46,   176,    62,   160,   153,
      62,   154,    44,   172,   116,   255,   177,   155,   116,   156,
     172,   233,   182,   174,   178,   301,   116,   134,   135,   242,
     174,    62,    88,    62,   157,    89,    90,    62,   197,   162,
      73,   173,   171,    73,   163,   116,   172,   164,   173,   171,
     116,   116,   116,   169,   116,   165,   174,   166,   116,   116,
     116,   116,   167,   202,   203,   180,   207,   170,   183,    73,
     116,   175,   172,   208,   173,   171,   209,   210,   116,   211,
     212,   116,   174,    62,   176,   197,   213,    46,    46,   218,
     220,    73,    46,   222,   177,    46,   223,   224,   260,   169,
     173,   171,   178,   225,    34,    35,   169,   228,   229,    39,
     202,   203,   231,   170,    73,   238,    46,   175,    46,   197,
     170,   239,    46,   232,   175,   241,   243,   197,   244,   245,
     176,   197,   169,   250,    41,   247,   251,   176,   254,   189,
     177,    42,   269,   270,   202,   203,   170,   177,   178,   271,
     175,   272,   202,   203,   273,   178,    43,   197,   169,   197,
     275,   276,   277,   176,   278,   286,   289,   296,    46,   292,
     293,   197,   170,   177,   294,   295,   175,   298,    63,   190,
     147,   178,   302,   197,   202,   203,   259,   145,   148,   176,
      34,    35,    36,    37,    38,    39,   202,   203,    15,   177,
     253,    34,    35,    36,    37,    38,    39,   178,     4,     5,
       6,     7,     8,     9,    34,    35,   287,    40,    70,    39,
      41,   263,   186,    10,     0,     0,     0,    42,    40,     0,
       0,    41,    34,    35,    36,    37,   257,   258,    42,     0,
       0,    40,    43,     0,    41,    99,   -32,   -32,   -32,   -32,
     -32,    42,   100,    43,   101,   102,   103,     0,   104,     0,
       0,    10,    99,   -32,   -32,   -32,   -32,   -32,   105,     0,
      99,   101,   102,   103,     0,   104,     0,   100,    10,   101,
     102,   103,     0,   104,     0,   105,    10,   283,   284,     0,
       0,    99,     0,   105,   205,   106,   107,     0,   100,     0,
     101,   102,   103,     0,   104,     0,  -147,    10,     0,     0,
    -147,     0,   106,   107,   105,  -147,    99,     0,     0,     0,
     106,   107,     0,   100,     0,   101,   102,   103,     0,   104,
       0,  -148,    10,     0,     0,  -148,    99,     0,     0,   105,
    -148,   106,   107,   100,     0,   101,   102,   103,     0,   104,
       0,     0,    10,   283,   284,     0,     0,     0,     0,   105,
    -134,    99,     0,     0,     0,     0,   106,   107,   100,    99,
     101,   102,   103,     0,   104,   159,   100,    10,   101,   102,
     103,     0,   104,     0,   105,    10,   106,   107,     0,     0,
      99,     0,   105,   205,     0,     0,     0,   196,     0,   101,
     102,   103,     0,   104,     0,     0,    10,     0,     0,     0,
       0,   106,   107,   105,   226,    99,     0,     0,     0,   106,
     107,     0,   196,     0,   101,   102,   103,     0,   104,     0,
       0,    10,     0,     0,     0,    99,     0,     0,   105,   256,
     106,   107,   100,     0,   101,   102,   103,     0,   104,     0,
       0,    10,    18,     5,     6,     7,     8,     0,   105,   291,
      99,     0,     0,     0,     0,   106,   107,   196,     0,   101,
     102,   103,     0,   104,     0,     0,    10,     0,     0,     0,
      99,     0,     0,   105,   297,   106,   107,   100,     0,   101,
     102,   103,     0,   104,     0,     0,    10,     0,     0,     0,
       0,     0,     0,   105,     0,    99,     0,     0,     0,     0,
     106,   107,   196,    99,   101,   102,   103,     0,   104,     0,
     264,    10,   101,   102,   103,     0,   104,     0,   105,    10,
     106,   107,     0,     0,    99,     0,   265,     0,     0,     0,
       0,   264,     0,   101,   102,   103,     0,   104,   -82,   -82,
      10,     0,     0,     0,     0,   106,   107,   105,     0,    80,
      81,     0,     0,   106,   107,     0,    82,    83,    84,    85,
      86,    87,   -90,   -90,   -90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   106,   107
};

static const yytype_int16 yycheck[] =
{
       2,     2,    12,   119,   204,   250,    40,    27,    43,    35,
     238,    34,   220,    36,    37,   108,    33,     8,    35,    45,
      34,    42,    36,    37,    27,   153,     0,   155,    45,     8,
      20,   276,   105,    24,    57,   243,    15,    16,    17,    18,
      19,    35,    21,    57,    64,    24,   246,     8,    68,    69,
     278,    45,    31,    32,   127,    33,    66,   302,    40,    41,
      94,    43,    97,    39,    40,   158,    69,    88,    89,    90,
      46,    47,    48,    49,    50,    51,    57,   150,    27,    58,
      59,   197,    35,   292,    34,   105,   179,    37,   108,   119,
     290,   184,    45,   302,   222,    34,     8,   225,    37,   119,
      82,    83,    84,    85,    86,    87,    34,   127,    33,    37,
     180,    93,    94,    95,    96,    97,   186,   119,   119,    68,
      69,     3,     4,   251,   154,    23,     8,     8,   179,    27,
     150,   151,   152,   184,    32,    57,   156,   157,   158,   159,
       3,   234,    33,    33,    35,   273,    34,   220,   151,   152,
      36,    33,   154,   156,    43,    44,   159,    31,    40,   179,
     180,    29,   182,    27,   184,    52,   186,   197,   296,    39,
      40,   153,    28,   155,    53,   119,    54,   197,    45,   182,
     190,   274,    36,    37,   204,    34,   279,   280,   281,   119,
      39,    40,   265,   119,    31,   197,   197,   270,   271,   272,
     220,    31,   151,   152,    68,    69,   119,   156,   301,    33,
     159,    33,   232,   243,   234,   245,   119,    33,   238,    33,
     250,    36,    37,   243,   119,   298,   246,    80,    81,   232,
     250,   180,    38,   182,    31,    41,    42,   186,   157,    57,
     222,   243,   243,   225,    57,   265,   276,    57,   250,   250,
     270,   271,   272,   197,   274,    57,   276,    57,   278,   279,
     280,   281,    57,   157,   157,    35,    32,   197,    36,   251,
     290,   197,   302,    57,   276,   276,    57,    57,   298,    57,
      57,   301,   302,   232,   197,   204,    57,   151,   152,    36,
      34,   273,   156,    57,   197,   159,    34,    34,   247,   243,
     302,   302,   197,    33,     3,     4,   250,    57,    32,     8,
     204,   204,    32,   243,   296,    31,   180,   243,   182,   238,
     250,    31,   186,    45,   250,    18,    16,   246,     3,    57,
     243,   250,   276,    34,    33,    23,    33,   250,    36,     8,
     243,    40,    34,    56,   238,   238,   276,   250,   243,    56,
     276,    56,   246,   246,    33,   250,    55,   276,   302,   278,
      16,    16,    34,   276,    31,    15,    57,    33,   232,    34,
      57,   290,   302,   276,    57,    32,   302,    31,    29,   154,
      95,   276,    34,   302,   278,   278,   247,    93,    96,   302,
       3,     4,     5,     6,     7,     8,   290,   290,     2,   302,
     243,     3,     4,     5,     6,     7,     8,   302,     9,    10,
      11,    12,    13,    14,     3,     4,   275,    30,     7,     8,
      33,   248,    35,    24,    -1,    -1,    -1,    40,    30,    -1,
      -1,    33,     3,     4,     5,     6,     7,     8,    40,    -1,
      -1,    30,    55,    -1,    33,     8,     9,    10,    11,    12,
      13,    40,    15,    55,    17,    18,    19,    -1,    21,    -1,
      -1,    24,     8,     9,    10,    11,    12,    13,    31,    -1,
       8,    17,    18,    19,    -1,    21,    -1,    15,    24,    17,
      18,    19,    -1,    21,    -1,    31,    24,    25,    26,    -1,
      -1,     8,    -1,    31,    32,    58,    59,    -1,    15,    -1,
      17,    18,    19,    -1,    21,    -1,    23,    24,    -1,    -1,
      27,    -1,    58,    59,    31,    32,     8,    -1,    -1,    -1,
      58,    59,    -1,    15,    -1,    17,    18,    19,    -1,    21,
      -1,    23,    24,    -1,    -1,    27,     8,    -1,    -1,    31,
      32,    58,    59,    15,    -1,    17,    18,    19,    -1,    21,
      -1,    -1,    24,    25,    26,    -1,    -1,    -1,    -1,    31,
      32,     8,    -1,    -1,    -1,    -1,    58,    59,    15,     8,
      17,    18,    19,    -1,    21,    22,    15,    24,    17,    18,
      19,    -1,    21,    -1,    31,    24,    58,    59,    -1,    -1,
       8,    -1,    31,    32,    -1,    -1,    -1,    15,    -1,    17,
      18,    19,    -1,    21,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    58,    59,    31,    32,     8,    -1,    -1,    -1,    58,
      59,    -1,    15,    -1,    17,    18,    19,    -1,    21,    -1,
      -1,    24,    -1,    -1,    -1,     8,    -1,    -1,    31,    32,
      58,    59,    15,    -1,    17,    18,    19,    -1,    21,    -1,
      -1,    24,     9,    10,    11,    12,    13,    -1,    31,    32,
       8,    -1,    -1,    -1,    -1,    58,    59,    15,    -1,    17,
      18,    19,    -1,    21,    -1,    -1,    24,    -1,    -1,    -1,
       8,    -1,    -1,    31,    32,    58,    59,    15,    -1,    17,
      18,    19,    -1,    21,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,     8,    -1,    -1,    -1,    -1,
      58,    59,    15,     8,    17,    18,    19,    -1,    21,    -1,
      15,    24,    17,    18,    19,    -1,    21,    -1,    31,    24,
      58,    59,    -1,    -1,     8,    -1,    31,    -1,    -1,    -1,
      -1,    15,    -1,    17,    18,    19,    -1,    21,    28,    29,
      24,    -1,    -1,    -1,    -1,    58,    59,    31,    -1,    39,
      40,    -1,    -1,    58,    59,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    59
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    61,    62,     0,     9,    10,    11,    12,    13,    14,
      24,    63,    70,    71,    73,    96,    20,     8,     9,    95,
      96,    57,    57,     8,    33,    33,    35,    45,     8,    33,
      34,    64,    95,     3,     3,     4,     5,     6,     7,     8,
      30,    33,    40,    55,    74,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    93,    94,    64,    31,    34,    37,    36,    33,    35,
       7,    74,    77,    78,    86,    94,    78,    80,    78,    91,
      39,    40,    46,    47,    48,    49,    50,    51,    38,    41,
      42,    43,    44,    29,    28,    53,    54,    52,    34,     8,
      15,    17,    18,    19,    21,    31,    58,    59,    65,    66,
      67,    68,    69,    71,    72,    73,    74,    97,    98,    99,
     100,   106,   107,   110,   112,   113,   114,    31,    95,    45,
      75,    76,    76,    34,    79,    79,    78,    78,    78,    78,
      78,    78,    80,    80,    80,    85,    86,    89,    90,    91,
      31,    35,    45,    33,    33,    33,    33,    31,    65,    22,
      66,    92,    57,    57,    57,    57,    57,    57,    67,    68,
      69,    71,    72,    73,    74,   110,   112,   113,   114,    65,
      35,    34,    37,    36,    65,    76,    35,    76,    83,     8,
      70,    72,    73,   111,    83,    76,    15,    99,   101,   102,
     103,   105,   106,   107,   109,    32,    76,    32,    57,    57,
      57,    57,    57,    57,    92,    75,    76,    92,    36,    75,
      34,    95,    57,    34,    34,    33,    32,   105,    57,    32,
      36,    32,    45,    36,    65,    98,    35,    83,    31,    31,
      83,    18,    76,    16,     3,    57,   109,    23,   115,   116,
      34,    33,    98,   100,    36,    72,    32,     7,     8,    93,
      94,    27,    32,   116,    15,    31,   102,   104,    83,    34,
      56,    56,    56,    33,    65,    16,    16,    34,    31,    65,
      65,    65,    83,    25,    26,   108,    15,   103,   102,    57,
     109,    32,    34,    57,    57,    32,    33,    32,    31,   104,
      83,    65,    34,   104
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 75 "test.y"
    {
                                if (main_defined) {
                                    yyerror("Error: Multiple definitions of main function");
                                } else {
                                    main_defined = true;
                                }
                            ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 92 "test.y"
    {
                                if (strcmp((yyvsp[(2) - (9)]), "main") == 0) {
                                    yyerror("Error: main function must have int return type");
                                }
                            ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 98 "test.y"
    {
                                if (strcmp((yyvsp[(2) - (9)]), "main") == 0) {
                                    if (main_defined) {
                                        yyerror("Error: Multiple definitions of main function");
                                    } else if ((yyvsp[(1) - (9)]) != INT_TYPE_KEYWORD) {
                                        yyerror("Error: main function must have int return type");
                                    } else {
                                        main_defined = true;
                                    }
                                }
                            ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 141 "test.y"
    { 
                                fprintf(stderr, "Error: Unrecognized token\n"); 
                            ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 145 "test.y"
    { 
                                fprintf(stderr, "Error: Reserved identifier used\n"); 
                            ;}
    break;



/* Line 1455 of yacc.c  */
#line 1821 "test.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 369 "test.y"


void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
}

int main() {
    yyparse();
    return 0;
}
