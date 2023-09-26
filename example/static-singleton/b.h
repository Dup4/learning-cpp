#pragma once

#include <iostream>

#include "./a.h"

class B {
public:
    static B& Instance() {
        static B b;
        return b;
    }

    B() {
        std::cout << "B constructor begin" << std::endl;
        num = A::Instance().num;
        std::cout << "B constructor finished" << std::endl;
    }

public:
    int num;
};
