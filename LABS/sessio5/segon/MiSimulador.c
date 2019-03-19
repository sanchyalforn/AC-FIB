#include "CacheSim.h"

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */




/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al començar cada un dels tests.
 * */

int TAG[128];
int v[128];

void init_cache ()
{
    totaltime=0.0;
	/* Escriu aqui el teu codi */
    for (int i = 0; i < 128; ++i)
	    v[i] = 0;

}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address)
{
	/*
	tam = 12 bits
	tam_lin = 7 bits
	offset = 5 bits
	*/
	
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
        
	byte = address & 0x001F; //5 bits finals
	bloque_m = address >> 5; 

	tag = address >> 12;
	linea_mc = bloque_m & 0x007F; //7 bits

	miss = !v[linea_mc] || TAG[linea_mc] != tag;
	if (!v[linea_mc] &&  miss) v[linea_mc] = 1; 
	if (miss) {
        tag_out = tag;
        tag[linea_mc] = tag;
    }
	replacement = miss && tag_out == tag;

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
  
  
}
