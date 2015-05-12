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
    VAPHuman *_children;// = (VAPHuman *)malloc(20 * sizeof(VAPHuman));
    VAPHuman *_partner;
    VAPHuman *_mother;
    VAPHuman *_father;
    char *_name;
    uint16_t _age;
    VAPGender _gender;
    uint8_t _childrenCount:5; 
    bool _isMarried:1;
};



#pragma mark -
#pragma mark Public Implementation

VAPHuman* VAPHumanCreate(char *name, uint16_t age, VAPGender gender, uint8_t childrenCount) {

    VAPHuman *humanoid =malloc(sizeof(VAPHuman));
    humanoid->_children = malloc(20 * sizeof(VAPHuman));
    VAPHumanSetName(humanoid, name);
    VAPHumanSetAge(humanoid, age);
    VAPHumanSetGender(humanoid, gender);
    VAPHumanSetChildrenCount(humanoid, childrenCount);

    
    return humanoid;
}

void VAPMarriedHumanoid(VAPHuman *man, VAPHuman *woman) {
    
    if (man->_gender == Male && woman->_gender == Female) {
        VAPHumanSetMarried(man, true);
        VAPHumanSetMarried(woman, true);
        VAPHumanSetPartner(man, woman);
        VAPHumanSetPartner(woman, man);
        printf("MARRIED\n");
    }
}

void VAPDivorceHumanoid(VAPHuman *husband, VAPHuman *wife) {
    
    if (husband->_partner == wife && wife->_partner == husband) {
        VAPHumanSetMarried(husband, false);
        VAPHumanSetMarried(wife, false);
        VAPHumanSetPartner(husband, NULL);
        VAPHumanSetPartner(wife, NULL);
        printf("deMARRIED\n");

    }
    
}

void VAPHumanFamalyBirthChild(VAPHuman *husband, VAPHuman *wife) {
    
    if (husband->_partner == wife && wife->_partner == husband) {
        VAPHuman *child = VAPHumanCreate("unname", 0, rand()%2, 0);
        VAPHumanSetChild(husband, child);
        VAPHumanSetChild(wife, child);
        VAPHumanSetFather(child, husband);
        VAPHumanSetMother(child, wife);
        
    }
}

void VAPHumanSetChild(VAPHuman *humanoid, VAPHuman *child) {
    
    if (humanoid->_childrenCount < kMaxchildrenCount) {
        for (int i = 0; i <= humanoid->_childrenCount; i++,humanoid->_children++) {
            if(i == humanoid->_childrenCount) {
                VAPHumanSetChild(humanoid, child);
            }
        }
    }
}

VAPHuman* VAPHumanGetChild(VAPHuman *humanoid) {
    
    VAPHuman *firstChild;
    firstChild = humanoid;
    
    return firstChild;
}

void VAPHumanSetPartner(VAPHuman *humanoid, VAPHuman *partner) {
    humanoid->_partner = partner;
}

void VAPHumanSetMother(VAPHuman *humanoid, VAPHuman *mother) {
    humanoid->_mother = mother;
}

void VAPHumanSetFather(VAPHuman *humanoid, VAPHuman *father) {
    humanoid->_father = father;
}

void VAPHumanSetName(VAPHuman *humanoid, char* name) {
    humanoid->_name = strdup(name);
}

char* VAPHumanGetName(VAPHuman *humanoid){
    return humanoid->_name;
}

void VAPHumanSetAge(VAPHuman *humanoid, uint16_t age) {
    humanoid->_age = age;
}

uint16_t VAPHumanGetAge(VAPHuman *humanoid) {
    return humanoid->_age;
}

void VAPHumanSetGender(VAPHuman *humanoid, VAPGender gender) {
    humanoid->_gender = gender;
}

VAPGender VAPHumanGetGender(VAPHuman *humanoid) {
    return humanoid->_gender;
}

void VAPHumanSetChildrenCount(VAPHuman *humanoid, uint8_t count) {
    humanoid->_childrenCount = count;
}

uint8_t VAPHumanGetChildrenCount(VAPHuman *humanoid) {
    return humanoid->_childrenCount;
}

void VAPHumanSetMarried(VAPHuman *humanoid, bool isMarried) {
    humanoid->_isMarried = isMarried;
}

#pragma mark -
#pragma mark Private Implementation

