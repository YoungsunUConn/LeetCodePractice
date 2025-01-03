int maxArea(int* height, int heightSize) {
    // O(n) solution

    int i, j;
    int max_output = -1;
    int max_height = -1;
    

    for(i = 0 ; i < heightSize - 1; i ++) {
        int possible_max = height[i] * (heightSize - i - 1);

        // this height has a potential to proceed
        if(possible_max > max_output && height[i] > max_height) {
            int output;
            for(j = heightSize - 1 ; j > i ; j --) {
                
                output = (j - i) * (height[i] < height[j] ? height[i] : height[j]);

                if( output > max_output) {
                    max_output = output;
                }
                // no reason to search further
                if(height[j] >= height[i] || height[i] * (j-i) < max_output) {
                    break;
                }
            }
        }
        if( max_height < height[i]) max_height = height[i];
    }
    return max_output;

}
