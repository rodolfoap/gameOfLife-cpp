void initncurses() {
	initscr(); // mandatory
        noecho(); // avoid echo
        attron(A_REVERSE); // Reverse
        curs_set(0); // hides cursor
        use_default_colors(); // ncurses has horrible colors, this uses the users' default... more or less.
        init_pair(1, COLOR_GREEN, COLOR_BLACK); // id, foreground, background
        attron(COLOR_PAIR(1));
}
void dot(int y, int x, int v){
        if(v)attron(A_REVERSE);else attroff(A_REVERSE);
	mvprintw(y, x, " ");
}
