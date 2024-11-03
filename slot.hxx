#ifndef SLOT_HXX
#define SLOT_HXX
#include <string>
class Slot
{
public:
    Slot();
    void slayMe();
    void slayMeWithString(std::string &str);
    void slayWithIinteger(int);
};

#endif // SLOT_HXX
