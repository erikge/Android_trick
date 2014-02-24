#include "com_vctl_mainso_NdkCall.h"

#include <android/log.h>
#include "c.h"
#include "cpp.h"

#include <jni.h>


JNIEXPORT void JNICALL Java_com_vctl_mainso_NdkCall_trigger
  (JNIEnv *env, jobject obj) {
      
      Calculator calculator = calCreate(CAL_TYPE_A_C);
      SayHandle say = sayCreate(SAY_TYPE_A);

      int c_count = calEnumCount();
      int cpp_count = sayCount();
      __android_log_print( ANDROID_LOG_DEBUG, "erik", "~~~~~~~~ c(%d), cpp(%d)", c_count, cpp_count);
      
    
      __android_log_print( ANDROID_LOG_DEBUG, "erik", "~~~ c: 2+3= %d", calAdd(calculator, 2, 3));
      __android_log_print( ANDROID_LOG_DEBUG, "erik", "~~~ c: 5-4= %d", calMinus(calculator, 5, 4));
      sayHello(say);
      sayName(say);



}

