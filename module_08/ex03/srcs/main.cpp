#include <iostream>

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

int main(int argc, char* argv[])
{
    MindSetProgram myprog;
    std::string str, flag;

    if (argc > 3 || argc < 2)
    {
        std::cout << "Wrong number of parameters" << std::endl;
        return (1);
    }

    if (argc == 3){
        flag = argv[1];
        myprog.m_debuging = flag == "-g" ? true : false;
        str = argv[2];
    }
    else
        str = argv[1];
    

    if (myprog.compile(str))
    {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Succesful compilation" << std::endl;
        myprog.execute();
        std::cout << std::endl;
        std::cout << std::endl;
    }
    else
        std::cout << "Couldnt compile" << std::endl;

    return (0);
}