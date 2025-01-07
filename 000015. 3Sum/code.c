// TODO: further optimization with pruning    
// TODO: There is a faster way to do with using a dictionary (array), but I like this memory-efficient way more.

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int binary_search(int* return_pos, int *ary, int len, int val) {
    int p1 = 0;
    int p2 = len;
    int mid;

    if(len == 0 || ary[0] > val || ary[len-1] < val) return 0;
    
    do {
        mid = (int)((p1 + p2) / 2);

        if( val > ary[mid]) {
            if( p1 == (int)((mid+p2) / 2)) return 0;
            p1 = mid;
        }
        else if(val < ary[mid]) {
            if( p2 == (int)((mid+p1) / 2)) return 0;
            p2 = mid;
        }
        else {
            *return_pos = mid;
            return 1;
        }

        
    } while(1);
    return 0;
}
 

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int p1, p2, i;
    int return_tmp[100000][3];
    int **return_ary;

    

    *returnSize = 0;

    qsort(nums, numsSize, sizeof(int), compare_ints);

    p1 = 0; p2 = 1;

    while(1) {
        int twoSum = nums[p1] + nums[p2];
        int target_value = 0 - twoSum;
        int return_bs, return_pos;

        return_bs = binary_search(&return_pos, nums + p2 + 1, (numsSize) - p2 - 1, target_value);

        if(return_bs) {
            return_tmp[*returnSize][0] = nums[p1];
            return_tmp[*returnSize][1] = nums[p2];
            return_tmp[*returnSize][2] = nums[return_pos + p2 + 1];
            (*returnSize) ++;
        }

        // skip the duplicate value for p2
        p2 += 1;
        while(p2 < numsSize && nums[p2] == nums[p2-1]) { p2 += 1; }

        if( p2 >= numsSize) {
            p1 ++;
            p2 = p1 + 1;
            // skip the duplicate value for p1, except that two numbers are same (but not all zeros)
            while(p1 < numsSize - 1 && nums[p1] == nums[p1-1] && ((nums[p1] != nums[p2]) || (nums[p1] == nums[p2] && nums[p1] == nums[p1-1]))) { p1 += 1; }
            p2 = p1 + 1;
        }
        if( p1 >= numsSize - 1) break;
    }


    return_ary = (int**)malloc(sizeof(int*) * *returnSize);
    *returnColumnSizes = (int*)malloc(sizeof(int*) * *returnSize);

    for( i = 0 ; i < *returnSize ; i ++) {
        return_ary[i] = (int*)malloc(sizeof(int) * 3);
        
        return_ary[i][0] = return_tmp[i][0];
        return_ary[i][1] = return_tmp[i][1];
        return_ary[i][2] = return_tmp[i][2];

        (*returnColumnSizes)[i] = 3;
    }
    return return_ary;
}
