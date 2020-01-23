// RGB 转换工具#include<stdio.h>

#include<stdio.h>
#include<stdlib.h>		// system() 函数需要的头文件
#include<Windows.h>

// 定义全局变量
int R;
int G;
int B;

int main()
{
	// 定义变量
	int m;
	char c;
	//int RGB_Value[3] = {0, 0, 0};				// 数组传入参数后输出有问题，已删除部分代码
	
	system("mode con cols=60 lines=50");		// 设置窗口大小
	system("title RGB 转换工具（V1.0.0）");		// 设置标题
	
	printf("                         欢迎使用！                         \n\n");
Start:											// 菜单开始
	for (; ; )
	{
		printf("------------------------- 菜    单 ------------------------- \n");
		printf("\t\t\t1、RGB → #FFFFFF \n");
		printf("\t\t\t2、RGB → CMYK \n");
		printf("\t\t\t3、RGB → HSV \n");
		printf("\t\t\t4、#FFFFFF → RGB \n");
		printf("\t\t\t5、CMYK → RGB \n");
		printf("\t\t\t6、HSV → RGB \n");
		printf("\n");
		printf("\t\t\t9、继续转换 \n");
		printf("\t\t\t0、退    出 \n");
		printf("------------------------------------------------------------\n\n");

		printf("输入对应数字以选择：\n");
	RE: scanf_s("%d", &m);
		switch (m)
		{
		case 1:
			system("cls");	// 清屏
			printf("当前位置：RGB → #FFFFFF \n");
			printf("------------------------------------------------------------\n\n");
			RGB_to_XXX();	// 调用 RGB 转换为 十六进制 的函数
		case 2:
			system("cls");	// 清屏
			printf("当前位置：RGB → CMYK \n");
			printf("------------------------------------------------------------\n\n");
			RGB_to_CMYK();	// 调用 RGB 转换为 CMYK 的函数
		case 3:
			system("cls");	// 清屏
			printf("当前位置：RGB → HSV \n");
			printf("------------------------------------------------------------\n\n");
		case 4:
			system("cls");	// 清屏
			printf("当前位置：#FFFFFF → RGB \n");
			printf("------------------------------------------------------------\n\n");
		case 5:
			system("cls");	// 清屏
			printf("当前位置：CMYK → RGB \n");
			printf("------------------------------------------------------------\n\n");
		case 6:
			system("cls");	// 清屏
			printf("当前位置：HSV → RGB \n");
			printf("------------------------------------------------------------\n\n");
		case 9:
			system("cls");	// 清屏
			goto Start;
		case 0:
			system("cls");	// 清屏
			goto Exit;
		default:
			printf("请输入有效数字！\n");
			goto RE;
		}
	}
Exit:				// 菜单“退出”的确认部分
	{
		printf("是否确认退出？（确认：y，取消：n）\n");
	ER: scanf_s("%c", &c, 1);
		if (c == '\n')
		{
			goto ER;
		}
		else if (c == 'y')
		{
			printf("程序已退出，关闭窗口即可 \n");
			goto End;
		}
		else if (c == 'n')
		{
			goto Start;
		}
		else
		{
			printf("请输入“y”或“n”！\n");
			goto ER;
		}
	}

End:return 0;		// 程序结束，主函数返回
}


// 将 RGB 转换为 十六进制 的函数
int RGB_to_XXX()
{
	int i;

	printf("请按照提示输入待转换的颜色值（0~255）：\n");
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
	printf("该颜色的十六进制值为：# %X %X %X \n", R, G, B);		//  将 RGB 的值以十六进制的形式输出

}

// 将 RGB 转换为 CMYK 的函数
int RGB_to_CMYK()
{

}
