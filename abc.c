#define _TI_ENHANCED_MATH_H 1
#include <math.h>
#include <std.h>
#include "abccfg.h"
#include "fir.h"

#define Nmask 63
#define MASK_LO 0x0000FFFF
#define MASK_HI 0xFFFF0000

short bufor[64];
short probka_l, probka_p;
int n, k;
int probka;
float sum;

void main()
{
n=0;
MCBSP_enableRcv(hMcbsp1);		
MCBSP_enableXmt(hMcbsp1);			
IER|=0x2000;						
}

void przerwanie_lcv()
{
probka = MCBSP_read(hMcbsp1);
probka_p = probka & MASK_LO;
probka_l = (probka & MASK_HI) >> 16;
sum = 0;
bufor[n] = probka_p;
for(k=0; k<N; k++)
{
    sum+=B[k]*bufor[((n-k)&Nmask)];
}
    
n++;
n&=Nmask;
probka_p=sum;
probka=probka_p;

MCBSP_write(hMcbsp1, probka);

}