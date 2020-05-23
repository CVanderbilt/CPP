#ifndef PUTCHAR_HPP
# define PUTCHAR_HPP

#include "IInstruction.hpp"

class PutChar: public IInstruction
{
    public:
        PutChar(void);
        virtual ~PutChar(void);

        void execute(MindSetProgram&) const;
        char getInstruction(void) const;
        IInstruction* clone(void) const;

    private:
        PutChar(const PutChar&);
        PutChar& operator=(const PutChar&);
};

#endif