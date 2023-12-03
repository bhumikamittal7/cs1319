int main(){
    int a = (5==1);
    int b = (a == 0);
    int c = (a == b);
    int d;
    (a||b)? (d = 2) : (d = 1);
    (b && !c)? (d = -1) : (d = 999999999);
    return 0;
}