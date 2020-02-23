#include <iostream>
#include <fstream>
#include "../BigInt/BigInt.h"

using namespace std;

//加法测试
void TestAdd()
{
    ifstream fin("add.txt");
    string s1, s2, s3;
    BigInt a, b, c;

    cout << "Begin add test..." << endl;

    int cnt = 1;
    while (fin >> s1 >> s2 >> s3)
    {
        a.assign(s1);
        b.assign(s2);
        c.assign(s3);
        if (a + b != c)
        {
            cout << "Add test failed!" << endl;
            fin.close();
            return;
        }
        //cout << "\tCase " << cnt << " passed" << endl;
        cnt++;
    }

    cout << "Add test passed!" << endl << endl;
    fin.close();
    return;
}

//减法测试
void TestSub()
{
    ifstream fin("sub.txt");
    string s1, s2, s3;
    BigInt a, b, c;

    cout << "Begin sub test..." << endl;

    int cnt = 1;
    while (fin >> s1 >> s2 >> s3)
    {
        a.assign(s1);
        b.assign(s2);
        c.assign(s3);
        if (a - b != c)
        {
            cout << "Sub test failed!" << endl;
            fin.close();
            return;
        }
        //cout << "\tCase " << cnt << " passed" << endl;
        cnt++;
    }

    cout << "Sub test passed!" << endl << endl;
    fin.close();
    return;
}

//乘法测试
void TestMul()
{
    ifstream fin("mul.txt");
    string s1, s2, s3;
    BigInt a, b, c;

    cout << "Begin mul test..." << endl;

    int cnt = 1;
    while (fin >> s1 >> s2 >> s3)
    {
        a.assign(s1);
        b.assign(s2);
        c.assign(s3);
        if (a * b != c)
        {
            cout << "Mul test failed!" << endl;
            fin.close();
            return;
        }
        //cout << "\tCase " << cnt << " passed" << endl;
        cnt++;
    }

    cout << "Mul test passed!" << endl << endl;
    fin.close();
    return;
}

//除法测试
void TestDiv()
{
    ifstream fin("div.txt");
    string s1, s2, s3;
    BigInt a, b, c;

    cout << "Begin div test..." << endl;

    int cnt = 1;
    while (fin >> s1 >> s2 >> s3)
    {
        a.assign(s1);
        b.assign(s2);
        c.assign(s3);
        if (a / b != c)
        {
            cout << "Div test failed!" << endl;
            fin.close();
            return;
        }
        //cout << "\tCase " << cnt << " passed" << endl;
        cnt++;
    }

    cout << "Div test passed!" << endl << endl;
    fin.close();
    return;
}

//取余测试
void TestRem()
{
    ifstream fin("rem.txt");
    string s1, s2, s3;
    BigInt a, b, c;

    cout << "Begin rem test..." << endl;

    int cnt = 1;
    while (fin >> s1 >> s2 >> s3)
    {
        a.assign(s1);
        b.assign(s2);
        c.assign(s3);
        if (a % b != c)
        {
            cout << "Rem test failed!" << endl;
            fin.close();
            return;
        }
        //cout << "\tCase " << cnt << " passed" << endl;
        cnt++;
    }

    cout << "Rem test passed!" << endl << endl;
    fin.close();
    return;
}

//求幂测试
void TestPow()
{
    ifstream fin("pow.txt");
    string s1, s2, s3;
    BigInt a, b, c;

    cout << "Begin pow test..." << endl;

    int cnt = 1;
    while (fin >> s1 >> s2 >> s3)
    {
        a.assign(s1);
        b.assign(s2);
        c.assign(s3);
        if ((a ^ b) != c)
        {
            cout << "Pow test failed!" << endl;
            fin.close();
            return;
        }
        //cout << "\tCase " << cnt << " passed" << endl;
        cnt++;
    }

    cout << "Pow test passed!" << endl << endl;
    fin.close();
    return;
}

//最大公因数测试
void TestGcd()
{
    ifstream fin("gcd.txt");
    string s1, s2, s3;
    BigInt a, b, c;

    cout << "Begin gcd test..." << endl;

    int cnt = 1;
    while (fin >> s1 >> s2 >> s3)
    {
        a.assign(s1);
        b.assign(s2);
        c.assign(s3);
        if (BigInt::Gcd(a, b) != c)
        {
            cout << "Gcd test failed!" << endl;
            fin.close();
            return;
        }
        //cout << "\tCase " << cnt << " passed" << endl;
        cnt++;
    }

    cout << "Gcd test passed!" << endl << endl;
    fin.close();
    return;
}

//最小公倍数测试
void TestLcm()
{
    ifstream fin("lcm.txt");
    string s1, s2, s3;
    BigInt a, b, c;

    cout << "Begin lcm test..." << endl;

    int cnt = 1;
    while (fin >> s1 >> s2 >> s3)
    {
        a.assign(s1);
        b.assign(s2);
        c.assign(s3);
        if (BigInt::Lcm(a, b) != c)
        {
            cout << "Lcm test failed!" << endl;
            fin.close();
            return;
        }
        //cout << "\tCase " << cnt << " passed" << endl;
        cnt++;
    }

    cout << "Lcm test passed!" << endl << endl;
    fin.close();
    return;
}
