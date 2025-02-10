import numpy as np
import pandas as pd



df_2 = pd.DataFrame({'id': [1, 2, 3, 4, 5], 'height': [1.5, 1.6, 1.7, 1.8, 1.9],
                    'body_mass': [125, 130, 135, 140, 145], 'body_length': [3.2, 2.8, 2.2, 4.4, 4.0]})
df_1 = pd.DataFrame({'id': [1, 2, 3, 4, 5], 'country': ['USA', 'Ethiopia', 'Namibia', 'Kenya', 'Nigeria'],
                    'species': ['African', 'African', 'African', 'American', 'Australian']})
#answer
merged_df = pd.merge(df_1, df_2, on='id')
print(merged_df.groupby('species')['body_mass'].mean())

