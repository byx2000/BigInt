#include <iostream>
#include "BigInt/BigInt.h"
#include "Test/TestUtil.h"
#include "Test/Test.h"

using namespace std;

int main()
{
    // ÄÚ´æĞ¹Â©¼ì²â
    CheckMemoryLeak();

    // µ¥Ôª²âÊÔ
    BigIntTest::Run();

    return 0;
}
