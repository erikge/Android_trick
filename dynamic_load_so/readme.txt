问题：项目中遇到这样的情况，同一功能（如编解码）需要有不同的实现（如软编解、硬编解，ffmpeg、openMax等不同实现），不同的实现需要动态加载。有些最终安装包只需要某一个单独实现，有些需要多个实现，这样分成不同的动态库可以自由按需组合，减小安装包的体积。程序运行过程中也可以按照需要灵活动态加载多个模块。

方案：

User(MainSo: java + so) --> 动态加载模块(Struct: struct.so) --> 功能实现模块(ImplA: impla.so)
    ImplA只是一个举例，可以有多个实现
    
用法：
    MainSo只知道Struct，并不知道Struct背后有多少个ImplX。
    ImplA也只知道Struct，不知道功能使用者MainSo的信息。
    1、编译Struct
    2、编译ImplA，ImplA依赖Struct的路径已配置好，无需copy
    3、编译MainSo，MainSo依赖Struct的路径已配置好，无需copy
    4、将用到的功能实现so，如ImplA copy到MainSo中
    5、MainSo的java代码中load相关功能实现so，如ImplA，然后使用相关功能
