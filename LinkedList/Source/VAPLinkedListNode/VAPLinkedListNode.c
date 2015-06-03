//
//  LinkedListNode.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 02.06.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include "VAPLinkedListNode.h"

extern
VAPLinkedListNode *VAPLinkedListNodeCreateWithObject(void *object) {
    VAPLinkedListNode *node = VAPObjectCreateType(VAPLinkedListNode);
    VAPLinkedListNodeSetObject(node, object);
    
    return node;
}

void __VAPLinkedListNodeDeallocate(void *object){
    
    VAPObjectRelease(object);
}

VAPLinkedListNode *VAPLinkedListNodeGetNextNode(VAPLinkedListNode *node) {
    
    return NULL != node ? node->_nextNode : NULL;
}


void VAPLinkedListNodeSetNextNode(VAPLinkedListNode *node, VAPLinkedListNode *nextNode) {
    if (NULL != node && node->_nextNode != nextNode) {

            VAPLinkedListNode *localNextNode = VAPLinkedListNodeGetNextNode(node);
            VAPObjectRetain(nextNode);
            VAPObjectRelease(localNextNode);
            node->_nextNode = nextNode;
    }
}


void *VAPLinkedListNodeGetObject(VAPLinkedListNode *node) {
    return NULL != node ? node->_object : NULL;
}

void VAPLinkedListNodeSetObject(VAPLinkedListNode *node, void *object) {
    if (NULL != node) {
        VAPObjectRetain(object);
        VAPObjectRelease(node->_object);
        node->_object = object;
    }
}
