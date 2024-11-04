#ifndef THECTFRECIPES_CHALLENGES_TICKET_H
#define THECTFRECIPES_CHALLENGES_TICKET_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct ticket {
    void (*display)();
    char title[34];
    char *content;
} ticket;

void display_ticket(ticket *this){
    int i = 0;
    int size = strlen(this->content);
    char line[33] = "+------------------------------+";
    char data[29] = "";
    line[32] = '\0';
    strcat(data,this->title);
    while(strlen(data) < sizeof(data)-1){
        strcat(data, " ");
    }
    data[28] = '\0';
    printf("%s\n",line);
    printf("| %s |\n",data);
    printf("%s\n",line);
    while(i < size){
        memcpy(data, &this->content[i], 28);
        while(strlen(data) < sizeof(data)-1){
            strcat(data, " ");
        }
        data[28] = '\0';
        printf("| %s |\n",data);
        i += 28;
    }
    printf("%s\n",line);
}

ticket* ticket_create(){
    char buf[8];
    int size;
    char title[24] = "";
    ticket *t = (ticket *)malloc(sizeof(ticket));

    t->display = display_ticket;
    fflush(stdin);
    fflush(stdout);
    printf("Title : ");
    fgets(title, sizeof(title),stdin);
    if (title[strlen(title)-1] == '\n'){
        title[strlen(title) -1] = '\0';
    }
    strcpy(t->title, title);
    printf("Ticker size :");
    fgets(buf, sizeof(buf),stdin);
    size = atoi(buf);
    t->content = (char *)malloc(size);
    if (!t->content) {
        printf("Allocation Error");
        exit(-1);
    }
    printf("Content :");
    fgets(t->content, size,stdin);
    if (t->content[strlen(t->content)-1] == '\n'){
        t->content[strlen(t->content) -1] = '\0';
    }
    return t;
}

void ticket_del(ticket *t){
    free(t->content);
    t->content = NULL;
}

#endif //THECTFRECIPES_CHALLENGES_TICKET_H
