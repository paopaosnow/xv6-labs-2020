#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  if (argc < 2){
    fprintf(2,"sleep: missing arg ! please provide the duration for sleeping !\n");
    exit(1);

  }else{
    sleep(atoi(argv[1]));
    exit(0);

  }

//   for(i = 1; i < argc; i++){
//     write(1, argv[i], strlen(argv[i]));
//     if(i + 1 < argc){
//       write(1, " ", 1);
//     } else {
//       write(1, "\n", 1);
//     }
//   }
}