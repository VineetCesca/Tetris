/* T, T1, T2, T3 */

/* ERRORE DI PIANIFICAZIONE NEL DISEGNO DEI PEZZI: E' MOLTO PIU' COMODO TENERE CONTO DELLA COORDINATA
    X E Y DEGLI 1 PIU' IN BASSO DEL PEZZO CHE SI STA CONSIDERANDO: QUESTO PERMETTE DI FARE
    CADERE PEZZI DI DIMENSIONE DIVERSA O RUOTATI FINO AL BORDO DELLA MAPPA OPPURE FINCHE' NON
    TROVANO UN 1 APPENA SOTTO */

/* ERRORE DELLA COLLISIONE DIRETTA */
/* ATTENTO ALLE FUNZIONI DELETE: DEVONO SETTARE I VALORI A 0 E NON A 1: CANCELLARE!!! */

/*  ***  */
/*   *   */

int drawT(int map[15][10], int width, int height, int x, int y){
    int k, i , j, f = 1;
    for(i = 0; i + 1 < height - 1; i++){
        for(j = 1; j + 2 < width - 1; j++){
            if(i == y && j == x){
                for(k = j; k < j + 3; k++){
                    if(map[i][k] == 1 || map[i + 1][j + 1] == 1){
                        printf("\nPiece cannot be here \n");
                        return 0;
                    }
                }
                
                for(k = j; k < j + 3; k++){
                    map[i][k] = 1;
                    if(k == j + 1){
                        map[i + 1][k] = 1;
                    }
                }
                return 1;

            } else {
                f = 0;
            }
        }
    }

    return f;
}

void deleteT(int map[15][10], int width, int height, int x, int y){
    int k, i, j;
    for(i = 0; i < height - 1; i++){
        for(j = 1; j < width - 1; j++){
            if(i == y && j == x){
                for(k = j; k < j + 3; k++){
                    map[i][k] = 0;
                    if(k == j + 1){
                        map[i + 1][k] = 0;
                    }
                }
            }
        }
    }
}



/*   *   */
/*  ***  */

int drawT1(int map[15][10], int width, int height, int x, int y){  /* */
    int k, i , j, f = 1;
    for(i = 0; i + 1 < height - 1; i++){
        for(j = 1; j + 2 < width - 1; j++){
            if(i == y && j == x){
                for(k = j; k < j + 3; k++){
                    if(map[i][j + 1] == 1 || map[i + 1][k] == 1){
                        printf("\nPiece cannot be here \n");
                        return 0;
                    }
                }

                for(k = j; k < j + 3; k++){
                    map[i + 1][k] = 1;
                    if(k == j + 1){
                        map[i][j + 1] = 1;
                    }
                }
                return 1;

            }
        }
    }
    return f;
}

void deleteT1(int map[15][10], int width, int height, int x, int y){  /* */
    int k, i , j;
    for(i = 0; i < height - 1; i++){
        for(j = 1; j < width - 1; j++){
            if(i == y && j == x){
                map[i][j + 1] = 0;
                for(k = j; k < j + 3; k++){
                    map[i + 1][k] = 0;
                }
            }
        }
    }
}


/*   +   */
/*   ++   */
/*   +    */

int drawT2(int map[15][10], int width, int height, int x, int y){
    int k, i , j, f = 1;
    for(i = 0; i + 2 < height - 1; i++){
        for(j = 1; j + 1 < width - 1; j++){
            if(i == y && j == x){
                for(k = i; k < i + 3; k++){
                    if(map[i + 1][j + 1] == 1 || map[k][j] == 1){
                        printf("\nPiece cannot be here \n");
                        return 0;
                    }
                }
                
                for(k = i; k < i + 3; k++){
                    map[k][j] = 1;
                    if(k == i + 1){
                        map[k][j + 1] = 1;
                    }
                }
                return 1;

            }
        }
    }
    return f;
}

