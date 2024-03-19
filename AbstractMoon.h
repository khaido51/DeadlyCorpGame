#ifndef ABSTRACTMOON_H
#define ABSTRACTMOON_H
 
#include <iostream>
#include <string>

class Game;
class AbstractMoon {
public:
    AbstractMoon();
    virtual ~AbstractMoon();
    const std::string& name() const;
    virtual void onDayBegin(Game& g);
    virtual void sellCargo(Game& g, int amount) = 0;
    virtual void sendEmployees(Game& g, int amount) = 0;
};

#endif // !ABSTRACTMOON_H
