/*
 * * * * * * * * * * * * * * * * * * * * �ƶ���������ȫ����ʵ����* * * * * * * * * * * * * * * * * * * *
 *   WRITTEN BY: AMANE ICE                                                                            *
 *   DATE: 20/09/2018                                                                                  *
 *   REFERENCES: GUIDANCE BOOK OF MOBILE INTERNET SECURITY TECH.                                      *
 *   SCHOOL OF INFORMATION AND TELECOMMUNICATION ENGINNERING,                                          *
 *   BEIJING UNIVERSITY OF POSTS AND TELECOMMUNICATIONS                                               *
 * * * * * * * * * * * * * * * * * * * * * *  * RSA�㷨* * * * * * * * * * * * * * * * * * * * * * * * *

���Բο�������Կ��N = 2773�� e = 63�� d = 847����ԭ�ģ�RSA encryption��
��ĿҪ��
��1��a.���ַ���A����תΪ 2 ���Ʊ�����ʽ�����b. �Ѷ����Ʊ���'01000010'ת��Ϊ�ַ������

��2��a. ��д������� 1~65535 ֮���ȫ��������b. �����ڼ������Ӧ����ν��б�ʾ����ν������㣻
c. ��д RSA ��Կ�����ɳ���Ҫ��a) ���룺��Կ���ȣ���� 512bit�� b) �����ѡȡ������ p��q��ģ�� n����Կ e��˽Կ d;
d.���Լ�⣬�ҳ����е������ж�������

��3��a. ��ģ���㣬��¼���Ƚϳ��������ʱ�䣻
b.��д RSA ���ܳ���Ҫ��a) ���룺��Կ����e��n����ԭ���ַ��������磬��RSA encryption�����Ӽ������룩��b) ��������ܵ����ġ�
c. ��д RSA ���ܳ���Ҫ��a) ���룺˽Կ����d��n���������ַ��������磬RSA ���ܳ���������b) ��������ܵ����ġ�

��4����д RSA ���ܡ�����ϵͳ��Ҫ��
a) ��ȡ�ı��ļ���RSA.txt����Ϊԭ�ģ����м��ܽ��ܹ���
b) ������ɹ�Կ��˽Կ����Կ����Ϊ 128bit����ѡȡ������ p��q����Կ��˽Կ�������ı��ļ���RSA_key.txt����
c) �����ܵ����ı������ı��ļ���RSA_encrypt.txt���С�
d) �Ը��ļ����н��ܣ������ܵĽ�������ڡ�RSA_final���У���������ԭ�Ľ��бȽϣ��ж��Ƿ�ɹ����н���

��5��RSA �㷨�Ĺ�����
*/

#include"test.h"
#include"func.h"
#include"prime.h"

int main() {
	while (1) {
		char c;
		printf_s("����������Ҫ�Ĳ�����\n1.��ʽת��\n2.��Կ������\n3.RSA����\n4.RSA����\n5.RSAϵͳ\n6.�˳�\n");
		cin >> c;
		system("cls");//����
		switch (c) {
		case '1':
			cout << "��������Ҫת�����ַ���\n";
			cin >> charac;
			cout << charac << "��Ӧ�Ķ���������";
			code_trans_cb(charac, 1); cout << "\n\n";//�ַ�ת�����ƺ���
			cout << "��������Ҫת���Ķ���������\n";
			cin >> binary;
			cout << binary << "��Ӧ���ַ���";
			code_trans_bc(); cout << "\n\n";//������ת�ַ�����
			system("pause");
			break;
		case '2':
			int nail;
			cout << "��1��N���е�����Ϊ��������N��\n";
			cin >> nail;
			cout << "��1��" << nail << "֮��ȫ���������У�";
			find_prime_number(initial, nail);cout << "\n\n";//Ѱ����������
			cout << "��������Կ���ȣ����أ�����������1292byte��";
			cin >> keylength;
			generate_key_pair(keylength);//������Կ��ʮ���ƣ���byteΪ��λ���㣩����
			system("pause");
			break;
		case '3':
			RSA_encode_test(keylength);//��ģ���㺯��
			RSA_encode(keylength, '1');//RSA���ܺ���
			break;
		case '4':
			RSA_decode('1');//RSA���ܺ���
			break;
		case '5':
			RSA();//RSAϵͳ����
			break;
		case'6':
			return 0;
		default:
			cout << "��������!���������룺\n";
			break;
		}
	}
}

