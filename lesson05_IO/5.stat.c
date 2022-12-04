       #include <sys/types.h>
       #include <sys/stat.h>
       #include <unistd.h>
#include <stdio.h>
       /*
        int stat(const char *pathname, struct stat *statbuf);
       作用：获取一个文件相关的一些信息
       参数： 
            路径
            结构体变量，传出参数
                保存获取到的文件信息
                成功： 0
                失败： -1
       */
        int main(){
            struct stat statbuf;
            int ret = stat("copy.txt", &statbuf);

            if(ret == -1){
                perror("stat");
                return -1;
            }
            printf("size:%ld\n", statbuf.st_size);
            return 0;
        }