//
//  main.c
//  Humanoid
//
//  Created by Aleksandr Vasylchenko on 12.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//
#include "VAPHumanoidObject.h"
#include <stdio.h>
#include <stdlib.h>

void testChild() ;

int main(int argc, const char * argv[]) {
//    VAPHuman *Kirill = VAPHumanCreate("Kirill", 22, Male , );
    VAPHumanoidObjectTest();
    return 0;
}
void testChild(VAPHuman *hum) {
    VAPHuman *humf = VAPHumanGetChild(hum);
    printf("%d\n",VAPHumanGetAge(humf));
}