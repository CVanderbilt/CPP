#include <string>

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact 
{
    private:
        /*std::string fields[11]
        {
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
        };*/

    public:
        static const std::string field_names[];
        std::string fields[11];
        void    setInfo(void);
        void    displayInfo(void);
        
        Contact (void);
};
#endif