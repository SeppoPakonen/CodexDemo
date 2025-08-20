#pragma once
#include "EcsSystem.h"

namespace ecs {

class SDL3_Context_System : public EcsSystem {
public:
    SDL3_Context_System() : EcsSystem("SDL3_Context") {}
    void update() override {}
    void onPacket(graph::Packet& pkt) override { (void)pkt; }
};

} // namespace ecs
