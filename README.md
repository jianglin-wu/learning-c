# 重学 C 语言

## 前言
抛开 bat 脚本和易语言不谈，C 语言应该是我学的第一门比较正式的程序语言。学的并不理想，很多知识没有学到。经常心里惦记着把它重新再学一遍，无奈一拖再拖过去了好几年，所以今天定下决心治治自己的拖延症。


## 编译
在 Linux 下自带了工具 `gcc`，使用它可以将你的 C 代码编译为可以直接运行的二进制文件。

执行这条命令将 `hello.c` 文件编译成二进制，并输出为 `hello.out` 文件。
```bash
$ gcc -o hello.out hello.c
```