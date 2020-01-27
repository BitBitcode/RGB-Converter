# 超级色值计算器


![编写语言](https://img.shields.io/badge/Language-C-E02080)
![问题](https://img.shields.io/badge/Issue-1/1-FF0000)
![版本](https://img.shields.io/badge/Version-1.1.2-0078D7)
![运行环境](https://img.shields.io/badge/Platform-Windows-0078D7)
![开发工具](https://img.shields.io/badge/IDE-Visual_Studio-9153CC)
![开源许可](https://img.shields.io/badge/License-MIT-45BF17)


## 关  于
  + 复杂的颜色模式总是让人迷惑，繁琐的转换计算也时常消耗精力。为什么不让计算机来完成呢，你只专注于配色，这个也就项目就应运而生；
  + 基于 *C语言* 构建的控制台应用程序，用来转换不同的颜色模式，支持RGB转换为十六进制、CMYK和HSV，以及十六进制、CMYK和HSV转换为RGB；
  + 应用仍处在开发阶段，将不定期更新；
  + 欢迎 [`Fork`](https://github.com/login?return_to=%2FBitBitcode%2FRGB-Converter) 与 [`Pull Request`](https://github.com/BitBitcode/RGB-Converter/pulls)，如有 BUG 还请在 [`Issues`](https://github.com/BitBitcode/RGB-Converter/issues) 中提出，谢谢！


## 更新日志
   + V1.1.2 质量更新
  <br>`2020.1.27`  `内部版本号：1.1.2.20200127_Beta`
    - 解决了十六进制转RGB模式下输入时需要加入逗号的问题，提升用户体验
    - 但尚无法校验用户是否输入了非十六进制数，并且如果输入了非十六进制数会导致程序卡死
  
  + V1.1.1 质量更新
  <br>`2020.1.26`  `内部版本号：1.1.1.20200126_Beta`
    - 向 .exe 文件中添加了版本号、版权信息、文件名等信息
    - 修复了 RGB 转 CMYK 中，RGB = (0, 0, 0)  时输出错误的问题
    - 修复了 CMYK 转 RGB 中，变量对应错误导致输出全部为 (0, 0, 0) 的问题
    
  + V1.1.0 功能更新
  <br> `时间：2020.1.25`  `内部版本号：1.1.0.20200125_Beta`
    - 加入了更换主题的功能
    - 优化了部分代码

  + V1.0.1 测试版发布
  <br>`时间：2020.1.25`  `内部版本号：1.0.1.20200125_Beta`
    - 六种转换全部制作完成
    - 加入了“帮助与提示”和“关于”
    - 尚有一个输入问题，已列在 [`Issues`](https://github.com/BitBitcode/RGB-Converter/issues) 中

  + V1.0.0 预览版发布
  <br>`时间：2020.1.23`  `内部版本号：1.1.0.20200125_Alpha`
    - 初步完成了整体框架与操作逻辑的编写
    - 完成了前两个转换的编写


## 运行环境
  + 系统平台：Microsoft Windows
  + 体系架构：x64（尚未测试32位系统的兼容性）
  + 应用类型：控制台应用程序
  + 安装说明：无需安装，即点即用
  + 系统要求：
    - CPU：1.6 GHz 及以上
    - 内存：2 G 及以上
    - Windows 7 或更高版本
    - x64 体系架构


## 更多信息
### 开发计划
  + 第一阶段：构建简单的的控制台应用程序，菜单是输入交互模式；
  + 第二阶段：考虑添加一定的复杂菜单与操作逻辑，增加美观性，并优化现有的功能；
  + 第三阶段：真正意义上实现一个有界面的小软件（暂缓）；

### 开发说明
  + **函数及其作用**
      ```
      void Welcome(void);	    // 欢迎界面
      void Enter_RGB(void);       // 获取 RGB 值
      void Enter_HEX(void);       // 获取 十六进制颜色
      void Enter_CMYK(void);      // 获取 CMYK 值
      void Enter_HSV(void);       // 获取 HSV 值
      void RGB_to_HEX(void);      //（1）将RGB转换为十六进制颜色
      void RGB_to_CMYK(void);     //（2）将RGB转换为CMYK
      void RGB_to_HSV(void);      //（3）将RGB转换为HSV
      void HEX_to_RGB(void);      //（4）将十六进制颜色转换为RGB
      void CMYK_to_RGB(void);     //（5）将CMYK转换为RGB
      void HSV_to_RGB(void);      //（6）将HSV转换为RGB
      void Help(void);            // 帮助与提示
      void About(void);           // 关  于
      float max_num(float a, float b, float c);	  // 获取最大值
      float min_num(float a, float b, float c);	  // 获取最小值 
      ```

  + **色彩模式转换原理**
    <br>资料均来源于互联网，主要参考自以下网站：
    * [RapidTables](https://www.rapidtables.com/convert/color/index.html)
    * [CSDN](https://www.csdn.net/) 论  坛
    * [Baidu](https://www.baidu.com/) 百  度


## 版权信息
  + 转载请注明作者
  + Copyright © 2019-2020 BitBitcode.
