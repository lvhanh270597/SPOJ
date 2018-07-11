#include <iostream>
#include <stack>

using namespace std;

const int MAX = 30010;
const int  INF = 10;

int n;
int L, R;
int a[MAX];
int res;

void readData(){
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
}

void maximize(int & res, int & L, int & R, int l, int r, int val){
    int cnt = r - l + 1;
    val = val * cnt;
    if (val == res){
        if (l < L){
            L = l;
            R = r;
        }
    }
    if (val > res){
        res = val;
        L = l;
        R = r;
    }
}

void process(){
    stack <int> st;
    stack <int> id;
    res = 0; L = -1, R = -1;
    a[n + 1] = -INF + 1;
    st.push(-INF); id.push(0);
    for (int i=1; i<=n + 1; i++){
        if (st.top() <= a[i]){
            st.push(a[i]);
            id.push(i);
        }
        else{
            while (st.top() > a[i]){
                id.pop();
                maximize(res, L, R, id.top() + 1, i - 1, st.top());
                st.pop();
            }
            maximize(res, L, R, id.top() + 1, i, a[i]);
            st.push(a[i]);  id.push(i);
        }
    }
}

void printOutput(){
    cout<<res<<" "<<L<<" "<<R<<"\n";
}

void processing(){
    int T;
    cin>>T;
    while (T--){
        readData();
        process();
        printOutput();
    }
}

int main(){
    //freopen("A.INP", "r", stdin);
    ios_base::sync_with_stdio(false);
    processing();
    return 0;
}
