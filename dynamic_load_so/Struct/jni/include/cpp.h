#ifndef __CPP_H__
#define __CPP_H__


#include "cpp_common.h"

#ifdef __cplusplus
extern "C" {
#endif

int sayCount();
SayHandle sayCreate(SayType type);

int sayHello(SayHandle handle);
int sayName(SayHandle handle);

#ifdef __cplusplus
}
#endif

#endif /* __CPP_H__ */

