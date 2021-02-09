#include "number_maze.h"
#include <iostream>
#include <ctime>
#include <limits>

Puzzleboard::Puzzleboard(int dimension){
    this->dimension = dimension;
    board = new int*[dimension];
    for(int i = 0; i < dimension; i++)
        board[i] = new int[dimension];
    currentposition = new int[2];
    currentposition[0] = currentposition[1] = 0;
    srand((unsigned) time(0));
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            board[i][j] = rand() % (dimension) + 1;
            
        }
    }
}

bool Puzzleboard::makemove(int direction){
    while(true){
        if(direction == 0){
            if(currentposition[0] - board[currentposition[0]][currentposition[1]] < 0){
                return false;
            }else{
                currentposition[0] -= board[currentposition[0]][currentposition[1]];
                return true;
            }
            break;
        }else if(direction == 3){
            if(currentposition[1] - board[currentposition[0]][currentposition[1]] < 0){
                return false;
            }else{
                currentposition[1] -= board[currentposition[0]][currentposition[1]];
                return true;
            }
            break;
        }else if(direction == 2){
            if(currentposition[0] + board[currentposition[0]][currentposition[1]] < dimension){
                currentposition[0] += board[currentposition[0]][currentposition[1]];
                return true;
            }else{
                return false;
            }
            break;
        }else if(direction == 1){
            if(currentposition[1] + board[currentposition[0]][currentposition[1]] < dimension){
                currentposition[1] += board[currentposition[0]][currentposition[1]];
                return true;
            }else{
                return false;
            }
            break;
        }else{
            std::cout << "Wrong command, enter the command again" << std::endl;
        }
    }
}

bool Puzzleboard::getresult(){
    int n = dimension - 1;
    if(currentposition[0] == n && currentposition[1] == n){
        return true;
    }else{
        return false;
    }
}

void Puzzleboard::printboard(){
    for(int i = 0 ; i < dimension; i++){
        std::cout << "|" ;
        for(int j = 0 ; j < dimension; j++){
                std::cout << board[i][j] << "|";
        }
        std::cout << std::endl;
    }
}