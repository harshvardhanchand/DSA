#include <stdio.h>
#include <stdlib.h>
// We can generate tree from traversal
//  We use combination of inorder and preorder traversal or postorder traversal and inorder traversal
//  inorder will help us decide left and right elements to the root
// store all elements from inorder traversal in a list
// Preorder s first element is root and then we will use list to find left and right elements
// keep doing same thing recursively