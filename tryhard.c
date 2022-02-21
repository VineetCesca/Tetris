#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#include "TextSettings.h"
#include "Initializer.h"
#include "DrawPieces.h"
#include "Extra.h"
#include "Logic.h"
#include "Print.h"
#include "Cut.h"



int main(void){
    
    int i, j;
    int map[15][10];
    int height, width;
    height = 15;
    width = 10;
    int winning;
    int x, y;
    int opt, singleopt, multiopt;
    int avaiblep[6];
    int dim;
    dim = 6; /* T, I, O, Z, L, Lr */
    int selectedSM;
    selectedSM;
    int rotation;
    int drawn;
    int released = 0;
    int score;
    int won = 0;

    loadGame();

    do{
        opt = intro();

        if(opt == 1){
            initGame(map, width, height, avaiblep, dim);
            setCursor(&x, &y, 4, 0);
            initScore(&score);
            do{
                released = 0;
                updateScoreSM(map, width, height, &score);
                introSDynamic(map, width, height, "blue", score);
                selectProcess(avaiblep, dim, &selectedSM, &rotation, &drawn, map, width, height, x, y);
                saltaRighe(2);
                winning = movePiece(map, width, height, x, y, selectedSM, rotation, &released, &score);
                checkWin(avaiblep, dim, &won);
            }while(winning != 0 && !won);

            setcolorText("white", 1); 
        }

        if(opt == 2){
            setcolorText("red", 1);
            opt = 0;
        }

        if(opt== 3){
            system("cls");
            setCursor(&x, &y, 0, 0);
            setcolorText("white", 1);
            printTitle("GAME INSTRUCTIONS\n");
            printMoveMenu(x, y, "blue");            
            saltaRighe(4);
            gotoXY(0, 24);
            printLegendaPieces();
            saltaRighe(4);
            printLegendaAllPieces(width, height, "blue");
            gotoXY(0, 17);
            centerText(100);
            printf("ENTER ANYTHING TO GO BACK TO THE MENU: ");
            getch();
            setcolorText("white", 1);
        }

        if(opt == 0){
            system("cls");
            initMap(map, width, height);
            fillOne(map, width, height);
            printMap2(map, width, height);
            setcolorText("white", 1);
            Sleep(1500);
            closeGame();
        }

    }while(opt != 0);

    return 0;
}