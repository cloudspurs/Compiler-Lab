%{ 
#include <string>
#include "scanner.h"

/* import the parser's token type into a local typedef */
typedef compiler::Parser::token token;
typedef compiler::Parser::token_type token_type;

/* By default yylex returns int, we use token_type. Unfortunately yyterminate
 * by default returns 0, which is not of token_type. */
#define yyterminate() return token::END

/* This disables inclusion of unistd.h, which is not available under Visual C++
 * on Win32. The C++ scanner uses STL streams instead. */
#define YY_NO_UNISTD_H
%}

/*** Flex Declarations and Options ***/

/* enable c++ scanner class generation */
%option c++

/* change the name of the scanner class. results in "CompilerFlexLexer" */
%option prefix="Compiler"

/* the manual says "somewhat more optimized" */
%option batch

/* enable scanner to generate debug output. disable this for release
 * versions. */
%option debug

/* no support for include files is planned */
%option yywrap nounput 

/* enables the use of start condition stacks */
%option stack

/* The following paragraph suffices to track locations accurately. Each time
 * yylex is invoked, the begin position is moved onto the end position. */
%{
#define YY_USER_ACTION  yylloc->columns(yyleng);
%}

%% 

 /* code to place at the beginning of yylex() */
%{
    yylloc->step();
%}

"="	{ std::cout<<"Assign : "<<yytext<<std::endl; 	return token::ASSIGN; }
"+"	{ std::cout<<"ADD : "<<yytext<<std::endl; 	return token::ADD; }
"-"	{ std::cout<<"SUB : "<<yytext<<std::endl; 	return token::SUB; }
"*"	{ std::cout<<"MUL : "<<yytext<<std::endl;	return token::MUL; }
"/"	{ std::cout<<"DIV : "<<yytext<<std::endl; 	return token::DIV; }
"|"	{ std::cout<<"ABS : "<<yytext<<std::endl;	return token::ABS; }
"("	{ std::cout<<"LBR : "<<yytext<<std::endl;	return token::LBR; }
")"	{ std::cout<<"RBR : "<<yytext<<std::endl;	return token::RBR; }
">"	{ std::cout<<"GR : "<<yytext<<std::endl;	return token::GR; }
"<"	{ std::cout<<"LR : "<<yytext<<std::endl;	return token::LR; }
"=="	{ std::cout<<"EQUAL : "<<yytext<<std::endl;	return token::EQUAL; }
";"	{ std::cout<<"AND : "<<yytext<<std::endl;	return token::AND; }

"if"	{ std::cout<<"WKIF"<<std::endl; 	return token::IF; }
"then"	{ std::cout<<"KWTHEN"<<std::endl; 	return token::THEN; }
"else"	{ std::cout<<"KWELSE"<<std::endl; 	return token::ELSE; }
"while"	{ std::cout<<"KWWHILE"<<std::endl;	return token::WHILE; }
"do"	{ std::cout<<"KWDO"<<std::endl;		return token::DO; }

[0][0-7]+ {
	yylval->num = strtol(yytext, NULL, 8);
	std::cout<<"INT8 : "<<yylval->num<<std::endl;
	return token::INTEGER;
	}

[0-9]+	{
	yylval->num = atoi(yytext);	
	std::cout<<"INT10 : "<<yylval->num<<std::endl;
	return token::INTEGER;
	}
[0][xX][0-9a-fA-F]+ {
	yylval->num = strtol(yytext, NULL, 16);	
	std::cout<<"INT16 : "<<yylval->num<<std::endl; 
	return token::INTEGER;
	}

[a-zA-Z][0-9a-zA-z]* {
	yylval->var = new std::string(yytext, yyleng);	
	std::cout<<"IDN : "<<yytext<<std::endl;
	return token::STRING;
	}
 
[ \t\r]+ {
	yylloc->step();
	}	

 /* gobble up end-of-lines */
\n	{
	yylloc->lines(yyleng); yylloc->step();
	return token::EOL;
	}

 /* pass all other characters up to bison */
.	{
	return static_cast<token_type>(*yytext);
	}

%% 

namespace compiler {

Scanner::Scanner(std::istream *in,std::ostream *out)
    : CompilerFlexLexer(in, out) {}

Scanner::~Scanner() {}

void Scanner::set_debug(bool b) {
    yy_flex_debug = b;
}

} //namespace

/* This implementation of ExampleFlexLexer::yylex() is required to fill the
 * vtable of the class ExampleFlexLexer. We define the scanner's main yylex
 * function via YY_DECL to reside in the Scanner class instead. */

#ifdef yylex
#undef yylex
#endif

int CompilerFlexLexer::yylex() {
    std::cerr << "in ExampleFlexLexer::yylex() !" << std::endl;
    return 0;
}

int CompilerFlexLexer::yywrap() {
    return 1;
}
