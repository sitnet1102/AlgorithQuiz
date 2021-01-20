#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct page{
  string name;
  int basic_score;
  double foriegn_link;
  vector<string> out_link;
};

int solution(string word, vector<string> pages) {
    int answer = 0;
    vector <struct page> link;
    int max_index;
    double max_score = -1;
    for(int i=0;i<word.size();i++){
      if(word[i] > 64 && word[i] < 91){
        word[i] = word[i] + 32;
      }
    }
    for(int i=0;i<pages.size();i++){
      struct page tmp;

      //int head = pages[i].find("<head>");
      int head = pages[i].find("<meta property");
      int headend = pages[i].find("</head>");
      string head_tmp = pages[i].substr(head ,headend - head);
      int a = head_tmp.find("https://");
      int b = head_tmp.find("\"",a+2);
      int c = b-a;
      
      int body = pages[i].find("<body>");
      int bodyend = pages[i].find("</body>");
      int top = 0;
      int back = 0;
      string body_tmp = pages[i].substr(body + 6,bodyend - body-6);
      vector<string> out;   // 외부 링크 이름 
      vector<string> word_v;
      tmp.name = head_tmp.substr(a+8, c-8);
      tmp.basic_score = 0;
      tmp.foriegn_link = 0;

      for(int j=0;j<body_tmp.size();j++){
        if(body_tmp[j] < 91 && body_tmp[j] > 64){
          body_tmp[j] = body_tmp[j] + 32;
        }
        if(body_tmp[j] < 97 || body_tmp[j] > 122){
          back = j;
          word_v.push_back(body_tmp.substr(top, back - top));
          top = back+1;
        }
      }
      while(body_tmp.find("<a href") != -1){
        int href_start = body_tmp.find("<a href");
        int href = body_tmp.find("\"",href_start+10);
        int href_end = body_tmp.find("</a>",href_start);
        string link_name = body_tmp.substr(href_start+17,href - href_start-17);
        out.push_back(link_name);
        body_tmp = body_tmp.substr(0, href_start) + body_tmp.substr(href_end + 4);
      }
      // 기본점수 
      // word 와 같은 것이 있는 지 확인해서 점수 계산 
      for(int j=0;j<word_v.size();j++){
        if(word_v[j] == word){
          tmp.basic_score ++;
        }
      }
      tmp.out_link = out;
      link.push_back(tmp);
    }
    for(int i=0;i<link.size();i++){
      // 외부 링크 수

      // 링크 점수 
      for(int j=0;j<link[i].out_link.size();j++){
        for(int k=0;k<link.size();k++){
          if(link[i].out_link[j] == link[k].name){
            double tmp_f = (double)link[i].basic_score / (double)link[i].out_link.size();
            link[k].foriegn_link = link[k].foriegn_link + tmp_f;
          }
        }
      }
      // 매칭 점수 
      cout << "==================\n";
      cout << "name : " << link[i].name << "\n";
      cout << "basic score : " << link[i].basic_score << "\n";
      cout << "link score : " << link[i].foriegn_link << "\n";
      cout << "foriegn links : ";
      for(int j=0;j<link[i].out_link.size();j++){
        cout << link[i].out_link[j] << " ";
      }
      cout <<"\n";
    }
    for(int i=0;i<link.size();i++){
      if(link[i].basic_score + link[i].foriegn_link > max_score){
        max_score = link[i].basic_score + link[i].foriegn_link;
        max_index = i;
      }
    }
    answer = max_index;
    return answer;
}