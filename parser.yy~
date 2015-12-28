%{  
#include <stdio.h>
#include <string>
//#include <vector>
#include "node.h"
%}
 
/* add debug output code to generated parser. disable this for release
 * versions. */
%debug

// 设置开始符号
%start start

// 生成包含token定义头文件
%defines

// 使用lalr1文法
%skeleton "lalr1.cc"

// 设置命名空间 
%name-prefix="compiler"

// 设置生成的parser类名字 
%define parser_class_name "Parser"

// 跟踪当前输入位置
%locations

%initial-action {
    // initialize the initial location object
    @$.begin.filename = @$.end.filename = &driver.streamname;
};

/* The driver is passed by reference to the parser and to the scanner. This
 * provides a simple but effective pure interface, not relying on global
 * variables. */
%parse-param { class Driver &driver }

/* verbose error messages */
%error-verbose

%union {
	int			num;
	std::string	*var;
	class Cal	*cal;
	class Exp 	*exp;
	class Stmt	*stmt;
}

%token	END		0	
%token	EOL		
%token	ADD SUB MUL DIV ABS MINUS ASSIGN
%token	LBR RBR
%token	GR LR EQUAL
%token	IF THEN ELSE WHILE DO AND

%token 	<num> 	INTEGER
%token	<var>	STRING
%type	<stmt>	stmt
%type	<cal>	cal
%type 	<exp>	exp term factor num variable	 
 
// avoid memory leak
%destructor { delete $$; } stmt cal exp term factor num variable STRING	  


%{

#include "driver.h"
#include "scanner.h"
#include "node.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex
 
%}

%%  

stmt:	IF cal THEN stmt { $$ = new Iftst("IF", $2, $4); }
|	IF cal THEN stmt ELSE stmt {$$ = new Ifst("IF", $2, $4, $6); }
|	WHILE cal DO stmt { $$ = new Whst("WHILE", $2, $4); }
|	exp { $$ = (Stmt*)$1; }  
|	stmt AND stmt {
		if ($3 == NULL)
			$$ = $1;
		else 
			driver.ast.node.push_back($3);
	}

cal:	exp GR exp { $$ = new Cal(">", $1, $3); }
|	exp LR exp { $$ = new Cal("<", $1, $3); }
|	exp EQUAL exp { $$ = new Cal("==", $1, $3); }

;

exp:	term
|	exp ADD term { $$ = new Binary("+", $1, $3); }
|	exp SUB term { $$ = new Binary("-", $1, $3); }
|	variable ASSIGN exp { $$ = new Assign("=", $1, $3); }
;

term:	factor
|	term MUL factor { $$ = new Binary("*", $1, $3); }
|	term DIV factor { $$ = new Binary("/", $1, $3); }
;

factor:	num 
|	variable
|	SUB factor { $$ = new Unary("-", $2); }
|	ABS factor { $$ = new Unary("|", $2); }
|	LBR exp RBR { $$ = $2; }
;
 
num:	INTEGER { $$ = new Number($1); }
;

variable:	STRING	{ $$ = new Variable(*$1); }
;


start	: /* empty */
	| start ';'
	| start EOL
	| start exp ';'{
		driver.ast.node.push_back($2);
	}
 
	| start exp EOL {
			driver.ast.node.push_back($2);
	}
        
	| start exp END {
		driver.ast.node.push_back($2);
	}
	
	| start cal ';' {
		driver.ast.node.push_back($2);
	}
	
	| start cal EOL {
		driver.ast.node.push_back($2);
	}
	
	| start cal END {
		driver.ast.node.push_back($2);
	}

	| start stmt {
		driver.ast.node.push_back($2);
	}
	
	| start stmt EOL  {
		driver.ast.node.push_back($2);
	}
	
	| start stmt END  {
		driver.ast.node.push_back($2);
	}
	
%%

// 错误处理函数
void compiler::Parser::error(const Parser::location_type &l,
			     const std::string &m) {
    driver.error(l, m);
}
