bool isMatch(char* s, char* p) {

    // recursive function version (because s.len and p.len are only 20 or less)
    // TODO: writing a code without using a recursive function

    int s_idx_add, p_idx_add;

    if( p[0] == 0 && s[0] == 0) return true;
    else if (p[0] == 0) return false; // pattern must encompass wholse s

    if( s[0] == 0 && p[1] == '*') return isMatch(s, p+2); // residul pattern characters can be discarded if there's *
    else if (s[0] == 0) return false;
    

    if( p[0] == '.' && p[1] == '*') {
        for( s_idx_add = 0 ; s_idx_add <= strlen(s) ; s_idx_add++)
            if (isMatch(s+s_idx_add, p+2)) return true;
        return false;
    }
    else if( s[0] == p[0] && p[1] == '*' ) {
        if (isMatch(s, p+2)) return true; // zero of the preceding element
        for( s_idx_add = 0 ; (s[s_idx_add] == s[0]); s_idx_add++) // one+ of the preceding element
            if (isMatch(s+s_idx_add+1, p+2)) return true;
        return false;
    }
    else if( s[0] != p[0] && p[1] == '*' ) {
        return isMatch(s, p+2);
    }
    else if( s[0] == p[0] || p[0] == '.') {
        return isMatch(s+1, p+1);
    }
    
    return false;
}
