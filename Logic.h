int checkAvaible(int *pieces, int dim, int selected){
    if(pieces[selected] <= 0){
        return 0; /* piece is not avaible */
    }
    return 1; /* piece is avaible */
}

int selectPiece(int *pieces, int dim, char *colorPiece){
    int selected;
    char c;
    setcolorText(colorPiece, 1);
    do{
        printf("Select a piece (0, 1, 2, 3, 4, 5): "); /* T = 0  Z = 1  I = 2  L = 3  Lr = 4  O = 5 */
    }while( ( (scanf("%d%c", &selected, &c) != 2 || c != '\n') && clean_stdin() == 1 ) || selected < 0 || selected > 5);
    if( checkAvaible(pieces, dim, selected) == 1 ){
        pieces[selected]--; /* update avaiblepieces */
    }
    
    return selected;
}

int selectRotation(char *colorPiece){
    int r;
    char c;
    setcolorText(colorPiece, 1);
    do{
        printf("Select a rotation (0, 1, 2, 3): ");
    } while(  ( (scanf("%d%c", &r, &c) != 2 || c != '\n') && clean_stdin() == 1 ) || r < 0 || r > 3);

    return r;
}

int drawSelected(int map[15][10], int x, int y, int selected, int rotation){
    /*rotation = 0 1 2 3 */
    int drawn;
    if(selected == 0){
        if(rotation == 0){
            drawn = drawT(map, x, y);
        } else if(rotation == 1){
            drawn = drawT1(map, x, y);
        } else if(rotation == 2){
            drawn = drawT2(map, x, y);
        } else if(rotation == 3){
            drawn = drawT3(map, x, y);
        }  
    } else if(selected == 1){
        if(rotation == 0){
            drawn = drawZ(map, x, y);
        } else if(rotation == 1){
            drawn = drawZ1(map, x, y);
        } else if(rotation == 2){
            drawn = drawZ2(map, x, y);
        } else if(rotation == 3){
            drawn = drawZ3(map, x, y);
        }
    } else if(selected == 2){
        if(rotation == 0 || rotation == 2){
            drawn = drawI(map, x, y);
        } else if(rotation == 1 || rotation == 3){
            drawn = drawI1(map, x, y);
        }
    } else if(selected == 3){
        if(rotation == 0){
            drawn = drawL(map, x, y);
        } else if(rotation == 1){
            drawn = drawL1(map, x, y);
        } else if(rotation == 2){
            drawn = drawL2(map, x, y);
        } else if(rotation == 3){
            drawn = drawL3(map, x, y);
        }
    } else if(selected == 4){
        if(rotation == 0){
            drawn = drawLr(map, x, y);
        } else if(rotation == 1){
            drawn = drawLr1(map, x, y);
        } else if(rotation == 2){
            drawn = drawLr2(map, x, y);
        } else if(rotation == 3){
            drawn = drawLr3(map, x, y);
        }
    } else if(selected == 5){
        if(rotation == 0 || rotation == 1 || rotation == 2 || rotation == 3){
            drawn = drawO(map, x, y);
        }
    }

    return drawn;
}

void movebackSelected(int map[15][10], int x, int y, int selected, int rotation){
    /*rotation = 0 1 2 3 */
    if(selected == 0){
        if(rotation == 0){
            deleteT(map, x, y);
        } else if(rotation == 1){
            deleteT1(map, x, y);
        } else if(rotation == 2){
            deleteT2(map, x, y);
        } else if(rotation == 3){
            deleteT3(map, x, y);
        }
    } else if(selected == 1){
        if(rotation == 0){
            deleteZ(map, x, y);
        } else if(rotation == 1){
            deleteZ1(map, x, y);
        } else if(rotation == 2){
            deleteZ2(map, x, y);
        } else if(rotation == 3){
            deleteZ3(map, x, y);
        }
    } else if(selected == 2){
        if(rotation == 0 || rotation == 2){
            deleteI(map, x, y);
        } else if(rotation == 1 || rotation == 3){
            deleteI1(map, x, y);
        }
    } else if(selected == 3){
        if(rotation == 0){
            deleteL(map, x, y);
        } else if(rotation == 1){
            deleteL1(map, x, y);
        } else if(rotation == 2){
            deleteL2(map, x, y);
        } else if(rotation == 3){
            deleteL3(map, x, y);
        }
    } else if(selected == 4){
        if(rotation == 0){
            deleteLr(map, x, y);
        } else if(rotation == 1){
            deleteLr1(map, x, y);
        } else if(rotation == 2){
            deleteLr2(map, x, y);
        } else if(rotation == 3){
            deleteLr3(map, x, y);
        }
    } else if(selected == 5){
        if(rotation == 0 || rotation == 1 || rotation == 2 || rotation == 3){
            deleteO(map, x, y);
        }
    }
} 

