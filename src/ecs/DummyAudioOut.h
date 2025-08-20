#pragma once
#include "EcsSystem.h"
#include "GraphSystem.h"

namespace ecs {

class DummyAudioOut : public EcsSystem {
public:
    explicit DummyAudioOut(GraphSystem& g)
        : EcsSystem("DummyAudioOut"), m_graph(g) {}
    void setTarget(hash_t addr) { m_target = addr; }
    void update() override;
    void onPacket(graph::Packet&) override {}
private:
    GraphSystem& m_graph;
    hash_t m_target{0};
    uint32_t m_seq{0};
};

} // namespace ecs
