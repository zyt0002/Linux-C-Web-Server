#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
// int open(const char *pathname, int flags, mode_t mode);
/* 参数 ： 路径  操作方式 可选项（可变长参数）

linux下文件操作权限含义： 
-rwx-rwx-r--  每3个一组
文件类型-owner权限-组权限-其他用户权限
umusk:设置操作权限

mode:八进制的数，创建新文件操作权限，最终权限是：
 mode & ~umask  (取反)
*/
int main(){
    int fd = open("create.txt",O_RDWR | O_CREAT, 0777);
    if(fd==-1){
        perror("open");
    }
    close(fd);

    return 0;
}