       #include <sys/types.h>
       #include <dirent.h>
#include <stdio.h>
#include <string.h>

    
    /*
         DIR *opendir(const char *name);
        参数：name，目录名称
        返回：DIR*，目录流
        错误返回NULL


       struct dirent *readdir(DIR *dirp);
        读取目录数据
        返回结构，代表读取文件的信息
          struct dirent {
               ino_t          d_ino;       Inode number 
               off_t          d_off;        Not an offset; see below 
               unsigned short d_reclen;     Length of this record 
               unsigned char  d_type;       Type of file; not supported
                                              by all filesystem types 
               char           d_name[256];  Null-terminated filename 
           }
        失败返回null

       int closedir(DIR *dirp);
*/
int getFileNum(const char * path);

    int main(int argc, char* argv[]){
//读取某目录下所有普通文件个数，递归读
        if(argc <2){
            printf("%s path\n", argv[0]);
            return -1;
        }
        int num = getFileNum(argv[1]);

        printf("当前目录文件个数为%d\n",num);


return 0;
}

int getFileNum(const char * path){
    DIR * dir = opendir(path);
    if(dir == NULL){
        perror("opendir");
        return -1;
    }

struct dirent * ptr;
    int total = 0;

    while ((ptr = readdir(dir)) != NULL)
    {
        char *dname = ptr->d_name;
        if (strcmp(dname,".")==0 || strcmp(dname,"..")==0)
            continue;
        if (ptr->d_type == DT_DIR){
            //递归读取目录
            char newpath[256];
            sprintf(newpath,"%s/%s",path, dname);
            total += getFileNum(newpath);
        }

        if(ptr->d_type == DT_REG){
            //普通文件
            total++;
        }

    }
    
     closedir(dir);

    return total;
}