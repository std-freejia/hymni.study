#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSort(int arr[], int count);

int main(int argc, char *argv[], char *env[]){

	int arrayLength = 0;
	int result = 0;
	
	printf("Please Enter the Array Length : ");
	scanf("%d", &arrayLength);

	int aArray[arrayLength];
	int bArray[arrayLength];
	int cArray[arrayLength];

	printf("Enter the 'A' array index value : ");
	for(int i = 0; i < arrayLength; i++)
	{
		scanf("%d", &aArray[i]);
	}

	printf("Enter the 'B' array index value : ");
	for(int i = 0; i < arrayLength; i++)
	{
		scanf("%d", &bArray[i]);
	}

	memcpy(cArray, bArray, sizeof(bArray));

	bubbleSort(aArray, sizeof(aArray) / sizeof(int));
	bubbleSort(cArray, sizeof(cArray) / sizeof(int));

	for(int i = 0; i < arrayLength; i++)
	{
		result += (aArray[i] * cArray[arrayLength - (i+1)]);
	}

	printf("Result : %d\n", result);

	return 0;
}

void bubbleSort(int arr[], int count)
{
	int temp = 0;

	for(int i = 0; i < count; i++)
	{
		for(int j = 0; j < count - 1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
