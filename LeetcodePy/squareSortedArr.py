class Solution:
  def makeSquares(self, arr):
    n = len(arr)
    squares = [0 for _ in range(n)]

    left, right = 0, len(arr) - 1
    index = len(squares) - 1
    while left <= right: 
      if (arr[left] * arr[left]) > (arr[right] * arr[right]): 
        squares[index] = arr[left] * arr[left]
        left += 1 
      else: 
        squares[index] = arr[right] * arr[right]  
        right -= 1 
      
      index -= 1 
    
    return squares 

    # [-3,-2,-1]
    # [0, 4, 9]
    # 
