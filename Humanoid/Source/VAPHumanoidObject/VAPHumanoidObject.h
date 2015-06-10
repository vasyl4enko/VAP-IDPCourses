//
//  VAPHumanoidObject.h
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 12.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#ifndef __VAP_IDPCources__VAPHumanoidObject__
#define __VAP_IDPCources__VAPHumanoidObject__

#include <stdio.h>
#include <stdbool.h>
#include "VAPArray.h"
#include "VAPString.h"

typedef struct VAPHuman VAPHuman;

typedef enum {
    VAPGenderOther,
    VAPGenderMale,
    VAPGenderFemale
} VAPGender;

extern
VAPHuman *VAPHumanCreateWithParameters(char *name, uint16_t age, VAPGender gender);

extern
void VAPHumanAddChild(VAPHuman *humanoid, VAPHuman *child);

extern
void VAPHumanDivorce(VAPHuman *human);

extern
bool VAPHumanMarry(VAPHuman *human, VAPHuman *partner);

extern
VAPHuman *VAPHumanCreateChild(VAPHuman *human, VAPHuman *partner);

extern
void VAPHumanRemoveChildAtIndex(VAPHuman *human, uint64_t index);

extern
void VAPHumanRemoveChild(VAPHuman *human, VAPHuman *child);

extern
VAPArray *VAPHumanGetChildren(VAPHuman *humanoid);

extern
VAPHuman *VAPHumanGetPartner(VAPHuman *humanoid);

extern
void VAPHumanSetMother(VAPHuman *humanoid, VAPHuman *mother);

extern
VAPHuman *VAPHumanGetMother(VAPHuman *humanoid);

extern
void VAPHumanSetFather(VAPHuman *humanoid, VAPHuman *father);

extern
VAPHuman *VAPHumanGetFaTher(VAPHuman *humanoid);

extern
VAPString *VAPHumanGetName(VAPHuman *humanoid);

extern
void VAPHumanSetAge(VAPHuman *humanoid, uint16_t age);

extern
uint16_t VAPHumanGetAge(VAPHuman *humanoid);

extern
void VAPHumanSetGender(VAPHuman *humanoid, VAPGender gender);

extern
VAPGender VAPHumanGetGender(VAPHuman *humanoid);

extern
void VAPHumanSetMarried(VAPHuman *humanoid);

extern
uint8_t VAPHumanGetChildrenCount(VAPHuman *humanoid);

extern
bool VAPHumanIsMarried(VAPHuman *human);

extern
void __VAPHumanDeallocate(void *object);

#endif /* defined(__VAP_IDPCources__VAPHumanoidObject__) */
