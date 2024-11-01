#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 256 
#define MAX_FILEPATH 256
#define OUT_FILE "out.txt"

void copy_file() {
    char filename[MAX_FILEPATH];
    printf("enter the file path:");
    scanf("%s",filename);
    int input_file_descripter=open(filename,O_RDONLY,0);
    if(input_file_descripter==-1){
        printf("error in reading the file.");
        return;
    }
    printf("input file descriptor: %d\n",input_file_descripter);


    char buf[BUF_SIZE];
    int n;

    int output_file_descripter=open(OUT_FILE,O_RDWR,0);
    if(output_file_descripter==-1){
        output_file_descripter=creat(OUT_FILE,0666);
        if(output_file_descripter==-1){
            printf("error in opening output file: %d\n",output_file_descripter);
            return;
        }
    }
    printf("output file descripter: %d\n",output_file_descripter);

    while((n=read(input_file_descripter,buf,BUF_SIZE))>0)
        write(output_file_descripter,buf,n);
    return;   
}

int main() {
    copy_file();
    return 0;
}
