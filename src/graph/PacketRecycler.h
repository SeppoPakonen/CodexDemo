#pragma once
#include <vector>
#include "Packet.h"

namespace graph {

class PacketRecycler {
public:
    static PacketRecycler& instance();

    Packet* acquire();
    void recycle(Packet* pkt);

private:
    PacketRecycler();
    std::vector<Packet*> m_pool;
    Packet* m_free{nullptr};
};

} // namespace graph