//Ѱ����������
void find_prime_number(int a[], int nail)//�������ΪԤ�����顢N��1~N��������
{
	int count = 0;
	for (int i = 2; i <= nail; i++)
		if ((i == 2) || (i == 3) || (i % 6 == 1) || ((i % 6 == 5)))//�ų���6N,6N+2,6N+3,6N+4
			a[i] = 1;//���Ϊ1�ı���
	for (int i = 2;i <= nail / 2;i++)//����ɸ��
		if (a[i] == 1)
		{
			for (int j = i + i;j <= nail;j = j + i)//��������ı�������Ǹ�Ϊ0
				a[j] = 0;
		}
	for (int i = 2;i <= nail;i++)
		if (a[i] == 1)
		{
			printf_s("%d ,", i);//��ӡ�����Ϊ1��������
			count++;
		}
	printf_s("\n");
	cout <<"��1��"<<nail<<"�������ܹ���"<<count<<"����";
}

//��Կ���ɺ������˴��������Ϊbyte�����У�512bit��Ӧ154λʮ���ƣ���1232byte
void generate_key_pair(const unsigned keylength)//�������Ϊ��Կ���ȣ�byte��
{
	de_length = keylength / 16;//ȥbyte����ȡ�м�ֵ
	p_length = pp_length = de_length - 2;
	q_length = qq_length = de_length + 2;//��֤p��q���죬��10^4��
	n_length = phy_length = p_length + q_length;//nΪp��q֮����phyΪn��ŷ������
	pro_length = phy_length + e_length;//

	create_prime_p(p, p_length, 15);//��������p
	create_prime_q(q, q_length, 15);//��������q

	cout << "�õ�������p��q�ֱ�Ϊ��";cout << "\n\n";
	cout << "p��";
	print_array(p, p_length);cout << "\n\n";//��ӡ����p
	cout << "q��";
	print_array(q, q_length);cout << "\n\n";//��ӡ����q
	cout << "\n";


	copy_array(int_cp, p, 100);//����p�����ƣ�������һ������
	copy_array(int_cq, q, 100);//����q�����ƣ�������һ������

	cout << "�õ���ģ����n��Ϊ��";cout << "\n\n";
	cout << "n��";
	HyperMul_pq(p, q, 1);cout << '\n';//�����飨p��q����ˣ�ֵ���ظ�n
	cout << "\n";
	copy_array(int_cn, int_n, 100);//����n�����ƣ�������һ������

	cout << "p-1��q-1�ֱ�Ϊ��";cout << "\n\n";
	cout << "p-1��";
	HyperPureSub_pq(int_cp, One, 1);cout << "\n\n";//����������㣬p-1
	cout << "q-1��";
	HyperPureSub_pq(int_cq, One, 2);cout << "\n\n";//����������㣬q-1
	cout << "\n";
	cout << "�õ���ŷ������PHY(n)��ֵΪ��ʽ�� PHY(n) = (p-1)(q-1)��";cout << "\n\n";
	cout << "PHY(n)��";
	HyperMul_pq(int_pp, int_qq, 2);//����������㣬p-1��q-1���
	cout << "\n";

	cout << "ѡȡ�Ĺ�ԿeΪ��";cout << '\n';
	cout << "e��149873";cout << '\n';//Ϊ���㷽�㣬ѡ����Կe
	int E[100] = { 3,7,8,9,4,1 };
	while (1)//ŷ������㷨��ģ��Ԫ�أ����󲻶�����ax+by=1
	{
		HyperMul_de(int_phy, sum);//��ʼ��sum=1��ÿ�μ�1��ѭ������ŷ��������sum�˻���ֵ���ظ�pro

		HyperAdd_de(pro, One, 1);//pro��1
		copy_array(cpro, pro, 199);//����pro�����ƣ�������һ������
		copy_array(cE, E, 100);//����E�����ƣ�������һ������
		HyperDiv_de(cpro, cE);//
		copy_array(cpro, pro, 199);//����E�����ƣ�������һ������
		int detect_re = detect_zero(remain, 199);//����
		if (detect_re == 199)//�����1��1����ģΪ1��
			break;//��ʾ���������Ҫ�Ľ��
		HyperAdd_de(sum, One, 2);//��������ӷ���ÿ�μ�1
	}
	cout << "������˽ԿdΪ��";cout << "\n\n";
	cout << "d��";
	print_array(quotient, 199);cout << "\n\n";//��ӡd����Ϊ�̣�
	cout << "������֤˽Կ��������ȷ�ԣ�" << "\n\n";
	HyperMul_de(quotient, E);
	cout << "d��e���֮��Ϊ��";print_array(pro, 199);cout << "\n\n";
	HyperDiv_de(pro, int_phy);
	cout << "��PHY(n)���������Ϊ��";print_array(remain_, 199);cout << "\n\n";
	cout << "��������ȷ��" << "\n\n";
}

