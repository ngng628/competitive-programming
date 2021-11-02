import optuna
import subprocess
from multiprocessing import Pool
import os

case_num = 1
core = min(case_num, os.cpu_count() - 2)

def f(args):
  i, *args = args
  res = subprocess.run(['./tools/target/release/tester in/{:04}.txt ./a.out '.format(i) + ' '.join(map(str, args))],
                          universal_newlines=True, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
  s = res.stderr.split("Score = ")[1]
  res = int(res.stderr.split("Score = ")[1])
  return res

def wrapper(args):
  mean = 0
  with Pool() as pool:
      mean = sum(pool.map(f, [[i] + args for i in range(case_num)]))

  return -mean / case_num


def objective(trial):
  x = trial.suggest_loguniform('x', -1e3, 1e3)
  return wrapper([x])

def main():
  study = optuna.create_study()
  study.optimize(objective, n_trials=10000)
  print("minimum f(x) : ", study.best_value)
  print("argmin f(x) : ", study.best_params)

if __name__ == '__main__':
  main()
