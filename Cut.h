/* map è passato come parametro per righe e colonne ma basta specificare il numero delle colonne*/

void stampaNome(char *playerone){
    printf("Your name is %s \n", playerone);
}

void askName(char name[20], char n){
    int a = 0;
    char confirm;

    do{

        system("cls");

        printf("Type player %c name: ", n);
        scanf("%s", name);

        printf("You've typed: %s, are you sure? (Y/N):", name);
        /*
          The %c conversion specifier won't automatically skip any leading whitespace, so if there's
          a stray newline in the input stream (from a previous entry, for example) the scanf call
          will consume it immediately.
          One way around the problem is to put a blank space before the conversion specifier
          in the format string:
          
          scanf(" %c", &c);
        
        */
        scanf(" %c", &confirm);

        if(confirm == 'y' || confirm == 'Y'){
            a = 1;
        }

    }while(a != 1);

}


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

void initGame(int map[15][10], int avaiblep[6], int dim){
    initMap(map);
    initAvaiblePieces(avaiblep, dim, 20);
}

void initGameMP(int map[15][10], int map1[15][10], int avaibleMP[6], int dim){
    initMap(map);
    initMap(map1);
    initAvaiblePieces(avaibleMP, dim, 40);
}

void initScore(int *score){
    *score = 0;
}

int introS(int map[15][10], char *colorMode){
    int singleopt; 
    char c;
    setcolorText(colorMode, 1);
    do{
        system("cls");
        printTitle("SINGLE MODE");
        saltaRighe(2);
        printMapColor(map, colorSMPiece, colorMode, 100);
        printSModeOptions();
        saltaRighe(1);
        printf("Select an option (0, 1, 2): ");
    }while( ( (scanf("%d%c", &singleopt, &c) != 2 || c != '\n') && clean_stdin() == 1 ) || singleopt < 0 || singleopt > 2);
    return singleopt;
}

void introSDynamic(int map[15][10], char* colorMode, int score){
    setcolorText(colorMode, 1);
    system("cls");
    printTitle("SINGLE MODE");
    saltaRighe(2);
    printMapColor(map, colorSMPiece, colorMode, 103);
    saltaRighe(2);
    printScorePC(score, colorSMPiece, 3, '1');
    gotoXY(0, 25);
}

void introMPDynamicName(int map[15][10], char *colorPiece, char* colorMode, int score, int center, char player, char name[20]){
    setcolorText(colorMode, 1);
    system("cls");
    printTitle("MULTIPLAYER MODE");
    saltaRighe(2);
    /*printMapColor(map, width, height, "yellow", colorMode, 80);
    printMapColor(map1, width, height, "purple", colorMode, 115);*/
    printMapColor(map, colorPiece, colorMode, center);
    saltaRighe(2);
    printScoreName(score, colorPiece, 3, player, name);
    gotoXY(0, 25);
}

void introMPDynamicPC(int map[15][10], char *colorPiece, char* colorMode, int score, int center, char player){
    setcolorText(colorMode, 1);
    system("cls");
    printTitle("MULTIPLAYER MODE");
    saltaRighe(2);
    /*printMapColor(map, width, height, "yellow", colorMode, 80);
    printMapColor(map1, width, height, "purple", colorMode, 115);*/
    printMapColor(map, colorPiece, colorMode, center);
    saltaRighe(2);
    printScorePC(score, colorPiece, 3, player);
    gotoXY(0, 25);
}

void introMP2PC(int map[15][10], int map1[15][10], char* colorMode, int *score, int *score1,
             char *color1, char *color2, char name[20]){
    int invert;
    setcolorText(colorMode, 1);
    system("cls");
    printTitle("MULTIPLAYER MODE");
    
    /*printMapColor(map, width, height, "yellow", colorMode, 80);
    printMapColor(map1, width, height, "purple", colorMode, 115);*/
    invert = updateScoreMP2(map, score);

    if(invert >= 2){
        invertEnemy(map1, invert);
    }

    invert = updateScoreMP2(map1, score1);

    if(invert >= 2){
        invertEnemy(map, invert);
    }
    
    printMaps(map, map1, color1, color2, colorMode);
    printScoreName(*score, color1, 3, '1', name);
    printScorePC(*score1, color2, 5, '0');
    
    gotoXY(0, 25);
    
}

