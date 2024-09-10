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

# Problem 3: Inventory Restocking

You manage a warehouse where products are stored and moved frequently. The warehouse tracks its inventory by recording the stock count at different times during the day in an array $inventory$. Occasionally, inventory managers report the amount by which a product's stock needs to be adjusted, represented by an integer array $adjustments$, where each adjustment is a pair $[adjustment, index]$. Your task is to apply these adjustments and after each, calculate the total count of products with even stock numbers.

**Input Format:**

- The first line contains an integer $n$, representing the size of the $inventory$ array.
- The second line contains $n$ integers representing the initial values in the $inventory$ array.
- The third line contains an integer $q$, the number of stock adjustments.
- The following $q$ lines each contain a pair $adjustment$ and $index$, where $adjustment$ is the amount to be added or subtracted, and $index$ is the position in the $inventory$ array to adjust.

**Constraints:**

- $1 \leq n, q \leq 10^5$
- $-10^4 \leq inventory[i], adjustment \leq 10^4$

**Example Input:**
6
10 3 5 6 8 2
4
[3, 1]
[-4, 0]
[2, 3]
[-3, 4]

**Example Output:**
26
16
20
16
</text>

**Explanation:**

Initially, the array is $[10, 3, 5, 6, 8, 2]$, and the sum of even values is $10 + 6 + 8 + 2 = 26$.

- After adding $3$ to $inventory[1]$, the array becomes $[10, 6, 5, 6, 8, 2]$, and the sum of even values is $10 + 6 + 6 + 8 + 2 = 32$.
- After subtracting $4$ from $inventory[0]$, the array becomes $[6, 6, 5, 6, 8, 2]$, and the sum of even values is $6 + 6 + 6 + 8 + 2 = 28$.

**Input Method:**

The input will be provided via **hardcoded values** inside the code for testing purposes.

# Problem 4: Sales Target Analysis

You are tasked with analyzing sales data to determine how many subarrays of daily sales sum to a multiple of a target value $T$. The sales data is recorded in an array $sales$, and you need to calculate how many contiguous subarrays of $sales$ have a sum divisible by $T$.

**Input Format:**

- The first line contains two integers $n$ (the size of the sales array) and $T$ (the target value).
- The second line contains $n$ integers, representing the daily sales data.

**Constraints:**

- $1 \leq n \leq 10^5$
- $1 \leq T \leq 10^4$
- $-10^4 \leq sales[i] \leq 10^4$

**Output Format:**

- Output a single integer representing the number of subarrays whose sum is divisible by $T$.

**Example Input:**
6 5
4 5 0 -2 -3 1

**Example Output:**
7

**Explanation:**

There are 7 subarrays whose sum is divisible by $T = 5$:
- $[4, 5, 0, -2, -3, 1]$
- $[5]$
- $[5, 0]$
- $[5, 0, -2, -3]$
- $[0]$
- $[0, -2, -3]$
- $[-2, -3]$

**Input Method:**

The input is provided via **command-line arguments**.

# Problem 5: Weather Monitoring System

In a weather station, temperature data is collected every hour. You are given an array of hourly temperatures, and your task is to determine the subarray of length $k$ with the highest average temperature over a 24-hour period. The data is recorded in a text file, and you need to read the data from the file to compute the result.

**File Format:**

- The first line contains two integers $n$ (number of temperature readings) and $k$ (the length of the subarray).
- The second line contains $n$ integers representing the hourly temperature readings.

**Input Example:**
24 4
-2 0 1 5 3 -1 -6 2 4 8 -3 0 2 5 1 6 -4 7 -2 0 3 1 -5 -6

**Output Example:**
6.50000

**Explanation:**

The subarray with the highest average is $[8, -3, 0, 2]$ with an average of $6.50$.

**Input Method:**

The input is provided via **file input** from a `.txt` file.
