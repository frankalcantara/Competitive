### 1. Humidity Levels in a Greenhouse (Frank - 09-2024 - Easy)

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

**Example 3**:

Input: $humidity = [30, 41, 55, 68, 72]$, $adjustments = [[10,0],[-15,2],[22,1],[-8,4],[5,3]]$
Output: $[180,220,220,212,144]$
Explanation: Initially, the array is $[30,41,55,68,72]$.
After adding $10$ to $humidity[0]$, the array becomes $[40,41,55,68,72]$, and the sum of the even values is $40 + 68 + 72 = 180$.
After adding $-15$ to $humidity[2]$, the array becomes $[40,41,40,68,72]$, and the sum of the even values is $40 + 40 + 68 + 72 = 220$.
After adding $22$ to $humidity[1]$, the array becomes $[40,63,40,68,72]$, and the sum of the even values is $40 + 40 + 68 + 72 = 220$.
After adding $-8$ to $humidity[4]$, the array becomes $[40,63,40,68,64]$, and the sum of the even values is $40 + 40 + 68 + 64 = 212$.
After adding $5$ to $humidity[3]$, the array becomes $[40,63,40,73,64]$, and the sum of the even values is $40 + 40 + 64 = 144$.

**Constraints:**

- The number of sensors in the greenhouse is at least $1$ and at most $10,000$.
- Each humidity reading is between $-10,000$ and $10,000$.
- The number of adjustments throughout the day can vary between $1$ and $10,000$.
- Each adjustment can increase or decrease the sensor reading by up to $10,000$ units.
