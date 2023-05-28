#ifndef RNP_HPP
#define RNP_HPP
#include <stack>
#include <iostream>

class RPN
{
	 private:
		RPN();
		~RPN();
		RPN (const RPN &copy);
		RPN &operator=(const RPN&);
	 public:
		static bool isOperator(char c);
		static void resolveOperation(char c, std::stack<float> & stk);
		static void resolveRPN(char *str, std::stack<float> & stk);
};

#endif
