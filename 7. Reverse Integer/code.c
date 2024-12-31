int reverse(int x){
    char buffer[12]; // 2 to the power of 31 has ten digits (10 + 1 (sign) + 1 (end NULL))
    char rev_buffer[12];

    char max_val[12];
    char min_val[12];

    int rev_x;
    int i, j;


    // atoi() non-standard
    sprintf(buffer, "%d", x);
    sprintf(max_val, "%d", 2147483647);
    sprintf(min_val, "%d", -2147483647 - 1);
    
    if( buffer[0] == '-') {
        rev_buffer[0] = '-';
    }
    for( i = (buffer[0] == '-'), j = strlen(buffer) - 1 ; i < strlen(buffer) ; i++, j--) {
        rev_buffer[j] = buffer[i];
    }


    if(buffer[0] == '-' && strlen(rev_buffer) == strlen(min_val)) {
        for( i = 1 ; i < strlen(rev_buffer) ; i++ ) {
            if(rev_buffer[i] > min_val[i]) {
                return 0;
            }
            else if(rev_buffer[i] < min_val[i]) {
                break;
            }
        }
    }
    else if (buffer[0] != '-' && strlen(rev_buffer) == strlen(max_val)) {
        for( i = 0 ; i < strlen(rev_buffer) ; i++ ) {
            if(rev_buffer[i] > max_val[i]) {
                return 0;
            }
            else if(rev_buffer[i] < max_val[i]) {
                break;
            }
        }
    }
    sscanf(rev_buffer, "%d",&rev_x);
    return rev_x;
}
