/*
 * * * * * * * * * * * * * * * * * * * * 移动互联网安全技术实验三* * * * * * * * * * * * * * * * * * * *
 *   WRITTEN BY: AMANE ICE                                                                            *
 *   DATE: 20/09/2018                                                                                  *
 *   REFERENCES: GUIDANCE BOOK OF MOBILE INTERNET SECURITY TECH.                                      *
 *   SCHOOL OF INFORMATION AND TELECOMMUNICATION ENGINNERING,                                          *
 *   BEIJING UNIVERSITY OF POSTS AND TELECOMMUNICATIONS                                               *
 * * * * * * * * * * * * * * * * * * * * * *  * RSA算法* * * * * * * * * * * * * * * * * * * * * * * * *

测试参考：（密钥）N = 2773， e = 63， d = 847，（原文）RSA encryption。
题目要求：
（1）a.把字符‘A’，转为 2 进制比特形式输出；b. 把二进制比特'01000010'转换为字符输出；

（2）a. 编写程序求出 1~65535 之间的全部素数；b. 大数在计算机上应该如何进行表示、如何进行运算；
c. 编写 RSA 密钥对生成程序。要求：a) 输入：密钥长度，最大 512bit； b) 输出：选取的质数 p、q，模数 n，公钥 e，私钥 d;
d.素性检测，找出可行的素数判定方法；

（3）a. 幂模运算，记录并比较程序的运行时间；
b.编写 RSA 加密程序。要求：a) 输入：公钥：（e，n）；原文字符串：例如，“RSA encryption”（从键盘输入）。b) 输出：加密的密文。
c. 编写 RSA 解密程序。要求：a) 输入：私钥：（d，n）；密文字符串：例如，RSA 加密程序的输出。b) 输出：解密的明文。

（4）编写 RSA 加密、解密系统。要求：
a) 读取文本文件“RSA.txt”作为原文，进行加密解密过程
b) 随机生成公钥、私钥，密钥长度为 128bit，将选取的质数 p、q，公钥、私钥保存在文本文件“RSA_key.txt”中
c) 将加密的密文保存在文本文件“RSA_encrypt.txt”中。
d) 对该文件进行解密，将解密的结果保存在“RSA_final”中，并将其与原文进行比较，判断是否成功进行解密

（5）RSA 算法的攻击。
*/

#include"test.h"
#include"func.h"
#include"prime.h"

int main() {
	while (1) {
		char c;
		printf_s("请输入您想要的操作。\n1.格式转换\n2.密钥对生成\n3.RSA加密\n4.RSA解密\n5.RSA系统\n6.退出\n");
		cin >> c;
		system("cls");//清屏
		switch (c) {
		case '1':
			cout << "请输入您要转化的字符！\n";
			cin >> charac;
			cout << charac << "对应的二进制数是";
			code_trans_cb(charac, 1); cout << "\n\n";//字符转二进制函数
			cout << "请输入您要转化的二进制数！\n";
			cin >> binary;
			cout << binary << "对应的字符是";
			code_trans_bc(); cout << "\n\n";//二进制转字符函数
			system("pause");
			break;
		case '2':
			int nail;
			cout << "从1到N所有的质数为（请输入N）\n";
			cin >> nail;
			cout << "从1到" << nail << "之间全部的质数有：";
			find_prime_number(initial, nail);cout << "\n\n";//寻找质数函数
			cout << "请输入密钥长度（比特）！（不大于1292byte）";
			cin >> keylength;
			generate_key_pair(keylength);//生成密钥（十进制，按byte为单位计算）函数
			system("pause");
			break;
		case '3':
			RSA_encode_test(keylength);//幂模运算函数
			RSA_encode(keylength, '1');//RSA加密函数
			break;
		case '4':
			RSA_decode('1');//RSA解密函数
			break;
		case '5':
			RSA();//RSA系统函数
			break;
		case'6':
			return 0;
		default:
			cout << "输入有误!请重新输入：\n";
			break;
		}
	}
}

