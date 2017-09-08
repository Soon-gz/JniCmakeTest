#include <jni.h>
#include "nativeheader.h"

jint Java_com_example_administrator_jnicmaketest_MainActivity_stringFromJNI(
        JNIEnv* env, jobject jobj,jint a,jint b) {
    return add(a,b);
}
