//
//  LinkedListNode.h
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 02.06.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#ifndef __VAP_IDPCources__LinkedListNode__
#define __VAP_IDPCources__LinkedListNode__

#include <stdio.h>

#include "VAPObject.h"

typedef struct VAPLinkedListNode VAPLinkedListNode;

struct VAPLinkedListNode {
    VAPObject _super;
    VAPLinkedListNode *_nextNode;
    void *_object;
};

extern
VAPLinkedListNode *VAPLinkedListNodeCreateWithObject(void *object);

extern
void __VAPLinkedListNodeDeallocate(void *object);

extern
VAPLinkedListNode *VAPLinkedListNodeGetNextNode(VAPLinkedListNode *node);

extern
void VAPLinkedListNodeSetNextNode(VAPLinkedListNode *node, VAPLinkedListNode *nextNode);

extern
void *VAPLinkedListNodeGetObject(VAPLinkedListNode *node);

extern
void VAPLinkedListNodeSetObject(VAPLinkedListNode *node, void *object);

#endif /* defined(__VAP_IDPCources__LinkedListNode__) */
