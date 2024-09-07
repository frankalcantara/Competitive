### The Plate Balancer

In a famous restaurant, Chef André is known for his incredible skill in balancing plates. He has a long table with several plates, each containing a different amount of food.

André wants to find the "Magic Plate" - the plate where, when he places his finger underneath it, the weight of the food on the left and right balances perfectly.

Given a list of $plates$, where each number represents the weight of the food on each plate, your task is to help André find the index of the Magic Plate.

The Magic Plate is the one where the sum of the weights of all plates to its left is equal to the sum of the weights of all plates to its right.

If André places his finger under the leftmost plate, consider the weight on the left as $0$. The same applies if he chooses the rightmost plate.

Return the leftmost Magic Plate index. If no such plate exists, return $-1$.

**Example 1:**

Input: $plates = [3,1,5,2,2]$  
Output: $2$  
Explanation:  
The Magic Plate is at index $2$.  
Weight on the left = $plates[0] + plates[1] = 3 + 1 = 4$  
Weight on the right = $plates[3] + plates[4] = 2 + 2 = 4$

**Example 2:**

Input: $plates = [1,2,3]$  
Output: $-1$  
Explanation:  
There is no plate that can be the Magic Plate.

**Example 3:**

Input: $plates = [2,1,-1]$  
Output: $0$  
Explanation:  
The Magic Plate is the first plate.  
Weight on the left = $0$ (no plates to the left of the first plate)  
Weight on the right = $plates[1] + plates[2] = 1 + (-1) = 0$

**Constraints:**

$$1 \leq plates.length \leq 10^4$$  
$$-1000 \leq plates[i] \leq 1000$$

Note: André is very skilled, so don't worry about the real-world physics of balancing plates. Focus only on the mathematical calculations!
