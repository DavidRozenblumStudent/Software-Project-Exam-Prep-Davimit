import pandas as pd

df = pd.DataFrame({'Month': ['Jan', 'Feb', 'July', 'Aug'], 'Day': [31, 28, 31, 31],
                    'Temp': [20, 25, 30, 35], 'Rain': [10, 20, 30, 40], 'Country': ['India', 'USA', 'UK', 'France']})
#answer
df['summerSTD'] = df.loc[df["Month"].isin(['June', 'July', 'August']), 'Temp'].mean()
df['winterSTD'] = df.loc[df["Month"].isin(['December', 'January', 'February']), 'Temp'].mean()
df['seasonality'] = df['summerSTD'] / df['winterSTD']
print(df.sort_values('seasonality', ascending=False).iloc[0]['Country'])
