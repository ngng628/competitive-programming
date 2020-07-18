#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
from argparse import ArgumentParser
import subprocess


def main():
    links = ['https://atcoder.jp/contests/abc151/tasks/abc151_a', 'https://atcoder.jp/contests/abc151/tasks/abc151_b','https://atcoder.jp/contests/abc151/tasks/abc151_c','https://atcoder.jp/contests/abc151/tasks/abc151_d','https://atcoder.jp/contests/abc151/tasks/abc151_e','https://atcoder.jp/contests/abc151/tasks/abc151_f']

    for i in range(len(links)):
        directory = './'+chr(ord('A')+i)
        res = subprocess.run(['oj', 'download', links[i]], cwd=directory)

if  __name__ == '__main__':
    main()
