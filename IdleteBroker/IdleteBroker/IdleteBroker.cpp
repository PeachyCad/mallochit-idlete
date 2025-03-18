#include <memory>
#include "command.h"
#include "mediator.h"
#include "framework_proxy.h"
#include "vm_proxy.h"

using namespace std;

int main() {
    /// First create proxies with null mediator
    auto frameworkProxy = std::make_shared<ConcreteFrameworkProxy>(nullptr);
    auto vmProxy = std::make_shared<ConcreteVMProxy>(nullptr);

    /// Then create mediator with the proxies
    auto mediator = std::make_shared<ConcreteMediator>(frameworkProxy, vmProxy);

    /// Set mediator in proxies
    dynamic_cast<ConcreteFrameworkProxy*>(frameworkProxy.get())->setMediator(mediator);
    dynamic_cast<ConcreteVMProxy*>(vmProxy.get())->setMediator(mediator);

    /// Send commands using the proxies
    frameworkProxy->send(std::make_unique<NotifyIdleCommand>());
    vmProxy->send(std::make_unique<KillIsolateCommand>());

    return 0;
}
