import pandas as pd
import numpy as np

arr = np.array([6, 2, 5, 1 , 9, 3, 7, 4, 7])


#answer
bef = np.roll(arr, -1)
bef[-1] = bef[-2] - 1
aft = np.roll(arr, 1)
aft[0] = aft[1] - 1
df = pd.DataFrame({'-1': bef, '0': arr, '1': aft})
print(df.loc[(df['-1'] < df['0']) & (df['0'] > df['1'])]['0'].count())

