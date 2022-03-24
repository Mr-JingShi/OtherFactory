///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//    Copyright 经十                                                          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
#include "OtherFactory.hpp"

int main(int argc, char** argv) {
   ITest::ptr testA = OtherFactory::getInstance().generate("TestA");
   if (testA) {
      testA->test();  // TestA::test
   }

   ITest::ptr testB = OtherFactory::getInstance().generate("TestB");
   if (testB) {
      testB->test();  // TestB::test
   }

   ITest::ptr testX = OtherFactory::getInstance().generate("Testx");
   if (testX) {
      testX->test();  // nothing
   }
   return 0;
}
