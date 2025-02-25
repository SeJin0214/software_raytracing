

dir=wrongFile

for var in $(ls $dir)
do
	echo $var
	valgrind --leak-check=full ./miniRT "$var"
done
#CFLAGS = -Wall -Wextra -Werror -O3 -march=native -mavx2 -fno-stack-protector -funroll-loops -pthread   -g
