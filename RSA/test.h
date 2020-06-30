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

//�ַ�����������໥ת���ı���
bitset<8> binary;
char charac[8];

//�������鳣��const
int One[100] = { 1 };
int Two[200] = { 2 };
int clear[1000] = { 0 };
int cTwo[800] = { 0 };
int ccTwo[800] = { 0 };

int sum[200] = { 1 };
int cE[100] = { 0 };
int _N[800] = { 0 }, _NN[800] = { 0 };

//�����ж�����
int initial[10000000] = { 0 };

//������Կ����Կ��˽Կ�����ɱ���
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

//��ģ�������
int tes_m[100] = { 0 };
int cpr[100] = { 0 };
int cqr[100] = { 0 };int num[200] = { 0 };

//RSA�ӽ��ܱ���
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

//RSAϵͳ�ĳ�ʼ������
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

//��Ҫ����
void code_trans_cb(char s[], int flag);//�ַ�ת�����ƺ���
void code_trans_bc();//������ת�ַ�����
void find_prime_number(int a[], int nail);//Ѱ����������
void generate_key_pair(const unsigned keylength);//������Կ����
void RSA_encode_test(int keylength);//��ģ���㺯��
void RSA_encode(int keylength, char flag);//RSA���ܺ���
void RSA_decode(char flag);//RSA���ܺ���
void RSA();//RSAϵͳ����

//������hypernumber���������㼰��غ���
int* HyperAdd_de(int inum1[], int inum2[], int flag);//�����Ӻ���
int* HyperAdd_pq(int inum1[], int inum2[], int flag);//�����Ӻ���
int* HyperPureSub_pq(int hnum1[], int hnum2[], int flag);//������������
int Hyper_Upure_Sub(int hnum1[], int hnum2[], int len1, int len2);//����������
int* HyperMul_pq(int hnum1[], int hnum2[], int flag);//�����˺���
int* HyperMul_de(int hnum1[], int hnum2[]);//�����˺���
int* HyperMul_memo(int hnum1[], int hnum2[]);//������ģ�˺���
int* HyperDiv_de(int hnum1[], int hnum2[]);//����������
int* HyperDiv_memo(int hnum1[], int hnum2[]);//������ģ������
void HyperMemo(int copy_x[], int copy_e[], int copy_n[], int n[], int flag);//������ģ����
void HyperPrint(char hnum[], int hnum_length);//������ӡ����
int HyperEqual(int inum1[], int inum2[]);//������С�жϺ���
int* HyperToBinary(int inum[], int onum[800]);//����ת�����ƺ���
bool Hyper_binary_YU();//�����뺯��

//С����
int* create_prime_p(int pr[100], int length, const unsigned k);//��������p����
int* create_odd_p(int* apr, unsigned length);//��������p����
int* create_prime_q(int qr[100], int length, const unsigned k);//��������q����
int* create_odd_q(int* aqr, unsigned length);//��������q����
bool prime_test(unsigned k, int flag);//���Լ�⺯��

int getLength(int b);//��ȡint�������Ⱥ���
int* reverse_array(int inum[], int rnum[], int length, int flag);//���鵹�ú���
int* int_to_array(int a[], int b);//intתint*����
void print_array(int a[], int print_length);//�����ӡ����
void print_ARRAY(int a[], int print_length);//�����ӡ����
void copy_array(int fresh[], int old[], int size);//���鸴�ƺ���
void copy_ARRAY(char fresh[], char old[], int size);//���鸴�ƺ���
int detect_array(int a[], int estimated_size);//�����⺯��
int detect_zero(int a[], int size);//�������㺯��

#endif