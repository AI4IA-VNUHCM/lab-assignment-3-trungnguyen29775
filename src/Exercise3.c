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

void Ex3(int in_arr[], int n){
	int fInc[n], fDec[n];
	fInc[0] = 1;
	fDec[0] = 1;

	int maxInc = 1;
	int maxDec = 1;
	int indexInc = 0, indexDec = 0;

	for (int i = 1; i < n; i++)
	{
		fInc[i] = 1;
		fDec[i] = 1;
		if (in_arr[i] < in_arr[i-1])
		{
			fDec[i] = fDec[i - 1] + 1;
			if (fDec[i] > maxDec)
			{
				maxDec = fDec[i];
				indexDec = i;
			}
		}
		else
		{
			fInc[i] = fInc[i - 1] + 1;
			if (fInc[i] > maxInc)
			{
				maxInc = fInc[i];
				indexInc = i;
			}
		}
	}

	printf("Increasing ");
	for (int i = indexInc - maxInc + 1; i <= indexInc; i++)
	{
		printf("%d ", in_arr[i]);
	}

	printf("Decreasing ");
	for (int i = indexDec - maxDec + 1; i <= indexDec; i++)
	{
		printf("%d ", in_arr[i]);
	}
	
}

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	argc--;
	int testcase[argc],i;
	for(i=0; i<argc;i++){
		testcase[i] = atoi(argv[i+1]);
	}
	
	Ex3(testcase, argc);
	
	return 0;
}