void deleteT2(int map[15][10], int width, int height, int x, int y){
    int k, i , j;
    for(i = 0; i < height - 1; i++){
        for(j = 1; j < width - 1; j++){
            if(i == y && j == x){
                map[i + 1][j + 1] = 0;
                for(k = i; k < i + 3; k++){
                    map[k][j] = 0;
                }
            }
        }
    }
}


/*    +   */
/*   ++   */
/*    +    */

int drawT3(int map[15][10], int width, int height, int x, int y){
    int k, i , j, f = 1;
    for(i = 0; i + 2 < height - 1; i++){
        for(j = 1; j + 1 < width - 1; j++){
            if(i == y && j == x){
                for(k = i; k < i + 3; k++){
                    if(map[i + 1][j] == 1 || map[k][j + 1] == 1){
                        printf("\nPiece cannot be here \n");
                        return 0;
                    }
                }
                
                for(k = i; k < i + 3; k++){
                    map[k][j + 1] = 1;
                    if(k == i + 1){
                        map[i + 1][j] = 1;
                    }
                }
                return 1;

            }
        }
    }

    return f;
}

void deleteT3(int map[15][10], int width, int height, int x, int y){
    int k, i , j;
    for(i = 0; i < height - 1; i++){
        for(j = 1; j < width - 1; j++){
            if(i == y && j == x){
                map[i + 1][j] = 0;
                for(k = i; k < i + 3; k++){
                    map[k][j + 1] = 0;
                }
            }
        }
    }
}

/* T, T1, T2, T3 */
/* T = 0  Z = 1  I = 2  L = 3  Lr = 4  O = 5 */
/* Z, Z1, Z2, Z3 */

/*  **
     **  */

int drawZ(int map[15][10], int width, int height, int x, int y){
   int k, i , j, f = 1;
    for(i = 0; i + 1 < height - 1; i++){
        for(j = 1; j + 2 < width - 1; j++){
            if(i == y && j == x){
                for(k = j; k < j + 3; k++){
                    if( (k <= j + 1 && map[i][k] == 1 ) || ( k >= j + 1 && map[i + 1][k] == 1) ){
                        printf("\nPiece cannot be here \n");
                        return 0;
                    }
                }
                
                for(k = j; k < j + 3; k++){
                    if(k <= j + 1){
                        map[i][k] = 1;
                    }
                    if(k >= j + 1){
                        map[i + 1][k] = 1;
                    }
                }
                return 1;

            }
        }
    }

    return f;
}

void deleteZ(int map[15][10], int width, int height, int x, int y){
    int k, i , j;
    for(i = 0; i < height - 1; i++){
        for(j = 1; j < width - 1; j++){
            if(i == y && j == x){
                for(k = j; k < j + 3; k++){
                    if(k <= j + 1){
                        map[i][k] = 0;
                    }
                    if(k >= j + 1){
                        map[i + 1][k] = 0;
                    }
                }
            }
        }
    }
}


/*    *
    * *
    *   */

int drawZ1(int map[15][10], int width, int height, int x, int y){
   int k, i , j, f = 1;
    for(i = 0; i + 2 < height - 1; i++){
        for(j = 1; j + 1 < width - 1; j++){
            if(i == y && j == x){
                for(k = i; k < i + 3; k++){
                    if( (k <= i + 1 && map[k][j + 1] == 1 ) || ( k >= i + 1 && map[k][j] == 1) ){
                        printf("\nPiece cannot be here \n");
                        return 0;
                    }
                }
                
                for(k = i; k < i + 3; k++){
                    if(k <= i + 1){
                        map[k][j + 1] = 1;
                    }
                    if(k >= i + 1){
                        map[k][j] = 1;
                    }
                }
                return 1;

            }
        }
    }

    return f;
}

