#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int go = 1;
int type = 0;
char input[50];

//type 1 commands
void hello(){
    printf("Greetings!");
}

void bye(){
    printf("I am terminating the run now. Goodbye!");
    go = 0;
}

void assignment(){
    printf("202 lab #1 (Spring 2022)");
}

void author(){
    printf("Name: Steve Cha\n");
    printf("N-Number: N15395792\n");
    printf("NetID: TSC363");
}

void section(){
    printf("Section 003");
}

//determine if it's type 1 or type 2 command
void determineType(){
    int t = 0;
    int hello = 1;
    hello = strcmp(input, "hello");
    int bye = 1;
    bye = strcmp(input, "bye");
    int assignment = 1;
    assignment = strcmp(input, "assignment");
    int author = 1;
    author = strcmp(input, "author");
    int section = 1;
    section = strcmp(input, "section");
    t = hello * bye * assignment * author * section;
    if(t == 0){
        type = 1;
    }
    else{
        type = 2;
    }
}

void main(){

    //while go is 1 do this loop
    while(go == 1){
        //asks user to enter the command and retrieves the command from the terminal
        printf("Enter command: ");
        fgets(input, 50, stdin);
        //strip \n at the end of input
        size_t len = strlen(input);
        if(len > 0 && input[len - 1] == '\n'){
            input[len - 1] = '\0';
        }
        if(input == "hello"){
            printf("STeve too nice");
        }
        //check if command is t1 or t2, changes the variable "type" to 1 or 2 accordingly
        determineType();

        //if type 1, run respective type 1 commands
        if(type == 1){
            if(strcmp(input, "hello") == 0){
                hello();
                printf("\n");
            }
            if(strcmp(input, "bye") == 0){
                bye();
                printf("\n");
                go = 0;
            }
            if(strcmp(input, "assignment") == 0){
                assignment();
                printf("\n");
            }
            if(strcmp(input, "author") == 0){
                author();
                printf("\n");
            }
            if(strcmp(input, "section") == 0){
                section();
                printf("\n");
            }
        }



        //if type 2,
        else{
            //two processes
            int parentOrChild;
            int status;
            parentOrChild = fork();
            //child process
            if(parentOrChild == 0){
                status = 0;
                char bin[60];
                strcpy(bin, "/usr/bin/");
                strcpy(input, input);
                strcat(bin, input);
                //printf(bin);
                char *argv[2][50] = {
                    {bin},
                    {NULL}
                };
                execve(bin, argv, NULL);
            }
            //parent process
            else{
                wait(&status);
            }
        }




        //reset variables
        type = 0;
        memset(input, 0, sizeof(input));
    }
}


