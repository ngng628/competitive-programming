'''
state:サイコロの全状態(u,d,f,b,l,rの順)(u+d=f+b=l+r=7)
(反対でない)2面と初期座標(now)を与えて初期化
…u,d,f,b,l,rは0,1,2,3,4,5に対応
now:座標
u,d,f,b,l,r:上,下,前,後,左,右
前面がy軸の-方向,右面がx軸の+方向
'''
class Dice:
    state=[[1,6,2,5,4,3],[1,6,3,4,2,5],[1,6,4,3,5,2],[1,6,5,2,3,4],
           [2,5,1,6,3,4],[2,5,3,4,6,1],[2,5,4,3,1,6],[2,5,6,1,4,3],
           [3,4,1,6,5,2],[3,4,2,5,1,6],[3,4,5,2,6,1],[3,4,6,1,2,5],
           [4,3,1,6,2,5],[4,3,2,5,6,1],[4,3,5,2,1,6],[4,3,6,1,5,2],
           [5,2,1,6,4,3],[5,2,3,4,1,6],[5,2,4,3,6,1],[5,2,6,1,3,4],
           [6,1,2,5,3,4],[6,1,3,4,5,2],[6,1,4,3,2,5],[6,1,5,2,4,3]]

    def __init__(self,state1,value1,state2,value2,now):
        self.now=[now[0],now[1]]
        for i in range(24):
            if Dice.state[i][state1]==value1 and Dice.state[i][state2]==value2:
                self.u,self.d,self.f,self.b,self.l,self.r=Dice.state[i]
                break
    #上から見てy軸の+方向に回転(後面が下面に！)
    def RotateN(self):
        self.d,self.f,self.u,self.b=self.b,self.d,self.f,self.u
        self.now[1]+=1
    #上から見てy軸の-方向に回転(前面が下面に！)
    def RotateS(self):
        self.d,self.f,self.u,self.b=self.f,self.u,self.b,self.d
        self.now[1]-=1
    #上から見てx軸の+方向に回転(右面が下面に！)
    def RotateE(self):
        self.d,self.l,self.u,self.r=self.r,self.d,self.l,self.u
        self.now[0]+=1
    #上から見てx軸の-方向に回転(左面が下面に！)
    def RotateW(self):
        self.d,self.l,self.u,self.r=self.l,self.u,self.r,self.d
        self.now[0]-=1
    #前から見て左回転(反時計回り)
    def RotateL(self):
        self.f,self.l,self.b,self.r=self.r,self.f,self.l,self.b
    #前から見て右回転(時計回り)
    def RotateR(self):
        self.f,self.l,self.b,self.r=self.l,self.b,self.r,self.f
