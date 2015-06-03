//
//  VAPLinkedList.h
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 03.06.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#ifndef __VAP_IDPCources__VAPLinkedList__
#define __VAP_IDPCources__VAPLinkedList__

#include <stdio.h>

#include "VAPObject.h"
#include "VAPLinkedListNode.h"


typedef struct VAPLinkedListNode VAPLinkedListNode;

 typedef struct  {
    VAPObject _super;
    
    VAPLinkedListNode *_head;
    uint64_t _count;
}   VAPLinkedList;

extern
void __VAPLinkedListDeallocate(void *object);

extern
void VAPLinkedListIsEmpty(VAPLinkedList *list);

extern
void VAPLinkedListAddNode(VAPLinkedList *list, VAPLinkedListNode *node);

extern
void VAPLinkedListAddObject(VAPLinkedList *list, void *object);

extern
void VAPLinkedListRemoveAllObjects(VAPLinkedList *list);

extern
void VAPLinkedListRemoveObjectAtIndex(VAPLinkedList *list, uint64_t index);

extern
VAPLinkedListNode *VAPLinkedListGetFirstNode(VAPLinkedList *node);

#endif /* defined(__VAP_IDPCources__VAPLinkedList__) */
