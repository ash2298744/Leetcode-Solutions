class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort() # solve greedily after sorting

        boats, left, right, = 0, 0, len(people) - 1
        while left <= right:
            onTheBoat = people[left] + people[right]

            if left == right:
                onTheBoat -= people[left] # to remove duplicate weight

            if onTheBoat > limit:
                right -= 1 # we can always exclude the largest weight if more than limit. (since, limit >= people[i])
            else:
                left += 1
                right -= 1
            
            boats += 1
        return boats
