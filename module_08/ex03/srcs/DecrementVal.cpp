#include "DecrementVal.hpp"

DecrementVal::DecrementVal(void){}
DecrementVal::~DecrementVal(void){}

void DecrementVal::execute(MindSetProgram& m) const
{
    m.m_arr[m.m_ptr]--;
}

IInstruction* DecrementVal::clone(void) const{return (new DecrementVal);}

char DecrementVal::getInstruction(void) const{return ('-');}