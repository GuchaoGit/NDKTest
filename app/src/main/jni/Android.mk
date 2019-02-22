
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE    := pcap
LOCAL_SRC_FILES := libpcap.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := JNITest
LOCAL_LDLIBS := -llog
LOCAL_SRC_FILES := test.c
LOCAL_SHARED_LIBRARIES := pcap
include $(BUILD_SHARED_LIBRARY)