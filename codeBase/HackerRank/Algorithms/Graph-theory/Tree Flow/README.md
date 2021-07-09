**Problem Statement**:  Recall that a tree is an undirected, connected acyclic graph. We have a weighted tree, ![$T$](https://render.githubusercontent.com/render/math?math=%24T%24), with ![$n$](https://render.githubusercontent.com/render/math?math=%24n%24) vertices; let ![$dist_{u, v}$](https://render.githubusercontent.com/render/math?math=%24dist_%7Bu%2C%20v%7D%24) be the total sum of edge weights on the path between nodes ![$u$](https://render.githubusercontent.com/render/math?math=%24u%24) and ![$v$](https://render.githubusercontent.com/render/math?math=%24v%24).

Let's consider all the matrices, ![$A_{u, v}$](https://render.githubusercontent.com/render/math?math=%24A_%7Bu%2C%20v%7D%24) such that:

* ![$A_{u,v} = -A_{u,v}$](https://render.githubusercontent.com/render/math?math=%24A_%7Bu%2Cv%7D%20%3D%20-A_%7Bu%2Cv%7D%24)
* ![$0 \leq |A_{u,v}| \leq dist_{v, u}$](https://render.githubusercontent.com/render/math?math=%240%20%5Cleq%20%7CA_%7Bu%2Cv%7D%7C%20%5Cleq%20dist_%7Bv%2C%20u%7D%24)
* ![$\sum_{i=1}^{n} A_{u,i} = 0$](https://render.githubusercontent.com/render/math?math=%24%5Csum_%7Bi%3D1%7D%5E%7Bn%7D%20A_%7Bu%2Ci%7D%20%3D%200%24) for each ![$u\neq 1,n$](https://render.githubusercontent.com/render/math?math=%24u%5Cneq%201%2Cn%24) for each ![$u\neq 1$](https://render.githubusercontent.com/render/math?math=%24u%5Cneq%201%24) and ![$u\neq n$](https://render.githubusercontent.com/render/math?math=%24u%5Cneq%20n%24)

We consider the total value of matrix ![$A$](https://render.githubusercontent.com/render/math?math=%24A%24) to be:
    ![$\sum_{i=1}^{n} A_{1,i}$](https://render.githubusercontent.com/render/math?math=%24%5Csum_%7Bi%3D1%7D%5E%7Bn%7D%20A_%7B1%2Ci%7D%24)
Calculate and print the maximum total value of ![$A$](https://render.githubusercontent.com/render/math?math=%24A%24) for a given tree, ![$T$](https://render.githubusercontent.com/render/math?math=%24T%24).
