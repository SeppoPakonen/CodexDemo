#include "PacketRecycler.h"
#include <iostream>

namespace graph {

PacketRecycler& PacketRecycler::instance() {
    static PacketRecycler inst;
    return inst;
}

PacketRecycler::PacketRecycler() {
    // Pre-allocate a small pool
    const int initial = 32;
    m_pool.reserve(initial);
    for (int i = 0; i < initial; ++i) {
        Packet* p = new Packet();
        p->next = m_free;
        m_free = p;
        m_pool.push_back(p);
    }
}

Packet* PacketRecycler::acquire() {
    if (!m_free) {
        // allocate new packet if pool exhausted
        Packet* p = new Packet();
        m_pool.push_back(p);
        return p;
    }
    Packet* p = m_free;
    m_free = m_free->next;
    p->next = nullptr;
    p->format = PacketFormat::Unknown;
    return p;
}

void PacketRecycler::recycle(Packet* pkt) {
    if (!pkt) return;
    pkt->next = m_free;
    m_free = pkt;
}

} // namespace graph
