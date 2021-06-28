#include <iostream>
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include "CentralBureaucracy.hpp"

//Constructors & destructor
CentralBureaucracy::CentralBureaucracy(const CentralBureaucracy&c){(void)c;}
CentralBureaucracy::CentralBureaucracy(void): a_queue(0), a_queue_size(0){
    for (int i = 0; i < 20; i++)
        this->a_blocks_list[i].setIntern(&this->a_interns_list[i]);
    this->a_burolist[0] = "RobotomyRequestForm";
    this->a_burolist[1] = "ShrubberyCreationForm";
    this->a_burolist[2] = "PresidentialPardonForm";
    this->a_burolist[3] = "WrongFormatForm";
}
CentralBureaucracy::~CentralBureaucracy(void){}

CentralBureaucracy& CentralBureaucracy::operator=(const CentralBureaucracy& f){(void)f; return (*this);}

//Others
void CentralBureaucracy::feed(Bureaucrat& b)
{
    for (int i = 0; i < 20; i++)
        if (this->a_blocks_list[i].getSigner() == &b ||
            this->a_blocks_list[i].getExecutor() == &b){
                std::cout << "Bureaucrat " << b << "is already working here on block n: " << i << std::endl;
                return ;
            }
    for (int i = 0; i < 20; i++)
    {
        if (!this->a_blocks_list[i].getSigner())
        {
            this->a_blocks_list[i].setSigner(b);
            return ;
        }
        if (!this->a_blocks_list[i].getExecutor())
        {
            this->a_blocks_list[i].setExecutor(b);
            return ;
        }
    }
    std::cout << "Bureaucrat not added, all blocks full" << std::endl;
}

void CentralBureaucracy::queueUp(const std::string& name)
{
    std::string *arr;

    arr = new std::string[this->a_queue_size + 1];
    for (int i = 0; i < this->a_queue_size; i++)
        arr[i] = this->a_queue[i];
    arr[this->a_queue_size] = name;
    this->a_queue_size++;

    delete [] this->a_queue;
    this->a_queue = arr;
}

void CentralBureaucracy::doBureaucracy(void)
{
    int rndom = rand() % 4;

    for (int i = 0; i < this->a_queue_size; i++)
    {
        try
        {
            std::cout << "Office " << i % 20 << " is taking care of " << this->a_queue[i] << " petition." << std::endl;
            this->a_blocks_list[i % 20].doBureaucracy(this->a_burolist[rand() % 4], this->a_queue[i]);
            if (i % 20 == 0)
                std::cout << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            if (i % 20 == 0)
                std::cout << std::endl;
        }
    }
    delete [] this->a_queue;
    this->a_queue = 0;
    this->a_queue_size = 0;
}

//Get & set
int CentralBureaucracy::getQueuesize(void) const{return (this->a_queue_size);}
std::string* CentralBureaucracy::getQueue(void) const{return (this->a_queue);}