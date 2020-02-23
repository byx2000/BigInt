#include <iostream>
#include "BigInt/BigInt.h"
#include "Test/TestUtil.h"
#include "Test/Test.h"

using namespace std;

int main()
{
    CheckMemoryLeak();
    BigIntTest::Run();

    //
    /*边界条件测试*/
    //BoundaryTest();

    /*单元测试*/

    //去掉以下注释可运行单元测试
    //单元测试可能需要较长时间，请耐心等待
	/*cout << "Begin unit tests" << endl << endl;
	TestAdd();
	TestSub();
	TestMul();
	TestDiv();
	TestRem();
	TestPow();
	TestGcd();
	TestLcm();*/

	/*用法示例*/

    //构造函数与赋值
    /*BigInt n1(1);
    BigInt n2(-1);
    BigInt n3("12345678987654321");
    BigInt n4("-12345678987654321");
    BigInt n5 = BigInt(1);
    BigInt n6 = BigInt(-1);
    BigInt n7 = BigInt("12345678987654321");
    BigInt n8 = BigInt("-12345678987654321");
    cout << n1 << endl;
    cout << n2 << endl;
    cout << n3 << endl;
    cout << n4 << endl;
    cout << n5 << endl;
    cout << n6 << endl;
    cout << n7 << endl;
    cout << n8 << endl;

    //+ - * / % ^ 运算符重载
    cout << BigInt(1) + BigInt(1) << endl;
    cout << BigInt(1) - BigInt(1) << endl;
    cout << BigInt(1) * BigInt(1) << endl;
    cout << BigInt(1) / BigInt(1) << endl;
    cout << BigInt(12) % BigInt(35) << endl;
    cout << (BigInt(12) ^ BigInt(35)) << endl;

    //+= -= *= /= %= ^= 运算符重载
    cout << (BigInt(1) += BigInt(1)) << endl;
    cout << (BigInt(1) -= BigInt(1)) << endl;
    cout << (BigInt(1) *= BigInt(1)) << endl;
    cout << (BigInt(1) /= BigInt(1)) << endl;
    cout << (BigInt(12) %= BigInt(35)) << endl;
    cout << (BigInt(12) ^= BigInt(35)) << endl;

    //== != > < >= <= 运算符重载
    cout << (BigInt(123) > BigInt(456)) << endl;
    cout << (BigInt(123) < BigInt(456)) << endl;
    cout << (BigInt(123) == BigInt(456)) << endl;
    cout << (BigInt(123) == BigInt(123)) << endl;
    cout << (BigInt(123) != BigInt(456)) << endl;
    cout << (BigInt(123) != BigInt(123)) << endl;
    cout << (BigInt(123) >= BigInt(456)) << endl;
    cout << (BigInt(123) <= BigInt(456)) << endl;*/

    /*应用示例*/

    //最大公因数
    /*cout << BigInt::Gcd(BigInt(120), BigInt(150)) << endl;
    cout << BigInt::Gcd(BigInt("28757278364874"), BigInt("917310310739812")) << endl;*/

    //求大数阶乘
    BigInt res = BigInt(1);
    for (int i = 2; i <= 1000; ++i)
    {
        res *= BigInt(i);
    }
    cout << "1000! = " << res << endl << endl;

    //求幂
    cout << "2^5000 = " << (BigInt(2) ^ BigInt(5000)) << endl << endl;

    //求斐波拉契数列
    BigInt a(1), b(1);
	BigInt t;
	for (int i = 3; i <= 5000; ++i)
	{
		t = a;
		a = b;
		b = t + b;
	}
	cout << "fib(5000) = " << b << endl;

    return 0;
}
