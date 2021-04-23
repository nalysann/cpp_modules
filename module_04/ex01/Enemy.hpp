#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>

class Enemy {
  public:
    Enemy();
    Enemy(int hp, const std::string& type);
    Enemy(const Enemy& other);
    Enemy& operator=(const Enemy& other);
    virtual ~Enemy();

    const std::string& getType() const;
    int getHP() const;

    virtual void takeDamage(int damage);

  protected:
    int _hp;
    std::string _type;
};

#endif
