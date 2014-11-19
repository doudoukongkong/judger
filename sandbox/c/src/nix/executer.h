#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <sys/reg.h>
#include <sys/user.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <sys/syscall.h>
#include <signal.h>
#include <sys/time.h>
#include <pthread.h>

extern int max_time;         // max time
extern int max_mem;          // max memory
extern int array_len;        // syscall list length
extern int allow_syscall[];  // allow syscall list
extern int fd;               // debug log file
extern char* executable;     // executable path
extern int EXE_LEN;          // executable path length

char* read_config(const char* filename);
void parse_config_json(char* text);
int free_config_buffer(char* buffer);

