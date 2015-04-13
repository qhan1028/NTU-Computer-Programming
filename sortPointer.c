#include <stdio.h> 

#define MAXN 700

int sortPointer(int *pointerArray[], int sizeArray[], int *result)
{
  	int i, j, k;
  	int n = 0;

  	for (i = 0 ; sizeArray[i] != 0 ; i++) {
  		n += sizeArray[i];
  	}

  	i = 0;
  	k = 0;
  	while(sizeArray[i] != 0) {
  		for (j = 0 ; j < sizeArray[i] ; j++, k++) {
  			result[k] =  *( *(pointerArray + i) + j ); 
  		} 
  		i++;
  	}

  	int temp;

  	for (i = 0 ; i < n ; i++) {
  		for (j = i+1 ; j < n ; j++) {
  			if (result[i] > result[j]) {
  				temp = result[i];
  				result[i] = result[j];
  				result[j] = temp;
  			}
  		}
  	}
  	return n;
}

int main()
{
  int a[] = {3, 6, 19, -20};
	int b[] = {23, -6, 13};
 	int c[] = {-31, 26, 49, 20};

	int *pointerArray[] = {b, c, a};
	int sizeofa = sizeof(a) / sizeof(int);
	int sizeofb = sizeof(b) / sizeof(int);
	int sizeofc = sizeof(c) / sizeof(int);
	int sizeArray[] = {sizeofb, sizeofc, sizeofa, 0};
  	int result[MAXN];
  	int i;
  	int totalNumber = sortPointer(pointerArray, sizeArray, result);

 	for (i = 0; i < totalNumber; i++)
   		printf("%d\n", result[i]);

 	return 0;
}