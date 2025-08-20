#pragma once
#include "EcsSystem.h"
#include <iostream>

namespace ecs {

class DummyAudioIn : public EcsSystem {
public:
    std::string name() const override { return "DummyAudioIn"; }
    void update() override {}
    void onPacket(graph::Packet& pkt) override {
        auto& a = pkt.data.audio;
        std::cout << "DummyAudioIn packet seq " << a.seq
                  << " samples: " << a.samples[0] << ", " << a.samples[1]
                  << ", " << a.samples[2] << ", " << a.samples[3] << std::endl;
        pkt.address = 0; // delivered
    }
};

} // namespace ecs
