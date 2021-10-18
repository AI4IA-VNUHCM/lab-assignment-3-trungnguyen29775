/*
3.	Input an array of n integers. Find the largest sorted sub array
(sorted array increasing/decreasing and has the largest number of elements)
Ex:
 _____________________________________________
| Input: 2 5 3 4 8 9 7 6 10                   |
| Output: Increasing 3 4 8 9 Decreasing 9 7 6 |
|_____________________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Ex3(int in_arr[], int n) {
	int number_arr_in = -1;
	int number_arr_de = -1;
	int arr_in[1000];
	int arr_de[1000];
	int max_number_arr_in = 0;
	int max_number_arr_de = 0;
	int arr_clone[1000];
	for (int i = 0; i < n - 1; i++)
	{
		if (in_arr[i] < in_arr[i + 1])
		{
			number_arr_in += 1;
			arr_clone[number_arr_in] = in_arr[i];
		}
		if (in_arr[i] > in_arr[i + 1])
		{
			number_arr_in += 1;
			arr_clone[number_arr_in] = in_arr[i];
			if (max_number_arr_in < number_arr_in)
			{
				max_number_arr_in = number_arr_in;
				for (int j = 0; j <= number_arr_in; j++)
					arr_in[j] = arr_clone[j];

			}
			number_arr_in = -1;
		}
	}
	printf("Increasing ");
	for (int i = 0; i <= max_number_arr_in; i++)
		printf("%d ", arr_in[i]);
	for (int i = 0; i < n - 1; i++)
	{
		if (in_arr[i] > in_arr[i + 1])
		{
			number_arr_de += 1;
			arr_clone[number_arr_de] = in_arr[i];
		}
		if (in_arr[i] < in_arr[i + 1])
		{
			number_arr_de += 1;
			arr_clone[number_arr_de] = in_arr[i];
			if (max_number_arr_de < number_arr_de)
			{
				max_number_arr_de = number_arr_de;
				for (int j = 0; j <= number_arr_de; j++)
					arr_de[j] = arr_clone[j];

			}
			number_arr_de = -1;
		}
	}
	printf("Decreasing ");
	for (int i = 0; i <= max_number_arr_de; i++)
		printf("%d ", arr_de[i]);

}

int main(int argc, char* argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	argc--;
	int testcase[argc], i;
	for (i = 0; i < argc; i++) {
		testcase[i] = atoi(argv[i + 1]);
	}

	Ex3(testcase, argc);

	return 0;
}