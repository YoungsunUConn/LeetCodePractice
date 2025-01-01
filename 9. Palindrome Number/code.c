bool isPalindrome(int x) {
    
    // solution without converting the integer to a string
    if( x < 0) {
        return false;
    }
    else {
        // presuming x >= 0
        int digit = 1;

        // find the digits
        if(x >= 1000000000) {
            digit = 1000000000;
        }
        else {
            while(digit*10-1 < x) {
                digit *= 10;
            }
        }

        while(x > 9) {
            int inc;
            
            if(x / digit !=  x % 10) return false;
            
            // if next digits are zeros
            inc = 10;
            while((x / inc > inc) &&  ((x / (digit / inc)) % 10  == 0 )) {
                if( (x/inc) % 10 > 0) {
                    return false;
                }
                inc *= 10;
            }
            while(inc > 10) {
                x /= 10;
                digit /= 100;
                inc /= 10;
            }
            
            do {
                x = x - digit;
            } while(x - digit >= 0);
            
            x /= 10;
            digit /= 100;
        }
        return true;
    }
}
