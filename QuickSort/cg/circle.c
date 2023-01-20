#include "stdio.h"

int main(int argc, const char *argv[]){
    int rad,x,y;
    printf("please enter radius: ");
    scanf("%d", &rad);
    for(y = rad; y>= -rad; y--){
        for(x = -rad; x <= rad; x++){
            if(x*x + y*y <= rad*rad)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

}