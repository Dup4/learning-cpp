#pragma once

#include <iostream>

class A {
public:
    static A& Instance() {
        static A a;
        return a;
    }

    A() {
        std::cout << "A constructor begin" << std::endl;
        num = 10;
        std::cout << "A constructor finished" << std::endl;
    }

public:
    int num;
};
