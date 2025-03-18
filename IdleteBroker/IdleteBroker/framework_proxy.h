#pragma once
#include <memory>
#include <iostream>
#include "proxy.h"
#include "mediator.h"

using namespace std;

class FrameworkProxy : public Proxy {
public:
    virtual ~FrameworkProxy() = default;
};

/// Concrete framework proxy implementation
class ConcreteFrameworkProxy : public FrameworkProxy {
private:
    std::shared_ptr<Mediator> mediator;

public:
    explicit ConcreteFrameworkProxy(std::shared_ptr<Mediator> mediator_);

    void receive(std::unique_ptr<Command> command) override;
    void send(std::unique_ptr<Command> command) override;
    void setMediator(std::shared_ptr<Mediator> mediator) override;
};
