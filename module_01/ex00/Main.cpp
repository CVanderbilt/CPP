#include "Pony.hpp"

void    ponyOnTheHeap()
{
    Pony *pony1 = new Pony(10, 100, "heap");
    
    pony1->doThings();
    delete (pony1);
}

void    ponyOnTheStack()
{
    Pony pony1(13, 100, "stack");
    pony1.doThings();
}

int main(void)
{
    ponyOnTheStack();
    ponyOnTheHeap();
    return (0);
}