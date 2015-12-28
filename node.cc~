#include "node.h"
#include <iostream>
#include <string>
#include <sstream>

// initialize static variable
int ShowVisitor::index = 0;
int CodeVisitor::t = 0;
int CodeVisitor::l = 0;

std::string Unary::Accept(const Visitor &v) const {
	 return v.VisitUnary(this);
}

std::string Binary::Accept(const Visitor &v) const {
	return v.VisitBinary(this);
}

std::string Number::Accept(const Visitor &v) const {
	return v.VisitNumber(this);
}

std::string Variable::Accept(const Visitor &v) const {
	return v.VisitVariable(this);
}

std::string Cal::Accept(const Visitor &v) const {
	return v.VisitCal(this);
}

std::string Assign::Accept(const Visitor &v) const {
	return v.VisitAssign(this);
}

std::string Iftst::Accept(const Visitor &v) const {
	return v.VisitIftst(this);
}

std::string Ifst::Accept(const Visitor &v) const {
	return v.VisitIfst(this);
}

std::string Whst::Accept(const Visitor &v) const {
	return v.VisitWhst(this);
}

std::string ShowVisitor::VisitUnary(const Unary *u) const {
	// 输出缩进
	ShowVisitor::print_index(index);
	// 输出op	
	std::cout<<u->op<<std::endl;
	// 设置缩进（每输出一个op，缩进一次）
	index++; 
	// 输出left
	u->left->Accept(*this);
	// 输出完缩进-1	
	index--; 
	
	return "0";
}

std::string ShowVisitor::VisitBinary(const Binary *b) const {
	ShowVisitor::print_index(index);
	std::cout<<b->op<<std::endl;
	index++; 
	b->left->Accept(*this);
	b->right->Accept(*this);
	index--;
 
	return "0";
}

// Number只输出，缩进无变化（Variable相同）
std::string ShowVisitor::VisitNumber(const Number *n) const {
	ShowVisitor::print_index(index);
	std::cout<<n->value<<std::endl;
	return "0";
}

std::string ShowVisitor::VisitVariable(const Variable *v) const {
	ShowVisitor::print_index(index);
	std::cout<<v->var<<std::endl;

	return "0";
}

std::string ShowVisitor::VisitCal(const Cal *c) const {
	ShowVisitor::print_index(index);
	std::cout<<c->op<<std::endl;
	index++;
	c->left->Accept(*this);
	c->right->Accept(*this);
	index--;

	return "0";
}

std::string ShowVisitor::VisitAssign(const Assign *a) const {
	ShowVisitor::print_index(index);
	std::cout<<a->op<<std::endl;
	index++;
	a->var->Accept(*this);
	a->exp->Accept(*this);
	index--;

	return "0";
}

std::string ShowVisitor::VisitIftst(const Iftst *i) const {
 	ShowVisitor::print_index(index);
	std::cout<<i->op<<std::endl;
	index++;
	i->cal->Accept(*this);
	i->t->Accept(*this);
	index--;

	return "0";
}

std::string ShowVisitor::VisitIfst( const Ifst *i) const {
 	ShowVisitor::print_index( index);
	std::cout<<i->op<<std::endl;
	index++;
	i->cal->Accept(*this);
	i->t->Accept(*this);
	i->f->Accept(*this);
	index--;

	return "0";
}

std::string ShowVisitor::VisitWhst(const Whst *w) const {
 	ShowVisitor::print_index(index);
	std::cout<<w->op<<std::endl;
	index++;
	w->cal->Accept(*this);
	w->t->Accept(*this);
	index--;

	return "0";
}

// 将value转换为string类型并返回
std::string CodeVisitor::VisitNumber(const Number *n) const {
	std::stringstream temp;
	temp<<n->value;
	return temp.str();
}

std::string CodeVisitor::VisitVariable(const Variable *v) const {
	return v->var;
}

std::string CodeVisitor::VisitUnary(const Unary *u) const {
	// 输出左子树的三地址代码，并给code1赋值
	std::string code1 = u->left->Accept(*this);
	// 生成新的临时变量t赋值给code
	std::string code =  CodeVisitor::codeT();
	// 输出三地址代码
	std::cout<<code<<" = "<<u->op<<code1<<std::endl;
	// 返回本条语句产生的临时变量t
	return code;
}

std::string CodeVisitor::VisitBinary(const Binary *b) const {
	// 左子树三地址代码，并给code1赋值	 	
	std::string code1 = b->left->Accept(*this);
	// 右子树三地址代码，并给code2赋值	
	std::string code2 = b->right->Accept(*this);
	// 生成新的临时变量t赋值给code
	std::string code = CodeVisitor::codeT();
	// 输出三地址代码
	std::cout<<code<<" = "<<code1<<b->op<<code2<<std::endl;
	// 返回本条语句产生的临时变量t
	return code;
}

std::string CodeVisitor::VisitCal(const Cal *c) const {	
	std::string code1 = c->left->Accept(*this);
	std::string code2 = c->right->Accept(*this);
	std::cout<<"if("<<code1<<c->op<<code2<<") ";
	
	return "0";
}

std::string CodeVisitor::VisitAssign(const Assign *a) const {
	std::string code1 = a->var->Accept(*this);
	std::string code2 = a->exp->Accept(*this);
	std::cout<<code1<<"="<<code2<<std::endl;

	return "0";
}

std::string CodeVisitor::VisitIftst(const Iftst *i) const {
	std::string cTrue = CodeVisitor::codeL();
	std::string sNext = CodeVisitor::codeL();
	
	i->cal->Accept(*this);
    // goto c.true
	std::cout<<"goto"<<cTrue<<std::endl;
    // goto c.false	
    std::cout<<"goto"<<sNext<<std::endl;
    // c.true	
    std::cout<<cTrue<<" ";
	i->t->Accept(*this);
    // s.next	
    std::cout<<sNext<<" ";

	return "0";
}

std::string CodeVisitor::VisitIfst(const Ifst *i) const {
	std::string cTrue = CodeVisitor::codeL();
	std::string cFalse = CodeVisitor::codeL();
	std::string sNext = CodeVisitor::codeL();
	
	i->cal->Accept(*this);
	// goto c.true
	std::cout<<"goto"<<cTrue<<std::endl;
	// goto c.false
	std::cout<<"goto"<<cFalse<<std::endl;
	// c.true
	std::cout<<cTrue<<" ";
	i->t->Accept(*this);
	// goto s.next
	std::cout<<"goto"<<sNext<<std::endl;
	// c.false
	std::cout<<cFalse<<" ";
	i->f->Accept(*this);
	// s.next
	std::cout<<sNext<<" ";

	return "0";
}
	
std::string CodeVisitor::VisitWhst(const Whst *w) const {
	std::string sBegin = CodeVisitor::codeL();
	std::string sNext = CodeVisitor::codeL();	
	std::string cTrue = CodeVisitor::codeL();
	
	// s.begin
	std::cout<<sBegin<<" ";
	w->cal->Accept(*this);
	// goto c.true
	std::cout<<"goto"<<cTrue<<std::endl;
	// goto s.next
	std::cout<<"goto"<<sNext<<std::endl;
	// c.true
	std::cout<<cTrue<<" ";
	w->t->Accept(*this);
	// goto s.begin
	std::cout<<"goto"<<sBegin<<std::endl;
	// s.next	
	std::cout<<sNext<<" ";
	
	return "0";
}


