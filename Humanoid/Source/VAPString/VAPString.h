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
    char *_name;
    
} VAPString;


//typedef void (*VAPStringDeallocCallBack)(void *);

extern
void *VAPStringCreate(char *name);

extern
char *VAPStringGetName(VAPString *string);

extern
void VAPStringSetName(VAPString *string, char *newName);

extern
void __VAPStringDeallocate(void *object);

#endif /* defined(__VAP_IDPCources__VAPString__) */
