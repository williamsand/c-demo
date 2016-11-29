/*************************************************************************
	> File Name: level.h
	> Author: 
	> Mail: 
	> Created Time: Wed 23 Nov 2016 03:52:58 AM PST
 ************************************************************************/

#ifndef _LEVEL_H
#define _LEVEL_H

#define LEVEL_ERROR 31

#define LEVEL_DEBUG 32

#define LEVEL_INFO 37

typedef struct _LOG_INFO
{
    char name[30];
    char log[512];
}LOG_INFO;


typedef struct _TEST
{
    char name[10];
}TEST;

void my_log(void *ctx,int level,const char *fmt,...);

#endif
