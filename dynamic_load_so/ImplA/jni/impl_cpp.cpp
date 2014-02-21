#include "cpp_impl.h"

#include <jni.h>
#include <android/log.h>

int implASayHello(SayHandle handle) {
    __android_log_print( ANDROID_LOG_DEBUG, "erik", "~~~~~~~~ hello");
}

int implASayName(SayHandle handle) {
    
    __android_log_print( ANDROID_LOG_DEBUG, "erik", "~~~~~~~~ name");
}


static SayInner s_inner = {
    SAY_TYPE_A,
    implASayHello,
    implASayName,
};

jint JNI_OnLoad(JavaVM* vm, void* /*reserved*/)
{
    __android_log_print( ANDROID_LOG_DEBUG, "erik", "~~~~~~~~ JNI_OnLoad cpp");
    
    if (!vm)
    {
        __android_log_write(ANDROID_LOG_ERROR, "erik",
                            "JNI_OnLoad did not receive a valid VM pointer");
        return -1;
    }
    
    // Get JNI
    JNIEnv* env;
    if (JNI_OK != vm->GetEnv(reinterpret_cast<void**> (&env),
                             JNI_VERSION_1_4))
    {
        __android_log_write(ANDROID_LOG_ERROR, "erik",
                            "JNI_OnLoad could not get JNI env");
        return -1;
    }
    
    sayRegister(&s_inner);
    
    
    return JNI_VERSION_1_4;
}

