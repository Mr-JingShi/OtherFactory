
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//    Copyright 经十                                                          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <map>
#include "ITest.hpp"

class OtherFactory {
 public:
    OtherFactory() = default;
    ~OtherFactory() = default;

    /** registerTest
     *
     * \param index the index of map
     * \param fun the fun of create ITest
     */
    void registerTest(const std::string& index, ITest::ptr ptr);

    /** deregisterTest
     *
     * \param index the index of map
     */
    void deregisterTest(const std::string& index);

    /** generate
     *
     * \param index the index of map
     */
    ITest::ptr generate(const std::string& index);

    static OtherFactory& getInstance() {
        static OtherFactory factory;
        return factory;
    }

 private:
    std::map<std::string, ITest::ptr> mTestMap;
};