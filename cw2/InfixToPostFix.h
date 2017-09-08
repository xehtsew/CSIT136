#pragma once
#include <string>
#include <iostream>
using namespace std;

class InfixToPostFix
{
public:
	InfixToPostFix();
	bool getInfix(const string &new_infx);
	void showInfix() const;
	void showPostfix() const;

private:
	string infx;
	string pfx;

	int precedence(char op1, char op2);
	bool isOp(char candidate);
	bool isAddOp(char candidate);
	bool isMultOp(char candidate);
	bool isOperand(char candidate);
	bool isOpenParen(char candidate);
	bool isClosedParen(char candidate);
	void convertToPostfix();
};

