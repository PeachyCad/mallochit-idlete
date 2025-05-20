#include "vm_proxy.h"

ConcreteVMProxy::ConcreteVMProxy(std::shared_ptr<Mediator> mediator_)
    : mediator(mediator_) {}

void ConcreteVMProxy::receive(std::unique_ptr<Command> command) {
    /// Additional logic for handling commands from the framework
    std::cout << "VM Proxy: received command" << std::endl;
    command->execute();
}

void ConcreteVMProxy::send(std::unique_ptr<Command> command) {
    mediator->send(std::move(command));
}

void ConcreteVMProxy::setMediator(std::shared_ptr<Mediator> mediator_) {
    mediator = mediator_;
}
