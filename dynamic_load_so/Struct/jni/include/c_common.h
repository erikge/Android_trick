#ifndef __C_COMMON_H__
#define __C_COMMON_H__

#define NULL    ((void*)0)

typedef void * Calculator;

typedef enum CalTypeEnum {
    CAL_TYPE_A_CPP,
    CAL_TYPE_A_C,
} CalType;

#define CAL_SUCCESS 0
#define CAL_UNIMPL -1
#define CAL_NULL -2


#endif /* __C_COMMON_H__ */



