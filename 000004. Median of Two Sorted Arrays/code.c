double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    //int nums_merged[2000];

    int i=0,j=0;
    int med = 0;




    while(i < nums1Size || j < nums2Size) {
        int Thenum;
        int num1, num2;

        if(i < nums1Size) num1 = nums1[i];
        if(j < nums2Size) num2 = nums2[j];
        
        
        if((num1 > num2 && i < nums1Size && j < nums2Size) || (i == nums1Size && j < nums2Size)) {
            Thenum = num2; j ++;
            
        }
        else {
            Thenum = num1; i ++;
        }
        
        if( ((nums1Size + nums2Size) % 2) == 0) {
            if ( (i + j == (int)((nums1Size + nums2Size) / 2 + 1)) || (i + j == (int)((nums1Size + nums2Size) / 2))) {
                med += Thenum;
            }

        } else {
            if( i + j == (int)((nums1Size + nums2Size) / 2) + 1) {
                med = Thenum;
            }
        }

    }

    if (((nums1Size + nums2Size) % 2) == 0) return med / 2.0;
    else return med;
}
