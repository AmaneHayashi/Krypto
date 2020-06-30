#pragma once
#ifndef __FUNC_H__
#define __FUNC_H__ 

#include"test.h"
#include"prime.h"
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

//字符转二进制函数（与实验二相同）
void code_trans_cb(char s[], int flag) {//传入参数为字符串数组，输出单元数
	char z[72] = { '\0' };
	int k = 0;
	z[0] = '\0';
	for (int i = 0; s[i]; i++)
	{
		for (int j = 7;j >= 0;j--)
		{
			(bool((s[i] & 1 << j) != 0) == true) ? (z[k] = '1') : (z[k] = '0');
			k++;
		}
	}
	if (flag == 1)
		HyperPrint(z, 8);//大数组打印函数
	if (flag == 2)
		sst << z;
	//	return sst;
}

//二进制转字符函数（与实验二相同）
void code_trans_bc()
{
	cout << (char)binary.to_ulong() << endl;//借助bitset类
}

//打印数组函数（int数组，排零，逆序打印）
void print_array(int a[], int print_length)//传入参数为数组、打印长度（未知）
{
	for (; a[print_length] == 0 && print_length >= 0; print_length--);//排零
	for (int i = print_length; i >= 0; i--)
		printf_s("%d", a[i]);
}

//打印数组函数（int数组，不排零，逆序打印）
void print_ARRAY(int a[], int print_length)//传入参数为数组、打印长度（已知）
{
	for (int i = print_length - 1; i >= 0; i--)
		cout << a[i];
}


//创造质数p函数
int* create_prime_p(int pr[100], int length, const unsigned k)//传入参数为待定质数、质数长度、素性检测次数
{
	assert(k > 0);//判定k是否大于0，否则直接跳出
	pr = create_odd_p(pr, length);//创造一个奇数
	cout << "待检测的数是：";print_array(pr, 100);cout << "\n\n";
	copy_array(cpr, pr, 99);//保留pr并复制，用于下一步操作
	while (prime_test(k, 1) == false)//如果检测为假，则执行
	{
		cout << "该数不是素数！对选定的数进行加2" << "\n\n";
		HyperAdd_pq(cpr, Two, 1);//通过加2的方式，再次检测
		cout << "待检测的数是：";print_array(cpr, 100);cout << "\n\n";
	}
	cout << "检测成功！" << "\n\n";
	copy_array(p, cpr, 99);//将复制数回传
	return pr;
}

//创造奇数p函数
int* create_odd_p(int* apr, unsigned length)//传入参数为待定数指针、数长度
{
	odd_p = create_hyperodd(odd_p);//创建100位奇数并传入
	odd_p = odd_p.substr(100 - length);//从后面截取长度length的数，一定为奇数

	for (unsigned int i = 0; i < length; i++)
		apr[i] = (char)(odd_p[length - 1 - i] - 48);//string转int
	return apr;
}

//创建质数q函数，与p相同
int* create_prime_q(int qr[100], int length, const unsigned k)//传入参数为待定质数、质数长度、素性检测次数
{
	assert(k > 0);//判定k是否大于0，否则直接跳出
	qr = create_odd_q(qr, length);//创造一个奇数
	cout << "待检测的数是：";print_array(qr, 100);cout << "\n\n";
	copy_array(cqr, qr, 99);//保留qr并复制，用于下一步操作
	while (prime_test(k, 2) == false)//如果检测为假，则执行
	{
		cout << "对选定的数进行加2" << "\n\n";
		HyperAdd_pq(qr, Two, 2);//通过加2的方式，再次检测
	}
	cout << "检测成功！" << "\n\n";
	copy_array(q, cqr, 99);//将复制数回传
	return qr;
}

//创建奇数q函数，与p相同
int* create_odd_q(int* aqr, unsigned length)//传入参数为待定数指针、数长度
{
	odd_q = create_hyperodd(odd_q);//创建100位奇数并传入
	odd_q = odd_q.substr(100 - length);//从后面截取长度length的数，一定为奇数
	for (unsigned int i = 0; i < length; i++)
		aqr[i] = (char)(odd_q[length - 1 - i] - 48);//string转int
	return aqr;
}


