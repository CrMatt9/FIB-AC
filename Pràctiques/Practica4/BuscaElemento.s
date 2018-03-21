 .text
	.align 4
	.globl BuscarElemento
	.type BuscarElemento,@function
BuscarElemento:
        # Aqui viene vuestro codigo

        pushl %ebp              # EBP
        movl %esp,%ebp

if:     movl 16(%ebp),%eax      # @mid
        movl (%eax),%eax        # *mid

        movl 32(%ebp),%ecx      # @v
        imul $12,%edx           # Calculem a la posició del vector que indica *mid
        addl %edx,%ecx          # @v[*mid]
        addl $4, %ecx           # @v[*mid].k

        movl 24(%ebp),%edx      # X.k

        cmpl (%ecx),%edx        # X.k == v[*mid].k
        jne else1

        movl (%eax),%eax        # return *mid
        jmp return

else1:  movl 12(%ebp), %ecx     # @high
        movl (%ecx), %ecx       # *high
        cmpl %ecx, %eax         # *mid - high > 0 salto
        jge else2               # else si *mid >= *high

        # Interior if
        movl %ecx, %eax         # *mid = *high
        movl 8(%ebp),%eax       # @low
        addl $1,(%eax)          # (*low)++
        jmp else3


else2:  movl 8(%ebp),%ecx       # @low
        movl (%ecx),%ecx        # *low
        movl %ecx, %eax         # *mid = *low
        movl 12(%ebp),%eax      # high = @ a la que apunta high
        subl $1,(%eax)          # (*high)--


else3:  movl $-1,%eax           # return -1

return: movl %ebp,%esp
        popl %ebp
        ret
