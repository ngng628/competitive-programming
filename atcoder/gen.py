from colorama import Fore, Back, Style
import sys
import os
import re
import shutil
import subprocess

check   = '[' +   Fore.MAGENTA  + 'x' + Fore.RESET + ']'
warning = '[' +   Fore.RED  + '*' + Fore.RESET + ']'
plus    = '[' + Fore.LIGHTGREEN_EX + '+' + Fore.RESET + ']'
cin     = '[' + Fore.YELLOW + '>' + Fore.RESET + ']'

def main():
    argvs = sys.argv
    argc = len(argvs)

    if argc < 2:
        print(warning, 'Usege:', 'gen.py contest_name')
        exit(1)

    contest_name = argvs[1]
    contest_grope = ''
    if re.search(r'(A|a)(B|b)(C|c)\d{3}', contest_name):
        contest_grope = 'ABC'
        contest_name = contest_name.upper()
    elif re.search(r'(A|a)(R|r)(C|c)\d{3}', contest_name):
        contest_grope = 'ARC'
        contest_name = contest_name.upper()
    elif re.search(r'(A|a)(G|g)(C|c)\d{3}', contest_name):
        contest_grope = 'AGC'
        contest_name = contest_name.upper()
    else:
        contest_grope = 'others'

    if os.path.exists(contest_grope + '/' + contest_name):
        print(warning, contest_name, 'is already exists')
        exit(1)
    else:
        os.mkdir(contest_grope + '/' + contest_name)
        print(plus, contest_name, 'is created')

    shutil.copyfile('./download.rb', contest_grope + '/' + contest_name + '/download.rb')
    print(plus, 'download.rb is created')
    
    if contest_grope in ['ABC', 'ARC', 'AGC']:
        contest_number = int(contest_name[3:])
        if contest_grope == 'ABC':
            if contest_number >= 212:
                problem_size = 8
            elif contest_number >= 126:
                problem_size = 6
            else:
                problem_size = 4
        elif contest_grope == 'AGC':
            problem_size = 6
        else:
            problem_size = 6
    else:  # others
        print(check, 'Please enter a problem_size')
        print(cin + ' ', end='')
        problem_size = int(input())
        print('')
    
    for i in range(problem_size):
        task_name = chr(ord('A') + i)
        path = contest_grope + '/' + contest_name + '/' + task_name
        if os.path.isfile(path):
            print(warning, task_name, 'is already exists')
        else:
            compe_home = os.environ['COMPE']
            os.mkdir(path)
            template = f'{compe_home}/template/compe.cr'
            shutil.copyfile(template, path + '/main.cr')

            os.symlink(f'{compe_home}/crystal-env/lib', path + '/lib')

            print(plus, task_name, 'is created')

if __name__ == '__main__':
    main()