void deleteZ1(int map[15][10], int width, int height, int x, int y){
    int k, i , j;
    for(i = 0; i < height - 1; i++){
        for(j = 1; j < width - 1; j++){
            if(i == y && j == x){
                for(k = i; k < i + 3; k++){
                    if(k <= i + 1){
                        map[k][j + 1] = 0;
                    }
                    if(k >= i + 1){
                        map[k][j] = 0;
                    }
                }
            }
        }
    }
}

/*    * *
    * *     */

int drawZ2(int map[15][10], int width, int height, int x, int y){
   int k, i , j, f = 1;
    for(i = 0; i + 1 < height - 1; i++){
        for(j = 1; j + 2 < width - 1; j++){
            if(i == y && j == x){
                for(k = j; k < j + 3; k++){
                    if( (k >= j + 1 && map[i][k] == 1 ) || ( k <= j + 1 && map[i + 1][k] == 1) ){
                        printf("\nPiece cannot be here \n");
                        return 0;
                    }
                }
                
                for(k = j; k < j + 3; k++){
                    if(k >= j + 1){
                        map[i][k] = 1;
                    }
                    if(k <= j + 1){
                        map[i + 1][k] = 1;
                    }
                }
                return 1;

            }
        }
    }

    return f;
}

void deleteZ2(int map[15][10], int width, int height, int x, int y){
    int k, i , j;
    for(i = 0; i < height - 1; i++){
        for(j = 1; j < width - 1; j++){
            if(i == y && j == x){
                for(k = j; k < j + 3; k++){
                    if(k >= j + 1){
                        map[i][k] = 0;
                    }
                    if(k <= j + 1){
                        map[i + 1][k] = 0;
                    }
                }
            }
        }
    }
}

/*  *
    * *
      *   */

int drawZ3(int map[15][10], int width, int height, int x, int y){
   int k, i , j, f = 1;
    for(i = 0; i + 2 < height - 1; i++){
        for(j = 1; j + 1 < width - 1; j++){
            if(i == y && j == x){
                for(k = i; k < i + 3; k++){
                    if( (k >= i + 1 && map[k][j + 1] == 1 ) || ( k <= i + 1 && map[k][j] == 1) ){
                        printf("\nPiece cannot be here \n");
                        return 0;
                    }
                }
                
                for(k = i; k < i + 3; k++){
                    if(k >= i + 1){
                        map[k][j + 1] = 1;
                    }
                    if(k <= i + 1){
                        map[k][j] = 1;
                    }
                }
                return 1;

            }
        }
    }

    return f;
}

void deleteZ3(int map[15][10], int width, int height, int x, int y){
    int k, i , j;
    for(i = 0; i < height - 1; i++){
        for(j = 1; j < width - 1; j++){
            if(i == y && j == x){
                for(k = i; k < i + 3; k++){
                    if(k >= i + 1){
                        map[k][j + 1] = 0;
                    }
                    if(k <= i + 1){
                        map[k][j] = 0;
                    }
                }
            }
        }
    }
}


/* Z, Z1, Z2, Z3 */
/* T = 0  Z = 1  I = 2  L = 3  Lr = 4  O = 5 */
/* I, I1 */

/* 
    *
    *
    * 
    * 
*/

int drawI(int map[15][10], int width, int height, int x, int y){
    int k, i , j, f = 1;
    for(i = 0; i + 3 < height - 1; i++){
        for(j = 1; j < width - 1; j++){
            if(i == y && j == x){
                for(k = i; k < i + 4; k++){
                    if(map[k][j] == 1){
                        printf("\nPiece cannot be here \n");
                        return 0;
                    }
                }
                
                for(k = i; k < i + 4; k++){
                    map[k][j] = 1;
                }
                return 1;

            }
        }
    }

    return f;
}

void deleteI(int map[15][10], int width, int height, int x, int y){
    int k, i , j;
    for(i = 0; i < height - 1; i++){
        for(j = 1; j < width - 1; j++){
            if(i == y && j == x){
                for(k = i; k < i + 4; k++){
                    map[k][j] = 0;
                }
            }
        }
    }
}


