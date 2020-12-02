from heapq import* n = 0 max_h = [] min_h = [] while True : try : num
= int(input()) n +=
    1

    if n == 1 : heappush(max_h, -num) median = num print(median) continue

                                                   if num < median
    : heappush(max_h, -num) elif median < num : heappush(min_h, num)

                                                    if len(max_h) -
                                                len(min_h) >
      1 : heappush(min_h, -heappop(max_h)) elif len(min_h) - len(max_h) > 1
    : heappush(max_h, -heappop(min_h))

          if len(max_h) == len(min_h)
    : median = (-max_h[0] + min_h[0]) / 2 elif len(max_h) > len(min_h)
    : median = -max_h[0] elif len(max_h) < len(min_h)
    : median = min_h[0]

    print(int(median))

        except : break