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

//�ַ�ת�����ƺ�������ʵ�����ͬ��
void code_trans_cb(char s[], int flag) {//�������Ϊ�ַ������飬�����Ԫ��
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
		HyperPrint(z, 8);//�������ӡ����
	if (flag == 2)
		sst << z;
	//	return sst;
}

//������ת�ַ���������ʵ�����ͬ��
void code_trans_bc()
{
	cout << (char)binary.to_ulong() << endl;//����bitset��
}

//��ӡ���麯����int���飬���㣬�����ӡ��
void print_array(int a[], int print_length)//�������Ϊ���顢��ӡ���ȣ�δ֪��
{
	for (; a[print_length] == 0 && print_length >= 0; print_length--);//����
	for (int i = print_length; i >= 0; i--)
		printf_s("%d", a[i]);
}

//��ӡ���麯����int���飬�����㣬�����ӡ��
void print_ARRAY(int a[], int print_length)//�������Ϊ���顢��ӡ���ȣ���֪��
{
	for (int i = print_length - 1; i >= 0; i--)
		cout << a[i];
}


//��������p����
int* create_prime_p(int pr[100], int length, const unsigned k)//�������Ϊ�����������������ȡ����Լ�����
{
	assert(k > 0);//�ж�k�Ƿ����0������ֱ������
	pr = create_odd_p(pr, length);//����һ������
	cout << "���������ǣ�";print_array(pr, 100);cout << "\n\n";
	copy_array(cpr, pr, 99);//����pr�����ƣ�������һ������
	while (prime_test(k, 1) == false)//������Ϊ�٣���ִ��
	{
		cout << "����������������ѡ���������м�2" << "\n\n";
		HyperAdd_pq(cpr, Two, 1);//ͨ����2�ķ�ʽ���ٴμ��
		cout << "���������ǣ�";print_array(cpr, 100);cout << "\n\n";
	}
	cout << "���ɹ���" << "\n\n";
	copy_array(p, cpr, 99);//���������ش�
	return pr;
}

//��������p����
int* create_odd_p(int* apr, unsigned length)//�������Ϊ������ָ�롢������
{
	odd_p = create_hyperodd(odd_p);//����100λ����������
	odd_p = odd_p.substr(100 - length);//�Ӻ����ȡ����length������һ��Ϊ����

	for (unsigned int i = 0; i < length; i++)
		apr[i] = (char)(odd_p[length - 1 - i] - 48);//stringתint
	return apr;
}

//��������q��������p��ͬ
int* create_prime_q(int qr[100], int length, const unsigned k)//�������Ϊ�����������������ȡ����Լ�����
{
	assert(k > 0);//�ж�k�Ƿ����0������ֱ������
	qr = create_odd_q(qr, length);//����һ������
	cout << "���������ǣ�";print_array(qr, 100);cout << "\n\n";
	copy_array(cqr, qr, 99);//����qr�����ƣ�������һ������
	while (prime_test(k, 2) == false)//������Ϊ�٣���ִ��
	{
		cout << "��ѡ���������м�2" << "\n\n";
		HyperAdd_pq(qr, Two, 2);//ͨ����2�ķ�ʽ���ٴμ��
	}
	cout << "���ɹ���" << "\n\n";
	copy_array(q, cqr, 99);//���������ش�
	return qr;
}

//��������q��������p��ͬ
int* create_odd_q(int* aqr, unsigned length)//�������Ϊ������ָ�롢������
{
	odd_q = create_hyperodd(odd_q);//����100λ����������
	odd_q = odd_q.substr(100 - length);//�Ӻ����ȡ����length������һ��Ϊ����
	for (unsigned int i = 0; i < length; i++)
		aqr[i] = (char)(odd_q[length - 1 - i] - 48);//stringתint
	return aqr;
}


