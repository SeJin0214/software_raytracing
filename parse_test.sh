

dir=wrongFile

for var in $(ls $dir)
do
	echo $var
	./miniRT "$var"
done
