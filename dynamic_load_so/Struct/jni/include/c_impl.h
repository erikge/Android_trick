#ifndef __CALCULATOR_C_IMPL_H__
#define __CALCULATOR_C_IMPL_H__

#include "c_common.h"

typedef struct CalculatorImplStruct {

    CalType type;

    int (*calAdd)(Calculator handle, int x, int y);
    int (*calMinus)(Calculator handle, int x, int y);

} CalculatorImpl;

#ifdef __cplusplus
extern "C" {
#endif
    
int calRegister(CalculatorImpl *impl);

#ifdef __cplusplus
}
#endif
        
#endif /* __CALCULATOR_C_IMPL_H__ */

