#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

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
#include "Print.h"
#include "Logic.h"
#include "Cut.h"



int main(void){
    
    int map[15][10];
    int map1[15][10];
    int avaiblep[6];
    int avaiblepMP[6];

    int winning, winning1,
        x, y, 
        opt, singleopt, multiopt, 
        selectedSM, selectedMP, 
        rotation, rotation1, 
        drawn, drawn1, 
        released, released1,
        score, score1,
        won, won1;

    char player1[20], player2[20];

    loadGame();

    do{
        opt = intro();

        if(opt == 1){
            initGame(map, avaiblep, dim);
            setCursor(&x, &y, 4, 0);
            initScore(&score);
            do{
                won = 0;
                released = 0;
                updateScoreSM(map, &score);
                introSDynamic(map, colorSM, score);
                selectProcess(avaiblep, dim, &selectedSM, &rotation, &drawn, map, x, y, colorSM, colorSMPiece);
                winning = movePiece(map, x, y, selectedSM, rotation, &released, &score);
                checkEndGame(avaiblep, dim, &won);/*verifichiamo la disponibilità dei tetramini (condivisi) -> se non 
                ce ne sono più, bisogna concludere il gioco*/
            }while(winning != 0 && !won);

            setcolorText("white", 1); 
        }

        if(opt == 2){
            multiopt = whoEnemy();
            
            if(multiopt > 0){ /* p1 vs pc? p1 vs p2?*/
            /*Un giocatore perde la partita se non posiziona correttamente un pezzo nel proprio campo di gioco. Se i pezzi
            finiscono vince il giocatore con il punteggio più alto.*/
        
                won = 0; /* è bene ricordare che all'inizio nessuno dei due vince -> vince chi continua a fare punti */
                won1 = 0; /*il gioco va in crush se qualcuno fa scontrare i suoi tetramini, motivo per cui la partita termina
                            e si guarda al punteggio più alto*/
                initGameMP(map, map1, avaiblepMP, dim); /*un solo array avaibleMP perchè p1 e p2(pc) pescano dallo stesso insieme di tetramini
                rispetto al avaiblep in modalità singolo giocatore, hai il doppio dei tetramini (20*2) = 40 CODIVISI*/
                setCursor(&x, &y, 4, 0);
                initScore(&score);
                initScore(&score1);

                if(multiopt == 1){
                    
                    askName(player1, '1');

                    do{

                        gameOneVSPC(map, map1, x, y, &score, &score1, &drawn, &drawn1, &rotation, &rotation1, &released, &released1, &selectedSM, 
                                 &selectedMP, avaiblepMP, dim, &won, &won1, &winning, &winning1, colorMP, color1, color2, player1);

                    }while( (winning1 != 0 && !won1) && (winning != 0 && !won) );

                } else if(multiopt == 2){

                    askName(player1, '1');
                    askName(player2, '2');

                    do{

                        gameOneVSOne(map, map1, x, y, &score, &score1, &drawn, &drawn1, &rotation, &rotation1, &released, &released1, &selectedSM, 
                                 &selectedMP, avaiblepMP, dim, &won, &won1, &winning, &winning1, colorMP, color1, color2, player1, player2);

                    }while( (winning1 != 0 && !won1) && (winning != 0 && !won) );
                }

            }
             
            setcolorText("white", 1);
        }

        if(opt== 3){
            system("cls");
            setCursor(&x, &y, 0, 0);
            setcolorText("white", 1);
            printTitle("GAME INSTRUCTIONS\n");
            printMoveMenu(x, y, colorSM);            
            saltaRighe(4);
            gotoXY(0, 24);
            printLegendaPieces(colorSM, colorSMPiece);
            saltaRighe(4);
            printLegendaAllPieces(colorSM, colorSMPiece);
            gotoXY(0, 17);
            centerText(100);
            printf("ENTER ANYTHING TO GO BACK TO THE MENU: ");
            getch();
            setcolorText("white", 1);
        }

        if(opt == 0){
            system("cls");
            initMap(map);
            initMap(map1);
            fillOne(map);
            fillOne(map1);
            printMaps(map, map1, color1, color2, colorMP);
            setcolorText("white", 1);
            delay(1.5);
            closeGame();
        }

    }while(opt != 0);

    return 0;
}