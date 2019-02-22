package com.guc.ndktest;

/**
 * Created by guc on 2019/2/19.
 * 描述：步骤参阅： https://blog.csdn.net/young_time/article/details/80346631
 */
public class JNITest {

    // 动态导入 so 库
    static {
        System.loadLibrary("pcap");
        System.loadLibrary("JNITest");
    }

    public native static String get();
}
