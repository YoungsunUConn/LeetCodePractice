int maxArea(int* height, int heightSize) {
    // find points x and y
    // water_amount = (loc_x - loc_y) * min(x,y)

    int i, j;
    int max_output = -1;
    int max_output_i, max_output_j = heightSize - 1;


    int max_height = -1;
    
    
    for(i = 0 ; i < heightSize - 1; i ++) {
        int possible_max = height[i] * (heightSize - i - 1);

        // this height has a potential to proceed
        if(possible_max > max_output && height[i] > max_height) {
            int output;
            for(j = max_output_j; j > i ; j --) {
                
                output = (j - i) * (height[i] < height[j] ? height[i] : height[j]);

                if( output > max_output) {
                    max_output = output;
                    max_output_i = i;
                    max_output_j = j;
                }
                // no need to search further due to getting short in x-axis
                if(height[i] * (j-i) < max_output) {
                    break;
                }
                // no need to check shorter heights
                if(height[j] >= height[i]) {
                    break;
                }
            }
        }
        if( max_height < height[i]) max_height = height[i];
    }
    return max_output;

}
