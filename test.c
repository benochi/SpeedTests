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

int sumAdjacentWithReduce(int *arr)
{
  int sum = 0;
  for (int i = 0; i < SIZE - 1; i++)
  {
    sum += arr[i] + arr[i + 1];
  }
  return sum;
}

void sumAdjacentWithForLoop(int *arr, int *result)
{
  for (int i = 0; i < SIZE - 1; i++)
  {
    result[i] = arr[i] + arr[i + 1];
  }
}

int sumArrayOptimal(int *arr)
{
  int sum = 0;
  for (int i = 0; i < SIZE; i++)
  {
    sum += arr[i];
  }
  return sum;
}

int sumAdjacentValues(int *arr)
{
  int sum = 0;
  for (int i = 0; i < SIZE - 1; i++)
  {
    sum += arr[i] + arr[i + 1];
  }
  return sum;
}

void sumAdjacentWithMapAndTernary(int *arr, int *result)
{
  for (int i = 0; i < SIZE - 1; i++)
  {
    result[i] = arr[i] + arr[i + 1];
  }
}

void sumAdjacentWithArrayFrom(int *arr, int *result)
{
  for (int i = 0; i < SIZE - 1; i++)
  {
    result[i] = arr[i] + arr[i + 1];
  }
}

void sumAdjacentWithWhileLoop(int *arr, int *result)
{
  int i = 0;
  while (i < SIZE - 1)
  {
    result[i] = arr[i] + arr[i + 1];
    i++;
  }
}

int sumAdjacentWithPointers(int *arr)
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
  return sum;
}

void runTest(char *testName, void (*sumAdjacentFunction)(int *), int (*sumFunction)(int *))
{
  int testArray[SIZE];
  int result[SIZE - 1];
  for (int i = 0; i < SIZE; i++)
  {
    testArray[i] = rand() % 100;
  }

  long total_time = 0;
  for (int i = 0; i < 100; i++)
  {
    clock_t start = clock();
    sumAdjacentFunction(testArray, result);
    clock_t end = clock();
    total_time += (end - start);
  }
  printf("%s took %ld nanoseconds in total.\n", testName, total_time);
}

int main()
{
  srand(time(NULL));
  runTest("sumAdjacentWithMap", sumAdjacentWithMap, NULL);
  runTest("sumAdjacentWithReduce", sumAdjacentWithReduce, NULL);
  runTest("sumAdjacentWithForLoop", sumAdjacentWithForLoop, NULL);
  runTest("sumArrayOptimal", sumArrayOptimal, NULL);
  runTest("sumAdjacentValues", sumAdjacentValues, NULL);
  runTest("sumAdjacentWithMapAndTernary", sumAdjacentWithMapAndTernary, NULL);
  runTest("sumAdjacentWithArrayFrom", sumAdjacentWithArrayFrom, NULL);
  runTest("sumAdjacentWithWhileLoop", sumAdjacentWithWhileLoop, NULL);
}