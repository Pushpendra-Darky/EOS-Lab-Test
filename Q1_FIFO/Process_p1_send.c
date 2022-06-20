#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define MAX_SIZE 10240
unsigned char buff[MAX_SIZE];

int main()
{
    int fdf;
    int fdr;
    int rd,wr;

    fdr=open("/usr/include/stdio.h",O_RDONLY);
    if(fdr == -1)
    {
        perror("ERROR IN OPENING FILE\n");
        exit(EXIT_FAILURE);
    }
    else 
    {
    while(1)
    {
        rd=read(fdr, buff,MAX_SIZE);
        
        if (EOF ==rd)
        {
            break;
        }
        fdf = open("fifoIPC",O_WRONLY);
        wr=write(fdf,buff,rd); 

        if (EOF == wr)
        {
            break;
        }  
    }
    printf("\nData Sent Succesfully\n");
    }
    close(fdr);
    close(fdf);
    return 0;

}