//寻找质数函数
void find_prime_number(int a[], int nail)//传入参数为预备数组、N（1~N的质数）
{
	int count = 0;
	for (int i = 2; i <= nail; i++)
		if ((i == 2) || (i == 3) || (i % 6 == 1) || ((i % 6 == 5)))//排除掉6N,6N+2,6N+3,6N+4
			a[i] = 1;//标记为1的保留
	for (int i = 2;i <= nail / 2;i++)//素数筛法
		if (a[i] == 1)
		{
			for (int j = i + i;j <= nail;j = j + i)//如果有它的倍数，标记改为0
				a[j] = 0;
		}
	for (int i = 2;i <= nail;i++)
		if (a[i] == 1)
		{
			printf_s("%d ,", i);//打印标记仍为1的数即可
			count++;
		}
	printf_s("\n");
	cout <<"从1到"<<nail<<"的素数总共有"<<count<<"个。";
}

//密钥生成函数（此处传入参数为byte。其中，512bit对应154位十进制，即1232byte
void generate_key_pair(const unsigned keylength)//传入参数为密钥长度（byte）
{
	de_length = keylength / 16;//去byte化后取中间值
	p_length = pp_length = de_length - 2;
	q_length = qq_length = de_length + 2;//保证p、q差异，有10^4倍
	n_length = phy_length = p_length + q_length;//n为p、q之积，phy为n的欧拉函数
	pro_length = phy_length + e_length;//

	create_prime_p(p, p_length, 15);//创建质数p
	create_prime_q(q, q_length, 15);//创建质数q

	cout << "得到的质数p，q分别为：";cout << "\n\n";
	cout << "p：";
	print_array(p, p_length);cout << "\n\n";//打印质数p
	cout << "q：";
	print_array(q, q_length);cout << "\n\n";//打印质数q
	cout << "\n";


	copy_array(int_cp, p, 100);//保留p并复制，用于下一步操作
	copy_array(int_cq, q, 100);//保留q并复制，用于下一步操作

	cout << "得到的模数（n）为：";cout << "\n\n";
	cout << "n：";
	HyperMul_pq(p, q, 1);cout << '\n';//大数组（p、q）相乘，值返回给n
	cout << "\n";
	copy_array(int_cn, int_n, 100);//保留n并复制，用于下一步操作

	cout << "p-1，q-1分别为：";cout << "\n\n";
	cout << "p-1：";
	HyperPureSub_pq(int_cp, One, 1);cout << "\n\n";//大数组减运算，p-1
	cout << "q-1：";
	HyperPureSub_pq(int_cq, One, 2);cout << "\n\n";//大数组减运算，q-1
	cout << "\n";
	cout << "得到的欧拉函数PHY(n)的值为，式中 PHY(n) = (p-1)(q-1)：";cout << "\n\n";
	cout << "PHY(n)：";
	HyperMul_pq(int_pp, int_qq, 2);//大数组乘运算，p-1与q-1相乘
	cout << "\n";

	cout << "选取的公钥e为：";cout << '\n';
	cout << "e：149873";cout << '\n';//为运算方便，选定公钥e
	int E[100] = { 3,7,8,9,4,1 };
	while (1)//欧几里得算法求模反元素，即求不定方程ax+by=1
	{
		HyperMul_de(int_phy, sum);//初始化sum=1，每次加1，循环计算欧拉函数与sum乘积，值返回给pro

		HyperAdd_de(pro, One, 1);//pro加1
		copy_array(cpro, pro, 199);//保留pro并复制，用于下一步操作
		copy_array(cE, E, 100);//保留E并复制，用于下一步操作
		HyperDiv_de(cpro, cE);//
		copy_array(cpro, pro, 199);//保留E并复制，用于下一步操作
		int detect_re = detect_zero(remain, 199);//零检测
		if (detect_re == 199)//如果有1个1（即模为1）
			break;//表示计算出了需要的结果
		HyperAdd_de(sum, One, 2);//否则大数加法，每次加1
	}
	cout << "产生的私钥d为：";cout << "\n\n";
	cout << "d：";
	print_array(quotient, 199);cout << "\n\n";//打印d（即为商）
	cout << "下面验证私钥产生的正确性：" << "\n\n";
	HyperMul_de(quotient, E);
	cout << "d，e相乘之积为：";print_array(pro, 199);cout << "\n\n";
	HyperDiv_de(pro, int_phy);
	cout << "与PHY(n)相除，余数为：";print_array(remain_, 199);cout << "\n\n";
	cout << "运算结果正确！" << "\n\n";
}

