

dir=wrongFile

for var in $(ls $dir)
do
	echo $var
	valgrind --leak-check=full ./miniRT "$var"
done
