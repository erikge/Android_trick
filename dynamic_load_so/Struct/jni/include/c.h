#ifndef __C_H__
#define __C_H__

#include "c_common.h"

int calEnumCount();
Calculator calCreate(CalType type);

int calAdd(Calculator handle, int x, int y);
int calMinus(Calculator handle, int x, int y);


#endif /* __C_H__ */



