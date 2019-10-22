#include <stdint.h>
#include <math.h>
#include <stdio.h>

#define FLOAT float //for declarations
#define FFLOAT double //for printf and friends

#define PI ((FLOAT)3.1415926) //dont use M_PI for portability

const FLOAT grad2rad_f = PI/180;

static inline FLOAT grad2rad (uint16_t a) { return  grad2rad_f*a; } ;

static inline uint16_t f2intrep (FLOAT f) { return  f*50000; } //fit enoug of FLOAT intto uint16

void gen(void);

//cos must be in range 0 to 1.0  inclusive
extern uint16_t acos_table(uint16_t cos_v);

int main(void) {
	gen (); return 0;
	return 0;
}

void gen() {
	for (uint16_t a=1; a<=89; a++) {
		FLOAT v=cos(grad2rad(a));
		uint16_t v_i=f2intrep(v);
		printf("%u, // a=%u cos=%.5f\n",(unsigned)v_i,(unsigned)a,(FFLOAT)v);
	}
}