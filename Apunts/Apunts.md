# FIB-AC

Los chinos van a dominar el mundo (y el primo informático también).

## Mesures:

| Nom | Símbol | 2^x | 10^x | Error |
|-|-|-|-|-|
| Kilo | K | 2^10 -> 1024 | 10^3 -> 1000 | 2,4% |

Depende de dónde esté un KB son 1000 (DISCO) o 1024 (RAM). Los vendedores no te engañan, depende de lo que compres es una medida u otra.

> "Debuga esto. Mal rollo."

> "Cada bombilla consume un huevo... Y un huevo por mucho... Mal rollo."

- Cost `Mida, complexitat i cost social i econòmic`
- Rendimient `1/temps de la feina`
- Consum `Energia consumida per unitat de temps`
- Fiabilitat `Tolerància a falles i temps per reparar-ho`

### Cost econòmic:
Abaixar els preus: `Deslocalitzar. Fàbriques a Xina, Mèxic...`

### Cost ambiental:
Contaminació al construïr i destruïr.

> Breaking Bad no es nada comparado con el negocio de los residuos.

### Cost social:
Addicions, estrès, contacte humà...

### Cost humà:
Salut, dignitat, igualtat...
> Coltan

## **Tecnologia de fabricació:**

`S'utilitza la tecnologia CMOS`

> La mida d'integració s'ha anat reduint amb el temps.
>
> Primer processador: 1971 Intel 4004 -> 10 micrometres
>
> 2018 S'esta arribant al límit de mida -> 7 nm

*Transparències*

## Evaluació del cost:

- Factor de yield: Fracció de circuits correctes.

- Cost de un circuit integrat = (Cost del die + cost de test + cost de eempaquetat + test final) / Yeld final (test)

- Cost de die (dau)

*Acabar*


## Latència:

Temps des de que solicitem una dada fins a poder-ne disposar.

- Ping a www.unizar.es: `10 ms`
- Ferrari F1 (a 300 Km/h): `3.600 s`
- Camión Volvo FH16 (a 100 Km/h): `10.800 s`

## Ample de banda:
Bytes transmesos per unitat de temps.
- ADSL a 20 Mb/s: `2,5 MB/s`
- Ferrari F1 (transportando 1 HD de 1 TB): `277,8 MB/s`
- Camión Volvo FH16 (transportando 34.000 HD de 1 TB): `3,15 TB/s`

## Temps de resposta vs productivitat:

## Rendiment d'un processador:
```
1/rendiment = Temps d'execució =  N*CPI*Tcicle
```

#### *Canvis de compilador:*
Canvia N i CPI

#### *Canvis en el llenguatge màquina (LM):*
Canvia N i compilador

#### *Organització:*
Canvia CPI i Tcicle (Nombre de cachés...)

#### *Tecnologia:*
Canvia Tcicle (Mida transistors...)

#### **Altres mètriques:**
> **MIPS:** Milions d'instruccios per segon
>
> **MFLOPS:** Milions de operacions en coma flotant per segon

## Llei d'Amdahl:

Com millora el sistema amb canvis: més disc, més processadors...
Pot fer empitjorar una altra part del sistema.

```
Ganància = Toriginal/Tmillorat = 1 / (1-fm+fm/gm)
```

## Llenguatge màquina:
`x86`

Per compilar:
```
... --32 ...
```

MMX: A diverses dades se li pot fer una pantalla:
> Instruccions de 32 bits -> < 8b 8b 8b 8b > Sumar-li 3 a totes les 4 dades.

MIPS (RISC) | x86 (CISC)
-|-
A(Rb) | A(Rb,Ri,s)
M[A+Rb] | M[A+Rb+Ri*s]
Longitud fixa | Longitud variable

### Tipus de dades:
#### Enters:
> 1,2,4 bytes
>
> (MOVB, MOVW, MOVL)

#### Reals (coma flotant):
> 4,8,10 bytes
>
> Tipus simple...

### Operacions:
- Aritmètiques/logiques
- Transferència (memòria-registre)
- Saltos

### Rangs

Naturals|de|a
-|-|-
Bytes|0|255
Word|0|65.535
Longword|0|4.294967.215

Enters|de|a
-|-|-
Bytes|-128|127
Word|-32.768|32.767
Longword|-2.147.483.648|2.147.483.647

Reals|de|a
-|-|-
Precissió simple|1,18·10^-38|3,40·10^38
Precissió doble|2,23·10^-308|1,79·10^308
Precissió doble extesa|3,37·10^-4932|1,18·10^4932

### Modes de direccionament:

#### - Inmediat:
`$19, $0x2A`

#### - Registre:
`%eax, %ah, %esi`

#### - Memòria:
`D(Rb, Ri, s) -> M[Rb+Ri*s+D]`

### Codificació:
```
OPcode(1-2bytes) Mode(1byte) SIB(1byte) Desplaçament(1,2,4bytes) Inmediat(1,2,4bytes)
```

**SIB (Scale Index Base):**
```
S (2 bits) Índex*1,2,4,8
I (3 bits) Registre Índex
B (3 bits) Registre Base
```
### Instruccions de moviment de dades:
> `MOVx op1,op2` Compia
>
> `MOVSxy op1, op2` Exten signe
>
> `MOVZxy op1, op2` Exten zeros

[]()

> `LEAL op1, op2` Calcula direcció del op1 i la mou a op2
>
> `IMUL` -> 32 bits `IMULL` -> 64 bits (Concatenant registres %EDX%EAX)
>
> `CLTD` %EDX%EAX, s'exten el signe de %EAX a %EDX
>
> `IDIVL op1` %EAX <- Quocient %EDX <- residu
