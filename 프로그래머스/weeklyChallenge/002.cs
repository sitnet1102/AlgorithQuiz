using System;
using System.Collections.Generic;

public class Solution {
    public string solution(int[,] scores) {
        string answer = "";
        var s = new List<int>();
        var v = new List<float>();
        //List<int> s;
        for(int i=0;i<scores.GetLength(0);i++){
            int max = -1;
            bool maxFlag = false;
            int min = 101;
            bool minFlag = false;
            int sum = 0;
            int num = scores.GetLength(1);
            for(int j=0;j<scores.GetLength(1);j++){
                if(scores[j,i] > max){
                    max = scores[j,i];
                    maxFlag = false;
                }else if(scores[j,i] == max){
                    maxFlag = true;
                }
                
                if(scores[j,i] < min){
                    min = scores[j,i];
                    minFlag = false;
                }else if(scores[j,i] == min){
                    minFlag = true;
                }
                sum += scores[j,i];
            }
            if(!maxFlag && max == scores[i,i]){
                sum -= scores[i,i];
                num --;
            }else if(!minFlag && min == scores[i,i]){
                sum -= scores[i,i];
                num --;
            }
            v.Add((float)sum / (float)num);
        }
        foreach(float e in v){
            //Console.Write(e+" ");
            char g;
            if(e >= 90){
                g = 'A';
            }else if(e >= 80){
                g = 'B';
            }else if(e >= 70){
                g = 'C';
            }else if(e >= 50){
                g = 'D';
            }else{
                g = 'F';
            }
            answer += g;
        }
        //Console.WriteLine(scores.GetLength(1));
        return answer;
    }
}