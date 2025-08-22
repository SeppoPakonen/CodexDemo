#pragma once
#include "EcsSystem.h"
#include "../core/Log.h"
#include "../graph/PacketDebug.h"

namespace ecs {

class DummyAudioIn : public EcsSystem {
public:
    DummyAudioIn() : EcsSystem("DummyAudioIn") {}
    void update() override {}
    void onPacket(graph::Packet& pkt) override {
        core::Log::write(graph::toDebugString(pkt));
        pkt.address = 0; // delivered
    }
};

} // namespace ecs
