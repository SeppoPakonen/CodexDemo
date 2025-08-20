#include "GraphSystem.h"

namespace ecs {

void GraphSystem::addSystem(EcsSystem* sys) {
    if (sys && sys != this)
        m_systems.push_back(sys);
}

void GraphSystem::enqueue(graph::Packet* pkt) {
    if (pkt)
        m_packets.push(pkt);
}

void GraphSystem::update() {
    while (!m_packets.empty()) {
        graph::Packet* pkt = m_packets.front();
        m_packets.pop();
        for (EcsSystem* sys : m_systems) {
            sys->onPacket(*pkt);
        }
        graph::PacketRecycler::instance().recycle(pkt);
    }
}

} // namespace ecs