//��ģ���㺯��
void RSA_encode_test(int keylength)//�������Ϊ���鳤��
{
	int memo_length;
	srand((unsigned)time(NULL)); //������
	int loop = 3;
	while (loop--)
	{
		copy_array(_ce, clear, 799);copy_array(Memo_x, clear, 799);
		copy_array(Memo_e, clear, 799);copy_array(Memo_n, clear, 799);
		cout << "��������ģ�����У��������ĳ��ȣ�������696byte����\n";
		cin >> memo_length;
		int length = memo_length / 8;
		for (int i = 0; i < length; i++)//��λ���������ģ����Ļ�����X����ָ����E����ģ����N��
		{
			Memo_x[i] = rand() % 9 + 1;
			Memo_e[i] = rand() % 9 + 1;
			Memo_n[i] = rand() % 9 + 1;
		}
		cout << "�����������x��e��n�����ǣ�" << '\n';
		cout << "x:";print_array(Memo_x, length);cout << '\n';
		cout << "e:";print_array(Memo_e, length);cout << '\n';
		cout << "n:";print_array(Memo_n, length);cout << '\n';
		copy_array(cMemo_x, Memo_x, 299);
		copy_array(cMemo_e, Memo_e, 299);
		copy_array(cMemo_n, Memo_n, 299);

		clock_t begin, end;//ʱ���¼
		double cost;
		begin = clock();//��ʼ

		HyperMemo(cMemo_x, cMemo_e, cMemo_n, Memo_n, 0);//��ģ���㺯��

		end = clock();//����
		cost = (double)(end - begin) / CLOCKS_PER_SEC;//ʱ�����
		cout << '\n';
		printf_s("�㷨����ʱ��Ϊ: %lf sec\r\n", cost);
	}
}

