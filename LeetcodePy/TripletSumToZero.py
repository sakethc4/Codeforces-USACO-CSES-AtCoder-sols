class Solution:
    def searchTriplets(self, arr):
        # pick an individual number find the two sum for it
        # if we pick the same num we get duplicate so skip
        # dupes can just sort and skip if currNum same as prev
        # [-3, 0, 1, 2, -1, 1, -2]
        # [-3,-2,-1,0,1,1,2,2]
        # [-3, -1, 4, 5]
        arr.sort()
        triplets = []
        for index, num in enumerate(arr):
            if index > 0 and arr[index] == arr[index - 1]:
                continue

            self.findTwoSum(arr, index + 1, -num, triplets)

        return triplets

    def findTwoSum(self, arr, index, target, triplets):
        left, right = index, len(arr) - 1
        while left < right:
            currSum = arr[left] + arr[right]
            if currSum == target:
                triplets.append([-target, arr[left], arr[right]])
                left += 1
                right -= 1
                # handling dupes
                while left < right and left > 0 and arr[left] == arr[left - 1]:
                    left += 1
                while left < right and right < len(arr) - 1 and arr[right] == arr[right + 1] :
                    right -= 1
            elif currSum < target:
                left += 1
            else:
                right -= 1


        

 
    

    
        
      