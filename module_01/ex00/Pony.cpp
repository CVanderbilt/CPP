        #include "Pony.hpp"
        
        Pony::Pony(int a, int w, std::string name)
        : age(a), weight(w), name(name){}
        Pony::~Pony()
        {
            std::cout << "Pony named " << this->getName() << " destroyed" << std::endl;
        }
        int         Pony::getWeight(void){
            return (this->weight);
        }
        int         Pony::getAge(void){
            return (this->age);
        }
        std::string Pony::getName(void){
            return (this->name);
        }
        void        Pony::doThings(void)
        {
            std::cout << "Pony named " << this->getName() << " is doing something:" << std::endl;
            std::cout << "  age: " << this->getAge() << " weight " << this->getWeight() << std::endl;
        }