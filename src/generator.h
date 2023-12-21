#pragma once

#include <random>

class Generator
{
public:
	Generator();

	template<typename __type = int>
	__type HardRandom(__type minValue, __type maxValue);

	int RandomInteger(int minValue, int maxValue);
	long int RandomLong(long int minValue, long int maxValue);
	float RandomFloat(float minValue, float maxValue);
	double RandomDouble(double minValue, double maxValue);

private:
	std::random_device m_seed;
	std::mt19937 m_random;
};