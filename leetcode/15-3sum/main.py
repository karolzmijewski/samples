class Solution:
    def threeSum(self, nums):
        nnums = len(nums)
        lidx = 0
        ridx = nnums -1 
        nums.sort()
        print(f"sorted: {nums}")
        result = []
        
        while(lidx < nnums - 2):
            if lidx == 0 or nums[lidx] != nums[lidx - 1]:
                print(f"lidx = {lidx}")
                ilidx = lidx + 1
                iridx = ridx
                while(ilidx < iridx):
                    print(f"ilidx = {ilidx}, iridx = {iridx}")
                    sum = nums[lidx] + nums[ilidx] + nums[iridx]
                    if sum < 0:
                        ilidx += 1
                    elif sum > 0:
                        iridx -= 1
                    elif sum == 0:
                        result.append([nums[lidx], nums[ilidx], nums[iridx]])
                         # skip duplicate second numbers
                        while ilidx < iridx and nums[ilidx] == nums[ilidx + 1]:
                            ilidx += 1
                        # skip duplicate third numbers
                        while ilidx < iridx and nums[iridx] == nums[iridx - 1]:
                            iridx -= 1
                        ilidx += 1
                        iridx -= 1
            lidx += 1
        return result
