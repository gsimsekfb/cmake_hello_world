#include <iostream>
#include "foo.h"

class Obj
{
    int i;
public:
    Obj(int j) : i(j) {}
    ~Obj(){}   
};

struct Zoo {
    Zoo() {};  
    ~Zoo() {}; 
    int _count; /// VS: warning C26495: Variable 'Zoo::_count' is uninitialized.     
};

int test2(int x){
    /// clang-tidy: warning: non-void function does not return a value 
    // [clang-diagnostic-return-type]
	return 0;
}

int main(int argc, char *argv[])
{
    /// VS: warning C26444: Avoid unnamed objects with custom construction and destruction
	// Sol.1: #pragma
    #if _MSC_VER
	#pragma warning( push )
	// #pragma warning( disable : 26444)
	Obj(2);	// <-- !! 	// Sol.2: (void) obj(2)
	#pragma warning( pop )
    #endif
    
    std::cout << "Hello World - " << std::endl;

    /// 
    // foo();    // divide by zero

	/// clang compiler warning: 
    // warning: implicit conversion changes signedness: 'int' to 'std::size_t' 
    // (aka 'unsigned long long') [-Wsign-conversion]  
	std::size_t bigstuff = -1;	// clang++ -Weverthing or -Wsign-conversion
	int *y = new int; 
	  /// scan-build, clang-tidy: warning: Value stored to 'y' during its initialization 
      // is never read [clang-analyzer-deadcode.DeadStores]
    int x = 42;
  	// return 5/(x-x);  /// scan-build, clang-tidy: warning: Division by zerowarn
    return 0;  
        /// clang-tidy: warning: Potential leak of memory pointed to by 'x' 
        // [clang-analyzer-cplusplus.NewDeleteLeaks]
}