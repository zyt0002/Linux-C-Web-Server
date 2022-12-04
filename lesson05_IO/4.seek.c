#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
/*
   off_t lseek(int fd, off_t offset, int whence);
      
      offset：偏移量
      SEEK_SET
            偏移量= 设置文件指针的偏移量
       SEEK_CUR
            偏移量= 当前位置+第二个参数offset的值
       SEEK_END
            偏移量= 文件大小+offset
    返回：文件指针位置

    作用
    1. 移动文件指针到头文件
        lseek(fd,0,seek_set)
    2. 获取当前文件指针位置
        lseek(fd,0,set_cur)
    3.获取文件长度
        lseek(fd,0,seek_end)
    4. 扩展文件长度：需要写数据
        lseek(fd,100,SEEK_END)
*/
    int main(){
        int fd = open("copy.txt",O_RDWR);
        if(fd==-1){
            perror("open");
            _exit(-1);
        }

        //写入数据才能扩展
        int ret = lseek(fd,1000,SEEK_END);
        printf("%d",ret);
        write(fd," ",1);        
        close(fd);
        return 0;
    }