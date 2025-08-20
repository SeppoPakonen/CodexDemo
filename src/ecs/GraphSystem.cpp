#include "GraphSystem.h"

namespace ecs {

void GraphSystem::addSystem(EcsSystem* sys) {
    if (sys && sys != this) {
        m_systems[sys->address()] = sys;
    }
}

void GraphSystem::enqueue(graph::Packet* pkt) {
    if (pkt)
        m_packets.push(pkt);
}

void GraphSystem::update() {
    while (!m_packets.empty()) {
        graph::Packet* pkt = m_packets.front();
        m_packets.pop();
        auto it = m_systems.find(pkt->address);
        if (it != m_systems.end()) {
            graph::PacketFormat fmt = pkt->format;
            it->second->onPacket(*pkt);
            if (pkt->format == fmt && pkt->address != 0) {
                m_packets.push(pkt);
            } else {
                graph::PacketRecycler::instance().recycle(pkt);
            }
        } else {
            graph::PacketRecycler::instance().recycle(pkt);
        }
    }
}

} // namespace ecs