/*素性检测算法（Miller-Rabin算法）
a.计算奇数M，使得N=(2^j)*M+1
b.选择随机数A < N
c.对于任意i < j，若A ^ ((2 ^ i)*M) MOD N = N - 1，则N通过随机数A的测试
d.若A^M MOD N = 1，则N通过随机数A的测试
e.让A取不同的值对N进行5次测试，若全部通过则判定N为素数
f.若N通过一次测试，则N不是素数的概率为 25 % ，若N 通过t 次测试，则N不是素数的概率为(1/4)^t。
在本实验中，实际检测15次*/
bool prime_test(unsigned k, int flag)//传入参数为检测次数，检测标志
{
	cout << "开始进行素数检测：" << "\n\n";;
	bool judge = false;
	if (flag == 1)
		cout << "对p的检测：", copy_array(num, cpr, 99);cout << "\n\n";//将数复制给num，准备检测
	if (flag == 2)
		cout << "对q的检测：", copy_array(num, cqr, 99);cout << "\n\n";//将数复制给num，准备检测
	/*	HyperToBinary(num, binum);
		int d = num_length - detect_array(binum, 799);
		for (int i = 0; i < k; i++){
			srand((unsigned)time(NULL));
			for (int j = 0; j < num_length - 1;j--)
				tes_m[j] = rand() % 10;
			tes_m[num_length - 1] = rand() % (num[num_length - 1]-1) + 0;
			copy_array(tes_num, num, 99);
			HyperPureSub_pq(tes_num, One, 3);
			HyperMemo(tes_m, tes_d, tes_num, num);}*/
	srand((unsigned)time(NULL));//播种子
	int numlength = detect_array(num, 99);int PrK;//检测num非零位数
	if (numlength <= 3)
	{
		for (int i = 0; i < 168;i++)
		{
			if (100 * num[2] + 10 * num[1] + num[0] == prime_basket[i]){
				judge = true;
				break;
			}
		}
		if (flag == 1) copy_array(num, cpr, 99);//对p求
		if (flag == 2) copy_array(num, cqr, 99);//对q求
	}
	else {
		for (unsigned int i = 0; i < 5 * k; i++)
		{
			for (;;) {
				(numlength == 4) ?//若待检测数在4位以下，从素数表中抽取前168个元素计算；否则抽取前13848个元素
					(PrK = prime_basket[rand() % 168]) : (PrK = prime_basket[rand() % 13848]);
				int_to_array(tes_m, PrK);//将数按位转换为数组，准备比较

				if (HyperEqual(num, tes_m) == 1)//如果num>tes_m，则进入比较
				{
					cout << "选定的随机数为：" << PrK << "\n\n";
					break;
				}
				else
					cout << "该数不符合条件！" << '\n';
			}
			HyperDiv_de(num, tes_m);//求大数除法
			cout << "计算出的余数为：";print_array(remain, 99);cout << "\n\n";
			if (flag == 1) copy_array(num, cpr, 99);//对p求
			if (flag == 2) copy_array(num, cqr, 99);//对q求
			if (detect_array(remain, 99) == 99)//如果remain全零，则整除，说明是合数
			{
				judge = false;
				break;
			}
			else
				judge = true;//否则可能是质数
		}
	}
	return judge;
}

//数字转数组函数
int* int_to_array(int a[], int b)//传入参数为转换数组、待转数字
{
	int tyc[100] = { 0 };//定义中间数组
	int N = getLength(b);//获取数字长度函数
	int NN = N;
	for (int i = 0; ;i++)
	{
		int c = pow(10, N - 1);
		a[i] = b / c;//每次除以10，将商赋给a
		b -= a[i] * c;
		N--;
		if (b == 0)
			break;
	}
	for (int i = 0; i < NN; i++)
		tyc[i] = a[NN - 1 - i];//倒置运算
	copy_array(tes_m, tyc, 99);//回传
	return 0;
}

//获取数字长度函数
int getLength(int b)//输入为int型变量
{
	int n = b, count = 0;
	while (n)
	{
		count++;
		n /= 10;
	}
	return count;
}

