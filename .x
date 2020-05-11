execute(){
	./gameoflife r-pentomino.matrix
}
debug(){
	nemiver gameoflife
}
build(){
	[ -d build/ ] && {
		pushd build &> /dev/null;
	} || {
		mkdir build;
		pushd build &> /dev/null;
		cmake .. -Wdev;
	}
	make -j8; STATUS=$?
	popd &> /dev/null;
	[ $STATUS == 0 ] && echo [100%] $(ls -l gameoflife) || echo [ERROR] Compilation error.
}
case "$1" in
	"")
		rm -f gameoflife
		[ -f gameoflife ] || build;
		execute
	;;
	d)	# Debug
		debug
	;;
	e)
		vi -p gameoflife.cpp functions.cpp CMakeLists.txt
		rm -f gameoflife
		build;
		execute;
	;;
esac
