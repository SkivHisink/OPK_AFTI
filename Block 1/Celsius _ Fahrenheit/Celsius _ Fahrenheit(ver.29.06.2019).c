/*http://opk.afti.ru/tasks/tselsiy-i-farengeyt
�������: 
*�������� ���������, ������� ��������� ������� ������� � ������� ���������� � �������.
*������������ ��������� ����� �������� � ������ ��������, ��������� ��������� ��� � ������ �������.
*�������: C = (F - 32) * 5/9
*/
#include <stdio.h>

int main()
{
	char System;
	float Temp=0;
	printf("Enter system of temperature:");
	scanf_s("%c", &System);
	printf("Enter temperature:");
	scanf_s("%f", &Temp);
	if (System == 'C') {
		Temp = Temp * 9 / 5 + 32;
		printf("%f temperature in Fahrenheit", Temp);
	}
	else if (System == 'F') {
		Temp = (Temp - 32) * 5 / 9;
		printf("%f temperature in Celsius", Temp);
	}
	else {
		printf("Error");
	}
	getchar();
	getchar();
	return 0;
}