//幂模运算函数
void RSA_encode_test(int keylength)//传入参数为数组长度
{
	int memo_length;
	srand((unsigned)time(NULL)); //播种子
	int loop = 3;
	while (loop--)
	{
		copy_array(_ce, clear, 799);copy_array(Memo_x, clear, 799);
		copy_array(Memo_e, clear, 799);copy_array(Memo_n, clear, 799);
		cout << "请输入幂模运算中，运算数的长度（不大于696byte）！\n";
		cin >> memo_length;
		int length = memo_length / 8;
		for (int i = 0; i < length; i++)//按位随机产生幂模运算的基数（X）、指数（E）、模数（N）
		{
			Memo_x[i] = rand() % 9 + 1;
			Memo_e[i] = rand() % 9 + 1;
			Memo_n[i] = rand() % 9 + 1;
		}
		cout << "产生的随机数x，e，n依次是：" << '\n';
		cout << "x:";print_array(Memo_x, length);cout << '\n';
		cout << "e:";print_array(Memo_e, length);cout << '\n';
		cout << "n:";print_array(Memo_n, length);cout << '\n';
		copy_array(cMemo_x, Memo_x, 299);
		copy_array(cMemo_e, Memo_e, 299);
		copy_array(cMemo_n, Memo_n, 299);

		clock_t begin, end;//时间记录
		double cost;
		begin = clock();//开始

		HyperMemo(cMemo_x, cMemo_e, cMemo_n, Memo_n, 0);//幂模运算函数

		end = clock();//结束
		cost = (double)(end - begin) / CLOCKS_PER_SEC;//时间计算
		cout << '\n';
		printf_s("算法花费时间为: %lf sec\r\n", cost);
	}
}

