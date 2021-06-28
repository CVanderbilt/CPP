# include <iostream>
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include "CentralBureaucracy.hpp"

/*check_ignore*/

int main(void)
{
    srand (time(NULL));

    CentralBureaucracy cb;

    Bureaucrat b1("Buro_1", rand() % 150 + 1);
    Bureaucrat b2("Buro_2", rand() % 150 + 1);
    Bureaucrat b3("Buro_3", rand() % 150 + 1);
    Bureaucrat b4("Buro_4", rand() % 150 + 1);
    Bureaucrat b5("Buro_5", rand() % 150 + 1);
    Bureaucrat b6("Buro_6", rand() % 150 + 1);
    Bureaucrat b7("Buro_7", rand() % 150 + 1);
    Bureaucrat b8("Buro_8", rand() % 150 + 1);
    Bureaucrat b9("Buro_9", rand() % 150 + 1);
    Bureaucrat b10("Buro_10", rand() % 150 + 1);
    Bureaucrat b11("Buro_11", rand() % 150 + 1);
    Bureaucrat b12("Buro_12", rand() % 150 + 1);
    Bureaucrat b13("Buro_13", rand() % 150 + 1);
    Bureaucrat b14("Buro_14", rand() % 150 + 1);
    Bureaucrat b15("Buro_15", rand() % 150 + 1);
    Bureaucrat b16("Buro_16", rand() % 150 + 1);
    Bureaucrat b17("Buro_17", rand() % 150 + 1);
    Bureaucrat b18("Buro_18", rand() % 150 + 1);
    Bureaucrat b19("Buro_19", rand() % 150 + 1);
    Bureaucrat b20("Buro_20", rand() % 150 + 1);
    Bureaucrat b21("Buro_21", rand() % 150 + 1);

    cb.feed(b1);
    cb.feed(b2);
    cb.feed(b3);
    cb.feed(b4);
    cb.feed(b5);
    cb.feed(b6);
    cb.feed(b7);
    cb.feed(b8);
    cb.feed(b9);
    cb.feed(b10);
    cb.feed(b11);
	cb.feed(b4);
    cb.feed(b12);
    cb.feed(b13);
    cb.feed(b14);
    cb.feed(b15);
    cb.feed(b16);
    cb.feed(b17);
    cb.feed(b18);
    cb.feed(b19);
    cb.feed(b20);
    cb.feed(b21);
    

    cb.queueUp("1_en_cola");
    cb.queueUp("2_en_cola");
    cb.queueUp("3_en_cola");
    cb.queueUp("4_en_cola");
    cb.queueUp("5_en_cola");
    cb.queueUp("6_en_cola");
    cb.queueUp("7_en_cola");
    cb.queueUp("8_en_cola");
    cb.queueUp("9_en_cola");
    cb.queueUp("10_en_cola");
    cb.queueUp("11_en_cola");
    cb.queueUp("12_en_cola");
    cb.queueUp("13_en_cola");
    cb.queueUp("14_en_cola");
    cb.queueUp("15_en_cola");
    cb.queueUp("16_en_cola");
    cb.queueUp("17_en_cola");
    cb.queueUp("18_en_cola");
    cb.queueUp("19_en_cola");
    cb.queueUp("20_en_cola");
    cb.queueUp("21_en_cola");
    cb.queueUp("22_en_cola");
    cb.queueUp("23_en_cola");
    cb.queueUp("24_en_cola");
    cb.queueUp("25_en_cola");

    for (int i = 0; i < cb.getQueuesize(); i++)
        std::cout << "(Queue: "  << i << ")> " << cb.getQueue()[i] << std::endl;

    std::cout << "Start doing bureaucracy" << std::endl << std::endl;
    cb.doBureaucracy();

    return (0);
}