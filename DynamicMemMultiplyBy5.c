/**
* Statement: Write a program that will read an integer array * from user. Write a function ‘modify’ that will multiply 
* each array element by 5. Print the new array elements.
*
* Date: 19/10/21
* Version: 0.1
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "DynamicMemMultiplyBy5.h"

int main()
{
	//uint16_t *pointerToDynamicArray;
	uint8_t counter = 0;

	// syntax: ptr = (cast-type*) malloc(byte-size)
	// Example: ptr = (int*) malloc(100 * sizeof(int));
	pointerToDynamicArray = (uint16_t *)malloc(ARRAY_SIZE*sizeof(uint16_t));

	printf("Enter the 5 array emlements:\n");
	for(counter = 0; counter < ARRAY_SIZE; counter++)
	  scanf("%hu", (pointerToDynamicArray + counter));

	modify(pointerToDynamicArray);

	printf("Array emenemnts are:\n");
	for(counter = 0; counter < ARRAY_SIZE; counter++)
		printf("  Element %d: %5d\n",counter+1, *(pointerToDynamicArray + counter));

	free(pointerToDynamicArray);
	return 0;
}


uint8_t modify(uint16_t *pointerToDynamicArray)
{
	uint8_t counter = 0;

	for(counter=0; counter < ARRAY_SIZE; counter++)
	  *(pointerToDynamicArray+counter) *= MULTIPLIER;

	return 1;
}