//RSA加密函数
void RSA_encode(int keylength, char flag)//传入参数为数组长度，每次14个
{
	memset(ttemp_plain, 0, sizeof(ttemp_plain) / sizeof(char));
	char txt_ar[100];
	char TXT_e[800] = { 0 };
	char TXT_n[800] = { 0 };

	int txt_e[800];
	int txt_n[800];
	if (flag == '1')
	{
		copy_array(txt_e, clear, 799);
		copy_array(txt_n, clear, 799);
		txt_arr = "", sst.str(""), sst.clear();
		cout << "请输入原文字符串：" << "\n\n";
		cin.getline(txt_ar, 100);
		cin.getline(txt_ar, 100);
		cout << "请输入私钥对（e，n）：" << "\n\n";
		cin >> TXT_e >> TXT_n;
		int tdlength = strlen(TXT_e);
		for (int i = 0; i < tdlength; i++)
			txt_e[i] = TXT_e[tdlength - 1 - i] - '0';
		int tnlength = strlen(TXT_n);
		for (int i = 0; i < tnlength; i++)
			txt_n[i] = TXT_n[tnlength - 1 - i] - '0';
	}

	if (flag == '2')
	{
		copy_ARRAY(txt_ar, ttemp, 15);
		int txtt_e[800] = { 3,6 };
		int txtt_n[800] = { 3,7,7,2 };
		copy_array(txt_e, txtt_e, 799);
		copy_array(txt_n, txtt_n, 799);
		//输入仅有e,n,ar
	}

	int txtlength = strlen(txt_ar);
	int itxt[800] = { 0 };
	int temp[3] = { 0 };
	char st[8] = { 0 };
	for (int i = 0; i < txtlength;i++)
	{
		st[0] = txt_ar[i];
		code_trans_cb(st, 2);
	}
	sst >> txt_arr;
	cout << "字符串对应的二进制数为：" << txt_arr << "\n\n";
	//	string txt_arr = "010 100 100 101 001 101 000 001 001 000 000 110 010 101 101 110 011 000 110 111 001 001 111 001 011 100 000 111 
	//010 001 101 001 011 011 110 110 111 0(00)";
	int arrlength = txt_arr.length(), resilength = arrlength % 3, quolength = arrlength / 3;//113,2,37 112,1,37
	if ((resilength == 1))//8进制算法下，多一位时补位，如0补位000
	{
		temp[0] = txt_arr[(quolength) * 3] - 48, temp[1] = temp[2] = 0;
		txt_arr.erase(txt_arr.end() - 1);
		itxt[quolength + 1] = 4 * temp[0] + 2 * temp[1] + 1 * temp[2];
	}

	if (resilength == 2)//8进制算法下，多两位时补位，如10补位100
	{
		temp[0] = txt_arr[(quolength) * 3] - 48, temp[1] = txt_arr[(quolength) * 3 + 1] - 48, temp[2] = 0;
		txt_arr.erase(txt_arr.end() - 2);
		itxt[quolength + 1] = 4 * temp[0] + 2 * temp[1] + 1 * temp[2];
	}
	for (int i = 0;i < arrlength + 2;i++)
	{
		itxt[i] = 4 * (txt_arr[0] - 48) + 2 * (txt_arr[1] - 48) + (txt_arr[2] - 48);//每位取8进制数
		txt_arr = txt_arr.substr(3);//取完后截短前3位
		if (txt_arr == "")
			break;
	}
	reverse_array(itxt, htxt, quolength + 1, 3);
	cout << "原文字符串转化的数字数组(n)为：";print_ARRAY(htxt, quolength + 1); cout << "\n\n";

	copy_array(htxt_e, txt_e, 799);
	cout << "公钥转化的数字数组(e)为：";print_array(htxt_e, 799); cout << "\n\n";
	copy_array(htxt_n, txt_n, 799);
	cout << "密钥转化的数字数组(N)为：";print_array(htxt_n, 799); cout << "\n\n";
	for (int i = 0;i < detect_array(htxt, 799);i++)
	{
		int a[800] = { 0 };
		if (itxt[i] != 0)
		{
			a[0] = itxt[i];
			cout << "计算元素为：";print_array(a, 799); cout << "\n\n";
			copy_array(htxt_c, a, 799);
			copy_array(htxt_e, txt_e, 799);
			HyperMemo(htxt_c, htxt_e, htxt_n, txt_n, 1);//幂模运算
		}
		else
		{
			a[0] = 0;
			cout << "计算元素为：0" << "\n\n";
			copy_array(htxt_c, a, 799);
			copy_array(htxt_e, txt_e, 799);
			HyperMemo(htxt_c, htxt_e, htxt_n, txt_n, 1);//幂模运算
		}
	}
	cout << "经整理得到的密文为：";
	print_ARRAY(RSAe, 4 * (quolength + 1));cout << "\n\n";
	cout << "经整理得到的密文（二进制）为：";
	HyperPrint(RSAee, 999); cout << "\n\n";//二进制输出

	for (int i = 4 * (quolength + 1) - 2;i >= 0;i -= 2)
	{
		cout << ((10 * RSAe[i + 1] + RSAe[i]) + 33) << " ";//ASCII码（加33）输出
	}
	cout << '\n';
	cout << "经整理得到的密文（字符）为：";
	int j = 0;
	for (int i = 4 * (quolength + 1);i >= 0;i -= 2)
	{
		cout << (char)(((10 * RSAe[i + 1] + RSAe[i])) + 33);//字符串（加33）输出，所有元素均落在表示符号内
		if (flag == '2')
		{ 
			ttemp_plain[j] = (char)(((10 * RSAe[i + 1] + RSAe[i])) + 33);
			j++;
		}
	}
	cout << "\n\n";
}

