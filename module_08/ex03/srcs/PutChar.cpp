#include <iostream>
#include "PutChar.hpp"

PutChar::PutChar(void){}
PutChar::~PutChar(void){}

void PutChar::execute(MindSetProgram& m) const
{
    if (m.m_debuging)
        std::cout << "  putchar: " << (int)m.m_arr[m.m_ptr] << std::endl;
    std::cout << m.m_arr[m.m_ptr];
}

IInstruction* PutChar::clone(void) const{return (new PutChar);}

char PutChar::getInstruction(void) const{return ('.');}