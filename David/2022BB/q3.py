import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression

def q3(A, Y):
    '''
    Input: A- adjacency matrix, Y- target values
    Output: the R^2 score of the linear regression model
    '''
    degrees = np.sum(A, axis = 1).reshape(-1, 1)
    print(np.sum(A, axis = 1))
    X_train, X_test, Y_train, Y_test = train_test_split(degrees, Y, test_size = 0.2)
    model = LinearRegression()
    model.fit(X_train, Y_train)
    return model.score(X_test, Y_test)



def main():
    A = np.array([[0, 1, 0, 0, 1, 1, 0, 1], [1, 0, 1,0 , 1 , 1, 0, 0], 
    [0, 1, 0, 1, 0, 0, 1, 0], [0, 0, 1, 0, 1, 0, 0, 1], [1, 1, 0, 1, 0, 0, 0, 0], 
    [1, 1, 0, 0, 0, 0, 1, 0], [0, 0, 1, 0, 0, 1, 0, 1], [1, 0, 0, 1, 0, 0, 1, 0]])
    Y = np.array([1, 2, 3, 4, 5, 6, 7, 8])
    print(q3(A, Y))

if __name__ == "__main__":
    main()