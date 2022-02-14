void gotoXY(int x, int y){
 
 COORD coord;
 
 coord.X = x;
 
 coord.Y = y;
 
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
 
}

void loadGame(){
    int r, cnt = 5, n = 30;
    gotoXY(36,14);
    printf("LOADING...");
    for(r=1;r<=20;r++){
        gotoXY(n, 15);
        Sleep(100);
        printf("%c", 177);
        gotoXY(51, 15);
        printf("%3d/100", cnt);
        cnt += 5;
        n++;
    }
    
    gotoXY(30, 19);
    printf("Enter anything to play \n");  
    getch();
}

void closeGame(){
    int r, cnt = 5, n = 30;
    gotoXY(36,14);
    printf("SHUTTING DOWN...");
    for(r=1;r<=20;r++){
        gotoXY(n, 15);
        Sleep(100);
        printf("%c", 177);
        gotoXY(51, 15);
        printf("%3d/100", cnt);
        cnt += 5;
        n++;
    }

}

int clean_stdin() /* useful to prevent input data errors */
{
    while (getchar()!='\n');
    return 1;
}

/* self-made */
void fillOne(int map[15][10], int width, int height){
    int i, j;
    for (i = 1; i < height - 1; i++){
        for(j = 1; j < width - 1; j++){
            map[i][j] = 1;
        }
    }
}

void delay(float number_of_seconds){
    // Converting time into milli_seconds
    float milli_seconds = 1000 * number_of_seconds;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}


