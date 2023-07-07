# 管道

`input.c` 可以接收任意个数值并相加，输出总数与个数。`avg.c` 输入总数与个数计算平均值。我们可以使用 `|` Linux 中的管道符将两个工具结合起来，将前者的 `stdout` 作为后者的 `stdin`。

```bash
$ gcc input.c -o input.out
$ gcc avg.c -o avg.out
$ ./input.out | ./avg.out # 前者的输出作为后者的输入
```
