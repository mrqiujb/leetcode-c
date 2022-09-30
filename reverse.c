int reverse(int x){
    int flag=0;//符号位取出
    if(x==0) return 0;
    else if(x<0)
    {
        flag=1;
        if(x==-pow(2,31)) return 0;
        x=-x;
    }
    uint8_t stack[32];
    uint8_t i=0;
    while (x!=0)
    {
        uint8_t tem=x%10;
        stack[i]=tem;
        i++;
        x=x/10;
    }
    int res=0;
    int n=0;
    for (int j = i-1; j >=0; j--)
    {
        //负数 最大为-2^31
        if(flag==1)
        {
            if(stack[j]*pow(10,n)>pow(2,31)||(res+stack[j]*pow(10,n))>pow(2,31)) return 0;
        }
        else
        {
            if(stack[j]*pow(10,n)>pow(2,31)-1||(res+stack[j]*pow(10,n))>pow(2,31)-1) return 0;
        }
        res+=stack[j]*pow(10,n);
        n++;
    }
    if(flag==1) res*=-1;
    return res;
}