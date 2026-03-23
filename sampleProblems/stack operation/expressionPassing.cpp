/* C++ program to convert infix expression to postfix and evaluate it 

*/
// C++ Code for Expression Parsing Using Stack
#include <iostream>
#include <string>
#include <cctype>
#include <stack>
// char stack
std::stack<char> stack;

void push(char item) {
    stack.push(item);
}
char pop() {
    char top = stack.top();
    stack.pop();
    return top;
}
// returns precedence of operators
int precedence(char symbol) {
    switch(symbol) {
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 3;
        case '^':
            return 4;
        case '(':
        case ')':
        case '#':
            return 1;
    }
    return 0;
}
// check whether the symbol is an operator
int isOperator(char symbol) {
    switch(symbol) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '(':
        case ')':
            return 1;
        default:
            return 0;
    }
}
// converts infix expression to postfix
void convert(const std::string& infix, std::string& postfix) {
    int j = 0;
    stack.push('#');
    for (char symbol : infix) {
        if (isOperator(symbol) == 0) {
            postfix += symbol;
            j++;
        } else {
            if (symbol == '(') {
                push(symbol);
            } else {
                if (symbol == ')') {
                    while (stack.top() != '(') {
                        postfix += pop();
                        j++;
                    }
                    stack.pop(); // pop out '('
                } else {
                    if (precedence(symbol) > precedence(stack.top())) {
                        push(symbol);
                    } else {
                        while (precedence(symbol) <= precedence(stack.top())) {
                            postfix += pop();
                            j++;
                        }
                        push(symbol);
                    }
                }
            }
        }
    }

    while (stack.top() != '#') {
        postfix += pop();
        j++;
    }

    postfix[j] = '\0'; // null terminate string
}
// evaluates postfix expression
int evaluate(const std::string& postfix) {
    std::stack<int> stack_int;
    int operand1, operand2;
    for (char ch : postfix) {
        if (std::isdigit(ch)) {
            stack_int.push(ch - '0'); // Push the operand
        } else {
            // Operator, pop two operands
            operand2 = stack_int.top();
            stack_int.pop();
            operand1 = stack_int.top();
            stack_int.pop();
            switch (ch) {
                case '+':
                    stack_int.push(operand1 + operand2);
                    break;
                case '-':
                    stack_int.push(operand1 - operand2);
                    break;
                case '*':
                    stack_int.push(operand1 * operand2);
                    break;
                case '/':
                    stack_int.push(operand1 / operand2);
                    break;
            }
        }
    }
    return stack_int.top();
}
int main() {
    std::string infix = "1*(2+3)", postfix;
    convert(infix, postfix);
    std::cout << "Infix expression is: " << infix << std::endl;
    std::cout << "Postfix expression is: " << postfix << std::endl;
    std::cout << "Evaluated expression is: " << evaluate(postfix) << std::endl;
    return 0;
}