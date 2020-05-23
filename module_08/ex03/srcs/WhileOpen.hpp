#ifndef WHILEOPEN_HPP
# define WHILEOPEN_HPP

#include "IInstruction.hpp"

class WhileOpen: public IInstruction
{
    public:
        WhileOpen(void);
        virtual ~WhileOpen(void);

        void execute(MindSetProgram&) const;
        char getInstruction(void) const;
        IInstruction* clone(void) const;

    private:
        WhileOpen(const WhileOpen&);
        WhileOpen& operator=(const WhileOpen&);
};

#endif