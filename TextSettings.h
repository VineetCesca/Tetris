void centerText(int n){
    int i;
    for(i = 0; i < n/2; i++){
        printf(" ");
    }
}

void setcolorText(char *color, int bold){

    if( (color == "black" || color == "BLACK" || color == "Black") && (bold == 1 || bold == 0) ){
        printf("\033[%d;30m", bold);
    } else if( (color == "red" || color == "RED" || color == "Red") && (bold == 1 || bold == 0) ){
        printf("\033[%d;31m", bold); /*funziona anche così*/
    } else if( (color == "green" || color == "GREEN" || color == "Green") && (bold == 1 || bold == 0) ){
        printf("\033[%d;32m", bold);
    } else if( (color == "yellow" || color == "YELLOW" || color == "Yellow") && (bold == 1 || bold == 0) ){
        printf("\033[%d;33m", bold);
    } else if( (color == "blue" || color == "BLUE" || color == "Blue") && (bold == 1 || bold == 0) ){
        printf("\033[%d;34m", bold);
    } else if( (color == "purple" || color == "PURPLE" || color == "Purple") && (bold == 1 || bold == 0) ){
        printf("\033[%d;35m", bold);
    } else if( (color == "cyan" || color == "CYAN" || color == "Cyan") && (bold == 1 || bold == 0) ){
        printf("\033[%d;36m", bold);
    } else if( (color == "white" || color == "WHITE" || color == "White") && (bold == 1 || bold == 0) ){
        printf("\033[%d;37m", bold);
    }
}

void saltaRighe(int N){
    int i;
    for(i = 0; i < N; i++){
        printf("\n");
    }
}
