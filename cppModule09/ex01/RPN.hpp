#include <string>
#include <stack>
#include <iostream>
#include <stdexcept>

#define RED "\e[91m"
#define CYAN "\033[36m"
#define RESET "\e[0m"

class RPN
{
public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    int evaluate(const std::string &expression);

private:
    std::stack<int> stack;
};