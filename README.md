# win32diskimager
A Windows tool for writing images to USB sticks or SD/CF cards

用于将 img 镜像写入 USB 或 SD/CF 卡的 Windows 工具

代码 Fork 自 https://sourceforge.net/p/win32diskimager/code/ci/master/tree/src/

源码已经 5 年没更新了，我去掉了一些没用的文件

保证代码能用 Qt 5.15.2 + msvc 2019 x64 在 win10 下正常编译
![ui](https://github.com/abc881858/win32diskimager/assets/320155/8ae6d77f-69c1-47b2-8ff7-c5a09847efc4)

------

如果编译正常，在 QtCreator 内运行提示

```shell
02:09:39: Starting C:\Users\Administrator\Desktop\Git\win32diskimager\build\debug\DiskImager.exe...
02:09:39: The process failed to start. Either the invoked program "C:\Users\Administrator\Desktop\Git\win32diskimager\build\debug\DiskImager.exe" is missing, or you may have insufficient permissions to invoke the program.
```

请关闭 QtCreator，用管理员权限重新启动

