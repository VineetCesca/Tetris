/* map è passato come parametro per righe e colonne ma basta specificare il numero delle colonne*/

int intro(){
    int opt;
    char c;
    do{
        system("cls");
        printTitle("WELCOME TO TETRIS GAME");
        printGameMenu();
        saltaRighe(1);
        printf("Select an option(0, 1, 2, 3): ");
    }while( ( (scanf("%d%c", &opt, &c) != 2 || c != '\n') && clean_stdin() == 1 ) || opt < 0 || opt > 3);

    return opt;

}

void initGame(int map[15][10], int width, int height, int avaiblep[6], int dim){
    initMap(map, width, height);
    initAvaiblePieces(avaiblep, dim);
}

void initScore(int *score){
    *score = 0;
}

int introS(int map[15][10], int width, int height, char *colorMode){
    int singleopt; 
    char c;
    setcolorText(colorMode, 1);
    do{
        system("cls");
        printTitle("SINGLE MODE");
        saltaRighe(2);
        printMapColor(map, width, height, "green", colorMode, 100);
        printSModeOptions();
        saltaRighe(1);
        printf("Select an option (0, 1, 2): ");
    }while( ( (scanf("%d%c", &singleopt, &c) != 2 || c != '\n') && clean_stdin() == 1 ) || singleopt < 0 || singleopt > 2);
    return singleopt;
}

void introSDynamic(int map[15][10], int width, int height, char* colorMode, int score){
    setcolorText(colorMode, 1);
    system("cls");
    printTitle("SINGLE MODE");
    saltaRighe(2);
    printMapColor(map, width, height, "green", colorMode, 100);
    saltaRighe(2);
    printScore(score, colorMode, 3);
    gotoXY(0, 25);
}

void introMP2(int map[15][10], int map1[15][10], int width, int height, char* colorMode, int score, int score1){
    setcolorText(colorMode, 1);
    system("cls");
    printTitle("MULTIPLAYER MODE");
    saltaRighe(2);
    /*printMapColor(map, width, height, "yellow", colorMode, 80);
    printMapColor(map1, width, height, "purple", colorMode, 115);*/
    printMaps(map, map1, width, height, "yellow", "purple", colorMode);
    saltaRighe(2);
    printScore(score, "yellow", 3);
    printScore(score1, "purple", 5);
    gotoXY(0, 25);
}

void updateAvPieces(int avaiblep[6], int selectedSM, int drawn){
    if(drawn == 0){
        avaiblep[selectedSM]++;
    }
}

void selectProcess(int avaiblep[6], int dim, int *selectedSM, int *rotation, 
                   int *drawn, int map[15][10], int width, int height, int x, int y){
    saltaRighe(1);
    printLegendaPieces();
    saltaRighe(1);
    printAvaiblePieces(avaiblep, dim);
    saltaRighe(1);
    printLegendaAllPieces(width, height, "blue");
    *selectedSM = selectPiece(avaiblep, dim); /*T = 0  Z = 1 I = 2  L = 3  Lr = 4  O = 5 */
    *rotation = selectRotation();
    *drawn = drawSelected(map, width, height, x, y, *selectedSM, *rotation);
    printf("drawn = %d\n", *drawn);
    Sleep(1000);
    updateAvPieces(avaiblep, *selectedSM, *drawn);
    printMapColor(map, width, height, "green", "blue", 100);
}

