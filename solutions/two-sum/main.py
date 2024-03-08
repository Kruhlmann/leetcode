class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        numbers_to_index = {}
        for index, number in enumerate(nums):
            complement = target - number
            if complement in numbers_to_index:
                return [numbers_to_index[complement], index]
            numbers_to_index[number] = index
        return []
