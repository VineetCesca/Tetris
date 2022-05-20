#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#include <process.h>

const int height = 15, width = 10;
const int dim = 6; /* T, I, O, Z, L, Lr */
char *colorSM = "blue";
char *colorSMPiece = "green";
char *colorMP = "red";
char *color1 = "yellow";
char *color2 = "purple";

#include "TextSettings.h"
#include "Initializer.h"
#include "DrawPieces.h"
#include "Extra.h"
#include "Logic.h"
#include "Print.h"
#include "Cut.h"



int main(){

    /*
    
    char key;

    while(1){
        while(!kbhit()){

        }
        key = getch();
        printf("%c \n", key);
        if(key == 'a'){
            printf("a");
        }
    }

    int width = 10, height = 15;
    int score;

    initScore(&score);
    printLegendaAllPieces(width, height);
    printScore(score);
    
    time_t curtime;
    struct tm *loc_time;
    
    Getting current time of system:
    curtime = time (NULL);

    Converting current time to local time:
    loc_time = localtime (&curtime);

    Displaying date and time in standard format
    printf("%s", asctime (loc_time));



    char key;
    int t;
    int i = 0;
    time_t curtime;
    struct tm *loc_time;
    curtime = time(NULL);
    loc_time = localtime(&curtime);
    printf("%s \n", asctime (loc_time));
    key = 's';

    while(1){

        while(!kbhit()){
            i += 2;
            Sleep(850);
            gotoXY(i, 30);
            printf("%c ", key);
        }

        key = getch();

        printf("%c ", key);


        fflush(stdin);
    }*/
    
    char playerone[20];
    char n;

    askName(playerone, n);

    printf("Your name is: %s \n", playerone);

    char *name = playerone;

    stampaNome(name);

    return 0;
}