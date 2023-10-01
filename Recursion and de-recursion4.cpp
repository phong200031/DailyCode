#include <bits/stdc++.h>
using namespace std;
int a[1000], n;
int mem[1000]; //# m?ng ghi nh? l?i gi?i c�c b�i to�n con d� du?c gi?i

void init(){
    memset(mem, -1, sizeof(mem));
}

//# Quy ho?ch d?ng, 
//# H�m lis(i) tr? v? d? d�i d�y con tang d�i nh?t k?t th�c b?i a[i]
int lis(int n) {
    mem[0] = 1;
    if(n==0){
        
        return 1;
    }
    int tmp = a[n];
    int maxL = 0;
    for(int i = 0; i < n; i++){
        if(tmp > a[i]) maxL = max(maxL, mem[i]);
    }
    maxL++;
    mem[n] = maxL;
    return maxL;
}

//# Truy vet loi giai
void trace(int i){
    for(int j = 0; j < i; j++){
        if (a[j] < a[i] && mem[i] == 1 + mem[j]){
            trace(j);
            break;
        }
    }
    cout << a[i] << " ";
}

int main(){
    init();
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int res = 1, pos = 0;
    for(int i = 1; i < n; i++){
        if (res < lis(i)){
            res = lis(i);
            pos = i;
        }
    }
    cout << res << endl;
    trace(pos);
    return 0;
}
