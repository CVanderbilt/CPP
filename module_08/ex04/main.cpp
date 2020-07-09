#include <iostream>
#include <stack>
#include <vector>
#include <iostream>
#include <ostream>
#include "Itoken.hpp"
#include "parentheses.hpp"
#include "number.hpp"
#include "operand.hpp"

#define ISTOKENIZABLE(x) (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')')

std::ostream& operator<<(std::ostream& os, std::stack<IToken*>& stack){
    std::stack<IToken*>s = stack;

    os << "ST";
    while (!s.empty())
    {
        os << " " << s.top()->toString();
        s.pop();
    }
    os << "]";
    return os;
}

std::ostream& operator<<(std::ostream& os, std::vector<IToken*>& v){
    for (std::vector<IToken*>::iterator it = v.begin(); it != v.end(); it++)
        os << (*it)->toString() << " ";
    return (os);
}


IToken* ft_token_ptr(char c)
{
    if (!ISTOKENIZABLE(c))
        throw std::exception();
    if (c != '(' && c != ')')
        return (new Operand(c));
    return (c == '(' ? new Parentheses(true) : new Parentheses(false));
}

std::vector<IToken*> *ft_tokenize(char *str)
{
    std::vector<IToken*> *v = new std::vector<IToken*>();

    for (int i = 0; str[i]; i++)
    {
        char c = str[i];

        if (isdigit(c))
        {
            v->push_back(new Number(std::stoi(str + i)));
            while (isdigit(str[++i]));
            i--;
        }
        else if (ISTOKENIZABLE(c))
        {
                IToken *token = ft_token_ptr(c);
                v->push_back(token);
        }
        else
            if (!isspace(c))
                throw std::exception();
    }
    return (v);
}



std::vector<IToken*>* ft_infix_to_postfix(std::vector<IToken*>& v)
{
    std::vector<IToken*>* out = new std::vector<IToken*>();
    std::stack<IToken*> operator_stack;

    for (std::vector<IToken*>::iterator it = v.begin(); it != v.end(); it++)
    {
        //std::cout << "Colocamos: " << (*it)->toString() << ": " << (*it)->getIDChar() << std::endl;
        if ((*it)->getIDChar() == 'n')
            out->push_back((*it)->clone());
        else 
        {
            if ((*it)->getIDChar() == ')')
            {
                //std::cout << "Deberia entrar" << std::endl;
                do
                {
                    //std::cout << "kk: " << operator_stack.size() << " " << operator_stack << std::endl;
                    if (operator_stack.empty())
                    {
                        //std::cout << "kk--" << std::endl;
                        throw std::exception();
                    }
                    out->push_back(operator_stack.top()->clone());
                    //std::cout << "      3Pop: " << operator_stack.top()->getIDChar() << ": " << operator_stack.top()->toString() << std::endl;
                    operator_stack.pop();
                    
                } while (operator_stack.top()->getIDChar() != '(');
                //std::cout << "      2Pop: " << operator_stack.top()->getIDChar() << ": " << operator_stack.top()->toString() << std::endl;
                operator_stack.pop();
            }
            else
            {
                if ((*it)->getIDChar() == 'n')
                    out->push_back((*it)->clone());
                else
                {
                    while (!operator_stack.empty() && ((operator_stack.top()->priority() >= (*it)->priority()) && (*it)->getIDChar() != '('))
                    {
                        out->push_back(operator_stack.top()->clone());
                        //std::cout << "      1Pop: " << operator_stack.top()->getIDChar() << ": " << operator_stack.top()->toString() << std::endl;
                        operator_stack.pop();
                    }
                    //std::cout << "      Push: " << (*it)->getIDChar() << ": " << (*it)->toString() << std::endl;
                    operator_stack.push(*it);
                }
            }
        }
    }
    while(!operator_stack.empty())
    {
        out->push_back(operator_stack.top()->clone());
        //std::cout << "      Pop: " << operator_stack.top()->getIDChar() << ": " << operator_stack.top()->toString() << std::endl;
        operator_stack.pop();
    }
    return (out);
}

void ft_operate(std::vector<IToken*>& v)
{
    std::stack<IToken*>stack;

    for (std::vector<IToken*>::iterator it = v.begin(); it != v.end(); it++)
    {
        Number *ptr = dynamic_cast<Number*>(*it);
        if (ptr)
        {
            stack.push(ptr);
            std::cout << "I " << ptr->toString() << " | OP Push     |" << stack << std::endl;
        }
        else
        {
            if (stack.size() < 2)
                throw std::exception();
            Number* a_ptr = dynamic_cast<Number*>(stack.top());
            stack.pop();
            Number* b_ptr = dynamic_cast<Number*>(stack.top());
            Operand* op = dynamic_cast<Operand*>(*it);
            if (!a_ptr || !b_ptr || !op)
                throw std::exception();
            std::cout << "I " << op->toString() << "  | OP ";
            switch (op->getIDChar())
            {
                case '+':
                    *b_ptr + *a_ptr;
                    std::cout << "Add     |" << stack << std::endl;
                    break;
                case '-':
                    *b_ptr - *a_ptr;
                    std::cout << "Substractc     |" << stack << std::endl;
                    break;
                case '*':
                    *b_ptr * *a_ptr;
                    std::cout << "Multiply     |" << stack << std::endl;
                    break;
                case '/':
                    *b_ptr / *a_ptr;
                    std::cout << "Divide     |" << stack << std::endl;
                    break;
                default:
                    throw std::exception();
            }
        } 
    }
    Number* a_ptr = dynamic_cast<Number*>(stack.top());
    if (!a_ptr)
        throw std::exception();
    std::cout << "Resut: " << a_ptr->getValue() << std::endl;
}


int main(int argc, char *argv[])
{
    std::vector<IToken*> *vector;
    std::vector<IToken*> *output;
    if (argc == 2)
    {
        try
        {
            vector = ft_tokenize(argv[1]);
            std::cout << "Tokens: " << *vector << std::endl;
            output = ft_infix_to_postfix(*vector);
            std::cout << "Postfix : " << *output << std::endl;

            ft_operate(*output);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Wrong format, check your expresion" << std::endl;;
        }
        
        if (vector)
        {    
            for (std::vector<IToken*>::iterator it = vector->begin(); it != vector->end(); it++)
                delete *it;
            delete vector;
        }
        
        if (output)
        {    
            for (std::vector<IToken*>::iterator it = output->begin(); it != output->end(); it++)
                delete *it;
            delete output;
        }
    }
}