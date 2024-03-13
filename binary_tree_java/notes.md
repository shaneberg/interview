# Working Notes

## Tree Printing

Assume 3 digits
`_` = whitespace
`x` = digits


num_nodes_in_this_row = 2^rowIndex
Tree Row Render Width = node_width * num_nodes_in_this_row + (min_space_width * (num_nodes_in_this_row - 1))


### Height = 1
nodes[0] = 1;
padd [0] = 0;
width[0] = 1;
```
x
```

### Height = 2
nodes[0] = 1;

padd [0] = 1;
width[0] = 2;

nodes[1] = 2;

padd [1] = 0;
width[1] = 3;
space[1] = 1;
```
  x
 x x
```

### Height = 3

nodes[0] = 1;

padd [0] = 3;
width[0] = 4;

nodes[1] = 2;

padd [1] = 1;
width[1] = 6;
space[1] = 3;

nodes[2] = 0;

padd [2] = 0;
width[2] = 7;
space[2] = 1;
```
   x
 x   x
x x x x
```

### Height = 4

space[0] = 0;
space[1] = 7;
space[2] = 3;
space[3] = 1;

padd [0] = 7;
padd [1] = 3;
padd [2] = 1;
padd [3] = 0;
padd = max_width / 2;
padd = max_width / 4;
padd = max_width / 8;
padd = max_width / 16;
padd = max_width / 2^(row_index+1);

space[0] = 0;
space[1] = 7;
space[2] = 3;
space[3] = 1;
space = (padd * 2) + 1

nodes[0] = 1;
nodes[1] = 2;
nodes[2] = 4;
nodes[3] = 8;

width[0] = 8;
width[1] = 12;
width[2] = 14;
width[3] = 15;
max = (2^height * 2) - 1


```
       x
   x       x
 x   x   x   x
x x x x x x x x
``
