#include <stdio.h>

//判断是否相同
int cmp(const char *str1,const char *str2)
{
    while(*str1 == *str2)
    {
        if(*str1 == '\0' || *str2 == '\0')
            break;
        str1++;
        str2++;
    }
    return *str1=='\0'&&(*str2=='\0'||*str2==' ');
}

int main()
{
	char data[15],buf[1000010];
	//输入数据
	gets(data);
	gets(buf);
	//处理单词头
	data[0]=tolower(data[0]);

	int times=0,pos=-1;
	int bufi=0,len_buf;

    //计算buf长度
	len_buf=strlen(buf);

	//buf全小写
	for(bufi=0;bufi<len_buf;bufi++)
	{
	    buf[bufi]=tolower(buf[bufi]);
	}

	bufi=0;
	while(bufi<len_buf)
	{
	    //跳到单词开头
	    while(buf[bufi]==' ')
	    {
	        bufi++;
	    }
	    //比较
	    if(cmp(data,buf+bufi))
	    {
	        if(-1==pos)
	        {
	            pos=bufi;
	        }
	        times++;
	    }
	    //跳到单词末尾的下一个字符
	    while(isalpha(buf[bufi]))
	    {
	        bufi++;
	    }
	}

	0==times?printf("-1"):printf("%d %d",times,pos);
	return 0;
}
