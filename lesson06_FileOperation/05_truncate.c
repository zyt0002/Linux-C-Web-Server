       #include <unistd.h>
       #include <sys/types.h>

       #include <stdio.h>

    //    int truncate(const char *path, off_t length);
    /*
    扩展/缩减文件尺寸
    最终文件大小
    */

int main(){
    int ret = truncate("a.txt",5);
    if (ret == -1){
        perror("truncate");
        _exit(-1);
    }
    printf("truncate sucess1");
    return 0;
}