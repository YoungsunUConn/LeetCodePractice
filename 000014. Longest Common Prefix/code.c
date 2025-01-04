char* longestCommonPrefix(char** strs, int strsSize) {
    int i,j,common_idx=0;
    // lowercase only
    char *common = (char*)malloc(sizeof(char) * 201);
    int pos = 0;
    while(pos < strlen(strs[0])) {

        char common_ch = strs[0][pos];
        for(i = 1; i < strsSize ; i ++) { 
            if(strs[i][pos] == 0 || strs[i][pos] != common_ch) {
                common[pos] = 0;
                return common;
            }
        }

        common[pos++] = common_ch;
    }
    return strs[0];   
}
