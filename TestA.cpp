///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//    Copyright 经十                                                          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
#include "TestA.hpp"
#include <iostream>
#include "OtherFactory.hpp"

#define OTHERFACTORY_INDEX "TestA"

namespace {
struct TestARegister {
    TestARegister() {
        static bool already_here = false;
        if (already_here) {
            return;
        }
        already_here = true;

        OtherFactory::getInstance().registerTest(OTHERFACTORY_INDEX, std::make_shared<TestA>());
    }

    ~TestARegister() {
        OtherFactory::getInstance().deregisterTest(OTHERFACTORY_INDEX);
    }
}gTestARegister;
}

void TestA::test() {
    std::cout << "TestA::test" << std::endl;
}
