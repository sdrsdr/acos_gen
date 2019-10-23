#include "acos_table.h"


static uint16_t acos_lookup[89]={
49992, // a=1(1.02488) cos=0.99984
49969, // a=2(2.01771) cos=0.99938
49931, // a=3(3.01045) cos=0.99862
49878, // a=4(4.00331) cos=0.99756
49809, // a=5(5.00965) cos=0.99618
49726, // a=6(6.00103) cos=0.99452
49627, // a=7(7.00289) cos=0.99254
49513, // a=8(8.00332) cos=0.99026
49384, // a=9(9.00305) cos=0.98768
49240, // a=10(10.00256) cos=0.98480
49081, // a=11(11.00215) cos=0.98162
48907, // a=12(12.00210) cos=0.97814
48718, // a=13(13.00257) cos=0.97436
48514, // a=14(14.00373) cos=0.97028
48296, // a=15(15.00130) cos=0.96592
48063, // a=16(16.00035) cos=0.96126
47815, // a=17(17.00093) cos=0.95630
47552, // a=18(18.00306) cos=0.95104
47275, // a=19(19.00327) cos=0.94550
46984, // a=20(20.00212) cos=0.93968
46679, // a=21(21.00007) cos=0.93358
46359, // a=22(22.00059) cos=0.92718
46025, // a=23(23.00072) cos=0.92050
45677, // a=24(24.00077) cos=0.91354
45315, // a=25(25.00105) cos=0.90630
44939, // a=26(26.00184) cos=0.89878
44550, // a=27(27.00083) cos=0.89100
44147, // a=28(28.00093) cos=0.88294
43730, // a=29(29.00233) cos=0.87460
43301, // a=30(30.00062) cos=0.86602
42858, // a=31(31.00081) cos=0.85716
42402, // a=32(32.00088) cos=0.84804
41933, // a=33(33.00111) cos=0.83866
41451, // a=34(34.00180) cos=0.82902
40957, // a=35(35.00120) cos=0.81914
40450, // a=36(36.00166) cos=0.80900
39931, // a=37(37.00148) cos=0.79862
39400, // a=38(38.00100) cos=0.78800
38857, // a=39(39.00054) cos=0.77714
38302, // a=40(40.00040) cos=0.76604
37735, // a=41(41.00084) cos=0.75470
37157, // a=42(42.00042) cos=0.74314
36567, // a=43(43.00115) cos=0.73134
35966, // a=44(44.00163) cos=0.71932
35355, // a=45(45.00055) cos=0.70710
34732, // a=46(46.00146) cos=0.69464
34099, // a=47(47.00144) cos=0.68198
33456, // a=48(48.00082) cos=0.66912
32802, // a=49(49.00145) cos=0.65604
32139, // a=50(50.00057) cos=0.64278
31466, // a=51(51.00003) cos=0.62932
30783, // a=52(52.00011) cos=0.61566
30090, // a=53(53.00108) cos=0.60180
29389, // a=54(54.00037) cos=0.58778
28678, // a=55(55.00115) cos=0.57356
27959, // a=56(56.00089) cos=0.55918
27231, // a=57(57.00130) cos=0.54462
26495, // a=58(58.00130) cos=0.52990
25751, // a=59(59.00121) cos=0.51502
25000, // a=60(60.00000) cos=0.50000
24240, // a=61(61.00063) cos=0.48480
23473, // a=62(62.00075) cos=0.46946
22699, // a=63(63.00068) cos=0.45398
21918, // a=64(64.00071) cos=0.43836
21130, // a=65(65.00115) cos=0.42260
20336, // a=66(66.00104) cos=0.40672
19536, // a=67(67.00069) cos=0.39072
18730, // a=68(68.00040) cos=0.37460
17918, // a=69(69.00049) cos=0.35836
17101, // a=70(70.00001) cos=0.34202
16278, // a=71(71.00050) cos=0.32556
15450, // a=72(72.00103) cos=0.30900
14618, // a=73(73.00070) cos=0.29236
13781, // a=74(74.00104) cos=0.27562
12940, // a=75(75.00114) cos=0.25880
12096, // a=76(76.00011) cos=0.24192
11247, // a=77(77.00065) cos=0.22494
10395, // a=78(78.00069) cos=0.20790
9540, // a=79(79.00053) cos=0.19080
8682, // a=80(80.00047) cos=0.17364
7821, // a=81(81.00084) cos=0.15642
6958, // a=82(82.00076) cos=0.13916
6093, // a=83(83.00054) cos=0.12186
5226, // a=84(84.00049) cos=0.10452
4357, // a=85(85.00091) cos=0.08714
3487, // a=86(86.00095) cos=0.06974
2616, // a=87(87.00092) cos=0.05232
1744, // a=88(88.00112) cos=0.03488
872, // a=89(89.00071) cos=0.01744
};


//clipping, full range -1 to +1 
uint16_t acos_i(float  cos_v) {
	//clip
	if (cos_v>1) cos_v=1;
	else if (cos_v<-1) cos_v=-1;

	//work in cos_v>=0  ranges:
	if (cos_v<0) return 180-acos_table(cos_v2cos_vi(-cos_v));
	return acos_table(cos_v2cos_vi(cos_v));

}


//cos_v must be in range 0 to 1.0  inclusive
uint16_t acos_table(uint16_t cos_vi) {
	uint16_t a; uint16_t *acos_lookup_at;


	if (cos_vi<acos_lookup[44]){
		if (cos_vi<acos_lookup[66]) {
			a=66; acos_lookup_at=acos_lookup+66;
		} else {
			a=44; acos_lookup_at=acos_lookup+44;
		}
	} else {
		if (cos_vi<acos_lookup[21]) {
			a=21; acos_lookup_at=acos_lookup+21;
		} else {
			a=0; acos_lookup_at=acos_lookup;
		}
	}

	while (a<=89) {
		if (cos_vi>*acos_lookup_at) return a;
		a++;acos_lookup_at++;
	}

	return 90;
}
