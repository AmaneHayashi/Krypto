#pragma once
#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include"test.h"

//�ַ���ת�����ƺ������������
void code_trans_cb(char s[], int x) {//�������Ϊ�ַ������飬�����Ԫ��
	int k = 1, real_k = 1;
	z[72] = { 0 }, real_z[72] = { 0 };
	z[0] = real_z[0] = '\0';//��ʼ��������real_z�����ո����ڼ��㣬z���ո��������
	for (int i = 0; s[i]; i++)
	{
		for (int j = 7;j >= 0;j--)
		{
			real_z[real_k] = bool((s[i] & (1 << j) != 0));//ÿ�����ƣ��Ƚϸ�λ�Ƿ�Ϊ1
			z[k] = real_z[real_k];
			k++, real_k++;
		}
		z[k++] = '\0';//��8�ı�����Ҫ
	}
	for (int i = 1;i < x; i++)
		(i % 9 == 0) ? (cout << " ") : cout << z[i];//ÿ8λ��һ�������
	cout << '\n';
}

//�ַ���ת�����ƺ��������������
void code_trans_cb_sys(char s[]) {//�������Ϊ�ַ�������
	int real_k = 1;
	real_z[72] = { 0 };
	real_z[0] = '\0';
	for (int i = 0; s[i]; i++)
	{
		for (int j = 7;j >= 0;j--)
		{
			real_z[real_k] = bool((s[i] & 1 << j) != 0);//ÿ�����ƣ��Ƚϸ�λ�Ƿ�Ϊ1, &Ϊ�����㣬<<Ϊ��������
			real_k++;
		}
	}
	cout << '\n';
}

//������ת�ַ�������������bitset�࣬�������
void code_trans_bc()
{
	cout << (char)binary.to_ulong() << endl;//ֱ�ӵ���bitset�ڵĺ���
}

//�任ת�ƺ���������16������Կ�ĺ�����
//�����������ΪCi��Di��key���ϲ��õ��ģ���finalkey���û��õ��ģ������Ʋ�����C/D����ĳ��ȡ��û������鳤��
int move_transfer(int a[], int b[], int combine[], int final[], int t[], int path, int range1, int range2)
{
	move(a, range1, path);//��aѭ������pathλ
	move(b, range1, path);//��bѭ������pathλ
	compose(a, b, combine, range1);//�ϲ�a��b
	transfer(final, combine, t, range2);//PC_2���û�
	return 0;
}

//ѭ�����ƺ���������Ϊn������aѭ������mλ��
void move(int a[], int n, int m)//�������Ϊת�����顢���鳤�ȡ�ѭ����λ��
{
	while (m--) {
		int t = a[1];
		for (int j = 2; j < n + 1; j++)
			a[j - 1] = a[j];//����
		a[n] = t;//�Ƴ�ȥ�Ĳ��������
	}
}

//�ϲ�����������������ϲ�Ϊһ�����飬��������������ȳ����Σ�
void compose(int former[], int latter[], int combine[], int range)//�������Ϊ��ǰ���顢�Ӻ����顢�ϲ����顢�ϲ���Χ
{
	for (int i = 1; i <= 2 * range; i++)
		(i <= range) ? (combine[i] = former[i]) : (combine[i] = latter[i - range]);
}

//���û�������������DES�㷨�������û����ܣ�
void transfer(int a[], int b[], int t[], int range)//�������Ϊ�����顢ԭ���顢�û��������鳤��
{
	for (int i = 1; i <= range; i++)
		a[i] = b[t[i - 1]];//��t[]�еĵ�i-1��Ԫ�ص�ֵ��Ӧ������ֵ����������ĵ�i��Ԫ��
}

//f�任��������������/���ܺ��ĺ�����
int f(int R[], int L[], int nR[], int nL[], int KR[], int ER[], int range)//�������ΪRn-1��Ln-1��Rn��Ln��Kn,�û���E�����鳤��
{
	f_transfer(KR, ER, R, 48);//f�任�õ�F����
	for (int i = 1; i <= range; i++) {
		nR[i] = L[i] ^ F[i];//XOR���㣬�����µ�Rn
		nL[i] = R[i];//�����������µ�Ln
	}
	return 0;
}

