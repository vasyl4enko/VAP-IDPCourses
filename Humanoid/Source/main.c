//
//  main.c
//  Humanoid
//
//  Created by Aleksandr Vasylchenko on 12.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//
#include "VAPHumanoidObject.h"
#include <stdio.h>

void testChild() ;

int main(int argc, const char * argv[]) {
//    VAPHuman *Kirill = VAPHumanCreate("Kirill", 22, Male , );
    uint16_t age = 50;
    uint8_t count = 0;
    char *name = "Kirill";
    VAPHuman *Kirill = VAPHumanCreate(name, age, Male, count);
    VAPHuman *child = VAPHumanCreate(name, age, Male, count);
    VAPHumanSetChild(Kirill, child);
    testChild(Kirill);
//    printf("%d\n",VAPHumanGetAge(Kirill));
    return 0;
}
void testChild(VAPHuman *hum) {
    VAPHuman *humf = VAPHumanGetChild(hum);
    printf("%d\n",VAPHumanGetAge(humf));
}