//Name: Hasan Syed
//Date: 01/18/2019
// BSTNode.hpp
// CSE 100 Project 1
//
// Last modified by Hasan Syed on 01/18/2019
//

#ifndef BSTNODE_HPP
#define BSTNODE_HPP

#include <iostream>
#include <iomanip>

using namespace std;

template <typename Data>
class BSTNode {
public:
    BSTNode<Data> *left;
    BSTNode<Data> *right;
    BSTNode<Data> *parent;
    Data const data;

    /** 
     * Constructor that initializes a BSTNode with the given data.
     */
    BSTNode(const Data &d) : data(d) {
        left = right = parent = nullptr;
    }

    /**
     * Find the successor this node.
     *
     * The successor of a node is the node in the BST whose data
     * value is the next in the ascending order.
     *
     * Returns:
     *     the BSTNode that is the successor of this BSTNode,
     *     or 0 if there is none (this is the last node in the BST).
     */
    // TODO
    BSTNode<Data> *successor() {
		if (right == NULL && parent == NULL) {
			return 0;
		}
		else if (right != NULL && right->left == NULL) {
			return right;
		}
		else if (right != NULL && right->left != NULL) {
			return findLeftMostNode(right);
		}
		else if (parent != NULL && parent->left == this && right == NULL) {
			return parent;
		}
		else if (parent != NULL && parent->right == this && right == NULL) {
			return findAncestor(parent);
		}
		else if(parent == NULL && right == NULL){
			return 0;
		}
		else {
			return 0;
		}
    }

    private:
    
     /**
     * find the leftmost node in the right subtree
     *
     * The successor of a node that has a right subtree will
     * be the left most node in that right subtree.
     *
     * Returns:
     *     the BSTNode that is the successor of this BSTNode,
     *     or 0 if there is none..
     */
    BSTNode<Data>* findLeftMostNode(BSTNode<Data>* n) {
		if (n == NULL) {
			return 0;
		}
		while (n->left != NULL) {
			n = n->left;
		}
		return n;
    }

    /**
     * Find the successor to a node without a right subtree
     *
     * The successor of a node that does not have a right subtree means 
     * that the successor will be one of the ancestors of the node so we 
     * recurse upwards until we find the parent node that has a left node
     * equal to our current node.
     *
     * Returns:
     *     the BSTNode that is the successor of this BSTNode,
     *     or 0 if there is none..
     */
	BSTNode<Data>* findAncestor(BSTNode<Data>* n) {
		if (n->parent == NULL) {
			return 0;
		}
		else {
			if (n->parent->left == n) {
				return n->parent;
			}
			else {
				return findAncestor(n->parent);
			}
		}
	}
};

/** 
 * Overload operator<< to print a BSTNode's fields to an ostream. 
 */
template <typename Data>
ostream &operator<<(ostream &stm, const BSTNode<Data> &n) {
    stm << '[';
    stm << setw(10) << &n;                  // address of the BSTNode
    stm << "; p:" << setw(10) << n.parent;  // address of its parent
    stm << "; l:" << setw(10) << n.left;    // address of its left child
    stm << "; r:" << setw(10) << n.right;   // address of its right child
    stm << "; d:" << n.data;                // its data field
    stm << ']';
    return stm;
}

#endif  // BSTNODE_HPP
