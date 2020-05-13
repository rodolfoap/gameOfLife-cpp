execute(){
	./gameoflife		patterns/glidergun.matrix
	#/gameoflife-sfml	patterns/glidergun.matrix
	#/gameoflife-ncurses	patterns/glidergun.matrix
	#/gameoflife-text	patterns/glidergun.matrix
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
	[ $STATUS == 0 ] && echo [100%] Generated binaries: $(ls gameoflife*) || echo [ERROR] Compilation error.
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
		vi -p 	src/{controller,model,small,view-ncurses,view-sfml,view-text}.cpp \
			include/{model,view}.hpp \
			CMakeLists.txt
		rm -f gameoflife-*
		build;
		execute;
	;;
esac
