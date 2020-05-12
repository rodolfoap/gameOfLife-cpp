# Game Of Life - C++

* Game of Life [1]. In C++. Just for fun.
* Simplified as much as possible, the original (and functional) commit was ~700 chars of code.
* Learning new tricks!
* Using CMake to make an elementary dependency injection. See the CMake `add_executable()` dependency injection mechanism. With this, the application is focused on the controller (`gameoflife.cpp`), while the CMake dependency-injection implements the selection of the view layer.

[1] https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life

## Compilation

```
mkdir build && pushd !!
cmake ..
make
popd
```

## Usage

Check the format of any `.matrix` file. Matrix files are the initial setup to run the game.

```
./gameoflife-text    [SOME_FILE.matrix] # plain text
./gameoflife-ncurses [SOME_FILE.matrix] # ncurses
./gameoflife-sfml    [SOME_FILE.matrix] # sfml window
```
## Example output

![](golife-ncurses.gif)

### Plain Text

![](plaintext.png)

### NCURSES

![](ncurses.png)

### SFML

![](sfml.png)
