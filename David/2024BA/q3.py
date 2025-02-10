import pandas as pd


df = pd.DataFrame({'Name': ['Orange', 'Apple', 'Banana', 'Grapes', 'Mango'],
                    'Quantity': [56, 78, 20 ,500 ,900], 'Sold': [20, 13, 1, 5, 6], 
                    'Type': ['Fruit', 'pop', 'Fruit', 'Fruit', 'Berry']})
#answer
df['Left'] = df.loc[:, 'Quantity'] - df.loc[:, 'Sold']
print(df.sort_values(by='Left', ascending=False)['Type'].iloc[0])
