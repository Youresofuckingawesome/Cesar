#include <generator.h>

Generator::Generator()
    : m_random(m_seed())
{ }

template<typename __type = int>
__type Generator::HardRandom(__type minValue, __type maxValue)
{
    std::uniform_int_distribution<__type> uid(minValue, maxValue);
    return uid(m_random);
}

int Generator::RandomInteger(int minValue, int maxValue)
{
    std::uniform_int_distribution<> uid(minValue, maxValue);
    return uid(m_random);
}

long int Generator::RandomLong(long int minValue, long int maxValue)
{
    std::uniform_int_distribution<> uid(minValue, maxValue);
    return uid(m_random);
}

float Generator::RandomFloat(float minValue, float maxValue)
{
    std::uniform_real_distribution<float> uid(minValue, maxValue);
    return uid(m_random);
}

double Generator::RandomDouble(double minValue, double maxValue)
{
    std::uniform_real_distribution<> uid(minValue, maxValue);
    return uid(m_random);
}