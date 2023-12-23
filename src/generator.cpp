#include <generator.h>

int Generator::RandomInteger(int minValue, int maxValue)
{
	std::random_device m_seed;
	std::mt19937 m_random(m_seed());
    std::uniform_int_distribution<> uid(minValue, maxValue);
	
    return uid(m_random);
}

long int Generator::RandomLong(long int minValue, long int maxValue)
{
	std::random_device m_seed;
	std::mt19937 m_random(m_seed());
    std::uniform_int_distribution<> uid(minValue, maxValue);
	
    return uid(m_random);
}
