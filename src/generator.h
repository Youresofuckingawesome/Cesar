#pragma once

#include <random>

class Generator
{
public:
	Generator() = default;

	int RandomInteger(int minValue, int maxValue);
	long int RandomLong(long int minValue, long int maxValue);
};