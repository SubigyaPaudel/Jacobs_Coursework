#include <stdio.h>

void total_time(int min[], int sec[], int n, int* sum_min, int* sum_sec){
    *sum_min=0;
    *sum_sec=0;
    for(int i =0; i < n; i++)
        *sum_sec += sec[i];
    int addtomin = *sum_sec / 60;
    for(int j = 0; j < n; j++)
        *sum_min += min[j];
    *sum_min += addtomin;
    *sum_sec = *sum_sec % 60;
}

int main(){
    int sum_mins, sum_secs;
    int mins[5] = {1,2,3,4,5};
    int secs[5] = {10, 20, 30, 40, 50};
    total_time(mins, secs, 5, &sum_mins, &sum_secs);
    printf("Sum = %d minutes, %d seconds",sum_mins, sum_secs);
    return 0;
}