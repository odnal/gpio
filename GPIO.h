#ifndef GPIO_H
#define GPIO_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define GPIO_PATH "/sys/class/gpio/"
char full_path[100];

// get gpio number and open full file path
char *get_gpio_pin(char *gpio_folder) {
    FILE *fp;
    sprintf(full_path, GPIO_PATH "%s", gpio_folder);
    fp = fopen(full_path, "r"); 
    if(fp == NULL) {
        printf("file not found");
        exit(-1);
    }
    char *ret = malloc(100);
    ret = full_path;
    fclose(fp);
    return ret;
}

// read the value of the file name and print -- file is "direction"
char *get_direction(char *path) { 
    FILE *fp;
    char line[100];
    char dir_path[20] = "/direction";
    strncat(path, dir_path, 100);
    fp = fopen(path, "r"); 
    if(fp == NULL) {
        printf("file not found");
        exit(-2);
    }
    
    printf("%s", path);    
    while(fgets(line, 10, fp) != NULL) {
        printf(" %s\n", line);
    }
    fclose(fp);
}

// sets the direction of the gpio pin "in" or "out"
char *set_direction(char *path, char *val) {
    FILE *fp;
    char line[100];
    char dir_path[20] = "/direction";
    strncat(path, dir_path, 100);
    fp = fopen(path, "w+"); 
    if(fp == NULL) {
        printf("file not found");
        exit(-2);
    }
    
    fprintf(fp, "%s", val); 
    fclose(fp);
}

// read the value of the gpio pin file "value" either 1 or 0
char *get_value(char *path) { 
    FILE *fp;
    char line[100];
    char val_path[20] = "/value";
    strncat(path, val_path, 100);
    fp = fopen(path, "r"); 
    if(fp == NULL) {
        printf("file not found");
        exit(-2);
    }
    
    printf("%s", path);    
    while(fgets(line, 10, fp) != NULL) {
        printf(" %s\n", line);
    }
    fclose(fp);
}

// sets the value of the gpio pin high or low -> 1 or 0
char *set_value(char *path, char *val) {
    FILE *fp;
    char line[100];
    char val_path[20] = "/value";
    strncat(path, val_path, 100);
    fp = fopen(path, "w+"); 
    if(fp == NULL) {
        printf("file not found");
        exit(-2);
    }
    
    fprintf(fp, "%s", val); 
    fclose(fp);
}
#endif
