/* A Bison parser, made by GNU Bison 3.2.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.2.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.go.y" /* yacc.c:338  */

package main

import (
  "errors"

  "fmt"
  "github.com/simelo/rextporter/src/config"
  "github.com/simelo/rextporter/src/core"
  // "github.com/davecgh/go-spew/spew"
  // "github.com/simelo/rextporter/src/util"
)

var (
  ErrBlockLevelUnderflow = errors.New("End of block is not possible beyond DATABASE")
  ErrBlockLevelOverflow  = errors.New("Too many nested syntax levels")
)

type parserEnv struct {
  env       core.RextEnv
  scraper   core.RextServiceScraper 
}

type strTuple struct {
  key  string
  val  string
}

type mainSecTuple struct {
  src  core.RextDataSource
  key  string
  val  interface{}
}

type metricDef struct {
  mname string
  mtype string
  mdesc string
  mlbls []string
  opts  core.RextKeyValueStore
}

// FIXME : Not global. Parser stack ? TLS ?
var root    parserEnv
var metric  metricDef

// TODO: metricDef should implement core.RextMetricDef

func value_for_str(str string) string {
  // FIXME: Support string literals
  return str[1: len(str) - 1]
}

func newOption() core.RextKeyValueStore {
  return config.NewOptionsMap()
}

func newStrTuple(s1, s2 string) *strTuple {
  return &strTuple {
    key:  s1,
    val: s2,
  }
}

func newMainDef(key string, value interface{}) *mainSecTuple {
  return &mainSecTuple{
    src: nil,
    key: key,
    val: value,
  }
}

func newMainSrc(src core.RextDataSource) *mainSecTuple {
  return &mainSecTuple{
    src: src,
    key: "",
    val: nil,
  }
}

func getRootEnv() *parserEnv {
  return &root
}

func (m *metricDef) GetMetricName() string {
  return m.mname
}

func (m *metricDef) GetMetricType() string {
  return m.mtype
}

func (m *metricDef) GetMetricDescription() string {
  return m.mdesc
}

func (m *metricDef) GetMetricLabels() []string {
  return m.mlbls
}

func (m *metricDef) SetMetricName(name string) {
  m.mname = name
}

func (m *metricDef) SetMetricType(typeid string) {
  m.mtype = typeid
}

func (m *metricDef) SetMetricDescription(desc string) {
  m.mdesc = desc
}

func (m *metricDef) SetMetricLabels(labels []string) {
  m.mlbls = labels
}

func (m *metricDef) GetOptions() core.RextKeyValueStore {
  return nil
}


#line 191 "parser.go.tab.c" /* yacc.c:338  */
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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    COUNTER = 258,
    GAUGE = 259,
    HISTOGRAM = 260,
    SUMMARY = 261,
    COMMA = 262,
    STR_LITERAL = 263,
    AS = 264,
    BIE = 265,
    BLK = 266,
    EOB = 267,
    EOL = 268,
    CTX = 269,
    DATASET = 270,
    DEFINE_AUTH = 271,
    DESCRIPTION = 272,
    EXTRACT_USING = 273,
    FOR_SERVICE = 274,
    FOR_STACK = 275,
    FROM = 276,
    HELP = 277,
    GET = 278,
    IDENTIFIER = 279,
    LABELS = 280,
    METRIC = 281,
    NAME = 282,
    POST = 283,
    RESOURCE_PATH = 284,
    SET = 285,
    TO = 286,
    TYPE = 287
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 123 "parser.go.y" /* yacc.c:353  */

  root    core.RextServiceScraper
  options core.RextKeyValueStore
  mains   []mainSecTuple
  mainsec *mainSecTuple
  exts    []core.RextMetricsExtractor
  extract core.RextMetricsExtractor
  metrics []core.RextMetricDef
  metric  core.RextMetricDef
  key     string
  strval  string
  strlist []string
  pair    *strTuple
  identVal int

#line 280 "parser.go.tab.c" /* yacc.c:353  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





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
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   63

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  87

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   183,   183,   186,   188,   191,   193,   195,   197,   200,
     205,   207,   223,   225,   229,   231,   233,   236,   239,   242,
     246,   247,   250,   251,   253,   265,   267,   269,   277,   279,
     283,   285,   289,   296,   305,   326,   330,   331,   334,   337,
     338,   340,   342,   344,   346,   348,   349,   350
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COUNTER", "GAUGE", "HISTOGRAM",
  "SUMMARY", "COMMA", "STR_LITERAL", "AS", "BIE", "BLK", "EOB", "EOL",
  "CTX", "DATASET", "DEFINE_AUTH", "DESCRIPTION", "EXTRACT_USING",
  "FOR_SERVICE", "FOR_STACK", "FROM", "HELP", "GET", "IDENTIFIER",
  "LABELS", "METRIC", "NAME", "POST", "RESOURCE_PATH", "SET", "TO", "TYPE",
  "$accept", "defverb", "srcverb", "mtvalue", "id", "setcls", "optsblk",
  "idlst", "mname", "mtype", "mhelp", "mhelpo", "mlablso", "optblkl",
  "optblkr", "metsec", "metblk", "extblk", "ssec", "srcsecsufixo",
  "srcsecsufix", "srcsec", "defsec", "srvstk", "srvstko", "srvcls",
  "srvclso", "mainsec", "mainblk", "eolo", "dataset", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287
};
# endif

