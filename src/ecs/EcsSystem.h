#pragma once
#include <string>
#include <functional>
#include <typeinfo>
#include "../graph/Packet.h"
#include "../core/Hash.h"

namespace ecs {

class EcsSystem {
public:
    virtual ~EcsSystem() = default;
    virtual std::string name() const = 0;
    virtual hash_t address() const {
        return std::hash<std::string>{}(
            std::string(typeid(*this).name()) + name());
    }
    virtual void update() = 0;
    virtual void onPacket(graph::Packet& pkt) = 0;
};

} // namespace ecs
