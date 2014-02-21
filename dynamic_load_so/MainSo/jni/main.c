#include "com_vctl_mainso_NdkCall.h"

#include <android/log.h>
#include "c.h"
#include "cpp.h"

#include <jni.h>


JNIEXPORT void JNICALL Java_com_vctl_mainso_NdkCall_trigger
  (JNIEnv *env, jobject obj) {

    int c_count = calEnumCount();
    int cpp_count = sayCount();
    __android_log_print( ANDROID_LOG_DEBUG, "erik", "~~~~~~~~ c(%d), cpp(%d)", c_count, cpp_count);



}

