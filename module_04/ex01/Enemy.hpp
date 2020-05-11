#ifndef ENEMY_HPP
# define ENEMY_HPP
# include <iostream>

class Enemy
{
    private:
        Enemy(void);
    protected:
        std::string type;
        int hit_points;
    public:
        Enemy(int hp, std::string const & type);
        Enemy(const Enemy&);
        virtual ~Enemy();

        Enemy& operator=(const Enemy&);

        virtual void takeDamage(int);

        std::string const &getType() const;
        int getHP() const;
};

#endif