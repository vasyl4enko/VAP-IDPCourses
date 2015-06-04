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
#include <assert.h>

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
    
    //create male person
    VAPHuman *chehov = VAPHumanCreateWithParameters("Chehov", 34, VAPGenderMale);
    
        //reference count should be 1
        assert(1 == VAPGetReferenceCount(chehov));
    
    //create female person
    VAPHuman *ahmatova = VAPHumanCreateWithParameters("Ahmatova", 28, VAPGenderFemale);
    
        //reference count should be 1
        assert(1 == VAPGetReferenceCount(ahmatova));
    
    //marry chehov & ahmatova
    VAPHumanMarry(chehov, ahmatova);
    
        //reference count of female obj should be 2
        assert(2 == VAPGetReferenceCount(ahmatova));
    
        //reference count of male obj should be 1
        assert(1 == VAPGetReferenceCount(chehov));
    
    //birth child
    VAPHuman *firstChild = VAPHumanCreateChild(ahmatova, chehov);
    
    //create next child
    VAPHuman *secondChild = VAPHumanCreateChild(ahmatova, chehov);
    
    //get array with children
    VAPArray *children = VAPHumanGetChildren(chehov);
    
        //cycle which check reference count children
        for (uint64_t index = 0; index < VAPHumanGetChildrenCount(chehov); index++) {
            assert(3 == VAPGetReferenceCount(VAPArrayGetObjectAtIndex(children, index)))  ;
        }
    
    //create second female person
    VAPHuman *doncova = VAPHumanCreateWithParameters("Doncova", 40, VAPGenderFemale);
    
    
    //reference count should be 1
    assert(1 == VAPGetReferenceCount(doncova));
    
    //divorce
    VAPHumanDivorce(ahmatova);
    
        //get partner ahmatova
        assert(NULL == VAPHumanGetPartner(ahmatova));
    
        //get partner chehov
        assert(NULL == VAPHumanGetPartner(chehov));
    
        //reference count should be 1
        assert(1 == VAPGetReferenceCount(ahmatova));
    
        //release ahmatova
        VAPObjectRelease(ahmatova);
    
    
        //cycle with children
        for (uint64_t index = 0; index < VAPHumanGetChildrenCount(chehov); index++) {
            assert(2 == VAPGetReferenceCount(VAPArrayGetObjectAtIndex(children, index)));
        }
    
    //marry doncova & chehov
    VAPHumanMarry(doncova, chehov);
    
    //create Batman
    VAPHuman *batman = VAPHumanCreateWithParameters("Batman", 42, VAPGenderMale);
    
    //batman try to destroy happy russian family
    VAPHumanMarry(doncova, batman);
    
        //get partner doncova
        assert(chehov == VAPHumanGetPartner(doncova));
    
        //get partner chehov
        assert(doncova == VAPHumanGetPartner(chehov));
    
        //Batman couldn't destroy. He's alone and he very sad
        assert(NULL == VAPHumanGetPartner(batman));
    
    
    //create next child
    VAPHuman *thirdChild = VAPHumanCreateChild(chehov, doncova);
    
    //get chehov's children
    children = VAPHumanGetChildren(chehov);
    
        //get reference count child at index 0 of parrent chehov
        assert(2 == VAPGetReferenceCount(VAPArrayGetObjectAtIndex(children, 0)));
    
        //get reference count child at index 1 of parrent chehov
        assert(2 == VAPGetReferenceCount(VAPArrayGetObjectAtIndex(children, 1)));
    
        //get reference count child at index 2 of parrent chehov
        assert(3 == VAPGetReferenceCount(VAPArrayGetObjectAtIndex(children, 2)));
    
    //get doncova's children
    children = VAPHumanGetChildren(doncova);
    
        //get reference count child at index 0 of parrent doncova
        assert(3 == VAPGetReferenceCount(VAPArrayGetObjectAtIndex(children, 0)));
    
    //release doncova
    VAPObjectRelease(doncova);
    
    //check reference count of firstChild
    assert(2 == VAPGetReferenceCount(firstChild));
    
    //release first child
    VAPObjectRelease(firstChild);
    
    //check reference count of firstChild
    assert(1 == VAPGetReferenceCount(firstChild));
    
    //release chehov
    VAPObjectRelease(chehov);
    
    //check reference count of secondChild
    assert(1 == VAPGetReferenceCount(secondChild));
    
    //check reference count of thirdChild
    assert(1 == VAPGetReferenceCount(thirdChild));
    
    //release second child
    VAPObjectRelease(secondChild);
    
    //release third child
    VAPObjectRelease(thirdChild);
    
    //release third batman
    VAPObjectRelease(batman);
}


