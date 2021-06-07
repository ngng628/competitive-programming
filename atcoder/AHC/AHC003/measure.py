"""
scripts/measure.py

A script to measure the efficacy of solutions rapidly.
"""

__author__ = "Kimiyuki Onaka"
__copyright__ = "Copyright (c) 2021 Kimiyuki Onaka"
__credits__ = []  # type: List[str]
__license__ = "MIT"
__version__ = "1.2.0"
__maintainer__ = "Kimiyuki Onaka"
__email__ = "kimiyuki95@gmail.com"
__status__ = "Production"

import argparse
import concurrent.futures
import math
import os
import pathlib
import subprocess
import sys
from logging import DEBUG, basicConfig, getLogger
from typing import *
import colorama
from colorama import Fore, Back, Style

logger = getLogger(__name__)


def gen(*, seeds: List[int]) -> None:
    logger.info('テストケースの生成')
    with open('seeds.txt', 'w') as fh:
        for seed in seeds:
            print(seed, file=fh)
    subprocess.check_call([str((pathlib.Path.cwd() / 'tools' / 'target' / 'release' / 'gen').resolve()), 'seeds.txt'])
    # subprocess.check_call(['cargo', 'run', '--manifest-path', str(pathlib.Path('tools', 'Cargo.toml')), '--release', '--bin', 'gen', 'seeds.txt'])


def run(*, command: str, input_path: pathlib.Path, output_path: pathlib.Path, seed: int) -> None:
    logger.info('SEED %d...', seed)
    try:
        with open(output_path, 'w') as fh2:
            subprocess.check_call([str((pathlib.Path.cwd() / 'tools' / 'target' / 'release' / 'tester').resolve()), f'{input_path}', command], stdout=fh2)
    except subprocess.SubprocessError:
        logger.exception('failed for seed = %d', seed)


def vis(*, input_path: pathlib.Path, output_path: pathlib.Path, vis_path: pathlib.Path, seed: int) -> int:
    try:
        command = [str((pathlib.Path.cwd() / 'tools' / 'target' / 'release' / 'vis').resolve()), str(input_path), str(output_path)]
        score_bytes = subprocess.check_output(command)
    except subprocess.SubprocessError:
        logger.exception('failed for seed = %d', seed)
        return 0
    os.rename('out.svg', vis_path)
    if not score_bytes.startswith(b'Score = '):
        raise RuntimeError(score_bytes.decode())
    return int(score_bytes.split()[2])


def main() -> 'NoReturn':
    parser = argparse.ArgumentParser()
    parser.add_argument('-c', '--command', default='./a.out')
    parser.add_argument('-n', '--count', type=int, default=50)
    parser.add_argument('-j', '--jobs', type=int, default=2)
    parser.add_argument('--same', action='store_true')
    parser.add_argument('--seed', type=int, default=0)
    args = parser.parse_args()

    # basicConfig(level=DEBUG)
    basicConfig(format='[' + Fore.MAGENTA + '%(levelname)s' + Style.RESET_ALL + '] ' + '%(message)s', level=DEBUG)

    if not pathlib.Path('tools').exists():
        logger.error('tools/ directory is not found')
        sys.exit(1)

    # gen
    if args.same:
        seeds = [args.seed for i in range(args.count)]
    else:
        seeds = [args.seed + i for i in range(args.count)]
    gen(seeds=seeds)

    # run
    pathlib.Path('out').mkdir(exist_ok=True)
    with concurrent.futures.ThreadPoolExecutor(max_workers=args.jobs) as executor:
        for i, seed in enumerate(seeds):
            input_path = pathlib.Path('in', '%04d.txt' % i)
            output_path = pathlib.Path('out', '%04d.txt' % i)
            executor.submit(run, command=args.command, input_path=input_path, output_path=output_path, seed=seed)

    # vis
    logger.info('svgの生成')
    pathlib.Path('vis').mkdir(exist_ok=True)
    scores: List[int] = []
    #command = ['cargo', 'build', '--manifest-path', str(pathlib.Path('tools', 'Cargo.toml')), '--release', '--bin', 'gen']
    #subprocess.check_output(command)
    for i, seed in enumerate(seeds):
        input_path = pathlib.Path('in', '%04d.txt' % i)
        output_path = pathlib.Path('out', '%04d.txt' % i)
        vis_path = pathlib.Path('vis', '%04d.svg' % i)
        score = vis(input_path=input_path, output_path=output_path, vis_path=vis_path, seed=seed)
        scores.append(score)
        logger.info('seed = {}: score = {}'.format(seed, score))
    average = sum(scores) / len(scores)

    print()
    logger.info('総得点 = %s', '{:,}'.format(int(100 * average)))
    logger.info('平均 = %s', '{:,}'.format(int(average)))
    logger.info('min = %s', '{:,}'.format(min(scores)))
    logger.info('max = %s', '{:,}'.format(max(scores)))
    logger.info('standard deviation = %s', math.sqrt(sum([(score - average)**2 for score in scores]) / len(scores)))

    if min(scores) <= 0:
        sys.exit(1)
    sys.exit(0)


if __name__ == '__main__':
    main()