void introMP2(int map[15][10], int map1[15][10], char* colorMode, int *score, int *score1,
             char *color1, char *color2, char name1[20], char name2[20]){
    int invert;
    setcolorText(colorMode, 1);
    system("cls");
    printTitle("MULTIPLAYER MODE");
    
    /*printMapColor(map, width, height, "yellow", colorMode, 80);
    printMapColor(map1, width, height, "purple", colorMode, 115);*/
    invert = updateScoreMP2(map, score);

    if(invert >= 2){
        invertEnemy(map1, invert);
    }

    invert = updateScoreMP2(map1, score1);

    if(invert >= 2){
        invertEnemy(map, invert);
    }
    
    printMaps(map, map1, color1, color2, colorMode);
    printScoreName(*score, color1, 3, '1', name1);
    printScoreName(*score1, color2, 5, '2', name2);
    
    gotoXY(0, 25);
    
}

void updateAvPieces(int avaiblep[6], int selectedSM, int drawn){
    if(drawn == 0){
        avaiblep[selectedSM]++;
    }
}

void selectProcess(int avaiblep[6], int dim, int *selectedSM, int *rotation, 
                   int *drawn, int map[15][10], int x, int y,
                   char *colorMode, char *colorPiece){
    saltaRighe(1);
    printLegendaPieces(colorMode, colorPiece);
    saltaRighe(1);
    printAvaiblePieces(avaiblep, dim, colorMode, colorPiece);
    saltaRighe(1);
    printLegendaAllPieces(colorMode, colorPiece);
    *selectedSM = selectPiece(avaiblep, dim, colorPiece); /*T = 0  Z = 1 I = 2  L = 3  Lr = 4  O = 5 */
    *rotation = selectRotation(colorPiece);
    *drawn = drawSelected(map, x, y, *selectedSM, *rotation);
    printf("drawn = %d\n", *drawn);
    delay(0.5);
    updateAvPieces(avaiblep, *selectedSM, *drawn);
    gotoXY(0, 25);
}