int avoidPieces(int map[15][10], int x, int sy, int selected, int rotation){

    int i;

    /* Istruzioni che non hanno bisogno del ciclo for (ottimizziamo il ciclo) */
    
    if( (selected == 0 && rotation == 2) && (map[sy + 1][x] == 1 
        || map[sy][x + 1] == 1 ) ){ /* ERRORE DELLA COLLISIONE DIRETTA */
            return 0;
    } else if(selected == 0 && rotation == 3 && (map[sy + 1][x + 1] == 1
        || map[sy][x] == 1) ){
            return 0;
    } else if(selected == 1 && rotation == 1 && (map[sy + 1][x] == 1
        || map[sy][x + 1] == 1) ){
            return 0;
    } else if(selected == 1 && rotation == 3 && (map[sy + 1][x + 1] == 1
        || map[sy][x] == 1) ){
            return 0;
    } else if(selected == 2 && (rotation == 0 || rotation == 2) && map[sy + 1][x] == 1){
        return 0;
    } else if(selected == 3 && rotation == 2 && (map[sy + 1][x + 1] == 1 || map[sy - 1][x] == 1) ){
        return 0;
    } else if(selected == 4 && rotation == 2 && (map[sy + 1][x] == 1 || map[sy - 1][x + 1] == 1) ){
        return 0;
    }

    /* Istruzioni che necessitano il ciclo for: 2 cicli o 3 cicli o 4 cicli */

    if(selected == 3 && rotation == 0){
        for(i = x; i < x + 2; i++){
            if(map[sy + 1][i] == 1){
                return 0;
            }
        }
    } else if(selected == 4 && rotation == 0){
        for(i = x; i < x + 2; i++){
            if(map[sy + 1][i] == 1){
                return 0;
            }
        }
    } else if(selected == 5){
        for(i = x; i < x + 2; i++){
            if(map[sy + 1][i] == 1){
                return 0;
            }
        }
    }

    if(selected == 2 && (rotation == 1 || rotation == 3) ){
        for(i = x; i < x + 4; i++){
            if(map[sy + 1][i] == 1){
                return 0;
            }
        }
    }

    for(i = x; i < x + 3; i++){
        if(selected == 0 && rotation == 0 && (map[sy + 1][x + 1] == 1
        || map[sy][i] == 1 && i != x + 1) ){
            return 0;
        } else if(selected == 0 && rotation == 1 && map[sy + 1][i] == 1){
            return 0;
        } else if(selected == 1 && rotation == 0 && ( (map[sy + 1][i] == 1 && i != x) 
        || (map[sy][x] == 1) ) ){
            return 0;
        } else if(selected == 1 && rotation == 2 && ( (map[sy + 1][i] == 1 && i != x + 2) 
        || map[sy][x + 2] == 1) ){
            return 0;
        } else if(selected == 3 && rotation == 1 && ( map[sy + 1][x] == 1 || (map[sy][i] == 1 && i != x) ) ){
            return 0;
        } else if(selected == 3 && rotation == 3 && map[sy + 1][i] == 1){
            return 0;
        } else if(selected == 4 && rotation == 1 &&  map[sy + 1][i] == 1){
            return 0;
        } else if(selected == 4 && rotation == 3 &&  (map[sy + 1][x + 2] == 1 || (map[sy][i] == 1 && i != x + 2) ) ){
            return 0;
        }
    }

    return 1;
}

int getLastCoords(int y, int selected, int rotation){
    /* ci da le coordinate corrette per il falldown
     in base al pezzo e alla rotazione: man mano che il pezzo cade, quindi y aumenta,
     allora anche la coordinata dell'ultimo 1 cambia */
    int sy;
    if(selected == 0){
        if(rotation == 0 || rotation == 1){
            sy = y + 1;
        } else if(rotation == 2 || rotation == 3){
            sy = y + 2;
        }
    } else if(selected == 1){
        if(rotation == 0 || rotation == 2){
            sy = y + 1;
        } else if(rotation == 1 || rotation == 3){
            sy = y + 2;
        }
    } else if(selected == 2){
        if(rotation == 0 || rotation == 2){
            sy = y + 3;
        } else if(rotation == 1 || rotation == 3){
            sy = y;
        }
    } else if(selected == 3){
        if(rotation == 0 || rotation == 2){
            sy = y + 2;
        } else if(rotation == 1 || rotation == 3){
            sy = y + 1;
        }
    } else if(selected == 4){
        if(rotation == 0 || rotation == 2){
            sy = y + 2;
        } else if(rotation == 1 || rotation == 3){
            sy = y + 1;
        }
    } else if(selected == 5){
        sy = y + 1;
    }

    return sy;
}

int getLastCoords1(int x, int selected, int rotation){
    /* ci da le coordinate corrette per il falldown
     in base al pezzo e alla rotazione: man mano che il pezzo cade, quindi y aumenta,
     allora anche la coordinata dell'ultimo 1 cambia */
    int sx;
    if(selected == 0){
        if(rotation == 0 || rotation == 1){
            sx = x + 2;
        } else if(rotation == 2 || rotation == 3){
            sx = x + 1;
        }
    } else if(selected == 1){
        if(rotation == 0 || rotation == 2){
            sx = x + 2;
        } else if(rotation == 1 || rotation == 3){
            sx = x + 1;
        }
    } else if(selected == 2){
        if(rotation == 0 || rotation == 2){
            sx = x;
        } else if(rotation == 1 || rotation == 3){
            sx = x + 3;
        }
    } else if(selected == 3){
        if(rotation == 0 || rotation == 2){
            sx = x + 1;
        } else if(rotation == 1 || rotation == 3){
            sx = x + 2;
        }
    } else if(selected == 4){
        if(rotation == 0 || rotation == 2){
            sx = x + 1;
        } else if(rotation == 1 || rotation == 3){
            sx = x + 2;
        }
    } else if(selected == 5){
        sx = x + 1;
    }

    return sx;
}

void fall(int map[15][10], int width, int height, int x, int y, int sy, int selected, int rotation, int score){
    if(sy < height - 2 && avoidPieces(map, x, sy, selected, rotation) == 1){
        introSDynamic(map, width, height, "blue", score);
        movebackSelected(map, width, height, x, y, selected, rotation);
        drawSelected(map, width, height, x, y + 1, selected, rotation);
    }

}

