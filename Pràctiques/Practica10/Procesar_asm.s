.text
	.align 4
	.globl procesar
	.type	procesar, @function
procesar:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi

# Aqui has de introducir el codigo
        xorl %eax, %eax         # i = 0
        movl 8(%ebp), %ebx      # @mata
        movl 12(%ebp), %ecx     # @matb
        movl 16(%ebp), %edi     # @matc
        movl 20(%ebp), %esi     # n
        imull %esi, %esi        # Fusió dels dos bucles (n*n)
        
for:    cmpl %eax, %esi			
        jl fifor               
        movb (%ebx), %dl        # mata[i*n+j]
        subb (%ecx), %dl        # mata[i*n+j] - matb[i*n+j]
        movb %dl, (%edi)        # matc[i*n+j] = mata[i*n+j] - matb[i*n+j]
        
if:     cmpb $0, (%edi)
        jle else                
        movb $255, (%edi)       
        jmp fif
        
else:   movb $0, (%edi)         

fif:    incl %eax              
        incl %ebx               
        incl %ecx               
        incl %edi               
        jmp for
fifor:
# El final de la rutina ya esta programado

	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
