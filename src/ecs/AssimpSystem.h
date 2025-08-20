#pragma once
#include "EcsSystem.h"

namespace ecs {

class AssimpSystem : public EcsSystem {
public:
    std::string name() const override { return "Assimp"; }
    void update() override {}
    void onPacket(graph::Packet& pkt) override { (void)pkt; }
};

} // namespace ecs
