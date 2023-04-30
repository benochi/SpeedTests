const testArray = Array.from({ length: 10000 }, () => Math.floor(Math.random() * 100));

function sumAdjacentWithMap(arr) {
  return arr.slice(0, -1).map((x, i) => x + arr[i + 1]);
}

function sumAdjacentWithReduce(arr) {
  return arr.slice(0, -1).reduce((acc, cur, i) => acc + cur + arr[i + 1], 0);
}

function sumAdjacentWithForLoop(arr) {
  const result = [];
  for (let i = 0; i < arr.length - 1; i++) {
    result.push(arr[i] + arr[i + 1]);
  }
  return result;
}

function sumArrayOptimal(arr) {
  return arr.reduce((acc, cur) => acc + cur, 0);
}

function sumAdjacentValues(array) {
  let sum = 0;
  for (let i = 0; i < array.length - 1; i++) {
    sum += array[i] + array[i + 1];
  }
  return sum;
}

function sumAdjacentWithMapAndTernary(arr) {
  return arr.map((x, i) => i < arr.length - 1 ? x + arr[i + 1] : null).filter(x => x !== null);
}

function sumAdjacentWithArrayFrom(arr) {
  return Array.from({ length: arr.length - 1 }, (_, i) => arr[i] + arr[i + 1]);
}

function sumAdjacentWithWhileLoop(arr) {
  const result = [];
  let i = 0;
  while (i < arr.length - 1) {
    result.push(arr[i] + arr[i + 1]);
    i++;
  }
  return result;
}

function sumAdjacentWithPointers(arr) {
  let left = 0;
  let right = 1;
  let sum = 0;

  while (right < arr.length) {
    sum += arr[left] + arr[right];
    left++;
    right++;
  }

  return sum;
}


function runTest(testName, testFunction) {
  const start = process.hrtime.bigint();
  for (let i = 0; i < 100; i++) {
    testFunction(testArray);
  }
  const end = process.hrtime.bigint();
  const totalNanoseconds = Number((end - start) / BigInt(1));
  console.log(`${testName} took ${totalNanoseconds} nanoseconds in total.`);
}

runTest('sumAdjacentWithMap', sumAdjacentWithMap);
runTest('sumAdjacentWithReduce', sumAdjacentWithReduce);
runTest('sumAdjacentWithForLoop', sumAdjacentWithForLoop);
runTest('sumArrayOptimal', sumArrayOptimal);
runTest('sumAdjacentValues', sumArrayOptimal);
runTest('sumAdjacentWithWhileLoop', sumAdjacentWithWhileLoop);
runTest('sumAdjacentWithArrayFrom', sumAdjacentWithArrayFrom);
runTest('sumAdjacentWithMapAndTernary', sumAdjacentWithMapAndTernary);
runTest('sumAdjacentWithPointers', sumAdjacentWithPointers);
