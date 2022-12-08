  #include <stdio.h>

    //    int rename(const char *oldpath, const char *newpath);

    int main(){
        int ret = rename("dir1","dir2");
        if(ret == -1){
            perror("rename");
            return -1;
        }
            return 0;
    
    }
