#pragma once
#include <cstdint>
#include "../core/Hash.h"

namespace graph {

enum class PacketFormat {
    Video,
    Audio,
    Event,
    Model,
    Unknown
};

struct VideoData { uint8_t dummy[256]; };
constexpr std::size_t AUDIO_SAMPLES_PER_PACKET = 1024 * 2; // 1024 frames, 2 channels
struct AudioData {
    uint32_t sampleRate;
    uint32_t channels;
    uint32_t frames;
    uint32_t seq;
    float samples[AUDIO_SAMPLES_PER_PACKET];
};
struct EventData { uint8_t dummy[64]; };
struct ModelData { uint8_t dummy[512]; };

struct Packet {
    PacketFormat format{PacketFormat::Unknown};
    hash_t address{0};
    void* ptr{nullptr};
    union {
        VideoData video;
        AudioData audio;
        EventData event;
        ModelData model;
    } data;
    Packet* next{nullptr};
};

} // namespace graph
