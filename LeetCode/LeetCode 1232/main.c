#include <stdio.h>
#include <stdlib.h>

bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize){
    double k = 0;
    int i,j;
    k = ((double)(coordinates[1][1] - coordinates[0][1])) / (coordinates[1][0] - coordinates[0][0]);//前两点的斜率
    for(i = 1; i < coordinatesSize - 1; i++) {
        if(((double)(coordinates[i + 1][1] - coordinates[i][1])) / (coordinates[i + 1][0] - coordinates[i][0]) != k)//斜率相等就说明在一条线上
            return false;
    }
    return true;
}
