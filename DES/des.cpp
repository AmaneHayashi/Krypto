/*
 * * * * * * * * * * * * * * * * * * * * 移动互联网安全技术实验二* * * * * * * * * * * * * * * * * * * *
 *   WRITTEN BY: AMANE ICE                                                                             *
 *   DATE: 16/09/2018                                                                                  *
 *   REFERENCES: GUIDANCE BOOK OF MOBILE INTERNET SECURITY TECH.                                       *
 *   SCHOOL OF INFORMATION AND TELECOMMUNICATION ENGINNERING,                                          *
 *   BEIJING UNIVERSITY OF POSTS AND TELECOMMUNICATIONS                                                *
 * * * * * * * * * * * * * * * * * * * * * *  * DES算法* * * * * * * * * * * * * * * * * * * * * * * * *

测试参考：（密钥）MIYAOKEY，（明文）LOVEBUPT，（密文）1111101101111110010100110011111101100101100001100101100111111010。
题目要求：
（1）a.把字符‘A’，转为 2 进制比特形式输出；b. 把二进制比特'01000010'转换为字符输出；

（2）a. 该字符串对应密钥的 64 位比特（8X8） 形式输出，使用（1）中的函数进行转换；
b. 经过置换选择 1 后，分别输出的 C0（28 位）和 D0（28 位）对应的比特；
c. 输出第 5 次迭代时，产生的子密钥 K5 所对应的 48 位比特;

（3）a. 原文对应的 64 位 2 进制比特序列；b. 64 比特序列经过初始置换 IP 后，得到新的 64 位比特；
c. 乘积变换需要进行 16 次迭代，输出经过 5 次迭代后，得到的64 位比特；
d. 输出完成乘积变换（16 次迭代）后得到的 64 位比特；e. 输出加密后的密文的 64 位比特；

（4）输出解密后的原文对应的字符串；

（5）把密文保存在另一个文本文件（“DES_Encrypt.txt”）中，然后对这个文件进行解密，得到的原文保存到文本文件（“DES_Final.txt”）中；

（6）设计实现三重 DES，完成对一段文字的加密与解密过程。
*/

#include"test.h"//定义变量
#include"function.h"//小函数

int main() {
	while (1) {
		char c;
		cout << "请输入您想要的操作。\n1.格式转换\n2.密钥产生\n3.DES加密\n4.DES解密\n5.加解密系统\n6.3DES\n7.退出\n";
		cin >> c;
		system("cls");//清屏
		switch (c) {
		case '1':
			cout << "请输入您要转化的字符！\n";
			cin >> charac;
			cout << charac << "对应的二进制数是";
			code_trans_cb(charac, 9); cout << "\n\n";//字符转二进制函数
			cout << "请输入您要转化的二进制数！\n";
			cin >> binary;
			cout << binary << "对应的字符是";
			code_trans_bc(); cout << "\n\n";//二进制转字符函数
			system("pause");
			break;
		case '2':
			cout << "请输入密钥（8位）！\n";
			cin >> secretkey;
			generate_secret_key(secretkey);//产生密码集函数
			cout << "经过置换选择后的C0与D0为（前者为C0，后者为D0）\n";
			print_array(C0_key, 1, 28);	cout << "\n\n";
			print_array(D0_key, 1, 28);	cout << "\n\n";
			cout << "经过第5次迭代时，产生的子密钥K5所对应的48比特为：\n";
			print_array(real_key5, 1, 48);	cout << "\n\n";
			system("pause");
			break;
		case '3':
			flag = 0;
			cout << "请输入密钥（8位）！\n";
			cin >> secretkey;
			cout << "请选择输入明文的方式！（字符，输入1；二进制数，输入2）" << "\n";
			cin >> flag;
			DES_encode(secretkey, flag);//DES加密函数
			cout << "初始置换后的原文比特序列为：";
			print_array(real_plaintext, 1, 64);cout << "\n\n";
		//	cout << "5次迭代后得到的64位比特为：";
		//	print_array(real_5_text, 1, 64); cout << "\n\n";
			cout << "16次迭代后得到的64位比特为：";
			print_array(real_text, 1, 64); cout << "\n\n";
			system("pause");
			break;
		case'4':
			flag = 0;
			cout << "请输入密钥（8位）！\n";
			cin >> secretkey;
			cout << "请选择输入明文的方式！（字符，输入1；二进制数，输入2）\n";
			cin >> flag;
			DES_decode(secretkey, flag);//DES解密函数
			cout << "初始置换后的原文比特序列为：";
			print_array(real_ciphertext, 1, 64);cout << "\n\n";
			cout << "16次迭代后得到的64位比特为：";
			print_array(real_text, 1, 64); cout << "\n\n";
			system("pause");
			break;
		case '5':
			cout << "请输入密钥（8位）！\n";
			cin >> secretkey;
			DES();//DES系统函数
			cout << "读写成功！\n";
			system("pause");
			break;
		case '6':
			cout << "请输入密钥（24位，注意：1~8位，9~16位，17~24位三段不能相等）！\n";
			cin >> secretkey_24;
			cout << "请选择输入明文的方式！（字符，输入1；二进制数，输入2）\n";
			cin >> flag;
			Trinity_DES(flag);//3DES函数
			system("pause");
			break;
		case '7':
			return 0;
		default:
			printf("输入有误!\n");
			system("pause");
			break;
		}
	}

}

