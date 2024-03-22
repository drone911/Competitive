class Solution:
    def insert(self, intervals: list[list[int]], newInterval: list[int]) -> list[list[int]]:
        n = len(intervals)
        if n == 0:
            return [newInterval]

        newStart = newInterval[0]
        newEnd = newInterval[1]        
        resultIntervals = []
        i = 0
        while i<n and intervals[i][1] < newStart:
            resultIntervals.append(intervals[i])
            i+=1
        if i == n:
            resultIntervals.append(newInterval)
            return resultIntervals
        currentStart = intervals[i][0]
        currentEnd = intervals[i][1]
        
        if newEnd < currentStart:
            # no overlap
            resultIntervals.append(newInterval)
            while i<n:
                resultIntervals.append(intervals[i])
                i+=1
        else:
            resultStart = min(newStart, currentStart)
            resultEnd = max(newEnd, currentEnd)
            j = i+1
            flag = False
            while j<n:
                if resultEnd >= intervals[j][1]:
                    j+=1
                else:
                    if resultEnd < intervals[j][0]:
                        #no merge
                        resultIntervals.append([resultStart, resultEnd])
                        flag = True
                        break
                    else:
                        #merge
                        resultIntervals.append([resultStart, intervals[j][1]])
                        j+=1
                        flag = True
                        break
            if not flag:
                resultIntervals.append([resultStart, resultEnd])
            
            while j<n:
                resultIntervals.append(intervals[j])
                j+=1
        return resultIntervals
            

        