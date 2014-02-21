#include "c_impl.h"

#include <jni.h>
#include <android/log.h>

int add(Calculator handle, int x, int y) {
    return x + y;
}

int minus(Calculator handle, int x, int y) {
    return x - y;
}

static CalculatorImpl s_inner = {
    CAL_TYPE_A_C,
    add,
    minus
};

//jint JNI_OnLoad(JavaVM* vm, void* args)
//{
//    __android_log_print( ANDROID_LOG_DEBUG, "erik", "~~~~~~~~ JNI_OnLoad c");
//    
//    calRegister(&s_inner);
//    
//    
//    return JNI_VERSION_1_4;
//}
