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

void VAPHumanSetChild(VAPHuman *humanoid, VAPHuman *child) ;

enum VAPGender {
    Other,
    Male,
    Female
};
extern
VAPHuman* VAPHumanCreate(char *name, uint16_t age, VAPGender gender);

extern
void VAPHumanDealoc(VAPHuman *humanoid);

extern
void VAPDivorceHumanoid(VAPHuman *husband, VAPHuman *wife);

extern
void VAPMarriedHumanoid(VAPHuman *man, VAPHuman *woman);

extern
void VAPHumanFamalyBirthChild(VAPHuman *husband, VAPHuman *wife);

//extern
//void VAPHumanSetChild(VAPHuman *humanoid, VAPHuman *child);

extern
VAPHuman* VAPHumanGetFirstChild(VAPHuman *humanoid);

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
void VAPHumanSetName(VAPHuman *humanoid, char* name);

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
void VAPHumanSetMarried(VAPHuman *humanoid, bool isMarried);

extern
bool VAPHumanGetMarried(VAPHuman *humanoid);

#endif /* defined(__VAP_IDPCources__VAPHumanoidObject__) */
