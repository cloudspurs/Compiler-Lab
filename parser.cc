// A Bison parser, made by GNU Bison 3.0.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Take the name prefix into account.
#define yylex   compilerlex

// First part of user declarations.
#line 1 "parser.yy" // lalr1.cc:399
  
#include <stdio.h>
#include <string>
//#include <vector>
#include "node.h"

#line 45 "parser.cc" // lalr1.cc:399

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.h"

// User implementation prologue.
#line 68 "parser.yy" // lalr1.cc:407


#include "driver.h"
#include "scanner.h"
#include "node.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex
 

#line 72 "parser.cc" // lalr1.cc:407


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyempty = true)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace compiler {
#line 158 "parser.cc" // lalr1.cc:474

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
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
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  Parser::Parser (class Driver &driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  Parser::~Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  Parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::~basic_symbol ()
  {
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
  Parser::by_type::by_type ()
     : type (empty)
  {}

  inline
  Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.type = empty;
  }

  inline
  int
  Parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  Parser::by_state::by_state ()
    : state (empty)
  {}

  inline
  Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  Parser::symbol_number_type
  Parser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty;
  }

  inline
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    switch (yysym.type_get ())
    {
            case 23: // STRING

#line 65 "parser.yy" // lalr1.cc:599
        { delete (yysym.value.var); }
#line 377 "parser.cc" // lalr1.cc:599
        break;

      case 26: // stmt

#line 65 "parser.yy" // lalr1.cc:599
        { delete (yysym.value.stmt); }
#line 384 "parser.cc" // lalr1.cc:599
        break;

      case 27: // cal

#line 65 "parser.yy" // lalr1.cc:599
        { delete (yysym.value.cal); }
#line 391 "parser.cc" // lalr1.cc:599
        break;

      case 28: // exp

#line 65 "parser.yy" // lalr1.cc:599
        { delete (yysym.value.exp); }
#line 398 "parser.cc" // lalr1.cc:599
        break;

      case 29: // term

#line 65 "parser.yy" // lalr1.cc:599
        { delete (yysym.value.exp); }
#line 405 "parser.cc" // lalr1.cc:599
        break;

      case 30: // factor

#line 65 "parser.yy" // lalr1.cc:599
        { delete (yysym.value.exp); }
#line 412 "parser.cc" // lalr1.cc:599
        break;

      case 31: // num

#line 65 "parser.yy" // lalr1.cc:599
        { delete (yysym.value.exp); }
#line 419 "parser.cc" // lalr1.cc:599
        break;

      case 32: // variable

#line 65 "parser.yy" // lalr1.cc:599
        { delete (yysym.value.exp); }
#line 426 "parser.cc" // lalr1.cc:599
        break;


      default:
        break;
    }
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  Parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::parse ()
  {
    /// Whether yyla contains a lookahead.
    bool yyempty = true;

    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    // User initialization code.
    #line 30 "parser.yy" // lalr1.cc:725
{
    // initialize the initial location object
    yyla.location.begin.filename = yyla.location.end.filename = &driver.streamname;
}

#line 563 "parser.cc" // lalr1.cc:725

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyempty)
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
        yyempty = false;
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Discard the token being shifted.
    yyempty = true;

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 84 "parser.yy" // lalr1.cc:847
    { (yylhs.value.stmt) = new Iftst("IF", (yystack_[2].value.cal), (yystack_[0].value.stmt)); }
#line 677 "parser.cc" // lalr1.cc:847
    break;

  case 3:
#line 85 "parser.yy" // lalr1.cc:847
    {(yylhs.value.stmt) = new Ifst("IF", (yystack_[4].value.cal), (yystack_[2].value.stmt), (yystack_[0].value.stmt)); }
#line 683 "parser.cc" // lalr1.cc:847
    break;

  case 4:
#line 86 "parser.yy" // lalr1.cc:847
    { (yylhs.value.stmt) = new Whst("WHILE", (yystack_[2].value.cal), (yystack_[0].value.stmt)); }
#line 689 "parser.cc" // lalr1.cc:847
    break;

  case 5:
#line 87 "parser.yy" // lalr1.cc:847
    { (yylhs.value.stmt) = (Stmt*)(yystack_[0].value.exp); }
#line 695 "parser.cc" // lalr1.cc:847
    break;

  case 6:
#line 88 "parser.yy" // lalr1.cc:847
    {
		if ((yystack_[0].value.stmt) == NULL)
			(yylhs.value.stmt) = (yystack_[2].value.stmt);
		else 
			driver.ast.node.push_back((yystack_[0].value.stmt));
	}
#line 706 "parser.cc" // lalr1.cc:847
    break;

  case 7:
#line 95 "parser.yy" // lalr1.cc:847
    { (yylhs.value.cal) = new Cal(">", (yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 712 "parser.cc" // lalr1.cc:847
    break;

  case 8:
#line 96 "parser.yy" // lalr1.cc:847
    { (yylhs.value.cal) = new Cal("<", (yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 718 "parser.cc" // lalr1.cc:847
    break;

  case 9:
#line 97 "parser.yy" // lalr1.cc:847
    { (yylhs.value.cal) = new Cal("==", (yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 724 "parser.cc" // lalr1.cc:847
    break;

  case 11:
#line 102 "parser.yy" // lalr1.cc:847
    { (yylhs.value.exp) = new Binary("+", (yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 730 "parser.cc" // lalr1.cc:847
    break;

  case 12:
#line 103 "parser.yy" // lalr1.cc:847
    { (yylhs.value.exp) = new Binary("-", (yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 736 "parser.cc" // lalr1.cc:847
    break;

  case 13:
#line 104 "parser.yy" // lalr1.cc:847
    { (yylhs.value.exp) = new Assign("=", (yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 742 "parser.cc" // lalr1.cc:847
    break;

  case 15:
#line 108 "parser.yy" // lalr1.cc:847
    { (yylhs.value.exp) = new Binary("*", (yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 748 "parser.cc" // lalr1.cc:847
    break;

  case 16:
#line 109 "parser.yy" // lalr1.cc:847
    { (yylhs.value.exp) = new Binary("/", (yystack_[2].value.exp), (yystack_[0].value.exp)); }
#line 754 "parser.cc" // lalr1.cc:847
    break;

  case 19:
#line 114 "parser.yy" // lalr1.cc:847
    { (yylhs.value.exp) = new Unary("-", (yystack_[0].value.exp)); }
#line 760 "parser.cc" // lalr1.cc:847
    break;

  case 20:
#line 115 "parser.yy" // lalr1.cc:847
    { (yylhs.value.exp) = new Unary("|", (yystack_[0].value.exp)); }
#line 766 "parser.cc" // lalr1.cc:847
    break;

  case 21:
#line 116 "parser.yy" // lalr1.cc:847
    { (yylhs.value.exp) = (yystack_[1].value.exp); }
#line 772 "parser.cc" // lalr1.cc:847
    break;

  case 22:
#line 119 "parser.yy" // lalr1.cc:847
    { (yylhs.value.exp) = new Number((yystack_[0].value.num)); }
#line 778 "parser.cc" // lalr1.cc:847
    break;

  case 23:
#line 122 "parser.yy" // lalr1.cc:847
    { (yylhs.value.exp) = new Variable(*(yystack_[0].value.var)); }
#line 784 "parser.cc" // lalr1.cc:847
    break;

  case 27:
#line 129 "parser.yy" // lalr1.cc:847
    {
		driver.ast.node.push_back((yystack_[1].value.exp));
	}
#line 792 "parser.cc" // lalr1.cc:847
    break;

  case 28:
#line 133 "parser.yy" // lalr1.cc:847
    {
			driver.ast.node.push_back((yystack_[1].value.exp));
	}
#line 800 "parser.cc" // lalr1.cc:847
    break;

  case 29:
#line 137 "parser.yy" // lalr1.cc:847
    {
		driver.ast.node.push_back((yystack_[1].value.exp));
	}
#line 808 "parser.cc" // lalr1.cc:847
    break;

  case 30:
#line 141 "parser.yy" // lalr1.cc:847
    {
		driver.ast.node.push_back((yystack_[1].value.cal));
	}
#line 816 "parser.cc" // lalr1.cc:847
    break;

  case 31:
#line 145 "parser.yy" // lalr1.cc:847
    {
		driver.ast.node.push_back((yystack_[1].value.cal));
	}
#line 824 "parser.cc" // lalr1.cc:847
    break;

  case 32:
#line 149 "parser.yy" // lalr1.cc:847
    {
		driver.ast.node.push_back((yystack_[1].value.cal));
	}
#line 832 "parser.cc" // lalr1.cc:847
    break;

  case 33:
#line 153 "parser.yy" // lalr1.cc:847
    {
		driver.ast.node.push_back((yystack_[0].value.stmt));
	}
#line 840 "parser.cc" // lalr1.cc:847
    break;

  case 34:
#line 157 "parser.yy" // lalr1.cc:847
    {
		driver.ast.node.push_back((yystack_[1].value.stmt));
	}
#line 848 "parser.cc" // lalr1.cc:847
    break;

  case 35:
#line 161 "parser.yy" // lalr1.cc:847
    {
		driver.ast.node.push_back((yystack_[1].value.stmt));
	}
#line 856 "parser.cc" // lalr1.cc:847
    break;


#line 860 "parser.cc" // lalr1.cc:847
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state,
                                           yyempty ? yyempty_ : yyla.type_get ()));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyempty)
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyempty = true;
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyempty)
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyempty)
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, symbol_number_type yytoken) const
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -28;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
     -28,    43,   -28,   -28,    47,    47,    47,    47,    47,   -28,
     -28,   -28,    26,    16,    10,    70,   -28,   -28,    -6,   -28,
     -28,   -28,    68,    11,     7,    22,   -28,   -28,    52,   -28,
     -28,   -28,   -28,   -28,    47,    47,    47,    47,    47,   -28,
      47,    47,    47,   -28,    52,    52,    32,    45,    70,    70,
      45,    45,    45,   -28,   -28,    45,     9,    32,    52,    32
  };

  const unsigned char
  Parser::yydefact_[] =
  {
      24,     0,     1,    26,     0,     0,     0,     0,     0,    22,
      23,    25,    33,     0,     5,    10,    14,    17,    18,    19,
      18,    20,     0,     0,     0,     0,    35,    34,     0,    32,
      31,    30,    29,    28,     0,     0,     0,     0,     0,    27,
       0,     0,     0,    21,     0,     0,     6,     5,    11,    12,
       7,     8,     9,    15,    16,    13,     2,     4,     0,     3
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -28,   -27,    71,    -1,    48,     4,   -28,    -2,   -28
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,    12,    13,    47,    15,    16,    17,    18,     1
  };

  const unsigned char
  Parser::yytable_[] =
  {
      14,    46,    20,    20,    42,    22,    24,    24,    19,    21,
      32,    34,    35,    33,    34,    35,    29,    56,    57,    30,
      36,    37,    38,    36,    37,    38,    26,    58,    44,    27,
      28,    59,    20,    20,    39,    50,    51,    52,    20,    20,
      31,    55,    45,     2,    53,    54,     3,    28,     4,    34,
      35,     5,     4,    28,     6,     5,     0,     4,     6,     7,
       5,     0,     8,     6,     0,     9,    10,    11,     7,     9,
      10,     8,    34,    35,     9,    10,    40,    41,    23,    25,
      43,     0,    48,    49
  };

  const signed char
  Parser::yycheck_[] =
  {
       1,    28,     4,     5,    10,     6,     7,     8,     4,     5,
       0,     4,     5,     3,     4,     5,     0,    44,    45,     3,
      13,    14,    15,    13,    14,    15,     0,    18,    17,     3,
      21,    58,    34,    35,    24,    36,    37,    38,    40,    41,
      24,    42,    20,     0,    40,    41,     3,    21,     5,     4,
       5,     8,     5,    21,    11,     8,    -1,     5,    11,    16,
       8,    -1,    19,    11,    -1,    22,    23,    24,    16,    22,
      23,    19,     4,     5,    22,    23,     6,     7,     7,     8,
      12,    -1,    34,    35
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,    33,     0,     3,     5,     8,    11,    16,    19,    22,
      23,    24,    26,    27,    28,    29,    30,    31,    32,    30,
      32,    30,    28,    27,    28,    27,     0,     3,    21,     0,
       3,    24,     0,     3,     4,     5,    13,    14,    15,    24,
       6,     7,    10,    12,    17,    20,    26,    28,    29,    29,
      28,    28,    28,    30,    30,    28,    26,    26,    18,    26
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    25,    26,    26,    26,    26,    26,    27,    27,    27,
      28,    28,    28,    28,    29,    29,    29,    30,    30,    30,
      30,    30,    31,    32,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    33,    33
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     4,     6,     4,     1,     3,     3,     3,     3,
       1,     3,     3,     3,     1,     3,     3,     1,     1,     2,
       2,     3,     1,     1,     0,     2,     2,     3,     3,     3,
       3,     3,     3,     2,     3,     3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "END", "error", "$undefined", "EOL", "ADD", "SUB", "MUL", "DIV", "ABS",
  "MINUS", "ASSIGN", "LBR", "RBR", "GR", "LR", "EQUAL", "IF", "THEN",
  "ELSE", "WHILE", "DO", "AND", "INTEGER", "STRING", "';'", "$accept",
  "stmt", "cal", "exp", "term", "factor", "num", "variable", "start", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  Parser::yyrline_[] =
  {
       0,    84,    84,    85,    86,    87,    88,    95,    96,    97,
     101,   102,   103,   104,   107,   108,   109,   112,   113,   114,
     115,   116,   119,   122,   126,   127,   128,   129,   133,   137,
     141,   145,   149,   153,   157,   161
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    24,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23
    };
    const unsigned int user_token_number_max_ = 278;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // compiler
#line 1313 "parser.cc" // lalr1.cc:1155
#line 165 "parser.yy" // lalr1.cc:1156


// 错误处理函数
void compiler::Parser::error(const Parser::location_type &l,
			     const std::string &m) {
    driver.error(l, m);
}
