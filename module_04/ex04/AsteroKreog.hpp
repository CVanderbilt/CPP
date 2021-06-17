#ifndef ASTEROKREOG_HPP
# define ASTEROKREOG_HPP

# include "IAsteroid.hpp"

class AsteroKreog: public IAsteroid
{
    private:
    public:
        AsteroKreog(void);
        AsteroKreog(const AsteroKreog&);
        virtual ~AsteroKreog(void);

        AsteroKreog& operator=(const AsteroKreog&);

        std::string beMined(StripMiner*) const;
        std::string beMined(DeepCoreMiner*) const;
        std::string getName() const;

};

#endif