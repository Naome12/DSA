import numpy as np
import matplotlib.pyplot as plt

# Define the function
def f(x):
    return (1 - x**2) / ((x**2 - 1)**2)

# Define x values, avoiding vertical asymptotes at x = ±1
x = np.linspace(-3, 3, 1000)
x = x[np.abs(x) > 1.01]  # avoid values too close to x = ±1

# Plot the function
plt.figure(figsize=(10, 6))
plt.plot(x, f(x), label=r"$f(x) = \frac{1 - x^2}{(x^2 - 1)^2}$", color='blue')

# Asymptotes
plt.axvline(x=1, color='red', linestyle='--', label='Vertical Asymptote x = 1')
plt.axvline(x=-1, color='red', linestyle='--', label='Vertical Asymptote x = -1')
plt.axhline(y=1, color='green', linestyle='--', label='Horizontal Asymptote y = 1')

# Max point
plt.plot(0, 0, 'ko', label='Maximum at (0, 0)')

# Formatting
plt.title("Graph of the Function with Given Asymptotes and Limits")
plt.xlabel("x")
plt.ylabel("f(x)")
plt.ylim(-10, 10)
plt.grid(True)
plt.legend()
plt.show()
