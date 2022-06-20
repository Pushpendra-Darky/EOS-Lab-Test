#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<semaphore.h>

#define MAX_SIZE 10240
int *count = NULL;
unsigned char buff[MAX_SIZE];
int main()
{
    int shm_fd;
    int frd;

    sem_t *count_sem;
    count_sem = sem_open("/shared_shmsem", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP,1);

    shm_fd = shm_open("/shared_shm",O_CREAT | O_RDWR,S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);

    if(-1 == shm_fd)
    {
        perror("shm_open: Error In Opening\n");
        return (EXIT_FAILURE);
    }

    ftruncate(shm_fd,sizeof(int));

    count = (int *)mmap(NULL,sizeof(int),PROT_READ | PROT_WRITE, MAP_SHARED,shm_fd,0);

    frd=open("/usr/include/stdio.h",O_RDONLY);
    if(frd ==-1)
    {
        perror("ERROR IN OPENING FILE\n");
        exit(EXIT_FAILURE);
    }
    else

    while(frd != EOF)
    {
       // sem_wait(count_sem);
        *count = read(frd,buff,sizeof(buff));
        printf("Occurence of s is %d\n",*count);

       // sem_post(count_sem);
    }

    sem_close(count_sem);
    sem_destroy(count_sem);
    
    return 0;
}