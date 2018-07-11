#include <iostream>
#include <stack>

using namespace std;

const int MAX = 30010;
const int  INF = 10;

int n;
int L[MAX], R[MAX];
int a[MAX];
int res, _left, _right;

void readData(){
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
}

void process(){
    stack <int> st;
    stack <int> id;
    L[0] = 0; L[1] = 1;
    st.push(0); id.push(0);
    st.push(a[1]);  id.push(1);
    for (int i=2; i<=n; i++){
        if (st.top() < a[i]){
            st.push(a[i]);
            id.push(i);
            L[i] = i;
        }
        else{
            while (st.top() >= a[i]){
                id.pop(); st.pop();
            }
            L[i] = id.top() + 1;
            st.push(a[i]);  id.push(i);
        }
    }

    while (!st.empty()){
        st.pop();   id.pop();
    }

    st.push(0);     id.push(n + 1);
    st.push(a[n]);  id.push(n);
    R[n] = n; R[n + 1] = n + 1;
    for (int i=n-1; i>=1; i--){
        if (st.top() < a[i]){
            st.push(a[i]);  id.push(i);
            R[i] = i;
        }
        else{
            while (st.top() >= a[i]){
                st.pop();   id.pop();
            }
            R[i] = id.top() - 1;
            st.push(a[i]);  id.push(i);
        }
    }
    res = 0;
    for (int i=1; i<=n; i++){
        int val = (R[i] - L[i] + 1) * a[i];
        if (res < val){
            res = val;
            _left = L[i];
            _right = R[i];
        }
    }
}

void printOutput(){
    cout<<res<<" "<<_left<<" "<<_right<<"\n";
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
