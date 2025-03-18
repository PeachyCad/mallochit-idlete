#pragma once
#include <memory>
#include "command.h"

using namespace std;

class Mediator;

class Proxy {
public:
    virtual void receive(std::unique_ptr<Command> command) = 0;
    virtual void send(std::unique_ptr<Command> command) = 0;
    virtual void setMediator(std::shared_ptr<Mediator> mediator) = 0;
    virtual ~Proxy() = default;
};
