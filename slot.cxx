#include "slot.hxx"
#include <iostream>

Slot::Slot() {}

void Slot::slayMe()
{
    std::cout << "slayed u xd\n";
};

void Slot::slayMeWithString(std::string &str)
{
    std::cout << str << "\n";
};

void Slot::slayWithIinteger(int in)
{
    std::cout << in << "\n";
};
