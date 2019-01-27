//Подсчёт количества простых годов в интервале от startAge до startAge + countYear

#include <cstdio>
#include <iostream>

using namespace std;

int g_arrPosition = 0;
int g_arrPrYears[70];

bool FindPrime(int aDivider) {
  //  Ищем простые делители 
	if (aDivider == 2) return true;
	if (aDivider % 2 == 0) return false;

	for (int i = 3; i <= aDivider / i; i += 2)
		if (aDivider % i == 0) return false;

	return true;
}

int YearsSolve(int aPosition, int aLeft, int aRight) {
  // Ищем количество простых лет
	if (aPosition == g_arrPosition || g_arrPrYears[aPosition] > aRight) return aRight - aLeft;
	else if (aLeft == aRight) return 0;
	else return YearsSolve(aPosition + 1, aLeft, aRight) - YearsSolve(aPosition + 1, aLeft / g_arrPrYears[aPosition], aRight / g_arrPrYears[aPosition]);
}

int main() {
	int startAge, countYears, countMinutes;

	cin >> startAge >> countYears >> countMinutes;

  for (int i = 2; i <= countMinutes + 1; ++i)
		if (FindPrime(i))
			g_arrPrYears[g_arrPosition++] = i;

	int primeYears = YearsSolve(0, startAge, startAge + countYears);

	for (int i = 0; i < g_arrPosition; ++i)
		if (g_arrPrYears[i] > startAge && g_arrPrYears[i] <= startAge + countYears)
			++primeYears;

	cout << primeYears;

	return 0;
}