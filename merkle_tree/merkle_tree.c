#include "merkle_tree.h"

/**
 *
 */
MerkleTree createMerkleTree() {

    MerkleTreeNode root;
    root.left = NULL;
    root.right = NULL;
    root.hash = "";

    MerkleTree tree;
    tree.leavesAmount = 0;
    tree.merkleNode = root;

    return tree;
}