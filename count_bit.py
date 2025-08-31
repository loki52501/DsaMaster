def count_bits(n):
    count=0
    for i in (bin(n)):
        if(i==1):
            count=1+count
    return count

print(count_bits(7))  # Output: 3
print(count_bits(10)) # Output: 2   