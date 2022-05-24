/**
 * Initializes the map
 * @param[out] map game map
 */
void initMap(int map[15][10]){
    int i, j;
    for(i = 0; i < height; i++){
        for(j = 0; j < width; j++){
            map[i][j] = 0;
        }
    }
}

/**
 * Set the Cursor object
 * 
 * @param[out] x Cursor x coord.
 * @param[out] y Cursor y coord.
 * @param[in] vx x value
 * @param[in] vy y value
 */
void setCursor(int *x, int *y, int vx, int vy){
    *x = vx;
    *y = vy;
}

/**
 * Initializes avaible pieces array
 * 
 * @param[out] pieces points to the avaible array
 * @param[in] dim avaible array's size
 * @param[in] limit a max value of availability
 */
void initAvaiblePieces(int *pieces, int dim, int limit){ /* T  Z  I  L Lr  O */
    int i;                                    /* 0  1  2  3  4  5 */
    for(i = 0; i < dim; i++){
        pieces[i] = limit;
    }
}

