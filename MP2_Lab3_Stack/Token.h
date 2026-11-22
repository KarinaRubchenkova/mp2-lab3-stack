#pragma once
#include <string>
enum TokenType{
	Number, Oper, OpenBr, CloseBr
};
struct Token {
	TokenType type;
	std::string str;
	double val;
};
