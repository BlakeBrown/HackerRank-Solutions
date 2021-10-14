# Non divisible subset
 Algorithm basically boils down to cleverly applying modulo. We know that no 2 elements can be
 divisible by k, which also means the mod(k) of no two numbers can sum to k. For example with
 k = 10, we can't have two numbers where first_number%k = 1 and second_number%k = 9, since those
 would sum to a multiple k. Thus we'll either take all of the numbers whose value mod k is 1, or
 all of the numbers whose value mod k is 9, whichever is bigger. Don't forget that we can also
 include one multiple of k itself (since we only require that the SUM of any two numbers isn't
 divisible by k).

## Application
 Non divisible subset algorithm can be used to calculate the maximum length of anomaly of
 elements if there sums doesn't fit together, for example in a logistic center, where
 boxes can contain other boxes recursively, non divisible subset divide the anomaly
 into different segments, and return the count for those that doesn't fit together.
