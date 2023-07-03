project(getting-start-uv LANGUAGES C)

set(sources main.c)

# 设定编译类型为debug，调试时需要选择debug
# set(CMAKE_BUILD_TYPE Debug)
# 设定编译类型为release，发布时需要选择release
# set(CMAKE_BUILD_TYPE Release)
# 一般不会之间使用以上配置在 CMakeLists.txt 中，而是以下这种在命令行中指定参数：
# cmake .. -DCMAKE_BUILD_TYPE=Debug
# cmake .. -DCMAKE_BUILD_TYPE=Release

# 向工程添加多个特定的头文件搜索路径
include_directories(~/code/github.com/libuv/libuv/include)

# 向工程添加多个特定的库文件搜索路径
link_directories(~/code/github.com/libuv/libuv/build)
link_libraries(uv)

# # 将动态库文件链接到可执行文件
# target_link_libraries(getting-start-uv libuv)

# # 添加编译参数 -Wall -std=c++11 -O2
# add_compile_options(-Wall -std=c++11 -O2)

# 生成可执行文件
add_executable(main ${sources})
