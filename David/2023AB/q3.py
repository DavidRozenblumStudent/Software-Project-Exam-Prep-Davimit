import numpy as np
from sklearn.linear_model import LogisticRegression

def q3(images, y):
    model = LogisticRegression()
    X_train, X_test, Y_train, Y_test = train_test_split(images, y, test_size = 0.2)
    model.fit(X_train, Y_train)
    return model.score(X_test, Y_test)

def main():



if __name__ == "__main__":
    main()
