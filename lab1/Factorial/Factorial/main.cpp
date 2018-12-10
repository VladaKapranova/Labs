#include <stdio.h>
#include <iostream>
#include <cstdlib>

long factorial(int number) // factorial calculation function
{
	long result = 1;
	for (int i = 1; i <= number; i++)
		result = result * i;
	return result;
}

int main()
{
	int x;
	long result;
	std::cout << "Input number: ";
	std::cin >> x;

	result = factorial(x);
	std::cout << "Factorial: " << result << std::endl;

	system("pause");

	return 0;
}
