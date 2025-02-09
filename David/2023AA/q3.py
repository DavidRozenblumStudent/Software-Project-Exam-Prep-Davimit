import numpy as np 
from sklearn.neighbors import KNeighborsClassifier


def q3(X_old, Y,  X_new):
    model = KNeighborsClassifier(n_neighbors=3)
    model.fit(X_old, Y)
    Y_new = model.predict(X_new)
    return Y_new


def main():
    X_old = np.array([[1, 2], [3, 4], [5, 6], [7, 8]])
    Y = np.array([0, 1, 0, 1])
    X_new = np.array([[1, 2], [3, 4], [5, 6], [7, 8]])
    print(q3(X_old, Y, X_new))

if __name__ == "__main__":
    main()
