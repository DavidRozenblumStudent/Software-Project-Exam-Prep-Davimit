import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression


x = pd.DataFrame({'Diners': [56, 78, 20 ,5 ,9], 'ToD': [684, 456, 566, 484, 484],
                    'Bill': [100, 200, 300, 400, 500], 'Tip': [25, 15, 10, 5, 2]})
#answer
x['TipPracent'] = (x.loc[:, 'Tip'] / x.loc[:, 'Bill']) * 100
X_train, X_test, Y_train, Y_test = train_test_split(x.loc[:, ['Diners', 'ToD']], x.loc[:, 'TipPracent'], train_size=0.8)
model = LinearRegression()
model.fit(X_train, Y_train)
Y_pred = model.predict(X_test)
print(Y_pred)
print(Y_test.to_numpy())
print(X_test)
