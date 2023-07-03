## Overflow

This directory is used to learn Libuv.


## Install and build dependencies

Clone the Libuv repository.

```
$ git clone https://github.com/libuv/libuv.git
```

Go to the project directory build Libuv.

```
$ cd /path/to/libuv
$ mkdir -p build
$ (cd build && cmake .. -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTING=ON) # generate project with tests
$ cmake --build build                       # add `-j <n>` with cmake >= 3.12
```

## Build the Libuv Example.

```
$ cd getting-start-uv
$ mkdir -p build
$ (cd build && cmake .. -DCMAKE_BUILD_TYPE=Debug && make)
$ ./build/main # 如果要调试，使用 vscode “(lldb) cmake” 调试模式，在当前目录点击运行
```
