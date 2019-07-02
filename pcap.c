#include<stdio.h>

int pack4chars(char c1, char c2, char c3, char c4)
{
    return ((int)(((unsigned char)c1) << 24)
            |  (int)(((unsigned char)c2) << 16)
            |  (int)(((unsigned char)c3) << 8)
            |  (int)((unsigned char)c4));
}

int main(void)
{
	int i,count = 0;	
	//FILE *fp;
	
 	unsigned int len,d;
	
	unsigned char ch,ch1,ch2,ch3,ch4,data[10000];
	
	char c;
	
	//fp = fopen("test.pcap","r");
	
	
	for(i=0;i<24;i++)
	{
		ch = getchar();
	}
	
	while(1)
	{
		c = getchar();
		
		if(c==EOF)
		{
		 	break;
		}	
		
		for(i=0;i<7;i++)
		{
			ch = getchar();
		}
	
		ch1 = getchar();
		ch2 = getchar();
		ch3 = getchar();
		ch4 = getchar();
	
		len = pack4chars(ch4,ch3,ch2,ch1);
	
		count++;
	
		//printf("Packet no:%d,length:%d\n",count,len);
	
		for(i = 0;i<4;i++)
		{
			ch = getchar();
		}
	
		for(i = 0;i<len;i++)
		{
			ch = getchar();
			data[i] = ch;
			
			if(i==len-1)
			{
				if(data[12]==8 && data[13]==6)
				{
					//printf("This is an ARP Packet\n")
					
					if(data[21]==1)
					{
						printf("Packet no:%d,length:%d ",count,len);
						printf("Who has %d.%d.%d.%d? Tell %d.%d.%d.%d\n",data[38],data[39],data[40],data[41],data[28],data[29],data[30],data[31]);
					}
					
					else if(i>=59 && data[21]!=1)
					{
						printf("Packet no:%d,length:%d ",count,len);
						printf("%d.%d.%d.%d is at %02X:%02X:%02X:%02X:%02X:%02X\n",data[28],data[29],data[30],data[31],data[22],data[23],data[24],data[25],data[26],data[27]);
					}
				}
			}
			
			/*d = (unsigned int)ch;
			printf("%X ",d);*/
		}
		
	}
	
	printf("There are %d packets\n",count);
	
	return 0;
}
