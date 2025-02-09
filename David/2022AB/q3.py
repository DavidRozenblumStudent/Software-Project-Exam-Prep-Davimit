import numpy as np
import pandas as pd
import sklearn as sk

def q3(y_pred, y_real):
    tp = np.sum((y_pred == 1) & (y_real == 1))
    tn = np.sum((y_pred == 0) & (y_real == 0))
    fp = np.sum((y_pred == 1) & (y_real == 0))
    fn = np.sum((y_pred == 0) & (y_real == 1))
    

    print("True Positives: ", tp, "True Negatives: ", tn, "False Positives: ", fp, "False Negatives: ", fn)



def main():
    y_pred = np.array([1, 0, 1, 0, 1, 0, 1, 0, 1, 0])
    y_real = np.array([1, 1, 1, 0, 1, 0, 0, 0, 1, 0])
    q3(y_pred, y_real)


if __name__ == "__main__":
    main()
