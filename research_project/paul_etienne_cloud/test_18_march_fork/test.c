#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
int status,pipedes[2];
char buf[100];
// int len;
char msg[]="Salut Fred !";
if (pipe(pipedes))
exit(1);
if (fork()) { /* Code du pere */
printf("père\n");
write(pipedes[1],msg,strlen(msg));
printf("ok, envoyé\n");
wait(&status);
return 0;
}
else { /* Code du fils */
printf("fils\n");
read(pipedes[0],buf,100);
printf("Mon pere adore l'art de decaler les sons : %s\n",buf);
return 0;
}
}