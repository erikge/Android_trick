#include "PrintSay.h"

#include <android/log.h>

PrintSay *PrintSay::_instance = 0;

/**
 * Returns the single instance of the object.
 */
PrintSay* PrintSay::getInstance() {
    // check if the instance has been created yet
    if (0 == _instance) {
        // if not, then create it
        _instance = new PrintSay;
    }
    // return the single instance
    return _instance;
};

int PrintSay::psayCount() {
    int count = 0;
    for (int i = 0; i < 4; ++i) {
        if (inner_say_[i] != NULL) {
            count++;
        }
    }
    return count;
}
SayHandle PrintSay::psayCreate(SayType type) {
    for (int i = 0; i < 4; ++i) {
        if (inner_say_[i] != NULL && inner_say_[i]->type == type) {
            return (SayHandle)inner_say_[i];
        }
    }
    return NULL;
}

int PrintSay::psayHello(SayHandle handle) {
    if (handle) {
        SayInner *inner = (SayInner *)handle;
        return (*inner->sayHello)(handle);
    }
    return SAY_NULL;
}
int PrintSay::psayName(SayHandle handle) {
    if (handle) {
        SayInner *inner = (SayInner *)handle;
        return (*inner->sayName)(handle);
    }
    return SAY_NULL;
}

int PrintSay::psayRegister(SayInner *impl) {
    
    __android_log_print( ANDROID_LOG_DEBUG, "erik", "~~~~~~~~ cpp psayRegister [class impl]");
    
    if (!impl) return SAY_NULL;
    for (int i = 0; i < 4; ++i) {
        if (inner_say_[i] == NULL) {
            inner_say_[i] = impl;
            return SAY_SUCCESS;
        }
    }
    return SAY_NULL;
}

