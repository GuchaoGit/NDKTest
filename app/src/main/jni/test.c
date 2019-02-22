#include<jni.h>
#include<stdio.h>
#include<android/log.h>
#include<pcap.h>
//导入我们创建的头文件
#include "com_guc_ndktest_JNITest.h"
 #define TAG "jnitest" // 这个是自定义的LOG的标识
 #define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
 #define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
 #define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
 #define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
 #define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型
void check_libpcap()
{
        printf("check libpcap available.\n");
        char errbuf[PCAP_ERRBUF_SIZE];

        pcap_if_t *devs;
        if (pcap_findalldevs(&devs, errbuf) != 0) {
                LOGE("pcap findalldevs failure: %s\n", errbuf);
        }
        pcap_if_t *d;
        int i = 0;
        LOGE("### list all dev ###\n");
        for (d = devs; d; d = d->next) {
                LOGE("%d. dev: %s\n", i++, d->name);
        }
        LOGE("### dev count: %d ###\n", i);
        pcap_freealldevs(devs);
}
JNIEXPORT jstring JNICALL Java_com_guc_ndktest_JNITest_get
  (JNIEnv *env, jclass jclass){
    char * name = "mronion";
    __android_log_print(ANDROID_LOG_INFO, "guc", "my name is %s\n", name); //log i类型

    LOGE( "my name is %s\n", name);
    check_libpcap();
     //返回一个字符串
      return (*env)->NewStringUTF(env,"This is my first NDK Application");
  }