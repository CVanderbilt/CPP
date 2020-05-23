#ifndef GETCHAR_HPP
# define GETCHAR_HPP

#include "IInstruction.hpp"

class GetChar: public IInstruction
{
    public:
        GetChar(void);
        virtual ~GetChar(void);

        void execute(MindSetProgram&) const;
        char getInstruction(void) const;
        IInstruction* clone(void) const;

    private:
        GetChar(const GetChar&);
        GetChar& operator=(const GetChar&);
};

#endif