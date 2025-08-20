#include "../core/Program.h"
#include "../ecs/GraphSystem.h"
#include "../ecs/SDL3_Context_System.h"
#include "../ecs/SDL3_Screen_System.h"
#include "../ecs/SDL3_Audio_System.h"
#include "../ecs/SDL3_Input_System.h"
#include "../ecs/AssimpSystem.h"

using namespace core;
using namespace ecs;

class App : public Program {
public:
    App() {
        m_graph.addSystem(&m_screen);
        m_graph.addSystem(&m_audio);
        m_graph.addSystem(&m_input);
        m_graph.addSystem(&m_assimp);
    }
protected:
    bool init() override {
        addSystem(&m_graph);
        addSystem(&m_ctx);
        addSystem(&m_screen);
        addSystem(&m_audio);
        addSystem(&m_input);
        addSystem(&m_assimp);
        return true;
    }
    void update() override {
        graph::Packet* pkt = graph::PacketRecycler::instance().acquire();
        pkt->format = graph::PacketFormat::Event;
        m_graph.enqueue(pkt);
    }
private:
    GraphSystem m_graph;
    SDL3_Context_System m_ctx;
    SDL3_Screen_System m_screen;
    SDL3_Audio_System m_audio;
    SDL3_Input_System m_input;
    AssimpSystem m_assimp;
};

int main() {
    App app;
    return app.run();
}
