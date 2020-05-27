#include "cato9tails.hpp"

int main(int argc, char *argv[])
{
    int i = 0;
    if (argc > 1)
        while (++i < argc)
            Cato9Tails::cat(argv[i]);
    else
        Cato9Tails::cat();
}