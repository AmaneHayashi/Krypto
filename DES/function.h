#pragma once
#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include"test.h"

//字符串转二进制函数（含输出）
void code_trans_cb(char s[], int x) {//传入参数为字符串数组，输出单元数
	int k = 1, real_k = 1;
	z[72] = { 0 }, real_z[72] = { 0 };
	z[0] = real_z[0] = '\0';//初始化，其中real_z不含空格用于计算，z含空格用于输出
	for (int i = 0; s[i]; i++)
	{
		for (int j = 7;j >= 0;j--)
		{
			real_z[real_k] = bool((s[i] & (1 << j) != 0));//每次左移，比较该位是否为1
			z[k] = real_z[real_k];
			k++, real_k++;
		}
		z[k++] = '\0';//逢8的倍数不要
	}
	for (int i = 1;i < x; i++)
		(i % 9 == 0) ? (cout << " ") : cout << z[i];//每8位空一个格输出
	cout << '\n';
}

//字符串转二进制函数（不含输出）
void code_trans_cb_sys(char s[]) {//传入参数为字符串数组
	int real_k = 1;
	real_z[72] = { 0 };
	real_z[0] = '\0';
	for (int i = 0; s[i]; i++)
	{
		for (int j = 7;j >= 0;j--)
		{
			real_z[real_k] = bool((s[i] & 1 << j) != 0);//每次左移，比较该位是否为1, &为与运算，<<为左移运算
			real_k++;
		}
	}
	cout << '\n';
}

//二进制转字符串函数（借助bitset类，含输出）
void code_trans_bc()
{
	cout << (char)binary.to_ulong() << endl;//直接调用bitset内的函数
}

//变换转移函数（产生16对子密钥的函数）
//传入参数依次为Ci、Di、key（合并得到的）、finalkey（置换得到的）、左移步数、C/D数组的长度、置换后数组长度
int move_transfer(int a[], int b[], int combine[], int final[], int t[], int path, int range1, int range2)
{
	move(a, range1, path);//将a循环左移path位
	move(b, range1, path);//将b循环左移path位
	compose(a, b, combine, range1);//合并a与b
	transfer(final, combine, t, range2);//PC_2表置换
	return 0;
}

//循环左移函数（将长为n的数组a循环左移m位）
void move(int a[], int n, int m)//传入参数为转换数组、数组长度、循环移位数
{
	while (m--) {
		int t = a[1];
		for (int j = 2; j < n + 1; j++)
			a[j - 1] = a[j];//左移
		a[n] = t;//移出去的补在最后面
	}
}

//合并函数（将两个数组合并为一个数组，适用于两个数组等长情形）
void compose(int former[], int latter[], int combine[], int range)//传入参数为居前数组、居后数组、合并数组、合并范围
{
	for (int i = 1; i <= 2 * range; i++)
		(i <= range) ? (combine[i] = former[i]) : (combine[i] = latter[i - range]);
}

//表置换函数（适用于DES算法的所有置换表功能）
void transfer(int a[], int b[], int t[], int range)//传入参数为新数组、原数组、置换表、新数组长度
{
	for (int i = 1; i <= range; i++)
		a[i] = b[t[i - 1]];//将t[]中的第i-1个元素的值对应的数组值赋给新数组的第i个元素
}

//f变换迭代函数（加密/解密核心函数）
int f(int R[], int L[], int nR[], int nL[], int KR[], int ER[], int range)//传入参数为Rn-1，Ln-1，Rn，Ln，Kn,置换表E，数组长度
{
	f_transfer(KR, ER, R, 48);//f变换得到F数组
	for (int i = 1; i <= range; i++) {
		nR[i] = L[i] ^ F[i];//XOR计算，生成新的Rn
		nL[i] = R[i];//迭代，生成新的Ln
	}
	return 0;
}

