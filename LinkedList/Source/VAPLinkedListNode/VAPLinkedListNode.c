//
//  LinkedListNode.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 02.06.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include "VAPLinkedListNode.h"
#include "VAPMacros.h"


VAPLinkedListNode *VAPLinkedListNodeCreateWithObject(void *object) {
    VAPLinkedListNode *node = VAPObjectCreateType(VAPLinkedListNode);
    VAPLinkedListNodeSetObject(node, object);
    
    return node;
}

void __VAPLinkedListNodeDeallocate(void *object){
    VAPLinkedListNodeSetNextNode(object, NULL);
    VAPLinkedListNodeSetObject(object, NULL);
    
    __VAPObjectDeallocate(object);
}

VAPLinkedListNode *VAPLinkedListNodeGetNextNode(VAPLinkedListNode *node) {
    
    return NULL != node ? node->_nextNode : NULL;
}


void VAPLinkedListNodeSetNextNode(VAPLinkedListNode *node, VAPLinkedListNode *nextNode) {
    VAPRetainSetter(node, _nextNode, nextNode);
}


void *VAPLinkedListNodeGetObject(VAPLinkedListNode *node) {
    
    return NULL != node ? node->_object : NULL;
}

void VAPLinkedListNodeSetObject(VAPLinkedListNode *node, void *object) {
    VAPRetainSetter(node, _object, object);
}
