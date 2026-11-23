#pragma once
#include <string>
enum TokenType{
	Number, Oper, OpenBr, CloseBr
};
struct Token {
	TokenType type;
	std::string str;
	double val;
	int priority;
	Token(TokenType t = Number, std::string s = " ", double v = 0.0, int pr = 0) : type(t), str(s),val(v),priority(pr) {}

};
