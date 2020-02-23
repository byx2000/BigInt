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
    /*�߽���������*/
    //BoundaryTest();

    /*��Ԫ����*/

    //ȥ������ע�Ϳ����е�Ԫ����
    //��Ԫ���Կ�����Ҫ�ϳ�ʱ�䣬�����ĵȴ�
	/*cout << "Begin unit tests" << endl << endl;
	TestAdd();
	TestSub();
	TestMul();
	TestDiv();
	TestRem();
	TestPow();
	TestGcd();
	TestLcm();*/

	/*�÷�ʾ��*/

    //���캯���븳ֵ
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

    //+ - * / % ^ ���������
    cout << BigInt(1) + BigInt(1) << endl;
    cout << BigInt(1) - BigInt(1) << endl;
    cout << BigInt(1) * BigInt(1) << endl;
    cout << BigInt(1) / BigInt(1) << endl;
    cout << BigInt(12) % BigInt(35) << endl;
    cout << (BigInt(12) ^ BigInt(35)) << endl;

    //+= -= *= /= %= ^= ���������
    cout << (BigInt(1) += BigInt(1)) << endl;
    cout << (BigInt(1) -= BigInt(1)) << endl;
    cout << (BigInt(1) *= BigInt(1)) << endl;
    cout << (BigInt(1) /= BigInt(1)) << endl;
    cout << (BigInt(12) %= BigInt(35)) << endl;
    cout << (BigInt(12) ^= BigInt(35)) << endl;

    //== != > < >= <= ���������
    cout << (BigInt(123) > BigInt(456)) << endl;
    cout << (BigInt(123) < BigInt(456)) << endl;
    cout << (BigInt(123) == BigInt(456)) << endl;
    cout << (BigInt(123) == BigInt(123)) << endl;
    cout << (BigInt(123) != BigInt(456)) << endl;
    cout << (BigInt(123) != BigInt(123)) << endl;
    cout << (BigInt(123) >= BigInt(456)) << endl;
    cout << (BigInt(123) <= BigInt(456)) << endl;*/

    /*Ӧ��ʾ��*/

    //�������
    /*cout << BigInt::Gcd(BigInt(120), BigInt(150)) << endl;
    cout << BigInt::Gcd(BigInt("28757278364874"), BigInt("917310310739812")) << endl;*/

    //������׳�
    BigInt res = BigInt(1);
    for (int i = 2; i <= 1000; ++i)
    {
        res *= BigInt(i);
    }
    cout << "1000! = " << res << endl << endl;

    //����
    cout << "2^5000 = " << (BigInt(2) ^ BigInt(5000)) << endl << endl;

    //��쳲���������
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
