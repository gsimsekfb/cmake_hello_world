#include<iostream>

class Obj
{
    int i;
public:
    Obj(int j) : i(j) {}
    ~Obj(){}   
};

struct Foo {
    Foo() {};  
    ~Foo() {}; 
    int _count; /// warning C26495: Variable 'Foo::_count' is uninitialized.     
};

int main(int argc, char *argv[])
{
    /// warning C26444: Avoid unnamed objects with custom construction and destruction
	// Sol.1: #pragma
    #if _MSC_VER
	#pragma warning( push )
	// #pragma warning( disable : 26444)
	Obj(2);	// <-- !! 	// Sol.2: (void) obj(2)
	#pragma warning( pop )
    #endif
    
    std::cout << "Hello World!" << std::endl;

	return 0;
}