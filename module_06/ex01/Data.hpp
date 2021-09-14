#ifndef DATA_HPP
# define DATA_HPP

/*check_ignore*/

    struct Data {
		int n;
        std::string s1;
        std::string s2;
    };

    uintptr_t serialize(Data *ptr);
    Data* deserialize(uintptr_t raw);

#endif