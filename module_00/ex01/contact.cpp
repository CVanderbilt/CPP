#include "contact.hpp"
#include <iostream>

const std::string Contact::field_names[] = {
    "first name",
    "last name",
    "nickname",
    "login",
    "postal address",
    "email address",
    "phone number",
    "birthday",
    "favourite meal",
    "underwear colour",
    "darkest secret"
};

Contact::Contact(void){
}

void    Contact::setInfo(void)
{
    std::string input;
    int i;

    std::cout << "Creating contact..." << std::endl;
    i = -1;
    while (++i < 11)
    {
        std::cout << "please, input your " << this->field_names[i] << std::endl;
        std::cin >> input;
        this->fields[i] = input;
    }
}

void    Contact::displayInfo(void)
{
    int i;

    i = -1;
    while (++i < 11)
        std::cout << this->field_names[i] << ": " << this->fields[i] << std::endl;
}