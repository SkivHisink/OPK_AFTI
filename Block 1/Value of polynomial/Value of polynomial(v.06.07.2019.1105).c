/*http://opk.afti.ru/tasks/znachenie-mnogochlena
Условие:
*Коэффициенты многочлена лежат в массиве a: a[0]...a[n] (n ≥ 0 - степень многочлена).
*Вычислить значение этого многочлена в точке x, то есть a[n]xn +...+ a[1]x + a[0].
///double polynom(double x, double a[], int n)
///{
///    ....
///}
*/
#include <stdio.h>

double polynom(double x, double coefficientMassive[], int power);

int main(int argc, char* argv[])
{
	double x = 0, *coefficientMassive = NULL;
	int power = 0;

	printf("Enter value of point:");
	scanf_s("%lf", &x);
	printf("Enter value of power:");
	scanf_s("%d", &power);

	coefficientMassive = (double*)malloc((power + 1) * sizeof(double));

	for (int i = 0; i < power + 1; i++) {
		printf("Enter value of %d coefficient:", i);
		scanf_s("%lf", &coefficientMassive[i]);
	}

	printf("\n %lf", polynom(x, coefficientMassive, power));

	return 0;
}

double PowerSearch(double x, int i)
{
	double b = 1;

	if (i == 0) {
		return 1;
	}
	else if (i == 1) {
		return x;
	}
	else if (i > 1) {
		for (int j = 0; j < i; j++) {
			b *= x;
		}
		return b;
	}
}

double polynom(double x, double coefficientMassive[], int power)
{
	double answer = 0;

	for (int i = 0; i < power + 1; i++) {
		answer += PowerSearch(x, i) * coefficientMassive[i];
	}

	return answer;
}