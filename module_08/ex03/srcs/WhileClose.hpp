#ifndef WHILECLOSE_HPP
# define WHILECLOSE_HPP

#include "IInstruction.hpp"

class WhileClose: public IInstruction
{
    public:
        WhileClose(void);
        virtual ~WhileClose(void);

        void execute(MindSetProgram&) const;
        char getInstruction(void) const;
        IInstruction* clone(void) const;

    private:
        WhileClose(const WhileClose&);
        WhileClose& operator=(const WhileClose&);
};

#endif