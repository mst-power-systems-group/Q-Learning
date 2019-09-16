import params
from random import seed, random

seed(1)

rand = False

params.init()

next_states = []
profits = []

def update_table(hour, curr_state, act, nxt_state, reward):
    
    params.Q_table[hour][curr_state][act] += params.alpha * (reward + params.gamma * np.amax(params.Q_table[hour][nxt_state]) - params.Q_table[hour][curr_state][act])
    
def get_action(hour, curr):
    
    if (rand == True):
        return np.random.randint(0, params.action_size)
    else:
        return np.argmax(params.Q_table[hour][curr]) #return the index, NOT THE VALUE!



def Q_learning(next_states, profits):
    
    if random() <= params.epsilon:
        rand = True
    
    for i in range(24):
        update_table(i, params.current_states[i], params.actions[i], next_states[i], profits[i])
        params.current_states[i] = next_states[i]
        params.actions[i] = get_action(i, params.current_states[i])
    
    #update_params(day)
        
    return params.actions

