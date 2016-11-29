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

typedef struct PenContext {
      TestClass *class;
      int gpu;
      int cpu;
      int rc;
}PenContext;


enum {
        ABR = 0,
        CBR,
        VBR,

};

#define OFFSET(x) offsetof(PenContext, x)
static const TestOption options[] = {
    {"gpu",  "pen set gpu info",  OFFSET(gpu),   OPT_TYPE_INT},
    {"cpu",  "pen set cpu info",  OFFSET(cpu),   OPT_TYPE_INT},
    {"rc",  "set pen rc mode",  OFFSET(rc),   OPT_TYPE_INT,{.i64=-1},"rc"},
    {"abr",  "set pen rc mode of abr", 0,  OPT_TYPE_CONST,{.i64=ABR},"rc"},
    {"cbr",  "set pen rc mode of cbr", 0,  OPT_TYPE_CONST,{.i64=CBR},"rc"},
    {"vbr",  "set pen rc mode of vbr", 0,  OPT_TYPE_CONST,{.i64=VBR},"rc"},
      {NULL}, 
};

static const TestClass PenClass = {
    .name = "pen_class",
    .option = options,
};

void pen_printf(PCodecContext  *codectx)
{
    PenContext *ctx = codectx->priv_data;
    my_log(ctx,LEVEL_INFO,"the pen [gpu]= %d\n",ctx->gpu);
    my_log(ctx,LEVEL_INFO,"the pen_[cpu] = %d\n",ctx->cpu);
    my_log(ctx,LEVEL_DEBUG,"the pen__[rc_mode] = %d\n",ctx->rc);
}

int pen_add(int a,int b )
{
    my_log(NULL,LEVEL_DEBUG ,"enter pen add oprator\n");
    my_log(NULL,LEVEL_INFO,"the pen add result is = [%d]\n",a+b);
    return 0;
}


myCodec pen_codec = {
    .name = "pen",
    .longname = "I have a pen",
    .myprintf = pen_printf,
    .myadd = pen_add,
    .priv_data_size = sizeof(PenContext),
    .priv_class = &PenClass,
};


