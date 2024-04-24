n = int(input());
subjects = list(map(float,input().split()))

tot = sum(subjects)

print(round(tot/n, 1))

if(tot >= 3.0):
    print('Good')
elif(tot >= 4.0):
    print('Perfect')
else:
    print('Poor')