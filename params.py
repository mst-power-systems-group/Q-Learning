import pprint
import numpy as np


global state_size = 12
global action_size = 7
global alpha = 0.55
global gamma = 0.6
global epsilon = 0.2
global hour = 24

global current_states = np.zeros(state_size)
global actions = np.ones(action_size)

global Q_table = np.zeros(hour, state_size, action_size)
