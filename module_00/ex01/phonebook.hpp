#include <string>

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

class Phonebook
{
    private:
        int     num;
        int     list_size;
        Contact contacts[8];
    public:
        Phonebook();
        void    addContact(void);
        void    showList(void);
        void    addNum(void);
        void    setNum(int num);
        void    setSize(int num);
        void    displayNormedField(int contact, int field);
        void    showContact(int index);
        void    getIndex(void);
        int     getNum(void);
        int     getSize(void);
};
#endif