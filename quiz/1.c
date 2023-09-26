#include <stdio.h>

int c=10;
int f(int n){
    if (0 ==n)
        return n+c;
    else
        return f(f(n-1) - c);
}
int main(){
    printf("%d\n", f(4));
    return 0;
}