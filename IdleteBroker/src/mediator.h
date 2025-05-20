#pragma once
#include <memory>
#include "command.h"
#include "proxy.h"

using namespace std;

class Mediator {
public:
    virtual void send(std::unique_ptr<Command> command) = 0;
    virtual ~Mediator() = default;
};

/// Concrete mediator implementation
class ConcreteMediator : public Mediator {
private:
    std::shared_ptr<Proxy> frameworkProxy;
    std::shared_ptr<Proxy> vmProxy;

public:
    ConcreteMediator(std::shared_ptr<Proxy> frameworkProxy,
        std::shared_ptr<Proxy> vmProxy);

    void send(std::unique_ptr<Command> command) override;

    std::shared_ptr<Proxy> getFrameworkProxy() const;
    std::shared_ptr<Proxy> getVMProxy() const;
};
