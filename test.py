import random
import time

testArray = [random.randint(0, 99) for i in range(10000)]


def sumAdjacentWithMap(arr):
    return [x + arr[i + 1] for i, x in enumerate(arr[:-1])]


def sumAdjacentWithReduce(arr):
    return sum([x + arr[i + 1] for i, x in enumerate(arr[:-1])])


def sumAdjacentWithForLoop(arr):
    result = []
    for i in range(len(arr) - 1):
        result.append(arr[i] + arr[i + 1])
    return result


def sumArrayOptimal(arr):
    return sum(arr)


def sumAdjacentValues(array):
    sum = 0
    for i in range(len(array) - 1):
        sum += array[i] + array[i + 1]
    return sum


def sumAdjacentWithMapAndTernary(arr):
    return [x + arr[i + 1] for i, x in enumerate(arr[:-1]) if i < len(arr) - 1]


def sumAdjacentWithArrayFrom(arr):
    return [arr[i] + arr[i + 1] for i in range(len(arr) - 1)]


def sumAdjacentWithWhileLoop(arr):
    result = []
    i = 0
    while i < len(arr) - 1:
        result.append(arr[i] + arr[i + 1])
        i += 1
    return result


def sumAdjacentWithPointers(arr):
    left = 0
    right = 1
    sum = 0
    while right < len(arr):
        sum += arr[left] + arr[right]
        left += 1
        right += 1
    return sum


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
