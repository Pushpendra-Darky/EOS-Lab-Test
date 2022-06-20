#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define MAX_SIZE 10240
int main()
{
    unsigned char buff[MAX_SIZE];
    int fdr;
    int i=0;
    int count=0;
    

    fdr = open("fifoIPC",O_RDONLY);
    
    int ssize_t = read(fdr,buff,sizeof(buff));
    if(ssize_t == -1)
    {
        perror("Error In Reading\n");
        exit(EXIT_FAILURE);
    }

    while(buff[i]!= '\0')
    {
    	if(buff[i]=='s')
    	count++;
    }
    printf("Read Data:%s",buff);
    printf("Number Of Occurence Of s Character : %d",count);
    close(fdr);
    return 0;
}