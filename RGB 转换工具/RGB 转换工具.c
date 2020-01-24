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
int H;
int S;
int V;


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
	printf("加载中 。。。 。。。\n");
	int m;										// 菜单选择变量

	//int RGB_Value[3] = {0, 0, 0};				// 数组传入参数后输出有问题，已删除部分代码
	
	system("mode con cols=60 lines=50");		// 设置窗口大小（单位：行）
	system("title RGB 转换工具（V1.0.0）");		// 设置标题
	
	Welcome();									//【调用】欢迎界面
	system("pause");

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

		printf("输入对应数字以选择：\n");
	RE: scanf_s("%d", &m);
		switch (m)
		{
		case 1:
			system("cls");	// 清屏
			printf("当前位置：RGB → #FFFFFF \n");
			printf("------------------------------------------------------------\n\n");
			Enter_RGB();	//【调用】获取 RGB 值
			RGB_to_HEX();	//【调用】RGB 转换为 十六进制 的函数
			system("pause");
			break;

		case 2:
			system("cls");	// 清屏
			printf("当前位置：RGB → CMYK \n");
			printf("------------------------------------------------------------\n\n");
			Enter_RGB();	//【调用】获取 RGB 值
			RGB_to_CMYK();	//【调用】RGB 转换为 CMYK 的函数
			system("pause");
			break;

		case 3:
			system("cls");	// 清屏
			printf("当前位置：RGB → HSV \n");
			printf("------------------------------------------------------------\n\n");
			Enter_RGB();	//【调用】获取 RGB 值
			RGB_to_HSV();	//【调用】RGB 转换为 HSV 的函数
			system("pause");
			break;

		case 4:
			system("cls");	// 清屏
			printf("当前位置：#FFFFFF → RGB \n");
			printf("------------------------------------------------------------\n\n");
			Enter_HEX();	//【调用】获取 十六进制 值
			HEX_to_RGB();	//【调用】十六进制 转换为 RGB 的函数
			system("pause");
			break;

		case 5:
			system("cls");	// 清屏
			printf("当前位置：CMYK → RGB \n");
			printf("------------------------------------------------------------\n\n");
			Enter_CMYK();	//【调用】获取 CMYK 值
			CMYK_to_RGB();	//【调用】CMYK 转换为 RGB 的函数
			system("pause");
			break;

		case 6:
			system("cls");	// 清屏
			printf("当前位置：HSV → RGB \n");
			printf("------------------------------------------------------------\n\n");
			Enter_HSV();	//【调用】获取 HSV 值
			HSV_to_RGB();	//【调用】HSV 转换为 RGB 的函数
			system("pause");
			break;

		case 0:
			goto Exit;
			break;

		default:
			printf("请输入有效数字！\n");
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
	printf("请按照提示输入待转换的颜色值，区间：[0, 255]\n");
	
	// 获取 R 值
	printf("R = ");
RE1:scanf_s("%d", &R);
	if (R < 0 || R > 255)
	{
		printf("【错误】RGB 应在 0 ~ 255 之间！请重新输入\n");
		goto RE1;
	}
	
	// 获取 G 值
	printf("G = ");
RE2:scanf_s("%d", &G);
	if (G < 0 || G > 255)
	{
		printf("【错误】RGB 应在 0 ~ 255 之间！请重新输入\n");
		goto RE2;
	}
	
	// 获取 B 值
	printf("B = ");
RE3:scanf_s("%d", &B);
	if (B < 0 || B > 255)
	{
		printf("【错误】RGB 应在 0 ~ 255 之间！请重新输入\n");
		goto RE3;
	}
}


//【函数】获取用户输入的 十六进制 值，并检测是否在 [#000000, #FFFFFF] 区间内
void Enter_HEX(void)
{
	printf("请按示例中的格式输入待转换的十六进制颜色值，区间：[#000000, #FFFFFF]\n");
	printf("示例：#AA,BB,FF\n\n");
RE4:printf("  请输入：#");
	scanf_s("%X,%X,%X", &HEX1, &HEX2, &HEX3);
	

	// 校验输入
	if (HEX1 < 0 && HEX1 > 165)
	{
		printf("【错误】输入的值应在：#000000 ~ #FFFFFF 内，请重新输入");
		goto RE4;
	}
	else
	{
		printf("【校验】已输入： #%X", HEX1);
	}

	if (HEX2 < 0 && HEX2 > 165)
	{
		printf("【错误】输入的值应在：#000000 ~ #FFFFFF 内，请重新输入");
		goto RE4;
	}
	else
	{
		printf("【校验】已输入： #%X", HEX2);
	}

	if (HEX3 < 0 && HEX3 > 165)
	{
		printf("【错误】输入的值应在：#000000 ~ #FFFFFF 内，请重新输入");
		goto RE4;
	}
	else
	{
		printf("【校验】已输入： #%X", HEX3);
	}
}


//【函数】获取用户输入的 CMYK 值，并检测是否在 [0%, 100%] 区间内
void Enter_CMYK(void)
{

}


//【函数】获取用户输入的 HSV 值，并检测是否在 [ , ] 区间内
void Enter_HSV(void)
{

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

	float t=0;

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

}


//【函数】（4）将 十六进制 色值转换为 RGB 值
void HEX_to_RGB(void)
{
	int Rx=0;		// 十六进制 R 值
	int Gx=0;		// 十六进制 G 值
	int Bx=0;		// 十六进制 B 值

	// 利用进位制原理将用户输入的一个6位十六进制数（数组）转化为三个2位的十六进制数（Rx、Gx、Bx）
	//Rx = (HEX/16)HEX % 16;	//（前两位）
	//Gx = HEX * 16 + HEX;	//（中间两位）
	//Bx = HEX * 16 + HEX;	//（后两位）

	// 输出结果
	printf("\n  该颜色的 CMYK 值为：\n");
	printf("  RGB = (%d, %d, %d)\n", Rx, Gx, Bx);
	printf("\n  分行显示便于拷贝：\n");
	printf("  R = %d\n", Rx);
	printf("  G = %d\n", Gx);
	printf("  B = %d\n", Bx);
}


//【函数】（5）将 CMYK 值转换为 RGB 值
void CMYK_to_RGB(void)
{

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