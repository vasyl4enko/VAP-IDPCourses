//
//  VAPObject.h
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 17.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#ifndef __VAP_IDPCources__VAPObject__
#define __VAP_IDPCources__VAPObject__

#include <stdio.h>
#include <stdlib.h>

typedef void (*VAPObjectDeallocCallBack)(void *);

typedef struct {
    uint64_t _referenceCount;
    VAPObjectDeallocCallBack _deallocCallBack;
} VAPObject;

extern
void *__VAPObjectCreate(size_t objectSize, VAPObjectDeallocCallBack deallocCallBack);

#define VAPObjectCreateType(type)\
__VAPObjectCreate(sizeof(type), (VAPObjectDeallocCallBack)__##type##Deallocate)

extern
void *VAPObjectRetain(void *object);

extern
void VAPObjectRelease(void *object);

extern
uint64_t IDPGetReferenceCount(void *object);

extern
void __VAPObjectDeallocate(void *object);

#endif /* defined(__VAP_IDPCources__VAPObject__) */
