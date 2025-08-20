#pragma once
#include <string>
#include "../graph/Packet.h"

namespace ecs {

class EcsSystem {
public:
    virtual ~EcsSystem() = default;
    virtual std::string name() const = 0;
    virtual void update() = 0;
    virtual void onPacket(graph::Packet& pkt) = 0;
};

} // namespace ecs
