def LCM(x,y):
    i=1
    j=1
    X=x
    Y=y
    while(X!=Y):
        if(X<Y):
            X=x*i
            i+=1
        else:
            Y=y*j
            j+=1
    return X

def GCD(x,y):
    lcm=LCM(x,y)
    gcd=(x*y)/lcm
    return int(gcd)

print(GCD(12,8))
print(LCM(12,8))