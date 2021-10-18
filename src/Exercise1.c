/*
1.	Input an array of n integers. Write a function to check whether
the array is symmetric or not (optional: use recursive)
Ex:
 ____________________________________
| Input: 1 2 3 2 1                   |
| Output: symmetric                  |
|____________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Ex1(int arr[], int n) {
	int kt = 1;
	int i = 0;
	int j = n - 1;
	while (i < n % 2 && j >= n % 2)
	{
		if (arr[i] == arr[j])
		{
			i += 1;
			j -= 1;
		}
		else
		{
			kt = 0;
			break;
		}
	}
	if (kt == 1)
		printf("asymmetric");
	else
		printf("not asymmetric");

}

int main(int argc, char* argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	argc--;
	int testcase[argc], i;
	for (i = 0; i < argc; i++) {
		testcase[i] = atoi(argv[i + 1]);
	}

	Ex1(testcase, argc);

	return 0;
}