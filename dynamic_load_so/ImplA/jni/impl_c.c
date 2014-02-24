#include "c_impl.h"

#include <jni.h>
#include <android/log.h>

int add(Calculator handle, int x, int y) {
    return x + y;
}

int minus(Calculator handle, int x, int y) {
    return x - y;
}

CalculatorImpl s_inner_c = {
    CAL_TYPE_A_C,
    add,
    minus
};
