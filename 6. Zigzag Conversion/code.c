char* convert(char* s, int numRows) {
    int i, j, pos, firstInterval, secondInterval, TotalInterval, inc;
    char *retStr = (char*)malloc(sizeof(char) * strlen(s)+1);
    int retStrIdx;


    
    if(numRows == 1) {
        memcpy(retStr,s,sizeof(char)*(strlen(s)+1));
        return retStr;
    }
    
    TotalInterval = 2 * numRows - 2; // Sum of intervals for each cycle should be this number
    inc = 0;

    retStrIdx = 0;
    for( i = 0; i < numRows ; i ++) {
        pos = i;
        if( i == 0 || i == numRows-1) {
            firstInterval = TotalInterval;    
            secondInterval = TotalInterval;
        }
        else {
            firstInterval = TotalInterval - inc;
            secondInterval = inc;
        }
        
        j = 0;
        while (pos < strlen(s)) {
            
            retStr[retStrIdx++] = s[pos];

            if( j++ % 2 == 0) pos += firstInterval;
            else pos += secondInterval;
        }

        inc += 2;
    }

    retStr[strlen(s)] = 0;

    return retStr;
}
