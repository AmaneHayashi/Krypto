#pragma once
#ifndef __TEST_H__
#define __TEST_H__ 

#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;

#define N 512
#define M 100

char x[N], y[N];//���ġ���������
char secret_key[M];//��Կ
char sub_table[M];//�����
char re_table[M];//���������
int table_len = 0;

void generate_secret_table();//�����������
void get_en_text(char *table);//�������ɺ���
void get_de_text(char *table);//�������ɺ���
void reverse_table();//���������

#endif