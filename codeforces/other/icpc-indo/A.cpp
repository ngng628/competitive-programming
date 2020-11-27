int main() {
    ll id,N,K;
    cin >>id>>N>>K;
    vector<string>S(N);
    rep(i,N){
        cin>>S[i];
    }
    ll loop=1000;
    random_device rnd;
    mt19937 mt(rnd());
    uniform_int_distribution<> rand100(1, K);
    cout<<loop<<endl;
    ll pre=S[0][0]-'0';
    rep(i,loop){
         ll tmp=rand100(mt);
         if(tmp==pre){
             i--;
             continue;
         }else{
             cout<<1<<" "<<1<<" "<<tmp<<endl;
         }
         
         pre=tmp;
    }