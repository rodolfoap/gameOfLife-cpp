execute(){
	./gameoflife-sfml glidergun.matrix
	#/gameoflife-ncurses glidergun.matrix
	#/gameoflife-text glidergun.matrix
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
	[ $STATUS == 0 ] && echo [100%] Generated binaries: $(ls gameoflife-*) || echo [ERROR] Compilation error.
}
case "$1" in
	"")
		rm -f gameoflife-*
		build;
		execute
	;;
	b)	# Build
		build
	;;
	e)
		vi -p sfml.cpp ncurses.cpp plaintext.cpp gameoflife.cpp CMakeLists.txt
		rm -f gameoflife-*
		build;
		execute;
	;;
esac
