#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

void sumAdjacentWithMap(int *arr)
{
  for (int i = 0; i < SIZE - 1; i++)
  {
    arr[i] = arr[i] + arr[i + 1];
  }
}

void sumAdjacentWithReduce(int *arr)
{
  int sum = 0;
  for (int i = 0; i < SIZE - 1; i++)
  {
    sum += arr[i] + arr[i + 1];
  }

}

void sumAdjacentWithForLoop(int *arr)
{
  int result[SIZE];
  for (int i = 0; i < SIZE - 1; i++)
  {
    result[i] = arr[i] + arr[i + 1];
  }
}

void sumArrayOptimal(int *arr)
{
  int sum = 0;
  for (int i = 0; i < SIZE; i++)
  {
    sum += arr[i];
  }
  
}

void sumAdjacentValues(int *arr)
{
  int sum = 0;
  for (int i = 0; i < SIZE - 1; i++)
  {
    sum += arr[i] + arr[i + 1];
  }
}

void sumAdjacentWithMapAndTernary(int *arr)
{
  int result[SIZE];
  for (int i = 0; i < SIZE - 1; i++)
  {
    result[i] = arr[i] + arr[i + 1];
  }
}

void sumAdjacentWithArrayFrom(int *arr)
{
  int result[SIZE];
  for (int i = 0; i < SIZE - 1; i++)
  {
    result[i] = arr[i] + arr[i + 1];
  }
}

void sumAdjacentWithWhileLoop(int *arr)
{
  int result[SIZE];
  int i = 0;
  while (i < SIZE - 1)
  {
    result[i] = arr[i] + arr[i + 1];
    i++;
  }
}

void sumAdjacentWithPointers(int *arr)
{
  int sum = 0;
  int *left = arr;
  int *right = arr + 1;
  for (int i = 0; i < SIZE - 1; i++)
  {
    sum += *left + *right;
    left++;
    right++;
  }
}

void runTest(char *testName, void (*sumAdjacentFunction)(int *))
{
  int testArray[SIZE];
  
  for (int i = 0; i < SIZE; i++)
  {
    testArray[i] = rand() % 100;
  }

  long total_time = 0;
  for (int i = 0; i < 100; i++)
  {
    clock_t start = clock();
    sumAdjacentFunction(testArray);
    clock_t end = clock();
    total_time += (end - start);
  }
  printf("%s took %ld nanoseconds in total.\n", testName, total_time);
}

int main()
{
  srand(time(NULL));
  runTest("sumAdjacentWithMap", sumAdjacentWithMap);
  runTest("sumAdjacentWithReduce", sumAdjacentWithReduce);
  runTest("sumAdjacentWithForLoop", sumAdjacentWithForLoop);
  runTest("sumArrayOptimal", sumArrayOptimal);
  runTest("sumAdjacentValues", sumAdjacentValues);
  runTest("sumAdjacentWithMapAndTernary", sumAdjacentWithMapAndTernary);
  runTest("sumAdjacentWithArrayFrom", sumAdjacentWithArrayFrom);
  runTest("sumAdjacentWithWhileLoop", sumAdjacentWithWhileLoop);
}