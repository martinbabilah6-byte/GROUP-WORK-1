Algorithm
Start

Input the number of circuits to assess.
For each circuit:
-Prompt user to enter circuit name
-supply voltage
-total load power.

Validate inputs (must be positive values).
-Calculate load current: 𝐼𝑙𝑜𝑎𝑑=𝑃𝑡𝑜𝑡𝑎𝑙𝑉𝑠𝑢𝑝𝑝𝑙𝑦
-Calculate design current: 𝐼𝑑𝑒𝑠𝑖𝑔𝑛=𝐼𝑙𝑜𝑎𝑑× 1.25

Compare design current against standard ratings (6, 10, 16, 20, 25, 32, 40, 63).

If a suitable rating ≥ design current is found → select it.

Else → report that no standard rating is available.

Display protection report (circuit name, load current, design current, recommended rating, status).

Save the same report to a file (protection_report.txt).

After all circuits are processed, close the file.

End.
