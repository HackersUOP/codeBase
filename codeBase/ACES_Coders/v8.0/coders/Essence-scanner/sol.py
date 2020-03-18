# Problem setter's code
# Author : harshana.w@eng.pdn.ac.lk
def f(X,Y,M,_x,_y):
    ret = 0
    for i in range(len(X)):
        d = (X[i]-_x)**2 + (Y[i]-_y)**2
        d = d**0.5
        ret += d*M[i]
    return ret

def geometricMedian(x, y, m): 
    n = len(x)

    # start assumption from Center of Mass
    _x,_y = 0, 0
    for i in range(n):
        _x += x[i] * m[i]
        _y += y[i] * m[i]
    _x,_y = _x/sum(m),_y/sum(m)
    opt_d = f(x,y,m,_x,_y) 

  
    for i in range(n):
        newd = f(x,y, m, x[i],y[i]) 
        if (newd < opt_d): 
            opt_d = newd
            _x = x[i]
            _y = y[i]
    
    test_distance = 10**5

    test_x = [-1,0,1,0]
    test_y = [0,1,0,-1]
    delta = 10**100
    while (test_distance > lower_limit and delta > 1e-7):
  
        flag = 0
        for i in range(4):
            newx = _x + test_distance * test_x[i]
            newy = _y + test_distance * test_y[i] 
            newd = f(x,y,m, newx,newy)  
            if (newd < opt_d):
                delta = opt_d - newd
                opt_d = newd
                _x = newx
                _y = newy
                # print("new loc {:.6f} {:.6f} d={:.6f} delta={:8f} testd={:.8f}".format(_x,_y,opt_d,delta,test_distance))
                flag = 1 
                break
        if (flag == 0):
            test_distance /= 2
    return _x,_y

lower_limit = 1e-5
N,M = map(int,input().split())
Xs,Ys = [],[]
ms = []
for i in range(N):
    x,y,m = map(int,input().split())
    Xs.append(x)
    Ys.append(y)
    ms.append(m)


xC,yC = geometricMedian(Xs, Ys, ms)

_x,_y = 0, 0
for i in range(len(Xs)):
    _x += Xs[i] * ms[i]
    _y += Ys[i] * ms[i]
_x,_y = _x/sum(ms),_y/sum(ms)


Xs.append(0)
Ys.append(0)
ms.append(M)
xH,yH = geometricMedian(Xs, Ys, ms)

_x,_y = 0, 0
for i in range(len(Xs)):
    _x += Xs[i] * ms[i]
    _y += Ys[i] * ms[i]
_x,_y = _x/sum(ms),_y/sum(ms)


print("{} {}".format(round(xC),round(yC)))
print("{} {}".format(round(xH),round(yH)))
