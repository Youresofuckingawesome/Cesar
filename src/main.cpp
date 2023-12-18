#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>

using namespace std::chrono;

int randint(int minValue, int maxValue, int stepSize = 1) {
    if (stepSize < 0) {
        throw std::invalid_argument("stepSize must be > 0");
    }
    else {
        int min = ceil(minValue / stepSize);
        int max = floor(maxValue / stepSize);
        int randValue = ((double)rand() / (RAND_MAX + 1) * (max - min) + min);
        return (int)randValue * stepSize;
    }
}

long int randLongInt(int minValue, int maxValue, int stepSize = 1) {
    if (stepSize < 0) {
        throw std::invalid_argument("stepSize mast be > 0");
    }
    else {
        int min = ceil(minValue / stepSize);
        int max = floor(maxValue / stepSize);
        long int randValue = ((double)rand() / (RAND_MAX + 1) * (max - min) + min);
        return (long int)randValue * stepSize;
    }
}

float randFloat(float minValue, float maxValue, float stepSize) {
    if (stepSize < 0 || maxValue < stepSize) {
        throw std::invalid_argument("stepSize must be > 0");
    } 
    else if (stepSize <= 1) {
        int transferCoeficent = (int)(1 / stepSize);
        int min = minValue * transferCoeficent;
        int max = maxValue * transferCoeficent;
        float randValue = ((double)rand() / (RAND_MAX + 1) * (max - min) + min);
        return (float) randValue * stepSize;
    }
    else {
        float randValue = ((double)rand() / (RAND_MAX + 1) * (maxValue - minValue) + minValue);
        return (float)randValue / stepSize;
    }

}

double randDouble(double minValue, double maxValue, double stepSize) {
    if (stepSize < 0 || maxValue < stepSize) {
        throw std::invalid_argument("stepSize must be > 0");
    }
    else if (stepSize <= 1) {
        long long int transferCoeficent = (1 / stepSize);
        long int min = minValue * transferCoeficent;
        int max = maxValue * transferCoeficent;
        double randValue = ((double)rand() / (RAND_MAX + 1) * (max - min) + min);
        return (double)randValue * stepSize;
    }
    else {

    }

}

float* generateList(int count) {
    float* testData = new float[count];
    
    return testData;
}

int main(void)
{
    srand((unsigned)time(0));

    int length = 300 * 1000 * 1000;
    // измерение времени генерации масива
    auto startGenerateList = high_resolution_clock::now();
    //-----------
    double* arrayOfRandomValues = new double[length];
    for (int i = 0; i < length; i++) {
        arrayOfRandomValues[i] = randDouble(1, 10000, 0.1);
    }
    //------------
    auto stopGenerateList = high_resolution_clock::now();

    float timeOfGenerateList = (float)duration_cast<nanoseconds>(stopGenerateList - startGenerateList).count() / 1000;

    //Выведение
    for (int i = 0; i < length / 100000; i++) {
        std::cout << arrayOfRandomValues[i] << " ";
    }
    std::cout << std::endl;

    // измерение времени доступа к массиву масива

    auto startGetting = high_resolution_clock::now();

    //-------------
    int temp = 0;
    for (int i = 1; i < length; i++) {
        temp = arrayOfRandomValues[i];
    }
    //-------------

    auto endGetting = high_resolution_clock::now();
    float timeOfGettingValuesFromList = (float)duration_cast<nanoseconds>(endGetting - startGetting).count() / 1000;

    std::cout << temp << std::endl;

    // тестируемая операция
    auto startTestingOfOperation = high_resolution_clock::now();

    //-----------
    long double result = arrayOfRandomValues[0];
    
    for (int i = 1; i < length; i++) {
        result += arrayOfRandomValues[i];
    }

    //-----------

    auto endTestingOfOperation = high_resolution_clock::now();
    float timeOfTestingOfOperation = (float)duration_cast<nanoseconds>(endTestingOfOperation - startTestingOfOperation).count() / 1000;

    //------------------
    std::ofstream out;
    out.open("result.txt");
    if (out.is_open())
    {
        out << "1 000 000 microseconds = 1 second" << std::endl;
        out << "Time of generate array: " << timeOfGenerateList << " microseconds" << std::endl;
        out << "Time of getting values from list: " << timeOfGettingValuesFromList << " microseconds" << std::endl;
        out << "Time of operation execution: " << timeOfTestingOfOperation << " microseconds" << std::endl;
        out << "Time of one operation execution: " << (double) (timeOfTestingOfOperation - timeOfGettingValuesFromList) / length << " microseconds" << std::endl;
        out << "The result = " << result << std::endl;
    }
    out.close();
    //------------------------
    std::string line;

    std::ifstream in("result.txt");
    if (in.is_open())
    {
        while (getline(in, line))
        {
            std::cout << line << std::endl;
        }
    }
    in.close();
}