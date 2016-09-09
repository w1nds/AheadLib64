format MS64 COFF
;===================================================
;" X64 HOOK PiaoYun/P.Y.G"
;" bbs.chinapyg.com "
;" www.dllhook.com "
;===================================================

public AsmFunc1
public AsmFunc2


AsmFunc1:
		mov rax,rcx
		retn          
               

AsmFunc2:
               	xchg rax,rcx
		jmp rax     
