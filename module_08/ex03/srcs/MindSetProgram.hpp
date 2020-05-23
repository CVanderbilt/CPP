#ifndef MINDSETPROGRAM
# define MINDSETPROGRAM
# include <deque>
# include <vector>
# include <iostream>

class MindSetProgram;

#include "IInstruction.hpp"

class MindSetProgram
{
    public:
        std::string m_name;
        bool m_debuging;
        IInstruction *instructable[8];
        static const char charinstructable[8];
        //std::vector<IInstruction*> instructions;
        //std::vector<IInstruction*>::iterator it;

        std::deque<IInstruction*> instructions;
        std::deque<IInstruction*>::iterator it;
        char m_arr[30000];
        int m_ptr;

        MindSetProgram(void);
        ~MindSetProgram(void);

        class CouldntReadFileException: public std::exception{
            const char* what(void) const throw();
        };
        class SyntaxErrorException: public std::exception{
            const char* what(void) const throw();
        };
        class SegFaultException: public std::exception{
            const char* what(void) const throw();
        };

        std::string readFile(const std::string&);
        void checkSyntax(const std::string&);
        bool compile(const std::string&);
        void saveInstruction(const char);
        void execute(void);

        void setName(std::string&);
    private:
        MindSetProgram(const MindSetProgram&);
        MindSetProgram& operator=(const MindSetProgram&);
        
};

#endif