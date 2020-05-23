#ifndef INCREMENTVAL_HPP
# define INCREMENTVAL_HPP

#include "IInstruction.hpp"

class IncrementVal: public IInstruction
{
    public:
        IncrementVal(void);
        virtual ~IncrementVal(void);

        void execute(MindSetProgram&) const;
        char getInstruction(void) const;
        IInstruction* clone(void) const;

    private:
        IncrementVal(const IncrementVal&);
        IncrementVal& operator=(const IncrementVal&);
};

#endif