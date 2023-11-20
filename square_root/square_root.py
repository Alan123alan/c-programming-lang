import math

class Solution:
  def mySqrt(self, x: int) -> int:
    # Implement integer square root
    # The square root of a number lies between 0 and the number/2
    # 0 and 1 are base cases
    # The rest of the cases get handled within the loop
    # This is why we initialize left pointer to 2 and right to number/2
    if x < 2:
      return x
    left, right = 2 , x//2
    while left <= right:
      # Pivot is the middle point between left and right pointer values
      # To calculate the pivot we get an offset and add it to the left pointer
      pivot = left + (right - left)//2
      # Pivot is our guess square root, to confirm we need to square it and compare
      num = pivot * pivot
      if num > x:
        right = pivot - 1
      elif num < x:
        left = pivot + 1
      else:
        return pivot 
    return right

