//【文件包含部分】
#include<stdio.h>
#include<stdlib.h>		// system()、exit() 等函数需要的头文件
#include<Windows.h>		// messagebox() 函数需要的头文件


//【定义全局变量】
int R;
int G;
int B;
float C;
float M;
float Y;
float K;
//int HEX[6];
//int i;	// 数组计数变量
int HEX1;
int HEX2;
int HEX3;
float H;
float S;
float V;


//【函数声明部分】
void Welcome(void);
void Enter_RGB(void);
void Enter_HEX(void);
void Enter_CMYK(void);
void Enter_HSV(void);

void RGB_to_HEX(void);		//（1）
void RGB_to_CMYK(void);		//（2）
void RGB_to_HSV(void);		//（3）
void HEX_to_RGB(void);		//（4）
void CMYK_to_RGB(void);		//（5）
void HSV_to_RGB(void);		//（6）

float max_num(float a, float b, float c);
float min_num(float a, float b, float c);


//【主函数部分】
int main()
{
	int m;										// 菜单选择变量
	printf("加载中 。。。 。。。\n");			// 应该看不到的，除非电脑太卡
	system("mode con cols=60 lines=50");		// 设置窗口大小（单位：行）
	system("title RGB 转换工具（V1.0.0）");		// 设置标题
	Welcome();									//【调用】欢迎界面
	system("pause");							// 暂停

Start:											//【标签】菜单开始
	for (;;)
	{
		system("cls");	// 清屏
		printf("\n     -------------------- 菜    单 -------------------- \n\n");
		printf("       1、RGB → #FFFFFF\t（RGB值转十六进制色值）\n");
		printf("       2、RGB → CMYK\t\t（RGB值转CMYK值）\n");
		printf("       3、RGB → HSV\t\t（RGB值转HSV值）\n");
		printf("       4、#FFFFFF → RGB\t（十六进制色值转RGB值）\n");
		printf("       5、CMYK → RGB\t\t（CMYK值转RGB值）\n");
		printf("       6、HSV → RGB \t\t（HSV值转RGB值）\n");
		printf("\n");
		printf("       0、退    出 \n");
		printf("     --------------------------------------------------\n\n");

		printf("  输入对应数字以选择：");
	RE: scanf_s("%d", &m);
		switch (m)
		{
		case 1:
			system("cls");	// 清屏
			printf("  当前位置：RGB → #FFFFFF \n");
			printf("------------------------------------------------------------\n\n");
			Enter_RGB();	//【调用】获取 RGB 值
			RGB_to_HEX();	//【调用】RGB 转换为 十六进制 的函数
			system("pause");
			break;

		case 2:
			system("cls");	// 清屏
			printf("  当前位置：RGB → CMYK \n");
			printf("------------------------------------------------------------\n\n");
			Enter_RGB();	//【调用】获取 RGB 值
			RGB_to_CMYK();	//【调用】RGB 转换为 CMYK 的函数
			system("pause");
			break;

		case 3:
			system("cls");	// 清屏
			printf("  当前位置：RGB → HSV \n");
			printf("------------------------------------------------------------\n\n");
			Enter_RGB();	//【调用】获取 RGB 值
			RGB_to_HSV();	//【调用】RGB 转换为 HSV 的函数
			system("pause");
			break;

		case 4:
			system("cls");	// 清屏
			printf("  当前位置：#FFFFFF → RGB \n");
			printf("------------------------------------------------------------\n\n");
			Enter_HEX();	//【调用】获取 十六进制 值
			HEX_to_RGB();	//【调用】十六进制 转换为 RGB 的函数
			system("pause");
			break;

		case 5:
			system("cls");	// 清屏
			printf("  当前位置：CMYK → RGB \n");
			printf("------------------------------------------------------------\n\n");
			Enter_CMYK();	//【调用】获取 CMYK 值
			CMYK_to_RGB();	//【调用】CMYK 转换为 RGB 的函数
			system("pause");
			break;

		case 6:
			system("cls");	// 清屏
			printf("  当前位置：HSV → RGB \n");
			printf("------------------------------------------------------------\n\n");
			Enter_HSV();	//【调用】获取 HSV 值
			HSV_to_RGB();	//【调用】HSV 转换为 RGB 的函数
			system("pause");
			break;

		case 0:
			goto Exit;
			break;

		default:
			printf("  请输入有效数字！\n");
			goto RE;
		}
	}
Exit:						//【标签】菜单“退出”的确认部分
	{
		int info = MessageBox(NULL, L"\n确定要退出吗？", L"退出提示", MB_YESNO);
		if (info == IDYES)
		{
			exit(0);		// 退出程序
		}
				
		else if (info == IDNO)
		{
			goto Start;
		}
	}
}


