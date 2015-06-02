//
//  LinkedListNode.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 02.06.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include "LinkedListNode.h"

extern
VAPLinkedListNode *VAPLinkedListNodeCreateWithObject(void *object) {
    VAPLinkedListNode *node = VAPObjectCreateType(VAPLinkedListNode);
    
    return node;
}

void __VAPLinkedListNodeDeallocate(void *object){
    
    VAPObjectRelease(object);
}

VAPLinkedListNode *VAPLinkedListNodeGetNextNode(VAPLinkedListNode *node) {
    
    return NULL != node ? node->_nextNode : NULL;
}

extern
void VAPLinkedListNodeSetNextNode(VAPLinkedListNode *node, VAPLinkedListNode *nextNode) {
    if (NULL != node) {
        if (NULL == VAPLinkedListNodeGetNextNode(node)) {
            node->_nextNode = nextNode;
            VAPObjectRetain(nextNode);
        }
    }
}


void *VAPLinkedListNodeGetObject(VAPLinkedListNode *node) {
    return NULL != node ? node->_object : NULL;
}

extern
void VAPLinkedListNodeSetObject(VAPLinkedListNode *node, void *object);
