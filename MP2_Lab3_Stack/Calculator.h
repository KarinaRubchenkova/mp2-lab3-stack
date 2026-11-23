#pragma once
#include <string>
#include "Token.h"
#include "Stack.h"
#include "Container.h"
/*
класс калькулятор: тесты на отдельные операции, комбинации, длинные выражения + все комбинации, простое выражение
в мейне можно ввести и вывести выражение, выражение может быь введено неверно, не хватает операндов, операций(консольное приложение)
доп задание: оформить графический  интерфейс. Установить штуки для графического интерфейса 

*/
class Calculator {
	std::string infix, postfix;
	Container<Token> inf_cont, post_cont;
	Stack <double> num;
	Stack <Token> oper;
public:
	Calculator() {
		infix = "";
		postfix = "";
		inf_cont.clear();
		post_cont.clear();
	}
private:
	void infix_to_cont() {
		inf_cont.clear();
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
	void to_postfix() {
		oper.Clear_Stack();
		for (int i = 0; i < inf_cont.get_size(); i++) {
			if (inf_cont[i].type == OpenBr) {
				oper.Push(inf_cont[i]);
				continue;
			}
			if (inf_cont[i].type == Number) {
				post_cont.push_back(inf_cont[i]);
				continue;
			}
			if (inf_cont[i].type == CloseBr) {
				while (oper.Top().type != CloseBr) {
					post_cont.push_back(oper.Pop());
				}
				oper.Pop();
				continue;
			}
			if (inf_cont[i].type == Oper) {
				while (inf_cont[i].prior <= oper.Top().prior) {
					post_cont.push_back(oper.Pop());
				}
				oper.Push(inf_cont[i]);
				continue;
			}
		}
	}
	double calc_postfix() {
		num.Clear_Stack();
		for (int i = 0; i < post_cont.get_size(); i++) {
			if (post_cont[i].type == Number) {
				num.Push(post_cont[i].val);
				continue;
			}
			double res = 0.0;
			if (post_cont[i].type == Oper) {
				double op_2 = num.Pop();
				double op_1 = num.Pop();
				if (post_cont[i].str == "+") {
					res = op_2 + op_1;
				}
				if (post_cont[i].str == "-") {
					res = op_2 - op_1;
				}
				if (post_cont[i].str == "*") {
					res = op_2 * op_1;
				}
				if (post_cont[i].str == "/") {
					res = op_2 / op_1;
				}
				if (post_cont[i].str == "^") {
					res = pow(op_2,op_1);
				}
				num.Push(res);
			}
		}
	}
};
