/**
 * Prints out the player's name
 * @param[out] playerone char pointer
 */ 
void stampaNome(char *playerone){
    printf("Your name is %s \n", playerone);
}

/**
 * Asks to player 1 or 2 to type the name 
 * and stores it and 
 * then asks to confirm
 * @param[out] name array of 20 chars
 * @param[in] n index: player1 or player2
 */ 
void askName(char name[20], char n){
    int a = 0;
    char confirm;

    do{

        system("cls");

        printf("Type player %c name: ", n);
        scanf("%s", name);

        printf("You've typed: %s, are you sure? (Y/N):", name);
        
        scanf(" %c", &confirm);

        if(confirm == 'y' || confirm == 'Y'){
            a = 1;
        }

    }while(a != 1);

}

/**
 * Prints out the Main Game Menu and asks
 * the user to choose an option
 * @return opt: game option which the user has selected
 */
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

/** 
 * Initialize a match in SinglePlayer
 * @param[out] map game map
 * @param[out] avaiblep avaible pieces
 * @param[in] dim avaiblep array's size
 * @see initMap()
 * @see initAvaiblePieces()
 */
void initGame(int map[15][10], int avaiblep[6], int dim){
    initMap(map);
    initAvaiblePieces(avaiblep, dim, 20);
}

/** 
 * Initialize a match in MultiPlayer
 * @param[out] map game map of player1
 * @param[out] map1 game map of player2
 * @param[out] avaiblep avaible pieces (shared)
 * @param[in] dim avaiblep array's dimension
 * @see initMap()
 * @see initAvaiblePieces()
 */
void initGameMP(int map[15][10], int map1[15][10], int avaibleMP[6], int dim){
    initMap(map);
    initMap(map1);
    initAvaiblePieces(avaibleMP, dim, 40);
}

/** 
 * Initialize the score of a match
 * @param[out] score score of player 1 or player 2 or PC
 */
void initScore(int *score){
    *score = 0;
}

/** 
 * Prints out the SinglePlayer Game Menu
 * and asks the user to choose an option
 * @param[in] map game map
 * @param[in] colorMode text color
 * @return singleopt: option selected
 * @see setcolorText()
 * @see printTitle()
 * @see printMapColor()
 * @see printSModeOptions()
 * @see saltaRighe()
 */
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

/** 
 * Prints out the SinglePlayer interface
 * while the piece (tetramino) is moving
 * inside the map
 * @param[in] map game map
 * @param[in] colorMode text color
 * @param[in] score current score
 * @see setcolorText()
 * @see printTitle()
 * @see printMapColor()
 * @see printSModeOptions()
 * @see saltaRighe()
 * @see printScore()
 * @see gotoXY()
 */
void introSDynamic(int map[15][10], char* colorMode, int score){
    setcolorText(colorMode, 1);
    system("cls");
    printTitle("SINGLE MODE");
    saltaRighe(2);
    printMapColor(map, colorSMPiece, colorMode, 103);
    saltaRighe(2);
    printScore(score, colorSMPiece, 3, '1');
    gotoXY(0, 25);
}

/**
 * Prints out the MultiPlayer (1 vs 1) interface
 * while the player 1 or 2 is moving the piece
 * inside the map
 * @param[in] map game map
 * @param[in] colorPiece map color
 * @param[in] colorMode text color
 * @param[in] score current score
 * @param[in] center a value to set the text position
 * @param[in] player index player 1 or 2
 * @param[in] name player's name
 * @see setcolorText()
 * @see printTitle()
 * @see printMapColor()
 * @see saltaRighe()
 * @see printScoreName()
 * @see gotoXY()
 */
void introMPDynamicName(int map[15][10], char *colorPiece, char* colorMode, int score, int center, char player, char name[20]){
    setcolorText(colorMode, 1);
    system("cls");
    printTitle("MULTIPLAYER MODE");
    saltaRighe(2);
    printMapColor(map, colorPiece, colorMode, center);
    saltaRighe(2);
    printScoreName(score, colorPiece, 3, player, name);
    gotoXY(0, 25);
}

/**
 * Prints out the MultiPlayer (1 vs PC) interface
 * while the player or PC is moving the piece
 * inside the map
 * @param[in] map game map
 * @param[in] colorPiece map color
 * @param[in] colorMode text color
 * @param[in] score current score
 * @param[in] center a value to set the text position
 * @param[in] player index player 1 or 2
 * @param[in] name player's name
 * @see setcolorText()
 * @see printTitle()
 * @see printMapColor()
 * @see saltaRighe()
 * @see printScorePC()
 * @see gotoXY()
 */
