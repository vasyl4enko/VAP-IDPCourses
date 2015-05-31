//
//  VAPString.h
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 18.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#ifndef __VAP_IDPCources__VAPString__
#define __VAP_IDPCources__VAPString__

#include <stdio.h>
#include "VAPObject.h"


typedef struct {
    VAPObject _super;
    char *_string;
    uint64_t _length;
} VAPString;

extern
void *VAPStringCreateWithString(char *string);

extern
char *VAPStringGetString(void *string);

extern
void VAPStringSetString(void *string, char *newString);

extern
uint64_t VAPStringGetLength(VAPString *object);

extern
void __VAPStringDeallocate(void *object);

#endif /* defined(__VAP_IDPCources__VAPString__) */