//【函数定义部分】
//【函数】欢迎界面
void Welcome(void)
{
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("              *------------------------------*              \n");
	printf("              |                              |              \n");
	printf("              |        超级色值计算器        |              \n");
	printf("              |                              |              \n");
	printf("              *------------------------------*              \n");
	printf("\n\n\n\n\n");
	printf("                          欢迎使用                          \n\n");
	printf("                 支持 RGB 转换为 CMYK、HSV                  \n");
	printf("                 支持 CMYK、HSV 转换为 RGB                  \n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("             Copyright (c) 2019-2020 BitBitcode             \n");
	printf("\n\n");
}


//【函数】获取用户输入的 RGB 值，并检测是否在 [0, 255] 区间内
void Enter_RGB(void)
{
	printf("  请按照提示输入待转换的颜色值，区间：[0, 255]\n");
	
	// 获取 R 值
RE1:printf("  R = ");
	scanf_s("%d", &R);
	if (R < 0 || R > 255)
	{
		printf("  【错误】RGB 应在 0 ~ 255 之间！请重新输入\n");
		goto RE1;
	}
	
	// 获取 G 值
RE2:printf("  G = ");
	scanf_s("%d", &G);
	if (G < 0 || G > 255)
	{
		printf("  【错误】RGB 应在 0 ~ 255 之间！请重新输入\n");
		goto RE2;
	}
	
	// 获取 B 值
RE3:printf("  B = ");
	scanf_s("%d", &B);
	if (B < 0 || B > 255)
	{
		printf("  【错误】RGB 应在 0 ~ 255 之间！请重新输入\n");
		goto RE3;
	}
}


//【函数】获取用户输入的 十六进制 值，并检测是否在 [#000000, #FFFFFF] 区间内
void Enter_HEX(void)
{
	printf("  请按示例中的格式输入待转换的十六进制颜色值，\n  区间：[#000000, #FFFFFF]\n");
	printf("  示例：#AA,BB,FF\n\n");
RE4:printf("  请输入：#");
	scanf_s("%X,%X,%X", &HEX1, &HEX2, &HEX3);
	printf("\n");

	// 验证输入的值是否正确（由于十六进制输错的情况太多，所以判断输入正确的情况）
	if (HEX1 >= 0 && HEX1 <= 255 && HEX2 >= 0 && HEX2 <= 255 && HEX3 >= 0 && HEX3 <= 255)
	{
		printf("  【校验】您已输入： #%X%X%X \n", HEX1, HEX2, HEX3);
	}
	else
	{
		printf("  【错误】输入的值应在：#000000 ~ #FFFFFF 内，并按照示例格式输入，请重新输入\n");
		goto RE4;
	}
}


//【函数】获取用户输入的 CMYK 值，并检测是否在 [0%, 100%] 区间内
void Enter_CMYK(void)
{
	printf("  请按照提示输入待转换的颜色值，区间：[0%, 100%]\n");

	// 获取 C 值
RE5:printf("  C(%%) = ");
	scanf_s("%f", &C);
	if (C < 0 || C > 100)
	{
		printf("【错误】CMYK 应在 0 ~ 100%% 之间！请重新输入\n");
		goto RE5;
	}

	// 获取 M 值
RE6:printf("  M(%%) = ");
	scanf_s("%f", &M);
	if (M < 0 || M > 100)
	{
		printf("【错误】CMYK 应在 0 ~ 100%% 之间！请重新输入\n");
		goto RE6;
	}

	// 获取 Y 值
RE7:printf("  Y(%%) = ");
	scanf_s("%f", &Y);
	if (Y < 0 || Y > 100)
	{
		printf("【错误】CMYK 应在 0 ~ 100%% 之间！请重新输入\n");
		goto RE7;
	}

	// 获取 K 值
RE8:printf("  K(%%) = ");
	scanf_s("%f", &K);
	if (K < 0 || K > 100)
	{
		printf("【错误】CMYK 应在 0 ~ 100%% 之间！请重新输入\n");
		goto RE8;
	}

	//【校验】
	/*printf("  C：%3.0f %% \n", C);
	printf("  M：%3.0f %% \n", M);
	printf("  Y：%3.0f %% \n", Y);
	printf("  K：%3.0f %% \n", K);
	*/
}


//【函数】获取用户输入的 HSV 值，并检测是否在 [ , ] 区间内
void Enter_HSV(void)
{
	printf("  请按照提示输入待转换的颜色值\n");

	// 获取 H 值（Hue，色调）
	printf("  H(0~360) = ");
RE9:scanf_s("%d", &H);
	if (H < 0 || H > 360)
	{
		printf("  【错误】H 应在 0 ~ 255 之间！请重新输入\n");
		goto RE9;
	}

	// 获取 S 值（Saturation，饱和度）
	printf("  S(0~100) = ");
RE10:scanf_s("%d", &S);
	if (S < 0 || S > 100)
	{
		printf("  【错误】S 应在 0 ~ 100 之间！请重新输入\n");
		goto RE10;
	}

	// 获取 V 值（Value，明度）
	printf("  V = ");
RE11:scanf_s("%d", &V);
	if (V < 0 || V > 100)
	{
		printf("  【错误】RGB 应在 0 ~ 100 之间！请重新输入\n");
		goto RE11;
	}
}


//【函数】（1）将 RGB 值转换为十六进制的色值
void RGB_to_HEX(void)
{	
	// 将 RGB 值以十六进制的形式输出
	printf("\n  该颜色的十六进制值为：");
	
	// R 值
	if (R < 16)
	{
		printf("#0%X", R);		// 小于10的值转换后要补零（即：0A、0B、0C、0D、0E、0F）
	}
	else
	{
		printf("#%X", R);
	}

	// G 值
	if (G < 16)
	{
		printf("0%X", G);		// 小于10的值转换后要补零（即：0A、0B、0C、0D、0E、0F）
	}
	else
	{
		printf("%X", G);
	}
	
	// B 值
	if (B < 16)
	{
		printf("0%X\n\n", B);	// 小于16的值转换后要补零（即：0A、0B、0C、0D、0E、0F）
	}
	else
	{
		printf("%X\n\n", B);
	}
}


//【函数】（2）将 RGB值 转换为 CMYK 值
void RGB_to_CMYK(void)
{
	float R0;
	float G0;
	float B0;

	float Rf;	// 浮点型 R
	float Gf;	// 浮点型 G
	float Bf;	// 浮点型 B

	// 需要强制转换类型，否则R、G、B的数据全部丢失（如果不转换，运行后发现之后的运行均为0）
	Rf = (float)R;
	Gf = (float)G;
	Bf = (float)B;

	// 根据查找到的 RGB 转换为 CMYK 的公式：
	R0 = Rf / 255;
	G0 = Gf / 255;
	B0 = Bf / 255;
	K = (1 - max_num(R0, G0, B0));
	C = (1 - R0 - K) / (1 - K);
	M = (1 - G0 - K) / (1 - K);
	Y = (1 - B0 - K) / (1 - K);
	
	// 转换为百分比形式（CMYK是百分比）
	C = C * 100;
	M = M * 100;
	Y = Y * 100;
	K = K * 100;

	// 输出结果（注意：“%”需要连续打两个才能输出）
	printf("\n  该颜色的 CMYK 值为：\n");
	printf("  C：%3.0f %% \n", C);		
	printf("  M：%3.0f %% \n", M);
	printf("  Y：%3.0f %% \n", Y);
	printf("  K：%3.0f %% \n", K);
}


//【函数】（3）将 RGB 值转换为 HSV 值
void RGB_to_HSV(void)
{
	float R0;
	float G0;
	float B0;
	float C_max;
	float C_min;
	float C_delta;

	float Rf;	// 浮点型 R
	float Gf;	// 浮点型 G
	float Bf;	// 浮点型 B

	// 需要强制转换类型，否则R、G、B的数据全部丢失（如果不转换，运行后发现之后的运行均为0）
	Rf = (float)R;
	Gf = (float)G;
	Bf = (float)B;

	// 根据查找到的 RGB 转换为 HSV 的公式：
	R0 = Rf / 255;
	G0 = Gf / 255;
	B0 = Bf / 255;

	C_max = max_num(R0, G0, B0);
	C_min = min_num(R0, G0, B0);
	C_delta = C_max - C_min;

	// H 的计算
	if (C_delta == 0)
	{
		H = 0;
	}
	else if (C_max == R0)
	{
		H = 60 * (((G0 - B0) / C_delta) + 0);
	}
	else if (C_max == G0)
	{
		H = 60 * (((B0 - R0) / C_delta) + 2);
	}
	else if (C_max == B0)
	{
		H = 60 * (((R0 - G0) / C_delta) + 4);
	}
	else
	{
		printf("\n【Error: H】\n");
	}
	
	// S 的计算
	if (C_max == 0)
	{
		S = 0;
	}
	else if (C_max != 0)
	{
		S = C_delta / C_max;
	}
	else
	{
		printf("\n【Error: S】\n");
	}

	// V 的计算
	V = C_max;

	// H 是角度，不用乘100。但是有可能出现负数（某两个色值相等时，上面的if语句会有两个同时成立，就会算出两个值）
	if (H < 0)
	{
		H = H + 360;
	}
	// 转化为百分比形式
	S = S * 100;
	V = V * 100;

	// 输出结果（注意：“%”需要连续打两个才能输出）
	printf("  该颜色的 HSV 值为：\n");
	printf("  HSV = (%f°, %f%%, %f%%)\n", H, S, V);
	printf("\n  分行显示便于拷贝：\n");
	
	// FEN HANG
	printf("\n  该颜色的 HSV 值为：\n");
	printf("  H：%3.0f ° \n", H);
	printf("  S：%3.0f %% \n", S);
	printf("  V：%3.0f %% \n", V);
	printf("\n");
}


//【函数】（4）将 十六进制 色值转换为 RGB 值
void HEX_to_RGB(void)
{
	//int Rx=0;		// 十六进制 R 值
	//int Gx=0;		// 十六进制 G 值
	//int Bx=0;		// 十六进制 B 值

	// 利用进位制原理将用户输入的一个6位十六进制数（数组）转化为三个2位的十六进制数（Rx、Gx、Bx）
	//Rx = HEX[0] * 16 + HEX[1];	//（前两位）
	//Gx = HEX[2] * 16 + HEX[3];	//（中间两位）
	//Bx = HEX[4] * 16 + HEX[5];	//（后两位）

	// 输出结果
	printf("\n  该颜色的 RGB 值为：\n");
	printf("  RGB = (%d, %d, %d)\n", HEX1, HEX2, HEX3);
	printf("\n  分行显示便于拷贝：\n");
	printf("  R = %d\n", HEX1);
	printf("  G = %d\n", HEX2);
	printf("  B = %d\n", HEX3);
	printf("\n");
}


//【函数】（5）将 CMYK 值转换为 RGB 值
void CMYK_to_RGB(void)
{
	R = 255 * (100 - C) * (100 - K) / 10000;
	G = 255 * (100 - M) * (100 - K) / 10000;
	B = 255 * (100 - Y) * (100 - K) / 10000;

	printf("  该颜色的 RGB 值为：\n");
	printf("  RGB = (%d, %d, %d)\n", R, G, B);
	printf("\n  分行显示便于拷贝：\n");
	printf("  R = %d \n", R);
	printf("  G = %d \n", G);
	printf("  B = %d \n", B);
	printf("\n");
}


//【函数】（6）将 HSV 值转换为 RGB 值
void HSV_to_RGB(void)
{

}


//【函数】返回最大值（CMYK需要）
float max_num(float a, float b, float c)
{
	float t;
	if (a > b)
	{
		t = a;
		a = b;
		b = t;
	}

	if (a > c)
	{
		t = a;
		a = c;
		c = t;
	}

	if (b > c)
	{
		t = b;
		b = c;
		c = t;
	}

	// 由小到大排列：（min）a < b < c（max）；
	return c;
}


//【函数】返回最小值（HSV需要）
float min_num(float a, float b, float c)
{
	float t;
	if (a > b)
	{
		t = a;
		a = b;
		b = t;
	}

	if (a > c)
	{
		t = a;
		a = c;
		c = t;
	}

	if (b > c)
	{
		t = b;
		b = c;
		c = t;
	}

	// 由小到大排列：（min）a < b < c（max）；
	return a;
}