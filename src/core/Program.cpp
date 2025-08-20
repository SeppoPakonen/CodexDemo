#include "Program.h"

namespace core {

void Program::addSystem(ecs::EcsSystem* sys) {
    if (sys)
        m_systems.push_back(sys);
}

int Program::run() {
    if (!init()) return -1;
    for (int i = 0; i < 3; ++i) { // simple loop
        update();
        for (auto* sys : m_systems) {
            sys->update();
        }
    }
    shutdown();
    return 0;
}

void Program::update() {}

} // namespace core
