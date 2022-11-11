cmake_minimum_required (VERSION 2.8.12)#规定cmake的最低版本要求
set(CMAKE_CXX_STANDARD 11)#c++版本
project(LEETCODE_C)#项目的名称，不一定和你的文件夹名称一样
set(CMAKE_CXX_COMPILER "clang++")#设置c++编译器
 
include_directories(${PROJECT_SOURCE_DIR}/include/**)#添加头文件的搜索路径
include_directories(${PROJECT_SOURCE_DIR}/include/DP/**)
aux_source_directory(./src/Greedy SrcFiles)#将源文件列表写在变量SrcFiles中

aux_source_directory(./src/LinkList SrcFiles)
aux_source_directory(./src/DP SrcFiles)#将源文件列表写在变量SrcFiles中
aux_source_directory(./src/Tree SrcFiles)#将源文件列表写在变量SrcFiles中
aux_source_directory(./src SrcFiles)#工程项目较大，要创建多个模块
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/build)#设置可执行文件输出路径
add_executable(main ${SrcFiles})#设置可执行文件的名称，make之后bin目录下出现main.exe
 