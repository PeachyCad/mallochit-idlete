#pragma once
#include <iostream>

using namespace std;

class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

/// Concrete command implementations
class NotifyIdleCommand : public Command {
public:
    void execute() override { std::cout << "Notify Idle" << std::endl; }
};

class KillIsolateCommand : public Command {
public:
    void execute() override { std::cout << "Kill Isolate" << std::endl; }
};