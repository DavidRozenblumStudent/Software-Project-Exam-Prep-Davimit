import numpy as np
import pandas as pd


def q2(tree):
    root = tree.loc[tree['P'].isnull(), 'N'].values[0]
    print("Root:", root)

    leafs = tree.loc[~tree['N'].isin(tree['P']), 'N'].values
    print("Leafs:", leafs)

    inner = tree.loc[(tree['N'].isin(tree['P'])) & (tree['N'] != root), 'N'].values
    print("Inner:", inner)


def main():
    vertices = pd.Series([1,3,6,9,2,8,5])
    parent = pd.Series([2, 2, 8,8,5,5, None])

    bst = pd.DataFrame({"N": vertices, "P": parent})
    q2(bst)

if __name__ == "__main__":
    main()
