       #include <unistd.h>
       #include <stdio.h>

    //    int access(const char *pathname, int mode);
    /*判断文件权限/是否存在
    参数：路径
    mode： 权限
    R_OK    是否有读权限
    W_OK       写
    X_OK        
    F_OK  是否存在

    返回： 成功返回0 
        失败返回-1
        */
       int main(){
        int ret = access("a.txt",F_OK);
       if (ret == -1){
        perror("access");
        _exit(-1);
       }
       printf("File exists");
       return 0;
       }