/*���Լ���㷨��Miller-Rabin�㷨��
a.��������M��ʹ��N=(2^j)*M+1
b.ѡ�������A < N
c.��������i < j����A ^ ((2 ^ i)*M) MOD N = N - 1����Nͨ�������A�Ĳ���
d.��A^M MOD N = 1����Nͨ�������A�Ĳ���
e.��Aȡ��ͬ��ֵ��N����5�β��ԣ���ȫ��ͨ�����ж�NΪ����
f.��Nͨ��һ�β��ԣ���N���������ĸ���Ϊ 25 % ����N ͨ��t �β��ԣ���N���������ĸ���Ϊ(1/4)^t��
�ڱ�ʵ���У�ʵ�ʼ��15��*/
bool prime_test(unsigned k, int flag)//�������Ϊ������������־
{
	cout << "��ʼ����������⣺" << "\n\n";;
	bool judge = false;
	if (flag == 1)
		cout << "��p�ļ�⣺", copy_array(num, cpr, 99);cout << "\n\n";//�������Ƹ�num��׼�����
	if (flag == 2)
		cout << "��q�ļ�⣺", copy_array(num, cqr, 99);cout << "\n\n";//�������Ƹ�num��׼�����
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
	srand((unsigned)time(NULL));//������
	int numlength = detect_array(num, 99);int PrK;//���num����λ��
	if (numlength <= 3)
	{
		for (int i = 0; i < 168;i++)
		{
			if (100 * num[2] + 10 * num[1] + num[0] == prime_basket[i]){
				judge = true;
				break;
			}
		}
		if (flag == 1) copy_array(num, cpr, 99);//��p��
		if (flag == 2) copy_array(num, cqr, 99);//��q��
	}
	else {
		for (unsigned int i = 0; i < 5 * k; i++)
		{
			for (;;) {
				(numlength == 4) ?//�����������4λ���£����������г�ȡǰ168��Ԫ�ؼ��㣻�����ȡǰ13848��Ԫ��
					(PrK = prime_basket[rand() % 168]) : (PrK = prime_basket[rand() % 13848]);
				int_to_array(tes_m, PrK);//������λת��Ϊ���飬׼���Ƚ�

				if (HyperEqual(num, tes_m) == 1)//���num>tes_m�������Ƚ�
				{
					cout << "ѡ���������Ϊ��" << PrK << "\n\n";
					break;
				}
				else
					cout << "����������������" << '\n';
			}
			HyperDiv_de(num, tes_m);//���������
			cout << "�����������Ϊ��";print_array(remain, 99);cout << "\n\n";
			if (flag == 1) copy_array(num, cpr, 99);//��p��
			if (flag == 2) copy_array(num, cqr, 99);//��q��
			if (detect_array(remain, 99) == 99)//���remainȫ�㣬��������˵���Ǻ���
			{
				judge = false;
				break;
			}
			else
				judge = true;//�������������
		}
	}
	return judge;
}

//����ת���麯��
int* int_to_array(int a[], int b)//�������Ϊת�����顢��ת����
{
	int tyc[100] = { 0 };//�����м�����
	int N = getLength(b);//��ȡ���ֳ��Ⱥ���
	int NN = N;
	for (int i = 0; ;i++)
	{
		int c = pow(10, N - 1);
		a[i] = b / c;//ÿ�γ���10�����̸���a
		b -= a[i] * c;
		N--;
		if (b == 0)
			break;
	}
	for (int i = 0; i < NN; i++)
		tyc[i] = a[NN - 1 - i];//��������
	copy_array(tes_m, tyc, 99);//�ش�
	return 0;
}

//��ȡ���ֳ��Ⱥ���
int getLength(int b)//����Ϊint�ͱ���
{
	int n = b, count = 0;
	while (n)
	{
		count++;
		n /= 10;
	}
	return count;
}

//��������������
string create_hyperodd(string aa)//����Ϊ���������ַ���
{
	string s;
	int n = 0;
	int count = 0;
	srand((unsigned)time(NULL)); //������
	for (int i = 0;i < 100;i++)
	{
		{
			n = rand() % 100000;
			if (n >= 10000)//�Ȳ���10000~100000���ڵ����������5λ��������19�����õ�ǰ95λ
			{
				count++;
				stringstream ss;
				ss << n;//�����ַ���
				ss >> s;
				aa = aa + s;//ճ��
				if (count == 19)
				{
					break;
				}
			}
		}
	}
	n = prime_basket[rand() % 5314 + 1229];//�������5λ�����������1229~6543��Ԫ��Ѱ��
	stringstream ss;
	ss << n;
	ss >> s;
	aa = aa + s;//ճ��
	return aa;
}

