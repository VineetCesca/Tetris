void initMap(int map[15][10]){
    int i, j;
    for(i = 0; i < height; i++){
        for(j = 0; j < width; j++){
            map[i][j] = 0;
        }
    }
}

void setCursor(int *x, int *y, int vx, int vy){
    *x = vx;
    *y = vy;
}

void initAvaiblePieces(int *pieces, int dim, int limit){ /* T  Z  I  L Lr  O */
    int i;                                    /* 0  1  2  3  4  5 */
    for(i = 0; i < dim; i++){
        pieces[i] = limit;
    }
}

