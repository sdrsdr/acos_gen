#include <stdint.h>
//cos must be in range 0 to 1.0  inclusive
static inline uint16_t cos2cos_v(float cos) {
	return cos*50000;
}

uint16_t acos_table(uint16_t cos_v) {

	if (cos_v<=((uint16_t)35355)) goto half; //jump to post 45 deg
	if (cos_v<=((uint16_t)46359)) goto top_mid; //jump to post 22 deg

	if (cos_v>=((uint16_t)49992)) return 1;
	if (cos_v>=((uint16_t)49970)) return 2;
	if (cos_v>=((uint16_t)49931)) return 3;
	if (cos_v>=((uint16_t)49878)) return 4;
	if (cos_v>=((uint16_t)49810)) return 5;
	if (cos_v>=((uint16_t)49726)) return 6;
	if (cos_v>=((uint16_t)49627)) return 7;
	if (cos_v>=((uint16_t)49513)) return 8;
	if (cos_v>=((uint16_t)49384)) return 9;
	if (cos_v>=((uint16_t)49240)) return 10;
	if (cos_v>=((uint16_t)49081)) return 11;
	if (cos_v>=((uint16_t)48907)) return 12;
	if (cos_v>=((uint16_t)48719)) return 13;
	if (cos_v>=((uint16_t)48515)) return 14;
	if (cos_v>=((uint16_t)48296)) return 15;
	if (cos_v>=((uint16_t)48063)) return 16;
	if (cos_v>=((uint16_t)47815)) return 17;
	if (cos_v>=((uint16_t)47553)) return 18;
	if (cos_v>=((uint16_t)47276)) return 19;
	if (cos_v>=((uint16_t)46985)) return 20;
	if (cos_v>=((uint16_t)46679)) return 21;
top_mid:
	if (cos_v>=((uint16_t)46359)) return 22;
	if (cos_v>=((uint16_t)46025)) return 23;
	if (cos_v>=((uint16_t)45677)) return 24;
	if (cos_v>=((uint16_t)45315)) return 25;
	if (cos_v>=((uint16_t)44940)) return 26;
	if (cos_v>=((uint16_t)44550)) return 27;
	if (cos_v>=((uint16_t)44147)) return 28;
	if (cos_v>=((uint16_t)43731)) return 29;
	if (cos_v>=((uint16_t)43301)) return 30;
	if (cos_v>=((uint16_t)42858)) return 31;
	if (cos_v>=((uint16_t)42402)) return 32;
	if (cos_v>=((uint16_t)41934)) return 33;
	if (cos_v>=((uint16_t)41452)) return 34;
	if (cos_v>=((uint16_t)40958)) return 35;
	if (cos_v>=((uint16_t)40451)) return 36;
	if (cos_v>=((uint16_t)39932)) return 37;
	if (cos_v>=((uint16_t)39401)) return 38;
	if (cos_v>=((uint16_t)38857)) return 39;
	if (cos_v>=((uint16_t)38302)) return 40;
	if (cos_v>=((uint16_t)37735)) return 41;
	if (cos_v>=((uint16_t)37157)) return 42;
	if (cos_v>=((uint16_t)36568)) return 43;
	if (cos_v>=((uint16_t)35967)) return 44;

half:
	if (cos_v<=((uint16_t)19537)) goto bottom; //jump to post 67 deg

	if (cos_v>=((uint16_t)35355)) return 45;
	if (cos_v>=((uint16_t)34733)) return 46;
	if (cos_v>=((uint16_t)34100)) return 47;
	if (cos_v>=((uint16_t)33457)) return 48;
	if (cos_v>=((uint16_t)32803)) return 49;
	if (cos_v>=((uint16_t)32139)) return 50;
	if (cos_v>=((uint16_t)31466)) return 51;
	if (cos_v>=((uint16_t)30783)) return 52;
	if (cos_v>=((uint16_t)30091)) return 53;
	if (cos_v>=((uint16_t)29389)) return 54;
	if (cos_v>=((uint16_t)28679)) return 55;
	if (cos_v>=((uint16_t)27960)) return 56;
	if (cos_v>=((uint16_t)27232)) return 57;
	if (cos_v>=((uint16_t)26496)) return 58;
	if (cos_v>=((uint16_t)25752)) return 59;
	if (cos_v>=((uint16_t)25000)) return 60;
	if (cos_v>=((uint16_t)24240)) return 61;
	if (cos_v>=((uint16_t)23474)) return 62;
	if (cos_v>=((uint16_t)22700)) return 63;
	if (cos_v>=((uint16_t)21919)) return 64;
	if (cos_v>=((uint16_t)21131)) return 65;
	if (cos_v>=((uint16_t)20337)) return 66;
bottom:
	if (cos_v>=((uint16_t)19537)) return 67;
	if (cos_v>=((uint16_t)18730)) return 68;
	if (cos_v>=((uint16_t)17918)) return 69;
	if (cos_v>=((uint16_t)17101)) return 70;
	if (cos_v>=((uint16_t)16278)) return 71;
	if (cos_v>=((uint16_t)15451)) return 72;
	if (cos_v>=((uint16_t)14619)) return 73;
	if (cos_v>=((uint16_t)13782)) return 74;
	if (cos_v>=((uint16_t)12941)) return 75;
	if (cos_v>=((uint16_t)12096)) return 76;
	if (cos_v>=((uint16_t)11248)) return 77;
	if (cos_v>=((uint16_t)10396)) return 78;
	if (cos_v>=((uint16_t)9540)) return 79;
	if (cos_v>=((uint16_t)8682)) return 80;
	if (cos_v>=((uint16_t)7822)) return 81;
	if (cos_v>=((uint16_t)6959)) return 82;
	if (cos_v>=((uint16_t)6093)) return 83;
	if (cos_v>=((uint16_t)5226)) return 84;
	if (cos_v>=((uint16_t)4358)) return 85;
	if (cos_v>=((uint16_t)3488)) return 86;
	if (cos_v>=((uint16_t)2617)) return 87;
	if (cos_v>=((uint16_t)1745)) return 88;
	if (cos_v>=((uint16_t)873 )) return 89;
	return 90;
};