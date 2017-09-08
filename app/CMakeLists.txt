# Sets the minimum version of CMake required to build the native
# library. You should either keep the default value or only pass a
# value of 3.4.0 or lower.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds it for you.
# Gradle automatically packages shared libraries with your APK.

#设置生成的so动态库最后输出的路径
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../jniLibs/${ANDROID_ABI})
find_library(
              log-lib
              log )
#设置so库
set(my_lib_path ${CMAKE_SOURCE_DIR}/libs)

add_library( nativeUtil
             SHARED
             IMPORTED )

set_target_properties( nativeUtil
                       PROPERTIES IMPORTED_LOCATION
                       ${my_lib_path}/${ANDROID_ABI}/libnativeUtil.so )
add_library(
             native-lib
             SHARED
             src/main/cpp/native-lib.c )




target_link_libraries(
                        native-lib
                       nativeUtil
                       ${log-lib} )
