# %%

def twoSum(nums: list[int], target) -> list[int]:

    idx_nums = [idx for idx in range(0,len(nums))]

    """idx = 0
    while idx < len(nums):
        if nums[idx] > target:
            del nums[idx]
            del idx_nums[idx]
        else:
            idx = idx + 1
    """



    idx_sorted = sorted(range(len(nums)), key=nums.__getitem__)
    

    idx1 = 0
    idx2 = len(nums) - 1
    while True: # Because there is one answer.
        sumv = nums[idx_sorted[idx1]] + nums[idx_sorted[idx2]]

        if sumv == target:
            return [idx_nums[idx_sorted[idx1]], idx_nums[idx_sorted[idx2]]]
        else:

            if (nums[idx_sorted[idx1+1]] + nums[idx_sorted[idx2]]) > target:
                idx2 = idx2 - 1
            elif (nums[idx_sorted[idx1]] + nums[idx_sorted[idx2-1]]) > target:
                idx1 = idx1 + 1
            else:

                left_sum = target - (nums[idx_sorted[idx1+1]] + nums[idx_sorted[idx2]])
                right_sum = target - (nums[idx_sorted[idx1]] + nums[idx_sorted[idx2-1]])

            

                if left_sum < right_sum:
                    idx1 = idx1 + 1
                else:
                    idx2 = idx2 - 1
