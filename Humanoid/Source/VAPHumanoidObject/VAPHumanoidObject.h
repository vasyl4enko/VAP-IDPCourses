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

typedef struct VAPHuman VAPHuman;

//typedef struct VAPString VAPString;


void VAPHumanSetChild(VAPHuman *humanoid, VAPHuman *child);

typedef enum {
    VAPGenderOther,
    VAPGenderMale,
    VAPGenderFemale
} VAPGender;

extern
VAPHuman* VAPHumanCreate(char *name, uint16_t age, VAPGender gender);

extern
void VAPHumanDealoc(VAPHuman *humanoid);

extern
void VAPHumanoidDivorce(VAPHuman *husband, VAPHuman *wife);

extern
void VAPHumanoidMarry(VAPHuman *man, VAPHuman *woman);

extern
void VAPHumanFamalyBirthChild(VAPHuman *husband, VAPHuman *wife);

//extern
//void VAPHumanSetChild(VAPHuman *humanoid, VAPHuman *child);

extern
VAPHuman** VAPHumanGetArrayOfChildren(VAPHuman *humanoid);

extern
void VAPHumanSetPartner(VAPHuman *humanoid, VAPHuman *partner);

extern
VAPHuman* VAPHumanGetPartner(VAPHuman *humanoid);

extern
void VAPHumanSetMother(VAPHuman *humanoid, VAPHuman *mother);

extern
VAPHuman* VAPHumanGetMother(VAPHuman *humanoid);

extern
void VAPHumanSetFather(VAPHuman *humanoid, VAPHuman *father);

extern
VAPHuman* VAPHumanGetFaTher(VAPHuman *humanoid);

extern
void VAPHumanSetName(VAPHuman *humanoid, char *name);

extern
char* VAPHumanGetName(VAPHuman *humanoid);

extern
void VAPHumanSetAge(VAPHuman *humanoid, uint16_t age);

extern
uint16_t VAPHumanGetAge(VAPHuman *humanoid);

extern
void VAPHumanSetGender(VAPHuman *humanoid, VAPGender gender);

extern
VAPGender VAPHumanGetGender(VAPHuman *humanoid);

extern
uint8_t VAPHumanGetChildrenCount(VAPHuman *humanoid);

extern
void VAPHumanSetMarried(VAPHuman *humanoid);

extern
void __VAPHumanDeallocate(void *object);

#endif /* defined(__VAP_IDPCources__VAPHumanoidObject__) */
