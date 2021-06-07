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
  # double alpha_c = 1.0 / 24000, alpha_hv = 1, alpha_delta = 1, start_alpha = 0.1, end_alpha = 0.08, penalty = 1, turn_c = 1;
  # int exploitation_turn = 130, beta_ = 10, epoch = 5;

  alpha_c = trial.suggest_loguniform('alpha_c', 1e-6, 1e-3)
  # alpha_c = 1.0 / 24000
  alpha_hv = trial.suggest_loguniform('alpha_hv', 1e-1, 10)
  # alpha_hv = 1
  alpha_delta = trial.suggest_loguniform('alpha_delta', 1e-1, 10)
  # alpha_delta = 1
  start_alpha = trial.suggest_uniform('start_alpha', 1e-2, 1e-1)
  # start_alpha = 0.1
  end_alpha = trial.suggest_uniform('end_alpha', 1e-2, start_alpha)
  # end_alpha = 0.08
  penalty = trial.suggest_loguniform('penalty', 1e-1, 10)
  # penalty = 1
  turn_c = trial.suggest_uniform('turn_c', 1, 10)
  # turn_c = 1
  exploitation_turn = trial.suggest_int("exploitation_turn", 50, 200)
  # exploitation_turn = 130
  beta = trial.suggest_int("beta", 1, 50)
  # beta = 10
  epoch = trial.suggest_int("epoch", 3, 8)
  # epoch = 5
  
  return wrapper([alpha_c, alpha_hv, alpha_delta, start_alpha, end_alpha, penalty, turn_c, exploitation_turn, beta, epoch])

def main():
  study = optuna.create_study()
  study.optimize(objective, n_trials=10000)
  print("minimum f(x) : ", study.best_value)
  print("argmin f(x) : ", study.best_params)

if __name__ == '__main__':
  main()
