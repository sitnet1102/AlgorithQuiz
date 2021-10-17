using System;
using System.Linq;

public class Solution {
    public int solution(int[,] sizes) {
        int answer = 0;
        int x=0;
        int y=0;
        //Console.WriteLine(sizes.GetLength(0));
        for(int i=0;i<sizes.GetLength(0);i++){
            int tmp;
            if(sizes[i,0] > sizes[i,1]){
                tmp = sizes[i,0];
                sizes[i,0] = sizes[i,1];
                sizes[i,1] = tmp;
            }
        }
        for(int i=0;i<sizes.GetLength(0);i++){
            //Console.WriteLine(sizes[i,0] + " " + sizes[i,1]);
            if(sizes[i,0] > x){
                x = sizes[i,0];
            }
            if(sizes[i,1] > y){
                y = sizes[i,1];
            }
        }
        //Console.WriteLine("x : "+x+", y : "+y);
        answer = x * y;
        return answer;
    }
}