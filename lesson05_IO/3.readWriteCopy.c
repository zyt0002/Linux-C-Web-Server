#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>



// ssize_t read(int fd, void *buf, size_t count);
/*
fd open返回
buf 存放数据的地方
count 每次读取的大小
返回 
>0：实际读取字节数
=0 读取完
-1 失败 
*/


// ssize_t write(int fd, const void *buf, size_t count);
/*
fd open返回
buf 往磁盘写入的数据
count 写的字节大小

返回 
>0：实际读取字节数
-1 失败 
*/


int main(){
    int srcfd = open("english.txt", O_RDONLY);
    if(srcfd == -1){
        perror("open");
        return -1;
    }
    int destfd = open("copy.txt",O_WRONLY | O_CREAT, 0664);
    if(destfd == -1){
        perror("open");
        return -1;
    }
    char buf[1024] = {0};
    int len = 0;
    while ((len = read(srcfd, buf, sizeof(buf)))>0)
    {
        write(destfd, buf, len);

    }
    close(destfd);
    close(srcfd);
    


    return 0;
}