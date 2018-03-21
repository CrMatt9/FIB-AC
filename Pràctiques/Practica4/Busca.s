 .text
	.align 4
	.globl Buscar
	.type Buscar,@function
Buscar:
        # Aqui viene vuestro codigo
        pushl %ebp
        movl %esp, %ebp

        # Reservem lloc per les variables locals.
        subl $16, %esp


        movl $-1, -4(%ebp)      # trobat = -1
        movl $0, -16(%ebp)      # low = 0
        movl $0, -8(%ebp)       # mid = 0

        #opcio 1
        movl $-1, %eax          # -1
        addl 24(%ebp), %eax     # N = -1+N

                # opcio 2 (per si de cas)
                # movl 24(%ebp), %eax
                # subl $1, %eax


        movl %eax, -12(%ebp)    # high = N-1

while:  movl -12(%ebp), %eax    # high
        movl -16(%ebp), %edx    # low

        cmpl %edx, %eax         # high - low -> saltar si l
        jg fiwhile              # low > high

        pushl 8(%ebp)           # @v
        pushl 20(%ebp)          # Struct X
        pushl 16(%ebp)
        pushl 12(%ebp)

        leal -8(%ebp), %eax
        pushl %eax              # &mid
        leal -12(%ebp), %eax
        pushl %eax              # &high
        leal -16(%ebp), %eax
        pushl %eax              # &low

        call BuscarElemento     # Anem a la funció

        addl $28, %esp          # esborrem els paràmetres

        movl %eax, -4(%ebp)     # trobat <- return

if:     cmpl $0, %eax           # if (trobat >= 0) ignorarem el salt
        jl while                # sempre retornem al while

fiwhile: movl -4(%ebp), %eax    # return trobat
         movl %ebp,%esp         # retornem punters
         popl %ebp         
         ret
