<!-- Traduzido para o inglês pelo Chatgpt em 07/08/2024 -->

# 1. Humidity Levels in a Greenhouse (Frank - 09-2024 - Easy)

You are responsible for monitoring and adjusting the humidity levels in a greenhouse that contains several plants. The greenhouse has a set of humidity sensors, represented by an array $humidity$, where each position in the array corresponds to a reading from a sensor.

Throughout the day, you receive a series of adjustment instructions, called $adjustments$. Each adjustment instruction is represented by a pair $[adjustment, sensor\_index]$, where $adjustment$ indicates the change that should be made to the reading from the sensor located at $sensor\_index$.

After each adjustment, you need to check the sum of the humidity levels that are within an acceptable range (i.e., the even numbers).

Your goal is, for each adjustment, to calculate this sum and report it in a final report.

**Example 1:**

Input: $humidity = [45, 52, 33, 64]$, $adjustments = [[5,0],[-20,1],[-14,0],[18,3]]$
Output: $[166,146,132,150]$
Explanation: Initially, the array is $[45,52,33,64]$.
After adding $5$ to $humidity[0]$, the array becomes $[50,52,33,64]$, and the sum of the even values is $50 + 52 + 64 = 166$.
After adding $-20$ to $humidity[1]$, the array becomes $[50,32,33,64]$, and the sum of the even values is $50 + 32 + 64 = 146$.
After adding $-14$ to $humidity[0]$, the array becomes $[36,32,33,64]$, and the sum of the even values is $36 + 32 + 64 = 132$.
After adding $18$ to $humidity[3]$, the array becomes $[36,32,33,82]$, and the sum of the even values is $36 + 32 + 82 = 150$.

**Example 2:**

Input: $humidity = [40]$, $adjustments = [[12,0]]$
Output: $[52]$

**Example 3**

Input: $humidity = [30, 41, 55, 68, 72]$, $adjustments = [[10,0],[-15,2],[22,1],[-8,4],[5,3]]$
Output: $[140,140,162,230,230]$
Explanation: Initially, the array is $[30,41,55,68,72]$.
After adding $10$ to $humidity[0]$, the array becomes $[40,41,55,68,72]$, and the sum of the even values is $40 + 68 + 72 = 140$.
After adding $-15$ to $humidity[2]$, the array becomes $[40,41,40,68,72]$, and the sum of the even values is $40 + 40 + 68 + 72 = 140$.
After adding $22$ to $humidity[1]$, the array becomes $[40,63,40,68,72]$, and the sum of the even values is $40 + 40 + 68 + 72 = 162$.
After adding $-8$ to $humidity[4]$, the array becomes $[40,63,40,68,64]$, and the sum of the even values is $40 + 40 + 68 + 64 = 230$.
After adding $5$ to $humidity[3]$, the array becomes $[40,63,40,73,64]$, and the sum of the even values is $40 + 40 + 64 = 230$.

**Constraints:**

- The number of sensors in the greenhouse is at least $1$ and at most $10,000$.
- Each humidity reading is between $-10,000$ and $10,000$.
- The number of adjustments throughout the day can vary between $1$ and $10,000$.
- Each adjustment can increase or decrease the sensor reading by up to $10,000$ units.

---

# The Plate Balancer

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
