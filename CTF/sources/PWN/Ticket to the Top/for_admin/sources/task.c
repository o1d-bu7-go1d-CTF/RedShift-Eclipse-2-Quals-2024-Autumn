#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user{
    char username[32];
    char password[64];
};

typedef struct ticket {
    void (*display)(struct ticket*);
    char username[32];
    char content[24];
} Ticket;

void display(Ticket *t){
    printf("%s\n", t->content);
}

char login(struct user *u){
    char secret[16] = "";
    char c;

    FILE *fp = fopen(".passwd", "r");
    fread(secret, 1, 15, fp);
    fclose(fp);
    secret[15] = '\0';

    if (strcmp(u->password, secret) == 0 && strcmp(u->password, "admin") == 0) {
        return 1;
    } else {
        return 0;
    }
}

void admin(){
    printf("You realy thiks that you can get the flag?\n");
}

void win(){
    FILE *file = fopen("FLAG.md", "r");
    if (file == NULL) {
        printf("Не удалось открыть файл FLAG.md\n");
        return;
    }
    
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    printf("\n");
    
    fclose(file);
}

int main(int argc, char **argv){
  setvbuf(stdout, NULL, _IONBF, 0);
    int log;
    char c=1, i;
    char buf[8];
    
    struct user *u = malloc(sizeof(struct user));
    strcpy(u->username, "Guest");
    strcpy(u->password, "");
    
    struct ticket *t = malloc(sizeof(struct ticket));
    t->display = display;
    strcpy(t->content, "");
    strcpy(t->username, u->username);

    while(c){
        printf("Press enter char to continue...");
        fgets(buf, 8, stdin);
        getchar();
        printf("\e[1;1H\e[2J");
        printf("Welcome %-10s.\nWhat to do you want to do ?\n", u->username);
        printf("1 - Read ticket\n");
        printf("2 - Create ticket\n");
        printf("3 - Delete ticket\n");
        printf("4 - Submit tickets\n");
        printf("5 - login\n");
        printf("0 - Exit\n");
        printf("Choice > ");
        scanf("%1s", buf);
        i = buf[0];
        printf("\e[1;1H\e[2J");
        switch (i) {
            case '0':
                c = 0;
                break;
            case '1':
                printf("Resume : \n");
                t->display(t);
                break;
            case '2':
                printf("Ticket content : \n");
                scanf("%24s",t->content);
                fflush(stdout);
                break;
            case '5':
                printf("Please enter credentials : \n");
                printf("Username : ");
                scanf("%s", u->username);
                printf("Password : ");
                scanf("%s", u->password);
                if (login(u) == 1){
                  admin();
                }
                break;
            default:
                printf("Function not yet implemented !\n");
        }
    }
    return 0;
}
