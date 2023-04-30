import numpy as np
import time

testArray = np.random.randint(0, 100, 10000)


def sumAdjacentWithMap(arr):
    return arr[:-1] + arr[1:]


def sumAdjacentWithReduce(arr):
    return np.sum(arr[:-1] + arr[1:])


def sumAdjacentWithForLoop(arr):
    result = []
    for i in range(len(arr) - 1):
        result.append(arr[i] + arr[i + 1])
    return result


def sumArrayOptimal(arr):
    return np.sum(arr)


def sumAdjacentValues(array):
    return np.sum(array[:-1] + array[1:])


def sumAdjacentWithMapAndTernary(arr):
    return np.array([arr[i] + arr[i + 1] for i in range(len(arr) - 1)])


def sumAdjacentWithArrayFrom(arr):
    return arr[:-1] + arr[1:]


def sumAdjacentWithWhileLoop(arr):
    result = []
    i = 0
    while i < len(arr) - 1:
        result.append(arr[i] + arr[i + 1])
        i += 1
    return result


def sumAdjacentWithPointers(arr):
    return np.sum(arr[:-1] + arr[1:])


def runTest(testName, testFunction):
    start = time.monotonic_ns()
    for i in range(100):
        testFunction(testArray)
    end = time.monotonic_ns()
    print(f"{testName} took {(end - start)} nanoseconds in total for 100 loops.")


runTest("sumAdjacentWithMap", sumAdjacentWithMap)
runTest("sumAdjacentWithReduce", sumAdjacentWithReduce)
runTest("sumAdjacentWithForLoop", sumAdjacentWithForLoop)
runTest("sumArrayOptimal", sumArrayOptimal)
runTest("sumAdjacentValues", sumAdjacentValues)
runTest("sumAdjacentWithMapAndTernary", sumAdjacentWithMapAndTernary)
runTest("sumAdjacentWithArrayFrom", sumAdjacentWithArrayFrom)
runTest("sumAdjacentWithWhileLoop", sumAdjacentWithWhileLoop)
runTest("sumAdjacentWithPointers", sumAdjacentWithPointers)