//RSA���ܺ���
void RSA_encode(int keylength, char flag)//�������Ϊ���鳤�ȣ�ÿ��14��
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
		cout << "������ԭ���ַ�����" << "\n\n";
		cin.getline(txt_ar, 100);
		cin.getline(txt_ar, 100);
		cout << "������˽Կ�ԣ�e��n����" << "\n\n";
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
		//�������e,n,ar
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
	cout << "�ַ�����Ӧ�Ķ�������Ϊ��" << txt_arr << "\n\n";
	//	string txt_arr = "010 100 100 101 001 101 000 001 001 000 000 110 010 101 101 110 011 000 110 111 001 001 111 001 011 100 000 111 
	//010 001 101 001 011 011 110 110 111 0(00)";
	int arrlength = txt_arr.length(), resilength = arrlength % 3, quolength = arrlength / 3;//113,2,37 112,1,37
	if ((resilength == 1))//8�����㷨�£���һλʱ��λ����0��λ000
	{
		temp[0] = txt_arr[(quolength) * 3] - 48, temp[1] = temp[2] = 0;
		txt_arr.erase(txt_arr.end() - 1);
		itxt[quolength + 1] = 4 * temp[0] + 2 * temp[1] + 1 * temp[2];
	}

	if (resilength == 2)//8�����㷨�£�����λʱ��λ����10��λ100
	{
		temp[0] = txt_arr[(quolength) * 3] - 48, temp[1] = txt_arr[(quolength) * 3 + 1] - 48, temp[2] = 0;
		txt_arr.erase(txt_arr.end() - 2);
		itxt[quolength + 1] = 4 * temp[0] + 2 * temp[1] + 1 * temp[2];
	}
	for (int i = 0;i < arrlength + 2;i++)
	{
		itxt[i] = 4 * (txt_arr[0] - 48) + 2 * (txt_arr[1] - 48) + (txt_arr[2] - 48);//ÿλȡ8������
		txt_arr = txt_arr.substr(3);//ȡ���ض�ǰ3λ
		if (txt_arr == "")
			break;
	}
	reverse_array(itxt, htxt, quolength + 1, 3);
	cout << "ԭ���ַ���ת������������(n)Ϊ��";print_ARRAY(htxt, quolength + 1); cout << "\n\n";

	copy_array(htxt_e, txt_e, 799);
	cout << "��Կת������������(e)Ϊ��";print_array(htxt_e, 799); cout << "\n\n";
	copy_array(htxt_n, txt_n, 799);
	cout << "��Կת������������(N)Ϊ��";print_array(htxt_n, 799); cout << "\n\n";
	for (int i = 0;i < detect_array(htxt, 799);i++)
	{
		int a[800] = { 0 };
		if (itxt[i] != 0)
		{
			a[0] = itxt[i];
			cout << "����Ԫ��Ϊ��";print_array(a, 799); cout << "\n\n";
			copy_array(htxt_c, a, 799);
			copy_array(htxt_e, txt_e, 799);
			HyperMemo(htxt_c, htxt_e, htxt_n, txt_n, 1);//��ģ����
		}
		else
		{
			a[0] = 0;
			cout << "����Ԫ��Ϊ��0" << "\n\n";
			copy_array(htxt_c, a, 799);
			copy_array(htxt_e, txt_e, 799);
			HyperMemo(htxt_c, htxt_e, htxt_n, txt_n, 1);//��ģ����
		}
	}
	cout << "������õ�������Ϊ��";
	print_ARRAY(RSAe, 4 * (quolength + 1));cout << "\n\n";
	cout << "������õ������ģ������ƣ�Ϊ��";
	HyperPrint(RSAee, 999); cout << "\n\n";//���������

	for (int i = 4 * (quolength + 1) - 2;i >= 0;i -= 2)
	{
		cout << ((10 * RSAe[i + 1] + RSAe[i]) + 33) << " ";//ASCII�루��33�����
	}
	cout << '\n';
	cout << "������õ������ģ��ַ���Ϊ��";
	int j = 0;
	for (int i = 4 * (quolength + 1);i >= 0;i -= 2)
	{
		cout << (char)(((10 * RSAe[i + 1] + RSAe[i])) + 33);//�ַ�������33�����������Ԫ�ؾ����ڱ�ʾ������
		if (flag == '2')
		{ 
			ttemp_plain[j] = (char)(((10 * RSAe[i + 1] + RSAe[i])) + 33);
			j++;
		}
	}
	cout << "\n\n";
}

