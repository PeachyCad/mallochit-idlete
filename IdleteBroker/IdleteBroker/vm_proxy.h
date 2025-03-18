#pragma once
#include <memory>
#include <iostream>
#include "proxy.h"
#include "mediator.h"

using namespace std;

class VMProxy : public Proxy {
public:
    virtual ~VMProxy() = default;
};

/// Concrete VM proxy implementation
class ConcreteVMProxy : public VMProxy {
private:
    std::shared_ptr<Mediator> mediator;

public:
    explicit ConcreteVMProxy(std::shared_ptr<Mediator> mediator_);

    void receive(std::unique_ptr<Command> command) override;
    void send(std::unique_ptr<Command> command) override;
    void setMediator(std::shared_ptr<Mediator> mediator_) override;
};
