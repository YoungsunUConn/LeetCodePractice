int romanToInt(char* s) {
    int i;
    int sum = 0;

    for( i = 0 ; i < strlen(s) ; i ++) {
        switch(s[i]) {
            case 'M':
                sum += 1000;
                break;
            case 'D':
                sum += 500;
                break;
            case 'C':
                if( i+1 < strlen(s) && (s[i+1] == 'M' || s[i+1] == 'D')) sum -= 100;
                else sum += 100;
                break;
            case 'L':
                sum += 50;
                break;
            case 'X':
                if( i+1 < strlen(s) && (s[i+1] == 'L' || s[i+1] == 'C')) sum -= 10;
                else sum += 10;
                break;
            case 'V':
                sum += 5;
                break;
            case 'I':
                if( i+1 < strlen(s) && (s[i+1] == 'V' || s[i+1] == 'X')) sum -= 1;
                else sum += 1;
                break;
        }
    }
    return sum;
}
