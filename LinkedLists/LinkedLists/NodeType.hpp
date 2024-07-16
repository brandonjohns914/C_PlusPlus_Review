//
//  NodeType.hpp
//  LinkedLists
//
//  Created by Brandon Johns on 7/16/24.
//

#ifndef NodeType_hpp
#define NodeType_hpp

#include <stdio.h>

template<class Type>
struct nodeType {
    Type info;
    nodeType<Type> *link;
};


#endif /* NodeType_hpp */
