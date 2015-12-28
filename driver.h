#ifndef COMPILER_DRIVER_H
#define COMPILER_DRIVER_H

#include <string>
#include <vector>

class AstContext;

namespace compiler {

class Driver {
public:
	Driver(class AstContext &ast);

	// enable debug output in the flex scanner and bison parser 
	bool trace_scanning;
	bool trace_parsing;
	
	// stream name used for error messages
	std::string streamname;

	bool parse_stream(std::istream &in, 
			  const std::string &sname = "stream input");
	bool parse_string(const std::string &input,
			  const std::string &sname = "string stream");
	bool parse_file(const std::string &filename);

	void error(const class location &l, const std::string &m);
	void error(const std::string &m);

	class Scanner *lexer;
	class AstContext &ast;
};

} //namespace compiler

#endif 
