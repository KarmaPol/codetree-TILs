n = int(input());
subjects = list(map(float,input().split()))

tot = sum(subjects)
avg = round(tot/n, 1)
print(avg)

if(avg >= 4.0):
    print('Perfect')
elif(avg >= 3.0):
    print('Good')
else:
    print('Poor')