int maxArea(int* height, int heightSize) {
    // find points x and y
    // water_amount = (loc_x - loc_y) * min(x,y)

    int i, j;
    int max_output = -1;
    int max_height = -1;
    

    for(i = 0 ; i < heightSize; i ++) {
        int max_len = heightSize - i - 1;
        int possible_max = height[i] * max_len;

        // this height has a potential to proceed
        if(possible_max > max_output ) {
            int output;
            for(j = heightSize - 1 ; j > i ; j --) {
                
                output = (j - i) * (height[i] < height[j] ? height[i] : height[j]);

                if( output > max_output) {
                    max_output = output;

                    // no reason to search further
                    if(height[j] >= height[i]) {
                        break;
                    }
                }
            }
        }
    }
    return max_output;

}
