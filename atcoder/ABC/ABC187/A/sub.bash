read a b
sa=$((a/10/10 + a/10%10 + a%10))
sb=$((b/10/10 + b/10%10 + b%10))
if [ $sa -gt $sb ]; then
    echo $sa
else
    echo $sb
fi