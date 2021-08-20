import random
import numpy as np
class NeuralTreeRegressor(BaseEstimator, RegressorMixin):
  def __init__(self,
    n_estimators=31,
    xi=0.0,
    beta=0.0,
    R=0,
    max_depth=None,
    max_features=1,
    bootstrap=True,
    random_state=None):
    
    self.n_estimators=n_estimators
    self.xi = xi
    self.beta = beta
    self.R = R
    self.max_depth = max_depth
    self.bootstrap = bootstrap

    if not random_state is None:
      random.seed(random_state)
      np.random.seed(random_state)

  def fit(self, X, y=None):
    self.
    return self
