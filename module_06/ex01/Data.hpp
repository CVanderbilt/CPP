#ifndef DATA_HPP
# define DATA_HPP

/*check_ignore*/

    struct Data {
        std::string s1;
        int n;
        std::string s2;
    };

    uintptr_t serialize(void);
    Data* deserialize(uintptr_t raw);

#endif