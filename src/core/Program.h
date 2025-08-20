#pragma once
#include <vector>
#include "../ecs/EcsSystem.h"

namespace core {

class Program {
public:
    virtual ~Program() = default;
    void addSystem(ecs::EcsSystem* sys);
    int run();

protected:
    virtual bool init() { return true; }
    virtual void update();
    virtual void shutdown() {}

    std::vector<ecs::EcsSystem*> m_systems;
};

} // namespace core
