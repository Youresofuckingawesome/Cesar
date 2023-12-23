#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <deque>
#include <string>
#include <math.h>
#include <generator.h>
#include "../timetest.h"

template<typename Container>
void findMaxAndMin(Container& container) {
    double max = container[0], min = container[0];
    for (auto& element : container) {
        if (element < min) {
            min = element;
        }
        else if (element > max) {
            max = element;
        }
    }
    std::cout << "max = " << max << std::endl << "min = " << min << std::endl;
}


int main(void)
{
    setlocale(0, "");
    srand((unsigned)time(0));

    // получение объёма заполняемых данных
    int length; //int length = 30 * 1000 * 1000;
    std::cout << "Введите размер контейнера в тысячах: "; std::cin >> length;
    length *= 1000;
    std::string resultTest = "1 000 000 microseconds = 1 second\n";


    // выбор контейнера, типа данных, параметров заполнения данными
    int type = 0;
    int conteinerType = 0;
    double min, max, step;

    std::cout << "Введите тип контейнера\n0 - динамический массив\t1 - vector \t2 - deque" << std::endl;
    std::cout << "Введите id нужного контейнера: "; std::cin >> conteinerType;

    std::cout << "Введите тип данных для заполнения\n0 - int\t1 - long int\t2 - float\t3 - double" << std::endl;
    std::cout << "Введите id нужного типа данных: "; std::cin >> type;

    std::cout << "Введите параметры для заполнения контейнера" << std::endl;
    std::cout << "Введите значение минимального элемента: "; std::cin >> min;
    std::cout << "Введите значение максимального элемента: "; std::cin >> max;
    std::cout << "Введите значение шага чисел: "; std::cin >> step;
    // создание контейнеров
    if (conteinerType == 0) { // этот тип контейнера изначально не пошёл
        if (type == 0) {
            int* array = new int[length];
            //Generator generator(array);
        }
        if (type == 1) {
            long int* array = new long int[length];
        }
        if (type == 2) {
            float* array = new float[length];
        }
        if (type == 3) {
            double* array = new double[length];
        }
    }
    else if (conteinerType == 1) {
        if (type == 0) {
            std::vector<int> array(length);
            Generator<std::vector<int>> generator{ array };
            resultTest += generator.randint(min, max, step);
            findMaxAndMin(array);
            TimeTests<std::vector<int>> timeTests{ array };
            resultTest += timeTests.testAccessToContainer();
        }
        if (type == 1) {
            std::vector<long int> array(length);
            Generator<std::vector<long int>> generator{ array };
            resultTest += generator.randLongInt(min, max, step);
            findMaxAndMin(array);
            TimeTests<std::vector<long int>> timeTests{ array };
            resultTest += timeTests.testAccessToContainer();
        }
        if (type == 2) {
            std::vector<float> array(length);
            Generator<std::vector<float>> generator{ array };
            resultTest += generator.randFloat(min, max, step);
            findMaxAndMin(array);
            TimeTests<std::vector<float>> timeTests{ array };
            resultTest += timeTests.testAccessToContainer();
        }
        if (type == 3) {
            std::vector<double> array(length);
            Generator<std::vector<double>> generator{ array };
            resultTest += generator.randDouble(min, max, step);
            findMaxAndMin(array);
            TimeTests<std::vector<double>> timeTests{ array };
            resultTest += timeTests.testAccessToContainer();
        }
        else if (conteinerType == 2) {
            if (type == 0) {
                std::deque<int> array(length);
                Generator<std::deque<int>> generator{ array };
                resultTest += generator.randint(min, max, step);
                findMaxAndMin(array);
                TimeTests<std::deque<int>> timeTests{ array };
                resultTest += timeTests.testAccessToContainer();
            }
            if (type == 1) { // этот контейнер плохо работает я какие - то изменения провёл и он отвалился 
                std::deque<int> array(length); // long int - не работает
                Generator<std::deque<int>> generator{ array };
                resultTest += generator.randLongInt(min, max, step);
                findMaxAndMin(array);
                TimeTests<std::deque<int>> timeTests{ array };
                resultTest += timeTests.testAccessToContainer();
            }
            if (type == 2) {
                std::deque<float> array(length);
                Generator<std::deque<float>> generator{ array };
                resultTest += generator.randFloat(min, max, step);
                findMaxAndMin(array);
                TimeTests<std::deque<float>> timeTests{ array };
                resultTest += timeTests.testAccessToContainer();
            }
            if (type == 3) {
                std::deque<double> array(length);
                Generator<std::deque<double>> generator{ array };
                resultTest += generator.randDouble(min, max, step);
                findMaxAndMin(array);
                TimeTests<std::deque<double>> timeTests{ array };
                resultTest += timeTests.testAccessToContainer();
            }
        }
        std::cout << resultTest << std::endl;
    }
}