//RSA解密函数，顺序与加密相反
void RSA_decode(char flag)
{
//	memset(ttemp_cipher, 0, sizeof(ttemp_cipher) / sizeof(char));
	char txt_dr[100];
	char TXT_d[800] = { 0 };
	char TXT_n[800] = { 0 };
	int txt_d[800];
	int tdt_n[800];
	if (flag == '1')
	{
		copy_array(txt_d, clear, 799);
		copy_array(tdt_n, clear, 799);
		cout << "请输入密文字符串：" << "\n\n";
		cin.getline(txt_dr, 100);
		cin.getline(txt_dr, 100);
		cout << "请输入私钥对（d，n）：" << "\n\n";
		cin >> TXT_d >> TXT_n;
		int tdlength = strlen(TXT_d);
		for (int i = 0; i < tdlength; i++)
			txt_d[i] = TXT_d[tdlength - 1 - i] - '0';
		int tnlength = strlen(TXT_n);
		for (int i = 0; i < tnlength; i++)
			tdt_n[i] = TXT_n[tnlength - 1 - i] - '0';
	}

	if (flag == '2')
	{
		copy_ARRAY(txt_dr, ttemp_cipher, 80);
		int txtt_d[800] = { 7,4,8 };
		int txtt_n[800] = { 3,7,7,2 };
		copy_array(txt_d, txtt_d, 799);
		copy_array(tdt_n, txtt_n, 799);
		//输入仅有e,n,ar
	}
	int tdtlength = strlen(txt_dr);
	int dN = 0;
	for (int i = 0;i < tdtlength;i++)
	{
		int temp = int(txt_dr[i] - 33);
		itdt[i + 1 + dN] = temp % 10, temp /= 10;
		itdt[i + dN] = temp % 10;
		dN += 1;
	}
	reverse_array(itdt, htdt, 2 * tdtlength, 3);
	cout << "密文字符串转化的数字数组(n)为：";print_ARRAY(htdt, 2 * tdtlength - 2); cout << "\n\n";//逆序输出
	copy_array(htdt_e, txt_d, 799);
	cout << "私钥转化的数字数组(d)为：";print_array(htdt_e, 799); cout << "\n\n";
	copy_array(htdt_n, tdt_n, 799);
	cout << "密钥转化的数字数组(N)为：";print_array(htdt_n, 799); cout << "\n\n";
	int A[800] = { 0 };
	for (int i = 0;i < 2 * tdtlength - 2;i += 4)//顺序取出4位进行运算
	{
		A[0] = htdt[0 + i];
		A[1] = htdt[1 + i];
		A[2] = htdt[2 + i];
		A[3] = htdt[3 + i];
		cout << "计算元素为：";print_array(A, 799); cout << "\n\n";
		copy_array(htdt_c, A, 799);
		copy_array(htdt_e, txt_d, 799);
		HyperMemo(htdt_c, htdt_e, htdt_n, tdt_n, 2);//幂模运算
	}
	cout << "经整理得到的明文为：";
	print_array(RSAd, 999);cout << "\n\n";
	cout << "经整理得到的明文（二进制）为：";
	HyperPrint(RSAdd, 999); cout << "\n\n";
	for (int i = 0; i < strlen(RSAdd) - 1;i++)
		ddRSA[i] = RSAdd[strlen(RSAdd) - 1 - i];//逆序
	cout << "\n\n" << "经整理得到的明文（二进制）为：";//每8位输出一次
	for (int i = 0; i < strlen(RSAdd) - 2;i += 8)

		cout << ddRSA[i] << ddRSA[i + 1] << ddRSA[i + 2] << ddRSA[i + 3] << ddRSA[i + 4] << ddRSA[i + 5] << ddRSA[i + 6] << ddRSA[i + 7] << "\n";

	cout << "\n\n" << "经整理得到的密文（数字）为：";//二进制转十进制ASCII码
	for (int i = 0;i < strlen(RSAdd) - 2;i += 8)
	{
		cout << ((64 * (ddRSA[i + 1] - 48) + 32 * (ddRSA[i + 2] - 48) + 16 * (ddRSA[i + 3] - 48) + 8 * (ddRSA[i + 4] - 48) +
			4 * (ddRSA[i + 5] - 48) + 2 * (ddRSA[i + 6] - 48) + (ddRSA[i + 7] - 48))) << " ";
	}
	cout << "\n\n" << "经整理得到的密文（字符）为：";//二进制转字符串
	int k = 0;
	for (int i = 0;i < strlen(RSAdd) - 2;i += 8)
	{
		cout << (char)((64 * (ddRSA[i + 1] - 48) + 32 * (ddRSA[i + 2] - 48) + 16 * (ddRSA[i + 3] - 48) + 8 * (ddRSA[i + 4] - 48) +
			4 * (ddRSA[i + 5] - 48) + 2 * (ddRSA[i + 6] - 48) + (ddRSA[i + 7] - 48)));
		if(flag =='2')
		{ 
			tempt_final[k] = (char)((64 * (ddRSA[i + 1] - 48) + 32 * (ddRSA[i + 2] - 48) + 16 * (ddRSA[i + 3] - 48) + 8 * (ddRSA[i + 4] - 48) +
				4 * (ddRSA[i + 5] - 48) + 2 * (ddRSA[i + 6] - 48) + (ddRSA[i + 7] - 48)));
			k++;
		}
	}
	cout << "\n\n";
}