//创建大奇数函数
string create_hyperodd(string aa)//输入为待创建的字符串
{
	string s;
	int n = 0;
	int count = 0;
	srand((unsigned)time(NULL)); //播种子
	for (int i = 0;i < 100;i++)
	{
		{
			n = rand() % 100000;
			if (n >= 10000)//先产生10000~100000以内的随机整数（5位），产生19个，得到前95位
			{
				count++;
				stringstream ss;
				ss << n;//过渡字符串
				ss >> s;
				aa = aa + s;//粘贴
				if (count == 19)
				{
					break;
				}
			}
		}
	}
	n = prime_basket[rand() % 5314 + 1229];//产生最后5位，从素数表第1229~6543个元素寻找
	stringstream ss;
	ss << n;
	ss >> s;
	aa = aa + s;//粘贴
	return aa;
}

//大数打印函数
void HyperPrint(char hnum[], int hnum_length)//传入参数为待打印大数，大数长度
{
	for (; hnum[hnum_length] == 0 && hnum_length >= 0; hnum_length--);//去零
	if (hnum_length >= 0)
		for (int i = 0; i <= hnum_length;i++)
			cout << hnum[i];
	cout << '\n';
}

//复制函数，用于int数组
void copy_array(int fresh[], int old[], int size)//传入参数为新数组、原数组、数组长度
{
	for (int i = 0; i < size; i++)
		fresh[i] = old[i];
}

//数组检测函数，返回值为数组非零元素数
int detect_array(int a[], int estimated_size)//传入参数为数组、预估长度
{
	for (int i = estimated_size; i >= 0;i--)
	{
		if (a[i] != 0) {
			return i + 1;//寻找到第一个非零元素时停止，返回i+1
			break;
		}
	}
}

//零位检测函数，返回值为数组为零元素数
int detect_zero(int a[], int size)//传入参数为数组、预估长度
{
	int detect = 0;
	for (int i = 0;i < size;i++)
		if (a[i] == 0)//每次寻找到一个为零的元素加1
			detect++;
	return detect;
}

//数组倒置函数
int* reverse_array(int inum[], int rnum[], int length, int flag)//传入参数为倒置前数组、倒置后数组、数组长度、标志
{
	for (int i = 0; i < length; i++)
		rnum[i] = inum[length - 1 - i];
	copy_array(inum, rnum, length);
	if (flag == 1)
		copy_array(_N, inum, length);//适用于幂模运算情形
	if (flag == 2)
		copy_array(_cee, inum, length);//适用于幂模运算情形
	return inum;
}

//char数组转int数组函数
void char_to_int_array(char a[], int b[])//传入参数为char数组、int数组
{
	int alength = strlen(a);
	for (int i = 0; i < alength; i++)
	{
		b[alength - 1 - i] = a[i] - '0';//ASCII符转化
	}
}

//复制数组函数（使用于char型数组）
void copy_ARRAY(char fresh[], char old[], int size)//传入参数为新数组、原数组、数组长度
{
	for (int i = 0; i < size; i++)
		fresh[i] = old[i];
}

//大数比较函数
int HyperEqual(int inum1[], int inum2[]) //传入参数为两个大数 
{
	int len1 = 99, len2 = 99;
	for (; inum1[len1] == 0 && len1 >= 0; len1--);//去零
	for (; inum2[len2] == 0 && len2 >= 0; len2--);//去零
	if (len1 > len2)
		return 1;
	else if (len1 < len2)
		return -1;
	else if (len1 == len2)
	{
		int len = len1, j = len - 1;
		for (int i = 0; i < len;i++)//从后向前逐位比较
		{
			if (inum1[j] > inum2[j])
				return 1;
			else if (inum1[j] < inum2[j])
				return -1;
			else if (inum1[j] == inum2[j])
				j--;
			else if ((inum1[j] == inum2[j]) && (j == 0))
				return 0;
		}
	}
}