/* 
    * * * *
*/

int drawI1(int map[15][10], int width, int height, int x, int y){
    int k, i , j, f = 1;
    for(i = 0; i < height - 1; i++){
        for(j = 1; j + 3 < width - 1; j++){
            if(i == y && j == x){
                for(k = j; k < j + 4; k++){
                    if(map[i][k] == 1){
                        printf("\nPiece cannot be here \n");
                        return 0;
                    }
                }
                
                for(k = j; k < j + 4; k++){
                    map[i][k] = 1;
                }
                return 1;

            }
        }
    }

    return f;
}

void deleteI1(int map[15][10], int width, int height, int x, int y){
    int k, i , j;
    for(i = 0; i < height - 1; i++){
        for(j = 1; j < width - 1; j++){
            if(i == y && j == x){
                for(k = j; k < j + 4; k++){
                    map[i][k] = 0;
                }
            }
        }
    }
}


/* I, I1 */
/* T = 0  Z = 1  I = 2  L = 3  Lr = 4  O = 5 */
/* L, L1, L2, L3 */

/* 
    *
    *
    * *
*/

int drawL(int map[15][10], int width, int height, int x, int y){
    int k, i , j, f = 1;
    for(i = 0; i + 2 < height - 1; i++){
        for(j = 1; j + 1 < width - 1; j++){
            if(i == y && j == x){
                for(k = i; k < i + 3; k++){
                    if(map[k][j] == 1 || (map[k][j + 1] == 1 && k == i + 2) ){
                        printf("\nPiece cannot be here \n");
                        return 0;
                    }
                }
                
                for(k = i; k < i + 3; k++){         
                    map[k][j] = 1;
                    if(k == i + 2){
                        map[k][j + 1] = 1;
                    }
                }
                return 1;

            }
        }
    }

    return f;
}

void deleteL(int map[15][10], int width, int height, int x, int y){
    int k, i , j;
    for(i = 0; i < height - 1; i++){
        for(j = 1; j < width - 1; j++){
            if(i == y && j == x){
                for(k = i; k < i + 3; k++){         
                    map[k][j] = 0;
                    if(k == i + 2){
                        map[k][j + 1] = 0;
                    }
                }
            }
        }
    }
}


/* 
    * * *
    *
*/

int drawL1(int map[15][10], int width, int height, int x, int y){
    int k, i , j, f = 1;
    for(i = 0; i + 1 < height - 1; i++){
        for(j = 1; j + 2 < width - 1; j++){
            if(i == y && j == x){
                for(k = j; k < j + 3; k++){
                    if(map[i][k] == 1 || map[i + 1][j] == 1){
                        printf("\nPiece cannot be here \n");
                        return 0;
                    }
                }
                
                for(k = j; k < j + 3; k++){         
                    map[i][k] = 1;
                    if(k == j){
                        map[i + 1][k] = 1;
                    }
                }
                return 1;

            }
        }
    }

    return f;
}

void deleteL1(int map[15][10], int width, int height, int x, int y){
    int k, i , j;
    for(i = 0; i < height - 1; i++){
        for(j = 1; j < width - 1; j++){
            if(i == y && j == x){
                for(k = j; k < j + 3; k++){         
                    map[i][k] = 0;
                    if(k == j){
                        map[i + 1][k] = 0;
                    }
                }
            }
        }
    }
}


/* 
    * *
      *
      * 
*/

int drawL2(int map[15][10], int width, int height, int x, int y){
    int k, i , j, f = 1;
    for(i = 0; i + 2 < height - 1; i++){
        for(j = 1; j + 1 < width - 1; j++){
            if(i == y && j == x){
                for(k = i; k < i + 3; k++){
                    if(map[k][j + 1] == 1 || (map[k][j] == 1 && k == i) ){
                        printf("\nPiece cannot be here \n");
                        return 0;
                    }
                }
                
                for(k = i; k < i + 3; k++){         
                    map[k][j + 1] = 1;
                    if(k == i){
                        map[k][j] = 1;
                    }
                }
                return 1;

            }
        }
    }

    return f;
}

