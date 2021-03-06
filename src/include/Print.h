/**
 * @file Print.h
 * @brief Prints out everything to play a match
 * @author Vineet
 */

/**
 * Prints out the map (SinglePlayer)
 * @param[in] map game map
 * @see centerText()
 * @see saltaRighe()
 */
void printMap(int map[15][10]){
    int i, j;
    for(i = 0; i < height; i++){
        centerText(100);
        for(j = 0; j < width; j++){
            if(j == 0 || j == width - 1 || i == height - 1 || map[i][j] == 1){
                printf("%d ", map[i][j]);
            } else{
                printf("  ");
            }
        }
        printf("\n");
    }
    
    saltaRighe(3);
}

/**
 * Prints out the map in different colors (Multiplayer)
 * @param[in] map game map
 * @param[in] color1 piece color
 * @param[in] color0 map color
 * @param[in] center a value to set text position
 * @see centerText()
 * @see setcolorText()
 * @see saltaRighe()
 */
void printMapColor(int map[15][10], char *color1, char *color0, int center){
    int i, j;
    for(i = 0; i < height; i++){
        centerText(center);
        for(j = 0; j < width; j++){
            if(j == 0 || j == width - 1 || i == height - 1){
                setcolorText(color0, 1);
                printf("%d ", map[i][j]);
            } else if(map[i][j] == 1){
                setcolorText(color1, 1);
                printf("%d ", map[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    setcolorText(color0, 1);
    saltaRighe(3);
}

/**
 * Prints out two maps at the same time in different colors (Multiplayer)
 * @param[in] map game map
 * @param[in] map1 enemy's game map
 * @param[in] color1 piece color
 * @param[in] color2 enemy's piece color
 * @param[in] color0 map color
 * @see setcolorText()
 * @see gotoXY()
 * @see saltaRighe()
 */
void printMaps(int map[15][10], int map1[15][10], char *color1, char *color2, char *color0){
    int i, j;
    for(i = 0; i < height; i++){
        for(j = 0; j < width; j++){
            if(j == 0 || j == width - 1 || i == height - 1){
                setcolorText(color0, 1);
                gotoXY(40 + j*2, 7 + i);
                printf("%d ", map[i][j]);
                /* second map */
                gotoXY(70 + j*2, 7 + i);
                printf("%d ", map1[i][j]);

            } else if(map[i][j] == 1 || map1[i][j] == 1){
                if(map[i][j] == 1){
                    setcolorText(color1, 1);
                    gotoXY(40 + j*2, 7 + i);
                    printf("%d ", map[i][j]);
                }

                /* second map */
                if(map1[i][j] == 1){
                    setcolorText(color2, 1);
                    gotoXY(70 + j*2, 7 + i);
                    printf("%d ", map1[i][j]);
                }
            } else{
                printf("  ");
            }
        }
        printf("\n");
    }
    setcolorText(color0, 1);
    saltaRighe(3);
}

/**
 * Prints out the map in two colors
 * @param[in] map game map
 * @see centerText()
 * @see setcolorText()
 */
void printMap2(int map[15][10]){
    int i, j;
    for(i = 0; i < height; i++){
        centerText(100);
        for(j = 0; j < width; j++){
            if(map[i][j] == 1){
                setcolorText("red", 1);
            } else{
                setcolorText("white", 1);
            }
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

/**
 * Prints out a Title in the middle of the current line
 * @param[in] title title name
 * @see centerText()
 * @see saltaRighe()
 */
void printTitle(char *title){
    centerText(110);
    printf("%s", title);
    saltaRighe(3);
}

/**
 * Prints out the Main Game Menu
 */
void printGameMenu(){
    printf("1 - SINGLE PLAYER\n");
    printf("2 - MULTIPLAYER\n");
    printf("3 - GAME INSTRUCTIONS\n");
    printf("0 - QUIT\n");
}

/**
 * Prits out the SinglePlayer Game Menu
 */
void printSModeOptions(){
    printf("1 - SELECT A PIECE\n");
    printf("2 - MOVE THE PIECE\n");
    printf("0 - Quit\n");
}

/**
 * Prints out which pieces are avaible or not
 * @param[in] pieces pointer to avaiblepieces array
 * @param[in] dim avaible array's size
 * @param[in] colorMode text color
 * @param[in] colorPiece piece color
 * @see setcolorText()
 */
void printAvaiblePieces(int *pieces, int dim, char *colorMode, char *colorPiece){ /* perch?? stamparli tutti se te ne serve solo uno ogni volta che ne selezioni uno? */
    int i;
    for(i = 0; i < dim; i++){
        if(pieces[i] > 0){
            
            printf("Piece %d : ", i);
            setcolorText(colorPiece, 1);
            printf("%d\n", pieces[i]);
            setcolorText(colorMode, 1);

        } else {
            printf("Piece %d is not avaible! \n", i);
        }
    }
}

/**
 * Prints out the mini Legenda to match a number with each piece
 * @param[in] colorMode text color
 * @param[in] colorPiece piece color
 * @see setcolorText()
 */
void printLegendaPieces(char *colorMode, char *colorPiece){
    setcolorText(colorMode, 1);
    printf("0 - ");
    setcolorText(colorPiece, 1);
    printf("T\n");
    setcolorText(colorMode, 1);
    printf("1 - ");
    setcolorText(colorPiece, 1);
    printf("Z\n");
    setcolorText(colorMode, 1);
    printf("2 - ");
    setcolorText(colorPiece, 1);
    printf("I\n");
    setcolorText(colorMode, 1);
    printf("3 - ");
    setcolorText(colorPiece, 1);
    printf("L\n");
    setcolorText(colorMode, 1);
    printf("4 - ");
    setcolorText(colorPiece, 1);
    printf("Lr\n");
    setcolorText(colorMode, 1);
    printf("5 - ");
    setcolorText(colorPiece, 1);
    printf("O\n");
    setcolorText(colorMode, 1);
}

/**
 * Prints out the Full Legenda
 * @param[in] colorMode text color
 * @param[in] colorPiece piece color
 * @see gotoXY()
 * @see setcolorText()
 * @see initMap()
 * @see drawT
 * @see drawT1
 * @see drawT2
 * @see drawT3
 * @see drawZ
 * @see drawZ1
 * @see drawZ2
 * @see drawZ3
 * @see drawI
 * @see drawI1
 * @see drawL
 * @see drawL1
 * @see drawL2
 * @see drawL3
 * @see drawLr
 * @see drawLr1
 * @see drawLr2
 * @see drawLr3
 * @see drawO
 */
void printLegendaAllPieces(char *colorMode, char *colorPiece){ /* T = 0  Z = 1  I = 2  L = 3  Lr = 4  O = 5 */
    int i, j, k;
    int gx = 28, gy = 25;
    int f;
    int x = 4, y = 0;
    int map[15][10];

    for(k = 0; k < 84; k += 14){
        if(k == 0){
            gotoXY(gx + k + 8, gy - 2);
            printf("T");
        } else if(k == 14){
            gotoXY(gx + k + 8, gy - 2);
            printf("Z");
        } else if(k == 28){
            gotoXY(gx + k + 8, gy - 2);
            printf("I");
        } else if(k == 42){
            gotoXY(gx + k + 8, gy - 2);
            printf("L");
        } else if(k == 56){
            gotoXY(gx + k + 8, gy - 2);
            printf("Lr");
        } else if(k == 70){
            gotoXY(gx + k + 8, gy - 2);
            printf("O");
        }
    }

    setcolorText(colorMode, 1);
    for(i = 0; i < 4; i++){
        gotoXY(gx - 11, 25 + i*4);
        printf("ROTATION: %d", i);
    }
    setcolorText(colorPiece, 1);
    for(k = 0; k < 84; k += 14){
        initMap(map);
        if(k == 0){
            f = drawT(map, x, y);
            f = drawT1(map, x, y + 3);
            f = drawT2(map, x, y + 6);
            f = drawT3(map, x, y + 10);
            for(i = 0; i < height; i++){
                gotoXY(gx + k, gy + i);
                for(j = 0; j < width; j++){
                    if(map[i][j] == 1){
                        printf("%d ", map[i][j]);
                    } else{
                        printf("  ");
                    }  
                }
                printf("\n");
            }
            
        } else if(k == 14){ 
            f = drawZ(map, x, y);
            f = drawZ1(map, x, y + 3);
            f = drawZ2(map, x, y + 7);
            f = drawZ3(map, x, y + 10);
            for(i = 0; i < height; i++){
                gotoXY(gx + k, gy + i);
                for(j = 0; j < width; j++){
                    if(map[i][j] == 1){
                        printf("%d ", map[i][j]);
                    } else{
                        printf("  ");
                    }  
                }
                printf("\n");
            }

        } else if(k == 28){
            f = drawI(map, x, y); /* T = 0  Z = 1  I = 2  L = 3  Lr = 4  O = 5 */
            f = drawI1(map, x - 1, y + 5);
            f = drawI(map, x, y + 7);
            f = drawI1(map, x - 1, y + 12);
            for(i = 0; i < height; i++){
                gotoXY(gx + k, gy + i);
                for(j = 0; j < width; j++){
                    if(map[i][j] == 1){
                        printf("%d ", map[i][j]);
                    } else{
                        printf("  ");
                    }  
                }
                printf("\n");
            }

        } else if(k == 42){
            f = drawL(map, x, y); /* T = 0  Z = 1  I = 2  L = 3  Lr = 4  O = 5 */
            f = drawL1(map, x, y + 4);
            f = drawL2(map, x, y + 7);
            f = drawL3(map, x, y + 11);
            for(i = 0; i < height; i++){
                gotoXY(gx + k, gy + i);
                for(j = 0; j < width; j++){
                    if(map[i][j] == 1){
                        printf("%d ", map[i][j]);
                    } else{
                        printf("  ");
                    }  
                }
                printf("\n");
            }

        } else if(k == 56){
            f = drawLr(map, x, y); /* T = 0  Z = 1  I = 2  L = 3  Lr = 4  O = 5 */
            f = drawLr1(map, x, y + 4);
            f = drawLr2(map, x, y + 7);
            f = drawLr3(map, x, y + 11);
            for(i = 0; i < height; i++){
                gotoXY(gx + k, gy + i);
                for(j = 0; j < width; j++){
                    if(map[i][j] == 1){
                        printf("%d ", map[i][j]);
                    } else{
                        printf("  ");
                    }  
                }
                printf("\n");
            }            

        } else if(k == 70){
            f = drawO(map, x, y); /* T = 0  Z = 1  I = 2  L = 3  Lr = 4  O = 5 */
            f = drawO(map, x, y + 4);
            f = drawO(map, x, y + 7);
            f = drawO(map, x, y + 11);
            for(i = 0; i < height; i++){
                gotoXY(gx + k, gy + i);
                for(j = 0; j < width; j++){
                    if(map[i][j] == 1){
                        printf("%d ", map[i][j]);
                    } else{
                        printf("  ");
                    }  
                }
                printf("\n");
            } 
        }
    }
    setcolorText(colorMode, 1);
}

/**
 * Prints out the Move Menu: how to move the piece
 * @param[in] x current x coord.
 * @param[in] y current y coord.
 * @param[in] colorMode text color
 * @see setcolorText()
 * @see centerText()
 */
void printMoveMenu(int x, int y, char *colorMode){
    setcolorText(colorMode, 1);
    printf("HOW TO SELECT THE PIECE: \n\n");
    printf("   1- SELECT THE PIECE SHAPE TYPE: \n");
    centerText(100);
    printf("EACH LETTER IS ABBINED WITH A NUMBER: \n");
    centerText(100);
    printf(" T = 0, Z = 1,  I = 2, L = 3,  Lr = 4,  O = 5\n\n");
    printf("   2- SELECT THE PIECE ROTATION: \n");
    centerText(100);
    printf("YOU CAN CHOOSE A ROTATION FROM 0 TO 3\n\n");
    printf("HOW TO MOVE THE PIECE: \n\n");
    centerText(100);
    printf("USE THE A-D KEYS TO MOVE THE PIECE AROUND THE MAP \n\n");
    centerText(100);
    printf("USE THE W KEY TO ROTATE THE PIECE \n\n");
    centerText(100);
    printf("USE 0-1-2-3 TO SET THE EXACT ROTATION \n\n");
    centerText(100);
    printf("ENTER Q TO QUIT AND SET THE PIECE AT X:%d Y:%d POSITION \n\n", x, y);

}

/**
 * Prints out the player's score
 * @param[in] score current score
 * @param[in] colorMode text color
 * @param[in] y current y coord.
 * @param[in] player index
 * @param[in] name player's name
 * @see setcolorText()
 * @see gotoXY()
 */
void printScoreName(int score, char *colorMode, int y, char player, char name[20]){
    gotoXY(100, y);
    setcolorText(colorMode, 1);
    if(player == '1'){
        printf("SCORE %s: %d", name, score);
    } else if(player == '2'){
        printf("SCORE %s: %d", name, score);
    }
    setcolorText("blue", 1);
}

/**
 * Prints out the player's score
 * @param[in] score current score
 * @param[in] colorMode text color
 * @param[in] y current y coord.
 * @param[in] player index
 * @see setcolorText()
 * @see gotoXY()
 */
void printScore(int score, char *colorMode, int y, char player){
    gotoXY(100, y);
    setcolorText(colorMode, 1);
    printf("SCORE: %d", score);
    setcolorText("blue", 1);
}

/**
 * Prints out PC score
 * @param[in] score current score
 * @param[in] colorMode text color
 * @param[in] y current y coord.
 * @param[in] player index
 * @see setcolorText()
 * @see gotoXY()
 */
void printScorePC(int score, char *colorMode, int y, char player){
    gotoXY(100, y);
    setcolorText(colorMode, 1);
    printf("SCORE PC: %d", score);
    setcolorText("blue", 1);
}

/**
 * Prints out Winner interface
 * @param[in] name player's name
 * @see setcolorText()
 * @see centerText()
 * @see delay()
 */
void printWinner(char name[20]){
    system("cls");
    setcolorText("green", 1);
    centerText(100);
    printf("THE WINNER IS %s \n", name);
    delay(2.0); /*due . 0 secondi*/
    setcolorText("white", 1);
}

/**
 * Prints out Loser interface
 * @param[in] name player's name
 * @see setcolorText()
 * @see centerText()
 * @see delay()
 */
void printLoser(char name[20]){
    system("cls");
    setcolorText("red", 1);
    centerText(100);
    printf("%s LOOSE AGAINST PC", name);
    delay(2.0);
    setcolorText("white", 1);
}

/**
 * Prints out Winner interface
 * @see setcolorText()
 * @see printTitle()
 * @see delay()
 */
void printPareggio(){
    system("cls");
    setcolorText("yellow", 1);
    printTitle("DRAW");
    delay(2.0);
    setcolorText("white", 1);
}

