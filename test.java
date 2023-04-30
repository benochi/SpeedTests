package com.psauer;

import java.util.Random;

public class test {
    private static final int SIZE = 10000;

    interface TestFunction {
        void run(int[] arr);
    }

    public static void sumAdjacentWithMap(int[] arr){
        for (int i = 0; i < SIZE -1; i++){
            arr[i] = arr[i] + arr[i+1];
        }
    }

    public static void sumAdjacentWithReduce(int[] arr){
        int sum = 0;
        for (int i = 0; i < SIZE -1; i++){
            sum += arr[i] + arr[i+1];
        }
    }
    public static void sumAdjacentWithForLoop(int[] arr) {
        int result[] = new int[SIZE];
        for (int i = 0; i < SIZE - 1; i++)
        {
            result[i] = arr[i] + arr[i + 1];
        }
    }
    public static void sumArrayOptimal(int[] arr)
    {
        int sum = 0;
        for (int i = 0; i < SIZE; i++)
        {
            sum += arr[i];
        }
    }

    public static void sumAdjacentWithMapAndTernary(int[] arr)
    {
        int result[] = new int[SIZE];
        for (int i = 0; i < SIZE - 1; i++)
        {
            result[i] = arr[i] + arr[i + 1];
        }
    }
    public static void sumAdjacentValues(int[] arr)
    {
        int sum = 0;
        for (int i = 0; i < SIZE - 1; i++)
        {
            sum += arr[i] + arr[i + 1];
        }
    }
    public static void sumAdjacentWithArrayFrom(int[] arr)
    {
        int result[] = new int[SIZE];
        for (int i = 0; i < SIZE - 1; i++)
        {
            result[i] = arr[i] + arr[i + 1];
        }
    }
    public static void sumAdjacentWithWhileLoop(int[] arr)
    {
        int result[] = new int[SIZE];
        int i = 0;
        while (i < SIZE - 1)
        {
            result[i] = arr[i] + arr[i + 1];
            i++;
        }
    }
    public static void runTest(String testName, TestFunction testFunction){
        int[] testArray = new int[SIZE];
        Random random = new Random();

        for (int i = 0; i < SIZE; i++) {
            testArray[i] = random.nextInt(100);
        }

        long totalTime = 0;
        for (int i = 0; i < 100; i++) {
            long startTime = System.nanoTime();
            testFunction.run(testArray);
            long endTime = System.nanoTime();
            totalTime += (endTime - startTime);
        }
        System.out.println(testName + " took " + totalTime + " nanoseconds in total.");
    }



    public static void main(String[] args) {
	    runTest("sumAdjacentWithMap", test::sumAdjacentWithMap);
        runTest("sumAdjacentWithReduce", test::sumAdjacentWithReduce);
        runTest("sumAdjacentWithForLoop", test::sumAdjacentWithForLoop);
        runTest("sumArrayOptimal", test::sumArrayOptimal);
        runTest("sumAdjacentValues", test::sumAdjacentValues);
        runTest("sumAdjacentWithMapAndTernary", test::sumAdjacentWithMapAndTernary);
        runTest("sumAdjacentWithArrayFrom", test::sumAdjacentWithArrayFrom);
        runTest("sumAdjacentWithWhileLoop", test::sumAdjacentWithWhileLoop);
    }
}