//RSA���ܺ�����˳��������෴
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
		cout << "�����������ַ�����" << "\n\n";
		cin.getline(txt_dr, 100);
		cin.getline(txt_dr, 100);
		cout << "������˽Կ�ԣ�d��n����" << "\n\n";
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
		//�������e,n,ar
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
	cout << "�����ַ���ת������������(n)Ϊ��";print_ARRAY(htdt, 2 * tdtlength - 2); cout << "\n\n";//�������
	copy_array(htdt_e, txt_d, 799);
	cout << "˽Կת������������(d)Ϊ��";print_array(htdt_e, 799); cout << "\n\n";
	copy_array(htdt_n, tdt_n, 799);
	cout << "��Կת������������(N)Ϊ��";print_array(htdt_n, 799); cout << "\n\n";
	int A[800] = { 0 };
	for (int i = 0;i < 2 * tdtlength - 2;i += 4)//˳��ȡ��4λ��������
	{
		A[0] = htdt[0 + i];
		A[1] = htdt[1 + i];
		A[2] = htdt[2 + i];
		A[3] = htdt[3 + i];
		cout << "����Ԫ��Ϊ��";print_array(A, 799); cout << "\n\n";
		copy_array(htdt_c, A, 799);
		copy_array(htdt_e, txt_d, 799);
		HyperMemo(htdt_c, htdt_e, htdt_n, tdt_n, 2);//��ģ����
	}
	cout << "������õ�������Ϊ��";
	print_array(RSAd, 999);cout << "\n\n";
	cout << "������õ������ģ������ƣ�Ϊ��";
	HyperPrint(RSAdd, 999); cout << "\n\n";
	for (int i = 0; i < strlen(RSAdd) - 1;i++)
		ddRSA[i] = RSAdd[strlen(RSAdd) - 1 - i];//����
	cout << "\n\n" << "������õ������ģ������ƣ�Ϊ��";//ÿ8λ���һ��
	for (int i = 0; i < strlen(RSAdd) - 2;i += 8)

		cout << ddRSA[i] << ddRSA[i + 1] << ddRSA[i + 2] << ddRSA[i + 3] << ddRSA[i + 4] << ddRSA[i + 5] << ddRSA[i + 6] << ddRSA[i + 7] << "\n";

	cout << "\n\n" << "������õ������ģ����֣�Ϊ��";//������תʮ����ASCII��
	for (int i = 0;i < strlen(RSAdd) - 2;i += 8)
	{
		cout << ((64 * (ddRSA[i + 1] - 48) + 32 * (ddRSA[i + 2] - 48) + 16 * (ddRSA[i + 3] - 48) + 8 * (ddRSA[i + 4] - 48) +
			4 * (ddRSA[i + 5] - 48) + 2 * (ddRSA[i + 6] - 48) + (ddRSA[i + 7] - 48))) << " ";
	}
	cout << "\n\n" << "������õ������ģ��ַ���Ϊ��";//������ת�ַ���
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

/*��ģ���㺯��������Montgomery���ɸ��������㷨
�ɸ�����ģ�˳�ģ���㹫ʽΪC=A*B*r^(-k) % N��
��R = H*k %N��R'=H*(-k) %N��E=SIGMA(E*2*i)��
��A'=A*R %N��X=A'����ô��n-1��0����ѭ����ÿ��ȡX=X*X*R' %N��
���E=1��X=X*A'*R' %N���򷵻�X=X*1*R' %N*/
void HyperMemo(int copy_x[], int copy_e[], int copy_n[], int n[], int flag)//�������Ϊ������ָ����ģ����ԭģ������־
{
	int mask[2000] = { 1 };
	reverse_array(copy_e, _cee, detect_array(copy_e, 299), 2);
//	cout << "�õ�����������Ϊ";print_array(copy_e, 299);cout << '\n';//����������
	HyperToBinary(copy_e, _ce);//��ָ���Ķ�������
	copy_array(_cce, _ce, 799);
	int nMaxBit = detect_array(_ce, 799);
	int _nMaxBit = nMaxBit;
//	cout << "���λ��Ϊ��" << nMaxBit;cout << '\n';//��ö����ƺ��ָ�������λ
	int CPY = 0;
	for (int N = nMaxBit; N >= 0;--N)//��n-1��0ѭ��
	{
		cTwo[N] = 1;
//		cout << "�õ��ģ�N������Ϊ��";print_array(cTwo, 299);cout << '\n';//ÿ��ȷ������ʣ�೤��
		HyperMul_memo(mask, mask);//A=A*A
		HyperDiv_memo(mask, copy_n);//��λ�ж�
		copy_array(copy_n, n, 799);
//		cout << "��ģ�����I��Ϊ��";print_array(mask, 1000);cout << '\n';
		if (Hyper_binary_YU())//�������ж��Ƿ���Ҫ�Ա�λ�ٴμ���
		{
			HyperMul_memo(mask, copy_x);
			HyperDiv_memo(mask, copy_n);
			copy_array(copy_n, n, 299);//������ģ
//			cout << "��ģ�����II��Ϊ��";print_array(mask, 1000);cout << '\n';
		}
		copy_array(cTwo, clear, 299);
	}
//	cout << "��ģ����Ľ��Ϊ�������Ϊ������";
	if ((mask[0] == 0) && (detect_array(mask, 199) == -1))
		cout << "0";
	else
		print_array(mask, 1000);
	if (flag == 1)//��־Ϊ1����RSA���ܹ���ʱ
	{
		for (int i = 0; i < 4;i++)//ÿ4λ��ȡһ��
		{
			int temp = mask[i];
			RSAe[RSAe_N] = mask[i];//����
			RSAee[RSAee_N + 3] = temp % 2 + '0', temp /= 2;
			RSAee[RSAee_N + 2] = temp % 2 + '0', temp /= 2;
			RSAee[RSAee_N + 1] = temp % 2 + '0', temp /= 2;
			RSAee[RSAee_N + 0] = temp % 2 + '0';
			RSAe_N += 1;
			RSAee_N += 4;
		}
	}
	if (flag == 2)//��־Ϊ2����RSA���ܹ���ʱ
	{
		int temp = mask[0];
		RSAd[RSAd_N] = temp;//˳��
		RSAdd[RSAdd_N + 0] = temp % 2 + '0', temp /= 2;
		RSAdd[RSAdd_N + 1] = temp % 2 + '0', temp /= 2;
		RSAdd[RSAdd_N + 2] = temp % 2 + '0';
		RSAd_N += 1;
		RSAdd_N += 3;
	}
	cout << '\n';
}

