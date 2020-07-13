//Name: Hasan Syed
//Date: 01/18/2019
// BST.hpp
// CSE 100 Project 1
//
// Last modified by Hasan Syed on 01/18/2019
//

#ifndef BST_HPP
#define BST_HPP

#include <iostream>

#include "BSTIterator.hpp"
#include "BSTNode.hpp"

using namespace std;

template <typename Data>
class BST {
protected:
	// Pointer to the root of this BST, or 0 if the BST is empty.
	BSTNode<Data> *root;

	// Number of elements stored in this BST.
	unsigned int isize;

	// Height of this BST.
	unsigned int iheight;

public:
	// Define iterator as an aliased typename for BSTIterator<Data>.
	typedef BSTIterator<Data> iterator;

	/**
	 * Default constructor. Initializes an empty BST.
	 */
	BST() : root(0), isize(0), iheight(0) {}

	/**
	 * Default destructor. Frees all memory allocated by this BST.
	 */
	 // TODO
	virtual ~BST() {
	    deleteAll(root);
		isize = 0;
		iheight = 0;
	}

	/**
	 * Inserts the given item into this BST.
	 *
	 * This function should use only the '<' operator when comparing
	 * Data items. (do not use ==, >, <=, >=). For the reasoning
	 * behind this, see the assignment writeup.
	 *
	 * Parameters:
	 *     item Data item to insert into this BST
	 *
	 * Returns:
	 *     true if the item was inserted as a consequence of calling
	 *     this function, false otherwise (e.g. item is a duplicate).
	 */
	 // TODO
	virtual bool insert(const Data &item) {

		if (root == NULL) {
			root = new BSTNode<Data>(item);
			isize++;
			iheight++;
			return true;
		}
		BSTNode<Data>* current = root;

		while (current != NULL) {
			if (item < current->data) {
				if (current->left == NULL) {
					current->left = new BSTNode<Data>(item);
					current->left->parent = current;
					isize++;
					iheight = findTreeHeight(root);
					return true;
				}
				else {
					current = current->left;
				}
			}
			else if (current->data < item)
			{
				if (current->right == NULL) {
					current->right = new BSTNode<Data>(item);
					current->right->parent = current;
					isize++;
					iheight = findTreeHeight(root);
					return true;
				}
				else {
					current = current->right;
				}
			}
			else {
				return false;
			}
		}
		return false;
	}

	/**
	 * Searches for the given item in this BST.
	 *
	 * This function should use only the '<' operator when comparing
	 * Data items. (should not use ==, >, <=, >=). For the reasoning
	 * behind this, see the assignment writeup.
	 *
	 * Parameters:
	 *     item Data item to search for in this BST.
	 *
	 * Returns:
	 *     An iterator pointing to the item if found, or pointing
	 *     past the last node in this BST if item is not found.
	 */
	 // TODO
	virtual iterator find(const Data &item) const {
		if (root == NULL) {
			return this->end();
		}

		BSTNode<Data>* current = root;

		while (current != NULL) {
			if (current->data < item) {
				current = current->right;
			}
			else if (item < current->data) {
				current = current->left;
			}
			else {
				return typename BST<Data>::iterator(current);
			}
		}
		return typename BST<Data>::iterator(0);
	}

	/**
	 * Returns the number of items currently in the BST.
	 */
	 // TODO
	unsigned int size() const {
		return isize;
	}

	/**
	 * Returns the height of this BST.
	 */
	 // TODO
	unsigned int height() const {
		return iheight;
	}

	/**
	 * Returns true if this BST is empty, false otherwise.
	 */
	 // TODO
	bool empty() const {
		if (isize == 0) return true;
		else return false;
	}

	/**
	 * Returns an iterator pointing to the first item in the BST (not the root).
	 */
	 // TODO
	iterator begin() const {
		BSTNode<Data>* current = root;
		if (current != NULL) {
			while (current->left != NULL) {
				current = current->left;
			}
		}
		return typename BST<Data>::iterator(current);
	}

	/**
	 * Returns an iterator pointing past the last item in the BST.
	 */
	iterator end() const {
		return typename BST<Data>::iterator(0);
	}

	/**
	 * Prints the elements in this BST in ascending order.
	 */
	void inorder() const {
		inorder(root);
	}

private:
	/*
	 * Find the first node in the given subtree with root curr.
	 */
	static BSTNode<Data>* first(BSTNode<Data> *curr) {
		if (!curr) return 0;
		while (curr->left) {
			curr = curr->left;
		}
		return curr;
	}

	/*
	 * Do an inorder traversal, printing the data in ascending order.
	 *
	 * You can achieve an inorder traversal recursively by following
	 * the order below.
	 *
	 *     recurse left - print node data - recurse right
	 */
	 // TODO
	static void inorder(BSTNode<Data> *n) {
		if (n == NULL) return;
		inorder(n->left);
		std::cout << *n << "" << std::endl;
		inorder(n->right);
	}

	/*
	 * Do a postorder traversal, deleting nodes.
	 *
	 * You can achieve a postorder traversal recursively by following
	 * the order below.
	 *
	 *     recurse left - recurse right - delete node
	 */
	 // TODO
	static void deleteAll(BSTNode<Data> *n) {
		if (n == NULL) return;
		deleteAll(n->left);
		deleteAll(n->right);
		delete n;
	}

	/*
	 * Helper function to traverse tree to find height of bst
	 *
	 * Achieved by recursive calls to function looking at 
	 * the right and left subtrees, adding one each time 
	 * we move to the right or left. Then we return whichever 
	 * depth of subtree was larger.
	 *
	 * returns height of the tree
	 */
	static int findTreeHeight(BSTNode<Data>* n) {
		if (n == NULL) return 0;
		else {
			int leftHeight = findTreeHeight(n->left);
			int rightHeight = findTreeHeight(n->right);

			if (leftHeight > rightHeight) {
				return(leftHeight + 1);
			}
			else {
				return(rightHeight + 1);
			}
		}
	}

};

#endif  // BST_HPP
