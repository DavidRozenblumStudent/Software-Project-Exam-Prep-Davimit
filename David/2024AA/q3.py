import numpy as np
import pandas as pd
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split


#test
db = pd.DataFrame({"Name": ["David", "John", "Mary", "Jane", "Tom", "Jerry", "Alice", "Bob", "Eve", "Marry"],
                     "Age": [23, 45, 34, 21, 32, 19, 25, 29, 27, 30],
                     "Gender": [1, 0, 1, 0, 1, 0, 1, 0, 1, 0],
                     "First Class": [True, False, True, False, True, False, True, False, True, False]})
print(db)

# answer
X = db.loc[:,['Age', 'Gender']].to_numpy()
Y = db.loc[:, 'First Class'].to_numpy()
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.2)
model = KNeighborsClassifier(n_neighbors=3)
model.fit(X_train, Y_train)
Y_pred = model.predict(X_test)
print("Accuracy:", np.mean(Y_pred == Y_test))


