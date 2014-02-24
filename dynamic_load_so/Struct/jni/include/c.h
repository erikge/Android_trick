#ifndef __C_H__
#define __C_H__

#include "c_common.h"

// c/cpp混编的情况下，有可能被cpp包含得头文件中得c函数都要加extern "C"
#ifdef __cplusplus
extern "C" {
#endif
    
int calEnumCount();
Calculator calCreate(CalType type);

int calAdd(Calculator handle, int x, int y);
int calMinus(Calculator handle, int x, int y);

#ifdef __cplusplus
}
#endif

#endif /* __C_H__ */



