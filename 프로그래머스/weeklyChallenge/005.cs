using System;
using System.Collections.Generic;

public class Solution {
    public int solution(string word) {
        int answer = 0;
        string[] c = { "A", "E", "I", "O", "U"};
        List<string> w = new List<string>();
        for(int i=0;i<c.Length;i++){
            string tmp = "";
            tmp += c[i];
            w.Add(tmp);
            for(int j=0;j<c.Length;j++){
                tmp += c[j];
                w.Add(tmp);
                for(int k=0;k<c.Length;k++){
                    tmp += c[k];
                    w.Add(tmp);
                    for(int l=0;l<c.Length;l++){
                        tmp += c[l];
                        w.Add(tmp);
                        for(int m=0;m<c.Length;m++){
                            tmp += c[m];
                            w.Add(tmp);
                            tmp = tmp.Remove(tmp.Length-1,1);    
                        }
                        tmp = tmp.Remove(tmp.Length-1,1);
                    }
                    tmp = tmp.Remove(tmp.Length-1,1);
                }
                tmp = tmp.Remove(tmp.Length-1,1);
            }
            tmp = tmp.Remove(tmp.Length-1,1);
        }
        
        for(int i=0;i<w.Count;i++){
            //Console.WriteLine(w[i]);
            if(w[i] == word){
                answer = i+1;
                break;
            }
        }
        
        return answer;
    }
}