//������ӡ����
void HyperPrint(char hnum[], int hnum_length)//�������Ϊ����ӡ��������������
{
	for (; hnum[hnum_length] == 0 && hnum_length >= 0; hnum_length--);//ȥ��
	if (hnum_length >= 0)
		for (int i = 0; i <= hnum_length;i++)
			cout << hnum[i];
	cout << '\n';
}

//���ƺ���������int����
void copy_array(int fresh[], int old[], int size)//�������Ϊ�����顢ԭ���顢���鳤��
{
	for (int i = 0; i < size; i++)
		fresh[i] = old[i];
}

//�����⺯��������ֵΪ�������Ԫ����
int detect_array(int a[], int estimated_size)//�������Ϊ���顢Ԥ������
{
	for (int i = estimated_size; i >= 0;i--)
	{
		if (a[i] != 0) {
			return i + 1;//Ѱ�ҵ���һ������Ԫ��ʱֹͣ������i+1
			break;
		}
	}
}

//��λ��⺯��������ֵΪ����Ϊ��Ԫ����
int detect_zero(int a[], int size)//�������Ϊ���顢Ԥ������
{
	int detect = 0;
	for (int i = 0;i < size;i++)
		if (a[i] == 0)//ÿ��Ѱ�ҵ�һ��Ϊ���Ԫ�ؼ�1
			detect++;
	return detect;
}

//���鵹�ú���
int* reverse_array(int inum[], int rnum[], int length, int flag)//�������Ϊ����ǰ���顢���ú����顢���鳤�ȡ���־
{
	for (int i = 0; i < length; i++)
		rnum[i] = inum[length - 1 - i];
	copy_array(inum, rnum, length);
	if (flag == 1)
		copy_array(_N, inum, length);//��������ģ��������
	if (flag == 2)
		copy_array(_cee, inum, length);//��������ģ��������
	return inum;
}

//char����תint���麯��
void char_to_int_array(char a[], int b[])//�������Ϊchar���顢int����
{
	int alength = strlen(a);
	for (int i = 0; i < alength; i++)
	{
		b[alength - 1 - i] = a[i] - '0';//ASCII��ת��
	}
}

//�������麯����ʹ����char�����飩
void copy_ARRAY(char fresh[], char old[], int size)//�������Ϊ�����顢ԭ���顢���鳤��
{
	for (int i = 0; i < size; i++)
		fresh[i] = old[i];
}

