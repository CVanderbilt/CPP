#include "phonebook.hpp"
#include <iostream>
#include <iomanip>

Phonebook::Phonebook(void)
{
    this->num = 0;
    this->list_size = 0;
}

int     Phonebook::getNum(void){
    return (this->num);
}

int     Phonebook::getSize(void){
    return (this->list_size);
}

void    Phonebook::setNum(int num){
    this->num = num;
}

void    Phonebook::setSize(int num){
    this->list_size = num;
}

void    Phonebook::addNum(void)
{
    int num;

    num = this->getNum() + 1;
    if (num >= 8)
        num = 0;
    this->setNum(num);
    num = this->getSize();
    if (num < 8)
    {
        num++;
        this->setSize(num);
    }
}

void    Phonebook::addContact(void)
{
    int num;

    num = this->getNum();
    this->contacts[num].setInfo();
    this->addNum();
}

void    Phonebook::displayNormedField(int contact, int field)
{
    if (this->contacts[contact].fields[field].length() > 10)
        std::cout << this->contacts[contact].fields[field].substr(0, 9) << ".|";
    else
        std::cout << std::setw(10) << this->contacts[contact].fields[field] << "|";
}

void    Phonebook::showContact(int index)
{
    if (index >= this->getSize() || index < 0)
        std::cout << "invalid index, cancelling operation" << std::endl;
    else
        this->contacts[index].displayInfo();
}

void    Phonebook::getIndex()
{
    int i;
    std::string str;

    std::cout << "Please input index" << std::endl;
    std::cin >> str;
    try 
    {
        i = std::stoi(str, nullptr);
    }
    catch (const std::invalid_argument& ia)
    {
        std::cerr << "Invalid argument: " << ia.what() << std::endl;
        return ;
    }
    catch (const std::out_of_range& oor)
    {
        std::cerr << "Out of Range error: " << oor.what() << std::endl;
        return ;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Undefined error: " << e.what() << std::endl;
        return ;
    }
    this->showContact(i);
}

void    Phonebook::showList(void)
{
    int i, size;
    std::string str;

    i = -1;
    size = this->getSize();
    std::cout << "showing list of size " << size << std::endl;
    std::cout << "     index|first name| last name|  nickname|" << std::endl;
    while (++i < size)
    {
        std::cout << std::setw(10) << i << "|";
        this->displayNormedField(i, 0);
        this->displayNormedField(i, 1);
        this->displayNormedField(i, 2);
        std::cout << std::endl;
    }
    this->getIndex();
}
