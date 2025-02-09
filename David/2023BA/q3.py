import numpy as np
import pandas as pd


users = pd.DataFrame({'id': np.array([1, 2, 3, 4, 5]), 'name': np.array(['Alice', 'Bob', 'Charlie', 'David', 'Eve']),
                        'neiborhood_id:': np.array([1, 2, 1, 2, 1]), 'created_at': np.array(['2023-01-01', '2023-01-02', '2023-01-03', '2023-01-04', '2023-01-05'])}) 
neiborhoods = pd.DataFrame({'id': np.array([1, 2, 3]), 'neiborhood name': np.array(['Uptown', 'Downtown', 'Midtown'])})

#answer
print(neiborhoods.loc[(~neiborhoods['id'].isin(users['neiborhood_id:']))])
