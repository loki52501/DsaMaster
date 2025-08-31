def twonumsum(arr, target):
    yarr={}
    tr=10000
    for i in range(0,len(arr)):
        yarr[target-arr[i]]=i
    for i in range(0,len(arr)):
        if yarr.get(arr[i]) and arr[i]!=target-arr[i]:
            return [arr[i],arr[yarr.get(arr[i])]]

        

        
s=[3,5,-4,8,11,1,-1,6]
print(twonumsum(s,10))
            


                                      