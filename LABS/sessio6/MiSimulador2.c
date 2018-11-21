#include "CacheSim.h"
#include <stdio.h>

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */




 int cache[128];
 int valid[128];
 int dirty[128];

 int n_hit;
 int n_miss;

/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al comen�ar cada un dels tests.
 * */
void init_cache () {
    int i;
    for (i = 0; i < 128; ++i){
	    valid[i] =  0;
	    dirty[i] =  0;
    }
    n_hit  = 0;
    n_miss = 0;
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

	/* Escriu aqui el teu codi */

    linea_mc    = (address & 0x00000FE0) >> 5;
    bloque_m    = (address & 0xFFFFFFE0) >> 5;
    byte        = (address & 0x0000001F);
    tag 	    = (address & 0xFFFFF000) >> 12;
    miss	    = 0;
    replacement = 0;
    
    if (!LE){
        //READ
	    if (valid[linea_mc]){
	        if (cache[linea_mc] == tag){
	        	//Hit lectura
	            miss = 0;
	            replacement = 0;
	            tag_out = 0;
	            lec_mp = 0;
	            mida_lec_mp = 0;
	            esc_mp = 0;
	            mida_esc_mp = 0;
	        }
	        else{
	        	//Miss de lectura
	            miss = 1;
	            tag_out = cache[linea_mc];
	            replacement = 1;
	            cache[linea_mc] = tag;
	            lec_mp = 1;
	            mida_lec_mp = 32;
	            if(dirty[linea_mc]){
	            	esc_mp = 1;
	            	mida_esc_mp = 32;
	            	dirty[linea_mc] = 0;
	        	}
	        	else{
	            	esc_mp = 0;
	            	mida_esc_mp = 0;
	        	}
	        }
	    }
	    else{
	        miss = 1;
	        replacement = 0;
	        tag_out = 0;
	        cache[linea_mc] = tag;
	        valid[linea_mc] = 1;
	        lec_mp = 1;
	        mida_lec_mp = 32;
	        esc_mp = 0;
	        mida_esc_mp = 0;
	    }
	}
	else{
		if (valid[linea_mc]){
	        if (cache[linea_mc] == tag){
	        	//Hit escriptura
	            miss = 0;
	            replacement = 0;
	            tag_out = 0;
	            lec_mp = 0;
	            mida_lec_mp = 0;
	            esc_mp = 0;
	            mida_esc_mp = 0;
	            if(!dirty[linea_mc]) dirty[linea_mc] = 1;
	        }
	        else{
	            miss = 1;
	            tag_out = cache[linea_mc];
	            replacement = 1;
	            cache[linea_mc] = tag;
	            lec_mp = 1;
	            mida_lec_mp = 32;

	           	if(dirty[linea_mc]){
	            	esc_mp = 1;
	            	mida_esc_mp = 32;
	        	}
	        	else{
	            	esc_mp = 0;
	            	mida_esc_mp = 0;
	            	dirty[linea_mc] = 1;
	        	}
	        }
	    }
	    else{
	        miss = 1;
	       	cache[linea_mc] = tag;
	        valid[linea_mc] = 1;
	        replacement = 0;
	        tag_out = 0;
	        lec_mp = 1;
	        mida_lec_mp = 32;
	        esc_mp = 0;
	        mida_esc_mp = 0;
	        dirty[linea_mc] = 1;
	    }
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

	//printf("Miss: %d\n", n_miss);
	//printf("Hit: %d\n", n_hit);

}

