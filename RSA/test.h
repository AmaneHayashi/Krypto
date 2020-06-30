#pragma once
#ifndef __TEST_H__
#define __TEST_H__ 

#include<iostream>
#include<stdlib.h>
#include<cstdlib>
#include<stdio.h>
#include<string.h>
#include<bitset>
#include<math.h>
#include<time.h>
#include<assert.h>
#include<sstream>
#include<conio.h>
#include<fstream>
#include<ostream>

using namespace std;

//字符串与二进制相互转化的变量
bitset<8> binary;
char charac[8];

//大数数组常用const
int One[100] = { 1 };
int Two[200] = { 2 };
int clear[1000] = { 0 };
int cTwo[800] = { 0 };
int ccTwo[800] = { 0 };

int sum[200] = { 1 };
int cE[100] = { 0 };
int _N[800] = { 0 }, _NN[800] = { 0 };

//质数判定数组
int initial[10000000] = { 0 };

//大数密钥（公钥、私钥）生成变量
string create_hyperodd(string aa);
int keylength;
int de_length, p_length, pp_length, q_length, qq_length,
n_length, e_length, phy_length, d_length, sum_length, pro_length;
int p[100] = { 0 }; int p_bi[800] = { 0 };int cp_bi[300] = { 0 };
int q[200] = { 0 };int q_bi[1200] = { 0 };int cq_bi[300] = { 0 };
int int_pp[100] = { 0 };
int int_qq[200] = { 0 };
int int_n[300] = { 0 };
int int_phy[300] = { 0 };
int int_cp[100] = { 0 };
int int_cq[200] = { 0 };
int int_cn[300] = { 0 };
int pro[200] = { 0 };
int cpro[200] = { 0 };
int quotient[200] = { 0 };
int remain[200] = { 0 };
int remain_[200] = { 1 };
int Memo_x[300], Memo_e[300], Memo_n[300];
int cMemo_x[300] = { 0 }, cMemo_e[300] = { 0 }, cMemo_n[300] = { 0 };
int  _ce[800] = { 0 } , _cce[800] = { 0 };
int _cee[800] = { 0 };
int detect[800] = { 0 };

//幂模运算变量
int tes_m[100] = { 0 };
int cpr[100] = { 0 };
int cqr[100] = { 0 };int num[200] = { 0 };

//RSA加解密变量
string txt_arr;
string odd_p, odd_q;
stringstream sst;
int RSAe_N = 0, RSAd_N = 0, RSAee_N = 0, RSAdd_N = 0;
int htxt[800] = { 0 };
int itdt[800] = { 0 };int htdt[800] = { 0 };
int htxt_c[800] = { 0 };int htxt_e[800] = { 0 };int htxt_n[800] = { 0 };
int RSAe[1000] = { 0 };int RSAd[1000] = { 0 };
int htdt_e[800] = { 0 }; int htdt_n[800] = { 0 };int htdt_c[900] = { 0 };
char RSAee[1000] = { 0 };char RSAdd[1000] = { 0 };char ddRSA[1000] = { 0 };

//RSA系统的初始化变量
char blank;
char temp[2000];
char temp_plain[15000];
char ttemp_plain[15000];
char tempt_plain[15000];
char temp_cipher[15000];
char ttemp_cipher[15000];
char tempt_final[15000];
char ttemp_final[5000];
char temp_final[5000];
char ttemp[15];

//主要函数
void code_trans_cb(char s[], int flag);//字符转二进制函数
void code_trans_bc();//二进制转字符函数
void find_prime_number(int a[], int nail);//寻找质数函数
void generate_key_pair(const unsigned keylength);//生成密钥函数
void RSA_encode_test(int keylength);//幂模运算函数
void RSA_encode(int keylength, char flag);//RSA加密函数
void RSA_decode(char flag);//RSA解密函数
void RSA();//RSA系统函数

//大数（hypernumber）四则运算及相关函数
int* HyperAdd_de(int inum1[], int inum2[], int flag);//大数加函数
int* HyperAdd_pq(int inum1[], int inum2[], int flag);//大数加函数
int* HyperPureSub_pq(int hnum1[], int hnum2[], int flag);//大数纯减函数
int Hyper_Upure_Sub(int hnum1[], int hnum2[], int len1, int len2);//大数减函数
int* HyperMul_pq(int hnum1[], int hnum2[], int flag);//大数乘函数
int* HyperMul_de(int hnum1[], int hnum2[]);//大数乘函数
int* HyperMul_memo(int hnum1[], int hnum2[]);//大数幂模乘函数
int* HyperDiv_de(int hnum1[], int hnum2[]);//大数除函数
int* HyperDiv_memo(int hnum1[], int hnum2[]);//大数幂模除函数
void HyperMemo(int copy_x[], int copy_e[], int copy_n[], int n[], int flag);//大数幂模函数
void HyperPrint(char hnum[], int hnum_length);//大数打印函数
int HyperEqual(int inum1[], int inum2[]);//大数大小判断函数
int* HyperToBinary(int inum[], int onum[800]);//大数转二进制函数
bool Hyper_binary_YU();//大数与函数

//小函数
int* create_prime_p(int pr[100], int length, const unsigned k);//创建质数p函数
int* create_odd_p(int* apr, unsigned length);//创建奇数p函数
int* create_prime_q(int qr[100], int length, const unsigned k);//创建质数q函数
int* create_odd_q(int* aqr, unsigned length);//创建奇数q函数
bool prime_test(unsigned k, int flag);//素性检测函数

int getLength(int b);//获取int变量长度函数
int* reverse_array(int inum[], int rnum[], int length, int flag);//数组倒置函数
int* int_to_array(int a[], int b);//int转int*函数
void print_array(int a[], int print_length);//数组打印函数
void print_ARRAY(int a[], int print_length);//数组打印函数
void copy_array(int fresh[], int old[], int size);//数组复制函数
void copy_ARRAY(char fresh[], char old[], int size);//数组复制函数
int detect_array(int a[], int estimated_size);//数组检测函数
int detect_zero(int a[], int size);//数组排零函数

#endif