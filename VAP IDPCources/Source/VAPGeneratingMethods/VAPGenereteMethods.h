//
//  VAPGenereteMethods.h
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 06.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#ifndef __VAP_IDPCources__VAPGenereteMethods__
#define __VAP_IDPCources__VAPGenereteMethods__


#include <stdio.h>

#define generetingMethodToPrintType(type, spec) void otput_##type(type value) { \
printf(#type "value - " #spec "\n",value);\
}
#define callGenereted(type,value) otput_##type(value)


#endif /* defined(__VAP_IDPCources__VAPGenereteMethods__) */
