
#include <stdio.h>

int main(void)
{
        FILE *pipein_fp, *pipeout_fp;
        char readbuf[80];

        if (( pipein_fp = popen("ls", "r")) == NULL)
        {
                perror("popen");
                exit(1);
        }

        if (( pipeout_fp = popen("sort", "w")) == NULL)
        {
                perror("popen");
                exit(1);
        }

	while(fgets(readbuf,80,pipein_fp))
		fputs(readbuf,pipeout_fp);
        pclose(pipein_fp);
        pclose(pipeout_fp);

        return(0);
}

