.text
	.align 4
	.globl procesar
	.type	procesar, @function
	zero: .byte 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	
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
       
for:    
	cmpl %esi, %eax
	jge fifor               
	movdqu (%ebx), %xmm0  	# mata[valor] 
	movdqu (%ecx), %xmm1    # matab[valor] 
	psubb %xmm1, %xmm0     	# %xmm0 = matb[]-mata[]
	movdqu %xmm0, (%edi)    # matc[] = %xmm0
	
	movdqu zero, %xmm2    	# posem a 0  	
	pcmpgtb %xmm2, %xmm0    # %xmm0 - %xmm2 -> o 0 o 255
							
	movdqu %xmm0, (%edi)   	# assignem al pixel
	
	# Incrementem en 16
	addl $16, %eax         
	addl $16, %ebx          
	addl $16, %ecx          
	addl $16, %edi          
	jmp for
	
fifor:

# El final de la rutina ya esta programado

	emms	# Instruccion necesaria si os equivocais y usais MMX
	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
