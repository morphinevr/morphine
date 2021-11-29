#include "Morphine/Morphine.h"
#include "psmoveapi.h"
#include <iostream>

namespace Morphine {
    void MorphineCore::Init() {
        std::cout << "Hello from MorphineAPI!" << std::endl;

        // Setup PS Move API
        psmoveapi_init(NULL, NULL);

        psmoveapi_quit();
    }
}