/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "limbaj.y"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "SymTable.h"

using namespace std;

extern int yylex();
void yyerror(const char* s);
extern FILE* yyin;
extern int yylineno;

SymTable* current = NULL;
ofstream tableFile("tables.txt");
string currentFuncName = "";

void enter_scope(string name) {
    current = new SymTable(name, current);
}

void exit_scope() {
    if (current) {
        SymTable* parent = current->getParent();
        current = parent;
    }
}

void sem_error(string msg) {
    cout << "Semantic Error at line " << yylineno << ": " << msg << endl;
}

/* Line 371 of yacc.c  */
#line 102 "limbaj.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "limbaj.tab.h".  */
#ifndef YY_YY_LIMBAJ_TAB_H_INCLUDED
# define YY_YY_LIMBAJ_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
/* Line 387 of yacc.c  */
#line 35 "limbaj.y"

    #include <string>
    #include <vector>
    using namespace std;

    struct ExprInfo {
        string type;
        string value;
    };


/* Line 387 of yacc.c  */
#line 146 "limbaj.tab.c"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NEW = 258,
     PRINT = 259,
     CLASS = 260,
     RETURN = 261,
     BGIN = 262,
     END = 263,
     ASSIGN = 264,
     IF = 265,
     ELSE = 266,
     WHILE = 267,
     FOR = 268,
     ID = 269,
     TYPE = 270,
     STRING = 271,
     NR = 272,
     FNR = 273,
     BVAL = 274,
     CMP = 275
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 46 "limbaj.y"

    std::string* Str;
    ExprInfo* EInfo;
    std::vector<string>* ArgList;


