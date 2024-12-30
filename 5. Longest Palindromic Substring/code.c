char* longestPalindrome(char* s) {
    
    char* substr = (char*)malloc(sizeof(char) * (strlen(s)+1));
    int max_len = -1;
    int stack_pos = 0;
    int i,j,inc, inc2;
    int len, len2;
    
    
    // minimum length of s = 1
    substr[0] = s[0];
    substr[1] = 0;

    for(i = 0; i < strlen(s); i++) { 
        
        // check odd number of strings
        for(inc = 0; i - (inc+1) >= 0  && i < strlen(s) - (inc+1) ; ) 
        {
            if(s[i-(inc+1)] != s[i+(inc+1)]) {
                break;
            }
            inc += 1;
        }

        // check even number of strings
        for(inc2 = 0 ; i - inc2 >= 0 && i+1 + inc2 < strlen(s) ; ) 
        {
            if(s[i-(inc2)] != s[i+1+(inc2)]) {
                break;
            }
            inc2 += 1;
        }
        
        
        // length of inc: 2 * inc + 1
        // length of inc2: 2 * inc2
        len = 2 * inc + 1;
        len2 = 2 * inc2;
        if(len > len2 && len > max_len) {
            max_len = len;
            
            for(j = 0; j < len; j ++) {
                substr[j] = s[i - inc + j];
            }
            substr[j] = 0;
            
        }
        else if(len2 > len && len2 > max_len) {
            max_len = len2;
            
            for(j = 0; j < len2; j ++) {
                substr[j] = s[i - (inc2-1) + j];
            }
            substr[j] = 0;
        }
    }
    
    return substr;
}
