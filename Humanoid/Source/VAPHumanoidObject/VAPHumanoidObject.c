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
//
//Задачи:
//1. Создать объектную структуру данных человек, имеющую поля имя, возраст, пол, количество детей, женат или нет, указатель на партнера, на родителей и на массив с детьми, где могло бы быть, максимум, 20 детей.
//Требования:
//- каждая из сущностей, будь то строка или массив, должны быть обернуты в свой объект, который, как минимум, умел бы выполнять подсчет ссылок и имел базовые аксессоры и тесты;
//- реализовать подсчет ссылок, геттеры и сеттеры для полей;
//- реализовать метод жениться, который бы устанавливал поле женат в true и указатель на партнера, с которым был брак;
//- реализовать метод развестись, который бы устанавливал поле женат и указатель на партнера;
//- реализовать метод произвести потомство, который бы создавал ребенка, устанавливал ему родителей, а у родителей добавлял бы ребенка;
//- создать тесты на все поведение человека.

#pragma mark -
#pragma mark Private Declaration



struct VAPHuman {
    VAPHuman *_children[kMaxchildrenCount];// = (VAPHuman *)malloc(20 * sizeof(VAPHuman));
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

VAPHuman* VAPHumanCreate(char *name, uint16_t age, VAPGender gender) {

    VAPHuman *humanoid =calloc(1, sizeof(VAPHuman));
    
    assert(humanoid != NULL);

    VAPHumanSetName(humanoid, name);
    VAPHumanSetAge(humanoid, age);
    VAPHumanSetGender(humanoid, gender);

    return humanoid;
}

void VAPMarriedHumanoid(VAPHuman *man, VAPHuman *woman) {
    
    if (man != NULL && woman != NULL) {
        if ((man->_gender == Male && woman->_gender == Female)  ) {
            if (!(man->_partner || woman->_partner )) {
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

void VAPDivorceHumanoid(VAPHuman *man, VAPHuman *woman) {
    
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
        if (man->_partner == woman && woman->_partner == man) {
            VAPHuman *child = VAPHumanCreate("unname", 0, rand()%3);
            
            VAPHumanSetChild(man, child);
            VAPHumanSetChild(woman, child);
            VAPHumanSetFather(child, man);
            VAPHumanSetMother(child, woman);
            
        }
    }
}



VAPHuman* VAPHumanGetFirsrChild(VAPHuman *humanoid) {
    
    VAPHuman *firstChild;
    firstChild = humanoid;
    
    return firstChild;
}

VAPHuman* VAPHumanGetFirstChild(VAPHuman *humanoid) {
    
    
    VAPHuman **children = humanoid->_children;
    return *children;
}

VAPHuman** VAPHumanGetArrayOfChildren(VAPHuman *humanoid) {
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

void VAPHumanSetName(VAPHuman *humanoid, char* name) {
    
    if (humanoid) {
        humanoid->_name = strdup(name);
    }
    
}

char* VAPHumanGetName(VAPHuman *humanoid) {
    
    return humanoid ? humanoid->_name : "unnamed";
    
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
    
    return humanoid ? humanoid->_gender : 0;
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
        if (humanoid->_childrenCount < kMaxchildrenCount) {
            for (int i = 0; i <= humanoid->_childrenCount; i++) {
                if(i == humanoid->_childrenCount) {
                    humanoid->_children[i] = child;
                    //                uint8_t incrementValue = 0;
                    //                incrementValue = humanoid->_childrenCount;
                    //                incrementValue++;
                    //                VAPHumanSetChildrenCount(humanoid, incrementValue); как лучше через сеттер? или можно так?
                    humanoid->_childrenCount = humanoid->_childrenCount + 1;
                    break;
                }
                
            }
        } else {
            printf("Famaly tired\n");
        }
    }
}


