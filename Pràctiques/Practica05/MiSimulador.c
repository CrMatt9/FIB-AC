#include "CacheSim.h"
#include <stdio.h>

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */

typedef struct {
	unsigned int v; 	// Bit validesa
	int tag;			// Etiqueta guardada a la cache
} linia_cache;

linia_cache cache[128];

int hit_count;			// Contador hits
int miss_count;			// Contador misses

/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al comen�ar cada un dels tests.
 * */
void init_cache ()
{
    totaltime=0.0;

	int i;
	for (i = 0; i < 128; i++)
		cache[i].v = 0; // Posem tots els bits de validesa a 0
		
	hit_count = miss_count = 0;
}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address)
{
	unsigned int byte;
	unsigned int bloque_m; 
	unsigned int linea_mc;
	unsigned int tag;
	unsigned int miss;	   // boolea que ens indica si es miss
	unsigned int replacement;  // boolea que indica si es reempla�a una linia valida
	unsigned int tag_out;	   // TAG de la linia reempla�ada
	float t1,t2;		// Variables per mesurar el temps (NO modificar)
	
	t1=GetTime();
	
	byte = (address & 0x0000001F);				// bit 27 - 31
	bloque_m = address >> 5;					// bit 0 - 26
	linea_mc = (address & 0x00000FE0) >> 5;		// bit 20 - 26
	tag = address >> 12;						// bit 0 - 19


	
	
	// Dada valida
	if (cache[linea_mc].v == 1) {
		
		// coincideix el TAG --> HIT
		if (cache[linea_mc].tag == tag) { 
			++hit_count;
			miss = 0;
			replacement = 0;
		}
		
		// NO coincideix el TAG --> MISS
		else {
			++miss_count;
			miss = 1;
			replacement = 1;
			tag_out = cache[linea_mc].tag;
			cache[linea_mc].tag = tag;
		}
	}
	
	// Dada no valida --> MISS (primer acces)
	else {
		++miss_count;
		miss = 1;
		replacement = 0;
		cache[linea_mc].tag = tag;
		cache[linea_mc].v = 1;
	}
        
	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual. Tamb� mesurem el temps d'execuci�
	 * */
	t2=GetTime();
	totaltime+=t2-t1;
	test_and_print (address, byte, bloque_m, linea_mc, tag,
			miss, replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
	printf("Num d'encerts: %d\nNum de fallades: %d\n", hit_count, miss_count);
}
