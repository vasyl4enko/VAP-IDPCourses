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
#include <stdbool.h>

#include "VAPObject.h"
#include "VAPLinkedListNode.h"



typedef struct VAPLinkedListNode VAPLinkedListNode;

typedef struct {
    VAPObject _super;
    
    VAPLinkedListNode *_head;
    uint64_t _count;
    uint64_t _mutationsCount;
}   VAPLinkedList;

extern
void __VAPLinkedListDeallocate(void *object);

extern
bool VAPLinkedListIsEmpty(VAPLinkedList *list);

extern
void VAPLinkedListAddFirstObject(VAPLinkedList *list, void *object);

extern
void VAPLinkedListAddLastObject(VAPLinkedList *list, void *object);

extern
void VAPLinkedListRemoveAllObjects(VAPLinkedList *list);

extern
void VAPLinkedListRemoveObject(VAPLinkedList *list, void *object);

extern
void *VAPLinkedListGetFirstObject(VAPLinkedList *list);

extern
uint64_t VAPLinkedListGetCount(VAPLinkedList *list);

extern
bool VAPLinkedListIsContainsObject(VAPLinkedList *list, void *object);

extern
void VAPLinkedListSetMutationCount(VAPLinkedList *list, uint64_t mutationsCount);

extern
uint64_t VAPLinkedListGetMutationCount(VAPLinkedList *list);

#endif /* defined(__VAP_IDPCources__VAPLinkedList__) */
