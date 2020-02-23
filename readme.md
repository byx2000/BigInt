# BigInt文档

## 简介

`BigInt` 是一个简单的高精度整数库，实现了任意精度整数的处理，支持加、减、乘、除、取余、求幂和各种比较运算。

`BigInt` 基于 `C++11` 和 `STL` 。

## 使用说明

要使用 `BigInt` ，请将文件 `BigInt.h` 和 `BigInt.c` 添加到项目中，并包含 `BigInt.h` 头文件。

编译时，请使用支持 `C++11` 的编译器。

### 初始化

`BigInt` 类提供如下构造函数：

```c++
BigInt::BigInt(long long i = 0); // 用一个整数初始化，默认值为0
BigInt::BigInt(const std::string &s); // 用数字字符串初始化
```

示例：

```c++
BigInt n1(100); // n1 == 100
BigInt n2("1234567890"); // n2 == 1234567890
```

### 运算

`BigInt` 支持加、减、乘、除、取余、求幂和各种比较运算，并重载了相应运算符。

注：求幂运算符为 `^` 。

示例：

```c++
BigInt a("23877328879187687293");
BigInt b(25);

BigInt n1 = a + b;
BigInt n2 = a - b;
BigInt n3 = a * b;
BigInt n4 = a / b;
BigInt n5 = a % b;
BigInt n6 = a ^ b;

bool b1 = a > b;
bool b2 = a >= b;
bool b3 = a < b;
bool b4 = a <= b;
bool b5 = a == b;
bool b6 = a != b;
```

除此之外，`BigInt` 还重载了 `+=` 、`-=` 、`*=` 、`/=` 、`%=` 、`^=` 运算符。

## 应用示例

### 求大数阶乘

```c++
BigInt res = BigInt(1);
for (int i = 2; i <= 1000; ++i)
{
    res *= BigInt(i);
}
cout << "1000! = " << res << endl << endl;
```

### 求斐波拉契数列第5000项

```c++
BigInt a(1), b(1);
BigInt t;
for (int i = 3; i <= 5000; ++i)
{
    t = a;
    a = b;
    b = t + b;
}
cout << "fib(5000) = " << b << endl;
```

