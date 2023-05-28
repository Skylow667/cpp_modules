#include "RPN.hpp"
#include <cctype>
#include <cwctype>
#include <sstream>
#include <stdexcept>

bool RPN::isOperator(char c) {
	if (c == '*' || c == '-' || c == '+' || c == '/')
		return true;
	return false;
}

void RPN::resolveOperation(char c, std::stack<float> & stk) {
	float leftNb, rightNb, result;

	if (stk.size() < 2)
		throw (std::logic_error("Error: operation not possible."));
	rightNb = stk.top();
	stk.pop();
	leftNb = stk.top();
	stk.pop();

	if (c == '-')
		result = leftNb - rightNb;
	else if (c == '+')
		result = leftNb + rightNb;
	else if (c == '/') {
		if (rightNb == 0)
			throw (std::logic_error("Error: division by 0"));
		result = leftNb / rightNb;
	}
	else if (c == '*')
		result = leftNb * rightNb;
	stk.push(result);
}

void RPN::resolveRPN(char *str, std::stack<float> & stk) {
	for (int i = 0; str[i]; i++) {
		if (i % 2 != 0 && str[i] != ' ')
			throw (std::logic_error("Error: a space is required between each character."));
		else if (std::isdigit(str[i]))
			stk.push(str[i] - 48);
		else if (isOperator(str[i]))
			resolveOperation(str[i], stk);
		else if (i % 2 != 0 && str[i] != ' ')
			throw (std::logic_error("Error: bad input."));
	}
	if (stk.size() > 1)
		throw (std::logic_error("Error: bad input."));
	else
		std::cout << stk.top() << std::endl;
}

RPN::RPN(void) {}

RPN::~RPN(){
}

RPN::RPN(const RPN &copy){
	*this = copy;
}

RPN & RPN::operator=(const RPN &copy){
	if (&copy != this)
	{
		this->~RPN();
		new(this) RPN(copy);
	}
	return (*this);
}
