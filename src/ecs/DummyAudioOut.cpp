#include "DummyAudioOut.h"
#include "../graph/PacketRecycler.h"
#include <cstring>

namespace ecs {

void DummyAudioOut::update() {
    graph::Packet* pkt = graph::PacketRecycler::instance().acquire();
    pkt->format = graph::PacketFormat::Audio;
    pkt->address = m_target;
    auto& a = pkt->data.audio;
    pkt->ptr = a.samples;
    a.sampleRate = 44100;
    a.channels = 2;
    a.frames = 1024;
    a.seq = m_seq++;
    for (size_t i = 0; i < graph::AUDIO_SAMPLES_PER_PACKET; ++i) {
        a.samples[i] = static_cast<float>(i % 4);
    }
    m_graph.enqueue(pkt);
}

} // namespace ecs
