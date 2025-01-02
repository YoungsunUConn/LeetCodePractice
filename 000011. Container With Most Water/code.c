int maxArea(int* height, int heightSize) {
    // find points x and y
    // water_amount = (loc_x - loc_y) * min(x,y)
    // O(n^2) solution

    int i, j;
    int max_output = -1;

    for(i = 0 ; i < heightSize; i ++) {
        int max_len = heightSize - i - 1;

        // this height has a potential to proceed
        if(height[i] * max_len > max_output ) {
            int output;
            for(j = i+1 ; j < heightSize ; j ++) {
                output = (j - i) * (height[i] < height[j] ? height[i] : height[j]);
                if( output > max_output) max_output = output;
            }
        }
    }
    return max_output;

}
