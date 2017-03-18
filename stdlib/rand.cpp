#include <stdlib.h>
#include <stdint.h>
//ChaCha20 pRNG
uint32_t seed[] = {
    0x629102ea,
    0x4975d940,
    0x5f38e808,
    0x93dc408e,
    0x310d8a7,
    0x13dfd36a,
    0xf231d746,
    0x6c55e3f6,
    0x3d5fb58f,
    0x18a6688d,
    0xce961cbc,
    0xbfab9c86,
    0x366766b1,
    0xcd5856e8,
    0xdb0c3687,
    0x82a27f5e
};
int index = 0;
void chacha20() {
    uint32_t x[16];
    for(int i=0;i<16;i++)
        x[i] = seed[i];
    auto rotate=[](uint32_t v, uint32_t c) -> uint32_t {
        return (v << c) | (v >> (32 - c));
    };
    auto quarter=[&x, rotate](int a, int b, int c, int d) -> void {
        x[a] += x[b];
        x[d] ^= x[a];
        x[d] = rotate(x[d], 16);
        x[c] += x[d];
        x[b] ^= x[c];
        x[b] = rotate(x[b], 12);

        x[a] += x[b];
        x[d] ^= x[a];
        x[d] = rotate(x[d], 8);
        x[c] += x[d];
        x[b] ^= x[c];
        x[b] = rotate(x[b], 7);
    };
    for(int i=0;i<10;i++) {
        quarter(0, 4, 8,12);
        quarter(1, 5, 9,13);
        quarter(2, 6,10,14);
        quarter(3, 7,11,15);
        quarter(0, 5,10,15);
        quarter(1, 6,11,12);
        quarter(2, 7, 8,13);
        quarter(3, 4, 9,14);
    }
    for(int i=0;i<16;i++) {
        x[i] += seed[i];
        seed[i] = x[i];
    }
    index=0;
}
int rand() {
    if(index == 16)
        chacha20();
    return (int)(seed[index++]&0x7FFFFFFF);
}
void srand(unsigned int sed) {
    seed[0]=0x61707865; //expa
    seed[1]=0x3320646e; //nd 3
    seed[2]=0x79622d32; //2-by
    seed[3]=0x6b206574; //te k
    seed[4]=0x344cbe69;
    seed[5]=0xe549fedf;
    seed[6]=0x3606ae57;
    seed[7]=0xf8b072f2;
    seed[8]=0x3c98c18b;
    seed[9]=0xe50c7103;
    seed[10]=0xe9753b30;
    seed[11]=0x82b37384;
    seed[12]=0;
    seed[13]=0;
    seed[14]=sed;
    seed[15]=sed;
    chacha20();
}
