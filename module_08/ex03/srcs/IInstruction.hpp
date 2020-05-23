#ifndef IINSTRUCTION_HPP
# define IINSTRUCTION_HPP

class IInstruction;

#include "MindSetProgram.hpp"

class IInstruction
{
    public:

    //IInstruction(void);
    virtual ~IInstruction(void){};

    //bool compare(const char) const;
    virtual void execute(MindSetProgram&) const = 0;
    virtual char getInstruction(void) const = 0;
    virtual IInstruction* clone(void) const = 0;

    private:
    //IInstruction(const IInstruction&);
    //IInstruction& operator=(const IInstruction&);
};

#endif