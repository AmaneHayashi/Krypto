/*
 * * * * * * * * * * * * * * * * * * * * �ƶ���������ȫ����ʵ���* * * * * * * * * * * * * * * * * * * *
 *   WRITTEN BY: AMANE ICE                                                                             *
 *   DATE: 16/09/2018                                                                                  *
 *   REFERENCES: GUIDANCE BOOK OF MOBILE INTERNET SECURITY TECH.                                       *
 *   SCHOOL OF INFORMATION AND TELECOMMUNICATION ENGINNERING,                                          *
 *   BEIJING UNIVERSITY OF POSTS AND TELECOMMUNICATIONS                                                *
 * * * * * * * * * * * * * * * * * * * * * *  * DES�㷨* * * * * * * * * * * * * * * * * * * * * * * * *

���Բο�������Կ��MIYAOKEY�������ģ�LOVEBUPT�������ģ�1111101101111110010100110011111101100101100001100101100111111010��
��ĿҪ��
��1��a.���ַ���A����תΪ 2 ���Ʊ�����ʽ�����b. �Ѷ����Ʊ���'01000010'ת��Ϊ�ַ������

��2��a. ���ַ�����Ӧ��Կ�� 64 λ���أ�8X8�� ��ʽ�����ʹ�ã�1���еĺ�������ת����
b. �����û�ѡ�� 1 �󣬷ֱ������ C0��28 λ���� D0��28 λ����Ӧ�ı��أ�
c. ����� 5 �ε���ʱ������������Կ K5 ����Ӧ�� 48 λ����;

��3��a. ԭ�Ķ�Ӧ�� 64 λ 2 ���Ʊ������У�b. 64 �������о�����ʼ�û� IP �󣬵õ��µ� 64 λ���أ�
c. �˻��任��Ҫ���� 16 �ε������������ 5 �ε����󣬵õ���64 λ���أ�
d. �����ɳ˻��任��16 �ε�������õ��� 64 λ���أ�e. ������ܺ�����ĵ� 64 λ���أ�

��4��������ܺ��ԭ�Ķ�Ӧ���ַ�����

��5�������ı�������һ���ı��ļ�����DES_Encrypt.txt�����У�Ȼ�������ļ����н��ܣ��õ���ԭ�ı��浽�ı��ļ�����DES_Final.txt�����У�

��6�����ʵ������ DES����ɶ�һ�����ֵļ�������ܹ��̡�
*/

#include"test.h"//�������
#include"function.h"//С����

int main() {
	while (1) {
		char c;
		cout << "����������Ҫ�Ĳ�����\n1.��ʽת��\n2.��Կ����\n3.DES����\n4.DES����\n5.�ӽ���ϵͳ\n6.3DES\n7.�˳�\n";
		cin >> c;
		system("cls");//����
		switch (c) {
		case '1':
			cout << "��������Ҫת�����ַ���\n";
			cin >> charac;
			cout << charac << "��Ӧ�Ķ���������";
			code_trans_cb(charac, 9); cout << "\n\n";//�ַ�ת�����ƺ���
			cout << "��������Ҫת���Ķ���������\n";
			cin >> binary;
			cout << binary << "��Ӧ���ַ���";
			code_trans_bc(); cout << "\n\n";//������ת�ַ�����
			system("pause");
			break;
		case '2':
			cout << "��������Կ��8λ����\n";
			cin >> secretkey;
			generate_secret_key(secretkey);//�������뼯����
			cout << "�����û�ѡ����C0��D0Ϊ��ǰ��ΪC0������ΪD0��\n";
			print_array(C0_key, 1, 28);	cout << "\n\n";
			print_array(D0_key, 1, 28);	cout << "\n\n";
			cout << "������5�ε���ʱ������������ԿK5����Ӧ��48����Ϊ��\n";
			print_array(real_key5, 1, 48);	cout << "\n\n";
			system("pause");
			break;
		case '3':
			flag = 0;
			cout << "��������Կ��8λ����\n";
			cin >> secretkey;
			cout << "��ѡ���������ĵķ�ʽ�����ַ�������1����������������2��" << "\n";
			cin >> flag;
			DES_encode(secretkey, flag);//DES���ܺ���
			cout << "��ʼ�û����ԭ�ı�������Ϊ��";
			print_array(real_plaintext, 1, 64);cout << "\n\n";
		//	cout << "5�ε�����õ���64λ����Ϊ��";
		//	print_array(real_5_text, 1, 64); cout << "\n\n";
			cout << "16�ε�����õ���64λ����Ϊ��";
			print_array(real_text, 1, 64); cout << "\n\n";
			system("pause");
			break;
		case'4':
			flag = 0;
			cout << "��������Կ��8λ����\n";
			cin >> secretkey;
			cout << "��ѡ���������ĵķ�ʽ�����ַ�������1����������������2��\n";
			cin >> flag;
			DES_decode(secretkey, flag);//DES���ܺ���
			cout << "��ʼ�û����ԭ�ı�������Ϊ��";
			print_array(real_ciphertext, 1, 64);cout << "\n\n";
			cout << "16�ε�����õ���64λ����Ϊ��";
			print_array(real_text, 1, 64); cout << "\n\n";
			system("pause");
			break;
		case '5':
			cout << "��������Կ��8λ����\n";
			cin >> secretkey;
			DES();//DESϵͳ����
			cout << "��д�ɹ���\n";
			system("pause");
			break;
		case '6':
			cout << "��������Կ��24λ��ע�⣺1~8λ��9~16λ��17~24λ���β�����ȣ���\n";
			cin >> secretkey_24;
			cout << "��ѡ���������ĵķ�ʽ�����ַ�������1����������������2��\n";
			cin >> flag;
			Trinity_DES(flag);//3DES����
			system("pause");
			break;
		case '7':
			return 0;
		default:
			printf("��������!\n");
			system("pause");
			break;
		}
	}

}

