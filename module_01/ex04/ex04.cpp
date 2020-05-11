#include <iostream>

int main(void)
{   
    std::string *the_pointer;
    std::string the_string;

    the_string = "HI THIS IS BRAIN";
    std::string &the_reference = the_string;
    the_pointer = &the_string;
    
    std::cout << "the string using the pointer: " << *the_pointer << std::endl;
    std::cout << "the string using the reference: " << the_reference << std::endl;

    return (0);
}