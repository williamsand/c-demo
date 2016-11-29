/*************************************************************************
	> File Name: pencodec.c
	> Author: 
	> Mail: 
	> Created Time: Sun 30 Oct 2016 04:25:52 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include"codec.h"
#include"options.h"
#include"level.h"

typedef struct AppleContext {
    TestClass *class;
    int gpu;
    int cpu;
    int rc;
}AppleContext;

enum {
    ABR = 0,
    CBR,
    VBR,
};

#define OFFSET(x) offsetof(AppleContext, x)
static const TestOption options[] = {
        {"gpu",  "apple set gpu info",  OFFSET(gpu),   OPT_TYPE_INT},
        {"cpu",  "apple set cpu info",  OFFSET(cpu),   OPT_TYPE_INT},
        {"rc",  "set apple rc mode",  OFFSET(rc),   OPT_TYPE_INT,{.i64=-1},"rc"},
        {"abr",  "set apple rc mode of abr", 0,  OPT_TYPE_CONST,{.i64=ABR},"rc"}, {"cbr",  "set apple rc mode of cbr", 0,  OPT_TYPE_CONST,{.i64=CBR},"rc"}, {"vbr",  "set apple rc mode of vbr", 0,  OPT_TYPE_CONST,{.i64=VBR},"rc"}, {NULL}, }; 
static const TestClass AppleClass = {
        .name = "apple_class",
        .option = options,
};

void apple_printf(PCodecContext *codectx)
{
    AppleContext *ctx = codectx->priv_data;
    my_log(ctx,LEVEL_INFO,"the apple [gpu]= %d\n",ctx->gpu);
    my_log(ctx,LEVEL_INFO,"the apple_[cpu] = %d\n",ctx->cpu);
    my_log(ctx,LEVEL_DEBUG,"the apple__[rc_mode] = %d\n",ctx->rc);
}

int apple_add(int a,int b)
{
    my_log(NULL,LEVEL_DEBUG,"enter apple add oprator\n");
    my_log(NULL,LEVEL_INFO,"the  apple add result is = [%d]\n",a+b);
    return 0;
}

myCodec apple_codec = {
    .name = "apple",
    .longname = "I have a apple",
    .myprintf = apple_printf,
    .myadd = apple_add,
    .priv_data_size = sizeof(AppleClass),
    .priv_class = &AppleClass,
};


