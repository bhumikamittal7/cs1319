int main();
int x = 2;

int main(){
    x = 5;
    if(x == 5){
        int i = 0;
        for(i = 0; i < 10; i = i + 1){
            x = x * x;
        }
    }
    else x = 0;
    return x;
}