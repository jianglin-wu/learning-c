# 再学 C/C++ 语言

## 前言

抛开 bat 脚本和易语言不谈，C 语言应该是我学的第一门比较正式的程序语言。学的并不理想，很多知识没有学到。经常心里惦记着把它再学一遍，无奈一拖再拖过去了好几年，所以今天定下决心治治自己的拖延症。


## 编译
### 编译流程
![](http://ww1.sinaimg.cn/large/e02f2343gy1fto7la7ipaj20ly03nt8y.jpg)
[图片来源](http://lxwei.github.io/posts/262.html)

```bash
# 普通编译(预处理>编译>汇编>链接)
$ gcc -o hello.out hello.c

# 详细步骤：
# 预处理过程（引入的标准库与头文件等操作）
$ gcc -E -o hello.i hello.c

# 编译过程（翻译为汇编语言）
$ gcc -S -o hello.s hello.i

# 汇编过程（编译为机器指令，编译后为二进制文件，但还不能运行）
$ gcc -c -o hello.o hello.s

# 链接（将依赖文件与头文件整合到一起，输出的文件是可执行程序）
$ gcc -o hello.out hello.o
```

其他

[5分钟理解make/makefile/cmake/nmake](https://zhuanlan.zhihu.com/p/111110992)

- gcc: GNU Compiler Collection（就是GNU编译器套件）
- make: 可以看成是一个智能的批处理工具
- makefile: 批处理工具的配置
- cmake
- CMakeList.txt


### Makefile 编写

参考：[利用makefile文件编译c++源文件](https://blog.csdn.net/zhaocuit/article/details/74782789)

编译 cpp（如果是 c 源文件只需将配置中 cpp 修改成 c，g++ 修改成 gcc）:

```
CC=g++
SRCS=main.cpp\
        udp.cpp
OBJS=$(SRCS:.cpp=.o)
EXEC=maincpp
start:$(OBJS)
        $(CC) -o $(EXEC) $(OBJS)
.cpp.o:
        #-DMYLINUX:-D为参数，MYLINUX为在cpp源文件中定义的宏名称，如#ifdef MYLINUX。注意-D和宏名称中间没有空格
        $(CC) -o $@ -c $< -DMYLINUX
        $(CC) -o $@ -c $< -DMYLINUX
clean:
        rm -rf $(OBJS)
```


编译 so 库：

```
CC=gcc
SRCS=mylib.c
OBJS=$(SRCS:.c=.o)
#这里的命名有一个规则，以lib开头，以.so结尾，必须这样
EXEC=libmylib.so
start:$(OBJS)
        #-shared表示最终链接成so共享文件
        $(CC) -o $(EXEC) $(OBJS) -shared
.c.o:
        #-fPIC表在编译时生成和位置无关的代码
        $(CC) -o $@ -c $< -fPIC
clean:
        rm -rf $(OBJS)
```

编译使用库的程序：

```
CC=g++
SRCS=main.cpp
OBJS=$(SRCS:.cpp=.o)
EXEC=maincpp
start:$(OBJS)
        #-L../表示需要链接库的地址，可以是相对路径或者绝对路径，-lmylib为需要使用的库，注意这里的mylib是指libmylib.so文件，去掉前面的lib和.so后缀名后的名字
        $(CC) -o $(EXEC) $(OBJS) -L../ -lmylib
.cpp.o:
        $(CC) -o $@ -c $<
clean:
        rm -rf $(OBJS)
```

> 上述 makefile 的 $(CC) -o $(EXEC) $(OBJS) -L../ -lmylib 部分时，只是指明了链接时的库文件路径，而没有指明运行时库文件路径。
> 在使用库文件（so文件）时，需要指明链接时的so文件路径和运行时的so文件路径。-L表示的是链接时库文件的路径。
> 而运行时的库文件路径由“-Wl,-R”参数或者"-Wl,-rpath"指定（如果使用"-Wl,-rpath"这个参数，参数和路径中间必须有空格。
> 也可以用"-Wl,-rpath="，这种方式的参数和路径中间就不需要空格）。
> 即只需要将$(CC) -o $(EXEC) $(OBJS) -L../ -lmylib修改成$(CC) -o $(EXEC) $(OBJS) -L../ -lmylib -Wl,-R../即可。


其他问题
- [怎么卸载用 make install 编译安装的软件？](https://www.zhihu.com/question/20092756)




### Cmake

- [从零开始详细介绍CMake](https://www.bilibili.com/video/BV1vR4y1u77h?p=1&vd_source=fa7ef5b52c257696949bed772d9dbced)
- CMake 指定安装目录（通过 CMAKE_INSTALL_PREFIX 参数）
  - [方法1: `CMake 指定安装目录`](https://blog.csdn.net/CaspianSea/article/details/53526725)

## VsCode 下开发

### 快捷构建任务

通过 `.vscode/tasks.json` 配置快捷任务，使用 `command + shift + b` 执行默认任务。或者 `command + shift + p` 调出命令输入框，输入 `tasks` 找到任务相关操作。

- 执行默认任务: `command + shift + b`
- 手动选择任务: `command + shift + p` 调出命令输入框，`>tasks: run task` 或 `>任务: 运行任务`（可以绑定快捷键，我使用 `command + shift + ctrl + b`）。


构建任务

- 【gcc complie simple C】构建简单的 C 代码程序，如果多文件要构建多个产出物则不适用。
- 【C/C++: clang】构建简单的 c/c++ 代码程序。
- 【makefile build】构建 makefile 程序，在 makefile 文件目录执行（默认）。


### 调试

通过 `.vscode/launch.json` 配置调试配置，在左侧【运行和调试】模块点击 “(lldb) 启动 workspace” 或直接按 `F5` 进入调试模式。

ps: 需要注意的是构建任务的 gcc 命令需要加上 `-g` 参数才能调试，参考 [gdb 调试](./12-005-gdb/note.md)。


## Todo

* [x] 编译单个源文件
* [x] 编译详细原理
* [x] 编译多个源文件
* [x] 使用外部函数库
* [x] 使用共享函数库和静态函数库
* [x] C 程序调式
* [ ] 交叉编译
