gcc -c -o main.o main.c -I inc/ -I ../ft_mem/inc/
gcc -o test main.o ./libftclist.a ../ft_mem/libftmem.a 
