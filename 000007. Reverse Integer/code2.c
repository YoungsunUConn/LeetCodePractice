int reverse(int x){
    int rev_x = 0, copy_x;
    int i, j, digit, rev_digit, len, return_flag = 0;

    char comp_val[11] = "214748364 ";


    if( x == 0) return 0; 
    comp_val[9] = '7' + (x < 0);
    
    // remove zeros at the end
    while( x % 10 == 0) { x /= 10; }

    copy_x = x;

    digit = 1;
    rev_digit = 1;
    len = 1;
    
    // find len
    for(i = 0 ; len < 10 && copy_x / 10 != 0 ; i ++, len ++) {

        int curr_digit = (copy_x % 10) * ((x > 0) ? 1:-1);
        
        if( return_flag == 0 && comp_val[i] - 48 < curr_digit ) {
            return_flag = -1;
        }
        else if( return_flag == 0 && comp_val[i] - 48 > curr_digit ) {
            return_flag = 1;
        }
        copy_x /= 10;
        rev_digit *= 10;
    }
    
    // if out of range
    if(len == 10 && return_flag < 0) {
        return 0;
    }
    
    // if not, calculate a rev value.
    for( i = 0 ; i < len ; i ++ ) {
        
        rev_x += (x % 10) * rev_digit;

        rev_digit /= 10;
        x /= 10;   
    }
    return rev_x;

}
