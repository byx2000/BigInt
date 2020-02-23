#include "Test.h"
#include "TestUtil.h"
#include "../BigInt/BigInt.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void BigIntTest::Run()
{
	BoundaryTest();
	AddTest();
	SubTest();
	MulTest();
	DivTest();
	RemTest();
	PowTest();
}

void BigIntTest::BoundaryTest()
{
	cout << "Boundary test begin..." << endl;

	StopWatch watch;
	watch.begin();

	ASSERT(BigInt(0) + BigInt(0) == BigInt(0));
	ASSERT(BigInt(0) + BigInt(1) == BigInt(1));
	ASSERT(BigInt(1) + BigInt(0) == BigInt(1));
	ASSERT(BigInt(1) + BigInt(1) == BigInt(2));
	ASSERT(BigInt(-1) + BigInt(-1) == BigInt(-2));
	ASSERT(BigInt(1) + BigInt(-1) == BigInt(0));
	ASSERT(BigInt(-1) + BigInt(1) == BigInt(0));
	ASSERT(BigInt(2) + BigInt(3) == BigInt(5));
	ASSERT(BigInt(2) + BigInt(-3) == BigInt(-1));
	ASSERT(BigInt(999) + BigInt(1) == BigInt(1000));
	ASSERT(BigInt(1) + BigInt(999) == BigInt(1000));
	ASSERT(BigInt(1000) + BigInt(-1) == BigInt(999));
	ASSERT(BigInt(-1000) + BigInt(1) == BigInt(-999));

	ASSERT(BigInt(0) - BigInt(0) == BigInt(0));
	ASSERT(BigInt(0) - BigInt(1) == BigInt(-1));
	ASSERT(BigInt(1) - BigInt(0) == BigInt(1));
	ASSERT(BigInt(1) - BigInt(1) == BigInt(0));
	ASSERT(BigInt(-1) - BigInt(-1) == BigInt(0));
	ASSERT(BigInt(1) - BigInt(-1) == BigInt(2));
	ASSERT(BigInt(2) - BigInt(3) == BigInt(-1));
	ASSERT(BigInt(2) - BigInt(-3) == BigInt(5));
	ASSERT(BigInt(3) - BigInt(-2) == BigInt(5));
	ASSERT(BigInt(1000) - BigInt(1) == BigInt(999));
	ASSERT(BigInt(999) - BigInt(-1) == BigInt(1000));

	ASSERT(BigInt(0) * BigInt(0) == BigInt(0));
	ASSERT(BigInt(0) * BigInt(1) == BigInt(0));
	ASSERT(BigInt(1) * BigInt(0) == BigInt(0));
	ASSERT(BigInt(0) * BigInt(-1) == BigInt(0));
	ASSERT(BigInt(-1) * BigInt(0) == BigInt(0));
	ASSERT(BigInt(1) * BigInt(1) == BigInt(1));
	ASSERT(BigInt(1) * BigInt(-1) == BigInt(-1));
	ASSERT(BigInt(-1) * BigInt(1) == BigInt(-1));
	ASSERT(BigInt(-1) * BigInt(-1) == BigInt(1));
	ASSERT(BigInt(2) * BigInt(10) == BigInt(20));
	ASSERT(BigInt(-2) * BigInt(10) == BigInt(-20));
	ASSERT(BigInt(2) * BigInt(-10) == BigInt(-20));
	ASSERT(BigInt(-2) * BigInt(-10) == BigInt(20));
	ASSERT(BigInt(999) * BigInt(1) == BigInt(999));
	ASSERT(BigInt(1) * BigInt(999) == BigInt(999));
	ASSERT(BigInt(999) * BigInt(9) == BigInt(8991));
	ASSERT(BigInt(9) * BigInt(999) == BigInt(8991));

	ASSERT(BigInt(0) / BigInt(1) == BigInt(0));
	ASSERT(BigInt(1) / BigInt(1) == BigInt(1));
	ASSERT(BigInt(2) / BigInt(1) == BigInt(2));
	ASSERT(BigInt(-2) / BigInt(1) == BigInt(-2));
	ASSERT(BigInt(2) / BigInt(-1) == BigInt(-2));
	ASSERT(BigInt(-2) / BigInt(-1) == BigInt(2));
	ASSERT(BigInt(1) / BigInt(2) == BigInt(0));
	ASSERT(BigInt(3) / BigInt(1) == BigInt(3));
	ASSERT(BigInt(3) / BigInt(2) == BigInt(1));
	ASSERT(BigInt(10086) / BigInt(10085) == BigInt(1));
	ASSERT(BigInt(10086) / BigInt(10086) == BigInt(1));
	ASSERT(BigInt(10086) / BigInt(10087) == BigInt(0));

	ASSERT(BigInt(0) % BigInt(1) == BigInt(0));
	ASSERT(BigInt(0) % BigInt(2) == BigInt(0));
	ASSERT(BigInt(1) % BigInt(1) == BigInt(0));
	ASSERT(BigInt(6) % BigInt(3) == BigInt(0));
	ASSERT(BigInt(3) % BigInt(8) == BigInt(3));
	ASSERT(BigInt(6) % BigInt(1) == BigInt(0));
	ASSERT(BigInt(5) % BigInt(2) == BigInt(1));
	ASSERT(BigInt(6) % BigInt(4) == BigInt(2));
	ASSERT(BigInt(10086) % BigInt(10085) == BigInt(1));
	ASSERT(BigInt(10086) % BigInt(10086) == BigInt(0));
	ASSERT(BigInt(10086) % BigInt(10087) == BigInt(10086));

	ASSERT((BigInt(1) ^ BigInt(0)) == BigInt(1));
	ASSERT((BigInt(-1) ^ BigInt(0)) == BigInt(1));
	ASSERT((BigInt(1) ^ BigInt(1)) == BigInt(1));
	ASSERT((BigInt(-1) ^ BigInt(1)) == BigInt(-1));
	ASSERT((BigInt(-1) ^ BigInt(2)) == BigInt(1));
	ASSERT((BigInt(-1) ^ BigInt(3)) == BigInt(-1));
	ASSERT((BigInt(-1) ^ BigInt(4)) == BigInt(1));
	ASSERT((BigInt(2) ^ BigInt(3)) == BigInt(8));
	ASSERT((BigInt(-2) ^ BigInt(3)) == BigInt(-8));

	ASSERT(BigInt::Gcd(BigInt(0), BigInt(1)) == BigInt(1));
	ASSERT(BigInt::Gcd(BigInt(0), BigInt(2)) == BigInt(2));
	ASSERT(BigInt::Gcd(BigInt(1), BigInt(0)) == BigInt(1));
	ASSERT(BigInt::Gcd(BigInt(2), BigInt(0)) == BigInt(2));
	ASSERT(BigInt::Gcd(BigInt(1), BigInt(1)) == BigInt(1));
	ASSERT(BigInt::Gcd(BigInt(1), BigInt(2)) == BigInt(1));
	ASSERT(BigInt::Gcd(BigInt(2), BigInt(1)) == BigInt(1));
	ASSERT(BigInt::Gcd(BigInt(2), BigInt(2)) == BigInt(2));
	ASSERT(BigInt::Gcd(BigInt(12), BigInt(15)) == BigInt(3));
	ASSERT(BigInt::Gcd(BigInt(6), BigInt(12)) == BigInt(6));
	ASSERT(BigInt::Gcd(BigInt(12), BigInt(12)) == BigInt(12));

	ASSERT(BigInt::Lcm(BigInt(1), BigInt(1)) == BigInt(1));
	ASSERT(BigInt::Lcm(BigInt(1), BigInt(2)) == BigInt(2));
	ASSERT(BigInt::Lcm(BigInt(2), BigInt(1)) == BigInt(2));
	ASSERT(BigInt::Lcm(BigInt(2), BigInt(2)) == BigInt(2));
	ASSERT(BigInt::Lcm(BigInt(12), BigInt(15)) == BigInt(60));

	watch.end();

	cout << "Boundary test finished" << endl;
	cout << "duration: " << watch.duration() << "s" << endl;
	cout << endl;
}

