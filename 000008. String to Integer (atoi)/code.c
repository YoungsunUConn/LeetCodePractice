int myAtoi(char* s) {
    int i, inc10, start = 0, end,sign, rounding_val;
    int ret = 0;
    

    // remove space first
    while(s[start] == ' ') {
        start ++;
    }

    // deteremine sign
    if( s[start] == '-') {  
        sign = -1;
        start += 1;
    }
    else if( s[start] == '+') {  
        sign = 1;
        start += 1;
    }
    else if ( (s[start] >= '0' && s[start] <= '9' )) {
        sign = 1;
    }
    else return 0;

    // remove 0 in front of the number
    while(s[start] == '0') {
        start ++;
    }
    
    end = start;
    
    while(s[end] >= '0' && s[end] <= '9') {
        end ++;
    }


    // rounding
    rounding_val = sign * 2147483647 - (sign < 0);
    if( end - start > 10) {
        return rounding_val;
    }
    else if( end - start == 10) {
        // 2147483648
        char lim_val[11] = "214748364 ";
        lim_val[9] = '7' + (sign < 0);

        for( i = start ; i < end ; i ++) {
            if( lim_val[i-start] < s[i] ) {
                return rounding_val;
            }
            else if( lim_val[i-start] > s[i] ) {
                break;
            }
        }
        if( i == end) return rounding_val;
    }

    for ( i = end - 1, inc10 = 0; i >= start ; i -- ) {
        if( inc10 == 0) {
            inc10 = 1;
        } else {
            inc10 *= 10;
        }
        ret += inc10 * (s[i] - '0');
    }
    return ret * sign;
}
