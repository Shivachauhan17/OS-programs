#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#define BUF_SIZE 256 
#define MAX_FILEPATH 256
#define OUT_FILE "out.txt"

void copy_file() {
    char filename[MAX_FILEPATH];
    printf("enter the file path:");
    scanf("%s",filename);
    int input_file_descripter=open(filename,O_RDONLY,0);
    if(input_file_descripter==-1){
        perror("Error opening source file");//system generated error prefix
        exit(EXIT_FAILURE);//this exist status will be accessible to others
    }
    printf("input file descriptor: %d\n",input_file_descripter);


    char buf[BUF_SIZE];
    int n;

    int output_file_descripter=open(OUT_FILE,O_RDWR,0);
    if(output_file_descripter==-1){
        output_file_descripter=creat(OUT_FILE,0666);
        if(output_file_descripter==-1){
            perror("Error opening/creating destination file");
            close(input_file_descripter);
            exit(EXIT_FAILURE);
        }
    }
    printf("output file descripter: %d\n",output_file_descripter);
    int m;
    while((n=read(input_file_descripter,buf,BUF_SIZE))>0){
        m=write(output_file_descripter,buf,n);
        if(m!=n){
            perror("Error writing to destination file");
            close(input_file_descripter);
            close(output_file_descripter);
            exit(EXIT_FAILURE);
        }
    }
    return;   
}

int main() {
    copy_file();
    return 0;
}

//trace system calls 
//strace ./copy_file 
