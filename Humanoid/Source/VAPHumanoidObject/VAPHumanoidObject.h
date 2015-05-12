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

//struct VAPHuman {
//    VAPHuman *_children;// = (VAPHuman *)malloc(20 * sizeof(VAPHuman));
//    VAPHuman *_partner;
//    VAPHuman *_mother;
//    VAPHuman *_father;
//    char *_name;
//    uint16_t _age; //
//    VAPGender _gender;
//    uint8_t _childrenCount:5; // посмотрим что из этого выйдет.
//    bool _married:1;
//};

typedef struct VAPHuman VAPHuman;
typedef enum VAPGender VAPGender;

enum VAPGender {
    Male,
    Female
};

VAPHuman* VAPHumanCreate(char *name, uint16_t age, VAPGender gender, uint8_t childrenCount);

void VAPDivorceHumanoid(VAPHuman *husband, VAPHuman *wife);
void VAPMarriedHumanoid(VAPHuman *man, VAPHuman *woman);

void VAPHumanSetChild(VAPHuman *humanoid, VAPHuman *child);
VAPHuman* VAPHumanGetChild(VAPHuman *humanoid);

void VAPHumanSetPartner(VAPHuman *humanoid, VAPHuman *partner);
VAPHuman* VAPHumanGetPartner(VAPHuman *humanoid);

void VAPHumanSetMother(VAPHuman *humanoid, VAPHuman *mother);
VAPHuman* VAPHumanGetMother(VAPHuman *humanoid);

void VAPHumanSetFather(VAPHuman *humanoid, VAPHuman *father);
VAPHuman* VAPHumanGetFaTher(VAPHuman *humanoid);

void VAPHumanSetName(VAPHuman *humanoid, char* name);
char* VAPHumanGetName(VAPHuman *humanoid);

void VAPHumanSetAge(VAPHuman *humanoid, uint16_t age);
uint16_t VAPHumanGetAge(VAPHuman *humanoid);

void VAPHumanSetGender(VAPHuman *humanoid, VAPGender gender);
VAPGender VAPHumanGetGender(VAPHuman *humanoid);

void VAPHumanSetChildrenCount(VAPHuman *humanoid, uint8_t count);
uint8_t VAPHumanGetChildrenCount(VAPHuman *humanoid);

void VAPHumanSetMarried(VAPHuman *humanoid, bool isMarried);
bool VAPHumanGetMarried(VAPHuman *humanoid);

#endif /* defined(__VAP_IDPCources__VAPHumanoidObject__) */
