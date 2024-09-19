# First Week's Challenges

1. **Widget Batch Sorting**

   A factory produces widgets in batches. Each batch is assigned a number between 2000 and 3200. Batches divisible by 7 are sent to Warehouse A, unless they're also divisible by 5, in which case they go to Warehouse B. Write a program to list all batch numbers sent to Warehouse A.

   Input: None
   Output: A comma-separated list of integers

   Example Output:

   ```shell
   2002,2009,2016,2023,2037,2044,2051,2058,2072,2079,2086,2093,2107,2114,2121,2128,2142,2149,2156,2163,2177,2184,2191,2198
   ```

   Hint: Use a `list` to store the batch numbers and the `range()` function for iteration. The `join()` method can be used to create the comma-separated output string.

2. **Bacterial Growth Calculator**

   A microbiologist is studying bacterial growth. The population doubles every generation. Given the number of generations, calculate the final population if starting with a single bacterium.

   Input: An integer $n$ representing the number of generations
   Output: An integer representing the final population

   Example:
   Input: `8`
   Output: `256`

   Hint: This is effectively a factorial calculation. Implement a recursive function. Use `int()` to convert input to an integer.

3. **Student Square Number Reference**

   A teacher wants to create a quick reference sheet for square numbers. For a given number of students $n$, create a dictionary where the keys are student numbers (1 to $n$) and the values are their numbers squared.

   Input: An integer $n$ representing the number of students
   Output: A dictionary where keys are integers from 1 to $n$, and values are their squares

   Example:
   Input: `5`
   Output: `{1: 1, 2: 4, 3: 9, 4: 16, 5: 25}`

   Hint: Use a `dict()` to create the dictionary. A `for` loop with `range()` can generate the student number and squared value pairs.

4. **Daily Sales Data Analyzer**

   A grocery store manager needs to analyze sales data. Write a program that takes comma-separated prices of items sold in a day, and generates both a list and a tuple of these prices.

   Input: A string of comma-separated floating-point numbers
   Output: A list and a tuple containing the input numbers

   Example:
   Input: `23.5,18.9,31.2,15.5,42.8`
   Output:

   ```txt
   ['23.5', '18.9', '31.2', '15.5', '42.8']
   ('23.5', '18.9', '31.2', '15.5', '42.8')
   ```

   Hint: Use `string.split()` to parse the input. Convert the result directly to a `list` and then to a `tuple`.

5. **Chatbot Text Processor**

   Design a simple text processing class for a chatbot. It should have methods to get input from a user and to respond with the input converted to uppercase.

   Input: A string from the user
   Output: The input string converted to uppercase

   Example:
   Input: `Hello, how are you?`
   Output: `HELLO, HOW ARE YOU?`

   Hint: Use `raw_input()` (or `input()` in Python 3) for getting input. Implement `__init__` method to initialize an empty string attribute.

6. **Water Tank Volume Calculator**

   An engineer is designing a series of water tanks. The volume $Q$ of each cylindrical tank is given by:

   $$Q = \sqrt{\frac{2 * C * D}{H}}$$

   where $C = 50$ (a flow coefficient) and $H = 30$ (the height of each tank).
   $D$ is the diameter, which varies for each tank. Write a program to calculate $Q$ for a series of diameters input as a comma-separated sequence.

   Input: A string of comma-separated integers representing diameters
   Output: A comma-separated string of floating-point numbers rounded to two decimal places

   Example:
   Input: `100,150,180`
   Output: `18.11,22.16,24.28`

   Hint: Use `math.sqrt()` for square root. Parse input into a `list` and use list comprehension to calculate volumes.

7. **Simple Voice Recognition**

   Create a simple voice recognition program that prints "Command Accepted" if it hears "Yes" in any capitalization, otherwise it prints "Command Declined".

   Input: A string representing the voice input
   Output: Either "Command Accepted" or "Command Declined"

   Example 1:
   Input: `yes`
   Output: `Command Accepted`

   Example 2:
   Input: `No`
   Output: `Command Declined`

   Hint: Use string methods like `lower()` or `upper()` to standardize the input before comparison.

8. **ASCII to UTF-8 Converter**

   A data analyst needs to convert ASCII-encoded data from an old system into UTF-8 for modern analysis. Write a program to perform this conversion on a given input string.

   Input: An ASCII-encoded string
   Output: The same string encoded in UTF-8

   Example:
   Input: `Hello, world!`
   Output: `Hello, world!` (but encoded in UTF-8)

   Hint: In Python 2, use `unicode()` function with 'utf-8' encoding. In Python 3, strings are already unicode.

9. **Savings Growth Calculator**

   An economist is modeling savings growth. The model is:

   $$savings(n)=savings(n−1)+100savings(n) = savings(n-1) + 100savings(n)=savings(n−1)+100$$

   where $n$ is the number of months and $savings(0) = 1000$.
   Write a program to calculate savings for a given number of months.

   Input: An integer $n$ representing the number of months
   Output: The total savings after $n$ months

   Example:
   Input: 5
   Output: 1500

   Hint: Implement a recursive function. Use a base case for $n=0$. Convert input to integer using int().

10. **Library Book Checkout System**

    A local library is implementing a digital system to track book checkouts. Each book has a unique 5-digit ID number. Books with ID numbers divisible by 3 are placed on the "Featured" shelf. However, if the ID is also divisible by 4, it goes to the "Classics" section instead. Create a program to help librarians quickly determine where to place a book.

    Input: An integer $n$ representing the book ID (10000 ≤ $n$ ≤ 99999)
    Output: A string: "Featured", "Classics", or "Regular"

    Examples:
    Input: `10002`
    Output: `Regular`

    Input: `10353`
    Output: `Featured`

    Input: `10512`
    Output: `Classics`

    Hint: Use the modulo operator `%` to check divisibility. Implement conditional statements to determine the correct category based on the ID number.

    Extra Challenge: Instead of a single ID, allow the librarian to input a comma-separated list of book IDs and output the category for each book in the same order.

    Example for Extra Challenge:
    Input: `10002,10353,10512`
    Output: `Regular,Featured,Classics`

_Solutions will be posted on Monday. Stay tuned!_
