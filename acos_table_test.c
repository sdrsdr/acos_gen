#include <stdint.h>
#include <math.h>
#include <stdio.h>
#include "acos_table.h"

#define FLOAT float //for declarations
#define FFLOAT double //for printf and friends

#define PI ((FLOAT)3.1415926) //dont use M_PI for portability

const FLOAT grad2rad_f = PI/180;

static inline FLOAT grad2rad (uint16_t a) { return  a*grad2rad_f; } ;
static inline FLOAT rad2grad (FLOAT a) { return  a/grad2rad_f; } ;

static inline FLOAT intrep2f (uint16_t i) { return  ((FLOAT)i)/((FLOAT)50000.0); } //turn back uint16 to FLOAT 

void gen(void);

const FLOAT step = 1.0/50000.0;
int main(void) {
	//gen (); return 0;
	uint16_t preva=-1;
	FLOAT cos_v=1;
	while (cos_v>=0) {
		uint16_t cos_vi=cos_v2cos_vi(cos_v);
		uint16_t a=acos_table(cos_vi);
		if (a!=preva || cos_v==0) {
			FFLOAT a_chk=(FFLOAT)rad2grad(acos(cos_v));
			printf("a=%u cos=%.5f(%u) acos(a):%.5f ",(unsigned)a,(FFLOAT)cos_v,(unsigned)cos_vi,a_chk);
			if(cos_v!=0 && cos_v!=1) {
				printf(" p:%.5f n:%.5f ",(FFLOAT)rad2grad(acos(cos_v+step)),(FFLOAT)rad2grad(acos(cos_v-step)));
			}
			preva=a;
			if ((uint16_t)a_chk!=a) {
				if ((uint16_t)(a_chk+0.05)!=a) {
					printf("!!! ERRORR !!!\n");
					return -1;
				} else {
					printf("OK?\n");
					//printf("!!! WARN! !!!\n");
				}
			} else {
				printf("OK!\n");
			}
		}
		cos_v-=step;
		if (cos_v<0 && cos_v!=-step) cos_v=0; 
	}
	return 0;
}

void gen() {
	uint16_t cos_vi=50000;
	uint16_t prev= 0;
	while (cos_vi) {
		FLOAT cos_v=intrep2f(cos_vi);
		FLOAT a=rad2grad(acos(cos_v));
		uint16_t ai=(uint16_t)a;
		if (ai!=prev) {
			printf("%u, // a=%u(%.5f) cos=%.5f\n",(unsigned)cos_vi,(unsigned)ai,(FFLOAT)a,(FFLOAT)cos_v);
			prev=ai;
		} 
		cos_vi--;
	}
}
