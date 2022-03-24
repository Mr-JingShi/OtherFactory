///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//    Copyright 经十                                                          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "ITest.hpp"

class TestA : public ITest {
 public:
    TestA() = default;
    virtual ~TestA() = default;

    void test() override;
};