//用于p、q运算时的大数纯减函数，适用于大数减1（或减2）
int* HyperPureSub_pq(int hnum1[], int hnum2[], int flag)//传入参数为两个大数与标志
{
	int sub_z[115] = { 0 };//定义结果数组
	int i, j = 0;
	int len1, len2;
	if (flag == 1) len1 = p_length;//flag为1对应p
	if (flag == 2) len1 = q_length;//flag为2对应q
	len2 = 1;
	for (i = 0;i < len1;i++)
	{
		if (hnum1[i] >= hnum2[i])//如果x[i]>=y[i]，不用向前一位借1，可直接减 
			sub_z[i] = hnum1[i] - hnum2[i];
		else  //如果x[i]<y[i]，向前一位借1，同时前一位应减1 
		{
			sub_z[i] = hnum1[i] + 10 - hnum2[i];
			hnum1[i + 1] = hnum1[i + 1] - 1;
		}
	}
	for (i = len1 - 1;i > 0;i--)//删除前缀0 
	{
		if (sub_z[i] == 0)
			len1--;
		else
			break;
	}
	if (flag == 1)
		copy_array(int_pp, sub_z, 114);//遇到p时，将结果回传
	if (flag == 2)
		copy_array(int_qq, sub_z, 114);//遇到q时，将结果回传
	print_array(sub_z, 114);
	return 0;
}

//用于大数除法时的大数减函数
int Hyper_Upure_Sub(int hnum1[], int hnum2[], int len1, int len2)//传入参数为两个数组及其长度
{
	int i;
	if (len1 < len2)
		return -1;
	if (len1 == len2)//判断p1 > p2
	{
		for (i = len1 - 1; i >= 0; i--)
		{
			if (hnum1[i] > hnum2[i])   //若大，则满足条件，可做减法
				break;
			else if (hnum1[i] < hnum2[i]) //否则返回-1
				return -1;
		}
	}
	for (i = 0; i <= len1 - 1; i++)  //从低位开始做减法
	{
		hnum1[i] -= hnum2[i];
		if (hnum1[i] < 0)          //若p1<0，则需要借位
		{
			hnum1[i] += 10;         //借1当10
			hnum1[i + 1]--;           //高位减1
		}
	}
	for (i = len1 - 1; i >= 0; i--)       //查找结果的最高位
		if (hnum1[i])                  //最高位第一个不为0
			return (i + 1);       //得到位数并返回
	return 0;                  //两数相等的时候返回0
}

//适用于p、q时的大数相乘函数
int* HyperMul_pq(int hnum1[], int hnum2[], int flag)//传入参数为两个数组与标志
{
	int len1, len2, i, j;
	int mul_z[300] = { 0 };
	len1 = p_length, len2 = q_length;
	for (i = 0;i < len1;i++)//将因数各个位上的数字与另一个各个位上的数字相乘 
	{
		for (j = 0;j < len2;j++)
			mul_z[i + j] = mul_z[i + j] + hnum1[i] * hnum2[j];//先乘起来，后面统一进行进位 
	}
	for (i = 0;i <= len1 + len2;i++)//进行进位 
	{
		if (mul_z[i] >= 10)  //若>=10 
		{
			mul_z[i + 1] = mul_z[i + 1] + mul_z[i] / 10;  //将十位上数字进位 
			mul_z[i] = mul_z[i] % 10;  //将个位上的数字留下
		}
	}
	for (i = len1 + len2;i > 0;i--)  //删除0的前缀 
	{
		if (mul_z[i] == 0)
			continue;
		else
			break;
	}
	print_array(mul_z, 299);
	if (flag == 1)
		copy_array(int_n, mul_z, 299);//为1对应p
	if (flag == 2)
		copy_array(int_phy, mul_z, 299);//为2对应q
	return 0;
}

//适用于d、e时的大数相乘函数
int* HyperMul_de(int hnum1[], int hnum2[])//传入参数为两个大数
{
	int len1, len2, i, j;
	int mul_de[300] = { 0 };
	len1 = detect_array(hnum1, 99), len2 = detect_array(hnum2, 99);
	for (i = 0;i < len1;i++)//将因数各个位上的数字与另一个各个位上的数字相乘 
	{
		for (j = 0;j < len2;j++)
			mul_de[i + j] = mul_de[i + j] + hnum1[i] * hnum2[j];//先乘起来，后面统一进行进位 
	}
	for (i = 0;i <= len1 + len2;i++)//进行进位 
	{
		if (mul_de[i] >= 10)  //若>=10 
		{
			mul_de[i + 1] = mul_de[i + 1] + mul_de[i] / 10;  //将十位上数字进位 
			mul_de[i] = mul_de[i] % 10;  //将个位上的数字留下
		}
	}
	for (i = len1 + len2;i > 0;i--)  //删除0的前缀 
	{
		if (mul_de[i] == 0)
			continue;
		else
			break;
	}
	copy_array(pro, mul_de, 199);//将得到的结果回传
	return 0;
}

