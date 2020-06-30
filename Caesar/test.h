#pragma once
#ifndef __TEST_H__
#define __TEST_H__ 

#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;

#define N 512
#define M 100

char x[N], y[N];//明文、密文数组
char secret_key[M];//密钥
char sub_table[M];//密码表
char re_table[M];//倒置密码表
int table_len = 0;

void generate_secret_table();//创建密码表函数
void get_en_text(char *table);//密文生成函数
void get_de_text(char *table);//明文生成函数
void reverse_table();//倒置密码表

#endif