#pragma once
#include "EcsSystem.h"

namespace ecs {

class SDL3_Audio_System : public EcsSystem {
public:
    SDL3_Audio_System() : EcsSystem("SDL3_Audio") {}
    void update() override {}
    void onPacket(graph::Packet& pkt) override { (void)pkt; }
};

} // namespace ecs
