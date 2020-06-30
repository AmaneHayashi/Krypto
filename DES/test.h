#pragma once
#ifndef __TEST_H__
#define __TEST_H__

#include<iostream>
#include<bitset>
#include <fstream>
#include <string>

using namespace std;
constexpr auto N = 512;
constexpr auto M = 80;

//字符串与二进制数互转的变量
bitset<8> binary;
char charac[8];
int z[N];
int real_z[N];
int rreal_z[N];

//密钥、明文、密文
int clear[N] = { 0 };
char secretkey[32];
char secretkey_24[32];
char plaintext[N];
char realtext[N];
char realcipher[N];
char ciphertext[N];
int real_plaintext[N];
char ceal_plaintext[N];
int real_ciphertext[N];
char ceal_ciphertext[N];

//读写文件的中间变量（temp）
char temp[2000];
char temp_plain[15000];
char ttemp_plain[15000];
char temp_cipher[15000];
char ttemp_final[5000];
char temp_final[5000];
char ttemp[8];

//DES加密、解密的变量
char flag;
int F[32] = { 0 };

int key0[M];
int key1[M];
int key2[M];
int key3[M];
int key4[M];
int key5[M];
int key6[M];
int key7[M];
int key8[M];
int key9[M];
int key10[M];
int key11[M];
int key12[M];
int key13[M];
int key14[M];
int key15[M];
int key16[M];

int real_key1[M];
int real_key2[M];
int real_key3[M];
int real_key4[M];
int real_key5[M];
int real_key6[M];
int real_key7[M];
int real_key8[M];
int real_key9[M];
int real_key10[M];
int real_key11[M];
int real_key12[M];
int real_key13[M];
int real_key14[M];
int real_key15[M];
int real_key16[M];

int C0_key[29];
int D0_key[29];

int L0_text[33];
int R0_text[33];
int L1_text[33];
int R1_text[33];
int L2_text[33];
int R2_text[33];
int L3_text[33];
int R3_text[33];
int L4_text[33];
int R4_text[33];
int L5_text[33];
int R5_text[33];
int L6_text[33];
int R6_text[33];
int L7_text[33];
int R7_text[33];
int L8_text[33];
int R8_text[33];
int L9_text[33];
int R9_text[33];
int L10_text[33];
int R10_text[33];
int L11_text[33];
int R11_text[33];
int L12_text[33];
int R12_text[33];
int L13_text[33];
int R13_text[33];
int L14_text[33];
int R14_text[33];
int L15_text[33];
int R15_text[33];
int L16_text[33];
int R16_text[33];

int ER0_text[50];
int ER1_text[50];
int ER2_text[50];
int ER3_text[50];
int ER4_text[50];
int ER5_text[50];
int ER6_text[50];
int ER7_text[50];
int ER8_text[50];
int ER9_text[50];
int ER10_text[50];
int ER11_text[50];
int ER12_text[50];
int ER13_text[50];
int ER14_text[50];
int ER15_text[50];

int real_text[65];
int real_5_text[65];

//3DES的中间变量
int not_real_cipher[72];
int not_real_plain[72];
int trinity_real_cipher[72];
int trinity_real_plain[72];

//置换表集
int IP[] = { 58, 50, 42, 34, 26, 18, 10, 2,
			 60, 52, 44, 36, 28, 20, 12, 4,
			 62, 54, 46, 38, 30, 22, 14, 6,
			 64, 56, 48, 40, 32, 24, 16, 8,
			 57, 49, 41, 33, 25, 17, 9,  1,
			 59, 51, 43, 35, 27, 19, 11, 3,
			 61, 53, 45, 37, 29, 21, 13, 5,
			 63, 55, 47, 39, 31, 23, 15, 7 };


int PC_1[] = { 57, 49, 41, 33, 25, 17, 9,
			   1, 58, 50, 42, 34, 26, 18,
			  10,  2, 59, 51, 43, 35, 27,
			  19, 11,  3, 60, 52, 44, 36,
			  63, 55, 47, 39, 31, 23, 15,
			   7, 62, 54, 46, 38, 30, 22,
			  14,  6, 61, 53, 45, 37, 29,
			  21, 13,  5, 28, 20, 12,  4 };


