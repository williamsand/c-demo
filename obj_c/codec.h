/*************************************************************************
	> File Name: codec.h
	> Author: 
	> Mail: 
	> Created Time: Sun 30 Oct 2016 04:21:31 AM PDT
 ************************************************************************/

#ifndef _CODEC_H
#define _CODEC_H

#include"options.h"

struct PCodecContext;
typedef struct myCodec{
    const char *name;
    const char *longname;
    void (*myprintf)( struct PCodecContext  *codectx);
    int (*myadd)(int a,int b);
    struct myCodec *next;
    int priv_data_size;
    const TestClass *priv_class;
}myCodec;

typedef struct PCodecContext{
    const char *name;
    struct myCodec *codec;
    void *priv_data;
}PCodecContext;
#endif
