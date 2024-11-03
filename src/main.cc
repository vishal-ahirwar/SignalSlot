
// Auto Genrated C++ file by newton CLI
// Copyright 2023 Vishal Ahirwar //replace it with your copyright notice!
#include "../slot.hxx"
#include <functional>
#include <iostream>
#include <vector>
template <typename... Args>
class Signal
{
private:
    std::vector<std::function<void(Args...)>> _slots;
public:
    template <class T>
    void connect(T *instance, void (T::*func)(Args...))
    {
        _slots.push_back([=](Args... args) -> void { (instance->*func)(args...); });
    };

    void connect(std::function<void(Args...)> func) { _slots.push_back(func); };

    void emit(Args... args)
    {
        for (auto &slot : _slots) {
            slot(args...);
        }
    }
};

int main(int argc, char *argv[])
{
    Signal signal;
    Slot slot;
    signal.connect(&slot, &Slot::slayMe);
    signal.connect([=]() -> void { std::cout << "hello,there!\n"; });
    signal.emit();
    return 0;
};
