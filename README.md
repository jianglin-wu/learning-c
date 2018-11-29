# 重学 C 语言

## 前言

抛开 bat 脚本和易语言不谈，C 语言应该是我学的第一门比较正式的程序语言。学的并不理想，很多知识没有学到。经常心里惦记着把它重新再学一遍，无奈一拖再拖过去了好几年，所以今天定下决心治治自己的拖延症。


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

## 编译知识 Todo
* [x] 编译单个源文件
* [x] 编译详细原理
* [x] 编译多个源文件
* [ ] 使用外部函数库
* [ ] 使用共享函数库和静态函数库
* [ ] gcc 选项详细描述
* [ ] C 程序调式
* [ ] 交叉编译


