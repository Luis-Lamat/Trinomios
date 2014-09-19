//
//  main.cpp
//  Triominos
//
//  Created by Luis Alberto Lamadrid on 9/18/14.
//  Copyright (c) 2014 Luis Alberto Lamadrid. All rights reserved.
//

#include <iostream>
using namespace std;

char mat[8][8];
char paint = '@';

// formula to calculate quadrant of two numbers
int which_quadrant(int x, int y, int size){
    int half = size/2;
    if (x <= half){ if (y <= half) return 1; else return 2; }
    else {          if (y <= half) return 3; else return 4; }
}

// recursive formula to fill matrix with l's
void triomino(int renI, int renF, int colI, int colF, int posX, int posY){
    
    //increase global paint variable
    paint++;
    
    // base case, paint L shaped figure...
    if (renF - renI == 1 && colF - colI == 1) {
        if (mat[renI][renF] == '@')
            mat[renI][renF] = paint;
        if (mat[renI+1][renF] == '@')
            mat[renI+1][renF] = paint;
        if (mat[renI][renF+1] == '@')
            mat[renI][renF+1] = paint;
        if (mat[renI+1][renF+1] == '@')
            mat[renI+1][renF+1] = paint;
    }
    
    // if the square matrix is not 2 X 2
    else {
        
        // calculate middle row and column
        int renMid = (renF+renI)/2;
        int colMid = (colF+colI)/2;
        
        // calculate quadrant of occupied square
        int q = which_quadrant(posX, posY, renF);
        
        // paint L in center if quadrant is not the same as position
        if(q != 1) mat[renMid][colMid] = paint;
        if(q != 2) mat[renMid][colMid+1] = paint;
        if(q != 3) mat[renMid+1][colMid] = paint;
        if(q != 4) mat[renMid+1][colMid+1] = paint;
    }
    
    return;
}

int main()
{
    // Initializing matrix with '@'s
    for (int i = 0; i < 8; ++i) {
        for (int k = 0; k < 8; ++k) {
            mat[i][k] = '@';}
    }
    
    // Declaration of user input variables &
    // Input of said variables
    int posX,posY;
    cout << "Introduce las coordenadas del cuadro base (0-7) :  ";
    cin >> posX >> posY;

    // Don't let user through if variables are in invalid range
    while ((posX < 0 || posX > 7) || (posY < 0 || posY > 7)) {
        cout << "Números inválidos, intente de nuevo (0-7): ";
        cin >> posX >> posY;
    }

    // increase paint char and paint the spot the user inputs
    paint++;
    mat[posX][posY] = paint;
    
    // L painting method call
    triomino(0, 7, 0, 7, posX, posY);
    
    /* PRINTS MATRIX START */
    cout << endl;
    for (int i = 0; i < 8; ++i){
        for (int k = 0; k < 8; ++k){
            cout << mat[i][k] << " ";}
        cout << endl;}
    cout << endl;
    /* PRINTS MATRIX ENDS */
    
    
    return 0;
}

