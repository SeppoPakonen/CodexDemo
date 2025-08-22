#include "PacketDebug.h"
#include <sstream>

namespace graph {

std::string toDebugString(const Packet& pkt) {
    std::ostringstream oss;
    oss << "Packet addr " << pkt.address << " format ";
    switch (pkt.format) {
    case PacketFormat::Audio: {
        oss << "Audio";
        const auto& a = pkt.data.audio;
        oss << " sampleRate=" << a.sampleRate
            << " channels=" << a.channels
            << " frames=" << a.frames
            << " seq=" << a.seq
            << " samples=[" << a.samples[0] << ", " << a.samples[1]
            << ", " << a.samples[2] << ", " << a.samples[3] << "]";
        break;
    }
    case PacketFormat::Video:
        oss << "Video";
        break;
    case PacketFormat::Event:
        oss << "Event";
        break;
    case PacketFormat::Model:
        oss << "Model";
        break;
    default:
        oss << "Unknown";
        break;
    }
    return oss.str();
}

} // namespace graph

