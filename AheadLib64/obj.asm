format MS64 COFF
;===================================================
;===================================================

public AsmFunc1
public AsmFunc2


AsmFunc1:
		mov rax,rcx
		retn          
               

AsmFunc2:
               	xchg rax,rcx
		jmp rax     
