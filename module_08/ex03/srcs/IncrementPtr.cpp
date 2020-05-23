#include "IncrementPtr.hpp"
#include <iostream>

IncrementPtr::IncrementPtr(void){}
IncrementPtr::~IncrementPtr(void){}

void IncrementPtr::execute(MindSetProgram& m) const
{
    if (m.m_ptr < 30000)
        m.m_ptr += 1;
    if (m.m_debuging)
        std::cout << "  incremented ptr: " << m.m_ptr << ", *ptr: " << (int)m.m_arr[m.m_ptr] << std::endl;
}

IInstruction* IncrementPtr::clone(void) const{return (new IncrementPtr);}

char IncrementPtr::getInstruction(void) const{return ('>');}