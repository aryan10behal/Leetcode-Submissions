object Solution {
    def getval(x: Array[String]): (Int, Int) = {
        var a: Int = 0;
        var b: Int = 0;
        for(i <- 0 to 1)
        {
            a = a*10 + x(0)(i).toInt - 48;
            b = b*10+x(0)(i+3).toInt - 48;
        }
        var c = a*60 + b;
        a = 0;
        b = 0;
         for(i <- 0 to 1)
        {
            a = a*10 + x(1)(i).toInt -48;
            b = b*10+x(1)(i+3).toInt-48;
        }
        var d = a*60 + b;
        return (c, d);
           
    }
    def haveConflict(event1: Array[String], event2: Array[String]): Boolean = {
        val a = getval(event1);
        val b = getval(event2);
        if (a._1 <= b._1 && a._2 >= b._1 || a._1 <= b._2 && a._2 >= b._2)
            return true
        else if (b._1 <= a._1 && b._2 >= a._1 || b._1 <= a._2 && b._2 >= a._2)
            return true;
        return false;
    }
}