void introMPDynamicPC(int map[15][10], char *colorPiece, char* colorMode, int score, int center, char player){
    setcolorText(colorMode, 1);
    system("cls");
    printTitle("MULTIPLAYER MODE");
    saltaRighe(2);
    printMapColor(map, colorPiece, colorMode, center);
    saltaRighe(2);
    printScorePC(score, colorPiece, 3, player);
    gotoXY(0, 25);
}

/** 
 * Prints out the MultiPlayer (1 vs PC) interface,
 * updates the scores and, if occurs, inverts the
 * enemy's rows
 * @param[out] map player's game map
 * @param[out] map1 PC's game map
 * @param[in] colorMode text color
 * @param[out] score player's current score
 * @param[out] score1 PC's current score
 * @param[in] color1 player's map color
 * @param[in] color2 PC's map color
 * @param[in] name player's name
 * @see setcolorText()
 * @see printTitle()
 * @see updateScoreMP2()
 * @see invertEnemy()
 * @see printMaps()
 * @see printScoreName()
 * @see printScorePC()
 * @see gotoXY()
 */
void introMP2PC(int map[15][10], int map1[15][10], char* colorMode, int *score, int *score1,
             char *color1, char *color2, char name[20]){
    int invert;
    setcolorText(colorMode, 1);
    system("cls");
    printTitle("MULTIPLAYER MODE");
    
    /*printMapColor(map, width, height, "yellow", colorMode, 80);
    printMapColor(map1, width, height, "purple", colorMode, 115);*/
    
    invert = updateScoreMP2(map, score);

    if(invert >= 3){ /*per i test ho provato con 2 e funziona, con 3 è più difficile creare la situazione*/
        invertEnemy(map1, invert);
    }

    invert = updateScoreMP2(map1, score1);

    if(invert >= 3){
        invertEnemy(map, invert);
    }
    
    printMaps(map, map1, color1, color2, colorMode);
    printScoreName(*score, color1, 3, '1', name);
    printScorePC(*score1, color2, 5, '0');
    
    gotoXY(0, 25);
    
}

/** 
 * Prints out the MultiPlayer (1 vs 1) interface,
 * updates the scores and, if occurs, inverts the
 * enemy's rows
 * @param[out] map player1 game map
 * @param[out] map1 player2 game map
 * @param[in] colorMode text color
 * @param[out] score player1 current score
 * @param[out] score1 player2 current score
 * @param[in] color1 player1 map color
 * @param[in] color2 player2 map color
 * @param[in] name1 player1 name
 * @param[in] name2 player2 name
 * @see setcolorText()
 * @see printTitle()
 * @see updateScoreMP2()
 * @see invertEnemy()
 * @see printMaps()
 * @see printScoreName()
 * @see gotoXY()
 */
void introMP2(int map[15][10], int map1[15][10], char* colorMode, int *score, int *score1,
             char *color1, char *color2, char name1[20], char name2[20]){
    int invert;
    setcolorText(colorMode, 1);
    system("cls");
    printTitle("MULTIPLAYER MODE");
    
    /*printMapColor(map, width, height, "yellow", colorMode, 80);
    printMapColor(map1, width, height, "purple", colorMode, 115);*/
    invert = updateScoreMP2(map, score);

    if(invert >= 3){
        invertEnemy(map1, invert);
    }

    invert = updateScoreMP2(map1, score1);

    if(invert >= 3){
        invertEnemy(map, invert);
    }
    
    printMaps(map, map1, color1, color2, colorMode);
    printScoreName(*score, color1, 3, '1', name1);
    printScoreName(*score1, color2, 5, '2', name2);
    
    gotoXY(0, 25);
    
}

/** 
 * When a piece could not be drawn,
 * this function stores back the amout
 * (decreased) to its original value
 * @param[out] avaiblep avaible pieces
 * @param[in] selectedSM selected piece
 * @param[in] drawn if piece was drawn or not
 */
void updateAvPieces(int avaiblep[6], int selectedSM, int drawn){
    if(drawn == 0){
        avaiblep[selectedSM]++;
    }
}

/** 
 * Selects a piece (tetramino), its rotation and
 * updates avaible pieces
 * @param[out] avaiblep avaible pieces
 * @param[in] dim avaiblep array's size
 * @param[out] selectedSM selected piece
 * @param[out] rotation player's current score
 * @param[out] drawn if piece was drawn or not
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 * @param[in] colorMode text color
 * @param[in] colorPiece map color
 * @see saltaRighe()
 * @see printLegendaPieces()
 * @see printAvaiblePieces()
 * @see printLegendaAllPieces()
 * @see selectPiece()
 * @see selectRotation()
 * @see drawSelected()
 * @see delay()
 * @see updateAvPieces()
 * @see gotoXY()
 */
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
    delay(1.5);
    updateAvPieces(avaiblep, *selectedSM, *drawn);
    gotoXY(0, 25);
}

