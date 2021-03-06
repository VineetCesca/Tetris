/**
 * @file Extra.h
 * @brief Functions which are not really needed to play the game
 * @author Vineet (with some third part of codes)
 */

/**
 * Moves the cursor at (x, y) coords
 * (windows.h)
 * @param x screen x coord.
 * @param y screen y coord.
 * @see SetConsoleCursorPosition()
 */
void gotoXY(int x, int y){
 
 COORD coord;
 
 coord.X = x;
 
 coord.Y = y;
 
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
 
}

/**
 * Waits for a certain number of seconds
 * @param[in] number_of_seconds amount of seconds to wait
 * @see clock()
 */
void delay(float number_of_seconds){
    /* Converting time into milli_seconds */
    float milli_seconds = 1000 * number_of_seconds;
  
    /* Storing start time */
    clock_t start_time = clock();
  
    /* looping till required time is not achieved*/
    while (clock() < start_time + milli_seconds);
}

/**
 * Prints out the loading bar
 * @see gotoXY()
 * @see delay() 
 */
void loadGame(){
    int r, cnt = 5, n = 60, m = n;
    gotoXY(n + 5, 25);
    printf("LOADING...");
    for(r=1;r<=20;r++){
        gotoXY(n, 26);
        delay(0.100);
        printf("%c", 177);
        gotoXY(n + 5, 27);
        printf("%3d/100", cnt);
        cnt += 5;
        n++;
    }
    
    gotoXY(m + 2, 30);
    printf("Enter anything to play \n");  
    getch();
}

/**
 * Shutting down bar while closing the game
 * @see gotoXY()
 * @see delay()
 */
void closeGame(){
    int r, cnt = 5, n = 60;
    gotoXY(n + 2, 25);
    printf("SHUTTING DOWN...");
    for(r=1;r<=20;r++){
        gotoXY(n, 26);
        delay(0.100);
        printf("%c", 177);
        gotoXY(n + 5, 27);
        printf("%3d/100", cnt);
        cnt += 5;
        n++;
    }

}

/**
 * Useful to prevent input mistakes (wrong data type)
 * @return 1 
 */
int clean_stdin() /* useful to prevent input data errors */
{
    while (getchar()!='\n');
    return 1;
}

/* self-made */
/**
 * Fills the map with '1'
 * @param[out] map game map
 */
void fillOne(int map[15][10]){
    int i, j;
    for (i = 1; i < height - 1; i++){
        for(j = 1; j < width - 1; j++){
            map[i][j] = 1;
        }
    }
}



