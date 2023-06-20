# 再学 C 语言

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
* [ ] 使用外部函数库
* [ ] 使用共享函数库和静态函数库
* [ ] gcc 选项详细描述
* [ ] C 程序调式
* [ ] 交叉编译
