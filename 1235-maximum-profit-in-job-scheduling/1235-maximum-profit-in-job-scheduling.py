class Solution:
    def jobScheduling(self, startTime, endTime, profit):
        jobs = []
        for i in range(len(startTime)):
            jobs.append((endTime[i], startTime[i], profit[i]))

        jobs.sort()

        n = len(jobs)
        dp = [0] * (n + 1)

        for i in range(n):
            end, start, p = jobs[i]

            skip = dp[i]

            low = 0
            high = i - 1
            j = -1
            while low <= high:
                mid = (low + high) // 2
                if jobs[mid][0] <= start:
                    j = mid
                    low = mid + 1
                else:
                    high = mid - 1

            if j >= 0:
                take = p + dp[j + 1]
            else:
                take = p

            dp[i + 1] = max(skip, take)

        return dp[n]