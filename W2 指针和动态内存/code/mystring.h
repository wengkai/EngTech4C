#ifndef _MY_STRING_H_
#define _MY_STRING_H_

typedef struct {
	int length;
    char *content;
} string;

/**	
	创建（初始化）字符串
	@param s 要被初始化的字符串
	@param source 用来做初始化内容的C字符串
	@return 初始化了的字符串s，其中的内容为source中的字符串
*/	
string* str_create(string* s, const char* source);

/** 
	释放字符串
	@param s 要释放的字符串
*/
void str_free(string* s);

/** 
	字符串长度
	@param s 要计算长度的字符串
	@return 字符串的长度
*/
unsigned int str_len(const string* s);

/**
	字符串拷贝
	@param dest 目的地字符串
	@param source 来源字符串
	@return 目的地字符串
*/
string* str_copy(string* dest, const string* source);

/**
	字符串连接
	@param dest 目的地字符串
	@param source 来源字符串
	@return 目的地字符串
*/
string* str_concat(string* dest, const string* source);

/**
	在标准输出上输出字符串
	@param s 要输出的字符串
*/
void str_print(const string* s);

/**
	从标准输入读入一行
	@param s 要写入的字符串
	@return 写入的字符串s
*/
string* str_readline(string* s);

#endif