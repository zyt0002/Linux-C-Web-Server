       #include <sys/types.h>
       #include <unistd.h>
       #include <stdio.h>

       /*
       pid_t fork(void);
        创建子进程
        返回两次：
            成功：
                父进程：返回子进程PID
                子进程：成功： 返回0
            失败：
                父进程：返回-1，设置errorNum
               
       */
      int main(){
           pid_t pid = fork();    
        //    printf("pid:%d\n",pid); 
        if(pid>0){
            printf("pid:%d\n",pid);
            printf("i am parent process pid: %d  ppid:%d\n",getpid(),getppid());
        }
        else if(pid ==0){
            printf("i am child process pid: %d ppid:%d\n",getpid(),getppid());

        }
        for (int i = 0; i< 100; i++){
            printf("i:%d pid:%d\n",i,getpid());
            // sleep(1);
        }
        return 0;
      }