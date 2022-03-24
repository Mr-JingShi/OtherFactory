
# 另类工厂模式

## 一种简易且好用的工厂模式，特别适合与测试相关的项目架构。
每个业务子类只需在cpp中按如下格式完成向工厂的注册、解注册即可达到与工厂的联动效果。
```C++
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
```

## 解耦
TestA、TestB、TestX等子类与工厂类解耦（隔离），后续新增TestC子类时无需改动工厂类任何内容，
TestA业务废弃时，只需删除TestA相关文件，仍无需改动工厂类任何内容。
开发者可以把更多的精力放到具体的业务实现中。

## 动态加载、卸载（业务类与主框架解耦带来的便利）
可以把一个个的业务子类设计成动态库so，配合dlopen使用便可以做到程序运行期的动态加载、卸载业务的功能。