void deleteL2(int map[15][10], int width, int height, int x, int y){
    int k, i , j;
    for(i = 0; i < height - 1; i++){
        for(j = 1; j < width - 1; j++){
            if(i == y && j == x){
                for(k = i; k < i + 3; k++){         
                    map[k][j + 1] = 0;
                    if(k == i){
                        map[k][j] = 0;
                    }
                }
            }
        }
    }
}


/* 
        *
    * * *
*/

int drawL3(int map[15][10], int width, int height, int x, int y){
    int k, i , j, f = 1;
    for(i = 0; i + 1 < height - 1; i++){
        for(j = 1; j + 2 < width - 1; j++){
            if(i == y && j == x){
                for(k = j; k < j + 3; k++){
                    if(map[i + 1][k] == 1 || map[i][j + 2] == 1){
                        printf("\nPiece cannot be here \n");
                        return 0;
                    }
                }
                
                for(k = j; k < j + 3; k++){         
                    map[i + 1][k] = 1;
                    if(k == j + 2){
                        map[i][k] = 1;
                    }
                }
                return 1;

            }
        }
    }

    return f;
}

void deleteL3(int map[15][10], int width, int height, int x, int y){
    int k, i , j;
    for(i = 0; i < height - 1; i++){
        for(j = 1; j < width - 1; j++){
            if(i == y && j == x){
                for(k = j; k < j + 3; k++){         
                    map[i + 1][k] = 0;
                    if(k == j + 2){
                        map[i][k] = 0;
                    }
                }
            }
        }
    }
}


/* L, L1, L2, L3 */
/* T = 0  Z = 1  I = 2  L = 3  Lr = 4  O = 5 */
/* Lr, Lr1, Lr2, Lr3 */

/*    *
      *
    * *
*/

int drawLr(int map[15][10], int width, int height, int x, int y){
    int k, i , j, f = 1;
    for(i = 0; i + 2 < height - 1; i++){
        for(j = 1; j + 1 < width - 1; j++){
            if(i == y && j == x){
                for(k = i; k < i + 3; k++){
                    if(map[k][j + 1] == 1 || (map[k][j] == 1 && k == i + 2) ){
                        printf("\nPiece cannot be here \n");
                        return 0;
                    }
                }
                
                for(k = i; k < i + 3; k++){         
                    map[k][j + 1] = 1;
                    if(k == i + 2){
                        map[k][j] = 1;
                    }
                }
                return 1;

            }
        }
    }

    return f;
}

void deleteLr(int map[15][10], int width, int height, int x, int y){
    int k, i , j;
    for(i = 0; i < height - 1; i++){
        for(j = 1; j < width - 1; j++){
            if(i == y && j == x){
                for(k = i; k < i + 3; k++){         
                    map[k][j + 1] = 0;
                    if(k == i + 2){
                        map[k][j] = 0;
                    }
                }
            }
        }
    }
}


/* 
    *
    * * *
*/

int drawLr1(int map[15][10], int width, int height, int x, int y){
    int k, i , j, f = 1;
    for(i = 0; i + 1 < height - 1; i++){
        for(j = 1; j + 2 < width - 1; j++){
            if(i == y && j == x){
                for(k = j; k < j + 3; k++){
                    if(map[i][k] == 1 || map[i + 1][j] == 1){
                        printf("\nPiece cannot be here \n");
                        return 0;
                    }
                }
                
                for(k = j; k < j + 3; k++){         
                    map[i + 1][k] = 1;
                    if(k == j){
                        map[i][k] = 1;
                    }
                }
                return 1;

            }
        }
    }

    return f;
}

