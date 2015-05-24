//
//  VAPHumanoidObjectTests.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 12.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include "VAPHumanoidObjectTests.h"
#include "VAPHumanoidObject.h"
#include "VAPArray.h"

#pragma mark -
#pragma mark Private Declaration

static
void VAPHumanoidFamillyTest(void);

#pragma mark -
#pragma mark Public impl


void VAPHumanoidObjectTest() {
    VAPHumanoidFamillyTest();
}

#pragma mark -
#pragma mark Private Implement

void VAPHumanoidFamillyTest(void) {
    VAPHuman *humanMan = VAPHumanCreateWithParameters("Lermontov", 30, VAPGenderMale);
    printf("Name - %s\n", VAPHumanGetName(humanMan));
    printf("Reference count - %llu\n", VAPGetReferenceCount(humanMan));
    printf("\n");
    VAPHuman *humanFemale = VAPHumanCreateWithParameters("Ahmatova", 25, VAPGenderFemale);
    printf("Name - %s\n", VAPHumanGetName(humanFemale));
    printf("Reference count - %llu\n", VAPGetReferenceCount(humanFemale));
    printf("\n");
    VAPHumanMarry(humanFemale, humanMan);
    printf("Name - %s\n", VAPHumanGetName(humanFemale));
    printf("Reference count - %llu\n", VAPGetReferenceCount(humanFemale));
    printf("\n");
    printf("Name - %s\n", VAPHumanGetName(humanMan));
    printf("Reference count - %llu\n", VAPGetReferenceCount(humanMan));
    printf("\n");
    VAPHumanDivorce(humanFemale);
    printf("Name - %s\n", VAPHumanGetName(humanFemale));
    printf("Reference count - %llu\n", VAPGetReferenceCount(humanFemale));
    printf("\n");
    printf("Name - %s\n", VAPHumanGetName(humanMan));
    printf("Reference count - %llu\n", VAPGetReferenceCount(humanMan));
    printf("\n");
}


