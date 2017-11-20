#include <cstdlib>
#include <iostream>
#include <math.h>
#include <string>

#include "Stack.h"

using namespace std;


string convert_postfix(string input) {
    Stack<char> operators {};
    string postfix;
    char x;
    
    for (auto& character : input) {
        if (isdigit(character)) {
            postfix += character;
            
        } else {
            switch (character) {
                case '+': case '-': case '*': case '/':
                    if (!operators.isEmpty()) {
                        x = operators.peek();
                        while (!operators.isEmpty() && character != x && x != '(') {
                            postfix += x;
                            operators.pop();
                        }
                    }
                    operators.push(character);
                    break;
                    
                case '^': case '(':
                    operators.push(character);
                    break;
                    
                case ')':
                    if (!operators.isEmpty()) {
                        x = operators.peek();
                    }
                    
                    while (!operators.isEmpty() && x != '(') {
                        postfix += x;
                        x = operators.retrieve();
                    }
                    operators.pop();
                    break;
                    
                default:
                    break;
            }
            
            while (!operators.isEmpty()) {
                postfix += operators.retrieve();
            }
            cout << postfix << endl;
            return postfix;
        }
    }
}

char evaluate_postfix(string postfix) {
    char operation1, operation2, r;
    Stack<char> values;

    for (auto& character : postfix) {
        if (isdigit(character)) {
            values.push(character);
        } else {
            int result;
            int x;
            int y;
            if (character == '+' || character == '-' || character == '*' || character == '/' || character == '^') {
                operation1 = values.retrieve();
                operation2 = values.retrieve();
                x = operation1 - '0';
                y = operation2 - '0';
            }
            
            switch (character) {
                case '+':
                    result = y + x;
                    break;
                    
                case '-':
                    result = y - x;
                    break;
                    
                case '*':
                    result = y * x;
                    break;
                    
                case '/':
                    result = y / x;
                    break;
                    
                case '^':
                    result = pow(y, x);
                    break;
                    
                default:
                    break;
            }
            r = '0' + result;
            values.push(r);
        }
    }
    cout << r;
    return r;
}

int main(int argc, char** argv) {

    Stack<int> stack{};
    stack.push(*new int{3});
    stack.push(*new int{4});

    cout << stack.peek() << endl;

    stack.printFromBottom();

    stack.pop();

    stack.printFromTop();
    
    string expression;
    cin >> expression;
    evaluate_postfix(convert_postfix(expression));
    
    return 0;
}