void deleteLr1(int map[15][10], int width, int height, int x, int y){
    int k, i , j;
    for(i = 0; i < height - 1; i++){
        for(j = 1; j < width - 1; j++){
            if(i == y && j == x){
                for(k = j; k < j + 3; k++){         
                    map[i + 1][k] = 0;
                    if(k == j){
                        map[i][k] = 0;
                    }
                }
            }
        }
    }
}


/* 
    * *
    *
    * 
*/

int drawLr2(int map[15][10], int width, int height, int x, int y){
    int k, i , j, f = 1;
    for(i = 0; i + 2 < height - 1; i++){
        for(j = 1; j + 1 < width - 1; j++){
            if(i == y && j == x){
                for(k = i; k < i + 3; k++){
                    if(map[k][j] == 1 || (map[k][j + 1] == 1 && k == i) ){
                        printf("\nPiece cannot be here \n");
                        return 0;
                    }
                }
                
                for(k = i; k < i + 3; k++){         
                    map[k][j] = 1;
                    if(k == i){
                        map[k][j + 1] = 1;
                    }
                }
                return 1;

            }
        }
    }

    return f;
}

void deleteLr2(int map[15][10], int width, int height, int x, int y){
    int k, i , j;
    for(i = 0; i < height - 1; i++){
        for(j = 1; j < width - 1; j++){
            if(i == y && j == x){
                for(k = i; k < i + 3; k++){         
                    map[k][j] = 0;
                    if(k == i){
                        map[k][j + 1] = 0;
                    }
                }
            }
        }
    }
}


/* 
    * * *
        *
*/

int drawLr3(int map[15][10], int width, int height, int x, int y){
    int k, i , j, f = 1;
    for(i = 0; i + 1 < height - 1; i++){
        for(j = 1; j + 2 < width - 1; j++){
            if(i == y && j == x){
                for(k = j; k < j + 3; k++){
                    if(map[i][k] == 1 || map[i + 1][j + 2] == 1){
                        printf("\nPiece cannot be here \n");
                        return 0;
                    }
                }
                
                for(k = j; k < j + 3; k++){         
                    map[i][k] = 1;
                    if(k == j + 2){
                        map[i + 1][k] = 1;
                    }
                }
                return 1;

            }
        }
    }

    return f;
}

void deleteLr3(int map[15][10], int width, int height, int x, int y){
    int k, i , j;
    for(i = 0; i < height - 1; i++){
        for(j = 1; j < width - 1; j++){
            if(i == y && j == x){
                for(k = j; k < j + 3; k++){         
                    map[i][k] = 0;
                    if(k == j + 2){
                        map[i + 1][k] = 0;
                    }
                }
            }
        }
    }
}


/* Lr, Lr1, Lr2, Lr3 */
/* T = 0  Z = 1  I = 2  L = 3  Lr = 4  O = 5 */
/* O */

/* 
    * *
    * *
*/

int drawO(int map[15][10], int width, int height, int x, int y){
    int k, i , j, f = 1;
    for(i = 0; i + 1 < height - 1; i++){
        for(j = 1; j + 1 < width - 1; j++){
            if(i == y && j == x){
                for(k = j; k < j + 2; k++){
                    if(map[i][k] == 1 || map[i + 1][k] == 1){
                        printf("\nPiece cannot be here \n");
                        return 0;
                    }
                }
                
                for(k = j; k < j + 2; k++){         
                    map[i][k] = 1;
                    map[i + 1][k] = 1;
                }
                return 1;

            }
        }
    }

    return f;
}

void deleteO(int map[15][10], int width, int height, int x, int y){
    int k, i , j;
    for(i = 0; i < height - 1; i++){
        for(j = 1; j < width - 1; j++){
            if(i == y && j == x){
                for(k = j; k < j + 2; k++){         
                    map[i][k] = 0;
                    map[i + 1][k] = 0;
                }
            }
        }
    }
}


