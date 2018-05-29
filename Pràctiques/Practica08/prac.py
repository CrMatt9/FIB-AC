# ALDO FUSTER TURPIN
# Nota: x**y es x elevado a y

# Notación científica
# >>> 1.1
# 1.1

# >>> 1.1e0
# 1.1          # 1.1 * 10**0
# >>> 1.1e3
# 1100.0       # 1.1 * 10**3

# >>> 8e-2
# 0.08         # 8 * 10**-2



def easy():
	# nombre de files i columnes
	N = int(input("N:"))

	# nombre d'operacions en coma flotant
	op_cf = N**3 * 2
	# print(op_cf) # debug info

	while (True):
		t_exe = float(input("t_exe:"))
		mflops = op_cf / ((10**6) * t_exe)
		print("N: {}, t_exe: {} -> mflops. {}".format(N, t_exe, mflops))


def complex(file_name, N):
	with open(file_name, "r") as f:
		print("arxiu: {}".format(file_name))
		print("N: {}".format(N))
		op_cf = N**3 * 2
		my_list =[]
		b = False
        
		ms_segons = 0
        
		for i in range (0,9):
		
			for line in f:
				# print(line)
				for c in line:
					if (c == "="):
						b = True
						continue # salta tot el que hi ha per sota del for i torna a entrar
					if (b):
						my_list.append(c)
			# print(my_list) # debug info
			ms_segons += float("".join(my_list).strip())
			# print(ms_segons) # debug info
			if i == 0:
				print("segons inst: {}".format(ms_segons* (10**-3)))
		mitjana = ms_segons/10.0 

		segons = mitjana * (10**-3)
		print("segons: {}".format(segons))

		mflops = op_cf / ((10**6) * segons)
		print("MFLOPS: {}".format(mflops))
		print("_" * 50)
		print("\n")
        
    

# complex("2_t_6_ijk.txt", 6)
# complex("2_t_6_jki.txt", 6)
# complex("2_t_6_kij.txt", 6)
    
complex("2_t_256_ijk.txt", 256)
complex("2_t_256_jki.txt", 256)
complex("2_t_256_kij.txt", 256)

complex("2_t_512_ijk.txt", 512)
complex("2_t_512_jki.txt", 512)
complex("2_t_512_kij.txt", 512)

complex("2_t_1024_ijk.txt", 1024)
complex("2_t_1024_jki.txt", 1024)
complex("2_t_1024_kij.txt", 1024)



complex("5_t_256_ijk.txt", 256)
complex("5_t_256_jki.txt", 256)
complex("5_t_256_kij.txt", 256)

complex("5_t_512_ijk.txt", 512)
complex("5_t_512_jki.txt", 512)
complex("5_t_512_kij.txt", 512)

complex("5_t_1024_ijk.txt", 1024)
complex("5_t_1024_jki.txt", 1024)
complex("5_t_1024_kij.txt", 1024) 
