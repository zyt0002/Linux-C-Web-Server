       #include <unistd.h>

       int chown(const char *pathname, uid_t owner, gid_t group);
//        查看用户组方法：vim /etc/passwd

// orgtaoshao:x:1000:1000:ORGTAOSHAO,  用户名，所有者ID，所在组ID 

// vim /etc/group  查看组id

// useradd + name  增加用户