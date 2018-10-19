#include<reg52.h>	 //sbit ø…“‘Œª—∞÷∑£¨
#include<intrins.h>
void delayms(int n)
{
int i,j;		
for(i=1;i<=n;i++)
for(j=1;j<=112;j++)
;
}
void main()
{
	while(1)
	{
		int i;
		P1=0Xfe;
		for(i=1;i<=8;i++)
		{
			 P1=_crol_(P1,1);
			 delayms(1000);
		}
	}
}