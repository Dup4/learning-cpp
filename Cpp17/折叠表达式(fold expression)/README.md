# 折叠表达式(fold expression)

- 一元右折叠(unary right fold)

    ( pack op ... )

    一元右折叠(E op ...)展开之后变为 E1 op (... op (EN-1 op EN))
- 一元左折叠(unary left fold)

    ( ... op pack )

    一元左折叠(... op E)展开之后变为 ((E1 op E2) op ...) op EN
- 二元右折叠(binary right fold)

    ( pack op ... op init )

    二元右折叠(E op ... op I)展开之后变为 E1 op (... op (EN−1 op (EN op I)))
- 二元左折叠(binary left fold)

    ( init op ... op pack )

    二元左折叠(I op ... op E)展开之后变为 (((I op E1) op E2) op ...) op EN