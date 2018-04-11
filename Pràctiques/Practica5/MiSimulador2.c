#include "CacheSim.h"
#include <stdio.h>
/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */
 
#define nvies 2
#define nconjunts 64
 
typedef struct {
	unsigned int v; // bit de validesa
	int tag;
} S_via;

typedef struct { 		// 2 associativa -> 2 vies
	S_via via[nvies];
	unsigned int lru; 	// 0 o 1 
} conjunt;

conjunt cache[nconjunts]; //Caché de 64 conjunts. 
// 4KB/línies de 32B = 128/2 = 64

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
	for (i; i < nconjunts; i++) {
		int j = 0;
		for (j; j < nvies; ++j) {
			cache[i].via[j].v = 0;
		}
	}
}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address)
{
	unsigned int byte;
	unsigned int bloque_m; 
	unsigned int conj_mc;
	unsigned int via_mc;
	unsigned int tag;
	unsigned int miss;	   // boolea que ens indica si es miss
	unsigned int replacement;  // boolea que indica si es reemplaça una linia valida
	unsigned int tag_out;	   // TAG de la linia reemplaçada
	float t1,t2;		// Variables per mesurar el temps (NO modificar)
	
	t1=GetTime();
	/* Escriu aqui el teu codi */
	
	byte = (address & 0x0000001F);				// bit 27 - 31
	bloque_m = address >> 5;					// bit 0 - 26
	conj_mc = (address & 0x000007E0) >> 5;		// bit 21 - 26
	tag = address >> 11;						// bit 0 - 20
	
	
	
	// Hit a la via 0
	if (cache[conj_mc].via[0].tag == tag && cache[conj_mc].via[0].v == 1){
		via_mc = 0;
		++hit_count;
		miss = 0;
		replacement = 0;
		cache[conj_mc].lru = 1;
	}
	// Hit a la via 1
	else if (cache[conj_mc].via[1].tag == tag && cache[conj_mc].via[1].v == 1){
		via_mc = 1;
		++hit_count;
		miss = 0;
		replacement = 0;
		cache[conj_mc].lru = 0;
	}
	
	// Tractem els miss
	else {
		miss = 1;
		++miss_count;
		// Intentem posar-ho a la via 0 si està buida 
		if (cache[conj_mc].via[0].v == 0) { 
			via_mc = 0;
			replacement = 0;
			cache[conj_mc].lru = 1;
			cache[conj_mc].via[via_mc].tag = tag;
			cache[conj_mc].via[via_mc].v = 1;
		}
		
		else if (cache[conj_mc].via[0].tag != tag) { // via 0 plena
			// Si la via 1 està buida ho posem allà
			if (cache[conj_mc].via[1].v == 0) {
				via_mc = 1;
				replacement = 0;
				cache[conj_mc].lru = 0;
				cache[conj_mc].via[via_mc].tag = tag;
				cache[conj_mc].via[via_mc].v = 1;
			}
			
			// Hem de posar-ho al lru substituint un tag
			else {
				replacement = 1;
				
				via_mc = cache[conj_mc].lru;
				tag_out = cache[conj_mc].via[via_mc].tag;
				cache[conj_mc].via[via_mc].tag = tag;
				
				if (via_mc) cache[conj_mc].lru = 0;
				else cache[conj_mc].lru = 1;
			}
		}
	}



	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual. També mesurem el temps d'execució
	 * */
	
	t2=GetTime();
	totaltime+=t2-t1;
	test_and_print2 (address, byte, bloque_m, conj_mc, via_mc, tag,
			miss, replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
 	/* Escriu aqui el teu codi */ 
  
	 printf("Num de encerts: %d. Num de fallades: %d\n", hit_count, miss_count);
}
