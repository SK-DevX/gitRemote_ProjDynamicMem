#include<stdio.h>
#include<stdint.h>
#include<criterion/criterion.h>
#include "../DynamicMemMultiplyBy5.h"

#define ARRAY_SIZE 5

// Runs every time new test is created at the beginning of test. Like a constructor.
void suiteSetup(void)
{
  pointerToDynamicArray = (uint16_t *)malloc(ARRAY_SIZE * sizeof(uint16_t));
  printf("In Constructor!\n");
}

// Run everytime test is created at the end of test. Like a destructor.
void suiteTeardown(void)
{
  free(pointerToDynamicArray); 
  printf("In Destructor!\n");
}

TestSuite(dynamicMemTest, .init=suiteSetup, .fini=suiteTeardown);

// 1st step: Test should fail. This test is often added to verify if the test is running or not. 
// And If it run s it should run as expected.
Test(dynamicMemTest, createDynamicMemTest)
{
  cr_expect(pointerToDynamicArray == NULL, "Dynamic memory creation should not return null!");
}

// 2nd step: Test should pass.
Test(dynamicMemTest, createDynamicMemTest2)
{
  cr_expect(pointerToDynamicArray != NULL, "Dynamic memory creation should not return null!");
}
