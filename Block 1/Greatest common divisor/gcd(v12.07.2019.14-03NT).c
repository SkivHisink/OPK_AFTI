/*http://opk.afti.ru/tasks/naibolshiy-obschiy-delitel
Условие:
*Для двух целых чисел a и b реализовать функцию, вычисляющую наибольший общий делитель НОД(a,b) по модифицированному алгоритму Евклида:
*НОД(a,b) = НОД(a mod b, b) при a≥b.
*НОД(a,b) = НОД(a, b mod a) при b≥a.
*НОД(a,0) = a
///int greatest_common_divisor(int a, int b) {
///    ... 
///}
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int greatest_common_divisor(int a, int b);

int main(int argc, char* argv[]) 
{
	int a = 0;
	int b = 0;
	printf("Enter two integer number:");
	scanf_s("%d%d", &a, &b);
	a = greatest_common_divisor(a, b);
	printf("%d", a);
	return 0; 
}

int greatest_common_divisor(int a, int b)
{
	int min, solution;
	if (a < b) {
		min = a;
	}
	else {
		min = b;
	}
	for (int i = 1; i < min; i++) {
		double s1 = (double)a / i;
		double s2 = (double)b / i;  
		if ((s1 == ceil(s1)) && (s2 == ceil(s2))) {
			solution = i;
		}
	}
	return solution;
}