/*http://opk.afti.ru/tasks/fizzbuzz
�������: 
�������� ���������, ������� ����� �������� ��� ����� �� 1 �� 100. ��� ����:
*���� ����� ������� �� 3, ������ ����� ���������� Fizz
*���� ����� ������� �� 5, ������ ����� ���������� Buzz
*���� ����� ������� � �� 3 � �� 5, ������ ����� ���������� FizzBuzz*/
#include <stdio.h>

int main()
{
	for (int i = 1; i < 101; i++) {
		if ((i % 3 == 0) && (i % 5 == 0))
			printf("FizzBuzz ");
		else if (i % 3 == 0)
			printf("Fizz ");
		else if (i % 5 == 0)
			printf("Buzz ");
		else
			printf("%d ", i);
	}
	getchar();
	return 0;
}