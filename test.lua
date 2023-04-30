function createTestArray(length)
  local arr = {}
  for i = 1, length do
    table.insert(arr, math.floor(math.random() * 100))
  end
  return arr
end

function sumAdjacentWithMap(arr)
  local result = {}
  for i = 1, #arr - 1 do
    table.insert(result, arr[i] + arr[i+1])
  end
  return result
end

function sumAdjacentWithReduce(arr)
  local result = 0
  for i = 1, #arr - 1 do
    result = result + arr[i] + arr[i+1]
  end
  return result
end

function sumAdjacentWithForLoop(arr)
  local result = {}
  for i = 1, #arr - 1 do
    table.insert(result, arr[i] + arr[i+1])
  end
  return result
end

function sumArrayOptimal(arr)
  local result = 0
  for i = 1, #arr do
    result = result + arr[i]
  end
  return result
end

function sumAdjacentValues(arr)
  local result = 0
  for i = 1, #arr - 1 do
    result = result + arr[i] + arr[i+1]
  end
  return result
end

function sumAdjacentWithMapAndTernary(arr)
  local result = {}
  for i = 1, #arr - 1 do
    table.insert(result, i < #arr and arr[i] + arr[i+1] or nil)
  end
  return result
end

function sumAdjacentWithArrayFrom(arr)
  local result = {}
  for i = 1, #arr - 1 do
    table.insert(result, arr[i] + arr[i+1])
  end
  return result
end

function sumAdjacentWithWhileLoop(arr)
  local result = {}
  local i = 1
  while i < #arr do
    table.insert(result, arr[i] + arr[i+1])
    i = i + 1
  end
  return result
end

function sumAdjacentWithPointers(arr)
  local left = 1
  local right = 2
  local result = 0
  while right <= #arr do
    result = result + arr[left] + arr[right]
    left = left + 1
    right = right + 1
  end
  return result
end

function runTest(testName, testFunction)
  local testArray = createTestArray(10000)
  local start = os.clock()
  for i = 1, 100 do
    testFunction(testArray)
  end
  local end_ = os.clock()
  local totalNanoseconds = (end_ - start) * 1e9
  print(string.format("%s took %d nanoseconds in total.", testName, totalNanoseconds))
end

runTest("sumAdjacentWithMap", sumAdjacentWithMap)
runTest("sumAdjacentWithReduce", sumAdjacentWithReduce)
runTest("sumAdjacentWithForLoop", sumAdjacentWithForLoop)
runTest("sumArrayOptimal", sumArrayOptimal)
runTest("sumAdjacentValues", sumAdjacentValues)
runTest("sumAdjacentWithMapAndTernary", sumAdjacentWithMapAndTernary)
runTest("sumAdjacentWithArrayFrom", sumAdjacentWithArrayFrom)
runTest("sumAdjacentWithWhileLoop", sumAdjacentWithWhileLoop)
runTest("sumAdjacentWithPointers", sumAdjacentWithPointers)