#define YYPACT_NINF -46

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-46)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -7,   -46,    -5,    15,     5,   -46,    -2,    -6,     6,     0,
     -46,   -46,    14,   -46,    -6,     9,    -3,    -6,    14,   -46,
      16,   -46,    10,   -16,   -46,     2,   -46,   -46,   -46,   -46,
       4,     7,   -46,   -46,   -46,    12,    18,    20,    11,   -16,
     -46,    22,     8,   -46,   -46,    23,    -3,   -46,   -46,    17,
      28,   -46,    -4,    27,   -46,    17,    -3,   -46,    13,    29,
     -46,     1,    19,   -46,    13,    33,    30,   -46,   -46,    21,
      -1,    31,   -46,   -46,   -46,   -46,   -46,    25,   -46,    34,
     -46,    32,   -46,    -3,    36,   -46,   -46
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      45,    46,     0,     0,     0,     1,    39,     0,     0,    36,
       9,    12,    38,    40,     0,     0,    22,     0,    35,    37,
       0,    11,     0,     0,    13,     0,    23,     2,     3,     4,
       0,     0,    42,    41,    43,    47,     0,     0,     0,     0,
      10,     0,     0,    44,    34,    30,    22,    33,    31,     0,
       0,    28,     0,     0,    32,     0,    22,    29,     0,     0,
      25,     0,     0,    27,     0,     0,     0,    26,    14,     0,
       0,    17,     6,     5,     7,     8,    15,     0,    19,     0,
      18,    20,    16,     0,     0,    21,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -46,   -46,   -46,   -46,    35,   -46,   -34,    37,   -46,   -46,
     -46,   -46,   -46,   -46,   -45,   -14,   -46,     3,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,   -46,   -46,    24,   -46,   -46,
     -46
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    30,    31,    76,    11,    21,    22,    12,    66,    71,
      80,    78,    81,    84,    23,    60,    61,    51,    52,    47,
      48,    32,    33,    15,    16,     8,     9,    34,    35,     2,
       3
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      27,    49,    72,    73,    74,    75,     1,    28,    54,    55,
       4,    58,    29,    63,    64,     5,     6,     7,    10,    13,
      14,    17,    19,    26,    25,    39,    40,    20,    37,    41,
      44,    38,    42,    36,    46,    50,    53,    45,    56,    59,
      62,    68,    82,    69,    77,    83,    65,    79,    86,    85,
      67,    18,    24,    70,     0,     0,     0,     0,    57,     0,
       0,     0,     0,    43
};

static const yytype_int8 yycheck[] =
{
      16,    46,     3,     4,     5,     6,    13,    23,    12,    13,
      15,    56,    28,    12,    13,     0,    11,    19,    24,    13,
      20,     7,    13,    13,     8,    13,     8,    30,    24,     9,
       8,    24,    21,    31,    11,    18,     8,    29,    11,    26,
      11,     8,     8,    13,    13,    13,    27,    22,    12,    83,
      64,    14,    17,    32,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    62,    63,    15,     0,    11,    19,    58,    59,
      24,    37,    40,    13,    20,    56,    57,     7,    40,    13,
      30,    38,    39,    47,    37,     8,    13,    16,    23,    28,
      34,    35,    54,    55,    60,    61,    31,    24,    24,    13,
       8,     9,    21,    60,     8,    29,    11,    52,    53,    47,
      18,    50,    51,     8,    12,    13,    11,    50,    47,    26,
      48,    49,    11,    12,    13,    27,    41,    48,     8,    13,
      32,    42,     3,     4,     5,     6,    36,    13,    44,    22,
      43,    45,     8,    13,    46,    39,    12
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    35,    35,    36,    36,    36,    36,    37,
      38,    39,    40,    40,    41,    42,    43,    44,    44,    45,
      46,    46,    47,    47,    48,    49,    49,    50,    51,    51,
      52,    52,    53,    54,    55,    56,    57,    57,    58,    59,
      59,    60,    60,    61,    61,    62,    62,    63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     1,     3,     2,     2,     2,     0,     2,     0,
       0,     2,     0,     2,     9,     1,     3,     6,     1,     3,
       0,     1,     4,     5,     4,     2,     0,     2,     2,     0,
       2,     1,     1,     1,     3,     0,     1,     7
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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
    default: /* Avoid compiler warnings. */
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

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
                  (unsigned long) yystacksize));

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
      yychar = yylex ();
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
        case 2:
