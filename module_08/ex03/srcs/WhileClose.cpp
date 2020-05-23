#include "WhileClose.hpp"
#include <iostream>

WhileClose::WhileClose(void){}
WhileClose::~WhileClose(void){}

void WhileClose::execute(MindSetProgram& m) const
{
    int n = 0;
    if (m.m_debuging)
        std::cout << "  while close, m_ptr = " << m.m_ptr << ", *m_ptr = " << (int)m.m_arr[m.m_ptr] << std::endl;
    if (m.m_arr[m.m_ptr]){
        while ((*(m.it))->getInstruction() != '[' || n)
        {
            if (m.m_debuging)
                std::cout << "      Retrocede" << std::endl;
            if ((*m.it)->getInstruction() == '['){
                n--;
                if (m.m_debuging)
                    std::cout << "      Otro abierto: " << n << std::endl;
            }
            m.it--;
            if ((*m.it)->getInstruction() == ']'){
                n++;
                if (m.m_debuging)
                    std::cout << "      Otro cerrado: " << n << std::endl;
            }
        }
    }
}

IInstruction* WhileClose::clone(void) const{return (new WhileClose);}

char WhileClose::getInstruction(void) const{return (']');}