int PC_2[] = { 14, 17, 11, 24,  1,  5,
			   3, 28, 15,  6, 21, 10,
			  23, 19, 12,  4, 26,  8,
			  16,  7, 27, 20, 13,  2,
			  41, 52, 31, 37, 47, 55,
			  30, 40, 51, 45, 33, 48,
			  44, 49, 39, 56, 34, 53,
			  46, 42, 50, 36, 29, 32 };


int shiftBits[] = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };

int E[] = { 32,  1,  2,  3,  4,  5,
			4,  5,  6,  7,  8,  9,
			8,  9, 10, 11, 12, 13,
		   12, 13, 14, 15, 16, 17,
		   16, 17, 18, 19, 20, 21,
		   20, 21, 22, 23, 24, 25,
		   24, 25, 26, 27, 28, 29,
		   28, 29, 30, 31, 32,  1 };


int S_BOX[8][4][16] = {
	{
		{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
		{0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
		{4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
		{15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
	},
	{
		{15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
		{3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
		{0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
		{13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}
	},
	{
		{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
		{13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
		{13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
		{1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}
	},
	{
		{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
		{13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
		{10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
		{3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}
	},
	{
		{2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
		{14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
		{4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
		{11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}
	},
	{
		{12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
		{10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
		{9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
		{4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}
	},
	{
		{4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},
		{13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
		{1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
		{6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}
	},
	{
		{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
		{1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
		{7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
		{2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}
	}
};


int P[] = { 16,  7, 20, 21,
		   29, 12, 28, 17,
			1, 15, 23, 26,
			5, 18, 31, 10,
			2,  8, 24, 14,
		   32, 27,  3,  9,
		   19, 13, 30,  6,
		   22, 11,  4, 25 };

int IP_1[] = { 40, 8, 48, 16, 56, 24, 64, 32,
			  39, 7, 47, 15, 55, 23, 63, 31,
			  38, 6, 46, 14, 54, 22, 62, 30,
			  37, 5, 45, 13, 53, 21, 61, 29,
			  36, 4, 44, 12, 52, 20, 60, 28,
			  35, 3, 43, 11, 51, 19, 59, 27,
			  34, 2, 42, 10, 50, 18, 58, 26,
			  33, 1, 41,  9, 49, 17, 57, 25 };

//主要的函数
void generate_secret_key(char* secretkey);//子密钥生成函数
int* DES_encode(char* encrypt, char flag);//DES加密函数
int* DES_decode(char* decrypt, char flag);//DES解密函数
void DES();//DES系统函数
void Trinity_DES(int flag);//3DES加解密

//小函数
void code_trans_cb(char s[], int x);//字符串转二进制函数
void code_trans_cb_sys(char s[]);//字符串转二进制函数
void code_trans_bc(void);//二进制转字符串函数

int move_transfer(int a[], int b[], int combine[], int final[], int t[], int path, int range1, int range2);//变换转移函数
void move(int a[], int n, int m);//循环左移函数
void compose(int former[], int latter[], int combine[], int range);//合并函数
void transfer(int a[], int b[], int t[], int range);//表置换函数

int f(int R[], int L[], int nR[], int nL[], int KR[], int ER[], int range);//f变换迭代函数
int f_transfer(int KR[], int ER[], int R[], int range);//f变换子函数
void decompose(int former[], int latter[], int combine[], int range);//分解函数
void S(int s[8][4][16], int b[7], int sb[10], int i);//S表映射函数
void de_to_bi(int arr[10], int a);//十进制转二进制函数

void print_array(int a[], int head, int length);//打印数组函数
void print_ARRAY(char a[], int head, int nail);//打印数组函数
void copy_array(int fresh[], int old[], int size);//复制数组函数
void copy_ARRAY(char fresh[], char old[], int size);//复制数组函数

#endif