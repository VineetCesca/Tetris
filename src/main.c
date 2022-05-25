/**
 * @file main.c
 * @brief wrap all the things
 * @author Vineet
 * @mainpage X-Tetris
 * @section Intro
 * X-Tetris game implementantion in ANSI C
 * @section Dependencies
 *
 * <ul>
 *      <li>MinGW (for windows users)</li>
 * </ul>
 *
 * @section Installation
 * <ol>
 *      <li>
 *          Download the repository
 *          <br />
 *          <code>git clone https://github.com/VineetCesca/Tetris</code>
 *      </li>
 *      <li>
 *          Install every dependecies
 *      </li>
 *      <li>
 *          Go into the repository folder and then change directory
 *          <br />
 *          <code>cd src</code>
 *      </li>
 *      <li>
 *          Compile and run the game
 *          <br />
 *          <code>gcc main.c -o main -ansi && ./main</code>
 *      </li>
 * </ol>
 *
 * @section Commands
 * Here the complete list of commands for the game. First of all you can select the game mode by input: <code>1</code> SinglePlayer, <code>2</code> MultiPlayer, <code>3</code> Game Instructions and <code>0</code> Quit.
 * If you have selected Multiplayer Game Mode, you need to specify how many players are going to play by input: <code>1</code> 1 vs PC, <code>2</code> 1 vs 1, <code>0</code> Main Menu.
 * Once you are playing a match, when it's your turn, you have to select a tetramino by input: <code>0</code> tetramino T, <code>1</code> tetramino Z , <code>2</code> tetramino I, <code>3</code> tetramino L, <code>4</code> tetramino Lr and <code>5</code> tetramino O.
 * Then you need to specify the rotation by input: <code>0</code>, <code>1>/code>, <code>2</code>, <code>3</code>.
 * You need to follow the Legenda to understand the exact tetramino shape and rotation you are choosing.
 * When you join the game, here is a list of complete commands:
 *
 * <ul>
 *      <li><code>W</code>: rotate tetramino</li>
 *      <li><code>A</code>: move left</li>
 *      <li><code>D</code>: move right</li>
 *      <li><code>S</code>: move down</li>
 *      <li><code>Q</code>: Release tetramino, make it fall</li>
 * </ul>
 *
 * The commands are the <b>same</b> for both of the two game modes avaible.
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

/**
 * Map height
 */
const int height = 15;
/**
 * Map width
 */
const int width = 10;
/**
 * Number of pieces and avaible array's size
 */
const int dim = 6; /* T, I, O, Z, L, Lr */
/**
 * Map color in SinglePlayer
 */
char *colorSM = "blue";
/**
 * Piece color in SinglePlayer
 */
char *colorSMPiece = "green";
/**
 * Map color in MultiPlayer
 */
char *colorMP = "red";
/**
 * Player1 piece color
 */
char *color1 = "yellow";
/**
 * Player2 or PC piece color
 */
char *color2 = "purple";


#include "include/TextSettings.h"
#include "include/Initializer.h"
#include "include/DrawPieces.h"
#include "include/Extra.h"
#include "include/Print.h"
#include "include/Logic.h"
#include "include/Cut.h"

/**
 * Main Function, contains the main game loop
 * @param[in] void
 * @param[out] 0
 * @see loadGame()
 * @see intro()
 * @see initGame()
 * @see setCursor()
 * @see initScore()
 * @see updateScoreSM()
 * @see introSDynamic()
 * @see selectProcess()
 * @see movePiece()
 * @see checkEndGame()
 * @see setcolorText()
 * @see whoEnemy()
 * @see initGameMP()
 * @see askName()
 * @see gameOneVSPC()
 * @see gameOneVSOne()
 * @see printTitle()
 * @see printMoveMenu()
 * @see saltaRighe()
 * @see gotoXY()
 * @see printLegendaPieces()
 * @see printLegendaAllPieces()
 * @see centerText()
 * @see initMap()
 * @see fillOne()
 * @see printMaps()
 * @see delay()
 * @see closeGame()
 */ 
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