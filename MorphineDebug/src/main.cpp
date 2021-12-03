#include "Morphine/Morphine.h"
#include <iostream>

int main() {

    std::cout << "Hello from MorphineDebug!" << std::endl;

    Morphine::MorphineCore::Init();

    // Setup PS Move API
    Morphine::PairPSMove();
    
    return 0;
}