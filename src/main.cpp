#include <iostream>
#include "BigInt/BigInt.h"
#include "Test/TestUtil.h"
#include "Test/Test.h"

using namespace std;

int main()
{
    // �ڴ�й©���
    CheckMemoryLeak();

    // ��Ԫ����
    BigIntTest::Run();

    return 0;
}
