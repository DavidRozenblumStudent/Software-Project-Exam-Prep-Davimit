import numpy as np
import random

#test
k = random.randint(1, 10)
arr1 = np.array([random.randint(1, 30) for i in range(5)])
arr2 = np.array([random.randint(1, 30) for i in range(5)])

print("k:", k, "\narr1:", arr1, "\narr2:", arr2)

# answer
print(sorted(arr1.tolist()+arr2.tolist())[k-1])