/* Line 387 of yacc.c  */
#line 188 "limbaj.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_LIMBAJ_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 216 "limbaj.tab.c"

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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   188

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNRULES -- Number of states.  */
#define YYNSTATES  155

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   275

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    25,     2,     2,
      28,    29,    23,    21,    30,    22,    32,    24,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    31,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,     2,    27,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     7,     8,     9,    12,    15,    18,    21,
      22,    27,    28,    35,    36,    39,    42,    43,    53,    54,
      63,    64,    74,    75,    84,    85,    94,    95,   103,   106,
     107,   110,   112,   116,   119,   122,   123,   126,   129,   131,
     134,   140,   144,   148,   154,   155,   164,   165,   174,   179,
     186,   190,   196,   200,   204,   208,   212,   216,   220,   224,
     226,   231,   235,   237,   239,   241,   243,   249,   250,   252
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      34,     0,    -1,    35,    36,    37,    -1,    -1,    -1,    36,
      39,    -1,    36,    42,    -1,    36,    60,    -1,    36,    61,
      -1,    -1,     7,    38,    53,     8,    -1,    -1,     5,    14,
      40,    26,    41,    27,    -1,    -1,    41,    60,    -1,    41,
      42,    -1,    -1,    15,    14,    28,    43,    51,    29,    26,
      49,    27,    -1,    -1,    15,    14,    28,    29,    44,    26,
      49,    27,    -1,    -1,    14,    14,    28,    45,    51,    29,
      26,    49,    27,    -1,    -1,    14,    14,    28,    29,    46,
      26,    49,    27,    -1,    -1,    14,    28,    47,    51,    29,
      26,    49,    27,    -1,    -1,    14,    28,    29,    48,    26,
      49,    27,    -1,    50,    53,    -1,    -1,    50,    60,    -1,
      52,    -1,    51,    30,    52,    -1,    15,    14,    -1,    14,
      14,    -1,    -1,    53,    54,    -1,    55,    31,    -1,    56,
      -1,    59,    31,    -1,     4,    28,    62,    29,    31,    -1,
       6,    62,    31,    -1,    14,     9,    62,    -1,    14,    32,
      14,     9,    62,    -1,    -1,    10,    28,    62,    29,    26,
      57,    53,    27,    -1,    -1,    12,    28,    62,    29,    26,
      58,    53,    27,    -1,    14,    28,    63,    29,    -1,    14,
      32,    14,    28,    63,    29,    -1,    15,    14,    31,    -1,
      15,    14,     9,    62,    31,    -1,    14,    14,    31,    -1,
      62,    21,    62,    -1,    62,    22,    62,    -1,    62,    23,
      62,    -1,    62,    24,    62,    -1,    62,    20,    62,    -1,
      28,    62,    29,    -1,    14,    -1,    14,    28,    63,    29,
      -1,    14,    32,    14,    -1,    17,    -1,    18,    -1,    19,
      -1,    16,    -1,     3,    14,    28,    63,    29,    -1,    -1,
      62,    -1,    63,    30,    62,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    64,    64,    75,    78,    80,    81,    82,    83,    87,
      87,    93,    92,   104,   106,   107,   113,   112,   123,   122,
     132,   131,   142,   141,   151,   150,   160,   159,   169,   170,
     170,   173,   174,   178,   185,   194,   196,   200,   201,   202,
     203,   205,   209,   220,   264,   264,   265,   265,   269,   283,
     298,   303,   313,   318,   322,   326,   330,   334,   338,   339,
     346,   351,   379,   380,   381,   382,   383,   390,   391,   392
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NEW", "PRINT", "CLASS", "RETURN",
  "BGIN", "END", "ASSIGN", "IF", "ELSE", "WHILE", "FOR", "ID", "TYPE",
  "STRING", "NR", "FNR", "BVAL", "CMP", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'{'", "'}'", "'('", "')'", "','", "';'", "'.'", "$accept", "program",
  "global_scope_start", "global_list", "main_block", "$@1", "class_decl",
  "$@2", "class_body", "func_decl", "$@3", "$@4", "$@5", "$@6", "$@7",
  "$@8", "func_body", "decl_list", "param_list", "param_decl", "stmt_list",
  "stmt", "assign_stmt", "control_stmt", "$@9", "$@10", "call_stmt",
  "var_decl", "object_decl", "expr", "args_list", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,    43,    45,    42,    47,    37,   123,   125,    40,    41,
      44,    59,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    35,    36,    36,    36,    36,    36,    38,
      37,    40,    39,    41,    41,    41,    43,    42,    44,    42,
      45,    42,    46,    42,    47,    42,    48,    42,    49,    50,
      50,    51,    51,    52,    52,    53,    53,    54,    54,    54,
      54,    54,    55,    55,    57,    56,    58,    56,    59,    59,
      60,    60,    61,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    63,    63,    63
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     0,     0,     2,     2,     2,     2,     0,
       4,     0,     6,     0,     2,     2,     0,     9,     0,     8,
       0,     9,     0,     8,     0,     8,     0,     7,     2,     0,
       2,     1,     3,     2,     2,     0,     2,     2,     1,     2,
       5,     3,     3,     5,     0,     8,     0,     8,     4,     6,
       3,     5,     3,     3,     3,     3,     3,     3,     3,     1,
       4,     3,     1,     1,     1,     1,     5,     0,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     4,     1,     0,     0,     9,     0,     0,     2,
       5,     6,     7,     8,    11,    35,     0,    24,     0,     0,
       0,    20,    52,    26,     0,     0,    16,    50,    13,     0,
       0,    10,     0,     0,     0,    36,     0,    38,     0,    22,
       0,     0,     0,     0,     0,    31,     0,    59,    65,    62,
      63,    64,     0,     0,    18,     0,     0,     0,     0,     0,
       0,     0,    67,     0,    37,    39,     0,     0,    29,    34,
      33,     0,     0,     0,    67,     0,     0,     0,     0,     0,
       0,     0,    51,     0,     0,     0,    12,    15,    14,     0,
      41,     0,     0,    42,    68,     0,     0,    29,     0,     0,
      35,    29,    32,    67,     0,    61,    58,    57,    53,    54,
      55,    56,    29,     0,     0,     0,     0,     0,    48,     0,
       0,    67,     0,    29,    27,     0,    28,    30,     0,     0,
      60,     0,    29,    40,    44,    46,    69,    43,     0,    23,
       0,     0,    25,    66,    19,     0,    35,    35,    49,    21,
      17,     0,     0,    45,    47
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     4,     9,    15,    10,    19,    56,    11,
      55,    83,    40,    66,    24,    41,    99,   100,    44,    45,
      20,    35,    36,    37,   146,   147,    38,    12,    13,    94,
      95
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -100
static const yytype_int16 yypact[] =
{
    -100,    17,  -100,  -100,   110,    26,  -100,     2,    30,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,    14,    33,    42,    20,
      99,    40,  -100,  -100,    68,     5,    45,  -100,  -100,    74,
       5,  -100,    88,    95,    11,  -100,   127,  -100,   129,  -100,
      68,   133,   112,   147,    61,  -100,   148,     9,  -100,  -100,
    -100,  -100,     5,    65,  -100,    68,    57,     5,    77,     5,
       5,     5,     5,   149,  -100,  -100,   138,    63,  -100,  -100,
    -100,   139,    68,   140,     5,   152,    98,     5,     5,     5,
       5,     5,  -100,   141,   104,    47,  -100,  -100,  -100,   108,
    -100,   118,   128,    -9,    -9,   106,     0,  -100,   143,   144,
     155,  -100,  -100,     5,   114,  -100,  -100,    55,   122,   122,
    -100,  -100,  -100,   146,   145,   150,   151,   153,  -100,     5,
       5,     5,   156,  -100,  -100,   160,   100,  -100,   157,   124,
    -100,   158,  -100,  -100,  -100,  -100,    -9,    -9,   126,  -100,
     159,    -5,  -100,  -100,  -100,   161,  -100,  -100,  -100,  -100,
    -100,    53,    54,  -100,  -100
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,   119,
    -100,  -100,  -100,  -100,  -100,  -100,   -94,  -100,   -30,   115,
     -99,  -100,  -100,  -100,  -100,  -100,  -100,   -50,  -100,   -25,
     -72
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      53,   126,   104,   122,    25,    58,    88,   128,    46,   120,
      67,    77,    78,    79,    80,    81,    16,     3,   131,    47,
      61,    48,    49,    50,    51,    84,    27,    76,   121,   140,
      17,   129,    89,    52,    91,    92,    93,    74,   145,    62,
      14,    75,    21,    63,    18,    22,    28,   151,   152,   138,
     127,    25,   107,   108,   109,   110,   111,    29,    29,    30,
      30,   114,    23,    32,    32,    33,    33,    34,    34,    39,
      26,    85,     8,    27,    54,    17,    78,    79,    80,    81,
     153,   154,    42,    43,    86,    77,    78,    79,    80,    81,
      71,    72,    98,    72,   136,   137,    82,    77,    78,    79,
      80,    81,    57,    29,    29,    30,    30,    31,    90,    32,
      32,    33,    33,    34,    34,     5,    59,     6,    77,    78,
      79,    80,    81,    60,     7,     8,    69,   106,    77,    78,
      79,    80,    81,   113,    72,   118,   119,   115,    77,    78,
      79,    80,    81,   130,   119,    80,    81,   116,    77,    78,
      79,    80,    81,   143,   119,   148,   119,   117,    64,    68,
      65,    70,    73,    96,    97,   101,   105,   112,   103,   123,
     125,   124,   132,    21,   141,    87,     0,   134,     0,   135,
       0,   133,     0,   139,   142,   144,   149,   102,   150
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-100)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      25,   100,    74,    97,     9,    30,    56,   101,     3,     9,
      40,    20,    21,    22,    23,    24,    14,     0,   112,    14,
       9,    16,    17,    18,    19,    55,    31,    52,    28,   123,
      28,   103,    57,    28,    59,    60,    61,    28,   132,    28,
      14,    32,    28,    32,    14,    31,    26,   146,   147,   121,
     100,     9,    77,    78,    79,    80,    81,     4,     4,     6,
       6,    14,    29,    10,    10,    12,    12,    14,    14,    29,
      28,    14,    15,    31,    29,    28,    21,    22,    23,    24,
      27,    27,    14,    15,    27,    20,    21,    22,    23,    24,
      29,    30,    29,    30,   119,   120,    31,    20,    21,    22,
      23,    24,    28,     4,     4,     6,     6,     8,    31,    10,
      10,    12,    12,    14,    14,     5,    28,     7,    20,    21,
      22,    23,    24,    28,    14,    15,    14,    29,    20,    21,
      22,    23,    24,    29,    30,    29,    30,    29,    20,    21,
      22,    23,    24,    29,    30,    23,    24,    29,    20,    21,
      22,    23,    24,    29,    30,    29,    30,    29,    31,    26,
      31,    14,    14,    14,    26,    26,    14,    26,    28,    26,
      15,    27,    26,    28,    14,    56,    -1,    26,    -1,    26,
      -1,    31,    -1,    27,    27,    27,    27,    72,    27
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    34,    35,     0,    36,     5,     7,    14,    15,    37,
      39,    42,    60,    61,    14,    38,    14,    28,    14,    40,
      53,    28,    31,    29,    47,     9,    28,    31,    26,     4,
       6,     8,    10,    12,    14,    54,    55,    56,    59,    29,
      45,    48,    14,    15,    51,    52,     3,    14,    16,    17,
      18,    19,    28,    62,    29,    43,    41,    28,    62,    28,
      28,     9,    28,    32,    31,    31,    46,    51,    26,    14,
      14,    29,    30,    14,    28,    32,    62,    20,    21,    22,
      23,    24,    31,    44,    51,    14,    27,    42,    60,    62,
      31,    62,    62,    62,    62,    63,    14,    26,    29,    49,
      50,    26,    52,    28,    63,    14,    29,    62,    62,    62,
      62,    62,    26,    29,    14,    29,    29,    29,    29,    30,
       9,    28,    49,    26,    27,    15,    53,    60,    49,    63,
      29,    49,    26,    31,    26,    26,    62,    62,    63,    27,
      49,    14,    27,    29,    27,    49,    57,    58,    29,    27,
      27,    53,    53,    27,    27
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

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

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
/* Line 1792 of yacc.c  */
#line 65 "limbaj.y"
    { 
          cout << "Program is correct. Generating recursive tables..." << endl;
          
          if (current) {
              current->printTableRecursive(tableFile);
          }
      }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 75 "limbaj.y"
    { enter_scope("Global"); }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 87 "limbaj.y"
    { enter_scope("Main"); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 87 "limbaj.y"
    { exit_scope(); }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 93 "limbaj.y"
    { 
        if(!current->addSymbol("class", *(yyvsp[(2) - (2)].Str), "class"))
            sem_error("Class " + *(yyvsp[(2) - (2)].Str) + " already defined.");
        
        SymTable::classRegistry[*(yyvsp[(2) - (2)].Str)] = {*(yyvsp[(2) - (2)].Str), {}};
        enter_scope("Class: " + *(yyvsp[(2) - (2)].Str)); 
      }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 101 "limbaj.y"
    { exit_scope(); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 113 "limbaj.y"
    { 
         if(!current->addSymbol(*(yyvsp[(1) - (3)].Str), *(yyvsp[(2) - (3)].Str), "function"))
            sem_error("Function " + *(yyvsp[(2) - (3)].Str) + " already defined.");
         currentFuncName = *(yyvsp[(2) - (3)].Str);
         enter_scope("Function: " + *(yyvsp[(2) - (3)].Str)); 
      }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 120 "limbaj.y"
    { currentFuncName = ""; exit_scope(); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 123 "limbaj.y"
    { 
         if(!current->addSymbol(*(yyvsp[(1) - (4)].Str), *(yyvsp[(2) - (4)].Str), "function"))
            sem_error("Function " + *(yyvsp[(2) - (4)].Str) + " already defined.");
         enter_scope("Function: " + *(yyvsp[(2) - (4)].Str)); 
      }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 129 "limbaj.y"
    { exit_scope(); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 132 "limbaj.y"
    { 
         if(!current->addSymbol(*(yyvsp[(1) - (3)].Str), *(yyvsp[(2) - (3)].Str), "function"))
            sem_error("Function " + *(yyvsp[(2) - (3)].Str) + " already defined.");
         currentFuncName = *(yyvsp[(2) - (3)].Str);
         enter_scope("Function: " + *(yyvsp[(2) - (3)].Str)); 
      }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 139 "limbaj.y"
    { currentFuncName = ""; exit_scope(); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 142 "limbaj.y"
    { 
         if(!current->addSymbol(*(yyvsp[(1) - (4)].Str), *(yyvsp[(2) - (4)].Str), "function"))
            sem_error("Function " + *(yyvsp[(2) - (4)].Str) + " already defined.");
         enter_scope("Function: " + *(yyvsp[(2) - (4)].Str)); 
      }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 148 "limbaj.y"
    { exit_scope(); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 151 "limbaj.y"
    { 
         current->addSymbol("class_type", *(yyvsp[(1) - (2)].Str), "constructor");
         currentFuncName = *(yyvsp[(1) - (2)].Str);
         enter_scope("Constructor: " + *(yyvsp[(1) - (2)].Str)); 
      }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 157 "limbaj.y"
    { currentFuncName = ""; exit_scope(); }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 160 "limbaj.y"
    { 
         current->addSymbol("class_type", *(yyvsp[(1) - (3)].Str), "constructor");
         enter_scope("Constructor: " + *(yyvsp[(1) - (3)].Str)); 
      }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 165 "limbaj.y"
    { exit_scope(); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 179 "limbaj.y"
    {
          if(!current->addSymbol(*(yyvsp[(1) - (2)].Str), *(yyvsp[(2) - (2)].Str), "param"))
             sem_error("Parameter " + *(yyvsp[(2) - (2)].Str) + " duplicated.");
          if(current->getParent() && currentFuncName != "")
              current->getParent()->addFuncParam(currentFuncName, *(yyvsp[(1) - (2)].Str));
      }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 186 "limbaj.y"
    {
          if(!current->addSymbol(*(yyvsp[(1) - (2)].Str), *(yyvsp[(2) - (2)].Str), "param"))
             sem_error("Parameter " + *(yyvsp[(2) - (2)].Str) + " duplicated.");
          if(current->getParent() && currentFuncName != "")
              current->getParent()->addFuncParam(currentFuncName, *(yyvsp[(1) - (2)].Str));
      }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 204 "limbaj.y"
    { /* Predefined function logic */ }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 210 "limbaj.y"
    { 
        IdInfo* info = current->getSymbolInfo(*(yyvsp[(1) - (3)].Str));
        if(!info) 
            sem_error("Variable " + *(yyvsp[(1) - (3)].Str) + " not declared!");
        else if(info->type != (yyvsp[(3) - (3)].EInfo)->type && (yyvsp[(3) - (3)].EInfo)->type != "error")
            sem_error("Type mismatch: cannot assign " + (yyvsp[(3) - (3)].EInfo)->type + " to " + info->type + " (" + *(yyvsp[(1) - (3)].Str) + ")");
        else
            current->updateValue(*(yyvsp[(1) - (3)].Str), (yyvsp[(3) - (3)].EInfo)->value);
      }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 221 "limbaj.y"
    {
          // 1. Verificăm dacă obiectul ($1) există
          IdInfo* objInfo = current->getSymbolInfo(*(yyvsp[(1) - (5)].Str));
          if(!objInfo) {
              sem_error("Object '" + *(yyvsp[(1) - (5)].Str) + "' is not declared.");
          } 
          else {
              string className = objInfo->type;

              // 2. Verificăm dacă clasa există în registru
              if(SymTable::classRegistry.count(className)) {
                  auto& members = SymTable::classRegistry[className].members;

                  // 3. Verificăm dacă membrul ($3) există în clasă
                  if(members.count(*(yyvsp[(3) - (5)].Str))) {
                      string fieldType = members[*(yyvsp[(3) - (5)].Str)].type;

                      // 4. Verificăm compatibilitatea de tip
                      if(fieldType != (yyvsp[(5) - (5)].EInfo)->type && (yyvsp[(5) - (5)].EInfo)->type != "error") {
                          sem_error("Type mismatch: Field '" + *(yyvsp[(3) - (5)].Str) + "' is " + fieldType + ", but expr is " + (yyvsp[(5) - (5)].EInfo)->type);
                      } else {
                          // --- LINIA LIPSA: AICI REALIZĂM ATRIBUIREA EFECTIVĂ ---
                          // Actualizăm valoarea în registrul de clase pentru ca tabelul să o poată printa
                          SymTable::classRegistry[className].members[*(yyvsp[(3) - (5)].Str)].value = (yyvsp[(5) - (5)].EInfo)->value;
                          current->updateValue(*(yyvsp[(3) - (5)].Str),(yyvsp[(5) - (5)].EInfo)->value);

                          
                          
                          cout << "[DEBUG] Assigned value " << (yyvsp[(5) - (5)].EInfo)->value << " to " << *(yyvsp[(1) - (5)].Str) << "." << *(yyvsp[(3) - (5)].Str) << endl;
                      }
                  } else {
                      sem_error("Class '" + className + "' does not have a member named '" + *(yyvsp[(3) - (5)].Str) + "'");
                  }
              } else {
                  sem_error("Variable '" + *(yyvsp[(1) - (5)].Str) + "' is not an object of a class.");
              }
          }
      }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 264 "limbaj.y"
    { enter_scope("If_Block"); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 264 "limbaj.y"
    { exit_scope(); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 265 "limbaj.y"
    { enter_scope("While_Block"); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 265 "limbaj.y"
    { exit_scope(); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 270 "limbaj.y"
    {
          IdInfo* info = current->getSymbolInfo(*(yyvsp[(1) - (4)].Str));
          if(!info) sem_error("Function " + *(yyvsp[(1) - (4)].Str) + " not defined.");
          else {
              if(info->paramTypes.size() != (yyvsp[(3) - (4)].ArgList)->size()) 
                  sem_error("Function " + *(yyvsp[(1) - (4)].Str) + " expects " + to_string(info->paramTypes.size()) + " args.");
              else {
                  for(size_t i=0; i<(yyvsp[(3) - (4)].ArgList)->size(); ++i)
                      if(info->paramTypes[i] != (*(yyvsp[(3) - (4)].ArgList))[i])
                          sem_error("Arg mismatch for " + *(yyvsp[(1) - (4)].Str));
              }
          }
      }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 284 "limbaj.y"
    {
          IdInfo* obj = current->getSymbolInfo(*(yyvsp[(1) - (6)].Str));
          if(!obj) sem_error("Object " + *(yyvsp[(1) - (6)].Str) + " undeclared.");
          else {
              string cls = obj->type;
              if(SymTable::classRegistry.count(cls)) {
                  if(!SymTable::classRegistry[cls].members.count(*(yyvsp[(3) - (6)].Str)))
                      sem_error("Member " + *(yyvsp[(3) - (6)].Str) + " not found in class " + cls);
              }
          }
      }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 299 "limbaj.y"
    { 
        if(!current->addSymbol(*(yyvsp[(1) - (3)].Str), *(yyvsp[(2) - (3)].Str), "variable"))
            sem_error("Variable " + *(yyvsp[(2) - (3)].Str) + " redeclared.");
      }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 304 "limbaj.y"
    { 
        if(*(yyvsp[(1) - (5)].Str) != (yyvsp[(4) - (5)].EInfo)->type && (yyvsp[(4) - (5)].EInfo)->type != "error")
            sem_error("Type mismatch in declaration of " + *(yyvsp[(2) - (5)].Str));
        if(!current->addSymbol(*(yyvsp[(1) - (5)].Str), *(yyvsp[(2) - (5)].Str), "variable", (yyvsp[(4) - (5)].EInfo)->value))
            sem_error("Variable " + *(yyvsp[(2) - (5)].Str) + " redeclared.");
      }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 314 "limbaj.y"
    { if(!current->addSymbol(*(yyvsp[(1) - (3)].Str), *(yyvsp[(2) - (3)].Str), "object")) sem_error("Object " + *(yyvsp[(2) - (3)].Str) + " redeclared."); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 318 "limbaj.y"
    {
        if((yyvsp[(1) - (3)].EInfo)->type != (yyvsp[(3) - (3)].EInfo)->type) { sem_error("Type mismatch: " + (yyvsp[(1) - (3)].EInfo)->type + " + " + (yyvsp[(3) - (3)].EInfo)->type); (yyval.EInfo) = new ExprInfo{"error",""}; }
        else (yyval.EInfo) = new ExprInfo{(yyvsp[(1) - (3)].EInfo)->type, ""};
    }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 322 "limbaj.y"
    {
        if((yyvsp[(1) - (3)].EInfo)->type != (yyvsp[(3) - (3)].EInfo)->type) { sem_error("Type mismatch: " + (yyvsp[(1) - (3)].EInfo)->type + " - " + (yyvsp[(3) - (3)].EInfo)->type); (yyval.EInfo) = new ExprInfo{"error",""}; }
        else (yyval.EInfo) = new ExprInfo{(yyvsp[(1) - (3)].EInfo)->type, ""};
    }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 326 "limbaj.y"
    {
        if((yyvsp[(1) - (3)].EInfo)->type != (yyvsp[(3) - (3)].EInfo)->type) { sem_error("Type mismatch: " + (yyvsp[(1) - (3)].EInfo)->type + " * " + (yyvsp[(3) - (3)].EInfo)->type); (yyval.EInfo) = new ExprInfo{"error",""}; }
        else (yyval.EInfo) = new ExprInfo{(yyvsp[(1) - (3)].EInfo)->type, ""};
    }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 330 "limbaj.y"
    {
        if((yyvsp[(1) - (3)].EInfo)->type != (yyvsp[(3) - (3)].EInfo)->type) { sem_error("Type mismatch: " + (yyvsp[(1) - (3)].EInfo)->type + " / " + (yyvsp[(3) - (3)].EInfo)->type); (yyval.EInfo) = new ExprInfo{"error",""}; }
        else (yyval.EInfo) = new ExprInfo{(yyvsp[(1) - (3)].EInfo)->type, ""};
    }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 334 "limbaj.y"
    {
        if((yyvsp[(1) - (3)].EInfo)->type != (yyvsp[(3) - (3)].EInfo)->type) { sem_error("Comparison type mismatch"); (yyval.EInfo) = new ExprInfo{"error",""}; }
        else (yyval.EInfo) = new ExprInfo{"bool", ""};
    }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 338 "limbaj.y"
    { (yyval.EInfo) = (yyvsp[(2) - (3)].EInfo); }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 339 "limbaj.y"
    {
        string t = current->getType(*(yyvsp[(1) - (1)].Str));
        IdInfo* info = current->getSymbolInfo(*(yyvsp[(1) - (1)].Str));
        string v = (info != nullptr) ? info->value : ""; // Preluăm valoarea actuală
        if(t == "") { sem_error("Undefined variable: " + *(yyvsp[(1) - (1)].Str)); t = "error"; }
        (yyval.EInfo) = new ExprInfo{t, v};
    }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 346 "limbaj.y"
    {
        IdInfo* info = current->getSymbolInfo(*(yyvsp[(1) - (4)].Str));
        if(!info) { sem_error("Function " + *(yyvsp[(1) - (4)].Str) + " undefined"); (yyval.EInfo) = new ExprInfo{"error",""}; }
        else (yyval.EInfo) = new ExprInfo{info->type, ""};
    }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 351 "limbaj.y"
    {
            // 1. Căutăm obiectul (masinaMea) în tabelele de scope (Main/Global)
            IdInfo* objInfo = current->getSymbolInfo(*(yyvsp[(1) - (3)].Str));
            if (!objInfo) {
                sem_error("Object " + *(yyvsp[(1) - (3)].Str) + " is not defined.");
                (yyval.EInfo) = new ExprInfo{"error", ""};
            } else {
                // 2. Aflăm tipul obiectului (Vehicul)
                string className = objInfo->type;

                // 3. Verificăm dacă acest tip există în registrul de clase
                if (SymTable::classRegistry.count(className)) {
                    // 4. Verificăm dacă membrul (marca) există în acea clasă
                    if (SymTable::classRegistry[className].members.count(*(yyvsp[(3) - (3)].Str))) {
                        IdInfo memberInfo = SymTable::classRegistry[className].members[*(yyvsp[(3) - (3)].Str)];
                        
                        // Returnăm tipul membrului și valoarea lui actuală
                        (yyval.EInfo) = new ExprInfo{memberInfo.type, memberInfo.value};
                    } else {
                        sem_error("Class " + className + " does not have member " + *(yyvsp[(3) - (3)].Str));
                        (yyval.EInfo) = new ExprInfo{"error", ""};
                    }
                } else {
                    sem_error(*(yyvsp[(1) - (3)].Str) + " is not an object of a defined class.");
                    (yyval.EInfo) = new ExprInfo{"error", ""};
                }
            }
        }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 379 "limbaj.y"
    { (yyval.EInfo) = new ExprInfo{"int", *(yyvsp[(1) - (1)].Str)}; }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 380 "limbaj.y"
    { (yyval.EInfo) = new ExprInfo{"float", *(yyvsp[(1) - (1)].Str)}; }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 381 "limbaj.y"
    { (yyval.EInfo) = new ExprInfo{"bool", *(yyvsp[(1) - (1)].Str)}; }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 382 "limbaj.y"
    { (yyval.EInfo) = new ExprInfo{"string", *(yyvsp[(1) - (1)].Str)}; }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 383 "limbaj.y"
    {
        if(SymTable::classRegistry.count(*(yyvsp[(2) - (5)].Str)) == 0) sem_error("Class " + *(yyvsp[(2) - (5)].Str) + " not defined");
        (yyval.EInfo) = new ExprInfo{*(yyvsp[(2) - (5)].Str), ""};
    }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 390 "limbaj.y"
    { (yyval.ArgList) = new vector<string>(); }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 391 "limbaj.y"
    { (yyval.ArgList) = new vector<string>(); (yyval.ArgList)->push_back((yyvsp[(1) - (1)].EInfo)->type); }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 392 "limbaj.y"
    { (yyvsp[(1) - (3)].ArgList)->push_back((yyvsp[(3) - (3)].EInfo)->type); (yyval.ArgList) = (yyvsp[(1) - (3)].ArgList); }
    break;


/* Line 1792 of yacc.c  */
#line 2010 "limbaj.tab.c"
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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


/* Line 2055 of yacc.c  */
#line 395 "limbaj.y"


void yyerror(const char* s) {
    cout << "Syntax Error: " << s << " at line: " << yylineno << endl;
}

int main(int argc, char** argv) {
    if (argc > 1) yyin = fopen(argv[1], "r");
    yyparse();
    tableFile.close();
    return 0;
}