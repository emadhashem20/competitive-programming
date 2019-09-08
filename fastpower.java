static long PowerMod(int a, int b, int c){// a^b %c
 
    long v=a, r=1;
 
    while(b!=0){
 
        if(b%2==0){
            b /= 2;
            v = v*v%c;
        }else{
            r = r*v%c;
            b--;
        }
 
    }
 
    return  (r%c);
}
