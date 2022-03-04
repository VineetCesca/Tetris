#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#include <process.h>

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
    selectedSM = -1;
    int rotation;
    int drawn;
    int released = 0;
    int score = 0;
    int won = 0;

    loadGame();

    do{
        opt = intro();

        if(opt == 1){

            initGame(map, width, height, avaiblep, dim);
            setCursor(&x, &y, 4, 0);
            initScore(&score);
            do{

                singleopt = introS(map, width, height, "blue");

                if(singleopt == 1){
                    
                    selectProcess(avaiblep, dim, &selectedSM, &rotation, &drawn, map, width, height, x, y, "blue", "green");                    
                    released = 0;

                } else if(singleopt == 2){
                    if(released == 0){
                        winning = movePiece(map, width, height, x, y, selectedSM, rotation, &released, score);
                        if(!winning){
                            singleopt = 0;
                        }
                    } else {
                        printf("\nYou already have realeased the piece. pls select a new piece! \n");
                        Sleep(1500);
                    }
                }

            }while(singleopt != 0);

            setcolorText("white", 1);
            
        }

        if(opt == 2){
            setcolorText("red", 1);
            opt = 0;
        }

        if(opt == 0){
            system("cls");
            printMap2(map, width, height);
            setcolorText("white", 1);
            Sleep(1500);
            closeGame();
        }

    }while(opt != 0);

    return 0;
}