#include "IncrementVal.hpp"

IncrementVal::IncrementVal(void){}
IncrementVal::~IncrementVal(void){}

void IncrementVal::execute(MindSetProgram& m) const
{
    m.m_arr[m.m_ptr] += 1;
}

IInstruction* IncrementVal::clone(void) const{return (new IncrementVal);}

char IncrementVal::getInstruction(void) const{return ('+');}