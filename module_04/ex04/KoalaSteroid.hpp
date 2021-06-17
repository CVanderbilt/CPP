#ifndef KOALASTEROID_HPP
# define KOALASTEROID_HPP

# include "IAsteroid.hpp"

class KoalaSteroid: public IAsteroid
{
    private:
    public:
        KoalaSteroid(void);
        KoalaSteroid(const KoalaSteroid&);
        virtual ~KoalaSteroid(void);

        KoalaSteroid& operator=(const KoalaSteroid&);

        std::string beMined(DeepCoreMiner*) const;
        std::string beMined(StripMiner*) const;
        std::string getName() const;

};

#endif