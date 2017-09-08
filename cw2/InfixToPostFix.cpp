#include "InfixToPostFix.h"
#include <stack>

bool InfixToPostFix::getInfix(const string &new_infx) {
	infx = new_infx;
	convertToPostfix();
}
InfixToPostFix::InfixToPostFix() {
	infx = "";
	pfx = "";
}

void InfixToPostFix::convertToPostfix() {
	stack<char> s;
	for (int index = 0; index < infx.length(); index++) {
		char sym = infx[index];
		if (isOperand(sym)) {
			pfx += sym;
			pfx += ' ';
		}
		else if (isOpenParen(sym)) {
			s.push(sym);
		}
		else if (isClosedParen(sym)) {
			while (!isOpenParen(s.top())) {
				char top = s.top();
				s.pop();
				pfx += top;
				pfx += ' ';
			}
			s.pop();
		}
		else if (isOp(sym)) {
			while (!isOpenParen(s.top()) && precedence(s.top(), sym) >= 0) {
				pfx += s.top();
				s.pop();
			}
			s.push(sym);
		}
	}
	while (!s.empty()) {
		s.pop();
		pfx += s.top();
		pfx += ' ';
	}
}
void InfixToPostFix::showInfix() const {
	cout << infx;
}
void InfixToPostFix::showPostfix() const {
	cout << pfx;
}

int InfixToPostFix::precedence(char op1, char op2) {
	int state = 0;
	if (isAddOp(op1)) state += 1;
	if (isAddOp(op2)) state += 2;
	switch (state) {
	case 0:
		return 0;
	case 1:
		return -1;
	case 2:
		return 1;
	default:
		return 0;
	}
}
bool InfixToPostFix::isOp(char candidate) {
	return isAddOp(candidate) || isMultOp(candidate);
}

bool InfixToPostFix::isAddOp(char candidate) {
	return candidate == '+' || candidate == '-';
}

bool InfixToPostFix::isMultOp(char candidate) {
	return candidate == '*' || candidate == '/';
}
bool InfixToPostFix::isOperand(char candidate) {
	
}
bool InfixToPostFix::isOpenParen(char candidate) {
	return candidate == '(';
}
bool InfixToPostFix::isClosedParen(char candidate) {
	return candidate == ')';
}