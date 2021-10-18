/*
5. Write a function to move all positive element of an array upfront
Ex:
______________________________________
| Input: 2 -3 4 6 -7 9 8 -2          |
| Output: 2 4 6 9 8 -3 -7 -2         |
|____________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Ex5(int arr[], int n){
	int pos[n], nonPos[n];
	int j = 0;
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > 0)
		{
			pos[j] = arr[i];
			j++;
		}
		else
		{
			nonPos[t] = arr[i];
			t++;
		}
	}

	// for (int i = 0; i < j; i++)
	// {
	// 	arr[i] = pos[i];
	// }

	// for (int i = 0; i < t; i++)
	// {
	// 	arr[j + i] = nonPos[i];
	// }

	for (int i = 0; i < j; i++)
	{
		printf("%d ", pos[i]);
	}

	for (int i = 0; i < t; i++)
	{
		printf("%d ", nonPos[i]);

	}
}

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	argc--;
	int testcase[argc],i;
	for(i=0; i<argc;i++){
		testcase[i] = atoi(argv[i+1]);
	}
	
	Ex5(testcase, argc);
	
	return 0;
}
