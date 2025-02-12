# Solution to the Rod Cutting Problem using the Divide and Conquer approach in Python

def cut_rod(price, n):
	max_val = 0

	for i in range(0, n):
		max_val = max(max_val, price[i] + cut_rod(price, n-i-1))

	return max_val

# example price list (for rod lengths 1 to 10)
price = [1, 5, 8, 9, 10, 17, 17, 20, 24, 30]

user_len = int(input("Enter length: "))

# checking if user_len is valid
if user_len >= 1 or user_len <= len(price):
	print("Maximum cost you can get:", cut_rod(price, user_len))
else:
	print("Invalid length! Enter value between 1 and", len(price))
