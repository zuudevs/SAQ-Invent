#pragma once

#include "core/manager.hpp"

namespace saq {

class Application {
public:
    Application() = default;
    ~Application() = default;
    
    void run();
};

} // namespace saq