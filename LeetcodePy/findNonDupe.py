class Solution:
  def moveElements(self, arr):
    # 2,3,3,3,6,9
    if len(arr) < 2: 
      return len(arr)
    
    nextNonDupe = 1
    for index, num in enumerate(arr):
      if arr[index] != arr[nextNonDupe - 1]:
        arr[nextNonDupe] = arr[index]
        nextNonDupe += 1 
      
    
    return nextNonDupe

