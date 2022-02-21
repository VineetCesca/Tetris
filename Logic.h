int checkAvaible(int *pieces, int dim, int selected){
    if(pieces[selected] <= 0){
        return 0; /* piece is not avaible */
    }
    return 1; /* piece is avaible */
}

int selectPiece(int *pieces, int dim){
    int selected;
    char c;
    do{
        printf("Select a piece (0, 1, 2, 3, 4, 5): "); /* T = 0  Z = 1  I = 2  L = 3  Lr = 4  O = 5 */
    }while( ( (scanf("%d%c", &selected, &c) != 2 || c != '\n') && clean_stdin() == 1 ) || selected < 0 || selected > 5);
    if( checkAvaible(pieces, dim, selected) == 1 ){
        pieces[selected]--; /* update avaiblepieces */
    }
    
    return selected;
}

int selectRotation(){
    int r;
    char c;
    do{
        printf("Select a rotation (0, 1, 2, 3): ");
    } while(  ( (scanf("%d%c", &r, &c) != 2 || c != '\n') && clean_stdin() == 1 ) || r < 0 || r > 3);

    return r;
}

int drawSelected(int map[15][10], int width, int height, int x, int y, int selected, int rotation){
    /*rotation = 0 1 2 3 */
    int drawn;
    if(selected == 0){
        if(rotation == 0){
            drawn = drawT(map, width, height, x, y);
        } else if(rotation == 1){
            drawn = drawT1(map, width, height, x, y);
        } else if(rotation == 2){
            drawn = drawT2(map, width, height, x, y);
        } else if(rotation == 3){
            drawn = drawT3(map, width, height, x, y);
        }  
    } else if(selected == 1){
        if(rotation == 0){
            drawn = drawZ(map, width, height, x, y);
        } else if(rotation == 1){
            drawn = drawZ1(map, width, height, x, y);
        } else if(rotation == 2){
            drawn = drawZ2(map, width, height, x, y);
        } else if(rotation == 3){
            drawn = drawZ3(map, width, height, x, y);
        }
    } else if(selected == 2){
        if(rotation == 0 || rotation == 2){
            drawn = drawI(map, width, height, x, y);
        } else if(rotation == 1 || rotation == 3){
            drawn = drawI1(map, width, height, x, y);
        }
    } else if(selected == 3){
        if(rotation == 0){
            drawn = drawL(map, width, height, x, y);
        } else if(rotation == 1){
            drawn = drawL1(map, width, height, x, y);
        } else if(rotation == 2){
            drawn = drawL2(map, width, height, x, y);
        } else if(rotation == 3){
            drawn = drawL3(map, width, height, x, y);
        }
    } else if(selected == 4){
        if(rotation == 0){
            drawn = drawLr(map, width, height, x, y);
        } else if(rotation == 1){
            drawn = drawLr1(map, width, height, x, y);
        } else if(rotation == 2){
            drawn = drawLr2(map, width, height, x, y);
        } else if(rotation == 3){
            drawn = drawLr3(map, width, height, x, y);
        }
    } else if(selected == 5){
        if(rotation == 0 || rotation == 1 || rotation == 2 || rotation == 3){
            drawn = drawO(map, width, height, x, y);
        }
    }

    return drawn;
}

void movebackSelected(int map[15][10], int width, int height, int x, int y, int selected, int rotation){
    /*rotation = 0 1 2 3 */
    if(selected == 0){
        if(rotation == 0){
            movebackT(map, width, height, x, y, 0, 0, 0);
        } else if(rotation == 1){
            movebackT1(map, width, height, x, y, 0, 0, 0);
        } else if(rotation == 2){
            movebackT2(map, width, height, x, y, 0, 0, 0);
        } else if(rotation == 3){
            movebackT3(map, width, height, x, y, 0, 0, 0);
        }
    } else if(selected == 1){
        if(rotation == 0){
            movebackZ(map, width, height, x, y, 0, 0, 0);
        } else if(rotation == 1){
            movebackZ1(map, width, height, x, y, 0, 0, 0);
        } else if(rotation == 2){
            movebackZ2(map, width, height, x, y, 0, 0, 0);
        } else if(rotation == 3){
            movebackZ3(map, width, height, x, y, 0, 0, 0);
        }
    } else if(selected == 2){
        if(rotation == 0 || rotation == 2){
            movebackI(map, width, height, x, y, 0, 0, 0);
        } else if(rotation == 1 || rotation == 3){
            movebackI1(map, width, height, x, y, 0, 0, 0);
        }
    } else if(selected == 3){
        if(rotation == 0){
            movebackL(map, width, height, x, y, 0, 0, 0);
        } else if(rotation == 1){
            movebackL1(map, width, height, x, y, 0, 0, 0);
        } else if(rotation == 2){
            movebackL2(map, width, height, x, y, 0, 0, 0);
        } else if(rotation == 3){
            movebackL3(map, width, height, x, y, 0, 0, 0);
        }
    } else if(selected == 4){
        if(rotation == 0){
            movebackLr(map, width, height, x, y, 0, 0, 0);
        } else if(rotation == 1){
            movebackLr1(map, width, height, x, y, 0, 0, 0);
        } else if(rotation == 2){
            movebackLr2(map, width, height, x, y, 0, 0, 0);
        } else if(rotation == 3){
            movebackLr3(map, width, height, x, y, 0, 0, 0);
        }
    } else if(selected == 5){
        if(rotation == 0 || rotation == 1 || rotation == 2 || rotation == 3){
            movebackO(map, width, height, x, y, 0, 0, 0);
        }
    }
} 

/* Una volta posizionato un tetramino, se una o più righe orizzontali vengono riempite
 * per intero, queste righe vengono cancellate come nel tetris originale.
 * La rimozione di una riga vale 1 punto, la rimozione di due righe con un solo pezzo vale
 * 3 punti, tre righe 6 punti, quattro righe 12 punti.
 */

void FallColumn(int map[15][10], int height, int j){
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

void FallAll(int map[15][10], int width, int height){
    int j;
    for(j = 1; j < width - 1; j++){
        FallColumn(map, height, j);
    }
}

void deleteRow(int map[15][10], int width, int height, int i){
    int k, j;
    for(k = 0; k < height - 1; k++){
        if(k == i){
            for(j = 1; j < width - 1; j++){
                map[k][j] = 0;
            } 
        }
    }
}

int countRows(int map[15][10], int width, int height){
    int i, j, n, count = 0;
    for(i = 0; i < height - 1; i++){
        n = 1;
        for(j = 1; j < width - 1; j++){
            if(map[i][j] == 0){
                n = 0;
            }
        }
        if(n == 1){
            count++;
            deleteRow(map, width, height, i);/* l'iesima riga deve essere eliminata */
        }
    }
    return count;
}

/* Una volta posizionato un tetramino, se una o più righe orizzontali vengono riempite
 * per intero, queste righe vengono cancellate come nel tetris originale.
 * La rimozione di una riga vale 1 punto, la rimozione di due righe con un solo pezzo vale
 * 3 punti, tre righe 6 punti, quattro righe 12 punti.
 */

void updateScoreSM(int map[15][10], int width, int height, int *score){
    int count = countRows(map, width, height);
    if(count == 0){
        return;
    } else if(count == 1){
        FallAll(map, width, height);
        *score += 1;
    } else if(count == 2){
        FallAll(map, width, height);
        *score += 3;
    } else if(count == 3){
        FallAll(map, width, height);
        *score += 6;
    } else if(count == 4){
        FallAll(map, width, height);
        *score += 12;
    } else {
        FallAll(map, width, height);
        *score += count;
    }
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
   
   
   
   