/*幂模运算函数，基于Montgomery（蒙哥马利）算法
蒙哥马利模乘乘模运算公式为C=A*B*r^(-k) % N。
设R = H*k %N，R'=H*(-k) %N，E=SIGMA(E*2*i)：
记A'=A*R %N，X=A'。那么从n-1到0逆序循环，每次取X=X*X*R' %N。
如果E=1，X=X*A'*R' %N，则返回X=X*1*R' %N*/
void HyperMemo(int copy_x[], int copy_e[], int copy_n[], int n[], int flag)//传入参数为基数、指数、模数、原模数、标志
{
	int mask[2000] = { 1 };
	reverse_array(copy_e, _cee, detect_array(copy_e, 299), 2);
//	cout << "得到的逆序数组为";print_array(copy_e, 299);cout << '\n';//将基数逆序
	HyperToBinary(copy_e, _ce);//求指数的二进制数
	copy_array(_cce, _ce, 799);
	int nMaxBit = detect_array(_ce, 799);
	int _nMaxBit = nMaxBit;
//	cout << "最高位数为：" << nMaxBit;cout << '\n';//求得二进制后的指数的最高位
	int CPY = 0;
	for (int N = nMaxBit; N >= 0;--N)//从n-1到0循环
	{
		cTwo[N] = 1;
//		cout << "得到的（N）数组为：";print_array(cTwo, 299);cout << '\n';//每次确定数组剩余长度
		HyperMul_memo(mask, mask);//A=A*A
		HyperDiv_memo(mask, copy_n);//逐位判断
		copy_array(copy_n, n, 799);
//		cout << "求模结果（I）为：";print_array(mask, 1000);cout << '\n';
		if (Hyper_binary_YU())//与运算判断是否需要对本位再次计算
		{
			HyperMul_memo(mask, copy_x);
			HyperDiv_memo(mask, copy_n);
			copy_array(copy_n, n, 299);//重新求模
//			cout << "求模结果（II）为：";print_array(mask, 1000);cout << '\n';
		}
		copy_array(cTwo, clear, 299);
	}
//	cout << "幂模运算的结果为：（输出为余数）";
	if ((mask[0] == 0) && (detect_array(mask, 199) == -1))
		cout << "0";
	else
		print_array(mask, 1000);
	if (flag == 1)//标志为1，即RSA加密过程时
	{
		for (int i = 0; i < 4;i++)//每4位存取一次
		{
			int temp = mask[i];
			RSAe[RSAe_N] = mask[i];//逆序
			RSAee[RSAee_N + 3] = temp % 2 + '0', temp /= 2;
			RSAee[RSAee_N + 2] = temp % 2 + '0', temp /= 2;
			RSAee[RSAee_N + 1] = temp % 2 + '0', temp /= 2;
			RSAee[RSAee_N + 0] = temp % 2 + '0';
			RSAe_N += 1;
			RSAee_N += 4;
		}
	}
	if (flag == 2)//标志为2，即RSA解密过程时
	{
		int temp = mask[0];
		RSAd[RSAd_N] = temp;//顺序
		RSAdd[RSAdd_N + 0] = temp % 2 + '0', temp /= 2;
		RSAdd[RSAdd_N + 1] = temp % 2 + '0', temp /= 2;
		RSAdd[RSAdd_N + 2] = temp % 2 + '0';
		RSAd_N += 1;
		RSAdd_N += 3;
	}
	cout << '\n';
}

