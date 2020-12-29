#include <iostream>
#include <vector>

using namespace std;

int N;				// 개수
int A[4];			// 연산자 숫자 입력
int max_num = 0;	// 최대값 저장
int min_num = 0;	// 최소값 저장 
int check = 0;      // max, min 값 처음 사용 여부 
vector<int> num;	// 입력되는 숫자 배열 (길이 N)
vector<int> opt;	// 연산자 배열 (길이 N-1)
vector<int> isused;	// 연산자 사용 여부 체크 배열 (길이 N-1) 
vector<int> v;	    // 사용되는 연산자 넣어주는 배열  

//  + : 0 , - : 1, * : 2, / : 3 

void func(int k){
    if(k == N-1){
    	int tmp = num[0];
        for(int i=0;i<N-1;i++){
            if(v[i] == 0){			// 덧셈
            	tmp = tmp + num[i+1];
            }else if(v[i] == 1){	// 뺄셈
            	tmp = tmp - num[i+1];
            }else if(v[i] == 2){	// 곱셈
            	tmp = tmp * num[i+1];
            }else if(v[i] == 3){	// 나눗셈
            	tmp = tmp / num[i+1];
            }
        }
        if(check){
            if(tmp > max_num){
                max_num = tmp;
            }
            if(tmp < min_num){
                min_num = tmp;
            }
        }
        else {
            max_num = tmp;
            min_num = tmp;
            check = 1;
        }
        ///
        /*
        printf("            max = %d\n", max_num);
        printf("            min = %d\n", min_num);
        */
        ///
        return;
        
    }
    for(int i=0;i<N-1;i++){
        if(!isused[i]){
            ///
            /*
            printf("================ k = %d\n",k);
            printf("isused -> ");
            for(int a=0;a<isused.size();a++){
                printf("%d ", isused[a]);
            }
            printf("\nv -> ");
            for(int a=0;a<v.size();a++){
                printf("%d ",v[a]);
            }
            printf("\n");
            */
            ///
            v.push_back(opt[i]);
            //v[k] = opt[i];
            isused[i] = 1;
            func(k+1);
            isused[i] = 0;
            v.pop_back();
        }
    }
}


int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        num.push_back(tmp);
    }
    for(int i=0;i<4;i++){
        cin >> A[i];
        for(int j=0;j<A[i];j++){
        	int tmp = i;
            int zero = 0;
        	opt.push_back(tmp);
        	isused.push_back(zero);
        }
    }

    ///
    //printf("%")
    ///

    func(0);
    /*
    cout << max << "\n";
    cout << min << "\n";
    */
    printf("%d\n%d\n",max_num, min_num);
    return 0;
}
















