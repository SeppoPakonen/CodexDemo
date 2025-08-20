#pragma once
#include <vector>
#include <queue>
#include <unordered_map>
#include "EcsSystem.h"
#include "../graph/PacketRecycler.h"

namespace ecs {

class GraphSystem : public EcsSystem {
public:
    GraphSystem() : EcsSystem("GraphSystem") {}
    void addSystem(EcsSystem* sys);
    void enqueue(graph::Packet* pkt);
    void update() override;
    void onPacket(graph::Packet& pkt) override { enqueue(&pkt); }

private:
    std::unordered_map<hash_t, EcsSystem*> m_systems;
    std::queue<graph::Packet*> m_packets;
};

} // namespace ecs
