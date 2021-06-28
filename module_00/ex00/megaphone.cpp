#include <iostream>
#include <string>
#include <locale>

//check_ignore

int main(int argc, char *argv[])
{
    int i;
    
    i = 1;
    if (argc <= 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
        while (i < argc)
        {
            std::string str = argv[i];
            for (std::string::iterator it = str.begin() ; it != str.end(); ++it)
		        std::cout << (char)toupper(*it);

            i++;
        }
    std::cout << std::endl;
    return (0);
}