//����Կ���ɺ���
void generate_secret_key(char* secretkey)//�������Ϊ��Կָ��
{
	key0[0] = C0_key[0] = D0_key[0] = '\0';//��0λ����
	cout << "��Կ��Ӧ��64λ��������Ϊ��";
	code_trans_cb(secretkey, 71); cout << '\n';
	transfer(key0, real_z, PC_1, 56);//����������Կ����PC_1����û�
	decompose(C0_key, D0_key, key0, 28);//���û��õ�������Կ�ֽ�ΪC0��D0

	//��C0��D0���Ʋ�ͨ��PC_2����û���ִ��16������16������Կ
	move_transfer(C0_key, D0_key, key1, real_key1, PC_2, 1, 28, 48);
	move_transfer(C0_key, D0_key, key2, real_key2, PC_2, 1, 28, 48);
	move_transfer(C0_key, D0_key, key3, real_key3, PC_2, 2, 28, 48);
	move_transfer(C0_key, D0_key, key4, real_key4, PC_2, 2, 28, 48);
	move_transfer(C0_key, D0_key, key5, real_key5, PC_2, 2, 28, 48);
	move_transfer(C0_key, D0_key, key6, real_key6, PC_2, 2, 28, 48);
	move_transfer(C0_key, D0_key, key7, real_key7, PC_2, 2, 28, 48);
	move_transfer(C0_key, D0_key, key8, real_key8, PC_2, 2, 28, 48);
	move_transfer(C0_key, D0_key, key9, real_key9, PC_2, 1, 28, 48);
	move_transfer(C0_key, D0_key, key10, real_key10, PC_2, 2, 28, 48);
	move_transfer(C0_key, D0_key, key11, real_key11, PC_2, 2, 28, 48);
	move_transfer(C0_key, D0_key, key12, real_key12, PC_2, 2, 28, 48);
	move_transfer(C0_key, D0_key, key13, real_key13, PC_2, 2, 28, 48);
	move_transfer(C0_key, D0_key, key14, real_key14, PC_2, 2, 28, 48);
	move_transfer(C0_key, D0_key, key15, real_key15, PC_2, 2, 28, 48);
	move_transfer(C0_key, D0_key, key16, real_key16, PC_2, 1, 28, 48);
}

