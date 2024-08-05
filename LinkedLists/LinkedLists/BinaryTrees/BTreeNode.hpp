//
//  BTreeNode.hpp
//  LinkedLists
//
//  Created by Brandon Johns on 8/5/24.
//

#ifndef BTreeNode_hpp
#define BTreeNode_hpp

#include <stdio.h>
template <class Type, int bTreeOrder>
struct bTreeNode{
    int recCount;
    Type list[bTreeOrder - 1];
    bTreeNode *children[bTreeOrder];
};

#endif /* BTreeNode_hpp */
