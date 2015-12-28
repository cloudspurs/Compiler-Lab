#ifndef	NODE_H
#define NODE_H

#include	<iostream>
#include	<vector>
#include	<sstream>
#include	<string>

// forward declare, abstract Visitor super class
class Visitor;

// abstact node super class
class Node {
public:
	virtual ~Node() {}
	// accept a Visitor, 纯虚函数
	virtual std::string Accept(const Visitor &v) const = 0;
};

// expression super class
class Exp : public Node {
public:
	virtual ~Exp() {}
	virtual std::string Accept(const Visitor &v) const =0;
};

// statement super class
class Stmt : public Node {
public:
	virtual ~Stmt() {}
	virtual std::string Accept(const Visitor &v) const = 0;
};

// unary expression
class Unary : public Exp {
	// 声明 ShowVisitor,CodeVisitor为友元类
	friend class ShowVisitor;
	friend class CodeVisitor;

private:
	std::string op;
	Exp* left;

public:
	// explicit:禁止隐含转换
	explicit Unary(std::string opp, Exp *l) : op(opp), left(l) {}
	virtual std::string Accept(const Visitor &v) const;
};

// binary expression
class Binary : public Unary {
	friend class ShowVisitor;
	friend class CodeVisitor;

private:
	Exp* right;

public:
	explicit Binary(std::string opp, Exp *l, Exp *r) : Unary(opp,l), right(r) {} 
	virtual std::string Accept(const Visitor &v) const;
};

// number 
class Number : public Exp {
	friend class ShowVisitor;
	friend class CodeVisitor;

private:
	int value;

public:
	explicit Number(int v): value(v) {}
	virtual std::string Accept(const Visitor &v) const;  
};

// variable
class Variable : public Exp {
	friend class ShowVisitor;
	friend class CodeVisitor;

private:
	std::string var;

public:
	explicit Variable(std::string v) : var(v) {}
	virtual std::string Accept(const Visitor &v) const;  
};

// exp relop exp
class 
Cal : public Exp {
	friend class ShowVisitor;
	friend class CodeVisitor;

private: 
	std::string op;
	Exp *left;
	Exp *right;

public:
	explicit Cal( std::string opp, Exp *l, Exp *r) : op(opp), left(l), right(r) {}
	virtual std::string Accept( const Visitor &v) const;  
};

// variable = exp
class Assign : public Exp {
	friend class ShowVisitor;
	friend class CodeVisitor;

private:
	std::string op;
	Exp *var;
	Exp *exp;

public:
	explicit Assign(std::string opp, Exp *v, Exp *e) : op(opp), var(v), exp(e) {}
	virtual std::string Accept(const Visitor &v) const;  
};

// if c then s
class Iftst : public Stmt {
	friend class ShowVisitor;
	friend class CodeVisitor;

private:
	std::string op;
	Cal *cal;
	Stmt *t;

public:
	explicit Iftst(std::string opp, Cal *c, Stmt *tt) : op(opp), cal(c), t(tt) {}
	virtual std::string Accept(const Visitor &v) const; 
};

// if c then s else s
class Ifst : public Stmt {
	friend class ShowVisitor;
	friend class CodeVisitor;

private: 
	std::string op;
	Cal *cal;
	Stmt *t;
	Stmt *f;

public:
	explicit Ifst(std::string opp, Cal *c, Stmt *t, Stmt *f) : op(opp), cal(c), t(t), f(f) {}
	virtual std::string Accept(const Visitor &v) const;  
}; 

// while c do s
class Whst : public Stmt {
	friend class ShowVisitor;
	friend class CodeVisitor;
private: 
	std::string op;
	Cal *cal;
	Stmt *t;

public:
	explicit Whst(std::string opp, Cal *c, Stmt *t) : op(opp), cal(c), t(t) {}
	virtual std::string Accept(const Visitor &v) const;  
}; 


class Visitor {
public:
	virtual std::string VisitUnary( const Unary *u) const =  0;
	virtual std::string VisitBinary( const Binary *b) const = 0;
	virtual std::string VisitNumber( const Number *n) const = 0;
	virtual std::string VisitVariable( const Variable *v) const = 0;
	virtual std::string VisitCal( const Cal *c) const = 0;
	virtual std::string VisitAssign( const Assign *a) const =0;
	virtual std::string VisitIftst( const Iftst *i) const = 0;
	virtual std::string VisitIfst( const Ifst *i) const = 0;
	virtual std::string VisitWhst( const Whst *w) const = 0;
};
 
// ShowVisitor to print ast indent
class ShowVisitor : public Visitor {
	// 控制缩进大小
	static int index;

public:
	// 每遇结点(except Number, Variable)， 调用一次print_index()，输出缩进
	static void print_index(int i) {
		for (int t = 0; t < i; t++)
			std::cout<<"    ";
	}
	virtual std::string VisitUnary(const Unary *u) const;
	virtual std::string VisitBinary(const Binary *b) const;
	virtual std::string VisitNumber(const Number *n) const;
	virtual std::string VisitVariable(const Variable *v) const;
	virtual std::string VisitCal(const Cal *c) const;
	virtual std::string VisitAssign(const Assign *a) const;
	virtual std::string VisitIftst(const Iftst *i) const;
	virtual std::string VisitIfst(const Ifst *i) const;
	virtual std::string VisitWhst(const Whst *w) const;
};
 
// print intermediate code
class CodeVisitor : public Visitor {
private: 
	static int t;	// record t number
	static int l;	// record l number
	static std::string senStart;	
	static std::string senNext;
	static std::string sen1Start;
	static std::string sen1Next;
	static std::string sen2Start;
	static std::string sen2Next;

public:
	// generate t label
	static std::string codeT() {
		std::string temp = "t";
		std::stringstream temp1;
		temp1<<t++;
		temp += temp1.str();
		return temp;		
	}

	// generate l label
	static std::string codeL() {
		std::string label = "L";
		std::stringstream temp;
		temp<<l++;
		label+=temp.str();
		return label;
	}
	
	virtual std::string VisitUnary( const Unary *u) const;
	virtual std::string VisitBinary( const Binary *b) const;
	virtual std::string VisitNumber( const Number *n) const;
	virtual std::string VisitVariable( const Variable *v) const;
	virtual std::string VisitCal( const Cal *c) const;
	virtual std::string VisitAssign( const Assign *a) const;
	virtual std::string VisitIftst( const Iftst *i) const;
	virtual std::string VisitIfst( const Ifst *i) const;
	virtual std::string VisitWhst( const Whst *w) const;
};

 
class 
AstContext {
public: 
	// save ast
	std::vector<Node*> node;

	~AstContext() {
		clearNode();
	}
	
	// clear node 
	void clearNode() {
		for(unsigned int i = 0; i < node.size(); ++i) {
	    		delete node[i];
		}
		node.clear();
	}
};

#endif 
