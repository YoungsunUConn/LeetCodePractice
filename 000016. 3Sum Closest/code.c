// TODO: more trim can be applied (during twosum)

int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    int i;
    int closest_target = 100000;

    // sort 
    qsort(nums, numsSize, sizeof(int), compare_ints);


    // x + y + z = target
    // y + z = target - x

    

    for( i = 0 ; i < numsSize ; i++) {
        // nums[i] = x
        int new_target = target - nums[i];

        // find two sum
        int j = 0,k = numsSize - 1;
        while(j < k) {
            if( i == j) { ++ j; continue; }
            else if(i == k){ -- k; continue; }
            
            int twosum = nums[j] + nums[k];

            if( abs(closest_target) > abs(nums[i] + twosum - target)) {
                closest_target = nums[i] + twosum - target;
            }

            if (twosum > new_target) {
                    --k;
            }
            else if( twosum < new_target) {
                    ++j;
            }
            else {
                    return target;
            }
        }
    }
    return closest_target + target;
}
