#include "CacheSim.h"
#include <stdio.h>

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */

typedef struct {
	unsigned int v; // Validesa
	int tag;
} linia_cache;

linia_cache cache[128];

int hit_count;
int miss_count;

/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al començar cada un dels tests.
 * */
void init_cache ()
{
    totaltime=0.0;
	/* Escriu aqui el teu codi */
	int i = 0;
	for (i; i < 128; i++)
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
	unsigned int replacement;  // boolea que indica si es reemplaça una linia valida
	unsigned int tag_out;	   // TAG de la linia reemplaçada
	float t1,t2;		// Variables per mesurar el temps (NO modificar)
	
	t1=GetTime();
	/* Escriu aqui el teu codi */

	
	byte = (address & 0x0000001F);
	bloque_m = (address & 0xFFFFFFE0) >> 5;
	linea_mc = (address & 0x00000FE0) >> 5;
	tag = (address & 0xFFFFF000) >> 12;
	
	
	// Si la dada es vàlida 
	if (cache[linea_mc].v == 1) {
		
		// coincideix el TAG
		if (cache[linea_mc].tag == tag) { 
			++hit_count;
			miss = 0;
			replacement = 0;
		}
		
		// NO coincideix el TAG
		else {
			++miss_count;
			miss = 1;
			replacement = 1;
			tag_out = cache[linea_mc].tag;
			cache[linea_mc].tag = tag;
		}
	}
	
	// Dada no vàlida 
	else {
		++miss_count;
		miss = 1;
		replacement = 0;
		cache[linea_mc].tag = tag;
		cache[linea_mc].v = 1;
	}
        
	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual. També mesurem el temps d'execució
	 * */
	t2=GetTime();
	totaltime+=t2-t1;
	test_and_print (address, byte, bloque_m, linea_mc, tag,
			miss, replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
 	/* Escriu aqui el teu codi */ 
  
	 printf("Num de encerts: %d. Num de fallades: %d\n", hit_count, miss_count);
}
