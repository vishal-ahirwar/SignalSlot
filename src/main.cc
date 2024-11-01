
// Auto Genrated C++ file by newton CLI
// Copyright 2023 Vishal Ahirwar //replace it with your copyright notice!
#include <iostream>
#include <vector>
#include <functional>

template <typename... Args>
class Signal
{
private:
    std::vector<std::function<void(Args...)>> _slots;
    std::vector<void (*)(Args...)> _cpslots;

public:
    template <class T>
    void connect(T *instance, void (T::*func)(Args...))
    {
        _slots.push_back([&](Args... args)->void
                         { (instance->*func)(args...); });
    };
    void connect(void (*func)(Args...))
    {
        _cpslots.push_back(func);
    };

    void emit(Args... args)
    {
        for (auto &slot : _slots)
        {
            std::cout << "vector :  ";
            slot(args...);
        }
        for (auto &slot : _cpslots)
        {
            std::cout << "C pointer : ";
            slot(args...);
        };
    }
};

class Slot
{
public:
    void caller(std::string &str)
    {
        std::cout << str << " : caller()\n";
    };
};

struct Test
{
    void call(std::string &str)
    {
        std::cout << str << "\nstruct Test is here!\n";
    }
};
class Another
{
public:
    void anotherCaller(std::string &str)
    {
        std::cout << str << "\nanother caller()\n";
    }
};
void func(std::string &str) { std::cout << str << "whatsup\n"; }
int main(int argc, char *argv[])
{
    Signal<std::string &> signal;
    Slot slot;
    Test test;
    Another another;
    std::string test_string{std::string("das ko choni hai")};
    signal.connect(&slot, &Slot::caller);
    signal.connect(&another, &Another::anotherCaller);
    signal.connect(&test, &Test::call);
    signal.connect([](std::string &str)
                   { std::cout << str << " hello,there\n"; });
    signal.connect(func);
    signal.emit(test_string);
    return 0;
};