void RSA()//每次加密14个
{
	cout << "注：该功能目前实现了特定密钥的RSA读写，定密钥为公钥（2773,63），私钥（2773,847）。输入任意字符以开始读写。\n";
	cin >> blank;
	int temp_N = 0;//增量
	fstream file1;//设文件为file1
	file1.open("D://RSA.txt", ios::binary | ios::in);
	file1.read((char*)&temp, sizeof(temp));
	file1.close();

	int seri = strlen(temp) / 14;//确定执行循环次数
	(strlen(temp) % 14 == 0) ? (seri += 0) : (seri += 1);

	//加密
	for (int i = 0; i < seri; i++)
	{
		for (int j = 0; j < 14; j++)
			ttemp[j] = temp[j + 14 * temp_N];//每次取14位到临时数组ttemp中
		RSA_encode(keylength, '2');//执行RSA加密
		for (int k = 0; k < 115;k++)
			tempt_plain[k + 114 * temp_N] = ttemp_plain[k];//将得到的结果转存到ttemp_plain中，每次64位，第0位不要
		temp_N++;
	}
	copy_ARRAY(temp_plain, tempt_plain, 14999);//将临时数组储存的二进制数转到temp_plain准备储存

	file1.open("D://RSA_Encrypt.txt", ios::binary | ios::out);
	file1.write((char*)&temp_plain, sizeof(temp_plain));
	file1.close();

	file1.open("D://RSA_Encrypt.txt", ios::binary | ios::in);
	file1.read((char*)&temp_cipher, sizeof(temp_cipher));
	file1.close();
	temp_N = 0;//初始化

	//解密
	for (int i = 0; i < seri; i++)
	{
		for (int j = 0; j < 78; j++)
			ttemp_cipher[j] = temp_cipher[j + 78 * temp_N];//每次从数组取76位给real_z，第0位不要
		RSA_decode('2');//执行RSA解密
		for (int k = 0; k < 15;k++)
			ttemp_final[k + 14 * temp_N] = tempt_final[k];//将得到的结果转存到ttemp_final中，每次8位
		temp_N++;
	}
	copy_ARRAY(temp_final, ttemp_final, 4999);//将临时数组储存的字符转到temp_final准备储存

	file1.open("D://RSA_Decrypt.txt", ios::binary | ios::out);
	file1.write((char*)&temp_final, sizeof(temp_final));
	file1.close();
	cout << "读写成功！" << "\n\n";
}