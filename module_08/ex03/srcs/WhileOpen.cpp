#include "WhileOpen.hpp"
#include <iostream>

WhileOpen::WhileOpen(void){}
WhileOpen::~WhileOpen(void){}

void WhileOpen::execute(MindSetProgram& m) const
{
    int n = 0;
    if (m.m_debuging)
        std::cout << "  while open, m_ptr = " << m.m_ptr << ", *m_ptr = " << (int)m.m_arr[m.m_ptr] << std::endl;
    if (!m.m_arr[m.m_ptr]){
        //std::cout << "  while open, instr-> " << (*(m.it))->getInstruction() << std::endl;
        //while (m.instructable[*m.it]->getInstruction() != '[')
        while ((*(m.it))->getInstruction() != ']' || n)
        {
            if (m.m_debuging)
                std::cout << "      Salta" << std::endl;
            if ((*m.it)->getInstruction() == ']'){
                n--;
                if (m.m_debuging)
                    std::cout << "      -Otro cerrado: " << n << std::endl;
            }
            m.it++;
            if ((*m.it)->getInstruction() == '['){
                n++;
                if (m.m_debuging)
                    std::cout << "      -Otro abierto: " << n << std::endl;
            }
        }
    }
}

IInstruction* WhileOpen::clone(void) const{return (new WhileOpen);}

char WhileOpen::getInstruction(void) const{return ('[');}