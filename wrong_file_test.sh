

dir=wrong_file_in_mandatory

for var in $(ls $dir)
do
	echo $var
	valgrind --leak-check=full ./miniRT "$dir" "$var"
done

