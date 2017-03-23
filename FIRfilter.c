#define _TI_ENHANCED_MATH_H 1
#include <math.h>
#include <std.h>
#include "FIRfiltercfg.h"
#include "fir.h"

#define Nmask 63
#define MASK_LO 0x0000FFFF
#define MASK_HI 0xFFFF0000

short buffer[64];
short sample_l, sample_r;
int n, k;
int sample;
float sum;

void main()
{
n=0;
MCBSP_enableRcv(hMcbsp1);		
MCBSP_enableXmt(hMcbsp1);			
IER|=0x2000;						
}

void rcv_interrupt()
{
probka = MCBSP_read(hMcbsp1);
sample_r = sample & MASK_LO;
sample_l = (sample & MASK_HI) >> 16;
sum = 0;
buffer[n] = sample_p;
for(k=0; k<N; k++)
{
    sum+=B[k]*buffer[((n-k)&Nmask)];
}
    
n++;
n&=Nmask;
sample_p=sum;
sample=sample_p;

MCBSP_write(hMcbsp1, sample);

}
