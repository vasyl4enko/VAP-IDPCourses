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



#endif /* defined(__VAP_IDPCources__VAPLinkedList__) */
