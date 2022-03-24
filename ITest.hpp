
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//    Copyright 经十                                                          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <memory>

class ITest {
 public:
    using ptr = std::shared_ptr<ITest>;
    using ref = std::weak_ptr<ITest>;

 public:
    ITest() = default;
    virtual ~ITest() = default;

    virtual void test() = 0;
};
