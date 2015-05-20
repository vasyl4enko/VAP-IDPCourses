//
//  VAPStringTests.c
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 20.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#include "VAPStringTests.h"
#include "VAPString.h"

//object created with char *name
//object get char name
//object set another name
//object reference count should be 1

static
void VAPStringCreationTest(void);

void VAPStringTests(void) {
    VAPStringCreationTest();
}

void VAPStringCreationTest(void) {
    char *randomNameInMyMind = "Pushkin";
    char *changingName = "Lermontov";
    //object created with char *randomNameInMyMind
    VAPString *object = VAPStringCreate(randomNameInMyMind);
    //object get char randomNameInMyMind
    printf("%s - randomNameInMyMind\n",VAPStringGetName(object));
    //object set another name
    VAPStringSetName(object, changingName);
    //object get changingName
    printf("%s - changingName\n",VAPStringGetName(object));
    //object retained
    VAPString *anotherObject = VAPObjectRetain(object);
    //anotherObject get reference count should be 2
    printf("%llu - anotherObject\n",VAPGetReferenceCount(anotherObject));
    VAPObjectRelease(anotherObject);
    //object get reference count should be 1
    printf("%llu - object\n",VAPGetReferenceCount(object));
    VAPObjectRelease(object);
}