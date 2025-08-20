#pragma once
#include "EcsSystem.h"

namespace ecs {

class SDL3_Audio_System : public EcsSystem {
public:
    std::string name() const override { return "SDL3_Audio"; }
    void update() override {}
    void onPacket(graph::Packet& pkt) override { (void)pkt; }
};

} // namespace ecs
