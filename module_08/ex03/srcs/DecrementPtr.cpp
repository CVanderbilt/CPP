#include "DecrementPtr.hpp"
#include <iostream>

DecrementPtr::DecrementPtr(void){}
DecrementPtr::~DecrementPtr(void){}

void DecrementPtr::execute(MindSetProgram& m) const
{
    if (m.m_ptr)
        m.m_ptr -= 1;
    if (m.m_debuging)
        std::cout << "  decremented ptr: " << m.m_ptr << ", *ptr: " << (int)m.m_arr[m.m_ptr] << std::endl;
}

IInstruction* DecrementPtr::clone(void) const{return (new DecrementPtr);}

char DecrementPtr::getInstruction(void) const{return ('<');}