/** 
 * Select randomly a piece (tetramino) 
 * and its rotation, then updates avaible pieces
 * (1 vs PC)
 * @param[out] avaiblep avaible pieces
 * @param[in] dim avaiblep array's size
 * @param[out] selectedSM selected piece
 * @param[out] rotation player's current score
 * @param[out] drawn if piece was drawn or not
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 * @param[in] colorMode text color
 * @param[in] colorPiece map color
 * @see saltaRighe()
 * @see printLegendaPieces()
 * @see printAvaiblePieces()
 * @see printLegendaAllPieces()
 * @see checkAvaible()
 * @see drawSelected()
 * @see delay()
 * @see updateAvPieces()
 * @see gotoXY()
 */
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
    /* senza la funzione selectPiece, non decrementa la disponibilità:  */
    if( checkAvaible(avaiblep, dim, *selectedSM) == 1 ){
        avaiblep[*selectedSM]--; /* update avaiblepieces */
    }
    *rotation = rand()% 4; /* random rotation from 0 to 3 -> don't need to initialize rand() because this
    function will be recalled everytime with random values */
    *drawn = drawSelected(map, x, y, *selectedSM, *rotation);
    printf("drawn = %d\n", *drawn);
    delay(1.5);
    updateAvPieces(avaiblep, *selectedSM, *drawn);
    gotoXY(0, 25);
}

/** 
 * Checks if the selected piece can move
 *  any further to any direction
 * @param[in] map game map
 * @param[in] x map x coord.
 * @param[in] sy piece y limit coord.
 * @param[in] selected selected piece
 * @param[in] rotation piece rotation
 * @param[out] 0 if it can move further
 * @param[out] 1 if it will collide
 */
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


/** 
 * Returns the last y coords of the selected piece.
 * @param[in] selected selected piece
 * @param[in] y map y coord.
 * @param[in] rotation piece rotation
 * @param[out] sy piece y limit coord.
 */
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

/** 
 * Returns the last x coords of the selected piece.
 * @param[in] selected selected piece
 * @param[in] x map x coord.
 * @param[in] rotation piece rotation
 * @param[out] sx piece x limit coord.
 */
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

/*

void fall(int map[15][10], int x, int y, int sy, int selected, int rotation, int score, char player){
    if(sy < height - 2 && avoidPieces(map, x, sy, selected, rotation) == 1){
        introSDynamic(map, colorSM, score);
        movebackSelected(map, x, y, selected, rotation);
        drawSelected(map, x, y + 1, selected, rotation);
    }

}

*/

/** 
 * Make the piece fall until
 * the bottom of the map or
 * the before colliding with
 * another piece (SinglePlayer)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 * @param[in] sy piece y limit coord.
 * @param[in] selected selected piece
 * @param[in] rotation piece rotation
 * @param[out] score current score
 * @see avoidPieces()
 * @see updateScore()
 * @see introSDynamic()
 * @see movebackSelected()
 * @see drawSelected()
 */
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

/** 
 * Make the piece fall until
 * the bottom of the map or
 * the before colliding with
 * another piece and, if it occurs,
 * inverts the rows (MultiPlayer)
 * @param[out] map game map
 * @param[out] mapEnemy enemy's game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 * @param[in] sy piece y limit coord.
 * @param[in] selected selected piece
 * @param[in] rotation piece rotation
 * @param[out] score current score
 * @param[in] colorPiece map color (the one who is moving the piece)
 * @param[in] colorMode text color
 * @param[in] center a value to set the text position
 * @param[in] player index of player
 * @param[in] name player's name (the one who is moving the piece)
 * @see avoidPieces()
 * @see updateScoreMP2()
 * @see invertEnemy()
 * @see introMPDynamicName()
 * @see introMPDynamicPC()
 * @see movebackSelected()
 * @see drawSelected()
 */
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
            if(invert >= 3){
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


/** 
 * Move the selected piece inside the map (SinglePlayer)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 * @param[in] selectedSM selected piece
 * @param[out] rotation piece rotation
 * @param[out] released if the piece is released or not
 * @param[out] score current score
 * @return 0: if the piece wasn't correctly moved, 1: if the piece was correctly moved
 * @see introSDynamic()
 * @see getLastCoords()
 * @see avoidPieces()
 * @see delay()
 * @see updateScoreSM()
 * @see movebackSelected()
 * @see drawSelected()
 * @see gotoXY()
 * @see saltaRighe()
 * @see getLastCoords1()
 * @see fallDown()
 * @see printMapColor()
 * @see setcolorText()
 * @see printTitle()
 */
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

            if(!winning){ /*GAME OVER SCREEN -> only in SINGOL GAME MODE */
                system("cls");
                setcolorText(colorMP, 1);
                printTitle("COLLISION! GAME OVER!\n");
                delay(2.0);
                setcolorText("white", 1);
                return 0;
            }
            
        }

        return 1;

    } else{
        printf("YOU NEED TO SELECT A PIECE BEFORE MOVING IT..\n");
    }
}