void BigIntTest::AddTest()
{
	cout << "Add test begin..." << endl;

	string filename = "src/Test/TestCase/add.txt";
	ifstream fin = OpenFile(filename);

	StopWatch watch;
	watch.begin();

	string s1, s2, s3;
	while (fin >> s1 >> s2 >> s3)
	{
		BigInt a(s1), b(s2), c(s3);
		if (a + b != c)
		{
			cout << "Add test failed!\a" << endl;
			cout << "Raw data:" << endl;
			cout << s1 << " " << s2 << " " << s3 << endl;
			exit(0);
		}
	}

	watch.end();
	cout << "Add test finished" << endl;
	cout << "duration: " << watch.duration() << "s" << endl;
	cout << endl;
}

void BigIntTest::SubTest()
{
	cout << "Sub test begin..." << endl;

	string filename = "src/Test/TestCase/sub.txt";
	ifstream fin = OpenFile(filename);

	StopWatch watch;
	watch.begin();

	string s1, s2, s3;
	while (fin >> s1 >> s2 >> s3)
	{
		BigInt a(s1), b(s2), c(s3);
		if (a - b != c)
		{
			cout << "Sub test failed!\a" << endl;
			cout << "Raw data:" << endl;
			cout << s1 << " " << s2 << " " << s3 << endl;
			exit(0);
		}
	}

	watch.end();
	cout << "Sub test finished" << endl;
	cout << "duration: " << watch.duration() << "s" << endl;
	cout << endl;
}

