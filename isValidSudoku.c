int char2int(char a)
{
    int res=-1;
    switch (a)
    {
    case '0':
        res=0;
        break;
    case '1':
        res=1;
        break;
    case '2':
        res=2;
        break;
    case '3':
        res=3;
        break;
    case '4':
        res=4;
        break;
    case '5':
        res=5;
        break;
    case '6':
        res=6;
        break;
    case '7':
        res=7;
        break;
    case '8':
        res=8;
        break;
    case '9':
        res=9;
        break;   
    default:
        break;
    }
    return res;
}
bool isVaildNUM(char *x)
{
    int flags[10]={0};
    for (size_t i = 0; i < 9; i++)
    {
        char tem= x[i];
        int x= char2int(tem);
        if(x==-1) continue;
        if (flags[x]==1)
        {
            return false;
        }
        else
        {
            flags[x]=1;
        }
    }
    return true;
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    char *pvaild=(char *)malloc(sizeof(char)*9);
    //逐行检查
    for (size_t i = 0; i < boardSize; i++)
    {
        for (size_t j = 0; j < boardSize; j++)
        {
            pvaild[j]=board[i][j];
        }
        if(isVaildNUM(pvaild)==false) return false;
    }
    
    //逐列检查
    for (size_t j = 0; j < boardSize; j++)
    {
        for (size_t i = 0; i < boardSize; i++)
        {
            pvaild[i]=board[i][j];
        }
        if(isVaildNUM(pvaild)==false) return false;
    }
    
    //方块检查
    for (size_t x = 0; x < 3; x++)
    {
        for (size_t a = 0; a < 3; a++)
        {
            int k=0;
            for (size_t i = 0; i < 3; i++)
            {
                for (size_t j = 0; j < 3; j++)
                {
                    pvaild[k++]=board[i+x*3][j+a*3];
                }
            }
            if(isVaildNUM(pvaild)==false) return false;
        }
    }
    return true;
}