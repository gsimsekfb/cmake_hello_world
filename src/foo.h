
int foo();

static int f2() {
    int zz = 42;
    /// clang-tidy: warning: Division by zero [clang-analyzer-core.DivideZero]    
    // Found with clang-tidy ../src/foo.h    
    return 55/(zz-zz); 
        // Todo: Not found with run-clang-tidy.py
        // Todo: Not found with scan-build
};

