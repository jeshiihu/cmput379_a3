# Hello World Program in Bash Shell

# exits script on first error
set -e

# echo "page size, specified in words:" $1
# echo "window size of working set:" $2
# echo "name of process:" $3

if [ "$1" == "clean" ];
then
	make clean
fi

if [ "$3" == "quicksort" ];
then
    echo "selected quicksort"
    make quicksort
    ./quicksort $1 $2
fi

if [ "$3" == "heapsort" ];
then
    echo "selected heapsort"
    make heapsort
    ./heapsort $1 $2
fi