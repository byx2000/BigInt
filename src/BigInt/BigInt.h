#pragma once

#include <vector>
#include <string>

class BigInt
{
public:
    /*构造函数*/
	BigInt();
    BigInt(long long i);
	explicit BigInt(const std::string &s);

	void assign(long long i);
	void assign(const std::string &s);

	int getSign() const;
	std::vector<char> getDigits() const;
	int getDigit(int i) const;

	//转换成字符串
    std::string toString() const;

	//绝对值
	BigInt abs() const;

	/*运算符重载*/
	bool operator<(const BigInt &num) const;
	bool operator>(const BigInt &num) const;
	bool operator==(const BigInt &num) const;
	bool operator!=(const BigInt &num) const;
	bool operator>=(const BigInt &num) const;
	bool operator<=(const BigInt &num) const;
	const BigInt operator<<(int n) const;
	const BigInt operator<<=(int n);
    const BigInt operator+(const BigInt &num) const;
    const BigInt operator-(const BigInt &num) const;
	const BigInt operator+=(const BigInt &num);
	const BigInt operator-=(const BigInt &num);
	const BigInt operator*(const BigInt &num) const;
	const BigInt operator*=(const BigInt &num);
	const BigInt operator/(const BigInt &num) const;
    const BigInt operator/=(const BigInt &num);
    const BigInt operator%(const BigInt &num) const;
    const BigInt operator%=(const BigInt &num);
    const BigInt operator^(const BigInt &num) const;
    const BigInt operator^=(const BigInt &num);

    static BigInt Max(const BigInt &a, const BigInt &b);
    static BigInt Min(const BigInt &a, const BigInt &b);
    static BigInt Gcd(const BigInt &a, const BigInt &b);
    static BigInt Lcm(const BigInt &a, const BigInt &b);

private:
	int sign;
	std::vector<char> d;

	/*内部函数*/
    //去除前置的0
	void reduceZero();
	//无符号加法
	static BigInt uAdd(const BigInt &num1, const BigInt &num2);
	//无符号减法
	static BigInt uSub(const BigInt &num1, const BigInt &num2);
	//无符号个位乘法
	static BigInt dMul(const BigInt &num, int dight);
	//无符号试商
	static BigInt tryDivision(const BigInt &dividend, const BigInt &divisor, BigInt &remain);
	//无符号求幂
	static BigInt power(const BigInt &a, const BigInt &b);
};

//重载<<运算符
std::ostream& operator<<(std::ostream& out, const BigInt &num);
