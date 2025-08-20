#include "../core/Program.h"
#include "../ecs/GraphSystem.h"
#include "../ecs/DummyAudioOut.h"
#include "../ecs/DummyAudioIn.h"
#include <chrono>
#include <thread>

using namespace core;
using namespace ecs;

class DummyAudioTester : public Program {
public:
    DummyAudioTester() : out(graph) {
        graph.addSystem(&out);
        graph.addSystem(&in);
    }

    bool init() override {
        out.setTarget(in.address());
        addSystem(&out);
        addSystem(&in);
        addSystem(&graph);
        return true;
    }

    int run() {
        if (!init()) return -1;
        auto start = std::chrono::steady_clock::now();
        while (std::chrono::steady_clock::now() - start < std::chrono::seconds(5)) {
            update();
            for (auto* sys : m_systems) sys->update();
            std::this_thread::sleep_for(
                std::chrono::milliseconds(23));
        }
        shutdown();
        return 0;
    }

private:
    GraphSystem graph;
    DummyAudioOut out;
    DummyAudioIn in;
};

int main() {
    DummyAudioTester app;
    return app.run();
}