void selectProcessPC(int avaiblep[6], int dim, int *selectedSM, int *rotation, 
                   int *drawn, int map[15][10], int x, int y,
                   char *colorMode, char *colorPiece){
    saltaRighe(1);
    printLegendaPieces(colorMode, colorPiece);
    saltaRighe(1);
    printAvaiblePieces(avaiblep, dim, colorMode, colorPiece);
    saltaRighe(1);
    printLegendaAllPieces(colorMode, colorPiece);
    *selectedSM = rand()% 6; /*T = 0  Z = 1 I = 2  L = 3  Lr = 4  O = 5 */
    *rotation = rand() % 4; /* random rotation from 0 to 3 -> don't need to initialize rand() because this
    function will be recalled everytime with random values */
    *drawn = drawSelected(map, x, y, *selectedSM, *rotation);
    printf("drawn = %d\n", *drawn);
    delay(1.5);
    updateAvPieces(avaiblep, *selectedSM, *drawn);
    gotoXY(0, 25);
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

void fall(int map[15][10], int x, int y, int sy, int selected, int rotation, int score, char player){
    if(sy < height - 2 && avoidPieces(map, x, sy, selected, rotation) == 1){
        introSDynamic(map, colorSM, score);
        movebackSelected(map, x, y, selected, rotation);
        drawSelected(map, x, y + 1, selected, rotation);
    }

}

void fallDown(int map[15][10], int x, int y, int sy, int selected, int rotation, int *score){
     /* servono le coordinate x e y dell'ultima riga di 1 del pezzo considerato */
    do{
        if(sy < height - 2 && avoidPieces(map, x, sy, selected, rotation) == 1){ 
        /* devi capire che tu stai permettendo al pezzo di scendere anche 
        se è nell'ultima posizione possibile (height - 1) mentre se dici di mandare giù nella
        penultima sei apposto */
            updateScoreSM(map, score);
            introSDynamic(map, colorSM, *score);
            movebackSelected(map, x, y, selected, rotation);
            drawSelected(map, x, y + 1, selected, rotation);
        } else {
            return;
        }
        y++;
        sy++;
    } while(sy < height - 2);
}

void fallDownMP(int map[15][10], int mapEnemy[15][10], int x, int y, int sy, int selected, int rotation, int *score,
                 char *colorPiece, char *colorMode, int center, char player, char name[20]){
    /* servono le coordinate x e y dell'ultima riga di 1 del pezzo considerato */
    int invert;

    do{
        if(sy < height - 2 && avoidPieces(map, x, sy, selected, rotation) == 1){ 
        /* devi capire che tu stai permettendo al pezzo di scendere anche 
        se è nell'ultima posizione possibile (height - 1) mentre se dici di mandare giù nella
        penultima sei apposto */
            invert = updateScoreMP2(map, score);
            if(invert >= 2){
                invertEnemy(mapEnemy, invert);
            }
            if(player != '0'){
                introMPDynamicName(map, colorPiece, colorMode, *score, center, player, name);
            } else {
                introMPDynamicPC(map, colorPiece, colorMode, *score, center, player);
            }
            movebackSelected(map, x, y, selected, rotation);
            drawSelected(map, x, y + 1, selected, rotation);
        } else {
            return;
        }
        y++;
        sy++;
    } while(sy < height - 2);
}



int movePiece(int map[15][10], int x, int y, int selectedSM, int rotation, int *released, int *score){

    int winning = 1;
    int sy;
    if(selectedSM >= 0 && selectedSM <= 5){
        char key;
        int esc = 0;
        float tempo = 0.300; /* handle delay time fall */
        *released = 0;

        while(esc == 0){
            
            introSDynamic(map,  colorSM, *score);

            while(!kbhit()){
                sy = getLastCoords(y, selectedSM, rotation);
                if(sy < height - 2 && avoidPieces(map, x, sy, selectedSM, rotation) == 1){
                    delay(tempo); 
                    updateScoreSM(map, score);
                    introSDynamic(map, colorSM, *score);
                    movebackSelected(map, x, y, selectedSM, rotation);
                    y++;
                    drawSelected(map, x, y, selectedSM, rotation);
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
            movebackSelected(map, x, y, selectedSM, rotation); /* ERRORE DELLA COLLISIONE DIRETTA */

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
                    fallDown(map, x, y, sy, selectedSM, rotation, score);
                } else{
                    /* serve solo quando il pezzo è a terra oppure ha sotto altri pezzi: così non viene cancellato */
                    drawSelected(map, x, y, selectedSM, rotation); 
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

            fflush(stdin); /*  risolve parzialmente il blocco causato dallo spam di movimenti */

            winning = drawSelected(map, x, y, selectedSM, rotation);
            printMapColor(map, colorSMPiece, colorSM, 100);

            if(!winning){
                system("cls");
                setcolorText(colorMP, 1);
                printTitle("COLLISION! GAME OVER!\n");
                delay(1.5);
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

int movePieceMP(int map[15][10], int mapEnemy[15][10], int x, int y, int selectedMP, int rotation, int *released, int *score, 
                char *colorMode, char *colorPiece, int center, char player, char name[20]){

    int winning = 1;
    int sy;
    if(selectedMP >= 0 && selectedMP <= 5){
        char key;
        int esc = 0;
        float tempo = 0.300; /* handle delay time fall */
        *released = 0;

        while(esc == 0){
            
            int invert;

            invert = updateScoreMP2(map, score); 

            if(invert >= 2){
                invertEnemy(mapEnemy, invert);
            }

            if(player != '0'){
                introMPDynamicName(map, colorPiece, colorMode, *score, center, player, name);
            } else {
                introMPDynamicPC(map, colorPiece, colorMode, *score, center, player);
            }
            
                    
            while(!kbhit()){

                sy = getLastCoords(y, selectedMP, rotation);

                invert = updateScoreMP2(map, score); 
                if(invert >= 2){
                    invertEnemy(mapEnemy, invert);
                }
                
                if(sy < height - 2 && avoidPieces(map, x, sy, selectedMP, rotation) == 1){
                    delay(tempo); /* handle timing fall */
                    if(player != '0'){
                        introMPDynamicName(map, colorPiece, colorMode, *score, center, player, name);  
                    } else {
                        introMPDynamicPC(map, colorPiece, colorMode, *score, center, player);  
                    }
                    movebackSelected(map, x, y, selectedMP, rotation);
                    y++;
                    drawSelected(map, x, y, selectedMP, rotation);
                } else if(avoidPieces(map, x, sy, selectedMP, rotation) == 0){
                    gotoXY(100, 5);
                    printf("\n ENTER Q TO FALL \n"); /* user can decide if move the piece
                    before the final fall */
                } else if(sy == height - 2){
                    return 1;
                }
                
            }
  
            key = getch();
            /*if(sizeof(key) > sizeof(char)){
                do{
                    key = getch();
                } while (sizeof(key) > sizeof(char));
                
            }*/
            saltaRighe(1);
            movebackSelected(map, x, y, selectedMP, rotation); /* ERRORE DELLA COLLISIONE DIRETTA */

            if(key == 'w'){ /* up arrow */
                if(rotation < 3 && getLastCoords1(x, selectedMP, rotation + 1) 
                    < width - 1 && getLastCoords(y, selectedMP, rotation + 1) < height - 1){
                    rotation++;
                } else if(rotation == 3 && getLastCoords1(x, selectedMP, 0) < width - 1
                           && getLastCoords(y, selectedMP, 0) < height - 1){
                    rotation = 0;
                } else { /* se vuole ruotarlo quando è vicino ai bordi della mappa, si sposta finchè può */
                    y--;
                    x--;
                }
                
            } else if(key == 's' && getLastCoords(y, selectedMP, rotation) < height - 2){ /* down arrow */
                y++;
            } else if(key == 'a' && x > 1){ /* left arrow */
                x--;
            } else if(key == 'd' && getLastCoords1(x, selectedMP, rotation) < width - 2){ /* right arrow */
                x++;
            } else if(key == 'q' || key == 'Q'){
                *released = 1;
                sy = getLastCoords(y, selectedMP, rotation);
                if(sy < height - 2 && avoidPieces(map, x, sy, selectedMP, rotation) == 1){
                    fallDownMP(map, mapEnemy, x, y, sy, selectedMP, rotation, score, colorPiece, colorMode, center, player, name);
                } else{
                    /* serve solo quando il pezzo è a terra oppure ha sotto altri pezzi: così non viene cancellato */
                    drawSelected(map, x, y, selectedMP, rotation); 
                }
                
                return 1;

            } else if(key == '0' && getLastCoords1(x, selectedMP, 0) < width - 2
                           && getLastCoords(y, selectedMP, 0) < height - 2){
                rotation = 0;
            } else if(key == '1' && getLastCoords1(x, selectedMP, 1) < width - 2
                           && getLastCoords(y, selectedMP, 1) < height - 2){
                rotation = 1;
            } else if(key == '2' && getLastCoords1(x, selectedMP, 2) < width - 2
                           && getLastCoords(y, selectedMP, 2) < height - 2){
                rotation = 2;
            } else if(key == '3' && getLastCoords1(x, selectedMP, 3) < width - 2
                           && getLastCoords(y, selectedMP, 3) < height - 2){
                rotation = 3;
            }

            fflush(stdin); /*  risolve parzialmente il blocco causato dallo spam di movimenti */

            winning = drawSelected(map, x, y, selectedMP, rotation);
            printMapColor(map, colorPiece, colorMode, center);


            if(!winning){
                system("cls");
                setcolorText("red", 1);
                printTitle("COLLISION! GAME OVER!\n");
                delay(1.5);
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


void gameOneVSOne(int map[15][10], int map1[15][10], int x, int y, int *score, int *score1, int *drawn,
              int *drawn1, int *rotation, int *rotation1, int *released, int *released1, int *selectedSM, int *selectedMP,
              int avaiblepMP[6], int dim, int *won, int *won1, int *winning, int *winning1, char *colorMode, 
              char *color1, char *color2, char name1[20], char name2[20]){

    introMP2(map, map1, colorMode, score, score1, color1, color2, name1, name2);

    *released = 0;

    selectProcess(avaiblepMP, dim, selectedSM, rotation, drawn, map, x, y, colorMode, color1);

    *winning = movePieceMP(map, map1, x, y, *selectedSM, *rotation, released, score, colorMode, color1, 80, '1', name1);

    checkWin(avaiblepMP, dim, won);

    introMP2(map, map1, colorMode, score, score1, color1, color2, name1, name2);

    *released1 = 0;

    selectProcess(avaiblepMP, dim, selectedMP, rotation1, drawn1, map1, x, y, colorMode, color2);

    *winning1 = movePieceMP(map1, map, x, y, *selectedMP, *rotation1, released1, score1, colorMode, color2, 150, '2', name2);

    checkWin(avaiblepMP, dim, won1);

}

void gameOneVSPC(int map[15][10], int map1[15][10], int x, int y, int *score, int *score1, int *drawn,
              int *drawn1, int *rotation, int *rotation1, int *released, int *released1, int *selectedSM, int *selectedMP,
              int avaiblepMP[6], int dim, int *won, int *won1, int *winning, int *winning1, char *colorMode, 
              char *color1, char *color2, char name[20]){

    introMP2PC(map, map1, colorMode, score, score1, color1, color2, name);

    *released = 0;

    selectProcess(avaiblepMP, dim, selectedSM, rotation, drawn, map, x, y, colorMode, color1);

    *winning = movePieceMP(map, map1, x, y, *selectedSM, *rotation, released, score, colorMode, color1, 80, '1', name);

    checkWin(avaiblepMP, dim, won);

    introMP2PC(map, map1, colorMode, score, score1, color1, color2, name);

    *released1 = 0;

    selectProcessPC(avaiblepMP, dim, selectedMP, rotation1, drawn1, map1, x, y, colorMode, color2);

    *winning1 = movePieceMP(map1, map, x, y, *selectedMP, *rotation1, released1, score1, colorMode, color2, 150, '0', name);

    checkWin(avaiblepMP, dim, won1);

}


