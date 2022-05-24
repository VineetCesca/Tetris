/* T, T1, T2, T3 */

/*  ***  */
/*   *   */

/** 
 * Goes to (x, y) coords and insert
 * '1' values in order to draw a T.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 * @return f: if (x, y) are out of map borders, 1: (x, y) coords are got filled, 0: if (x, y) coords are not empy
 */
int drawT(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '0' values in order to delete a T.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 */
void deleteT(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '1' values in order to draw a T1.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 * @return f: if (x, y) are out of map borders, 1: (x, y) coords are got filled, 0: if (x, y) coords are not empy
 */
int drawT1(int map[15][10], int x, int y){  /* */
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

/** 
 * Goes to (x, y) coords and insert
 * '0' values in order to delete a T1.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 */
void deleteT1(int map[15][10], int x, int y){  /* */
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

/** 
 * Goes to (x, y) coords and insert
 * '1' values in order to draw a T2.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 * @return f: if (x, y) are out of map borders, 1: (x, y) coords are got filled, 0: if (x, y) coords are not empy
 */
int drawT2(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '0' values in order to delete a T2.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 */
void deleteT2(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '1' values in order to draw a T3.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 * @return f: if (x, y) are out of map borders, 1: (x, y) coords are got filled, 0: if (x, y) coords are not empy
 */
int drawT3(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '0' values in order to delete a T3.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 */
void deleteT3(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '1' values in order to draw a Z.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 * @return f: if (x, y) are out of map borders, 1: (x, y) coords are got filled, 0: if (x, y) coords are not empy
 */
int drawZ(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '0' values in order to delete a Z.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 */
void deleteZ(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '1' values in order to draw a Z1.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 * @return f: if (x, y) are out of map borders, 1: (x, y) coords are got filled, 0: if (x, y) coords are not empy
 */
int drawZ1(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '0' values in order to delete a Z1.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 */
void deleteZ1(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '1' values in order to draw a Z2.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 * @return f: if (x, y) are out of map borders, 1: (x, y) coords are got filled, 0: if (x, y) coords are not empy
 */
int drawZ2(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '0' values in order to delete a Z2.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 */
void deleteZ2(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '1' values in order to draw a Z3.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 * @return f: if (x, y) are out of map borders, 1: (x, y) coords are got filled, 0: if (x, y) coords are not empy
 */
int drawZ3(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '0' values in order to delete a Z3.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 */
void deleteZ3(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '1' values in order to draw a I.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 * @return f: if (x, y) are out of map borders, 1: (x, y) coords are got filled, 0: if (x, y) coords are not empy
 */
int drawI(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '0' values in order to delete a I.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 */
void deleteI(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '1' values in order to draw a I1.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 * @return f: if (x, y) are out of map borders, 1: (x, y) coords are got filled, 0: if (x, y) coords are not empy
 */
int drawI1(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '0' values in order to delete a I1.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 */
void deleteI1(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '1' values in order to draw a L.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 * @return f: if (x, y) are out of map borders, 1: (x, y) coords are got filled, 0: if (x, y) coords are not empy
 */
int drawL(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '0' values in order to delete a L.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 */
void deleteL(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '1' values in order to draw a L1.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 * @return f: if (x, y) are out of map borders, 1: (x, y) coords are got filled, 0: if (x, y) coords are not empy
 */
int drawL1(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '0' values in order to delete a L1.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 */
void deleteL1(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '1' values in order to draw a L2.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 * @return f: if (x, y) are out of map borders, 1: (x, y) coords are got filled, 0: if (x, y) coords are not empy
 */
int drawL2(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '0' values in order to delete L2.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 */
void deleteL2(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '1' values in order to draw a L3.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 * @return f: if (x, y) are out of map borders, 1: (x, y) coords are got filled, 0: if (x, y) coords are not empy
 */
int drawL3(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '0' values in order to delete a L3.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 */
void deleteL3(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '1' values in order to draw a Lr.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 * @return f: if (x, y) are out of map borders, 1: (x, y) coords are got filled, 0: if (x, y) coords are not empy
 */
int drawLr(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '0' values in order to delete a Lr.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 */
void deleteLr(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '1' values in order to draw a Lr1.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 * @return f: if (x, y) are out of map borders, 1: (x, y) coords are got filled, 0: if (x, y) coords are not empy
 */
int drawLr1(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '0' values in order to delete a Lr1.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 */
void deleteLr1(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '1' values in order to draw a Lr2.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 * @return f: if (x, y) are out of map borders, 1: (x, y) coords are got filled, 0: if (x, y) coords are not empy
 */
int drawLr2(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '0' values in order to delete a Lr2.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 */
void deleteLr2(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '1' values in order to draw a Lr3.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 * @return f: if (x, y) are out of map borders, 1: (x, y) coords are got filled, 0: if (x, y) coords are not empy
 */
int drawLr3(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '0' values in order to delete a Lr3.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 */
void deleteLr3(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '1' values in order to draw a O.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 * @return f: if (x, y) are out of map borders, 1: (x, y) coords are got filled, 0: if (x, y) coords are not empy
 */
int drawO(int map[15][10], int x, int y){
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

/** 
 * Goes to (x, y) coords and insert
 * '0' values in order to delete a O.
 * (follow the Legenda)
 * @param[out] map game map
 * @param[in] x map x coord.
 * @param[in] y map y coord.
 */
void deleteO(int map[15][10], int x, int y){
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