//DES���ܺ���
int* DES_encode(char* encrypt, char flag)//�������Ϊ��Կָ����ִ������
{
	copy_array(real_ciphertext, clear, N);//��������ı�clear��
	copy_array(real_plaintext, clear, N);//��������ı�clear��

	generate_secret_key(encrypt);//����16������Կ

	//flagΪ1��2�������ڼ���ʱ������������ͣ�flagΪ3�������ڶ�д�ļ���flagΪ4��������3DES
	if (flag == '1') {
		cout << "���������ģ�\n";
		cin >> plaintext;
		cout << "���Ķ�Ӧ��64λ��������Ϊ��";
		code_trans_cb(plaintext, 72); cout << '\n';
	}
	if (flag == '2') {
		cout << "���������ģ�\n";
		cin >> realtext;
		for (int i = 0; i < 72; i++)
			real_z[i + 1] = realtext[i] - '0';//��0λ����
	}
	if (flag == '3')
		copy_array(real_z, rreal_z, 499);//��ԭreal_z
	if (flag == '4')
		for (int i = 0; i < 72; i++)
			real_z[i] = not_real_plain[i];//����3DES��һ����õĽ����ʼ��real_z

	//���ڲ�ͬ��С�ʣ��������ֻ����real_z���������ƻ�������ģ��Ļ�÷�ʽ��������ͬ
	transfer(real_plaintext, real_z, IP, 64);//����IP���û�real_z
	decompose(L0_text, R0_text, real_plaintext, 32);//���û���õ���real_plaintext�ֽ�ΪL0��R0

	//ִ�к���f��������XOR��E���û���S��ӳ�䣩�ܼ�16�Σ��õ����յ�����L16��R16
	f(R0_text, L0_text, R1_text, L1_text, real_key1, ER0_text, 32);
	f(R1_text, L1_text, R2_text, L2_text, real_key2, ER1_text, 32);
	f(R2_text, L2_text, R3_text, L3_text, real_key3, ER2_text, 32);
	f(R3_text, L3_text, R4_text, L4_text, real_key4, ER3_text, 32);
	f(R4_text, L4_text, R5_text, L5_text, real_key5, ER4_text, 32);

	f(R5_text, L5_text, R6_text, L6_text, real_key6, ER5_text, 32);
	f(R6_text, L6_text, R7_text, L7_text, real_key7, ER6_text, 32);
	f(R7_text, L7_text, R8_text, L8_text, real_key8, ER7_text, 32);
	f(R8_text, L8_text, R9_text, L9_text, real_key9, ER8_text, 32);
	f(R9_text, L9_text, R10_text, L10_text, real_key10, ER9_text, 32);
	f(R10_text, L10_text, R11_text, L11_text, real_key11, ER10_text, 32);
	f(R11_text, L11_text, R12_text, L12_text, real_key12, ER11_text, 32);
	f(R12_text, L12_text, R13_text, L13_text, real_key13, ER12_text, 32);
	f(R13_text, L13_text, R14_text, L14_text, real_key14, ER13_text, 32);
	f(R14_text, L14_text, R15_text, L15_text, real_key15, ER14_text, 32);
	f(R15_text, L15_text, R16_text, L16_text, real_key16, ER15_text, 32);

	compose(R16_text, L16_text, real_text, 32);//��L16��R16���Ϊreal_text
	transfer(real_ciphertext, real_text, IP_1, 64);//ͨ������IP_1�任�õ����ģ������ƣ�

	compose(L5_text, R5_text, real_5_text, 32);//��L5��R5���Ϊreal_5_text
	cout << "��5�ε����������64λ����Ϊ��";
	print_array(real_5_text, 1, 64); cout << "\n\n";
	cout << "���������Ϊ��";
	print_array(real_ciphertext, 1, 64); cout << "\n\n";

	if (flag == '3')//��д�ļ�ʱ
		for (int i = 0;i < 65; i++)
			ceal_ciphertext[i] = real_ciphertext[i] + '0';//���õ��Ķ�������תΪchar���ͣ���������DES_encrypt�ļ�
	if (flag == '4')
		copy_array(trinity_real_cipher, real_ciphertext, 65);
	copy_array(not_real_cipher, real_ciphertext, 65);//���õ����������鸴�Ƹ����������ġ�������3DES����һ������
	return real_ciphertext;
}

