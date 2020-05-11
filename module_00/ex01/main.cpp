#include <iostream>
#include <string>
#include "contact.hpp"
#include "phonebook.hpp"

void    ft_add(Phonebook *book)
{
    book->addContact();
}

void    ft_search(Phonebook *book)
{
    book->showList();
}

int     main()
{
    std::string input;
    Phonebook phonebook;
    

    while (input.compare("EXIT"))
    {
        std::cout << "Input a command (ADD, SEARCH, EXIT)" << std::endl;
        std::cin >> input;
        if (!input.compare("ADD"))
            ft_add(&phonebook);
        else if (!input.compare("SEARCH"))
            ft_search(&phonebook);
        else if (input.compare("EXIT"))
            std::cout << "Invalid input" << std::endl;
    }
}