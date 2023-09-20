# permutation

## next_permutation

- 从右到左进行扫描,发现第一个违背递增趋势的数字,称之为`PartitionNumber`, 如上图, $6$ 恰好是我们找到的`PartitionNumber`。
- 从右到左进行扫描,发现第一个比`PartitionNumber`要大的数,称之为`ChangeNumber`。而 $7$ 恰好是我们找到的`ChangeNumber`, 需要注意的是, 这样的数一定是存在的, 否则的话, 就找不到所谓的`PartitionNumber`了。
- 交换`PartitionNumber`和`ChangeNumber`。 这样一步, 会使得新的排列组成的数比旧的排列组成的数要大, 当然, 新数增长的幅度不一定是最小的。
- 反转在`PartitionNumber`右侧的数。此时, `PartitionNumber`右侧的排列已经是严格的从大到小排列了, 如此反转之后, 可以保证, 新的排列组成的数的增长幅度在所有的可能中最小。

如果没有找到`PartitionNumber`，那么显然这是最后一个排列了。

## prev_permutation

- 从右到左进行扫描,发现第一个违背递减趋势的数字,称之为`PartitionNumber`, 如上图, $3$ 恰好是我们找到的`PartitionNumber`。
- 从右到左进行扫描,发现第一个比`PartitionNumber`要小的数,称之为`ChangeNumber`。而 $2$ 恰好是我们找到的`ChangeNumber`, 需要注意的是, 这样的数一定是存在的, 否则的话, 就找不到所谓的`PartitionNumber`了。
- 交换`PartitionNumber`和`ChangeNumber`。 这样一步, 会使得新的排列组成的数比旧的排列组成的数要大, 当然, 新数增长的幅度不一定是最小的。
- 反转在`PartitionNumber`右侧的数。此时, `PartitionNumber`右侧的排列已经是严格的从大到小排列了, 如此反转之后, 可以保证, 新的排列组成的数的增长幅度在所有的可能中最小。

如果没有找到`PartitionNumber`，那么显然这是第一个排列了。