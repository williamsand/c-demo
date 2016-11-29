/*************************************************************************
	> File Name: options.h
	> Author: 
	> Mail: 
	> Created Time: Mon 24 Oct 2016 04:30:23 AM PDT
 ************************************************************************/

#ifndef _OPTIONS_H
#define _OPTIONS_H

typedef unsigned long long  u_int64;
enum OptionType{
  OPT_TYPE_FLAGS,
  OPT_TYPE_INT,
  OPT_TYPE_CONST,
}; 

typedef struct TestOption{
    const char *name;
    const char *help;
    int offset;
    enum OptionType type;    
    union{
        u_int64 i64;
        double dle;
        const char *str;
    }default_val;
    char *unit;

}TestOption;

typedef struct TestClass{
    const char *name;
    const struct TestOption *option;
}TestClass;


const TestOption *opt_next(const void *obj,const TestOption *last);
const TestOption *opt_find(void *src,const char *name,const char *unit);
int opt_set(void *src, const char *name,const char *val, void *target);

#endif

