#ifndef DECREMENTPTR_HPP
# define DECREMENTPTR_HPP

#include "IInstruction.hpp"

class DecrementPtr: public IInstruction
{
    public:
        DecrementPtr(void);
        virtual ~DecrementPtr(void);

        void execute(MindSetProgram&) const;
        char getInstruction(void) const;
        IInstruction* clone(void) const;

    private:
        //char instruction;
        DecrementPtr(const DecrementPtr&);
        DecrementPtr& operator=(const DecrementPtr&);
};

#endif