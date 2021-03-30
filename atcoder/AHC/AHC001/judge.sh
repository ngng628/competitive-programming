echo "[\e[32mv\e[m] g++ main.cpp"
g++-10 -std=gnu++17 -Wall -Wextra -Wno-unknown-pragmas -O2 main.cpp

echo "[\e[32mv\e[m] ./a.out < in/0000.txt > out/0000.txt"
./a.out < ./in/0000.txt > ./out/0000.txt
echo "[\e[32mv\e[m] ./a.out < in/0001.txt > out/0001.txt"
./a.out < ./in/0001.txt > ./out/0001.txt
echo "[\e[32mv\e[m] ./a.out < in/0002.txt > out/0002.txt"
./a.out < ./in/0002.txt > ./out/0002.txt
echo "[\e[32mv\e[m] ./a.out < in/0003.txt > out/0003.txt"
./a.out < ./in/0003.txt > ./out/0003.txt
echo "[\e[32mv\e[m] ./a.out < in/0004.txt > out/0004.txt"
./a.out < ./in/0004.txt > ./out/0004.txt
echo "[\e[32mv\e[m] ./a.out < in/0005.txt > out/0005.txt"
./a.out < ./in/0005.txt > ./out/0005.txt
echo "[\e[32mv\e[m] ./a.out < in/0006.txt > out/0006.txt"
./a.out < ./in/0006.txt > ./out/0006.txt
echo "[\e[32mv\e[m] ./a.out < in/0007.txt > out/0007.txt"
./a.out < ./in/0007.txt > ./out/0007.txt
echo "[\e[32mv\e[m] ./a.out < in/0008.txt > out/0008.txt"
./a.out < ./in/0008.txt > ./out/0008.txt
echo "[\e[32mv\e[m] ./a.out < in/0009.txt > out/0009.txt"
./a.out < ./in/0009.txt > ./out/0009.txt
echo "[\e[32mv\e[m] ./a.out < in/0010.txt > out/0010.txt"
./a.out < ./in/0010.txt > ./out/0010.txt
echo "[\e[32mv\e[m] ./a.out < in/0011.txt > out/0011.txt"
./a.out < ./in/0011.txt > ./out/0011.txt
echo "[\e[32mv\e[m] ./a.out < in/0012.txt > out/0012.txt"
./a.out < ./in/0012.txt > ./out/0012.txt
echo "[\e[32mv\e[m] ./a.out < in/0013.txt > out/0013.txt"
./a.out < ./in/0013.txt > ./out/0013.txt
echo "[\e[32mv\e[m] ./a.out < in/0014.txt > out/0014.txt"
./a.out < ./in/0014.txt > ./out/0014.txt

python3 ./calc.py < score.txt
rm ./score.txt
