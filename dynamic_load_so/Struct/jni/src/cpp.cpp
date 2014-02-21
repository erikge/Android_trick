#include "cpp.h"
#include "cpp_impl.h"
#include "PrintSay.h"

#include <android/log.h>

int sayCount() {
    return PrintSay::getInstance()->psayCount();
}
SayHandle sayCreate(SayType type) {
    return PrintSay::getInstance()->psayCreate(type);
}

int sayHello(SayHandle handle) {
    return PrintSay::getInstance()->psayHello(handle);
}
int sayName(SayHandle handle) {
    return PrintSay::getInstance()->psayName(handle);
}

int sayRegister(SayInner *impl) {
    __android_log_print( ANDROID_LOG_DEBUG, "erik", "~~~~~~~~ cpp sayRegister");
    
    return PrintSay::getInstance()->psayRegister(impl);
}

