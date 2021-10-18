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
	int max=0;
	int count = 0;
	int clone_arr[1000];
	int arr_result[1000];
	for (int i = 0, j = i + 1; i < n - 1 && j < n; i++, j++)
	{
		if (in_arr[i] < in_arr[j])
		{
			clone_arr[count] = in_arr[i];
			count += 1;
		}
		if (in_arr[i] > in_arr[j])
		{
			clone_arr[count] = in_arr[i];
			if (max < count)
			{
				max = count;
				for (int k = 0; k <= count; k++)
					arr_result[k] = clone_arr[k];
			}
			count = 0;
		}
	}
	printf("Increasing ");
	for (int i = 0; i <= max; i++)
		printf("%d ", arr_result[i]);
	printf("Decreasing ");
	count = 0;
	max = 0;
	for (int i = 0, j = i + 1; i < n - 1 && j < n; i++, j++)
	{
		if (in_arr[i] > in_arr[j])
		{
			clone_arr[count] = in_arr[i];
			count += 1;
		}
		if (in_arr[i] < in_arr[j])
		{
			clone_arr[count] = in_arr[i];
			if (max < count)
			{
				max = count;
				for (int k = 0; k <= count; k++)
					arr_result[k] = clone_arr[k];
			}
			count = 0;
		}
	}
	for (int i = 0; i <= max; i++)
		printf("%d ", arr_result[i]);
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