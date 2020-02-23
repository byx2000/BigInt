#pragma once

#include <iostream>
#include <fstream>

// 验证表达式为真
// 若表达式expr不为真，则打印文件名和行号，并退出程序
#define ASSERT(expr) \
do \
{ \
	if (!(expr)) \
	{ \
		cout << "Test failed at file "  << __FILE__ << ", line " << __LINE__ << ".\a" << endl; \
		exit(0); \
	} \
} while (0) \

// 验证表达式抛出异常
// 若表达式未抛出异常，则打印文件名和行号，并退出程序
#define ASSERT_EXCEPTION(expr) \
do \
{ \
    bool flag = false; \
    try \
    { \
        expr; \
    } \
    catch (...)\
    { \
        flag = true; \
    }\
    if (!flag) \
	{ \
		cout << "Test failed at file "  << __FILE__ << ", line " << __LINE__ << ".\a" << endl; \
		exit(0); \
	} \
} while (0) \

// 高精度计时器
class StopWatch
{
public:
	StopWatch();
	~StopWatch();
	void begin();
	void end();
	double duration();
private:
	enum { STOP, RUN } status;
	void* freq;
	void* beginTime;
	void* endTime;
};

// 打开文件
// 若打开失败，则退出程序
std::ifstream OpenFile(const std::string& filename);

// 将文本文件转换为字符串
// 若打开文件失败，则退出程序
std::string FileToString(const std::string& filename);

// 开启内存泄漏检测
void CheckMemoryLeak();