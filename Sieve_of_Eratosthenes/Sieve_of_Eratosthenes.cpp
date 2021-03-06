// Krzysztof Kwietniewski 

#include "pch.h"
#include <list>
#include <chrono>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <boost/multiprecision/cpp_int.hpp>

int main()
{
	using namespace boost::multiprecision;

	int128_t input;
	std::list<int> divisorsArray;

	std::cout << "Sieve of Eratosthenes | MAX number for this program = 2^128 - 1" << std::endl << std::endl << "provide number: ";

	std::cin >> input;
	std::cout << std::endl;

	float remainder;
	
	// CLOCK START
	auto t_start = std::chrono::high_resolution_clock::now();

	for (int i = 2; i < 10; i++) {
		remainder = (float)(input % i);

		std::cout << "Remainder of division " << input << " by " << i << "\n" << "Equale to: " << remainder << std::endl;
		
		if (remainder == 0) {
			divisorsArray.push_back(i);
		}

	}

	// CLOCK STOP
	auto t_end = std::chrono::high_resolution_clock::now();

	if (divisorsArray.size() < 2)
	{
		std::cout << std::endl << "Number: " << input << " is prime";
	}

	else
	{
		std::cout << std::endl << "Number: " << input << " divides by: " << std::endl;
		for (auto v : divisorsArray)
			std::cout << v << ", ";
		std::cout << std::endl << std::endl << input << " is NOT prime";
	}

	// DISPLAY CLOCK
	std::cout << std::endl << std::endl << "Operation took: " << std::endl << std::chrono::duration<double, 
std::milli>(t_end - t_start).count() << " ms" << " of real time" << "\n";

	
}
