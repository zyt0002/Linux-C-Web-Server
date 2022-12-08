       #include <unistd.h>
        #include <stdio.h>
        #include <fcntl.h>
        #include <sys/stat.h>
        #include <sys/types.h>
        #include <string.h>

        int main(){
            int fd1 = open("1.txt",O_WRONLY|O_CREAT,0664);
            int fd2 = open("2.txt",O_WRONLY|O_CREAT,0664);
            //error
            printf("fd1=%d fd2=%d\n",fd1,fd2);
            /*
            old fd:fd1
            new fd:fd2 
            把new重定向到old，关闭new
            实际上，操作fd2,等同于操作fd1
            */
            int ret = dup2(fd1,fd2);
            char * str = "this is dup2";
            int len = write(fd2,str,strlen(str));
            return 0;
        }