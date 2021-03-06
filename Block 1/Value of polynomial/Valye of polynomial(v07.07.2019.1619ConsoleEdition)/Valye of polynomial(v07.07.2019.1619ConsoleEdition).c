/*http://opk.afti.ru/tasks/znachenie-mnogochlena
Условие:
*Коэффициенты многочлена лежат в массиве a: a[0]...a[n] (n ≥ 0 - степень многочлена).
*Вычислить значение этого многочлена в точке x, то есть a[n]xn +...+ a[1]x + a[0].
///double polynom(double x, double a[], int n)
///{
///    ....
///}
*/
///First argument is value at point
/// Second argument is power of polynomial
///  Other arguments after second is coefficients of polynomial
////if returned:
////(1) - cheker memory isn't allocate because:
////	a)not enought arguments;
////	 b)not enought memory;
////	  c)something else.
////(2) - First argument doesn't exist
////(3) - Second argument doesn't exist
////(4) - One of other arguments after second doesn't exist
////(5) - Memory for coefficient massive isn't allocate
#include <stdio.h>
#include "FoolTest.h"

double polynom(double x, double coefficientMassive[], int power);

void FoolTest(int argc, char* argv[], _Bool checker[]);

int main(int argc, char* argv[]) 
{
	double x = 0, *coefficientMassive = NULL;
	int power = 0;
	_Bool *checker=NULL;

	if (ArgcChecher == FALSE) {
		return 1;
	}

	checker = (_Bool*)malloc(argc * sizeof(_Bool));

	FoolTest(argc, argv, checker);
	if (checker == NULL) {
		return 1;
	}
	if (checker[0] == FALSE) {
		return 2;
	}
	else if (checker[1] == FALSE) {
		return 3;
	}
	else if (checker[2] == FALSE) {
		return 4;
	}

	coefficientMassive = (double*)malloc((power + 2) * sizeof(double));
	if (coefficientMassive == NULL) {
		return 5;
	}
	x = DigitOrFloatAssign(x, argv, 1);
	power = atoi(argv[2]);

	for (int i = 0; i < power + 1; i++) {
		coefficientMassive[i] = DigitOrFloatAssign(coefficientMassive[i], argv, 3 + i);
	}

	printf("\n %lf", polynom(x, coefficientMassive, power));
	free(checker);
	//free(coefficientMassive);??????crash on it, why?
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

void FoolTest(int argc, char* argv[], _Bool checker[]) 
{
	if (argc < 4) {
		return 0;
	}

	for (int i = 0; i < argc; i++) {
		if (argv[i] == NULL) {
			return 0;
		}
	}

	checker[0] = FloatChecker(argv, 1);

	if (DigitChecker(argv, 2) == FALSE) {
		checker[1] = FALSE;
		return 0;
	}

	for (int i = 0; i < atoi(argv[2])+1; i++) {
		if (DigitChecker(argv, 3 + i) == FALSE) {
			checker[2] = FALSE;
		}
	}
}
