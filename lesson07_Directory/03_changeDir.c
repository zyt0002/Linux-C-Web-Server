       #include <unistd.h>
        #include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/*int chdir(const char *path);
修改进程的工作目录，参数：要修改为的工作目录

char *getcwd(char *buf, size_t size);
获取当前工作目录。
buf：存储路径（传出参数）
size:数组大小
返回：buf指向的一块内存，
*/

int main(){
    //pwd
    char buf[128];
    getcwd(buf,sizeof(buf));
    printf("wd : %s\n", buf);

    int ret = chdir("/home/orgtaoshao/WebServer");
    if(ret == -1){
        perror("chdir");
        return -1;
    }
//change Dir and create file
    int fd = open("chdir.txt", O_CREAT | O_WRONLY,0664);
    if (fd == -1){
        perror("open");
        return -1;
    }
    close(fd);

//pwd

    getcwd(buf,sizeof(buf));
    printf("wd : %s\n", buf);

    return 0;
    
}