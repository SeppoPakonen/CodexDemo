#pragma once
#include <string>
#include <functional>
#include <typeinfo>
#include "../graph/Packet.h"
#include "../core/Hash.h"

namespace ecs {

class EcsSystem {
public:
    explicit EcsSystem(const std::string& name) : m_name(name) {}
    virtual ~EcsSystem() = default;

    const std::string& name() const { return m_name; }
    virtual const char* get_type_name() const { return typeid(*this).name(); }
    virtual hash_t address() const {
        return std::hash<std::string>{}(std::string(get_type_name()) + name());
    }
    virtual void update() = 0;
    virtual void onPacket(graph::Packet& pkt) = 0;

protected:
    std::string m_name;
};

} // namespace ecs
