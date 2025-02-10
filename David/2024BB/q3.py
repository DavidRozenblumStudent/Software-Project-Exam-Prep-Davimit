import pandas as pd

df = pd.DataFrame({'Month': ['Jan', 'Feb', 'July', 'Aug'], 'Day': [31, 28, 31, 31],
                    'Temp': [20, 25, 30, 35], 'Rain': [10, 20, 30, 40], 'Country': ['India', 'USA', 'UK', 'France']})

#answer
df["SummerSTD"] = df.loc[df["Month"].isin(["July", "Aug", "June"]), "Temp"].std()
df["WinterSTD"] = df.loc[df["Month"].isin(["Jan", "Feb", "Dec"]), "Temp"].std()
df["seasonality"] = df["SummerSTD"] / df["WinterSTD"]
print(df.sort_values("seasonality", ascending=False).iloc[0]["Country"])
