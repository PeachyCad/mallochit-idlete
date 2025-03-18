#include "framework_proxy.h"

ConcreteFrameworkProxy::ConcreteFrameworkProxy(std::shared_ptr<Mediator> mediator_)
    : mediator(mediator_) {}

void ConcreteFrameworkProxy::receive(std::unique_ptr<Command> command) {
    /// Additional logic for handling commands from the virtual machine
    std::cout << "Framework Proxy: received command" << std::endl;
    command->execute();
}

void ConcreteFrameworkProxy::send(std::unique_ptr<Command> command) {
    mediator->send(std::move(command));
}

void ConcreteFrameworkProxy::setMediator(std::shared_ptr<Mediator> mediator_) {
    mediator = mediator_;
}
