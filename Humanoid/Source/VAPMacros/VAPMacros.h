//
//  VAPMacros.h
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 20.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#ifndef VAP_IDPCources_VAPMacros_h
#define VAP_IDPCources_VAPMacros_h

#define VAPMacrosAssign(object, element) \
    if(NULL != object) { \
        object->_##element = element; \
    }

#endif