//子密钥生成函数
void generate_secret_key(char* secretkey)//传入参数为密钥指针
{
	key0[0] = C0_key[0] = D0_key[0] = '\0';//第0位不用
	cout << "密钥对应的64位比特序列为：";
	code_trans_cb(secretkey, 71); cout << '\n';
	transfer(key0, real_z, PC_1, 56);//将二进制密钥根据PC_1表格置换
	decompose(C0_key, D0_key, key0, 28);//将置换得到的新密钥分解为C0、D0

	//将C0、D0左移并通过PC_2表格置换，执行16次生成16对子密钥
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

//DES加密函数
int* DES_encode(char* encrypt, char flag)//传入参数为密钥指针与执行类型
{
	copy_array(real_ciphertext, clear, N);//清空真密文表（clear）
	copy_array(real_plaintext, clear, N);//清空真明文表（clear）

	generate_secret_key(encrypt);//生成16对子密钥

	//flag为1或2，适用于加密时输入的文字类型；flag为3，适用于读写文件；flag为4，适用于3DES
	if (flag == '1') {
		cout << "请输入明文！\n";
		cin >> plaintext;
		cout << "明文对应的64位比特序列为：";
		code_trans_cb(plaintext, 72); cout << '\n';
	}
	if (flag == '2') {
		cout << "请输入明文！\n";
		cin >> realtext;
		for (int i = 0; i < 72; i++)
			real_z[i + 1] = realtext[i] - '0';//第0位不用
	}
	if (flag == '3')
		copy_array(real_z, rreal_z, 499);//还原real_z
	if (flag == '4')
		for (int i = 0; i < 72; i++)
			real_z[i] = not_real_plain[i];//利用3DES上一步求得的结果初始化real_z

	//对于不同的小问，有区别的只在于real_z（即二进制化后的明文）的获得方式，以下相同
	transfer(real_plaintext, real_z, IP, 64);//根据IP表置换real_z
	decompose(L0_text, R0_text, real_plaintext, 32);//将置换后得到的real_plaintext分解为L0、R0

	//执行函数f（迭代、XOR、E表置换、S表映射）总计16次，得到最终的区块L16、R16
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

	compose(R16_text, L16_text, real_text, 32);//将L16、R16结合为real_text
	transfer(real_ciphertext, real_text, IP_1, 64);//通过最后的IP_1变换得到密文（二进制）

	compose(L5_text, R5_text, real_5_text, 32);//将L5、R5结合为real_5_text
	cout << "第5次迭代后输出的64位比特为：";
	print_array(real_5_text, 1, 64); cout << "\n\n";
	cout << "输出的密文为：";
	print_array(real_ciphertext, 1, 64); cout << "\n\n";

	if (flag == '3')//读写文件时
		for (int i = 0;i < 65; i++)
			ceal_ciphertext[i] = real_ciphertext[i] + '0';//将得到的二进制数转为char类型，供储存入DES_encrypt文件
	if (flag == '4')
		copy_array(trinity_real_cipher, real_ciphertext, 65);
	copy_array(not_real_cipher, real_ciphertext, 65);//将得到的密文数组复制给“非真密文”，用于3DES的下一步操作
	return real_ciphertext;
}

//DES解密函数
int* DES_decode(char* decrypt, char flag)//传入参数为密钥指针与执行类型
{
	copy_array(real_plaintext, clear, N);//清空真明文表（clear）
	copy_array(real_ciphertext, clear, N);//清空真密文表（clear）
	generate_secret_key(decrypt);//生成16对子密钥

	//flag为1或2，适用于加密时输入的文字类型；flag为3，适用于读写文件；flag为4，适用于3DES
	if (flag == '1')
	{
		cout << "请输入密文！\n";
		cin >> ciphertext;
		cout << "密文对应的64位比特序列为：";
		code_trans_cb(ciphertext, 72); cout << '\n';
	}
	if (flag == '2')
	{
		cout << "请输入密文！\n";
		cin >> realcipher;
		for (int i = 0; i < 64; i++)
			real_z[i + 1] = realcipher[i] - '0';//第0位不用
	}
	if (flag == '3')
		copy_array(real_z, rreal_z, 499);//还原real_z
	if (flag == '4')
		for (int i = 0; i < 71; i++)
			real_z[i] = not_real_cipher[i];//利用3DES上一步求得的结果初始化real_z

	//对于不同的小问，有区别的只在于real_z（即二进制化后的明文）的获得方式，以下相同
	transfer(real_ciphertext, real_z, IP, 64);//根据IP表置换real_z
	decompose(L0_text, R0_text, real_ciphertext, 32);//将置换后得到的real_ciphertext分解为L0、R0

	//执行函数f（迭代、XOR、E表置换、S表映射）总计16次，得到最终的区块L16、R16（注意：real_key顺序反向）
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

	compose(R16_text, L16_text, real_text, 32);//将R16、L16结合为real_text（注意：R、L反序）
	transfer(real_plaintext, real_text, IP_1, 64);//通过最后的IP_1变换得到密文（二进制）

	cout << "输出的明文为：";//输出对应的二进制数
	print_array(real_plaintext, 1, 64); cout << "\n\n";

	cout << "明文对应的字符为：";//输出对应的字符串
	int CN = 0;
	for (int i = 1; i < 65;i += 8)
	{//直接根据进制转换，将二进制转换为十进制，十进制转换为ASCII符
		cout << (char)(128 * real_plaintext[i] + 64 * real_plaintext[i + 1] + 32 * real_plaintext[i + 2] + 16 * real_plaintext[i + 3] + 8 * real_plaintext[i + 4] + 4 * real_plaintext[i + 5] + 2 * real_plaintext[i + 6] + 1 * real_plaintext[i + 7]);
		if ((flag == '3') || (flag == '4'))
		{
			ceal_plaintext[CN] = (char)(128 * real_plaintext[i] + 64 * real_plaintext[i + 1] + 32 * real_plaintext[i + 2] + 16 * real_plaintext[i + 3] + 8 * real_plaintext[i + 4] + 4 * real_plaintext[i + 5] + 2 * real_plaintext[i + 6] + 1 * real_plaintext[i + 7]);
			CN++;
		}
	}
	cout << "\n";

	copy_array(not_real_plain, real_plaintext, 65);//适用于3DES的情形，用于进一步实现3DES
	return real_plaintext;
}

//DES系统函数
void DES()
{
	int temp_N = 0;//增量
	fstream file1;//设文件为file1
	file1.open("D://DES.txt", ios::binary | ios::in);
	file1.read((char*)&temp, sizeof(temp));
	file1.close();

	int seri = strlen(temp) / 8;//确定执行循环次数
	(strlen(temp) % 8 == 0) ? (seri += 0) : (seri += 1);

	//加密
	for (int i = 0; i < seri; i++)
	{
		copy_array(real_z, clear, 499);//初始化real_z
		for (int j = 0; j < 8; j++)
			ttemp[j] = temp[j + 8 * temp_N];//每次取8位到临时数组ttemp中
		code_trans_cb_sys(ttemp);//将ttemp中的字符二进制化，得到real_z
		copy_array(rreal_z, real_z, 499);//拷贝real_z
		DES_encode(secretkey, '3');//执行DES加密
		for (int k = 0; k < 65;k++)
			ttemp_plain[k + 65 * temp_N] = ceal_ciphertext[k];//将得到的结果转存到ttemp_plain中，每次64位，第0位不要
		temp_N++;
	}
	copy_ARRAY(temp_plain, ttemp_plain, 14999);//将临时数组储存的二进制数转到temp_plain准备储存

	file1.open("D://DES_Encrypt.txt", ios::binary | ios::out);
	file1.write((char*)&temp_plain, sizeof(temp_plain));
	file1.close();

	file1.open("D://DES_Encrypt.txt", ios::binary | ios::in);
	file1.read((char*)&temp_cipher, sizeof(temp_cipher));
	file1.close();
	temp_N = 0;//初始化

	//解密
	for (int i = 0; i < seri; i++)
	{
		copy_array(real_z, clear, 499);//初始化real_z
		for (int j = 1; j < 65; j++)
			real_z[j] = temp_cipher[j + 65 * temp_N] - '0';//每次从二进制数组取64位给real_z，第0位不要
		copy_array(rreal_z, real_z, 499);//拷贝real_z
		DES_decode(secretkey, '3');//执行DES解密
		for (int k = 0; k < 8;k++)
			ttemp_final[k + 8 * temp_N] = ceal_plaintext[k];//将得到的结果转存到ttemp_final中，每次8位
		temp_N++;
	}
	copy_ARRAY(temp_final, ttemp_final, 4999);//将临时数组储存的字符转到temp_final准备储存

	file1.open("D://DES_Decrypt.txt", ios::binary | ios::out);
	file1.write((char*)&temp_final, sizeof(temp_final));
	file1.close();
}

//3DES加解密（设计成系统的方法与（5）问相同）
void Trinity_DES(int flag)//传入参数为执行类型
{
	char skey_1[8] = { 0 }, skey_2[8] = { 0 }, skey_3[8] = { 0 };//定义3个子密钥
	for (int i = 0; i < 8; i++)
		skey_1[i] = secretkey_24[i];//1~8位给第一个密钥
	for (int j = 0; j < 8; j++)
		skey_2[j] = secretkey_24[j + 8];//9~16位给第一个密钥
	for (int k = 0; k < 8; k++)
		skey_3[k] = secretkey_24[k + 16];//17~24位给第一个密钥
	cout << "3段密钥分别为：";cout << "\n";//输出验证
	print_ARRAY(skey_1, 0, 8);cout << "\n";
	print_ARRAY(skey_2, 0, 8);cout << "\n";
	print_ARRAY(skey_3, 0, 8);cout << "\n";

	cout << "3DES加密开始！" << "\n\n";
	DES_encode(skey_1, flag);//第一次加密，输出为二进制数组
	DES_decode(skey_2, '4');//第一次解密，输出二进制数组
	DES_encode(skey_3, '4');//第二次加密，输出为二进制数组
	cout << "3DES加密结果为：" << "\n\n";
	print_array(trinity_real_cipher, 1, 64);
	cout << "\n\n";

	copy_array(not_real_cipher, clear, 65);//初始化not_real_cipher
	copy_array(not_real_plain, clear, 65);//初始化not_real_plai

	cout << "3DES解密开始！" << "\n\n";
	DES_decode(skey_3, '2');//第一次解密，输出为二进制数组
	DES_encode(skey_2, '4');//第一次加密，输出为二进制数组
	DES_decode(skey_1, '4'); //第二次解密，输出为字符串
	cout << "3DES加密结果为：" ;
	for (int i = 0; i < 8; i++)
		cout << ceal_plaintext[i];
	cout << endl;
}