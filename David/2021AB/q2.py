import numpy as np
import pandas as pd

def find_root(bst):
    # Find the root of the tree
    root = bst[bst["P"].isnull()]["N"].values[0]
    return root

def find_leaves(bst):
    # Find the leaves of the tree
    leaves = bst[~bst["N"].isin(bst["P"])]["N"].values
    return leaves

def find_internal_nodes(bst):
    # Find the internal nodes of the tree
    root = find_root(bst)
    internal_nodes = bst[bst["N"].isin(bst["P"]) & (bst["N"] != root)]["N"].values
    return internal_nodes

def main():
    vertices = pd.Series([1,3,6,9,2,8,5])
    parent = pd.Series([2, 2, 8,8,5,5, None])

    bst = pd.DataFrame({"N": vertices, "P": parent})
    print(bst) 
    root = find_root(bst)
    print("Root of the tree is: ", root)
    print("Leaves of the tree are: ", find_leaves(bst))
    print("Internal nodes of the tree are: ", find_internal_nodes(bst))

     


if __name__ == "__main__":
    main() 