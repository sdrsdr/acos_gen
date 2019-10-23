#pragma once
#include <stdint.h>

//cos_v must be in range 0 to 1.0  inclusive
static inline uint16_t cos_v2cos_vi(float cos_v) {
	return cos_v*50000;
}

//clipping, full range -1 to +1  using acos_table 
uint16_t acos_i(float  cos_v);

//cos_v must be in range 0 to 1.0  inclusive
uint16_t acos_table(uint16_t cos_vi);
