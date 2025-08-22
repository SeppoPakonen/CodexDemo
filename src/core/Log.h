#pragma once
#include <fstream>
#include <string>

namespace core {

class Log {
public:
    static void write(const std::string& line);
};

} // namespace core

