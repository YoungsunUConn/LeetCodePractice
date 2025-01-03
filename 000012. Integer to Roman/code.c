char* intToRoman(int num) {
    int digit,i, cnt = 0;
    const int roman_table[7] = {'I','V','X','L','C','D','M'};
    char reversed_ret[20]; // put in reverse and flip it later.
    char *ret;
    int ret_idx = 0;
    

    while(num > 0) {
        digit = num % 10;

        if( digit == 4) {
            // Add 'IV'
            reversed_ret[ret_idx++] = roman_table[cnt+1];
            reversed_ret[ret_idx++] = roman_table[cnt];
        }
        else if ( digit == 9) {
            // Add 'IX'
            reversed_ret[ret_idx++] = roman_table[cnt+2];
            reversed_ret[ret_idx++] = roman_table[cnt];
        }
        else if( digit >= 5) {
            for( i = 0 ; i < digit - 5 ; i ++) {
                reversed_ret[ret_idx++] = roman_table[cnt];
            }
            reversed_ret[ret_idx++] = roman_table[cnt+1];
        }
        else if( digit < 5) {
            for( i = 0 ; i < digit ; i ++) {
                reversed_ret[ret_idx++] = roman_table[cnt];
            }
        }

        cnt += 2;
        num /= 10;
    }
    ret = (char*)malloc(sizeof(char) * (ret_idx+1));
    for( i = 0 ; i < ret_idx ; i++) {
        ret[ret_idx-i-1] = reversed_ret[i];
    }
    ret[ret_idx] = 0;
    return ret;
}
