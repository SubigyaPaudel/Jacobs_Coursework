#ifndef N_HORSES_H
#define H_HOSRSES_H
#include <iostream>
#include <cstdlib>
#include <string>

enum class vacant{
    Allowed, 
    Forbidden
};

class chessboard{
    private:
        vacant** board;
        int dimensions;
        
    public:
    chessboard(int n){
        dimensions = n;
        board = new vacant*[n];
        for(int i = 0; i < n; i++)
            board[i] = new vacant[n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                board[i][j] = vacant::Allowed;
        }
    }
};

#endif