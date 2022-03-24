///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//    Copyright 经十                                                          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
#include "TestB.hpp"
#include <iostream>
#include "OtherFactory.hpp"

#define OTHERFACTORY_INDEX "TestB"

namespace {
struct TestBRegister {
    TestBRegister() {
        static bool already_here = false;
        if (already_here) {
            return;
        }
        already_here = true;

        OtherFactory::getInstance().registerTest(OTHERFACTORY_INDEX, std::make_shared<TestB>());
    }

    ~TestBRegister() {
        OtherFactory::getInstance().deregisterTest(OTHERFACTORY_INDEX);
    }
}gTestBRegister;
}

void TestB::test() {
    std::cout << "TestB::test" << std::endl;
}
