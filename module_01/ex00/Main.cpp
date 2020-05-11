#include "Pony.hpp"

void    ponyOnTheHeap()
{
    Pony *pony1 = new Pony;
    
    pony1->doThings();
    delete (pony1);
}

void    ponyOnTheStack()
{
    Pony pony1;
    pony1.doThings();
}

int main(void)
{
    ponyOnTheStack();
    ponyOnTheHeap();
    return (0);
}