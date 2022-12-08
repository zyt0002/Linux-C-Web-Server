       #include <unistd.h>
        #include <stdio.h>
        #include <fcntl.h>
        #include <sys/stat.h>
        #include <sys/types.h>
        #include <string.h>
       /*
       int dup(int oldfd);
       复制文件描述符

       int dup(int oldfd)
        作用：
       */
      int main(){
        int fd = open("a.txt", O_RDWR|O_CREAT,0664);
        int fd1 = dup(fd);
        //error

        printf("fd :%d , fd1 : %d \n", fd, fd1);

        close(fd);
        char * str = "test";
        int ret = write(fd1, str ,strlen(str));
        //error

        close(fd1);
 }