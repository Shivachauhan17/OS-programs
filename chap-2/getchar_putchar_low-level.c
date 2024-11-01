#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


char ll_getchar(){
    char c;
    return (read(0,&c,1)==1)?(unsigned char) c:EOF;
}

chat  

int main(){
    char c;
    while(1){
        c=ll_getchar();
        if(c==EOF){
            break;
        }
        printf("%c",c);
    }
    
    return 0;
}