//DES���ܺ���
int* DES_decode(char* decrypt, char flag)//�������Ϊ��Կָ����ִ������
{
	copy_array(real_plaintext, clear, N);//��������ı�clear��
	copy_array(real_ciphertext, clear, N);//��������ı�clear��
	generate_secret_key(decrypt);//����16������Կ

	//flagΪ1��2�������ڼ���ʱ������������ͣ�flagΪ3�������ڶ�д�ļ���flagΪ4��������3DES
	if (flag == '1')
	{
		cout << "���������ģ�\n";
		cin >> ciphertext;
		cout << "���Ķ�Ӧ��64λ��������Ϊ��";
		code_trans_cb(ciphertext, 72); cout << '\n';
	}
	if (flag == '2')
	{
		cout << "���������ģ�\n";
		cin >> realcipher;
		for (int i = 0; i < 64; i++)
			real_z[i + 1] = realcipher[i] - '0';//��0λ����
	}
	if (flag == '3')
		copy_array(real_z, rreal_z, 499);//��ԭreal_z
	if (flag == '4')
		for (int i = 0; i < 71; i++)
			real_z[i] = not_real_cipher[i];//����3DES��һ����õĽ����ʼ��real_z

	//���ڲ�ͬ��С�ʣ��������ֻ����real_z���������ƻ�������ģ��Ļ�÷�ʽ��������ͬ
	transfer(real_ciphertext, real_z, IP, 64);//����IP���û�real_z
	decompose(L0_text, R0_text, real_ciphertext, 32);//���û���õ���real_ciphertext�ֽ�ΪL0��R0

	//ִ�к���f��������XOR��E���û���S��ӳ�䣩�ܼ�16�Σ��õ����յ�����L16��R16��ע�⣺real_key˳����
	f(R0_text, L0_text, R1_text, L1_text, real_key16, ER0_text, 32);
	f(R1_text, L1_text, R2_text, L2_text, real_key15, ER1_text, 32);
	f(R2_text, L2_text, R3_text, L3_text, real_key14, ER2_text, 32);
	f(R3_text, L3_text, R4_text, L4_text, real_key13, ER3_text, 32);
	f(R4_text, L4_text, R5_text, L5_text, real_key12, ER4_text, 32);
	f(R5_text, L5_text, R6_text, L6_text, real_key11, ER5_text, 32);
	f(R6_text, L6_text, R7_text, L7_text, real_key10, ER6_text, 32);
	f(R7_text, L7_text, R8_text, L8_text, real_key9, ER7_text, 32);
	f(R8_text, L8_text, R9_text, L9_text, real_key8, ER8_text, 32);
	f(R9_text, L9_text, R10_text, L10_text, real_key7, ER9_text, 32);
	f(R10_text, L10_text, R11_text, L11_text, real_key6, ER10_text, 32);
	f(R11_text, L11_text, R12_text, L12_text, real_key5, ER11_text, 32);
	f(R12_text, L12_text, R13_text, L13_text, real_key4, ER12_text, 32);
	f(R13_text, L13_text, R14_text, L14_text, real_key3, ER13_text, 32);
	f(R14_text, L14_text, R15_text, L15_text, real_key2, ER14_text, 32);
	f(R15_text, L15_text, R16_text, L16_text, real_key1, ER15_text, 32);

	compose(R16_text, L16_text, real_text, 32);//��R16��L16���Ϊreal_text��ע�⣺R��L����
	transfer(real_plaintext, real_text, IP_1, 64);//ͨ������IP_1�任�õ����ģ������ƣ�

	cout << "���������Ϊ��";//�����Ӧ�Ķ�������
	print_array(real_plaintext, 1, 64); cout << "\n\n";

	cout << "���Ķ�Ӧ���ַ�Ϊ��";//�����Ӧ���ַ���
	int CN = 0;
	for (int i = 1; i < 65;i += 8)
	{//ֱ�Ӹ��ݽ���ת������������ת��Ϊʮ���ƣ�ʮ����ת��ΪASCII��
		cout << (char)(128 * real_plaintext[i] + 64 * real_plaintext[i + 1] + 32 * real_plaintext[i + 2] + 16 * real_plaintext[i + 3] + 8 * real_plaintext[i + 4] + 4 * real_plaintext[i + 5] + 2 * real_plaintext[i + 6] + 1 * real_plaintext[i + 7]);
		if ((flag == '3') || (flag == '4'))
		{
			ceal_plaintext[CN] = (char)(128 * real_plaintext[i] + 64 * real_plaintext[i + 1] + 32 * real_plaintext[i + 2] + 16 * real_plaintext[i + 3] + 8 * real_plaintext[i + 4] + 4 * real_plaintext[i + 5] + 2 * real_plaintext[i + 6] + 1 * real_plaintext[i + 7]);
			CN++;
		}
	}
	cout << "\n";

	copy_array(not_real_plain, real_plaintext, 65);//������3DES�����Σ����ڽ�һ��ʵ��3DES
	return real_plaintext;
}