#line 184 "parser.go.y" /* yacc.c:1645  */
    { (yyval.key) = "AUTH" }
#line 1419 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 3:
#line 187 "parser.go.y" /* yacc.c:1645  */
    { (yyval.key) = (yyvsp[0].key) }
#line 1425 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 4:
#line 189 "parser.go.y" /* yacc.c:1645  */
    { (yyval.key) = (yyvsp[0].key) }
#line 1431 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 5:
#line 192 "parser.go.y" /* yacc.c:1645  */
    { (yyval.key) = config.KeyMetricTypeGauge }
#line 1437 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 6:
#line 194 "parser.go.y" /* yacc.c:1645  */
    { (yyval.key) = config.KeyMetricTypeCounter }
#line 1443 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 7:
#line 196 "parser.go.y" /* yacc.c:1645  */
    { (yyval.key) = config.KeyMetricTypeHistogram }
#line 1449 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 8:
#line 198 "parser.go.y" /* yacc.c:1645  */
    { (yyval.key) = config.KeyMetricTypeSummary }
#line 1455 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 9:
#line 201 "parser.go.y" /* yacc.c:1645  */
    { (yyval.strval) = (yyvsp[0].strval) }
#line 1461 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 10:
#line 206 "parser.go.y" /* yacc.c:1645  */
    { (yyval.pair) = newStrTuple((yyvsp[-2].strval), (yyvsp[0].strval)) }
#line 1467 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 11:
#line 208 "parser.go.y" /* yacc.c:1645  */
    {
            (yyval.options) = newOption()
            // TODO: Error handling
            _, _ = (yyval.options).SetString((yyvsp[0].pair).key, (yyvsp[0].pair).val)
          }
#line 1477 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 12:
#line 224 "parser.go.y" /* yacc.c:1645  */
    { (yyval.strlist) = []string{ (yyvsp[0].strval) } }
#line 1483 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 13:
#line 226 "parser.go.y" /* yacc.c:1645  */
    { (yyval.strlist) = append((yyvsp[-2].strlist), (yyvsp[0].strval)) }
#line 1489 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 14:
#line 230 "parser.go.y" /* yacc.c:1645  */
    { (yyval.strval) = (yyvsp[0].strval) }
#line 1495 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 15:
#line 232 "parser.go.y" /* yacc.c:1645  */
    { (yyval.strval) = (yyvsp[0].key) }
#line 1501 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 16:
#line 234 "parser.go.y" /* yacc.c:1645  */
    { (yyval.strval) = (yyvsp[0].strval) }
#line 1507 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 17:
#line 236 "parser.go.y" /* yacc.c:1645  */
    {
            (yyval.strval) = "Metric extracted by [rextporter](https://github.com/simelo/rextporter)"
          }
#line 1515 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 18:
#line 240 "parser.go.y" /* yacc.c:1645  */
    { (yyval.strval) = (yyvsp[0].strval) }
#line 1521 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 19:
#line 242 "parser.go.y" /* yacc.c:1645  */
    { (yyval.strlist) = nil }
#line 1527 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 20:
#line 246 "parser.go.y" /* yacc.c:1645  */
    { (yyval.options) = nil }
#line 1533 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 21:
#line 248 "parser.go.y" /* yacc.c:1645  */
    { (yyval.options) = (yyvsp[0].options) }
#line 1539 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 22:
#line 250 "parser.go.y" /* yacc.c:1645  */
    { (yyval.options) = nil }
#line 1545 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 23:
#line 252 "parser.go.y" /* yacc.c:1645  */
    { (yyval.options) = (yyvsp[-1].options) }
#line 1551 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 24:
#line 254 "parser.go.y" /* yacc.c:1645  */
    {
            mm := metricDef{
              mname: (yyvsp[-6].strval),
              mtype: (yyvsp[-4].strval),
              mdesc: (yyvsp[-3].strval),
              mlbls: (yyvsp[-2].strlist),
              opts:  (yyvsp[-1].options),
            }
            fmt.Println(mm)
            (yyval.metric) = nil
          }
#line 1567 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 25:
#line 266 "parser.go.y" /* yacc.c:1645  */
    { (yyval.metrics) = nil; /*[]metricDef{ $1 }*/ }
#line 1573 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 26:
#line 268 "parser.go.y" /* yacc.c:1645  */
    { (yyval.metrics) = append((yyvsp[-2].metrics), (yyvsp[0].metric)) }
