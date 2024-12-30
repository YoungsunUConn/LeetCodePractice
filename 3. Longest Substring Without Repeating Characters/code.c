int lengthOfLongestSubstring(char* s) {
    int j;
    int max_count = 0;
    int count = 0;
    int prev_chars[128] = {0,};



    // dvdf
    int min_idx = 0; 

    for(j = 0 ; j < strlen(s); j ++)  {
        if( prev_chars[s[j]] > min_idx) {
            if( max_count < count) {
                max_count = count;
            }


            count = j - prev_chars[s[j]];
            min_idx = prev_chars[s[j]];
            
        }
        
        count ++;
        
        prev_chars[s[j]] = j + 1;

    }
    if( max_count < count) {
        max_count = count;
    }
    return max_count;
}
