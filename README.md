# AheadLib64
x64 dll hijacking tool(like AheadLib)


仿照Aheadlib做的64位的版本。
由于默认vs编译器不支持x64的内联汇编。所以使用了obj文件。


obj文件源码是obj.asm文件。

写个例子 说下 转发的原理：
1. 原始是call [0x405000];
2.进入劫持函数
void MyFunc()
{
	AsmFunc1();
	AsmFunc2((INT64)RealFuncAddr);
} 
3.
//这里只是保存一下第一个参数到rax
AsmFunc1:
		mov rax,rcx
		retn  
		
		
4.
//让rax指向真正的 eip(rcx是第一个参数) 还原第一个参数，跳到原始函数执行
AsmFunc2:
        xchg rax,rcx
		jmp rax  
		
5.返回的时候是先返回到 AsmFunc2 下面 再返回到 原始调用处的下面


实际情况自己找个DLL劫持下走一遍就清晰了。
 