/** 
 * Move the selected piece inside the map (MultiPlayer)
 * @param[out] map game map
 * @param[out] mapEnemy enemy's game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 * @param[in] selectedSM selected piece
 * @param[out] rotation piece rotation
 * @param[out] released if the piece is released or not
 * @param[out] score current score
 * @param[in] colorMode text color
 * @param[in] colorPiece map color
 * @param[in] center a value to set text position
 * @param[in] player index
 * @param[in] name player's name (the one who is moving the piece)
 * @return 0: if the piece wasn't correctly moved, 1: if the piece was correctly moved
 * @see updateScoreMP2()
 * @see invertEnemy()
 * @see introMPDynamicName()
 * @see introMPDynamiPC()
 * @see getLastCoords()
 * @see avoidPieces()
 * @see delay()
 * @see movebackSelected()
 * @see drawSelected()
 * @see gotoXY()
 * @see saltaRighe()
 * @see getLastCoords1()
 * @see fallDownMP()
 * @see printMapColor()
 */
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

            if(invert >= 3){
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
                if(invert >= 3){
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
                system("cls"); /*will check scores and print the winner */
                return 0;
            }
            
        }

        return 1;

    } else{
        printf("YOU NEED TO SELECT A PIECE BEFORE MOVING IT..\n");
    }
}


/** 
 * Move the selected piece inside the map (MultiPlayer)
 * @param[out] map player1 game map
 * @param[out] map1 player2 game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 * @param[out] score player1 current score
 * @param[out] score1 player2 current score
 * @param[out] drawn player1 current score
 * @param[out] drawn1 player2 current score
 * @param[out] rotation player1 piece rotation
 * @param[out] rotation1 player2 piece rotation
 * @param[out] released if player1 piece is released or not
 * @param[out] released1 if player2 piece is released or not
 * @param[out] selectedSM player1 selected piece
 * @param[out] selectedMP player2 selected piece
 * @param[out] avaibleMP avaible pieces (shared)
 * @param[in] dim avaibleMP array's size
 * @param[out] won if player1 has finished the pieces avaible
 * @param[out] won1 if player2 has finished the pieces avaible
 * @param[out] winning if player1 has moved the piece uncorrectly
 * @param[out] winning1 if player2 has moved the piece uncorrectly
 * @param[in] colorMode text color
 * @param[in] color1 player1 map color
 * @param[in] color2 player2 map color
 * @param[in] name1 player1 name (the one who is moving the piece)
 * @param[in] name2 player2 name (the one who is moving the piece)
 * @see introMP2()
 * @see selectProcess()
 * @see movePieceMP()
 * @see checkEndGame()
 * @see printWinner()
 * @see checkWinMP() 
 */
void gameOneVSOne(int map[15][10], int map1[15][10], int x, int y, int *score, int *score1, int *drawn,
              int *drawn1, int *rotation, int *rotation1, int *released, int *released1, int *selectedSM, int *selectedMP,
              int avaiblepMP[6], int dim, int *won, int *won1, int *winning, int *winning1, char *colorMode, 
              char *color1, char *color2, char name1[20], char name2[20]){

    introMP2(map, map1, colorMode, score, score1, color1, color2, name1, name2);

    *released = 0;

    selectProcess(avaiblepMP, dim, selectedSM, rotation, drawn, map, x, y, colorMode, color1);

    *winning = movePieceMP(map, map1, x, y, *selectedSM, *rotation, released, score, colorMode, color1, 80, '1', name1);

    checkEndGame(avaiblepMP, dim, won);/*verifichiamo la disponibilità dei tetramini (condivisi) -> se non 
    ce ne sono più, bisogna concludere il gioco*/

    if(*winning == 0){ /*il giocatore p1 ha posizionato male i tetramini -> ha perso indipendentemente dal punteggio*/
        printWinner(name2);
        return;
    } else if(*won == 1){ /*il giocatore p1 ha finito i pezzi (condivisi) per cui si controllano i punteggi: winner o pareggio*/
        checkWinMP(name1, name2, *score, *score1);
        return;
    }

    introMP2(map, map1, colorMode, score, score1, color1, color2, name1, name2);

    *released1 = 0;

    selectProcess(avaiblepMP, dim, selectedMP, rotation1, drawn1, map1, x, y, colorMode, color2);

    *winning1 = movePieceMP(map1, map, x, y, *selectedMP, *rotation1, released1, score1, colorMode, color2, 150, '2', name2);

    checkEndGame(avaiblepMP, dim, won1);/*verifichiamo la disponibilità dei tetramini (condivisi) -> se non 
    ce ne sono più, bisogna concludere il gioco*/

    if(*winning1 == 0){ /*il giocatore p2 ha posizionato male i tetramini -> ha perso indipendentemente dal punteggio*/
        printWinner(name1);
        return;
    } else if(*won1 == 1){ /*il giocatore p2 ha finito i pezzi (condivisi) per cui si controllano i punteggi: winner o pareggio*/
        checkWinMP(name1, name2, *score, *score1);
        return;
    }

}

