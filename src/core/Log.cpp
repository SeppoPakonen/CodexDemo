#include "Log.h"

namespace core {

void Log::write(const std::string& line) {
    static std::ofstream file("packets.log", std::ios::app);
    file << line << std::endl;
}

} // namespace core

