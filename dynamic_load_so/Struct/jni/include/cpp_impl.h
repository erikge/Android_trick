#ifndef __CPP_IMPL_H__
#define __CPP_IMPL_H__

#include "cpp_common.h"

typedef struct SayInnerStruct {

    SayType type;

    int (*sayHello)(SayHandle handle);
    int (*sayName)(SayHandle handle);

} SayInner;

int sayRegister(SayInner *impl);


#endif /* __CPP_IMPL_H__ */

