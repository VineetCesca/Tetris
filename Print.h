void printMap(int map[15][10], int width, int height){
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

void printMapColor(int map[15][10], int width, int height, char *color1, char *color0){
    int i, j;
    for(i = 0; i < height; i++){
        centerText(100);
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

void printMap2(int map[15][10], int width, int height){
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

void printTitle(char *title){
    centerText(110);
    printf("%s", title);
    saltaRighe(3);
}

void printGameMenu(){
    printf("1 - SINGLE PLAYER\n");
    printf("2 - MULTIPLAYER\n");
    printf("0 - QUIT\n");
}

void printSModeOptions(){
    printf("1 - SELECT A PIECE\n");
    printf("2 - MOVE THE PIECE\n");
    printf("0 - Quit\n");
}

void printAvaiblePieces(int *pieces, int dim){ /* perchè stamparli tutti se te ne serve solo uno ogni volta che ne selezioni uno? */
    int i;
    for(i = 0; i < dim; i++){
        if(pieces[i] > 0){
            
            printf("Piece %d : ", i);
            setcolorText("green", 1);
            printf("%d\n", pieces[i]);
            setcolorText("blue", 1);

        } else {
            printf("Piece %d is not avaible! \n", i);
        }
    }
}

void printLegendaPieces(){
    printf("0 - ");
    setcolorText("green", 1);
    printf("T\n");
    setcolorText("blue", 1);
    printf("1 - ");
    setcolorText("green", 1);
    printf("Z\n");
    setcolorText("blue", 1);
    printf("2 - ");
    setcolorText("green", 1);
    printf("I\n");
    setcolorText("blue", 1);
    printf("3 - ");
    setcolorText("green", 1);
    printf("L\n");
    setcolorText("blue", 1);
    printf("4 - ");
    setcolorText("green", 1);
    printf("Lr\n");
    setcolorText("blue", 1);
    printf("5 - ");
    setcolorText("green", 1);
    printf("O\n");
    setcolorText("blue", 1);
}

void printLegendaAllPieces(int width, int height){ /* T = 0  Z = 1  I = 2  L = 3  Lr = 4  O = 5 */
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

    for(i = 0; i < 4; i++){
        gotoXY(gx - 11, 25 + i*4);
        printf("ROTATION: %d", i);
    }
    setcolorText("green", 1);
    for(k = 0; k < 84; k += 14){
        initMap(map, width, height);
        if(k == 0){
            f = drawT(map, width, height, x, y);
            f = drawT1(map, width, height, x, y + 3);
            f = drawT2(map, width, height, x, y + 6);
            f = drawT3(map, width, height, x, y + 10);
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
            f = drawZ(map, width, height, x, y);
            f = drawZ1(map, width, height, x, y + 3);
            f = drawZ2(map, width, height, x, y + 7);
            f = drawZ3(map, width, height, x, y + 10);
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
            f = drawI(map, width, height, x, y); /* T = 0  Z = 1  I = 2  L = 3  Lr = 4  O = 5 */
            f = drawI1(map, width, height, x - 1, y + 5);
            f = drawI(map, width, height, x, y + 7);
            f = drawI1(map, width, height, x - 1, y + 12);
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
            f = drawL(map, width, height, x, y); /* T = 0  Z = 1  I = 2  L = 3  Lr = 4  O = 5 */
            f = drawL1(map, width, height, x, y + 4);
            f = drawL2(map, width, height, x, y + 7);
            f = drawL3(map, width, height, x, y + 11);
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
            f = drawLr(map, width, height, x, y); /* T = 0  Z = 1  I = 2  L = 3  Lr = 4  O = 5 */
            f = drawLr1(map, width, height, x, y + 4);
            f = drawLr2(map, width, height, x, y + 7);
            f = drawLr3(map, width, height, x, y + 11);
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
            f = drawO(map, width, height, x, y); /* T = 0  Z = 1  I = 2  L = 3  Lr = 4  O = 5 */
            f = drawO(map, width, height, x, y + 4);
            f = drawO(map, width, height, x, y + 7);
            f = drawO(map, width, height, x, y + 11);
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
    setcolorText("blue", 1);
}

void printMoveMenu(int x, int y){
    printf("USE THE A-S-D KEYS TO MOVE THE PIECE AROUND THE MAP \n\n");
    printf("ENTER Q or q TO QUIT AND SET THE PIECE AT X:%d Y:%d POSITION \n\n", x, y);
    printf("ENTER W or 0-1-2-3 TO CHANGE THE PIECE ROTATION \n", x, y);
}

void printScore(int score){
    gotoXY(100, 3);
    setcolorText("green", 1);
    printf("SCORE: %d", score);
    setcolorText("blue", 1);
}

void dude(){
    printf("DUDE\n");
}
