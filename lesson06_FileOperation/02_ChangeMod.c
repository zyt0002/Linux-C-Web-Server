       #include <sys/stat.h>
       #include <stdio.h>
       #include <stdlib.h>
       
    //    int chmod(const char *pathname, mode_t mode);
    /*
    mode：权限值， 八进制数
    返回：成功0
        失败-1
    */
   int main(){
    int ret = chmod("a.txt", 0777);
    if(ret == -1){
        perror("chmod");
        exit(-1);
    }
    printf("change mod sucess!");
    return 0;
   }