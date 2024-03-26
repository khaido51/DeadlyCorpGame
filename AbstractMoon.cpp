#include "AbstractMoon.h"

AbstractMoon::AbstractMoon()
{
}

AbstractMoon::~AbstractMoon()
{
}

const std::string& AbstractMoon::name() const
{
    // TODO: insert return statement here
    return moonName;
}



void AbstractMoon::onDayBegin(Game& g)
{

}
