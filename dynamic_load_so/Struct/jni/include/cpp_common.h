#ifndef __CPP_COMMON_H__
#define __CPP_COMMON_H__

#define NULL    ((void*)0)

typedef void * SayHandle;

typedef enum SayTypeEnum {
    SAY_TYPE_A,
    CAL_TYPE_B,
} SayType;

#define SAY_SUCCESS 0
#define SAY_UNIMPL -1
#define SAY_NULL -2


#endif /* __CPP_COMMON_H__ */

