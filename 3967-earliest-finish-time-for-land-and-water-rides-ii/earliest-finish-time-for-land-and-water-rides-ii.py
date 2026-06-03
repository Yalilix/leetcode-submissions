class Solution:
    def earliestFinishTime(self, landStartTime, landDuration, waterStartTime, waterDuration):
        land = list(zip(landStartTime, landDuration))
        water = list(zip(waterStartTime, waterDuration))

        def upper_bound(arr, target):
            left = 0
            right = len(arr)

            while left < right:
                mid = (left + right) // 2

                if arr[mid] <= target:
                    left = mid + 1
                else:
                    right = mid

            return left

        def solve(first, second):
            second.sort()

            n = len(second)
            starts = [ride[0] for ride in second]

            bestDuration = [0] * n
            bestDuration[0] = second[0][1]

            for i in range(1, n):
                bestDuration[i] = min(bestDuration[i - 1], second[i][1])

            bestFinish = [0] * n
            bestFinish[n - 1] = second[n - 1][0] + second[n - 1][1]

            for i in range(n - 2, -1, -1):
                start = second[i][0]
                duration = second[i][1]

                bestFinish[i] = min(
                    bestFinish[i + 1],
                    start + duration
                )

            ans = float("inf")

            for start, duration in first:
                cur = start + duration

                idx = upper_bound(starts, cur)

                # Case 1: second ride already opened
                if idx > 0:
                    ans = min(ans, cur + bestDuration[idx - 1])

                # Case 2: second ride opens later
                if idx < n:
                    ans = min(ans, bestFinish[idx])

            return ans

        return min(
            solve(land, water),
            solve(water, land)
        )