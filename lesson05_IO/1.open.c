#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
/* 打开一个已存在文件
int open(const char *pathname, int flags);

参数：路径
flags：对文件操作权限设置
O_RDONLY,O_WRONLY, or O_RDWR. 
read-only,  write-only, or read/write, respectively.
    返回值： 
    失败 -1
    成功 新的文件描述符

errno：系统函数库全局变量，记录最近的错误号

*/


/* #include <stdio.h>

       void perror(const char *s);  

       #include <errno.h>

       打印eroor number的错误描述
*/



int main(){
    int fd = open("a.c",O_RDONLY);

    if (fd = -1){
        perror("open");
    }

    close(fd);

    return 0;
}



