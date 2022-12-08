       #include <sys/stat.h>
       #include <sys/types.h>
       #include <stdio.h>

    //    int mkdir(const char *pathname, mode_t mode);
    /*
    mode：权限，八进制的数
         The  argument  mode  specifies the mode for the new directory (see inode(7)).
       It is modified by the process's umask in the usual way: in the absence  of  a
       default  ACL,  the  mode  of the created directory is (mode & ~umask & 0777).
       Whether other mode bits are honored for the created directory depends on  the
       operating system.  For Linux, see NOTES below.
    返回：成功 0
    失败  -1

    rmdir 函数只能删除空目录
    */
   int main(){
    // int ret = mkdir("dir1",777);
    int ret = mkdir("dir1",0777);

    if(ret == -1){
        perror("mkdir");
        return -1;
    }
    return 0;
   }