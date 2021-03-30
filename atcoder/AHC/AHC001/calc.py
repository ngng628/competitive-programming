import colorama
from colorama import Fore, Back, Style
CHECK = '[' + Fore.MAGENTA + 'v' + Style.RESET_ALL + ']'
ADD = '[' + Fore.GREEN + '+' + Style.RESET_ALL + ']'
DISPLAY = '[' + Fore.GREEN + '*' + Style.RESET_ALL + ']'
FAILURE = '[' + Fore.RED + 'x' + Style.RESET_ALL + ']'
HINT = '[' + Fore.YELLOW + '?' + Style.RESET_ALL + ']'
INPUT = '[' + Fore.GREEN + '>' + Style.RESET_ALL + ']'
SUCCESS = '[' + Fore.BLUE + 'o' + Style.RESET_ALL + ']'

ts = 15
tot = 0
for i in range(15):
  tot += int(input())
tot //= 15
score = tot * 50
print(f"平均 : {tot}")
print(f"換算 : {score}")
