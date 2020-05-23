#include <string>

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact 
{
    private:
        static const std::string field_names[];
        std::string fields[11];
    public:
        void    setInfo(void);
        void    displayInfo(void);
        
        std::string getField(int idx) const;
        std::string getFieldName(int idx) const;

        Contact(void);
};
#endif