using System;

class Solution
{
    public long solution(int price, int money, int count)
    {
        long sum = 0;
        long ret = 0;
        //Console.WriteLine(price);
        for(int i=1;i<=count;i++){
            sum = sum + i * price;
            Console.WriteLine("sum : "+sum+", price : "+i*price);
            
        }
        Console.WriteLine(sum);
        if(money < sum){
            ret = sum - money;
        }
        return ret;
    }
}