void BigIntTest::MulTest()
{
	cout << "Mul test begin..." << endl;

	string filename = "src/Test/TestCase/mul.txt";
	ifstream fin = OpenFile(filename);

	StopWatch watch;
	watch.begin();

	string s1, s2, s3;
	while (fin >> s1 >> s2 >> s3)
	{
		BigInt a(s1), b(s2), c(s3);
		if (a * b != c)
		{
			cout << "Mul test failed!\a" << endl;
			cout << "Raw data:" << endl;
			cout << s1 << " " << s2 << " " << s3 << endl;
			exit(0);
		}
	}

	watch.end();
	cout << "Mul test finished" << endl;
	cout << "duration: " << watch.duration() << "s" << endl;
	cout << endl;
}

void BigIntTest::DivTest()
{
	cout << "Div test begin..." << endl;

	string filename = "src/Test/TestCase/div.txt";
	ifstream fin = OpenFile(filename);

	StopWatch watch;
	watch.begin();

	string s1, s2, s3;
	while (fin >> s1 >> s2 >> s3)
	{
		BigInt a(s1), b(s2), c(s3);
		if (a / b != c)
		{
			cout << "Div test failed!\a" << endl;
			cout << "Raw data:" << endl;
			cout << s1 << " " << s2 << " " << s3 << endl;
			exit(0);
		}
	}

	watch.end();
	cout << "Div test finished" << endl;
	cout << "duration: " << watch.duration() << "s" << endl;
	cout << endl;
}

void BigIntTest::RemTest()
{
	cout << "Rem test begin..." << endl;

	string filename = "src/Test/TestCase/rem.txt";
	ifstream fin = OpenFile(filename);

	StopWatch watch;
	watch.begin();

	string s1, s2, s3;
	while (fin >> s1 >> s2 >> s3)
	{
		BigInt a(s1), b(s2), c(s3);
		if (a % b != c)
		{
			cout << "Rem test failed!\a" << endl;
			cout << "Raw data:" << endl;
			cout << s1 << " " << s2 << " " << s3 << endl;
			exit(0);
		}
	}

	watch.end();
	cout << "Rem test finished" << endl;
	cout << "duration: " << watch.duration() << "s" << endl;
	cout << endl;
}

void BigIntTest::PowTest()
{
	cout << "Pow test begin..." << endl;

	string filename = "src/Test/TestCase/pow.txt";
	ifstream fin = OpenFile(filename);

	StopWatch watch;
	watch.begin();

	string s1, s2, s3;
	while (fin >> s1 >> s2 >> s3)
	{
		BigInt a(s1), b(s2), c(s3);
		if ((a ^ b) != c)
		{
			cout << "Pow test failed!\a" << endl;
			cout << "Raw data:" << endl;
			cout << s1 << " " << s2 << " " << s3 << endl;
			exit(0);
		}
	}

	watch.end();
	cout << "Pow test finished" << endl;
	cout << "duration: " << watch.duration() << "s" << endl;
	cout << endl;
}
