using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] weights, string[] head2head) {
        int[] answer = new int[weights.Length];
        List<List<int>> Player = new List<List<int>>();
        for(int i=0;i<weights.Length;i++){
            Player.Add(new List<int>());
        }
        for(int i=0;i<head2head.Length;i++){
            int playNum = 0;
            int winNum = 0;
            int heavyWinNum = 0;
            for(int j=0;j<head2head[i].Length;j++){
                if(head2head[i][j] == 'W' || head2head[i][j] == 'L'){
                    playNum ++;
                    if(head2head[i][j] == 'W'){
                        winNum ++;
                        if(weights[i] < weights[j]){
                            heavyWinNum ++;
                        }
                    }
                }
                //Console.Write(head2head[i][j]+" ");
            }
            Player[i].Add(i);
            Player[i].Add(playNum);
            Player[i].Add(winNum);
            Player[i].Add(heavyWinNum);
            Player[i].Add(weights[i]);
            //Console.WriteLine();
        }
        /*
        for(int i=0;i<Player.Count;i++){
            for(int j=0;j<Player[i].Count;j++){
                Console.Write(Player[i][j]+" ");
            }
            Console.WriteLine();
        }
        */
        Console.WriteLine();
        Player.Sort((A,B) => {
            float aWinRate = 0;
            float bWinRate = 0;
            if(A[1] != 0){
                aWinRate = (float)A[2] / (float)A[1];
            }
            if(B[1] != 0){
                bWinRate = (float)B[2] / (float)B[1];
            }
            
            if(aWinRate > bWinRate){
                return -1;
            }else if(aWinRate < bWinRate){
                return 1;
            }else{  // 승률이 같을때,
                if(A[3] > B[3]){
                    return -1;
                }else if(A[3] < B[3]){
                    return 1;
                }else{  // 자신보다 몸무게가 무거운 복서를 이긴 횟수가 같을때
                    if(A[4] > B[4]){
                        return -1;
                    }else if(A[4] < B[4]){
                        return 1;
                    }else{  // 몸무게가 같을 때
                        if(A[0] < B[0]){
                            return -1;
                        }else{
                            return 1;
                        }
                    }
                }
            }
        });
        /*
        for(int i=0;i<Player.Count;i++){
            for(int j=0;j<Player[i].Count;j++){
                Console.Write(Player[i][j]+" ");
            }
            Console.WriteLine();
        }
        */
        
        for(int i=0;i<Player.Count;i++){
            answer[i] = (Player[i][0]+1);
        }
        return answer;
    }
}