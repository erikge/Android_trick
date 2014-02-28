CACHED_LOCAL_PATH := $(call my-dir)

### build struct #####################################################

LOCAL_PATH := $(call my-dir)
include $(LOCAL_PATH)/../../Struct/jni/Android.mk

### build implA #####################################################

LOCAL_PATH := $(CACHED_LOCAL_PATH)
include $(CLEAR_VARS)

LOCAL_MODULE    := implA
LOCAL_SRC_FILES := impl_c.c \
                impl_cpp.cpp \
		
LOCAL_C_INCLUDES :=  $(LOCAL_PATH)/../../Struct/jni/include

LOCAL_LDLIBS := -llog
LOCAL_SHARED_LIBRARIES := libstruct # the name should be the same with the module name in struct's Android.mk

include $(BUILD_SHARED_LIBRARY)





########################################################
# android mk syntax
########################################################

## inner command
#include $(TOP_LOCAL_PATH)/xxx/Android.mk

## conditional
#ifeq ($(TARGET_ARCH_ABI),armeabi)
#MY_PJSIP_FLAGS := $(BASE_PJSIP_FLAGS) -DPJ_HAS_FLOATING_POINT=0
#else
#MY_PJSIP_FLAGS := $(BASE_PJSIP_FLAGS) -DPJ_HAS_FLOATING_POINT=1
#endif

## unknown command
#$(info local_path: $(LOCAL_PATH))

## execute shell
##$(shell IF EXIST $(MEDIA_LIBS_PATH_DST)\libMediaEngine.so (del $(MEDIA_LIBS_PATH_DST)\libMediaEngine.so > NUL))

## import static lib
#include $(CLEAR_VARS)
#LOCAL_MODULE:= libavcodec
#LOCAL_SRC_FILES:= $(FFMPEG_LIB)/libavcodec.a
#LOCAL_EXPORT_C_INCLUDES := $(FFMPEG_INCLUDE)
#include $(PREBUILT_STATIC_LIBRARY)
#
#LOCAL_STATIC_LIBRARIES := libavcodec # this or the next line
#LOCAL_WHOLE_STATIC_LIBRARIES := libavcodec # (optional)
#LOCAL_PRELINK_MODULE := true

## import shared lib
#LOCAL_SHARED_LIBRARIES: = 3rd-party libs
