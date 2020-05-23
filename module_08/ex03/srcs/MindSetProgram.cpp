#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>

#include "MindSetProgram.hpp"

#include "MindSetProgram.hpp"
#include "IInstruction.hpp"
#include "IncrementPtr.hpp"
#include "IncrementVal.hpp"
#include "DecrementPtr.hpp"
#include "DecrementVal.hpp"
#include "WhileClose.hpp"
#include "WhileOpen.hpp"
#include "GetChar.hpp"
#include "PutChar.hpp"

#define ISINSTRUCTION(c) c == '+' || c == '-' || c == '>' || c == '<' || c == '[' || c == ']' || c == '.' || c == ','

const char MindSetProgram::charinstructable[] = {'>', '<', '+', '-', '[', ']', ',', '.'};

MindSetProgram::MindSetProgram(void): m_debuging(false), m_ptr(0)
{
    for (int i = 0; i < 30000; i++)
        this->m_arr[i] = 0;

    this->m_name = "";

    this->instructable[0] = new IncrementPtr();
    this->instructable[1] = new DecrementPtr();
    this->instructable[2] = new IncrementVal();
    this->instructable[3] = new DecrementVal();
    this->instructable[4] = new WhileOpen();
    this->instructable[5] = new WhileClose();
    this->instructable[6] = new GetChar();
    this->instructable[7] = new PutChar();

    this->it = this->instructions.begin();

    //this->instructable[0] = new IncrementPtr();
}

MindSetProgram::~MindSetProgram(void){
    for (int i = 0; i < 8; i++)
        delete this->instructable[i];
    for (this->it = this->instructions.begin(); this->it != this->instructions.end(); it++)
        delete *it;
}

const char* MindSetProgram::CouldntReadFileException::what(void) const throw(){return ("Couldnr read from file");}
const char* MindSetProgram::SyntaxErrorException::what(void) const throw(){return ("Wrong syntax found");}
const char* MindSetProgram::SegFaultException::what(void) const throw(){return ("MindOpen segv");}

void MindSetProgram::execute(void)
{
    //this->it = this->instructions.begin();
    if (this->m_debuging)
        std::cout << "Proggram instructions count: " << this->instructions.size() << std::endl;
    for (this->it = this->instructions.begin(); this->it != this->instructions.end(); this->it++)
    {
        IInstruction* i = *this->it;
        if (this->m_debuging)
            std::cout << "Instruction: " << (*this->it)->getInstruction() << std::endl;
        if (!*it)
            break ;
        i->execute(*this);
    }
}

std::string MindSetProgram::readFile(const std::string& filename)
{
        std::ifstream in(filename, std::ios::in | std::ios::binary);
    if (in)
    {
        std::ostringstream contents;
        contents << in.rdbuf();
        in.close();
        return(contents.str());
    }
    else
        throw MindSetProgram::CouldntReadFileException();
}

void MindSetProgram::checkSyntax(const std::string& filestr)
{
    int bracket_balance = 0;
    std::cout << "SYNTAX CHECK:" << std::endl;
    for (std::string::const_iterator it = filestr.begin(); it != filestr.end(); it++)
    {
        if (*it == '[')
        {
            std::cout << "  --Found open" << std::endl;
            bracket_balance++;
        }
        if (*it == ']')
        {
            std::cout << "  --Found close" << std::endl;
            if (bracket_balance <= 0)
                throw MindSetProgram::SyntaxErrorException();
            bracket_balance--;
        }
    }
    std::cout << "Ended with balance: " << bracket_balance << std::endl;
    if (bracket_balance != 0)
        throw MindSetProgram::SyntaxErrorException();
}

void MindSetProgram::saveInstruction(const char c)
{
    if (ISINSTRUCTION(c))
    {
        for (int i = 0; i < 8; i++)
            if (c == this->charinstructable[i])
            {
                std::cout << "  --Saving instruction n: " << i << ", (" << this->charinstructable[i] << ")" << std::endl;
                this->instructions.push_back(reinterpret_cast<IInstruction*>(this->instructable[i]->clone()));
                return ;
            }
    }
}

bool MindSetProgram::compile(const std::string& filename)
{
    std::string filestr;
    try
    {
        filestr = this->readFile(filename);
        this->checkSyntax(filestr);
        for (std::string::iterator it = filestr.begin(); it != filestr.end(); it++)
            this->saveInstruction(*it);
        return (true);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}

void MindSetProgram::setName(std::string& name){this->m_name = name;}