import pprint
import numpy as np


global state_size = 12
global action_size = 7
global alpha = 0.55
global gamma = 0.6
global epsilon = 0.2
global hour = 24

global current_states = [0] * 24
global actions = [1] * 24

global Q_table = []

for i in range(24):
  row = []
  for j in range(state_size):
    column = []
    for k in range(action_size):
      column.append(0.0)
    row.append(column)
  Q_table.append(row)
