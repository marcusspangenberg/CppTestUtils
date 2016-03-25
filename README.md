# CppTestUtils
Utility functions for implementing simple C++ unit tests.

## Example

```
#include "TestUtils.h"

void exampleTest()
{
    TEST_ENTER;

    TEST_VERIFY(1 == 1);
    TEST_VERIFY(1 == 0);
}

int main(int argc, char** argv)
{
    try
    {
        exampleTest();
    }
    catch (const TestUtils::TestFailure& exception)
    {
        std::cout << "Test failed: " << exception.getInfo() << std::endl;
        return 1;
    }

    return 0;
}
```

```
$ ./example 
-- exampleTest begin
   exampleTest end
Test failed: "1 == 0" - exampleTest:8
```
