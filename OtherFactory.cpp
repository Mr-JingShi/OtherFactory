
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//    Copyright 经十                                                          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
#include "OtherFactory.hpp"

void OtherFactory::registerTest(const std::string& index, ITest::ptr ptr) {
   mTestMap.insert({index, ptr});
}

void OtherFactory::deregisterTest(const std::string& index) {
   mTestMap.erase(index);
}

ITest::ptr OtherFactory::generate(const std::string& index) {
   ITest::ptr test;

   auto it = mTestMap.find(index);
   if (it != mTestMap.end()) {
      test = it->second; 
   }

   return test;
}