//DESϵͳ����
void DES()
{
	int temp_N = 0;//����
	fstream file1;//���ļ�Ϊfile1
	file1.open("D://DES.txt", ios::binary | ios::in);
	file1.read((char*)&temp, sizeof(temp));
	file1.close();

	int seri = strlen(temp) / 8;//ȷ��ִ��ѭ������
	(strlen(temp) % 8 == 0) ? (seri += 0) : (seri += 1);

	//����
	for (int i = 0; i < seri; i++)
	{
		copy_array(real_z, clear, 499);//��ʼ��real_z
		for (int j = 0; j < 8; j++)
			ttemp[j] = temp[j + 8 * temp_N];//ÿ��ȡ8λ����ʱ����ttemp��
		code_trans_cb_sys(ttemp);//��ttemp�е��ַ������ƻ����õ�real_z
		copy_array(rreal_z, real_z, 499);//����real_z
		DES_encode(secretkey, '3');//ִ��DES����
		for (int k = 0; k < 65;k++)
			ttemp_plain[k + 65 * temp_N] = ceal_ciphertext[k];//���õ��Ľ��ת�浽ttemp_plain�У�ÿ��64λ����0λ��Ҫ
		temp_N++;
	}
	copy_ARRAY(temp_plain, ttemp_plain, 14999);//����ʱ���鴢��Ķ�������ת��temp_plain׼������

	file1.open("D://DES_Encrypt.txt", ios::binary | ios::out);
	file1.write((char*)&temp_plain, sizeof(temp_plain));
	file1.close();

	file1.open("D://DES_Encrypt.txt", ios::binary | ios::in);
	file1.read((char*)&temp_cipher, sizeof(temp_cipher));
	file1.close();
	temp_N = 0;//��ʼ��

	//����
	for (int i = 0; i < seri; i++)
	{
		copy_array(real_z, clear, 499);//��ʼ��real_z
		for (int j = 1; j < 65; j++)
			real_z[j] = temp_cipher[j + 65 * temp_N] - '0';//ÿ�δӶ���������ȡ64λ��real_z����0λ��Ҫ
		copy_array(rreal_z, real_z, 499);//����real_z
		DES_decode(secretkey, '3');//ִ��DES����
		for (int k = 0; k < 8;k++)
			ttemp_final[k + 8 * temp_N] = ceal_plaintext[k];//���õ��Ľ��ת�浽ttemp_final�У�ÿ��8λ
		temp_N++;
	}
	copy_ARRAY(temp_final, ttemp_final, 4999);//����ʱ���鴢����ַ�ת��temp_final׼������

	file1.open("D://DES_Decrypt.txt", ios::binary | ios::out);
	file1.write((char*)&temp_final, sizeof(temp_final));
	file1.close();
}

//3DES�ӽ��ܣ���Ƴ�ϵͳ�ķ����루5������ͬ��
void Trinity_DES(int flag)//�������Ϊִ������
{
	char skey_1[8] = { 0 }, skey_2[8] = { 0 }, skey_3[8] = { 0 };//����3������Կ
	for (int i = 0; i < 8; i++)
		skey_1[i] = secretkey_24[i];//1~8λ����һ����Կ
	for (int j = 0; j < 8; j++)
		skey_2[j] = secretkey_24[j + 8];//9~16λ����һ����Կ
	for (int k = 0; k < 8; k++)
		skey_3[k] = secretkey_24[k + 16];//17~24λ����һ����Կ
	cout << "3����Կ�ֱ�Ϊ��";cout << "\n";//�����֤
	print_ARRAY(skey_1, 0, 8);cout << "\n";
	print_ARRAY(skey_2, 0, 8);cout << "\n";
	print_ARRAY(skey_3, 0, 8);cout << "\n";

	cout << "3DES���ܿ�ʼ��" << "\n\n";
	DES_encode(skey_1, flag);//��һ�μ��ܣ����Ϊ����������
	DES_decode(skey_2, '4');//��һ�ν��ܣ��������������
	DES_encode(skey_3, '4');//�ڶ��μ��ܣ����Ϊ����������
	cout << "3DES���ܽ��Ϊ��" << "\n\n";
	print_array(trinity_real_cipher, 1, 64);
	cout << "\n\n";

	copy_array(not_real_cipher, clear, 65);//��ʼ��not_real_cipher
	copy_array(not_real_plain, clear, 65);//��ʼ��not_real_plai

	cout << "3DES���ܿ�ʼ��" << "\n\n";
	DES_decode(skey_3, '2');//��һ�ν��ܣ����Ϊ����������
	DES_encode(skey_2, '4');//��һ�μ��ܣ����Ϊ����������
	DES_decode(skey_1, '4'); //�ڶ��ν��ܣ����Ϊ�ַ���
	cout << "3DES���ܽ��Ϊ��" ;
	for (int i = 0; i < 8; i++)
		cout << ceal_plaintext[i];
	cout << endl;
}