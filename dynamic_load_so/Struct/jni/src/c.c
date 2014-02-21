#include "c.h"

#include "c_impl.h"
#include <android/log.h>


#define IMPL_NUM 4

static CalculatorImpl *s_inner_impl[IMPL_NUM];


int calEnumCount() {
    int count = 0;
    int i = 0;
    
    for (i = 0; i < IMPL_NUM; ++i) {
        if (s_inner_impl[i] != NULL) {
            count++;
        }
    }
    __android_log_print( ANDROID_LOG_DEBUG, "erik", "~~~~~~~~ c calEnumCount: %d", count);
    return count;
}

Calculator calCreate(CalType type) {
    int i = 0;
    for (i = 0; i < IMPL_NUM; ++i) {
        if (s_inner_impl[i] != NULL && s_inner_impl[i]->type == type) {
            return (Calculator)s_inner_impl[i];
        }
    }
    return (void *)CAL_UNIMPL;
}

int calAdd(Calculator handle, int x, int y) {
    CalculatorImpl *impl = (CalculatorImpl *) handle;
    if (!impl) {
        return CAL_NULL;
    }
    return (*impl->calAdd)(handle, x, y);
}
int calMinus(Calculator handle, int x, int y) {
    CalculatorImpl *impl = (CalculatorImpl *) handle;
    if (!impl) {
        return CAL_NULL;
    }
    return (*impl->calMinus)(handle, x, y);
}

int calRegister(CalculatorImpl *impl) {
    int i = 0;
    __android_log_print( ANDROID_LOG_DEBUG, "erik", "~~~~~~~~ c calRegister");
    
    for (i = 0; i < IMPL_NUM; ++i) {
        if (s_inner_impl[i] == NULL) {
            s_inner_impl[i] = impl;
            return CAL_SUCCESS;
        }
    }
    return CAL_NULL;
}
