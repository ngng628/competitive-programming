if [ ! -e "./test" ]; then
    mkdir "test"
    echo "[\033[32m+\033[0m] test/"
fi
echo "[\033[33m>\033[0m] テストケース数"
read ts

for i in `seq 1 $ts`; do
    nvim test/sample-${i}.in test/sample-${i}.out -o
    printf "[\033[32m+\033[0m] test/sample-${i}.in\n"
    printf "[\033[32m+\033[0m] test/sample-${i}.out\n"
done

echo "[\033[33m>\033[0m] 入力の終わり方"
read end
for i in `seq 1 $ts`; do
    echo $end >> "test/sample-${i}.in"
done