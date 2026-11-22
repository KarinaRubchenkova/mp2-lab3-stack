#pragma once
#include <string>
#include "Token.h"
class Calculator {
	std::string infix, postfix;
	Container<Token> inf_cont, post_cont;
public:
	Calculator() {
		infix = "";
		postfix = "";
		inf_cont.clear();
		post_cont.clear();
	}
private:
	void infix_to_cont() {
		inf_cont.clean();
		int i = 0;
		while (i < infix.size()) {
			if (infix[i] == '(') {
				Token t;
				t.type = OpenBr;
				t.str = '(';
				inf_cont.push_back(t);
			}
			if (infix[i] == ')') {
				Token t;
				t.type = CloseBr;
				t.str = ')';
				inf_cont.push_back(t);
			}
			if (infix[i] >= '0' && infix[i] <= '9' || infix[i] == '.') {
				char* p;
				double val = strtod(&infix[i], &p);
				Token t;
				t.type = Number;
				t.val = val;
				int d = p - &infix[i];
				t.str = infix.substr(i, d);
				inf_cont.push_back(t);
				i += d - 1;
			}
			if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') {
				Token t;
				t.type = Oper;
				t.str = infix[i];
				inf_cont.push_back(t);
			}
		}
	}
};
