#pragma once

#include <iostream>
#include <fstream>

// ��֤���ʽΪ��
// �����ʽexpr��Ϊ�棬���ӡ�ļ������кţ����˳�����
#define ASSERT(expr) \
do \
{ \
	if (!(expr)) \
	{ \
		cout << "Test failed at file "  << __FILE__ << ", line " << __LINE__ << ".\a" << endl; \
		exit(0); \
	} \
} while (0) \

// ��֤���ʽ�׳��쳣
// �����ʽδ�׳��쳣�����ӡ�ļ������кţ����˳�����
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

// �߾��ȼ�ʱ��
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

// ���ļ�
// ����ʧ�ܣ����˳�����
std::ifstream OpenFile(const std::string& filename);

// ���ı��ļ�ת��Ϊ�ַ���
// �����ļ�ʧ�ܣ����˳�����
std::string FileToString(const std::string& filename);

// �����ڴ�й©���
void CheckMemoryLeak();