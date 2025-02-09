import numpy as np
import pandas as pd


def q2(txn):
    sums = txn.groupby("CustumerID")["TransactionAmount"].sum()
    print(sums)
    txn["Percantege"] = txn["TransactionAmount"] / txn["CustumerID"].map(sums)
    print(txn)

def main():
    txn = pd.DataFrame({
        "CustumerID": [1, 2, 1, 2, 1, 2],
        "TransactionAmount": [100, 200, 300, 400, 500, 600]
    })
    q2(txn)


if __name__ == "__main__":
    main()
