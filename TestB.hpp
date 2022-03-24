///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//    Copyright 经十                                                          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "ITest.hpp"

class TestB : public ITest {
 public:
    TestB() = default;
    virtual ~TestB() = default;

    void test() override;
};
