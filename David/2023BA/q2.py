import pandas as pd
import numpy as np
import random

#### 2a ####
x = np.array([True, True, False, False, True, False, True, False, False, True])
#my code
y = np.array(x[1:].tolist() + [False])
db = pd.DataFrame({'x': x, 'y': y})
print(db.loc[(db['x'] == False) & (db['y'] == True)]['x'].count())

#### 2b ####
ages = np.array([random.randint(18, 65) for i in range(5)])
print(ages) #debug
ages.sort()
print(ages) #debug
print(min([ages[i+1] - ages[i] for i in range(len(ages)-1)]))

