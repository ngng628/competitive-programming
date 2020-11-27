#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<array>
#include<map>
#include<iomanip>
#include<assert.h>
#include<list>
#include<bitset>
#include<stack>
#include<memory>
#include<numeric>
#include <utility>


using namespace std;
typedef long long int llint;
typedef long double lldo;
#define mp make_pair
#define mt make_tuple
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define fir first
#define sec second
#define res resize
#define ins insert
#define era erase
#define REP(i, n) for(int i = 0;i < (n);i++)
/*cout<<fixed<<setprecision(20);cin.tie(0);ios::sync_with_stdio(false);*/
const llint mod=1000000007;
const llint inf=2.19e15+1;
const long double pai=3.141592653589793238462643383279502884197;
const long double eps=1e-10;
template <class T,class U>bool chmin(T& a,U b){if(a>b){a=b;return true;}return false;}
template <class T,class U>bool chmax(T& a,U b){if(a<b){a=b;return true;}return false;}
llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
llint lcm(llint a,llint b){if(a==0){return b;}return a/gcd(a,b)*b;}
template<class T> void SO(T& ve){sort(ve.begin(),ve.end());}
template<class T> void REV(T& ve){reverse(ve.begin(),ve.end());}
template<class T>llint LBI(const vector<T>&ar,T in){return lower_bound(ar.begin(),ar.end(),in)-ar.begin();}
template<class T>llint UBI(const vector<T>&ar,T in){return upper_bound(ar.begin(),ar.end(),in)-ar.begin();}

