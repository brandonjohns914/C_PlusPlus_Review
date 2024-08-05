//
//  BinaryTreeNode.hpp
//  LinkedLists
//
//  Created by Brandon Johns on 8/5/24.
//

#ifndef BinaryTreeNode_hpp
#define BinaryTreeNode_hpp

#include <stdio.h>
template <class Type>
struct binaryTreeNode {
    Type info;
    binaryTreeNode<Type> *llink;
    binaryTreeNode<Type> *rlink;
};

#endif /* BinaryTreeNode_hpp */