void fallDown(int map[15][10], int width, int height, int x, int y, int sy, int selected, int rotation, int *score){
     /* servono le coordinate x e y dell'ultima riga di 1 del pezzo considerato */
    do{
        if(sy < height - 2 && avoidPieces(map, x, sy, selected, rotation) == 1){ 
        /* devi capire che tu stai permettendo al pezzo di scendere anche 
        se è nell'ultima posizione possibile (height - 1) mentre se dici di mandare giù nella
        penultima sei apposto */
            updateScoreSM(map, width, height, score);
            introSDynamic(map, width, height, "blue", *score);
            movebackSelected(map, width, height, x, y, selected, rotation);
            drawSelected(map, width, height, x, y + 1, selected, rotation);
        } else {
            return;
        }
        y++;
        sy++;
    } while(sy < height - 2);
}



int movePiece(int map[15][10], int width, int height, int x, int y, int selectedSM, int rotation, int *released, int *score){

    int winning = 1;
    int sy;
    if(selectedSM >= 0 && selectedSM <= 5){
        char key;
        int esc = 0;
        int tempo;
        *released = 0;

        while(esc == 0){
            
            introSDynamic(map, width, height, "blue", *score);

            while(!kbhit()){
                sy = getLastCoords(y, selectedSM, rotation);
                if(sy < height - 2 && avoidPieces(map, x, sy, selectedSM, rotation) == 1){
                    delay(0.300); /* handle timing fall */
                    updateScoreSM(map, width, height, score);
                    introSDynamic(map, width, height, "blue", *score);
                    movebackSelected(map, width, height, x, y, selectedSM, rotation);
                    y++;
                    drawSelected(map, width, height, x, y, selectedSM, rotation);
                } else if(avoidPieces(map, x, sy, selectedSM, rotation) == 0){
                    gotoXY(100, 5);
                    printf("\n ENTER Q TO FALL \n"); /* user can decide if move the piece
                    before the final fall */
                } else if(sy == height - 2){
                    return 1;
                }
                
            }
  
            key = getch();
            saltaRighe(1);
            movebackSelected(map, width, height, x, y, selectedSM, rotation); /* ERRORE DELLA COLLISIONE DIRETTA */

            if(key == 'w'){ /* up arrow */
                if(rotation < 3 && getLastCoords1(x, selectedSM, rotation + 1) 
                    < width - 1 && getLastCoords(y, selectedSM, rotation + 1) < height - 1){
                    rotation++;
                } else if(rotation == 3 && getLastCoords1(x, selectedSM, 0) < width - 1
                           && getLastCoords(y, selectedSM, 0) < height - 1){
                    rotation = 0;
                } else { /* se vuole ruotarlo quando è vicino ai bordi della mappa, si sposta finchè può */
                    y--;
                    x--;
                }
                
            } else if(key == 's' && getLastCoords(y, selectedSM, rotation) < height - 2){ /* down arrow */
                y++;
            } else if(key == 'a' && x > 1){ /* left arrow */
                x--;
            } else if(key == 'd' && getLastCoords1(x, selectedSM, rotation) < width - 2){ /* right arrow */
                x++;
            } else if(key == 'q' || key == 'Q'){
                *released = 1;
                sy = getLastCoords(y, selectedSM, rotation);
                if(sy < height - 2 && avoidPieces(map, x, sy, selectedSM, rotation) == 1){
                    fallDown(map, width, height, x, y, sy, selectedSM, rotation, score);
                } else{
                    /* serve solo quando il pezzo è a terra oppure ha sotto altri pezzi: così non viene cancellato */
                    drawSelected(map, width, height, x, y, selectedSM, rotation); 
                }
                
                return 1;

            } else if(key == '0' && getLastCoords1(x, selectedSM, 0) < width - 2
                           && getLastCoords(y, selectedSM, 0) < height - 2){
                rotation = 0;
            } else if(key == '1' && getLastCoords1(x, selectedSM, 1) < width - 2
                           && getLastCoords(y, selectedSM, 1) < height - 2){
                rotation = 1;
            } else if(key == '2' && getLastCoords1(x, selectedSM, 2) < width - 2
                           && getLastCoords(y, selectedSM, 2) < height - 2){
                rotation = 2;
            } else if(key == '3' && getLastCoords1(x, selectedSM, 3) < width - 2
                           && getLastCoords(y, selectedSM, 3) < height - 2){
                rotation = 3;
            }

            
            winning = drawSelected(map, width, height, x, y, selectedSM, rotation);
            printMapColor(map, width, height, "green", "blue", 100);

            if(!winning){
                system("cls");
                setcolorText("red", 1);
                printTitle("COLLISION! GAME OVER!\n");
                Sleep(1500);
                setcolorText("white", 0);
                return 0;
            }
            //getch();
        }

        return 1;

    } else{
        printf("YOU NEED TO SELECT A PIECE BEFORE MOVING IT..\n");
    }
}


