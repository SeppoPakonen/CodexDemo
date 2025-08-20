#pragma once
#include <cstdint>

namespace graph {

enum class PacketFormat {
    Video,
    Audio,
    Event,
    Model,
    Unknown
};

struct VideoData { uint8_t dummy[256]; };
struct AudioData { uint8_t dummy[256]; };
struct EventData { uint8_t dummy[64]; };
struct ModelData { uint8_t dummy[512]; };

struct Packet {
    PacketFormat format{PacketFormat::Unknown};
    union {
        VideoData video;
        AudioData audio;
        EventData event;
        ModelData model;
    } data;
    Packet* next{nullptr};
};

} // namespace graph
