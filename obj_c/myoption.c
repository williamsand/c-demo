/*************************************************************************
    > File Name: myoption.c
    > Author: 
    > Mail: 
    > Created Time: Mon 24 Oct 2016 04:40:42 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include <stddef.h>
#include <string.h>
#include"options.h"
#include"level.h"


const TestOption *opt_next(const void *obj,const TestOption *last)
{
    const TestClass *class;
    if (!obj)
        return NULL;
    class = *(const TestClass**)obj;
    if (!last && class && class->option && class->option[0].name)
    {
         return class->option;
    }
    if (last && last[1].name)
    {
         return ++last;
    }
    return NULL;
}

const TestOption *opt_find(void *src,const char *name,const char *unit)
{
    const TestOption *tmp = NULL;
    while(tmp = opt_next(src,tmp))
    {
      if( !strcmp(tmp->name,name))
      {
          my_log(NULL,LEVEL_DEBUG ,"find out the option [%s]\n",tmp->name);
          return tmp;
      }  
    }
    my_log(NULL,LEVEL_DEBUG ,"no this option\n");
}

int set_string_to_number(void *obj, void *target_obj, const TestOption *opt, const char *val, void *dst)
{
    int num;
    if( sscanf(val,"%d",&num) == 0 )
    {
       const  TestOption *unit_opt = NULL;
       unit_opt =  opt_find(target_obj,val,opt->unit);
       *(int *)dst = unit_opt->default_val.i64;  
    }
    else
    {
       *(int*)dst = atoi(val);
    }
}

int opt_set(void *src, const char *name,const char *val, void *target)
{
    void *dst;
    const TestOption *ret_opt = opt_find(src,name,0);
    dst = src;
    target = src;
    dst =(unsigned char *)target + ret_opt->offset;
    switch(ret_opt->type)
    {
        case OPT_TYPE_INT:
            set_string_to_number(src,target,ret_opt,val,dst);
            break;
        default:
            break;
    }
    return 0;
}

