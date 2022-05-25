#include <stdio.h>
#include <stdlib.h>
// Tree is a data structure that consists of a node and a link to other nodes.
// The nodes are arranged in a tree structure.
// The root node is the topmost node in the tree.
// The leaves are the nodes at the bottom of the tree.
// The internal nodes are the nodes that have one or more children.
// Parent node is the node that points to the child node.
// child node is the node that is pointed by the parent node.
// Degree of a node is the number of child nodes it has.minimum 3 of a tree
// The external nodes are the nodes that are not connected to any other node.
// Height of a tree is the number of edges on the longest path between two nodes.
// A tree of degree 2(max) is called a binary tree.
// Catalan number is a number related to Catalan's theorem. It is defined as follows: C(n) = (2n)! / (n+1)!n! gives no .of ways to arrange n unlabelled nodes in a binary tree.
// height starts from zero
// no.of tress with n unlabelled nodes with max height is 2^(n-1)
// There can be a recrusive way to get catalan number but it is not efficient.
// T(n) = summation of T(i-1) * T(n-i) (i=1 to i=n)
// Labelled nodes are the nodes that have a label. no .of ways to arrange labelled nodes in a binary tree is given by the formula: C(n) = (2n)! / (n+1)!n! n!
// Suppose height h is given min no.of nodes = h+1 , max = 2^(h+1)-1
// Conversely max height =n-1 and min height is log2(n+1) -1
// E = I(n)(n-1) + 1 (where E is no .of external nodes I(n) is no .of internal nodes of highest degree))
// A strict binary tree is a tree in which all internal nodes have exactly two children.
// min no.of nodes = 2h+1 , max = 2^(h+1)-1 in a strictly binary tree
// conversely max height =(n-1)/2 and min height is log2(n+1) -1
// All these formula can be applied to n- trees
// for example
// min no.of nodes = 3h+1 , max = ()3^(h+1)-1)/(3-1) in a strictly 3-arr tree
// Represntation of Binary tree
// we need to represent a binary tree in a form of an array.
// The array is a sequence of nodes.
// we need to store elements and store the relatonship between said elements
// Complete binary tree: A binary tree is complete if every level, except possibly the last, is completely filled, and all nodes are as far left as possible.(no gaps in array)
// Full binary tree: A binary tree is full if every node has either 0 or 2 children.(FULL ->Complete binary tree)(Complete->Full)
// Binary Tree Traversal:Preorder: Root, Left, Right (DFS) Inorder: Left, Root, Right (DFS) Postorder: Left, Right, Root (DFS) Levelorder: Level by level (BFS)