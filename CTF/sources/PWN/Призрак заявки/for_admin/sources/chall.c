#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ticket.h"

char login(void){
    char username[16] = "";
    char password[16] = "";
    char secret[16] = "";
    char c;

    FILE *fp = fopen(".passwd", "r");
    fread(secret, 1, 15, fp);
    fclose(fp);
    secret[15] = '\0';

    printf("Username: ");
    fgets(username, sizeof(username), stdin);
    fflush(stdout);
    if (username[strlen(username)-1] == '\n'){
        username[strlen(username) -1] = '\0';
    }
    username[strlen(username)] = '\0';
    printf("Password: ");
    fflush(stdin);
    fgets(password, sizeof(password), stdin);
    if (password[strlen(password)-1] == '\n'){
        password[strlen(password) -1] = '\0';
    }

    if (strcmp(password, secret) == 0 && strcmp(username, "admin") == 0) {
        return 1;
    } else {
        return 0;
    }
}

void admin(void){
    printf("Welcome Admin !\n");
    char i, c = 1;
    while(c){
        printf("What to do you want to do ?\n");
        printf("1 - List all tickets\n");
        printf("2 - Read ticket\n");
        printf("3 - Close ticket\n");
        printf("0 - Exit\n");
        printf("Choice > ");
        scanf("%hhd", &i);
        printf("\e[1;1H\e[2J");
        switch (i) {
            case 0:
                c = 0;
                break;
            default:
                printf("Function not yet implemented !\n");
        }
    }
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

void add_ticket(int *count, ticket **ticket_list){
    int i;
    if(*count > 4){
        printf("Error, ticket list is already full... \n");
        return;
    }
    for (i=(int)sizeof(ticket_list)-1;i>0;--i){
        ticket_list[i] = ticket_list[i-1];
    }
    ticket_list[0] = ticket_create();
    printf("ticket %p\n", ticket_list[*count]);
    *count = *count + 1;
}

void del_ticket(int *count, ticket **ticket_list){
    char buf[4];
    int id;
    ticket *tmp;
    printf("Index to remove :");
    fgets(buf, sizeof(buf),stdin);
    id = atoi(buf);
    if (id < 0 || id >= *count) {
        printf("Out of bound!");
        return;
    }
    tmp = ticket_list[id];
    ticket_list[id] = ticket_list[*count-1];
    ticket_list[*count-1] = tmp;
    ticket_del(tmp);
    free(tmp);
    *count = *count-1;
}

void display_tickets(int *count, ticket **ticket_list){
    int id = 0;
    if(*count == 0){
        printf("There is no tickets to display\n");
        return;
    }
    for(id = 0; id<*count;++id){
        printf("id : %d\n", id);
        ticket_list[id]->display(ticket_list[id]);
    }
}

void read_ticket(int *count, ticket **ticket_list){
    int id = 0;
    char buf[8];
    if(*count == 0){
        printf("There is no tickets to display\n");
        return;
    }
    printf("Index to read :");
    fgets(buf, sizeof(buf),stdin);
    id = atoi(buf);
    printf("id : %d\n", id);
    if(id >= 0 && id < sizeof(ticket_list)){
        ticket_list[id]->display(ticket_list[id]);
    }
}
void guest(void){
    char buf[8];
    ticket *ticket_list[5];
    int count = 0;
    printf("Welcome guest.\n");
    char i, c = 1;
    while(c){
        printf("Press enter char to continue...");
        getchar();
        printf("\e[1;1H\e[2J");
        printf("What to do you want to do ?\n");
        printf("1 - Get current tickets\n");
        printf("2 - Read ticket\n");
        printf("3 - Create ticket\n");
        printf("4 - Delete ticket\n");
        printf("5 - Submit tickets\n");
        printf("0 - Exit\n");
        printf("Choice > ");
        fgets(buf, sizeof(buf), stdin);
        i = buf[0];
        printf("\e[1;1H\e[2J");
        switch (i) {
            case '0':
                c = 0;
                break;
            case '1':
                display_tickets(&count, ticket_list);
                break;
            case '2':
                read_ticket(&count, ticket_list);
                break;
            case '3':
                add_ticket(&count, ticket_list);
                break;
            case '4':
                del_ticket(&count, ticket_list);
                break;
            default:
                printf("Function not yet implemented !\n");
        }
    }
}

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);   
    printf("\e[1;1H\e[2J");
    char userType = 0;
    printf("Welcome, please login.\n");
    userType = login();
    printf("\e[1;1H\e[2J");
    if (userType == 1) {
        admin();
    } else {
        guest();
    }
}
