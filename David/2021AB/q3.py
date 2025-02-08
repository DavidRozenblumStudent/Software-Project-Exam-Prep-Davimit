import numpy as np
from sklearn.neighbors import KNeighborsClassifier

def solution(X_old, X_new, y_old):
    knn = KNeighborsClassifier(n_neighbors=3)
    knn.fit(X_old, y_old) 
    y_new = knn.predict(X_new)
    print(np.sum(y_new))


def main():
    X_old = np.array([[1, 2], [3, 4], [5, 6], [7, 8], [9, 10]])
    X_new = np.array([[11, 12], [13, 14], [15, 16], [17, 18], [19, 20]])
    y_old = np.array([0, 1, 0, 1, 0])
    solution(X_old, X_new, y_old)

if __name__=="__main__":
    main()