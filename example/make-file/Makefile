# 当前文件为 Makefile 配置文件
# 以 "#" 符号开始作为注释
# 注意：配置中 Tab 不能用空格代替，否则无法编译

main.out:max.o min.o main.c
	gcc -g max.o min.o main.c -o main.out

max.o:max.c
	gcc -g -c max.c

min.o:min.c
	gcc -g -c min.c