//适用于d、e的大数相加函数
int* HyperAdd_de(int inum1[], int inum2[], int flag)//传入参数为两个数组与标志
{
	int add_de[115] = { 0 };
	int len;
	if (flag == 1)
		len = detect_array(pro, 99);//为1时传入pro
	if (flag == 2)
		len = detect_array(sum, 99);//为2时传入sum
	int i = 0;
	i = 0;//从最低位(个位)开始进行计算
	int m = 0;
	for (i = 0;i < len;i++)
	{
		add_de[i] = (inum1[i] + inum2[i] + m) % 10;//将所得数的个位存到数组z[i]中去 
		if ((inum1[i] + inum2[i] + m) >= 10)
			m = 1;
		else
			m = 0;
	}
	if ((inum1[i - 1] + inum2[i - 1] + m) >= 10)//判断运算的最大位的和是否>=10 
		add_de[i] = 1;
	else
		i = i - 1;
	copy_array(inum1, add_de, 109);
	if (flag == 1)
		copy_array(pro, inum1, 109);//为1时回传pro
	if (flag == 2)
		copy_array(sum, inum1, 109);//为2时回传sum
	//	print_array(inum, 109);
	return 0;
}

//适用于p、q的大数加函数
int* HyperAdd_pq(int inum1[], int inum2[], int flag)//传入参数为两个大数与标志
{
	int add_de[115] = { 0 };
	int len;
	if (flag == 1)
		len = p_length;//为1时传入p
	if (flag == 2)
		len = q_length;//为2时传入q
	int i = 0;
	i = 0;//从最低位(个位)开始进行计算
	int m = 0;
	for (i = 0;i < len;i++)
	{
		add_de[i] = (inum1[i] + inum2[i] + m) % 10;//将所得数的个位存到数组z[i]中去 
		if ((inum1[i] + inum2[i] + m) >= 10)
			m = 1;
		else
			m = 0;
	}
	if ((inum1[i - 1] + inum2[i - 1] + m) >= 10)//判断运算的最大位的和是否>=10 
		add_de[i] = 1;
	else
		i = i - 1;
	copy_array(inum1, add_de, 109);
	return 0;
}

//适用于d、e的大数相除函数
int* HyperDiv_de(int hnum1[], int hnum2[])//传入参数为两个大数
//除法函数 
{
	int num_c[200] = { 0 }, num_d_de[200] = { 0 };//定义商数组、余数数组
	int len1 = detect_array(hnum1, 199);
	int len2 = detect_array(hnum2, 99);

	int nTimes = len1 - len2;
	int nTemp;
	for (int m = len1 - 1; m >= 0; m--)
	{
		if (m >= nTimes)
			hnum2[m] = hnum2[m - nTimes];//如果除数与被除数有位数差，先把除数补到和被除数同位
		else
			hnum2[m] = 0;
	}
	len2 = len1;
	for (int j = 0;j <= nTimes;j++)
	{
		while ((nTemp = Hyper_Upure_Sub(hnum1, hnum2 + j, len1, len2 - j)) >= 0)
			//当被除数不能被同位除数相减时，移去被除数最高位，同位除数下移位，继续运算
		{
			len1 = nTemp;
			num_c[nTimes - j]++;
		}
	}
	int i_res;
	for (i_res = 99; hnum1[i_res] == 0 && i_res >= 0; i_res--);//跳过高位0
	if (i_res >= 0)
		for (; i_res >= 0; i_res--)
			num_d_de[i_res] = hnum1[i_res];//回传
	copy_array(quotient, num_c, 199);
	copy_array(remain, num_d_de, 199);
	return 0;
}

