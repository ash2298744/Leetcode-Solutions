class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        deadends = set(deadends)

        if "0000" in deadends:
            return -1
        deadends.add("0000")

        move = { 
            "0" : ["1", "9"],
            "1" : ["2", "0"],
            "2" : ["3", "1"],
            "3" : ["4", "2"],
            "4" : ["5", "3"],
            "5" : ["6", "4"],
            "6" : ["7", "5"],
            "7" : ["8", "6"],
            "8" : ["9", "7"],
            "9" : ["0", "8"]
        }
        
        dq = deque([["0000", 0]])
        while dq:
            state, turns = dq.popleft()

            if state == target:
                return turns

            for i in range(4):
                for j in move[state[i]]:
                    if (state[:i] + j + state[i + 1:]) not in deadends:
                        deadends.add(state[:i] + j + state[i + 1:])
                        dq.append([state[:i] + j + state[i + 1:], turns + 1])
        return -1
