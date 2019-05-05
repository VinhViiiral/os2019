#include<stdio.h> 
#include<unistd.h>

int main(){ 
        printf("Before fork:\n");
        int pid = fork();
        if (pid == 0){
                int pid2 = fork();
                if (pid2 == 0){
                        printf("child is printing...");
                        char* args[] = {"/bin/ps ", "-ef", NULL};
                        execvp("/bin/ps", args);
                    }
			    else {
                        printf("child free!");
                        char* args[] = {"free", "-h", NULL};
                        execvp("free", args);
        };
        return 0;
}
}