//f�任�Ӻ�����f�任���������ĺ��ģ�
int f_transfer(int KR[], int ER[], int R[], int range)//�������ΪKn,�û���E�����鳤��
{//�ֽ���
	int XOR[49] = { 0 };
	int X1[25] = { 0 };
	int X2[25] = { 0 };
	int X11[13] = { 0 };
	int X12[13] = { 0 };
	int X21[13] = { 0 };
	int X22[13] = { 0 };
//�ϲ���
	int P11[9] = { 0 };
	int P12[9] = { 0 };
	int P21[9] = { 0 };
	int P22[9] = { 0 };
	int P1[17] = { 0 };
	int P2[17] = { 0 };
	int PXOR[33] = { 0 };
//���������ֽ���
	int B1[7] = { 0 };
	int B2[7] = { 0 };
	int B3[7] = { 0 };
	int B4[7] = { 0 };
	int B5[7] = { 0 };
	int B6[7] = { 0 };
	int B7[7] = { 0 };
	int B8[7] = { 0 };
//���������ϲ���
	int SB1[10] = { 0 };
	int SB2[10] = { 0 };
	int SB3[10] = { 0 };
	int SB4[10] = { 0 };
	int SB5[10] = { 0 };
	int SB6[10] = { 0 };
	int SB7[10] = { 0 };
	int SB8[10] = { 0 };

	transfer(ER, R, E, 48);//�û���E�����û�

	for (int i = 1; i <= range; i++)//�����ɵ�ER��Kn����XOR����
		XOR[i] = KR[i] ^ ER[i];
//�ֽ�XORΪ8���֣�B1~B8
	decompose(X1, X2, XOR, 24);
	decompose(X11, X12, X1, 12);
	decompose(X21, X22, X2, 12);
	decompose(B1, B2, X11, 6);
	decompose(B3, B4, X12, 6);
	decompose(B5, B6, X21, 6);
	decompose(B7, B8, X22, 6);
//��ÿ���ֽ���S��ӳ�䣬B->SB
	S(S_BOX, B1, SB1, 0);
	S(S_BOX, B2, SB2, 1);
	S(S_BOX, B3, SB3, 2);
	S(S_BOX, B4, SB4, 3);
	S(S_BOX, B5, SB5, 4);
	S(S_BOX, B6, SB6, 5);
	S(S_BOX, B7, SB7, 6);
	S(S_BOX, B8, SB8, 7);
//��SB1~SB8�ϲ�ΪPXOR����
	compose(SB1, SB2, P11, 4);
	compose(SB3, SB4, P12, 4);
	compose(SB5, SB6, P21, 4);
	compose(SB7, SB8, P22, 4);
	compose(P11, P12, P1, 8);
	compose(P21, P22, P2, 8);
	compose(P1, P2, PXOR, 16);

	transfer(F, PXOR, P, 32);//�û���P�û����õ����պ���F

	return 0;
}

//�ֽ⺯������һ������ֽ�Ϊ�������飬��������������ȳ����Σ�
void decompose(int former[], int latter[], int combine[], int range)//�������Ϊ��ǰ���顢�Ӻ����顢�ϲ����顢�ϲ���Χ
{
	for (int i = 1; i <= 2 * range; i++)
		(i <= range) ? (former[i] = combine[i]) : (latter[i - range] = combine[i]);
}

//S��ӳ�亯����B����ĵ�һλ��ĩλ�������Ķ������������������м�λ�������Ķ���������������
void S(int s[8][4][16], int b[7], int sb[10], int i)//�������ΪS��B���顢ת�����SB���顢����
{
	int row, column, num = 0;
	row = 2 * b[1] + b[6];//�м��㣨BIN->DEC��
	column = 8 * b[2] + 4 * b[3] + 2 * b[4] + b[5];//�м��㣨BIN->DEC��
	num = s[i][row][column];
	de_to_bi(sb, num);//����ת����DEC->BIN��
}

//ʮ����ת�����ƺ����������۳�
void de_to_bi(int arr[10], int a)//�������Ϊ�洢���飬��ת����ʮ������
{
	int temp = a;
	int INDEX = 4;//ʮ�������4λ������
	if (a == 0)
		arr = { 0 };
	else
	{
		while (temp)
		{
			arr[INDEX] = (temp & 0x01);//��1��
			temp = temp >> 1;//����λ������2��
			INDEX--;
		}
	}
}

//��ӡ���麯����������int�����飬�Ҵ�1��ʼ��ӡ��
void print_array(int a[], int head, int length)//�������Ϊ���飬��ӡ����ţ���ӡ����
{
	for (int i = head; i <= length; i++)
		cout << a[i];
}

//��ӡ���麯����������char�����飬�Ҵ�0��ʼ��ӡ��
void print_ARRAY(char a[], int head, int nail)//�������Ϊ���飬��ӡ����ţ���ӡβ���
{
	for (int i = head; i < nail; i++)
		cout << a[i];
}

//�������麯����������int�����飬�Ҵ�1��ʼ���ƣ��¡�ԭ�����ַ��ͬ��
void copy_array(int fresh[], int old[], int size)//�������Ϊ�����顢ԭ���顢���鳤��
{
	for (int i = 1; i < size; i++)
		fresh[i] = old[i];
}

//�������麯����������char�����飬�Ҵ�0��ʼ���ƣ��¡�ԭ�����ַ��ͬ��
void copy_ARRAY(char fresh[], char old[], int size)//�������Ϊ�����顢ԭ���顢���鳤��
{
	for (int i = 0; i < size; i++)
		fresh[i] = old[i];
}

#endif