/* Una volta posizionato un tetramino, se una o più righe orizzontali vengono riempite
 * per intero, queste righe vengono cancellate come nel tetris originale.
 * La rimozione di una riga vale 1 punto, la rimozione di due righe con un solo pezzo vale
 * 3 punti, tre righe 6 punti, quattro righe 12 punti.
 */

void FallColumn(int map[15][10], int j){
    int i, k, count;
    for(i = 0; i < height - 1; i++){
        count = 0;
        if(map[i][j] == 1){
            for(k = i + 1; k < height - 1 && count < 1;  k++){
                if(map[k][j] == 0){
                    map[i][j] = 0;
                    map[k][j] = 1;
                    count++;
                }
            }
        }
    }
}

void FallAll(int map[15][10]){
    int j;
    for(j = 1; j < width - 1; j++){
        FallColumn(map, j);
    }
}

void deleteRow(int map[15][10], int i){
    int k, j;
    for(k = 0; k < height - 1; k++){
        if(k == i){
            for(j = 1; j < width - 1; j++){
                map[k][j] = 0;
            } 
        }
    }
}

int countRows(int map[15][10]){
    int i, j, n, count;
    count = 0;
    for(i = 0; i < height - 1; i++){
        n = 1;
        for(j = 1; j < width - 1; j++){
            if(map[i][j] == 0){
                n = 0;
            }
        }
        if(n == 1){
            count++;
            deleteRow(map, i);/* l'iesima riga deve essere eliminata */
        }
    }
    return count;
}

/* Una volta posizionato un tetramino, se una o più righe orizzontali vengono riempite
 * per intero, queste righe vengono cancellate come nel tetris originale.
 * La rimozione di una riga vale 1 punto, la rimozione di due righe con un solo pezzo vale
 * 3 punti, tre righe 6 punti, quattro righe 12 punti.
 */

void updateScoreSM(int map[15][10], int *score){
    int count;
    count = countRows(map);
    if(count <= 0){
        return;
    } else{

        if(count == 1){
            *score = *score +  1;     /* BIG MISTAKE: *score += 1 -> WRONG */
        } else if(count == 2){
            *score = *score +  3;
        } else if(count == 3){
            *score = *score +  6;
        } else if(count == 4){
            *score = *score +  12;
        } else {
            *score = *score +  count;
        }

    } 

    FallAll(map); /* FallAll sempre e comunque,  */
}

void invertEnemy(int map[15][10], int invert){
    int i, j;
    for(i = height - invert - 2; i < height - 1 && i >= 0; i++){  /*usiamo i = height - invert - 2 perchè le 
                                                posizioni i = height e i = height - 1 non sono valide */
        for(j = 1; j < width - 1; j++){
            if(map[i][j] == 0){
                map[i][j] = 1;
            } else if(map[i][j] == 1){
                map[i][j] = 0;
            }
        }
    }
}

int updateScoreMP2(int map[15][10], int *score){
    
    int count;
    count = countRows(map);

    if(count <= 0){
        return 0;
    } else {
        
        if(count == 1){
            *score = *score +  1;   /* BIG MISTAKE: *score += 1 -> WRONG */
        } else if(count == 2){
            *score = *score +  3;
        } else if(count == 3){
            *score = *score +  6;
        } else if(count == 4){
            *score = *score +  12;
        } else {
            *score = *score + count;
        }

    }

    FallAll(map);

    /* aggiungi le cose dalla consegna del progetto nel pdf */
    return count;
}

void checkWin(int avaiblep[6], int dim, int *won){
    int i;
    int count = 0;
    for(i = 0; i < dim; i++){
        if(avaiblep[i] == 0){
            count++;
        }
    }
    if(count == dim){
        *won = 1;
    }
}

int whoEnemy(){

    int p;
    char c;
    do{
        system("cls");
        printf("How many players? (0, 1, 2): ");
    }while( ( (scanf("%d%c", &p, &c) != 2 || c != '\n') && clean_stdin() == 1 ) || p < 0 || p > 2);
    
}
   
   
   
   