//�����ȽϺ���
int HyperEqual(int inum1[], int inum2[]) //�������Ϊ�������� 
{
	int len1 = 99, len2 = 99;
	for (; inum1[len1] == 0 && len1 >= 0; len1--);//ȥ��
	for (; inum2[len2] == 0 && len2 >= 0; len2--);//ȥ��
	if (len1 > len2)
		return 1;
	else if (len1 < len2)
		return -1;
	else if (len1 == len2)
	{
		int len = len1, j = len - 1;
		for (int i = 0; i < len;i++)//�Ӻ���ǰ��λ�Ƚ�
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

//����p��q����ʱ�Ĵ������������������ڴ�����1�����2��
int* HyperPureSub_pq(int hnum1[], int hnum2[], int flag)//�������Ϊ�����������־
{
	int sub_z[115] = { 0 };//����������
	int i, j = 0;
	int len1, len2;
	if (flag == 1) len1 = p_length;//flagΪ1��Ӧp
	if (flag == 2) len1 = q_length;//flagΪ2��Ӧq
	len2 = 1;
	for (i = 0;i < len1;i++)
	{
		if (hnum1[i] >= hnum2[i])//���x[i]>=y[i]��������ǰһλ��1����ֱ�Ӽ� 
			sub_z[i] = hnum1[i] - hnum2[i];
		else  //���x[i]<y[i]����ǰһλ��1��ͬʱǰһλӦ��1 
		{
			sub_z[i] = hnum1[i] + 10 - hnum2[i];
			hnum1[i + 1] = hnum1[i + 1] - 1;
		}
	}
	for (i = len1 - 1;i > 0;i--)//ɾ��ǰ׺0 
	{
		if (sub_z[i] == 0)
			len1--;
		else
			break;
	}
	if (flag == 1)
		copy_array(int_pp, sub_z, 114);//����pʱ��������ش�
	if (flag == 2)
		copy_array(int_qq, sub_z, 114);//����qʱ��������ش�
	print_array(sub_z, 114);
	return 0;
}

//���ڴ�������ʱ�Ĵ���������
int Hyper_Upure_Sub(int hnum1[], int hnum2[], int len1, int len2)//�������Ϊ�������鼰�䳤��
{
	int i;
	if (len1 < len2)
		return -1;
	if (len1 == len2)//�ж�p1 > p2
	{
		for (i = len1 - 1; i >= 0; i--)
		{
			if (hnum1[i] > hnum2[i])   //������������������������
				break;
			else if (hnum1[i] < hnum2[i]) //���򷵻�-1
				return -1;
		}
	}
	for (i = 0; i <= len1 - 1; i++)  //�ӵ�λ��ʼ������
	{
		hnum1[i] -= hnum2[i];
		if (hnum1[i] < 0)          //��p1<0������Ҫ��λ
		{
			hnum1[i] += 10;         //��1��10
			hnum1[i + 1]--;           //��λ��1
		}
	}
	for (i = len1 - 1; i >= 0; i--)       //���ҽ�������λ
		if (hnum1[i])                  //���λ��һ����Ϊ0
			return (i + 1);       //�õ�λ��������
	return 0;                  //������ȵ�ʱ�򷵻�0
}

//������p��qʱ�Ĵ�����˺���
int* HyperMul_pq(int hnum1[], int hnum2[], int flag)//�������Ϊ�����������־
{
	int len1, len2, i, j;
	int mul_z[300] = { 0 };
	len1 = p_length, len2 = q_length;
	for (i = 0;i < len1;i++)//����������λ�ϵ���������һ������λ�ϵ�������� 
	{
		for (j = 0;j < len2;j++)
			mul_z[i + j] = mul_z[i + j] + hnum1[i] * hnum2[j];//�ȳ�����������ͳһ���н�λ 
	}
	for (i = 0;i <= len1 + len2;i++)//���н�λ 
	{
		if (mul_z[i] >= 10)  //��>=10 
		{
			mul_z[i + 1] = mul_z[i + 1] + mul_z[i] / 10;  //��ʮλ�����ֽ�λ 
			mul_z[i] = mul_z[i] % 10;  //����λ�ϵ���������
		}
	}
	for (i = len1 + len2;i > 0;i--)  //ɾ��0��ǰ׺ 
	{
		if (mul_z[i] == 0)
			continue;
		else
			break;
	}
	print_array(mul_z, 299);
	if (flag == 1)
		copy_array(int_n, mul_z, 299);//Ϊ1��Ӧp
	if (flag == 2)
		copy_array(int_phy, mul_z, 299);//Ϊ2��Ӧq
	return 0;
}

//������d��eʱ�Ĵ�����˺���
int* HyperMul_de(int hnum1[], int hnum2[])//�������Ϊ��������
{
	int len1, len2, i, j;
	int mul_de[300] = { 0 };
	len1 = detect_array(hnum1, 99), len2 = detect_array(hnum2, 99);
	for (i = 0;i < len1;i++)//����������λ�ϵ���������һ������λ�ϵ�������� 
	{
		for (j = 0;j < len2;j++)
			mul_de[i + j] = mul_de[i + j] + hnum1[i] * hnum2[j];//�ȳ�����������ͳһ���н�λ 
	}
	for (i = 0;i <= len1 + len2;i++)//���н�λ 
	{
		if (mul_de[i] >= 10)  //��>=10 
		{
			mul_de[i + 1] = mul_de[i + 1] + mul_de[i] / 10;  //��ʮλ�����ֽ�λ 
			mul_de[i] = mul_de[i] % 10;  //����λ�ϵ���������
		}
	}
	for (i = len1 + len2;i > 0;i--)  //ɾ��0��ǰ׺ 
	{
		if (mul_de[i] == 0)
			continue;
		else
			break;
	}
	copy_array(pro, mul_de, 199);//���õ��Ľ���ش�
	return 0;
}

//������d��e�Ĵ�����Ӻ���
int* HyperAdd_de(int inum1[], int inum2[], int flag)//�������Ϊ�����������־
{
	int add_de[115] = { 0 };
	int len;
	if (flag == 1)
		len = detect_array(pro, 99);//Ϊ1ʱ����pro
	if (flag == 2)
		len = detect_array(sum, 99);//Ϊ2ʱ����sum
	int i = 0;
	i = 0;//�����λ(��λ)��ʼ���м���
	int m = 0;
	for (i = 0;i < len;i++)
	{
		add_de[i] = (inum1[i] + inum2[i] + m) % 10;//���������ĸ�λ�浽����z[i]��ȥ 
		if ((inum1[i] + inum2[i] + m) >= 10)
			m = 1;
		else
			m = 0;
	}
	if ((inum1[i - 1] + inum2[i - 1] + m) >= 10)//�ж���������λ�ĺ��Ƿ�>=10 
		add_de[i] = 1;
	else
		i = i - 1;
	copy_array(inum1, add_de, 109);
	if (flag == 1)
		copy_array(pro, inum1, 109);//Ϊ1ʱ�ش�pro
	if (flag == 2)
		copy_array(sum, inum1, 109);//Ϊ2ʱ�ش�sum
	//	print_array(inum, 109);
	return 0;
}

//������p��q�Ĵ����Ӻ���
int* HyperAdd_pq(int inum1[], int inum2[], int flag)//�������Ϊ�����������־
{
	int add_de[115] = { 0 };
	int len;
	if (flag == 1)
		len = p_length;//Ϊ1ʱ����p
	if (flag == 2)
		len = q_length;//Ϊ2ʱ����q
	int i = 0;
	i = 0;//�����λ(��λ)��ʼ���м���
	int m = 0;
	for (i = 0;i < len;i++)
	{
		add_de[i] = (inum1[i] + inum2[i] + m) % 10;//���������ĸ�λ�浽����z[i]��ȥ 
		if ((inum1[i] + inum2[i] + m) >= 10)
			m = 1;
		else
			m = 0;
	}
	if ((inum1[i - 1] + inum2[i - 1] + m) >= 10)//�ж���������λ�ĺ��Ƿ�>=10 
		add_de[i] = 1;
	else
		i = i - 1;
	copy_array(inum1, add_de, 109);
	return 0;
}

//������d��e�Ĵ����������
int* HyperDiv_de(int hnum1[], int hnum2[])//�������Ϊ��������
//�������� 
{
	int num_c[200] = { 0 }, num_d_de[200] = { 0 };//���������顢��������
	int len1 = detect_array(hnum1, 199);
	int len2 = detect_array(hnum2, 99);

	int nTimes = len1 - len2;
	int nTemp;
	for (int m = len1 - 1; m >= 0; m--)
	{
		if (m >= nTimes)
			hnum2[m] = hnum2[m - nTimes];//��������뱻������λ����Ȱѳ��������ͱ�����ͬλ
		else
			hnum2[m] = 0;
	}
	len2 = len1;
	for (int j = 0;j <= nTimes;j++)
	{
		while ((nTemp = Hyper_Upure_Sub(hnum1, hnum2 + j, len1, len2 - j)) >= 0)
			//�����������ܱ�ͬλ�������ʱ����ȥ���������λ��ͬλ��������λ����������
		{
			len1 = nTemp;
			num_c[nTimes - j]++;
		}
	}
	int i_res;
	for (i_res = 99; hnum1[i_res] == 0 && i_res >= 0; i_res--);//������λ0
	if (i_res >= 0)
		for (; i_res >= 0; i_res--)
			num_d_de[i_res] = hnum1[i_res];//�ش�
	copy_array(quotient, num_c, 199);
	copy_array(remain, num_d_de, 199);
	return 0;
}

//����ת�����ƺ���
int* HyperToBinary(int inum[], int onum[800])//�������Ϊ����������������
{
	int  j;
	int div, sumdiv, yu, k;
	int len = detect_array(inum, 299);
	memset(onum, 0, sizeof(onum));//����ռ�
	sumdiv = 1;k = 0;div = 0;
	while (sumdiv)
	{
		sumdiv = 0;
		for (int i = 0;i < len;i++)//ÿ�ζ�ÿλ����2��ȡ��ȡ�࣬˳�λش�������һλ��λ
		{
			j = i + 1;
			div = inum[i] / 2;
			sumdiv += div;
			yu = inum[i] % 2;
			if (i == (len - 1))
				onum[k++] = yu;
			else inum[j] += yu * 10;//���꽵λ
			inum[i] = div;
		}
	}
	if (k == 0)cout << 0;
	else
	{
		cout << "������ת���Ľ��Ϊ:";
		for (int i = k - 1;i >= 0;i--)//�������
		{
			cout << onum[i];
		}
		cout << '\n';
	}

	return onum;
}


//��������ģ����Ĵ�����������
int* HyperDiv_memo(int hnum1[], int hnum2[])//�������Ϊ
{
	int num_c[800] = { 0 }, num_d_memo[800] = { 0 };
	int len1 = detect_array(hnum1, 799);
	int len2 = detect_array(hnum2, 299);

	int nTimes = len1 - len2;
	int nTemp;
	for (int m = len1 - 1; m >= 0; m--)
	{
		if (m >= nTimes)
			hnum2[m] = hnum2[m - nTimes];//��������뱻������λ����Ȱѳ��������ͱ�����ͬλ
		else
			hnum2[m] = 0;
	}
	len2 = len1;
	for (int j = 0;j <= nTimes;j++)
	{
		while ((nTemp = Hyper_Upure_Sub(hnum1, hnum2 + j, len1, len2 - j)) >= 0)
		{//�����������ܱ�ͬλ�������ʱ����ȥ���������λ��ͬλ��������λ����������
			len1 = nTemp;
			num_c[nTimes - j]++;
		}
	}
	int i_res;
	for (i_res = 799; hnum1[i_res] == 0 && i_res >= 0; i_res--);//������λ0
	if (i_res >= 0)
		for (; i_res >= 0; i_res--)
			num_d_memo[i_res] = hnum1[i_res];
	//	copy_array(quotient, num_c, 100);
	copy_array(hnum1, num_d_memo, 799);

	return 0;
}

//��������ģ����Ĵ����˷�
int* HyperMul_memo(int hnum1[], int hnum2[])//�������Ϊ��������
{
	int len1, len2, i, j;
	int mul_z[2000] = { 0 };
	len1 = detect_array(hnum1, 899), len2 = detect_array(hnum2, 299);
	for (i = 0;i < len1;i++)//����������λ�ϵ���������һ������λ�ϵ�������� 
	{
		for (j = 0;j < len2;j++)
			mul_z[i + j] = mul_z[i + j] + hnum1[i] * hnum2[j];//�ȳ�����������ͳһ���н�λ 
	}
	for (i = 0;i <= len1 + len2;i++)//���н�λ 
	{
		if (mul_z[i] >= 10)  //��>=10 
		{
			mul_z[i + 1] = mul_z[i + 1] + mul_z[i] / 10;  //��ʮλ�����ֽ�λ 
			mul_z[i] = mul_z[i] % 10;  //����λ�ϵ���������
		}
	}
	for (i = len1 + len2;i > 0;i--)  //ɾ��0��ǰ׺ 
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


//�����Ķ������뺯��
bool Hyper_binary_YU()
{
	copy_array(_ce, _cce, 799);//������⺯������
	copy_array(ccTwo, cTwo, 799);//������⺯������
	//	HyperMul_memo(_ce, Two);
	//	HyperToBinary(ccTwo, _ce);
	for (int i = 0; i < 799; i++)
	{
		if ((_ce[i] == 1) && (ccTwo[i] == 1))//�����λ��Ϊ1����¼1
			detect[i] = 1;
		else//�����¼0
			detect[i] = 0;
	}
	int D_D = detect_zero(detect, 799);//����ж��ٸ�0
	copy_array(_cce, _ce, 799);
//	cout << "����Ļ���Ϊ��" << D_D << '\n';
//	cout << "������Ϊ��";
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