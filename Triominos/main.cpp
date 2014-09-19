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
int which_quadrant(int a, int b, int size){
    int half = size/2;
    if (a <= half){ if (b <= half) return 1; else return 2; }
    else {          if (b <= half) return 3; else return 4; }
}

// recursive formula to fill matrix with l's
void triomino(int renI, int renF, int colI, int colF, int posY, int posX){
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
    int a,b;
    cout << "Introduce las coordenadas del cuadro base (0-7) :  ";
    cin >> a >> b;

    // Don't let user through if variables are in invalid range
    while ((a < 0 || a > 7) || (b < 0 || b > 7)) {
        cout << "Números inválidos, intente de nuevo (0-7): ";
        cin >> a >> b;
    }
    
    /* PRINTS MATRIX START */
    cout << endl;
    for (int i = 0; i < 8; ++i){
        for (int k = 0; k < 8; ++k){
            cout << mat[i][k] << " ";}
        cout << endl;}
    cout << endl;
    /* PRINTS MATRIX ENDS */
    
    cout << which_quadrant(3, 3, 8) << endl;
    
    return 0;
}

