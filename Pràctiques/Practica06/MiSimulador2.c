// PRÀCTICA 6 - AC
// Caché amb Copy Back + Write Allocate
// Ariadna de Arriba i Marc Casellas

#include "CacheSim.h"
#include <stdio.h>

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */
 
typedef struct {
	unsigned int v; 	// Bit validesa
	int tag;			// Etiqueta guardada a la cache
	unsigned int d;		// Bit de dirty
} linia_cache;

linia_cache cache[128];

int hit_count;			// Contador hits
int miss_count;			// Contador misses
int write_count;		// Contador escriptures

/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al començar cada un dels tests.
 * */
void init_cache () {
	int i;
	for (i = 0; i < 128; i++){
		cache[i].v = 0; // Posem tots els bits de validesa a 0
		cache[i].d = 0; // Posem tots els dirty a 0
	}	
	hit_count = miss_count = 0;
	write_count = 0;
}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address, unsigned int LE) {

	unsigned int byte;
	unsigned int bloque_m; 
	unsigned int linea_mc;
	unsigned int tag;
	
	unsigned int miss;
	unsigned int lec_mp;
	unsigned int mida_lec_mp;
	unsigned int esc_mp;
	unsigned int mida_esc_mp;
	unsigned int replacement;
	unsigned int tag_out;
	
	lec_mp = 0;
	esc_mp = 0;
	mida_lec_mp = 0;
	mida_esc_mp = 0;
	replacement = 0;

	byte = (address & 0x0000001F);				// bit 27 - 31
	bloque_m = address >> 5;					// bit 0 - 26
	linea_mc = (address & 0x00000FE0) >> 5;		// bit 20 - 26
	tag = address >> 12;						// bit 0 - 19
	
	// Dada vàlida a la caché
	if (cache[linea_mc].v == 1) {
		
		// Coincideix el TAG --> HIT
		if (cache[linea_mc].tag == tag) { 
			
			miss = 0;
			++hit_count;
			
			// LECTURA: No es llegeix de MP
			
			// ESCRIPTURA: Només escrivim a la MC -> Dirty = 1
			if (LE) {
				cache[linea_mc].d = 1;
			}
		}
		
		// NO coincideix el TAG --> MISS
		else {
			miss = 1; 
			++miss_count;
			replacement = 1; // Reemplaçar en tots els casos (dada antiga vàlida)
			tag_out = cache[linea_mc].tag;
			cache[linea_mc].tag = tag;
			
			if (cache[linea_mc].d) { // Si el que reemplaçem està a dirty hem de guardar el bloc a MP
				esc_mp = 1;
				mida_esc_mp = 32;
				cache[linea_mc].d = 0;
				++write_count;
			}
			
			// Tant si llegim com si escrivim, nomès ho farem a MC
			
			// LECTURA
			lec_mp = 1;
			mida_lec_mp = 32;
			
			// ESCRIPTURA
			if (LE) cache[linea_mc].d = 1; // Posem el dirty a 1
		}
	}
	
	// Dada no valida --> MISS (primer accés)
	else {
		miss = 1; // És miss i no haurem de reemplaçar
		++miss_count;
		
		// Llegim el bloc de la MP
		lec_mp = 1;
		mida_lec_mp = 32;
		cache[linea_mc].v = 1; // Validem la data
		cache[linea_mc].tag = tag;
			
		if (LE) cache[linea_mc].d = 1;	// Si modifiquem: Dirty = 1
	}

	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual
	 * */
	test_and_print (address, LE, byte, bloque_m, linea_mc, tag,
			miss, lec_mp, mida_lec_mp, esc_mp, mida_esc_mp,
			replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final () {
	printf("Hits: %d\nMisses: %d\nEscriptures MP: %d\n", hit_count, miss_count, write_count);
}
