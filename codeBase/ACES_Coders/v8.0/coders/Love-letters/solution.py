# Written by: Dhanushki Mapitigama
# pavithya.mapitigama@eng.pdn.ac.lk


# In here we are using Aho corasick algorithm for the fully optimized solution.

FAIL = -1
    
keywords = []

S, N = (int(val) for val in str(input()).split())


for i in range (S):
    w = input()
    word = w.rstrip()
    word = word.lower()
    keywords.append(word)
    
        
# creating the Trie dictionary by adding given words

transitions = {}
outputs = {}
fails = {}

new_state = 0

for keyword in keywords:
    state = 0

    for j, char in enumerate(keyword):
        res = transitions.get((state, char), FAIL)
        if res == FAIL:
            break
        state = res

    for char in keyword[j:]:
        new_state += 1
        transitions[(state, char)] = new_state
        state = new_state

    outputs[state] = [keyword]

queue = []

for (from_state, char), to_state in transitions.items():
    if from_state == 0 and to_state != 0:
        queue.append(to_state)
        fails[to_state] = 0

while queue:
    r = queue.pop(0)
    for (from_state, char), to_state in transitions.items():
        if from_state == r:
            queue.append(to_state)
            state = fails[from_state]

            while True:
                res = transitions.get((state, char), state and FAIL)
                if res != FAIL:
                    break
                state = fails[state]

            failure = transitions.get((state, char), state and FAIL)
            fails[to_state] = failure
            outputs.setdefault(to_state, []).extend(
                outputs.get(failure, []))
        

        
# Taking letters one by one and check with the created dictionary

for j in range (N):
    root = [] 
    letter = input().rstrip()
    state = 0
    results = []
    for i, char in enumerate(letter.lower()):
        while True:
            res = transitions.get((state, char), state and FAIL)
            if res != FAIL:
                state = res
                break
            state = fails[state]

        for match in outputs.get(state, ()):
            pos = i - len(match) + 1
            results.append(match)
            
    root = results
    
    if len(root):
        print(str(j)+ " " + str(len(root)))
