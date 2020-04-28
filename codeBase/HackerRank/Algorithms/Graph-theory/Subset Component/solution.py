'''
    Copyright (C) 2020, Sathira Silva.
'''

from sys import stdin, stdout

def findConnectedComponents(i, previous_components, d):
    if i == len(d):
        return len(previous_components)
    count_cc = findConnectedComponents(i + 1, previous_components, d)
    currentComponent = d[i]
    components = []
    for cc in previous_components:
        if cc & currentComponent:
            currentComponent |= cc
        else:
            components.append(cc)
    if currentComponent:
        components.append(currentComponent)
    count_cc += findConnectedComponents(i + 1, components, d)
    return count_cc


if __name__ == '__main__':
    d_count = int(stdin.readline())
    d = list(map(int, stdin.readline().rstrip().split()))
    singletons = [1 << j for j in range(64)]
    components = findConnectedComponents(0, singletons, d)
    stdout.write(str(components) + '\n')
