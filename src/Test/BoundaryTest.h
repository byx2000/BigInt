#include <cassert>
#include "../BigInt/BigInt.h"

//边界测试
void BoundaryTest()
{
    assert(BigInt(0) + BigInt(0) == BigInt(0));
    assert(BigInt(0) + BigInt(1) == BigInt(1));
    assert(BigInt(1) + BigInt(0) == BigInt(1));
    assert(BigInt(1) + BigInt(1) == BigInt(2));
    assert(BigInt(-1) + BigInt(-1) == BigInt(-2));
	assert(BigInt(1) + BigInt(-1) == BigInt(0));
	assert(BigInt(-1) + BigInt(1) == BigInt(0));
	assert(BigInt(2) + BigInt(3) == BigInt(5));
	assert(BigInt(2) + BigInt(-3) == BigInt(-1));
	assert(BigInt(999) + BigInt(1) == BigInt(1000));
	assert(BigInt(1) + BigInt(999) == BigInt(1000));
	assert(BigInt(1000) + BigInt(-1) == BigInt(999));
	assert(BigInt(-1000) + BigInt(1) == BigInt(-999));

	assert(BigInt(0) - BigInt(0) == BigInt(0));
	assert(BigInt(0) - BigInt(1) == BigInt(-1));
	assert(BigInt(1) - BigInt(0) == BigInt(1));
	assert(BigInt(1) - BigInt(1) == BigInt(0));
	assert(BigInt(-1) - BigInt(-1) == BigInt(0));
	assert(BigInt(1) - BigInt(-1) == BigInt(2));
	assert(BigInt(2) - BigInt(3) == BigInt(-1));
	assert(BigInt(2) - BigInt(-3) == BigInt(5));
	assert(BigInt(3) - BigInt(-2) == BigInt(5));
	assert(BigInt(1000) - BigInt(1) == BigInt(999));
	assert(BigInt(999) - BigInt(-1) == BigInt(1000));

	assert(BigInt(0) * BigInt(0) == BigInt(0));
	assert(BigInt(0) * BigInt(1) == BigInt(0));
	assert(BigInt(1) * BigInt(0) == BigInt(0));
	assert(BigInt(0) * BigInt(-1) == BigInt(0));
	assert(BigInt(-1) * BigInt(0) == BigInt(0));
	assert(BigInt(1) * BigInt(1) == BigInt(1));
	assert(BigInt(1) * BigInt(-1) == BigInt(-1));
	assert(BigInt(-1) * BigInt(1) == BigInt(-1));
	assert(BigInt(-1) * BigInt(-1) == BigInt(1));
	assert(BigInt(2) * BigInt(10) == BigInt(20));
	assert(BigInt(-2) * BigInt(10) == BigInt(-20));
	assert(BigInt(2) * BigInt(-10) == BigInt(-20));
	assert(BigInt(-2) * BigInt(-10) == BigInt(20));
	assert(BigInt(999) * BigInt(1) == BigInt(999));
	assert(BigInt(1) * BigInt(999) == BigInt(999));
	assert(BigInt(999) * BigInt(9) == BigInt(8991));
	assert(BigInt(9) * BigInt(999) == BigInt(8991));

	assert(BigInt(0) / BigInt(1) == BigInt(0));
	assert(BigInt(1) / BigInt(1) == BigInt(1));
	assert(BigInt(2) / BigInt(1) == BigInt(2));
	assert(BigInt(-2) / BigInt(1) == BigInt (-2));
	assert(BigInt(2) / BigInt(-1) == BigInt (-2));
	assert(BigInt(-2) / BigInt(-1) == BigInt(2));
	assert(BigInt(1) / BigInt(2) == BigInt(0));
	assert(BigInt(3) / BigInt(1) == BigInt(3));
	assert(BigInt(3) / BigInt(2) == BigInt(1));
	assert(BigInt(10086) / BigInt(10085) == BigInt(1));
	assert(BigInt(10086) / BigInt(10086) == BigInt(1));
	assert(BigInt(10086) / BigInt(10087) == BigInt(0));

	assert(BigInt(0) % BigInt(1) == BigInt(0));
	assert(BigInt(0) % BigInt(2) == BigInt(0));
	assert(BigInt(1) % BigInt(1) == BigInt(0));
	assert(BigInt(6) % BigInt(3) == BigInt(0));
	assert(BigInt(3) % BigInt(8) == BigInt(3));
	assert(BigInt(6) % BigInt(1) == BigInt(0));
	assert(BigInt(5) % BigInt(2) == BigInt(1));
	assert(BigInt(6) % BigInt(4) == BigInt(2));
	assert(BigInt(10086) % BigInt(10085) == BigInt(1));
	assert(BigInt(10086) % BigInt(10086) == BigInt(0));
	assert(BigInt(10086) % BigInt(10087) == BigInt(10086));

	assert((BigInt(1) ^ BigInt(0)) == BigInt(1));
	assert((BigInt(-1) ^ BigInt(0)) == BigInt(1));
	assert((BigInt(1) ^ BigInt(1)) == BigInt(1));
	assert((BigInt(-1) ^ BigInt(1)) == BigInt(-1));
	assert((BigInt(-1) ^ BigInt(2)) == BigInt(1));
	assert((BigInt(-1) ^ BigInt(3)) == BigInt(-1));
	assert((BigInt(-1) ^ BigInt(4)) == BigInt(1));
	assert((BigInt(2) ^ BigInt(3)) == BigInt(8));
	assert((BigInt(-2) ^ BigInt(3)) == BigInt(-8));

	assert(BigInt::Gcd(BigInt(0), BigInt(1)) == BigInt(1));
	assert(BigInt::Gcd(BigInt(0), BigInt(2)) == BigInt(2));
	assert(BigInt::Gcd(BigInt(1), BigInt(0)) == BigInt(1));
	assert(BigInt::Gcd(BigInt(2), BigInt(0)) == BigInt(2));
	assert(BigInt::Gcd(BigInt(1), BigInt(1)) == BigInt(1));
	assert(BigInt::Gcd(BigInt(1), BigInt(2)) == BigInt(1));
	assert(BigInt::Gcd(BigInt(2), BigInt(1)) == BigInt(1));
	assert(BigInt::Gcd(BigInt(2), BigInt(2)) == BigInt(2));
	assert(BigInt::Gcd(BigInt(12), BigInt(15)) == BigInt(3));
	assert(BigInt::Gcd(BigInt(6), BigInt(12)) == BigInt(6));
	assert(BigInt::Gcd(BigInt(12), BigInt(12)) == BigInt(12));

	assert(BigInt::Lcm(BigInt(1), BigInt(1)) == BigInt(1));
	assert(BigInt::Lcm(BigInt(1), BigInt(2)) == BigInt(2));
	assert(BigInt::Lcm(BigInt(2), BigInt(1)) == BigInt(2));
	assert(BigInt::Lcm(BigInt(2), BigInt(2)) == BigInt(2));
	assert(BigInt::Lcm(BigInt(12), BigInt(15)) == BigInt(60));
}
