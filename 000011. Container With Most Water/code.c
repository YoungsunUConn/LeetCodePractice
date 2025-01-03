int maxArea(int* height, int heightSize) {

    int i, j;
    int max_output = -1;
    int max_output_j = heightSize - 1;


    int max_height = -1;
    
    
    for(i = 0 ; i < max_output_j; i ++) {
        int possible_max = height[i] * (max_output_j - i);

        // this height has a potential to proceed
        if(possible_max > max_output && height[i] > max_height) {
            int output;
            for(j = max_output_j; j > i ; j --) {
                
                output = (j - i) * (height[i] < height[j] ? height[i] : height[j]);

                if( output > max_output) {
                    max_output = output;
                    max_output_j = j;
                }
                // no need to search further due to getting short in x-axis
                if(height[i] * (j-i) < max_output) {
                    break;
                }
                // no need to check shorter heights (as j towards 0))
                if(height[j] >= height[i]) {
                    break;
                }
            }
        }
        if( max_height < height[i]) max_height = height[i];
    }
    return max_output;

}