/** 
 * Move the selected piece inside the map (MultiPlayer)
 * @param[out] map player1 game map
 * @param[out] map1 player2 game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 * @param[out] score player1 current score
 * @param[out] score1 player2 current score
 * @param[out] drawn player1 current score
 * @param[out] drawn1 player2 current score
 * @param[out] rotation player1 piece rotation
 * @param[out] rotation1 player2 piece rotation
 * @param[out] released if player1 piece is released or not
 * @param[out] released1 if player2 piece is released or not
 * @param[out] selectedSM player1 selected piece
 * @param[out] selectedMP player2 selected piece
 * @param[out] avaibleMP avaible pieces (shared)
 * @param[in] dim avaibleMP array's size
 * @param[out] won if player1 has finished the pieces avaible
 * @param[out] won1 if player2 has finished the pieces avaible
 * @param[out] winning if player1 has moved the piece uncorrectly
 * @param[out] winning1 if player2 has moved the piece uncorrectly
 * @param[in] colorMode text color
 * @param[in] color1 player1 map color
 * @param[in] color2 player2 map color
 * @param[in] name player1 name (the one who is moving the piece)
 * @see introMP2PC()
 * @see selectProcess()
 * @see movePieceMP()
 * @see checkEndGame()
 * @see printLoser()
 * @see printWinner()
 * @see checkWinMPC()
 * @see selectProcessPC()
 */
void gameOneVSPC(int map[15][10], int map1[15][10], int x, int y, int *score, int *score1, int *drawn,
              int *drawn1, int *rotation, int *rotation1, int *released, int *released1, int *selectedSM, int *selectedMP,
              int avaiblepMP[6], int dim, int *won, int *won1, int *winning, int *winning1, char *colorMode, 
              char *color1, char *color2, char name[20]){

    introMP2PC(map, map1, colorMode, score, score1, color1, color2, name);

    *released = 0;

    selectProcess(avaiblepMP, dim, selectedSM, rotation, drawn, map, x, y, colorMode, color1);

    *winning = movePieceMP(map, map1, x, y, *selectedSM, *rotation, released, score, colorMode, color1, 80, '1', name);

    checkEndGame(avaiblepMP, dim, won); /*verifichiamo la disponibilità dei tetramini (condivisi) -> se non 
    ce ne sono più, bisogna concludere il gioco*/

    if(*winning == 0){ /* il p1 ha fatto posizionato male i tetramini, ha perso, il pc ha vinto */
        printLoser(name);
        return;
    } else if(*won == 1){  /*il p1 ha finito i tetramini condivisi, si controllano i punteggi e il gioco si conclude */
        checkWinMPC(name, *score, *score1);
        return;
    }

    introMP2PC(map, map1, colorMode, score, score1, color1, color2, name);

    *released1 = 0;

    selectProcessPC(avaiblepMP, dim, selectedMP, rotation1, drawn1, map1, x, y, colorMode, color2);

    *winning1 = movePieceMP(map1, map, x, y, *selectedMP, *rotation1, released1, score1, colorMode, color2, 150, '0', name);

    checkEndGame(avaiblepMP, dim, won1);  /*verifichiamo la disponibilità dei tetramini (condivisi) -> se non 
    ce ne sono più, bisogna concludere il gioco*/

    if(*winning1 == 0){ /* il pc ha fatto posizionato male i tetramini, ha perso il pc */
        printWinner(name);
        return;
    } else if(*won1 == 1){  /*il pc ha finito i tetramini condivisi, si controllano i punteggi e il gioco si conclude */
        checkWinMPC(name, *score, *score1);
        return;
    }

}