#line 1579 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 27:
#line 270 "parser.go.y" /* yacc.c:1645  */
    {
            // env := getRootEnv()
            (yyval.extract) = nil //env.NewMetricsExtractor($2, $4, $5)
            // for _, md := range $6 {
            //   $$.AddMetricRule(&md)
            // }
          }
#line 1591 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 28:
#line 278 "parser.go.y" /* yacc.c:1645  */
    { (yyval.exts) = []core.RextMetricsExtractor{ (yyvsp[0].extract) } }
#line 1597 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 29:
#line 280 "parser.go.y" /* yacc.c:1645  */
    { (yyval.exts) = append((yyvsp[-2].exts), (yyvsp[0].extract)) }
#line 1603 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 30:
#line 283 "parser.go.y" /* yacc.c:1645  */
    { (yyval.exts) = nil }
#line 1609 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 31:
#line 286 "parser.go.y" /* yacc.c:1645  */
    { 
                 (yyval.exts) = (yyvsp[0].exts)
               }
#line 1617 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 32:
#line 290 "parser.go.y" /* yacc.c:1645  */
    {
                // FIXME: Error handling
                // _ = util.MergeStoresInplace(dsGetOptions(), $2)
                (yyval.exts) = (yyvsp[-1].exts)
             }
#line 1627 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 33:
#line 297 "parser.go.y" /* yacc.c:1645  */
    {
            // env := getRootEnv()
            // ds := env.NewMetricsDataSource($2)
            // dsSetMethod($1)
            // dsSetLocation($4)
            // $$ = newMainSrc(ds)
            (yyval.mainsec) = (yyvsp[-4].key)
          }
#line 1640 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 34:
#line 306 "parser.go.y" /* yacc.c:1645  */
    {
            // env := getRootEnv()
            // if defverb == 'AUTH' {
            //   $$ = newMainDef($4, env.NewAuthStrategy($2, $5))
            // }
            // TODO: Error handling
            (yyval.mainsec) = nil
          }
#line 1653 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 35:
#line 327 "parser.go.y" /* yacc.c:1645  */
    { (yyval.strlist) = (yyvsp[0].strlist) }
#line 1659 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 36:
#line 330 "parser.go.y" /* yacc.c:1645  */
    { (yyval.strlist) = nil }
#line 1665 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 37:
#line 332 "parser.go.y" /* yacc.c:1645  */
    { (yyval.strlist) = (yyvsp[-1].strlist) }
#line 1671 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 38:
#line 335 "parser.go.y" /* yacc.c:1645  */
    { (yyval.strlist) = (yyvsp[0].strlist) }
#line 1677 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 39:
#line 337 "parser.go.y" /* yacc.c:1645  */
    { (yyval.strlist) = nil }
#line 1683 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 40:
#line 339 "parser.go.y" /* yacc.c:1645  */
    { (yyval.strlist) = (yyvsp[-1].strlist) }
#line 1689 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 41:
#line 341 "parser.go.y" /* yacc.c:1645  */
    { (yyval.mainsec) = (yyvsp[0].mainsec) }
#line 1695 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 42:
#line 343 "parser.go.y" /* yacc.c:1645  */
    { (yyval.mainsec) = (yyvsp[0].mainsec) }
#line 1701 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 43:
#line 345 "parser.go.y" /* yacc.c:1645  */
    { (yyval.mains) = nil /*[]mainSecTuple { $1 }*/ }
#line 1707 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 44:
#line 347 "parser.go.y" /* yacc.c:1645  */
    { (yyval.mains) = nil; /*append($1, $3)*/ }
#line 1713 "parser.go.tab.c" /* yacc.c:1645  */
    break;

  case 47:
#line 351 "parser.go.y" /* yacc.c:1645  */
    {
            // env = $1
            // $$ = env.NewServiceScraper()
            // if $5 != nil {
            //   // TODO : Error handling
            //   _ = env.RegisterScraperForServices($5...)
            // }
            // if $6 != nil {
            //   // TODO : Error handling
            //   _ = env.RegisterScraperForServices($6...)
            // }
            // if $7 != nil {
            //   util.MergeStoresInplace($$.GetOptions(), $7)
            // }
            // for _, mainsec := range $8 {
            //   if mainsec.src != nil {
            //     $$.AddSource(mainsec.src)
            //   } else if mainsec.value != nil {
            //     if auth, isAuth := mainsec.value.(core.RextAuth); isAuth {
            //       $$.AddAuthStrategy(auth, mainsec.key)
            //     }
            //     // TODO : Error handling
            //   }
            //   // TODO : Error handling
            // }
          }
#line 1744 "parser.go.tab.c" /* yacc.c:1645  */
    break;


#line 1748 "parser.go.tab.c" /* yacc.c:1645  */
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 377 "parser.go.y" /* yacc.c:1903  */

