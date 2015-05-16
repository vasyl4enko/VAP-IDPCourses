//
//  VAPHumanoidObject.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 12.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include "VAPHumanoidObject.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

static const int kMaxchildrenCount = 20;

#pragma mark -
#pragma mark Private Declaration


struct VAPHuman {
    VAPHuman *_children[kMaxchildrenCount];
    VAPHuman *_partner;
    VAPHuman *_mother;
    VAPHuman *_father;
    char *_name;
    uint16_t _age;
    VAPGender _gender;
    uint8_t _childrenCount:5; 
    bool _isMarried:1;
};

//static
//void VAPHumanSetChild(VAPHuman *humanoid, VAPHuman *child);

#pragma mark -
#pragma mark Public Implementation

VAPHuman *VAPHumanCreate(char *name, uint16_t age, VAPGender gender) {
    VAPHuman *humanoid =calloc(1, sizeof(VAPHuman));
    
    assert(humanoid != NULL);

    VAPHumanSetName(humanoid, name);
    VAPHumanSetAge(humanoid, age);
    VAPHumanSetGender(humanoid, gender);

    return humanoid;
}

//void VAPHumanDealoc(VAPHuman *humanoid) {
//    if (humanoid) {
//        if (VAPHumanGetChildrenCount(humanoid) == 0) {
//            free(humanoid);
//        } else if (VAPHumanGetChildrenCount(humanoid) != 0) {
//            VAPHuman **children = VAPHumanGetArrayOfChildren(humanoid);
//            for (int i = 0;i < VAPHumanGetChildrenCount(humanoid) ; i++, children++) {
//                free(children);
//            }
////            free(humanoid);
//        }
//    }
//    
//}

void VAPHumanoidMarry(VAPHuman *man, VAPHuman *woman) {
    if (man != NULL && woman != NULL) {
        if ((man->_gender == VAPGenderMale && woman->_gender == VAPGenderFemale)  ) {
            if (!(VAPHumanGetPartner(man) || VAPHumanGetPartner(woman))) {
                VAPHumanSetMarried(man, true);
                VAPHumanSetMarried(woman, true);
                VAPHumanSetPartner(man, woman);
                VAPHumanSetPartner(woman, man);
                printf("%s and %s MARRIED\n",woman->_name, man->_name);
            } else {
                printf("can't\n");
            }
            
        } else {
            printf("can't\n");
        }
    }
}

void VAPHumanoidDivorce(VAPHuman *man, VAPHuman *woman) {
    if (man != NULL && woman != NULL) {
        if (man->_partner == woman && woman->_partner == man) {
            VAPHumanSetMarried(man, false);
            VAPHumanSetMarried(woman, false);
            VAPHumanSetPartner(man, NULL);
            VAPHumanSetPartner(woman, NULL);
            printf("%s and %s deMARRIED\n",woman->_name, man->_name);
            
        } else {
            printf("%s and %s can't demarried\n",woman->_name, man->_name);
        }
    }
}

void VAPHumanFamalyBirthChild(VAPHuman *man, VAPHuman *woman) {
    if (man != NULL && woman != NULL) {
        if (VAPHumanGetPartner(man) == woman && VAPHumanGetPartner(woman) == man) {
            VAPHuman *child = VAPHumanCreate("unname", 0, rand()%3);
            VAPHumanSetChild(man, child);
            VAPHumanSetChild(woman, child);
            VAPHumanSetFather(child, man);
            VAPHumanSetMother(child, woman);
            
        }
    }
}

#pragma mark -
#pragma mark Accesors

VAPHuman **VAPHumanGetArrayOfChildren(VAPHuman *humanoid) {
    VAPHuman **childr = humanoid->_children;
    return childr;
}

void VAPHumanSetPartner(VAPHuman *humanoid, VAPHuman *partner) {
    if (humanoid) {
        humanoid->_partner = partner;
    }
}

void VAPHumanSetMother(VAPHuman *humanoid, VAPHuman *mother) {
    if (humanoid) {
        humanoid->_mother = mother;
    }
}

void VAPHumanSetFather(VAPHuman *humanoid, VAPHuman *father) {
    if (humanoid) {
        humanoid->_father = father;
    }
}

void VAPHumanSetName(VAPHuman *humanoid, char *name) {
    if (humanoid) {
        humanoid->_name = strdup(name);
    }
    
}

char *VAPHumanGetName(VAPHuman *humanoid) {
    
    return humanoid ? humanoid->_name : "unname";
    
}

void VAPHumanSetAge(VAPHuman *humanoid, uint16_t age) {
    if (humanoid) {
        humanoid->_age = age;
    }
}

uint16_t VAPHumanGetAge(VAPHuman *humanoid) {

    return humanoid ? humanoid->_age : 0;
}

void VAPHumanSetGender(VAPHuman *humanoid, VAPGender gender) {
    if (humanoid) {
        humanoid->_gender = gender;
    }
}

VAPGender VAPHumanGetGender(VAPHuman *humanoid) {
    
    return humanoid ? VAPHumanGetGender(humanoid) : 0;
}

void VAPHumanSetChildrenCount(VAPHuman *humanoid, uint8_t count) {
    if (humanoid){
        humanoid->_childrenCount = count;
    }
}

uint8_t VAPHumanGetChildrenCount(VAPHuman *humanoid) {
    
    return humanoid ? humanoid->_childrenCount : 0;

}

void VAPHumanSetMarried(VAPHuman *humanoid, bool isMarried) {
    if (humanoid){
        humanoid->_isMarried = isMarried;
    }
}

#pragma mark -
#pragma mark Private Implementation

void VAPHumanSetChild(VAPHuman *humanoid, VAPHuman *child) {
    if (humanoid != NULL && child != NULL) {
        if ( VAPHumanGetChildrenCount(humanoid) < kMaxchildrenCount) {
            for (int i = 0; i <= humanoid->_childrenCount; i++) {
                if(i == humanoid->_childrenCount) {
                    humanoid->_children[i] = child;
                    uint8_t incrementValue = 0;
                    incrementValue = humanoid->_childrenCount;
                    incrementValue++;
                    VAPHumanSetChildrenCount(humanoid, incrementValue);
                    break;
                }
            }
        } else {
            printf("Famaly tired\n");
        }
    }
}


