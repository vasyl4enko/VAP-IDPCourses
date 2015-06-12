//
//  VAPMacros.h
//  VAP IDPCources
//
//  Created by Aleksandr Vasylchenko on 20.05.15.
//  Copyright (c) 2015 Aleksandr Vasylchenko. All rights reserved.
//

#ifndef VAP_IDPCources_VAPMacros_h
#define VAP_IDPCources_VAPMacros_h

#define VAPAssignSetter(object, _iVar, newVar) \
    if(NULL != object) { \
        object->_iVar = newVar; \
    }

#define VAPRetainSetter(object, _iVar, newVar) \
    if (NULL != object && object->_iVar != newVar) { \
        VAPObjectRetain(newVar); \
        VAPObjectRelease(object->_iVar); \
        object->_iVar = newVar; \
    }
//        VAPRetainSetter(object, ivar, newVar);

#endif
