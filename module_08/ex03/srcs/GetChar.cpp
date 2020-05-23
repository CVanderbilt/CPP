#include <iostream>
#include "GetChar.hpp"

GetChar::GetChar(void){}
GetChar::~GetChar(void){}

void GetChar::execute(MindSetProgram& m) const
{
    m.m_arr[m.m_ptr] = getchar();
}

IInstruction* GetChar::clone(void) const{return (new GetChar);}

char GetChar::getInstruction(void) const{return (',');}