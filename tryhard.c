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
    int map1[15][10];
    int height, width;
    height = 15;
    width = 10;
    int winning, winning1;
    int x, y, x1, y1;
    int opt, singleopt, multiopt;
    int avaiblep[6], avaiblep1[6];
    int dim;
    dim = 6; /* T, I, O, Z, L, Lr */
    int selectedSM, selectedMP;
    int rotation, rotation1;
    int drawn, drawn1;
    int released, released1;
    released = 0;
    released1 = 0;
    int score, score1;
    int won, won1;
    won = 0; 
    won1 = 0;


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
                selectProcess(avaiblep, dim, &selectedSM, &rotation, &drawn, map, width, height, x, y, "blue", "green");
                winning = movePiece(map, width, height, x, y, selectedSM, rotation, &released, &score);
                checkWin(avaiblep, dim, &won);
            }while(winning != 0 && !won);

            setcolorText("white", 1); 
        }

        if(opt == 2){
            multiopt = whoEnemy();
            
            if(multiopt != 0){ /* p1 vs pc? p1 vs p2?*/

                initGame(map, width, height, avaiblep, dim);
                initGame(map1, width, height, avaiblep1, dim);
                setCursor(&x, &y, 4, 0);
                setCursor(&x1, &y1, 4, 0);
                initScore(&score);
                initScore(&score1);

                if(multiopt == 1){

                } else if(multiopt == 2){
                    do{

                        introMP2(map, map1, width, height, "red", score, score1, "yellow", "purple");

                        released = 0;

                        selectProcess(avaiblep, dim, &selectedSM, &rotation, &drawn, map, width, height, x, y, "red", "yellow");

                        winning = movePieceMP(map, width, height, x, y, selectedSM, rotation, &released, &score, "red", "yellow", 80);

                        introMP2(map, map1, width, height, "red", score, score1,  "yellow", "purple");

                        checkWin(avaiblep, dim, &won);

                        released1 = 0;

                        selectProcess(avaiblep1, dim, &selectedMP, &rotation1, &drawn1, map1, width, height, x1, y1, "red", "purple");

                        winning1 = movePieceMP(map1, width, height, x1, y1, selectedMP, rotation1, &released1, &score1, "red", "purple", 150);

                        introMP2(map, map1, width, height, "red", score, score1,  "yellow", "purple");

                        checkWin(avaiblep1, dim, &won1);

                    }while( (winning1 != 0 && !won1) && (winning != 0 && !won));
                }

            }
             
            setcolorText("white", 1);
        }

        if(opt== 3){
            system("cls");
            setCursor(&x, &y, 0, 0);
            setcolorText("white", 1);
            printTitle("GAME INSTRUCTIONS\n");
            printMoveMenu(x, y, "blue");            
            saltaRighe(4);
            gotoXY(0, 24);
            printLegendaPieces("blue", "green");
            saltaRighe(4);
            printLegendaAllPieces(width, height, "blue", "green");
            gotoXY(0, 17);
            centerText(100);
            printf("ENTER ANYTHING TO GO BACK TO THE MENU: ");
            getch();
            setcolorText("white", 1);
        }

        if(opt == 0){
            system("cls");
            initMap(map, width, height);
            initMap(map1, width, height);
            fillOne(map, width, height);
            fillOne(map1, width, height);
            printMaps(map, map1, width, height, "yellow", "purple", "red");
            setcolorText("white", 1);
            Sleep(1500);
            closeGame();
        }

    }while(opt != 0);

    return 0;
}