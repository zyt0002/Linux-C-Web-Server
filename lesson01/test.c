#include <stdio.h>
#include <unistd.h>

#define PI 3.14
int main(){
    int i = PI +10;
    printf("hello");
    while(1){
        printf("world\n");
        sleep(1);
    }
    return 0;
}