//大数转二进制函数
int* HyperToBinary(int inum[], int onum[800])//传入参数为大数、二进制数组
{
	int  j;
	int div, sumdiv, yu, k;
	int len = detect_array(inum, 299);
	memset(onum, 0, sizeof(onum));//分配空间
	sumdiv = 1;k = 0;div = 0;
	while (sumdiv)
	{
		sumdiv = 0;
		for (int i = 0;i < len;i++)//每次对每位除以2，取商取余，顺次回传，除完一位则降位
		{
			j = i + 1;
			div = inum[i] / 2;
			sumdiv += div;
			yu = inum[i] % 2;
			if (i == (len - 1))
				onum[k++] = yu;
			else inum[j] += yu * 10;//除完降位
			inum[i] = div;
		}
	}
	if (k == 0)cout << 0;
	else
	{
		cout << "二进制转化的结果为:";
		for (int i = k - 1;i >= 0;i--)//逆序输出
		{
			cout << onum[i];
		}
		cout << '\n';
	}

	return onum;
}


//适用于幂模运算的大数除法函数
int* HyperDiv_memo(int hnum1[], int hnum2[])//传入参数为
{
	int num_c[800] = { 0 }, num_d_memo[800] = { 0 };
	int len1 = detect_array(hnum1, 799);
	int len2 = detect_array(hnum2, 299);

	int nTimes = len1 - len2;
	int nTemp;
	for (int m = len1 - 1; m >= 0; m--)
	{
		if (m >= nTimes)
			hnum2[m] = hnum2[m - nTimes];//如果除数与被除数有位数差，先把除数补到和被除数同位
		else
			hnum2[m] = 0;
	}
	len2 = len1;
	for (int j = 0;j <= nTimes;j++)
	{
		while ((nTemp = Hyper_Upure_Sub(hnum1, hnum2 + j, len1, len2 - j)) >= 0)
		{//当被除数不能被同位除数相减时，移去被除数最高位，同位除数下移位，继续运算
			len1 = nTemp;
			num_c[nTimes - j]++;
		}
	}
	int i_res;
	for (i_res = 799; hnum1[i_res] == 0 && i_res >= 0; i_res--);//跳过高位0
	if (i_res >= 0)
		for (; i_res >= 0; i_res--)
			num_d_memo[i_res] = hnum1[i_res];
	//	copy_array(quotient, num_c, 100);
	copy_array(hnum1, num_d_memo, 799);

	return 0;
}

//适用于幂模运算的大数乘法
int* HyperMul_memo(int hnum1[], int hnum2[])//传入参数为两个大数
{
	int len1, len2, i, j;
	int mul_z[2000] = { 0 };
	len1 = detect_array(hnum1, 899), len2 = detect_array(hnum2, 299);
	for (i = 0;i < len1;i++)//将因数各个位上的数字与另一个各个位上的数字相乘 
	{
		for (j = 0;j < len2;j++)
			mul_z[i + j] = mul_z[i + j] + hnum1[i] * hnum2[j];//先乘起来，后面统一进行进位 
	}
	for (i = 0;i <= len1 + len2;i++)//进行进位 
	{
		if (mul_z[i] >= 10)  //若>=10 
		{
			mul_z[i + 1] = mul_z[i + 1] + mul_z[i] / 10;  //将十位上数字进位 
			mul_z[i] = mul_z[i] % 10;  //将个位上的数字留下
		}
	}
	for (i = len1 + len2;i > 0;i--)  //删除0的前缀 
	{
		if (mul_z[i] == 0)
			continue;
		else
			break;
	}
	//	print_array(mul_z, 100);
//	if (flag == 1)
	copy_array(hnum1, mul_z, 1000);
	//	if (flag == 2)
	//		copy_array(Two, mul_z, 115);
	return 0;
}


//大数的二进制与函数
bool Hyper_binary_YU()
{
	copy_array(_ce, _cce, 799);//将待检测函数复制
	copy_array(ccTwo, cTwo, 799);//将待检测函数复制
	//	HyperMul_memo(_ce, Two);
	//	HyperToBinary(ccTwo, _ce);
	for (int i = 0; i < 799; i++)
	{
		if ((_ce[i] == 1) && (ccTwo[i] == 1))//如果两位均为1，记录1
			detect[i] = 1;
		else//否则记录0
			detect[i] = 0;
	}
	int D_D = detect_zero(detect, 799);//检测有多少个0
	copy_array(_cce, _ce, 799);
//	cout << "计算的或结果为：" << D_D << '\n';
//	cout << "或数组为：";
	if (D_D == 799) {
//		cout << '0' << '\n';
		return false;
	}
	else {
//		print_array(detect, 799);cout << '\n';
		return true;
	}
}

#endif