//f变换子函数（f变换迭代函数的核心）
int f_transfer(int KR[], int ER[], int R[], int range)//传入参数为Kn,置换表E，数组长度
{//分解区
	int XOR[49] = { 0 };
	int X1[25] = { 0 };
	int X2[25] = { 0 };
	int X11[13] = { 0 };
	int X12[13] = { 0 };
	int X21[13] = { 0 };
	int X22[13] = { 0 };
//合并区
	int P11[9] = { 0 };
	int P12[9] = { 0 };
	int P21[9] = { 0 };
	int P22[9] = { 0 };
	int P1[17] = { 0 };
	int P2[17] = { 0 };
	int PXOR[33] = { 0 };
//处理区，分解区
	int B1[7] = { 0 };
	int B2[7] = { 0 };
	int B3[7] = { 0 };
	int B4[7] = { 0 };
	int B5[7] = { 0 };
	int B6[7] = { 0 };
	int B7[7] = { 0 };
	int B8[7] = { 0 };
//处理区，合并区
	int SB1[10] = { 0 };
	int SB2[10] = { 0 };
	int SB3[10] = { 0 };
	int SB4[10] = { 0 };
	int SB5[10] = { 0 };
	int SB6[10] = { 0 };
	int SB7[10] = { 0 };
	int SB8[10] = { 0 };

	transfer(ER, R, E, 48);//置换表E进行置换

	for (int i = 1; i <= range; i++)//对生成的ER与Kn进行XOR运算
		XOR[i] = KR[i] ^ ER[i];
//分解XOR为8部分：B1~B8
	decompose(X1, X2, XOR, 24);
	decompose(X11, X12, X1, 12);
	decompose(X21, X22, X2, 12);
	decompose(B1, B2, X11, 6);
	decompose(B3, B4, X12, 6);
	decompose(B5, B6, X21, 6);
	decompose(B7, B8, X22, 6);
//对每部分进行S表映射，B->SB
	S(S_BOX, B1, SB1, 0);
	S(S_BOX, B2, SB2, 1);
	S(S_BOX, B3, SB3, 2);
	S(S_BOX, B4, SB4, 3);
	S(S_BOX, B5, SB5, 4);
	S(S_BOX, B6, SB6, 5);
	S(S_BOX, B7, SB7, 6);
	S(S_BOX, B8, SB8, 7);
//将SB1~SB8合并为PXOR数组
	compose(SB1, SB2, P11, 4);
	compose(SB3, SB4, P12, 4);
	compose(SB5, SB6, P21, 4);
	compose(SB7, SB8, P22, 4);
	compose(P11, P12, P1, 8);
	compose(P21, P22, P2, 8);
	compose(P1, P2, PXOR, 16);

	transfer(F, PXOR, P, 32);//置换表P置换，得到最终函数F

	return 0;
}

//分解函数（将一个数组分解为两个数组，适用于两个数组等长情形）
void decompose(int former[], int latter[], int combine[], int range)//传入参数为居前数组、居后数组、合并数组、合并范围
{
	for (int i = 1; i <= 2 * range; i++)
		(i <= range) ? (former[i] = combine[i]) : (latter[i - range] = combine[i]);
}

//S表映射函数，B数组的第一位、末位合起来的二进制数决定行数，中间位合起来的二进制数决定列数
void S(int s[8][4][16], int b[7], int sb[10], int i)//传入参数为S表、B数组、转换后的SB数组、表数
{
	int row, column, num = 0;
	row = 2 * b[1] + b[6];//行计算（BIN->DEC）
	column = 8 * b[2] + 4 * b[3] + 2 * b[4] + b[5];//列计算（BIN->DEC）
	num = s[i][row][column];
	de_to_bi(sb, num);//进制转换（DEC->BIN）
}

//十进制转二进制函数，采用累除
void de_to_bi(int arr[10], int a)//传入参数为存储数组，待转换的十进制数
{
	int temp = a;
	int INDEX = 4;//十进制最多4位二进制
	if (a == 0)
		arr = { 0 };
	else
	{
		while (temp)
		{
			arr[INDEX] = (temp & 0x01);//与1与
			temp = temp >> 1;//右移位（除以2）
			INDEX--;
		}
	}
}

//打印数组函数（适用于int型数组，且从1开始打印）
void print_array(int a[], int head, int length)//传入参数为数组，打印首序号，打印长度
{
	for (int i = head; i <= length; i++)
		cout << a[i];
}

//打印数组函数（适用于char型数组，且从0开始打印）
void print_ARRAY(char a[], int head, int nail)//传入参数为数组，打印首序号，打印尾序号
{
	for (int i = head; i < nail; i++)
		cout << a[i];
}

//复制数组函数（适用于int型数组，且从1开始复制，新、原数组地址不同）
void copy_array(int fresh[], int old[], int size)//传入参数为新数组、原数组、数组长度
{
	for (int i = 1; i < size; i++)
		fresh[i] = old[i];
}

//复制数组函数（适用于char型数组，且从0开始复制，新、原数组地址不同）
void copy_ARRAY(char fresh[], char old[], int size)//传入参数为新数组、原数组、数组长度
{
	for (int i = 0; i < size; i++)
		fresh[i] = old[i];
}

#endif