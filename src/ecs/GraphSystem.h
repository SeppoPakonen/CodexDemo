#pragma once
#include <vector>
#include <queue>
#include "EcsSystem.h"
#include "../graph/PacketRecycler.h"

namespace ecs {

class GraphSystem : public EcsSystem {
public:
    void addSystem(EcsSystem* sys);
    void enqueue(graph::Packet* pkt);

    std::string name() const override { return "GraphSystem"; }
    void update() override;
    void onPacket(graph::Packet& pkt) override { enqueue(&pkt); }

private:
    std::vector<EcsSystem*> m_systems;
    std::queue<graph::Packet*> m_packets;
};

} // namespace ecs
