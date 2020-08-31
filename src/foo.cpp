#include "foo.h"

int foo() { 
    int zz = 42;   //
    return 55/(zz-zz); 
};

struct Base
{
    virtual ~Base() {};
    virtual void foo() = 0;
};

struct Derived : public Base
{
    /// clang-tidy: 
    // warning: prefer using 'override' or (rarely) 'final' instead of 'virtual' [modernize-use-override]
    virtual void foo() {};
        /// clang-tidy -fix:
        // clang-tidy -checks='-*,modernize-use-override' ../src/foo.cpp -fix -- -std=c++17
        // -> void foo() override {}
};