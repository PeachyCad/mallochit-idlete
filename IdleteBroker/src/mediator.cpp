#include "mediator.h"
#include "proxy.h"

ConcreteMediator::ConcreteMediator(std::shared_ptr<Proxy> frameworkProxy_,
    std::shared_ptr<Proxy> vmProxy_) :
    frameworkProxy(frameworkProxy),
    vmProxy(vmProxy) {}

void ConcreteMediator::send(std::unique_ptr<Command> command) {
    /// Execute command and add any additional logic for handling commands
    command->execute();
    std::cout << "Mediator processed the command" << std::endl;
}

std::shared_ptr<Proxy> ConcreteMediator::getFrameworkProxy() const {
    return frameworkProxy;
}

std::shared_ptr<Proxy> ConcreteMediator::getVMProxy() const {
    return vmProxy;
}
