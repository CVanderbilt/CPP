#include "Squad.hpp"
#include <iostream>

Squad::Squad(void): size(0), arr(0){}
Squad::Squad(const Squad& s): size(0), arr(0){
    *this = s;
}
Squad::~Squad(void){
	std::cout << "sqyad delete" << std::endl;
	this->deleteOldSquad();
}

Squad& Squad::operator=(const Squad& s){
    int i, j;
    ISpaceMarine **list;

	std::cout << "copy operator:" << std::endl;
    j = -1;
    i = s.getCount();
    list = new ISpaceMarine*[i];
    while (++j < i)
        list[j] = s.getUnit(j)->clone();
    j = -1;
	if (this->arr)
		delete[] this->arr;
    this->arr = list;
    return (*this);
}

//others
void	Squad::deleteOldSquad(void)
{
	if (this->arr)
	{
		getchar();
		for (int j = 0; j < this->size; j++)
		{
			std::cout << "deleting: " << j << std::endl;
			getchar();
			//delete this->arr[j];
		}
		delete this->arr;
	}
}

int Squad::push(ISpaceMarine* m_ptr){
    ISpaceMarine **list;

    for (int i = 0; i < this->size; ++i)
        if (this->arr[i] == m_ptr)
            return (this->size);
    list = new ISpaceMarine*[this->size + 1];
    for (int i = 0; i < this->size; i++)
        list[i] = this->arr[i];
    list[this->size] = m_ptr;
	this->deleteOldSquad();
    this->arr = list;
    this->size += 1;
    return (this->size);
}

//get & set
int Squad::getCount(void) const{return (this->size);}
ISpaceMarine* Squad::getUnit(int index) const{
    if (this->size > index && index >= 0)
        return (this->arr[index]);
    return (0);
}