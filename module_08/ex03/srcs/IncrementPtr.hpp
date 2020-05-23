#ifndef INCREMENTPTR_HPP
# define INCREMENTPTR_HPP

#include "IInstruction.hpp"

class IncrementPtr: public IInstruction
{
    public:
        IncrementPtr(void);
        virtual ~IncrementPtr(void);

        void execute(MindSetProgram&) const;
        char getInstruction(void) const;
        IInstruction* clone(void) const;

    private:
        IncrementPtr(const IncrementPtr&);
        IncrementPtr& operator=(const IncrementPtr&);
};

#endif