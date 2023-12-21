#include <math.h>
#include <chrono>
#include <stdexcept>
#include <string>
#include <iostream>



using namespace std::chrono;
template<typename Container>
class Generator
{
public:

	Generator(Container& _container) : container(_container) {};

	std::string createAnswer(double time) {
		std::string answer = "Time of contaner filling: ";
		if (time > 100000.0) {
			answer += std::to_string(time / (1000 * 1000));
			answer += " seconds";
		}
		else {
			answer += std::to_string(time);
			answer += " microseconds";
		}
		answer += "\n";
		return answer;
	}


	std::string randint(int minValue, int maxValue, int stepSize = 1) {
		if (stepSize < 0) {
			throw std::invalid_argument("stepSize must be > 0");
		}
		else {
			int min = ceil(minValue / stepSize);
			int max = floor(maxValue / stepSize);

			auto start = high_resolution_clock::now();

			for (auto& element : container) {
				element = (int)((double)rand() / (RAND_MAX) * (max - min) + min) * stepSize;
			}

			auto stop = high_resolution_clock::now();

			double time = (double)duration_cast<nanoseconds>(stop - start).count() / 1000;

			return createAnswer(time);
		}

	}

	std::string randLongInt(int minValue, int maxValue, int stepSize = 1) {
		if (stepSize < 0) {
			throw std::invalid_argument("stepSize mast be > 0");
		}
		else {
			int min = ceil(minValue / stepSize);
			int max = floor(maxValue / stepSize);

			auto start = high_resolution_clock::now();

			for (auto& element : container) {
				element = (long int)((double)rand() / (RAND_MAX) * (max - min) + min) * stepSize;
			}

			auto stop = high_resolution_clock::now();

			double time = (double)duration_cast<nanoseconds>(stop - start).count() / 1000;
			return createAnswer(time);
		}
	}

	std::string randFloat(float minValue, float maxValue, float stepSize) {
		if (stepSize < 0 || maxValue < stepSize) {
			throw std::invalid_argument("stepSize must be > 0");
		}
		else if (stepSize <= 1) {
			int transferCoeficent = (int)(1 / stepSize);
			int min = minValue * transferCoeficent;
			int max = maxValue * transferCoeficent;

			auto start = high_resolution_clock::now();

			for (auto& element : container) {
				element = (float)((double)rand() / (RAND_MAX) * (max - min) + min) * stepSize;
			}

			auto stop = high_resolution_clock::now();

			double time = (double)duration_cast<nanoseconds>(stop - start).count() / 1000;
			return createAnswer(time);
		}
		else {
			auto start = high_resolution_clock::now();

			for (auto& element : container) {
				element = (float)((double)rand() / (RAND_MAX) * (maxValue - minValue) + minValue) / stepSize;
			}

			auto stop = high_resolution_clock::now();

			double time = (double)duration_cast<nanoseconds>(stop - start).count() / 1000;
			return createAnswer(time);
		}

	}

	std::string randDouble(double minValue, double maxValue, double stepSize) {
		if (stepSize < 0 || maxValue < stepSize) {
			throw std::invalid_argument("stepSize must be > 0");
		}
		else if (stepSize <= 1) {
			long long int transferCoeficent = (1 / stepSize);
			long int min = minValue * transferCoeficent;
			long int max = maxValue * transferCoeficent;

			auto start = high_resolution_clock::now();

			for (auto& element : container) {
				element = (double)((double)rand() / (RAND_MAX) * (max - min) + min) * stepSize;
			}

			auto stop = high_resolution_clock::now();

			double time = (double)duration_cast<nanoseconds>(stop - start).count() / 1000;
			return createAnswer(time);
		}
		else {
			int min = ceil(minValue / stepSize);
			int max = floor(maxValue / stepSize);
			auto start = high_resolution_clock::now();

			for (auto& element : container) {
				element = ((double)rand() / (RAND_MAX) * (max - min) + min) * stepSize;
			}

			auto stop = high_resolution_clock::now();

			double time = (double)duration_cast<nanoseconds>(stop - start).count() / 1000;
			return createAnswer(time);
		}

	};
	private:
		Container& container;
};