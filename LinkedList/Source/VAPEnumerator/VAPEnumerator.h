//
//  VAPEnumerator.h
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 22.06.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#ifndef __VAP_IDPCources__VAPEnumerator__
#define __VAP_IDPCources__VAPEnumerator__

#include <stdbool.h>
#include <stdio.h>

#include "VAPObject.h"
#include "VAPLinkedListPrivate.h"

//typedef struct VAPLinkedList VAPLinkedList;
//typedef struct VAPLinkedListNode VAPLinkedListNode;

typedef struct {
    VAPObject _super;
    VAPLinkedList *_list;
    VAPLinkedListNode *_node;
    uint64_t _mutationsCount;
    bool _isValid;
} VAPEnumerator;


extern
void __VAPEnumeratorDeallocate(void *object);

extern
VAPEnumerator *VAPEnumeratorCreateWithList(VAPLinkedList *list);

extern
void *VAPEnumeratorGetNextObject(VAPEnumerator *enumerator);

extern
bool VAPEnumeratorIsValid(VAPEnumerator *enumerator);


#endif /* defined(__VAP_IDPCources__VAPEnumerator__) */
