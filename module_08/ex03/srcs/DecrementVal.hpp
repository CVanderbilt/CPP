#ifndef DECREMENTVAL_HPP
# define DECREMENTVAL_HPP

#include "IInstruction.hpp"

class DecrementVal: public IInstruction
{
    public:
        DecrementVal(void);
        virtual ~DecrementVal(void);

        void execute(MindSetProgram& m) const;
        char getInstruction(void) const;
        IInstruction* clone(void) const;

    private:
        DecrementVal(const DecrementVal&);
        DecrementVal& operator=(const DecrementVal&);
};

#endif