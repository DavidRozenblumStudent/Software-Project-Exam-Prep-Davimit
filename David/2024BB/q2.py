import numpy as np
import random


arr = np.array([random.randint(1, 100) for i in range(10)])
print(arr)

#answer
#isincreasing = np.where(arr[1:] > arr[:-1])[0]
#print(isincreasing)
max = 1
curr = 1

for i in range(1, len(arr)):
    if(arr[i] > arr[i-1]):
        curr += 1
    else:
        curr = 1
    if curr > max:
        max = curr
print(max)