inline double getTime() {
    using namespace std::chrono;
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}
double starttime;
inline double myTime(){return getTime()-starttime;}//ミリ秒単位
llint allcost=0;
void putmove(int x,int y){
	allcost+=abs(x)+abs(y);
	int j;
	if(x>0){for(j=0;j<x;j++){cout<<'D';}}
	if(x<0){for(j=0;j<-x;j++){cout<<'U';}}
	if(y>0){for(j=0;j<y;j++){cout<<'R';}}
	if(y<0){for(j=0;j<-y;j++){cout<<'L';}}
}
int main(void){
	
	//ここでは、カードの番号を1～100で表します
	int n=20,m=100,i,j;
	array<int,102> sx,sy;//スタートのカードの位置
	array<array<int,20>,20> smat;//スタートのカードの配列
	
	array<int,102> tx,ty;//中間のカードの位置
	array<array<int,20>,20> tmat;//中間のカードの配列
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){smat[i][j]=-1;tmat[i][j]=-1;}
	}
	for(i=1;i<=m;i++){cin>>sx[i]>>sy[i];smat[sx[i]][sy[i]]=i;}
	for(i=1;i<=m;i++){tx[i]=5+i%10;ty[i]=5+i/10;tmat[tx[i]][ty[i]]=i;}
	
	sx[0]=0;sy[0]=0;
	sx[m+1]=10;sy[m+1]=10;
	tx[0]=10;ty[0]=10;
	tx[m+1]=10;ty[m+1]=10;
	
	array<int,102> zyun;//山札の順番->番号
	array<int,102> gz;//番号->山札の順番
	for(i=1;i<=m;i++){zyun[i]=i;gz[i]=i;}
	zyun[0]=0;zyun[m+1]=m+1;
	gz[0]=0;gz[m+1]=m+1;
	
	
	//2-opt
	mt19937 engine;
	
	
	starttime=getTime();
	int mita=0;
	//二段階積み法
	
	llint nowmove=0;
	int gx=0,gy=0;
	for(i=1;i<=m;i++){//指定した
		int ax=sx[zyun[i]],ay=sy[zyun[i]];
		nowmove+=abs(ax-gx)+abs(ay-gy);
		gx=ax;gy=ay;
	}
	for(i=m;i>=0;i--){//指定した
		int ax=tx[zyun[i]],ay=ty[zyun[i]];
		nowmove+=abs(ax-gx)+abs(ay-gy);
		gx=ax;gy=ay;
	}
	for(i=1;i<=m;i++){//指定した
		int ax=tx[i],ay=ty[i];
		nowmove+=abs(ax-gx)+abs(ay-gy);
		gx=ax;gy=ay;
	}
	
	auto Zcost=[&](int p,int q){
		if(q==m+1){return abs(sx[zyun[p]]-tx[zyun[p]])+abs(sy[zyun[p]]-ty[zyun[p]]);}
		return abs(sx[zyun[p]]-sx[zyun[q]])+abs(sy[zyun[p]]-sy[zyun[q]])+abs(tx[zyun[p]]-tx[zyun[q]])+abs(ty[zyun[p]]-ty[zyun[q]]);};
	//zyunがp番目のやつとq番目のやつの距離,cとtを足す
	
	auto Tcost=[&](int p,int nx,int ny){
		return abs(tx[zyun[gz[p]-1]]-nx)+abs(ty[zyun[gz[p]-1]]-ny)+abs(tx[zyun[gz[p]+1]]-nx)+abs(ty[zyun[gz[p]+1]]-ny)
		+abs(tx[p-1]-nx)+abs(ty[p-1]-ny)+(p!=m?abs(tx[p+1]-nx)+abs(ty[p+1]-ny):0);
	};
	//番号pが場所nx,nyにある時のコスト
	
	std::uniform_real_distribution<> dist(0.0, 1.0);
	double alltime=2980;
	double ondo=20;
	llint kai=0;
	int dxp[]={-2,-2,-2,-1,-1,-1,-1,-1,0,0,0,0,1,1,1,1,1,2,2,2};
	int dyp[]={-1,0,1,-2,-1,0,1,2,-2,-1,1,2,-2,-1,0,1,2,-1,0,1};
	int acou=0,bcou=0,ccou=0;
	for(kai=0;kai<1e12;kai++){
		tx[m+1]=sx[zyun[m]];ty[m+1]=sy[zyun[m]];
		if((kai&65535)==0){
			double zikan=myTime();
			
			/*if(zikan/600>=mita+1||zikan>alltime){
				mita=zikan/600;
				cerr<<"de ondo="<<ondo<<endl;
				cerr<<"nowmove="<<nowmove<<endl;
				int genmove=0;
				gx=0;gy=0;
				for(i=1;i<=m;i++){//指定した
					int ax=sx[zyun[i]],ay=sy[zyun[i]];
					genmove+=abs(ax-gx)+abs(ay-gy);
					gx=ax;gy=ay;
				}
				for(i=m;i>=0;i--){//指定した
					int ax=tx[zyun[i]],ay=ty[zyun[i]];
					genmove+=abs(ax-gx)+abs(ay-gy);
					gx=ax;gy=ay;
				}
				for(i=1;i<=m;i++){//指定した
					int ax=tx[i],ay=ty[i];
					genmove+=abs(ax-gx)+abs(ay-gy);
					gx=ax;gy=ay;
				}
				//cerr<<"genmove="<<genmove<<endl;
				//cerr<<"aper="<<acou*1.0/ccou<<endl;
				//cerr<<"bper="<<bcou*1.0/ccou<<endl;
				//acou=0;bcou=0;ccou=0;
			}*/
			
			if(zikan>alltime){break;}
			ondo=pow(1-zikan/alltime,2.1)*9;
		}
		llint sa=0;
		auto ran=engine();
		//ccou++;
		if(ran%7<3){
			bool ppp=(ran%7==0);
			ran/=7;
			//zyunの一部を反転する
			int a=ran%m +1;ran/=m;
			int b;
			if(ppp){b=ran%m +1;}
			else{
				b=a+ran%11-5;
				if(b<=0||m<b){continue;}
			}
			
			if(a==b){continue;}
			if(a>b){swap(a,b);}
			sa+=Zcost(a-1,b)-Zcost(a-1,a);
			sa+=Zcost(a,b+1)-Zcost(b,b+1);
			if(-log(dist(engine))*ondo>sa){//入れ替える
				//acou++;
				reverse(zyun.begin()+a,zyun.begin()+b+1);
				for(i=a;i<=b;i++){gz[zyun[i]]=i;}
				nowmove+=sa;
			}
		}else{
			ran/=7;
			//tmatを入れ替える
			int a=ran%m +1;ran/=m;
			
			//入れ替え先は、距離が近いやつにしたい
			int ax=tx[a],ay=ty[a];
			//if(tmat[ax][ay]!=a){cerr<<"bug"<<endl;}
			int uuu=ran%20;
			int bx=ax+dxp[uuu],by=ay+dyp[uuu];
			if(bx<0||bx>=n||by<0||by>=n){continue;}
			sa+=Tcost(a,bx,by)-Tcost(a,ax,ay);
			int b=tmat[bx][by];
			if(b!=-1){
				sa+=Tcost(b,ax,ay)-Tcost(b,bx,by);
				if(abs(a-b)==1){sa+=abs(ax-bx)+abs(ay-by)+abs(ax-bx)+abs(ay-by);}
				if(abs(gz[a]-gz[b])==1){sa+=abs(ax-bx)+abs(ay-by)+abs(ax-bx)+abs(ay-by);}
			
			}
			if(-log(dist(engine))*ondo>sa){//入れ替える
				//bcou++;
				swap(tmat[ax][ay],tmat[bx][by]);
				if(b!=-1){tx[b]=ax;ty[b]=ay;}
				tx[a]=bx;ty[a]=by;
				nowmove+=sa;
			}
		}
	}
	
	//最後に、少しだけの改善を入れる
	//回収フェーズ中に、ものを動かせるなら、動かす
	cerr<<"kai="<<kai<<endl;
	gx=0,gy=0;
	int setuyaku=0;
	auto fmat=smat;
	for(i=1;i<=m;i++){//指定した
		int ax=sx[zyun[i]],ay=sy[zyun[i]];
		
		tuple<int,int,int,int,int,int>aaa={0,-1,gx,gy,ax,ay};
		int dx=(ax>gx?1:-1);
		int dy=(ay>gy?1:-1);
		for(int ux=gx;ux!=ax+dx;ux+=dx){
			for(int uy=gy;uy!=ay+dy;uy+=dy){
				if(ux==gx&&uy==gy){continue;}
				if(fmat[ux][uy]==-1){continue;}
				int p=gz[fmat[ux][uy]];
				if(p<=i){continue;}
				for(int vx=ux;vx!=ax+dx;vx+=dx){
					for(int vy=uy;vy!=ay+dy;vy+=dy){
						if(vx==ax&&vy==ay){continue;}
						if(fmat[vx][vy]!=-1){continue;}
						int kyo=abs(sx[zyun[p-1]]-vx)+abs(sy[zyun[p-1]]-vy)+abs(sx[zyun[p+1]]-vx)+abs(sy[zyun[p+1]]-vy);
						   kyo-=abs(sx[zyun[p-1]]-ux)+abs(sy[zyun[p-1]]-uy)+abs(sx[zyun[p+1]]-ux)+abs(sy[zyun[p+1]]-uy);
						chmin(aaa,mt(kyo,zyun[p],ux,uy,vx,vy));
					}
				}
			}
		}
		if(get<1>(aaa)!=-1){
			int kyo,p,ux,uy,vx,vy;
			tie(kyo,p,ux,uy,vx,vy)=aaa;
			setuyaku-=kyo;
			putmove(ux-gx,uy-gy);cout<<'I';
			putmove(vx-ux,vy-uy);cout<<'O';
			putmove(ax-vx,ay-vy);cout<<'I';
			fmat[ux][uy]=-1;
			fmat[vx][vy]=p;
			sx[p]=vx;sy[p]=vy;
			//cerr<<ux<<" "<<uy<<" "<<vx<<" "<<vy<<" "<<p<<endl;
		}else{putmove(ax-gx,ay-gy);cout<<'I';}
		
		
		gx=ax;gy=ay;
		fmat[gx][gy]=0;
	}
	cerr<<"setuyaku="<<setuyaku<<endl;
	for(i=m;i>=1;i--){//指定した
		int ax=tx[zyun[i]],ay=ty[zyun[i]];
		putmove(ax-gx,ay-gy);
		cout<<'O';
		gx=ax;gy=ay;
	}
	for(i=1;i<=m;i++){//指定した
		int ax=tx[i],ay=ty[i];
		putmove(ax-gx,ay-gy);
		cout<<'I';
		gx=ax;gy=ay;
	}
	cout<<endl;
	cerr<<"allcost="<<allcost<<endl;
	return 0;
}
//17825792
/*
0~4
608
603
622
600
623
3056

604
607
619
602
626
3058
*/
