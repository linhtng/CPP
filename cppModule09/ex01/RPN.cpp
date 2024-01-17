#include "RPN.hpp"
#include <sstream>

// Default constructor
RPN::RPN() {}

// Copy constructor
RPN::RPN(const RPN &other) : stack(other.stack) {}

// Copy assignment operator
RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        stack = other.stack;
    }
    return *this;
}

// Destructor
RPN::~RPN() {}

// Evaluate function
int RPN::evaluate(const std::string &expression)
{
    std::istringstream iss(expression);
    std::string token;
    int tokenCount = 0;

    while (iss >> token)
    {
        tokenCount++;
        if (isdigit(token[0]) && token.size() == 1)
        {
            stack.push(std::stoi(token));
        }
        else if (token.size() == 1)
        {
            if (stack.size() < 2)
            {
                throw std::runtime_error("Error");
            }

            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();

            switch (token[0])
            {
            case '+':
                std::cout << a << " + " << b << " = " << a + b << "\n";
                stack.push(a + b);
                break;
            case '-':
                std::cout << a << " - " << b << " = " << a - b << "\n";
                stack.push(a - b);
                break;
            case '*':
                std::cout << a << " * " << b << " = " << a * b << "\n";
                stack.push(a * b);
                break;
            case '/':
                if (b == 0)
                {
                    throw std::runtime_error("Error");
                }
                std::cout << a << " / " << b << " = " << a / b << "\n";
                stack.push(a / b);
                break;
            default:
                throw std::runtime_error("Error");
            }
        }
        else
        {
            throw std::runtime_error("Error");
        }
    }

    if (stack.size() != 1 || tokenCount <= 1)
    {
        throw std::runtime_error("Error");
    }

    int result = stack.top();
    stack.pop();
    return result;
}