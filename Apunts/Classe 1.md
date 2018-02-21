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
1/rendiment = Temps d'execució =  N \* CPI \* Tcicle
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
