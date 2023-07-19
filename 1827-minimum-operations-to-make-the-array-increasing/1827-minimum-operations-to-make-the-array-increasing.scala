object Solution {
    def minOperations(nums: Array[Int]): Int = {
        var ans = 0;
        for(i <- 1 to (nums.length -1))
        {
            var x = if (nums(i) - nums(i-1) >0) 0 else nums(i-1)-nums(i)+1;
            ans += x;
            nums(i) += x;
        }
        ans;
    }
}