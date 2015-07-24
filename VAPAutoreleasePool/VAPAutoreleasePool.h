//
//  VAPAutoreleasePool.h
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 04.07.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#ifndef __VAP_IDPCources__VAPAutoreleasePool__
#define __VAP_IDPCources__VAPAutoreleasePool__

#include <stdio.h>

typedef struct VAPAutoreleasePool VAPAutoreleasePool;


extern
void __VAPAutoreleasePoolDeallocate(void *object);

extern
VAPAutoreleasePool *VAPAutoreleasePoolCreate();

extern
void VAPAutoreleasePoolAddObject(VAPAutoreleasePool *pool, void *object);

extern
void VAPAutoreleasePoolDrain(VAPAutoreleasePool *pool);


#endif /* defined(__VAP_IDPCources__VAPAutoreleasePool__) */
