// RGB 转换工具#include<stdio.h>

#include<stdio.h>

main()
{
	int R;
	int G;
	int B;

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
