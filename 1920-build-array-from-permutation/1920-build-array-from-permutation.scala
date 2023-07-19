import scala.collection.mutable.ArrayBuffer
object Solution {
    def buildArray(nums: Array[Int]): Array[Int] = {
        val ans = ArrayBuffer[Int]();
        for(i <- 0 to nums.length-1)
        {
            ans += nums(nums(i));
        }
        return ans.toArray;
    }
}