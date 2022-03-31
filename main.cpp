/*
 a program to generate a soduko game 
 and prompt the user to play it
 */

/* 
 * File:   main.cpp
 * Author: moham
 *
 * Created on 5 March 2021, 21:43
 */

#include <cstdlib>
#include <iostream>
#include <fstream.h>
#include "Sudoku.h"
#include <math.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
   int gridDimension,numberOfValues,value;
   
   Dyn2DArray initialGrid;
    ifstream f;
   f.open("C:\Users\moham\OneDrive\Documents\NetBeansProjects\project_1");//open the sudoku data file
   f>>numberOfValues;//insert the number of values from the file
   
   gridDimension=int (sqrt(numberOfValues));
   if((gridDimension*gridDimension)!=numberOfValues){
   //check if the grid dimension is a squre number(if the data represent a valid sudoku table)
   cerr<<"the number of values is not a square number";
   exit ;//exit the program if not
   }
   initialGrid=new int*[gridDimension];
   
   for(int i=0;i<gridDimension;i++){
    initialGrid[i]=new int[gridDimension];
    for(int j=0;j<gridDimension;j++){
       f>>value;//insert value from the file
       initialGrid[i][j]=value; //set the inititial grid element to value
      }
    }
   f.close();//close the file
   
   Sudoku mySudoku(initialGrid,gridDimension);//create a new sudoku object
  
   mySudoku.runGame();//call the method rungame to run the game a prompt the user to play it
   
   cout<<"thank you for playing this sudoku game";
   //thanks the user for playing
   
    return 0;
}