void RSA()//ÿ�μ���14��
{
	cout << "ע���ù���Ŀǰʵ�����ض���Կ��RSA��д������ԿΪ��Կ��2773,63����˽Կ��2773,847�������������ַ��Կ�ʼ��д��\n";
	cin >> blank;
	int temp_N = 0;//����
	fstream file1;//���ļ�Ϊfile1
	file1.open("D://RSA.txt", ios::binary | ios::in);
	file1.read((char*)&temp, sizeof(temp));
	file1.close();

	int seri = strlen(temp) / 14;//ȷ��ִ��ѭ������
	(strlen(temp) % 14 == 0) ? (seri += 0) : (seri += 1);

	//����
	for (int i = 0; i < seri; i++)
	{
		for (int j = 0; j < 14; j++)
			ttemp[j] = temp[j + 14 * temp_N];//ÿ��ȡ14λ����ʱ����ttemp��
		RSA_encode(keylength, '2');//ִ��RSA����
		for (int k = 0; k < 115;k++)
			tempt_plain[k + 114 * temp_N] = ttemp_plain[k];//���õ��Ľ��ת�浽ttemp_plain�У�ÿ��64λ����0λ��Ҫ
		temp_N++;
	}
	copy_ARRAY(temp_plain, tempt_plain, 14999);//����ʱ���鴢��Ķ�������ת��temp_plain׼������

	file1.open("D://RSA_Encrypt.txt", ios::binary | ios::out);
	file1.write((char*)&temp_plain, sizeof(temp_plain));
	file1.close();

	file1.open("D://RSA_Encrypt.txt", ios::binary | ios::in);
	file1.read((char*)&temp_cipher, sizeof(temp_cipher));
	file1.close();
	temp_N = 0;//��ʼ��

	//����
	for (int i = 0; i < seri; i++)
	{
		for (int j = 0; j < 78; j++)
			ttemp_cipher[j] = temp_cipher[j + 78 * temp_N];//ÿ�δ�����ȡ76λ��real_z����0λ��Ҫ
		RSA_decode('2');//ִ��RSA����
		for (int k = 0; k < 15;k++)
			ttemp_final[k + 14 * temp_N] = tempt_final[k];//���õ��Ľ��ת�浽ttemp_final�У�ÿ��8λ
		temp_N++;
	}
	copy_ARRAY(temp_final, ttemp_final, 4999);//����ʱ���鴢����ַ�ת��temp_final׼������

	file1.open("D://RSA_Decrypt.txt", ios::binary | ios::out);
	file1.write((char*)&temp_final, sizeof(temp_final));
	file1.close();
	cout << "��д�ɹ���" << "\n\n";
}