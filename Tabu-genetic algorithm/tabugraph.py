import matplotlib.pyplot as plt

# Replace the avalanche_degree_before and avalanche_degree_after lists with the actual avalanche degree values obtained for each generation
avalanche_degree_before = [95, 92, 87, 82, 78]  #  avalanche degree values before iterations for each generation
avalanche_degree_after = [90, 88, 85, 80, 77]   #  avalanche degree values after iterations for each generation

# Plot the avalanche degree curves
generations = range(1, len(avalanche_degree_before) + 1)
plt.plot(generations, avalanche_degree_before, label='Before Iterations', marker='o')
plt.plot(generations, avalanche_degree_after, label='After Iterations', marker='x')
plt.xlabel('Generation')
plt.ylabel('Avalanche Degree')
plt.title('Avalanche Degree Before and After Iterations')
plt.legend()
plt.show()

