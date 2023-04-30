package main

import (
    "fmt"
    "math/rand"
    "time"
)

func sumAdjacentWithMap(arr []int) []int {
    result := make([]int, len(arr)-1)
    for i := 0; i < len(result); i++ {
        result[i] = arr[i] + arr[i+1]
    }
    return result
}

func sumAdjacentWithReduce(arr []int) int {
    sum := 0
    for i := 0; i < len(arr)-1; i++ {
        sum += arr[i] + arr[i+1]
    }
    return sum
}

func sumAdjacentWithForLoop(arr []int) []int {
    result := make([]int, len(arr)-1)
    for i := 0; i < len(result); i++ {
        result[i] = arr[i] + arr[i+1]
    }
    return result
}

func sumArrayOptimal(arr []int) int {
    sum := 0
    for _, v := range arr {
        sum += v
    }
    return sum
}

func sumAdjacentValues(array []int) int {
    sum := 0
    for i := 0; i < len(array)-1; i++ {
        sum += array[i] + array[i+1]
    }
    return sum
}

func sumAdjacentWithMapAndTernary(arr []int) []int {
    result := make([]int, len(arr)-1)
    for i := 0; i < len(result); i++ {
        result[i] = arr[i] + arr[i+1]
    }
    return result
}

func sumAdjacentWithArrayFrom(arr []int) []int {
    result := make([]int, len(arr)-1)
    for i := 0; i < len(result); i++ {
        result[i] = arr[i] + arr[i+1]
    }
    return result
}

func sumAdjacentWithWhileLoop(arr []int) []int {
    result := make([]int, len(arr)-1)
    i := 0
    for i < len(result) {
        result[i] = arr[i] + arr[i+1]
        i++
    }
    return result
}

func sumAdjacentWithPointers(arr []int) int {
    left := 0
    right := 1
    sum := 0

    for right < len(arr) {
        sum += arr[left] + arr[right]
        left++
        right++
    }

    return sum
}

func runTest(testName string, testFunction func([]int) []int) {
    var testArray []int
    for i := 0; i < 10000; i++ {
        testArray = append(testArray, rand.Intn(100))
    }

    start := time.Now()
    for i := 0; i < 100; i++ {
        testFunction(testArray)
    }
    end := time.Now()
    totalNanoseconds := end.Sub(start).Nanoseconds()
    fmt.Printf("%s took %d nanoseconds in total.\n", testName, totalNanoseconds)
}

func main() {
	runTest("sumAdjacentWithMap", sumAdjacentWithMap)
	runTest("sumAdjacentWithReduce", sumAdjacentWithReduce)
	runTest("sumAdjacentWithForLoop", sumAdjacentWithForLoop)
	runTest("sumArrayOptimal", sumArrayOptimal)
	runTest("sumAdjacentValues", sumAdjacentValues)
	runTest("sumAdjacentWithWhileLoop", sumAdjacentWithWhileLoop)
	runTest("sumAdjacentWithArrayFrom", sumAdjacentWithArrayFrom)
	runTest("sumAdjacentWithMapAndTernary", sumAdjacentWithMapAndTernary)
	runTest("sumAdjacentWithPointers", sumAdjacentWithPointers)
}
