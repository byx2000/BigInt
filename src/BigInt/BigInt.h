#pragma once

#include <vector>
#include <string>

class BigInt
{
public:
    /*���캯��*/
	BigInt();
    BigInt(long long i);
	explicit BigInt(const std::string &s);

	void assign(long long i);
	void assign(const std::string &s);

	int getSign() const;
	std::vector<char> getDigits() const;
	int getDigit(int i) const;

	//ת�����ַ���
    std::string toString() const;

	//����ֵ
	BigInt abs() const;

	/*���������*/
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

	/*�ڲ�����*/
    //ȥ��ǰ�õ�0
	void reduceZero();
	//�޷��żӷ�
	static BigInt uAdd(const BigInt &num1, const BigInt &num2);
	//�޷��ż���
	static BigInt uSub(const BigInt &num1, const BigInt &num2);
	//�޷��Ÿ�λ�˷�
	static BigInt dMul(const BigInt &num, int dight);
	//�޷�������
	static BigInt tryDivision(const BigInt &dividend, const BigInt &divisor, BigInt &remain);
	//�޷�������
	static BigInt power(const BigInt &a, const BigInt &b);
};

//����<<�����
std::ostream& operator<<(std::ostream& out, const BigInt &num);
