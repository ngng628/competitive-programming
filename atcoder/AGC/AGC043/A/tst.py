import random
 
print(10, 8)
for y in range(10):
    for x in range(8):
        if random.choice([True, False]):
            print('#', end='')
        else:
            print('.', end='')
    print('');
